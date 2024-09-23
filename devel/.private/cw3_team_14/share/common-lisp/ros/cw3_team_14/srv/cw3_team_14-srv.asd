
(cl:in-package :asdf)

(defsystem "cw3_team_14-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "example" :depends-on ("_package_example"))
    (:file "_package_example" :depends-on ("_package"))
    (:file "set_arm" :depends-on ("_package_set_arm"))
    (:file "_package_set_arm" :depends-on ("_package"))
    (:file "set_gripper" :depends-on ("_package_set_gripper"))
    (:file "_package_set_gripper" :depends-on ("_package"))
  ))