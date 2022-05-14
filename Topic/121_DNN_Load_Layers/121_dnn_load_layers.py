import cv2 as cv

print(cv.__version__)

bin_model = "googlenet/bvlc_googlenet.caffemodel"
protxt = "googlenet/bvlc_googlenet.prototxt"

# Load names of classes
classes = None
with open("googlenet/classification_classes_ILSVRC2012.txt", 'rt') as f:
    classes = f.read().rstrip('\n').split('\n')

# load CNN model
net = cv.dnn.readNet(bin_model, protxt)

# 获取各层信息
layer_names = net.getLayerNames()
print(layer_names)
for name in layer_names:
    id = net.getLayerId(name)
    layer = net.getLayer(id)
    print("layer id : %d, type : %s, name: %s" % (id, layer.type, layer.name))

print("successfully loaded model...")
