
"use strict";

let set_gripper = require('./set_gripper.js')
let pick = require('./pick.js')
let set_arm = require('./set_arm.js')
let remove_collision = require('./remove_collision.js')
let add_collision = require('./add_collision.js')

module.exports = {
  set_gripper: set_gripper,
  pick: pick,
  set_arm: set_arm,
  remove_collision: remove_collision,
  add_collision: add_collision,
};
