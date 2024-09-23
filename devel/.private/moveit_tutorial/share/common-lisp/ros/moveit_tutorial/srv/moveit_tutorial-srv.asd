
(cl:in-package :asdf)

(defsystem "moveit_tutorial-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "add_collision" :depends-on ("_package_add_collision"))
    (:file "_package_add_collision" :depends-on ("_package"))
    (:file "set_arm" :depends-on ("_package_set_arm"))
    (:file "_package_set_arm" :depends-on ("_package"))
    (:file "set_gripper" :depends-on ("_package_set_gripper"))
    (:file "_package_set_gripper" :depends-on ("_package"))
  ))