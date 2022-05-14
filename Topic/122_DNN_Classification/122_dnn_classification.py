import cv2 as cv
import numpy as np

bin_model = "H:/OpenCV_Learning/121_DNN_Load_Layers/googlenet/bvlc_googlenet.caffemodel"
protxt = "H:/OpenCV_Learning/121_DNN_Load_Layers/googlenet/bvlc_googlenet.prototxt"

# Load names of classes
classes = None
with open("H:/OpenCV_Learning/121_DNN_Load_Layers/googlenet/classification_classes_ILSVRC2012.txt", 'rt') as f:
    classes = f.read().rstrip('\n').split('\n')

# load CNN model
net = cv.dnn.readNetFromCaffe(protxt, bin_model)
net.setPreferableBackend(cv.dnn.DNN_BACKEND_OPENCV)
net.setPreferableTarget(cv.dnn.DNN_TARGET_CPU)


# read input data
image = cv.imread("H:/OpenCV_Learning/122_DNN_Classification/space_shuttle.jpg")
blob = cv.dnn.blobFromImage(image, 1.0, (224, 224), (104, 117, 123), False, crop=False)
# 模型输入大小为224 (104,117, 123)数据集的均值
result = np.copy(image)
cv.imshow("input", image)

# Run a model
net.setInput(blob)
out = net.forward()

# Get a class with a highest score.
out = out.flatten()
classId = np.argmax(out)
confidence = out[classId]

# Put efficiency information.
t, _ = net.getPerfProfile()
label = 'Inference time: %.2f ms' % (t * 1000.0 / cv.getTickFrequency())
cv.putText(result, label, (0, 15), cv.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 0))

# Print predicted class.
label = '%s: %.4f' % (classes[classId] if classes else 'Class #%d' % classId, confidence)
cv.putText(result, label, (50, 50), cv.FONT_HERSHEY_SIMPLEX, 0.75, (0, 0, 255), 2)
cv.imshow("googlenet-demo", result)
cv.waitKey(0)
cv.destroyAllWindows()