/**
 * @file pid_controller_test.cpp
 * @author Marcus Hurt (mhurt@umd.edu)
 * @brief Test file for PID controller class
 * @version 0.1
 * @date 2025-10-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <gtest/gtest.h>
#include "pid_controller.hpp"

TEST(PIDControllerTest, Constructor)
{
    PIDController pid(1.0, 0.1, 0.05);
    EXPECT_DOUBLE_EQ(pid.getKp(), 1.0);
    EXPECT_DOUBLE_EQ(pid.getKi(), 0.1);
    EXPECT_DOUBLE_EQ(pid.getKd(), 0.05);
}

TEST(PIDControllerTest, Compute)
{
    PIDController pid(1.0, 0.1, 0.05);
    double output = pid.compute(10.0, 8.0, 1.0);

    // error = setpoint - pv = 10.0 - 8.0 = 2.0
    // integral = previous_integral + error * dt = 0 + 2.0 * 1.0 = 2.0
    // derivative = (error - previous_error) / dt = (2.0 - 0) / 1.0 = 2.0
    // output = Kp*error + Ki*integral + Kd*derivative
    // output = 1.0*2.0 + 0.1*2.0 + 0.05*2.0 = 2.0 + 0.2 + 0.1 = 2.3
    EXPECT_DOUBLE_EQ(output, 2.3);
}

TEST(PIDControllerTest, ComputeWithState)
{
    PIDController pid(1.0, 0.1, 0.05);
    pid.compute(10.0, 8.0, 1.0); // First call to set internal state
    double output = pid.compute(10.0, 9.0, 1.0);

    // error = setpoint - pv = 10.0 - 9.0 = 1.0
    // integral = previous_integral + error * dt = 2.0 + 1.0 * 1.0 = 3.0
    // derivative = (error - previous_error) / dt = (1.0 - 2.0) / 1.0 = -1.0
    // output = Kp*error + Ki*integral + Kd*derivative
    // output = 1.0*1.0 + 0.1*3.0 + 0.05*(-1.0) = 1.0 + 0.3 - 0.05 = 1.25
    EXPECT_DOUBLE_EQ(output, 1.25);
}

TEST(PIDControllerTest, Reset)
{
    PIDController pid(1.0, 0.1, 0.05);
    pid.compute(10.0, 8.0, 1.0); // Update internal state
    pid.reset();
    double output = pid.compute(10.0, 8.0, 1.0);

    // After reset, integral and previous_error should be zero
    // error = setpoint - pv = 10.0 - 8.0 = 2.0
    // integral = previous_integral + error * dt = 0 + 2.0 * 1.0 = 2.0
    // derivative = (error - previous_error) / dt = (2.0 - 0) / 1.0 = 2.0
    // output = Kp*error + Ki*integral + Kd*derivative
    // output = 1.0*2.0 + 0.1*2.0 + 0.05*2.0 = 2.0 + 0.2 + 0.1 = 2.3
    EXPECT_DOUBLE_EQ(output, 2.3);
}