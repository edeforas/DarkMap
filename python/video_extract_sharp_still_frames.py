import cv2
import numpy as np
import os

##########################################################################
# from https://stackoverflow.com/questions/28717054/calculating-sharpness-of-an-image
def getBlurValue(image):
    canny = cv2.Canny(image, 50,250)
    return np.mean(canny)
##########################################################################
def getSimilarity(img1,img2):
    return cv2.matchTemplate(frame, last_image, cv2.TM_CCOEFF_NORMED)[0][0]
##########################################################################
# theses parameters can be changed
proba_similarity_match=0.9
video_file='video_test1.mp4'
min_sharpness=4
out_folder='sharp_still_frames'
still_duration=5  # 5 frames still needed

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

    sharpness=getBlurValue(frame)
    sharpness_good=sharpness>min_sharpness
    still_good=getSimilarity(frame, last_image)>proba_similarity_match

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