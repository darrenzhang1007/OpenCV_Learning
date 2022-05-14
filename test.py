import os
import shutil

for root, dirs, files in os.walk(".", topdown=False):
    for name in files:
        if '.sln' in name:
            os.remove(os.path.join(root, name))
        if '.vcxproj' in name:
            os.remove(os.path.join(root, name))