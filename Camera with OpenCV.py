#  resource for understanding edge detection: https://code.tutsplus.com/tutorials/canny-edge-detector-using-python--cms-30095


import picamera
#import cv2
#import numpy as np
#from matplotlib import pyplot as plt
from time import sleep
import sys

from skimage import io
from skimage import feature
camera = picamera.picamera()

powerOn = 1

camera_side_current = "left"
camera_side_next = "center"

counter = 1

while (powerOn and counter < 3):
    camera.start_preview()
    if camera_side_current == "left":
        print("picture from left side\n")
        camera_side_next = "center"

    elif camera_side_current == "center":
        print("picture from center side\n")
        camera_side_next = "right"

    elif camera_side_current == "right":
        print("picture from right side\n")
        camera_side_next = "left"


    sleep(.3)
    camera.stop_preview()
#sleep(1.7)

    if camera_side_current == "left":
        camera.capture('/home/pi/Desktop/Pictures/Left_Side_%s.jpg' %counter)
        image = io.imread('/home/pi/Desktop/Pictures/Left_Side_%s.jpg')

    elif camera_side_current == "center":
        camera.capture('/home/pi/Desktop/Pictures/Center_Side_%s.jpg' %counter)
        image = io.imread('/home/pi/Desktop/Pictures/Center_Side_%s.jpg')

    elif camera_side_current == "right":
        camera.capture('/home/pi/Desktop/Pictures/Right_Side_%s.jpg' %counter)
        image = io.imread('/home/pi/Desktop/Pictures/Right_Side_%s.jpg')

    print('done with ' + camera_side_current + ' side\n')

    edge = feature.canny(image)
    io.imshow(edge)
    io.show()
    sleep(1.7)
    camera_side_current = camera_side_next

    if camera_side_current == "left":
        counter = counter + 1
        sleep(3)

