import cv2
import numpy as np
import os
import cv2

# theses parameters can be changed
proba_similarity_match=0.9
video_file='video_test1.mp4'
min_sharpness=10
out_folder='sharp_still_frames'
still_duration=10  # 10 frames still needed

##########################################################################

print("Extracting sharp still frames from video...")
# set video file path of input video with name and extension
vid_capture = cv2.VideoCapture(video_file)

if not os.path.exists(out_folder):
    os.makedirs(out_folder)

last_image=None
index=-1
nb_frames_still=0
still_image_ref=None
must_save=False
last_sharpness=0
while(True):
    index+=1
    ret,frame = vid_capture.read()
    if not ret:
        break

    if last_image is None:
        last_image=frame

    sharpness=cv2.Laplacian(frame, cv2.CV_64F).std()
    sharpness_good=sharpness>min_sharpness
    still_good=cv2.matchTemplate(frame, last_image, cv2.TM_CCOEFF_NORMED)[0][0]>proba_similarity_match

    if sharpness_good and still_good:
        nb_frames_still+=1
        must_save=True
        if last_sharpness<sharpness:
            image_to_save=frame
    else:
        if must_save and nb_frames_still>still_duration:
            name = './' + out_folder +'/frame_' + str(index) + '.jpg'
            print ('Saving...' + name)
            cv2.imwrite(name, image_to_save)
        must_save=False
        nb_frames_still=0

    last_image=frame
    last_sharpness=sharpness

print("End of extraction.")