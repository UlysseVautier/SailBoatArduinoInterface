#ifndef XSENS_SENSOR_H
#define XSENS_SENSOR_H

#include <SensorsInterface.h>
#include <sensor_msgs/Imu.h>
#include <XBus.h>

class XSens : public SensorROS{
	public:
		XSens(uint8_t address = 0x1d) : SensorROS("IMU", &msg, 1), address(address), xbus(address), wokeUp(false){}
		
		void init(ros::NodeHandle* n);
		void updateMeasures();
		void updateTest();
		void communicateData();
		
		float getHeadingYaw(){return xbus.headingYaw;}
		
		float* getQuat(){return xbus.quat;}
		float* getAccel(){return xbus.accel;}
		float* getMag(){return xbus.mag;}
		float* getRot(){return xbus.rot;}
		
	private:
		
		uint8_t address;
		
		bool wokeUp;
		
		sensor_msgs::Imu msg;
		XBus xbus;
};

#endif