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
    return cv2.matchTemplate(img1, img2, cv2.TM_CCOEFF_NORMED)[0][0]
##########################################################################
# algorithm parameters
proba_similarity_match=0.98
video_file=1 #'video_test1.mp4'
min_sharpness=5
out_folder='sharp_still_frames'
still_duration=10  # 5 frames still needed


print("Extracting sharp still frames from video...")
# set video file path of input video with name and extension
vid_capture = cv2.VideoCapture(video_file)
if vid_capture.isOpened()==False:
    print("Video File not found: "+ video_file)
    quit()

fps = vid_capture.get(cv2.CAP_PROP_FPS)
print(f"Real FPS={fps}")

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
    ret,image = vid_capture.read()
    if not ret:
        break

    if last_image is None:
        last_image=image

    sharpness=getBlurValue(image)
    sharpness_good=sharpness>min_sharpness
    similarity=getSimilarity(image, last_image)
    similarity_good=similarity>proba_similarity_match
    #print ("Sharpness="+str(sharpness)+" Similarity="+str(similarity))

    if sharpness_good and similarity_good:
        nb_frames_still+=1
        must_save=True
        if sharpness>last_sharpness:
            image_to_save=image
            sharpness_save=sharpness
            still_save=similarity
    else:
        if must_save and nb_frames_still>still_duration:
            name = './' + out_folder +'/frame_' + str(index) + '.jpg'
            print ('Saving...' + name+" Sharpness="+str(sharpness_save)+" Still="+str(still_save))
            cv2.imwrite(name, image_to_save)
        must_save=False
        nb_frames_still=0

    last_image=image
    last_sharpness=sharpness

print("End of extraction.")