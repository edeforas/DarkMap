import cv2
import numpy as np
import os
import tqdm

##########################################################################
# from https://stackoverflow.com/questions/28717054/calculating-sharpness-of-an-image
def getBlur(image):
    canny = cv2.Canny(image, 50,250)
    return np.mean(canny)
##########################################################################
def getSimilarity(img1,img2):
    return cv2.matchTemplate(img1, img2, cv2.TM_CCOEFF_NORMED)[0][0]
##########################################################################
def extract_sharp_still_frames(video_file, out_folder, min_sharpness=5, still_duration=10, proba_similarity_match=0.98):

    allSharpness=[]
    allSimilarity=[]

    # set video file path of input video with name and extension
    vid_capture = cv2.VideoCapture(video_file)
    if vid_capture.isOpened()==False:
        print("Video File not found: "+ video_file)
        quit()

    fps = vid_capture.get(cv2.CAP_PROP_FPS)
    print(f"Real FPS={fps:.2f}")

    nb_frames = int(vid_capture.get(cv2.CAP_PROP_FRAME_COUNT))
    print(f"Number of frames={nb_frames}")

    if not os.path.exists(out_folder):
        os.makedirs(out_folder)

    last_image=None
    nb_frames_still=0
    still_image_ref=None
    must_save=False
    last_sharpness=0

    for frame in tqdm.tqdm(range(nb_frames)):

        ret,image = vid_capture.read()
        if not ret:
            break
        if last_image is None:
            last_image=image

        sharpness=getBlur(image)
        allSharpness.append(sharpness)
        sharpness_good=sharpness>min_sharpness
        similarity=getSimilarity(image, last_image)
        allSimilarity.append(similarity)

        similarity_good=similarity>proba_similarity_match
        #print (f"Frame={frame} Sharpness={sharpness:.2f} Similarity={similarity:.2f}")

        if sharpness_good and similarity_good:
            nb_frames_still+=1
            must_save=True
            if sharpness>last_sharpness:
                image_to_save=image
                sharpness_save=sharpness
                still_save=similarity
        else:
            if must_save and nb_frames_still>still_duration:
                name = './' + out_folder +'/frame_' + str(frame) + '.jpg'
                print (f'Saving... {name} Sharpness={sharpness_save:.2f} Still={still_save:.2f}')
                cv2.imwrite(name, image_to_save)
            must_save=False
            nb_frames_still=0

        last_image=image
        last_sharpness=sharpness

    return np.array(allSharpness), np.array(allSimilarity)
##############################################################################################

# algorithm parameters
proba_similarity_match=0.8
video_file='../data/stone_1/stone_1.mp4'
min_sharpness=50
out_folder='../data/stone_1/still_frames_from_video'
still_duration=5  # 5 frames still needed
print("Extracting sharp still frames from video...")
sharpness, similarity = extract_sharp_still_frames(video_file, out_folder, min_sharpness, still_duration, proba_similarity_match)

import matplotlib.pyplot as plt
plt.plot(sharpness,label="Sharpness") 
plt.plot(similarity*100.,label="Similarity * 100")
plt.xlabel("Frame")
plt.title(f"Sharpness, similarity*100 for file {video_file}")
plt.legend()
plt.grid()  
plt.savefig(out_folder + "/sharpness_similarity.png")
plt.show()