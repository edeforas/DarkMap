import cv2

#Capture video from webcam
vid_capture = cv2.VideoCapture(0)

fps = vid_capture.get(cv2.CAP_PROP_FPS)
print(f"Real FPS={fps}")
#vid_capture.set(cv2.CAP_PROP_FPS, 100)
#vid_capture.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
#vid_capture.set(cv2.CAP_PROP_FRAME_HEIGHT, 1024)

vid_codec = cv2.VideoWriter_fourcc(*'XVID')
output = cv2.VideoWriter("video_test1.mp4", vid_codec, fps, (640,480))
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