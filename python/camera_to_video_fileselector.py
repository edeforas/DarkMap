import cv2
from tkinter import Tk     # from tkinter import Tk for Python 3.x
from tkinter.filedialog import askopenfilename

Tk().withdraw()
filename = askopenfilename(title= "Please select a file:")

#Capture video from webcam
vid_capture = cv2.VideoCapture(0)
vid_cod = cv2.VideoWriter_fourcc(*'XVID')
output = cv2.VideoWriter(filename, vid_cod, 20.0, (640,480))
while(True):
     # Capture each frame of webcam video
     ret,frame = vid_capture.read()
     cv2.imshow("My cam video", frame)
     output.write(frame)

     if cv2.waitKey(1) &0XFF == ord('q'):
         break

vid_capture.release()
output.release()
cv2.destroyAllWindows()