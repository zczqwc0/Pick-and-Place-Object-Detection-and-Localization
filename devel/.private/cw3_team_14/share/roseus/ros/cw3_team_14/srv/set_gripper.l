;; Auto-generated. Do not edit!


(when (boundp 'cw3_team_14::set_gripper)
  (if (not (find-package "CW3_TEAM_14"))
    (make-package "CW3_TEAM_14"))
  (shadow 'set_gripper (find-package "CW3_TEAM_14")))
(unless (find-package "CW3_TEAM_14::SET_GRIPPER")
  (make-package "CW3_TEAM_14::SET_GRIPPER"))
(unless (find-package "CW3_TEAM_14::SET_GRIPPERREQUEST")
  (make-package "CW3_TEAM_14::SET_GRIPPERREQUEST"))
(unless (find-package "CW3_TEAM_14::SET_GRIPPERRESPONSE")
  (make-package "CW3_TEAM_14::SET_GRIPPERRESPONSE"))

(in-package "ROS")





(defclass cw3_team_14::set_gripperRequest
  :super ros::object
  :slots (_finger_distance ))

(defmethod cw3_team_14::set_gripperRequest
  (:init
   (&key
    ((:finger_distance __finger_distance) 0.0)
    )
   (send-super :init)
   (setq _finger_distance (float __finger_distance))
   self)
  (:finger_distance
   (&optional __finger_distance)
   (if __finger_distance (setq _finger_distance __finger_distance)) _finger_distance)
  (:serialization-length
   ()
   (+
    ;; float64 _finger_distance
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _finger_distance
       (sys::poke _finger_distance (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _finger_distance
     (setq _finger_distance (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass cw3_team_14::set_gripperResponse
  :super ros::object
  :slots (_success ))

(defmethod cw3_team_14::set_gripperResponse
  (:init
   (&key
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _success __success)
   self)
  (:success
   (&optional (__success :null))
   (if (not (eq __success :null)) (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass cw3_team_14::set_gripper
  :super ros::object
  :slots ())

(setf (get cw3_team_14::set_gripper :md5sum-) "a328c0db6d1f73db097d15f13b92a27a")
(setf (get cw3_team_14::set_gripper :datatype-) "cw3_team_14/set_gripper")
(setf (get cw3_team_14::set_gripper :request) cw3_team_14::set_gripperRequest)
(setf (get cw3_team_14::set_gripper :response) cw3_team_14::set_gripperResponse)

(defmethod cw3_team_14::set_gripperRequest
  (:response () (instance cw3_team_14::set_gripperResponse :init)))

(setf (get cw3_team_14::set_gripperRequest :md5sum-) "a328c0db6d1f73db097d15f13b92a27a")
(setf (get cw3_team_14::set_gripperRequest :datatype-) "cw3_team_14/set_gripperRequest")
(setf (get cw3_team_14::set_gripperRequest :definition-)
      "float64 finger_distance
---
bool success
")

(setf (get cw3_team_14::set_gripperResponse :md5sum-) "a328c0db6d1f73db097d15f13b92a27a")
(setf (get cw3_team_14::set_gripperResponse :datatype-) "cw3_team_14/set_gripperResponse")
(setf (get cw3_team_14::set_gripperResponse :definition-)
      "float64 finger_distance
---
bool success
")



(provide :cw3_team_14/set_gripper "a328c0db6d1f73db097d15f13b92a27a")


