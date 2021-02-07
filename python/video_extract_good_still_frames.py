import cv2
import numpy as np
import os
import cv2

# theses parameters can be changed
proba_similarity_match=0.9
video_file='video_test1.mp4'
min_sharpness=100
out_folder='images_still'
still_duration=10  # 10 frames still needed

##########################################################################

print("Extracting good images from video...")
# set video file path of input video with name and extension
vid_capture = cv2.VideoCapture(video_file)

if not os.path.exists(out_folder):
    os.makedirs(out_folder)

last_image=None
index=-1
nb_frames_still=0
while(True):
    index+=1
    ret,frame = vid_capture.read()
    if not ret:
        break

    if (last_image is None) or (nb_frames_still==0):
        last_image=frame

    if index==100:
        index=101

    sharpness=cv2.Laplacian(frame, cv2.CV_64F).var()
    if sharpness<min_sharpness:
        nb_frames_still=0
        continue

    img_template_probability_match = cv2.matchTemplate(frame, last_image, cv2.TM_CCOEFF_NORMED)[0][0]

    if img_template_probability_match>proba_similarity_match:
        nb_frames_still+=1
    else:
        nb_frames_still=0
        continue

    if nb_frames_still>still_duration:
        name = './' + out_folder +'/frame_' + str(index) + '.jpg'
        print ('Saving...' + name)
        cv2.imwrite(name, frame)
        nb_frames_still=0

print("End of extraction.")