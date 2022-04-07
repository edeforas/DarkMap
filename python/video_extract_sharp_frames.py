import cv2
import numpy as np
import os
import cv2

##########################################################################
# from https://stackoverflow.com/questions/28717054/calculating-sharpness-of-an-image
def getBlurValue(image):
    canny = cv2.Canny(image, 50,250)
    return np.mean(canny)
##########################################################################

# theses parameters can be changed
video_file='video_test1.mp4'
min_sharpness=4
out_folder='sharp_images'

print("Extracting sharp frames from video...")
# set video file path of input video with name and extension
vid_capture = cv2.VideoCapture(video_file)

if not os.path.exists(out_folder):
    os.makedirs(out_folder)

prev_sharpness=-10000
must_save=False
img_to_save=None
last_saved_image=None
index=0
while(True):
    ret,frame = vid_capture.read()
    if not ret: 
        break

    sharpness=getBlurValue(frame)

    if sharpness>min_sharpness:
        if sharpness>prev_sharpness:
            must_save=True
            img_to_save=frame
        else:
            if must_save:
                must_save=False
 
                name = './' + out_folder +'/frame_' + str(index) + '.jpg'
                print ('Saving...' + name)
                cv2.imwrite(name, img_to_save)
                last_saved_image=img_to_save

    
    prev_sharpness=sharpness
    index=index+1

print("End of extraction.")