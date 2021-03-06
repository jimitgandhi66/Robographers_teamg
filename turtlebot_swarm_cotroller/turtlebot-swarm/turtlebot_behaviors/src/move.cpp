//Low level motion primitives
#include <ros/ros.h>

#include <iostream>
#include <map>

#include <boost/foreach.hpp>

#include <boost/algorithm/clamp.hpp>
#include <boost/range/adaptor/map.hpp>

#include <Eigen/Core>
#include <Eigen/Geometry>

#include <angles/angles.h>

#include <eigen_conversions/eigen_msg.h>

#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

#include "turtlebot_behaviors/turtlebot_behaviors.h"

namespace turtlebot_behaviors {

namespace {

const double LINEAR_VELOCITY = 0.15;

}

void moveForward()
{
  BOOST_FOREACH(const int rid, robot_ids | boost::adaptors::map_values) {
    publishCommand(rid, LINEAR_VELOCITY, 0.0);
  }
}

void moveBackward()
{
  BOOST_FOREACH(const int rid, robot_ids | boost::adaptors::map_values) {
    publishCommand(rid, -LINEAR_VELOCITY, 0.0);
  }
}

void moveStop()
{
  BOOST_FOREACH(const int rid, robot_ids | boost::adaptors::map_values) {
    publishCommand(rid, 0.0, 0.0);
  }
}

} 

