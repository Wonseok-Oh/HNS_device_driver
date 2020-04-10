#include <string>
#include <cstdint>
#include <iostream>
#include "serial/serial.h"
#include <ros/ros.h>

int main(int argc, char** argv){
   ros::init(argc, argv, "test_serial");
   ros::NodeHandle nh;
   unsigned long baud_rate = 9600;
   uint32_t timeout = 1000;
   std::string port("/dev/ttyACM0");
   serial::Serial my_serial(port, baud_rate, serial::Timeout::simpleTimeout(timeout));
 
   std::cout << "Is the serial port open?";
   if (my_serial.isOpen()) std::cout << " Yes." << std::endl;
   else std::cout << " No." << std::endl;
   std::string input;

   // Input the Test String
   while (ros::ok()){
      std::cout << "Input: ";
      std::cin >> input;
      size_t bytes_wrote = my_serial.write(input);
      std::cout << "Bytes written: " << bytes_wrote << ", Sent input: " << input <<std::endl;
      ros::spinOnce();
   }
   return 0;
}
