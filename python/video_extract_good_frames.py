import cv2
import numpy as np
import os
import cv2

# theses parameters can be changed
proba_similarity_match=0.8
video_file='video_test1.mp4'
min_sharpness=100
out_folder='images'

##########################################################################

print("Extracting good images from video...")
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

    sharpness=cv2.Laplacian(frame, cv2.CV_64F).var()

    if sharpness>min_sharpness:
        if sharpness>prev_sharpness:
            must_save=True
            img_to_save=frame
        else:
            if must_save:
                must_save=False
                # Saves image if not too similar to previous image
                if last_saved_image is not None:
                    img_template_probability_match = cv2.matchTemplate(img_to_save, last_saved_image, cv2.TM_CCOEFF_NORMED)[0][0]
                    if img_template_probability_match>proba_similarity_match:
                        continue # image is too similar

                name = './' + out_folder +'/frame_' + str(index) + '.jpg'
                print ('Saving...' + name)
                cv2.imwrite(name, img_to_save)
                last_saved_image=img_to_save

    
    prev_sharpness=sharpness
    index=index+1

print("End of extraction.")