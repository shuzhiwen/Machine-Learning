import os
import cv2

def alter(path,object):
  result = []
  s = os.listdir(path)
  count = 1
  for i in s:
    document = os.path.join(path,i)
    img = cv2.imread(document)
    img = cv2.resize(img, (30,30))
    fileName = str(count)
    cv2.imwrite(object+os.sep+'%s.jpg' % fileName, img)
    count = count + 1

alter('org_pos', 'pos')
