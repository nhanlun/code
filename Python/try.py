import cv2
import numpy as np 

if __name__ == "__main__":
    face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
    cap = cv2.VideoCapture(0)

    while True:
        ret, frame = cap.read()
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        faces = face_cascade.detectMultiScale (
            gray,
            scaleFactor = 1.1,
            minNeighbors = 5,
            minSize = (50, 50),
            flags = cv2.CASCADE_SCALE_IMAGE
        )

        # for (x,y,w,h) in faces:
        #     frame = cv2.rectangle(frame, (x, y), (x+w, y+h), (255,0,0), 3)

        h = frame.shape[0]
        w = frame.shape[1]
        frame = frame[: h // 2, : w // 2, :]
        # print(frame.shape)

        frame1 = cv2.flip(frame, 1)

        frame = np.concatenate([frame, frame1], axis=1)

        frame2 = cv2.flip(frame, 0)

        frame = np.concatenate([frame, frame2], axis=0)

        cv2.imshow('live', frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()
