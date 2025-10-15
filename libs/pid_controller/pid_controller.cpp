/**
 * @file pid_controller.cpp
 * @author Marcus Hurt (mhurt@umd.edu)
 * @brief PID controller class implementation
 * @version 0.1
 * @date 2025-10-06
 *
 * @copyright Copyright (c) 2025
 *
 * This class implements a simple PID controller.
 */

#include "pid_controller.hpp"

PIDController::PIDController(double kp, double ki, double kd) : kp_(kp), ki_(ki), kd_(kd), previous_error_(0.0), integral_(0.0) {}

double PIDController::compute(double setpoint, double measured_value,
                              double dt) {
  double error = setpoint - measured_value;
  double integral = integral_ + error * dt;
  double derivative = (error - previous_error_) / dt;

  previous_error_ = error;
  integral_ = integral;

  return kp_ * error + kd_ * derivative + ki_ * integral;                
  // return 0.0;
}

double PIDController::getKp() const {
  return kp_;  
}

double PIDController::getKi() const {
  return ki_;
}

double PIDController::getKd() const {
  return kd_;
}

void PIDController::setKp(double kp) {
  kp_ = kp;
}

void PIDController::setKi(double ki) {
  ki_ = ki;
}

void PIDController::setKd(double kd) {
  kd_ = kd;
}

void PIDController::reset() {
  previous_error_ = 0.0;
  integral_ = 0.0;
}