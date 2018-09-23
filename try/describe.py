import os

size = 30

def creat(path, sign):
  l = os.listdir(path)
  os.chdir(path)
  files = open(path+'.txt', 'w')
  for name in l:
    if name == path+'.txt':
      continue
    files.write(path+'/'+name)
    if sign == '-':
      files.write('\n')
      continue
    else:
      files.write(' 1 0 0 '+str(size)+' '+str(size))
      if name != l[len(l) - 1]:
        files.write('\n')
  files.close
  os.chdir('..')

creat('pos', '+')
creat('neg', '-')