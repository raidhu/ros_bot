# ros_bot
autonomous bot using ros and lidar
```
cd catkin_ws
source devel/setup.bash
roscd lino_visualize/rviz
rviz -d navigate.rviz


roslaunch linorobot bringup.launch
roslaunch linorobot navigate.launch

rostopic pub /start_journey std_msgs/Empty -1

rosrun teleop_twist_keyboard teleop_twist_keyboard.py

rostopic pub /path_ready std_msgs/Empty "{}" -1
<include file="$(find follow_waypoints)/launch/follow_waypoints.launch" />
<node pkg="rostopic" type="rostopic" name="path_ready" args="pub /start_journey std_msgs/Empty -1" output="screen"/> 
```

# boot_up service
```
roslaunch linorobot uvbot.launch
sudo systemctl enable roslaunch.service
sudo systemctl start roslaunch.service
sudo systemctl status roslaunch.service
systemctl stop roslaunch.service
systemctl disable roslaunch.service
sudo rm /etc/systemd/system/roslaunch.service
```
