import cv2

index = 0
prev_sharpness=-10000
must_save=False
img_to_save=None
vid_capture = cv2.VideoCapture(0)
while(True):
    ret,frame = vid_capture.read()
    cv2.imshow("My cam video", frame)
    sharpness=cv2.Laplacian(frame, cv2.CV_64F).var()

    if sharpness>100:
        if sharpness>prev_sharpness:
            print("#############################Sharpness="+str(sharpness))
            must_save=True
            img_to_save=frame
        else:
            if must_save:
                must_save=False
                cv2.imshow("Sharpness", img_to_save)
    
    prev_sharpness=sharpness

    if cv2.waitKey(100) &0XFF == ord('q'):
        break

cv2.destroyAllWindows()