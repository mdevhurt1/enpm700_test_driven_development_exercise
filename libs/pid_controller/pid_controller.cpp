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

/**
 * @brief Construct a new PIDController object.
 *
 * Initializes the PID controller with the provided gain parameters.
 *
 * @param kp Proportional gain.
 * @param ki Integral gain.
 * @param kd Derivative gain.
 */
PIDController::PIDController(double kp, double ki, double kd)
    : kp_(kp), ki_(ki), kd_(kd), previous_error_(0.0), integral_(0.0) {}

/**
 * @brief Compute the PID control output.
 *
 * Calculates the control output based on the setpoint, measured value, and time
 * step. Uses the PID formula:
 *
 * @f[
 * u(t) = K_p e(t) + K_i \int e(t) dt + K_d \frac{de(t)}{dt}
 * @f]
 *
 * @param setpoint Desired target value.
 * @param measured_value Current measured process value.
 * @param dt Time interval since last computation (in seconds).
 * @return double Control output value.
 */
double PIDController::compute(double setpoint, double measured_value,
                              double dt) {
  double error = setpoint - measured_value;
  double integral = integral_ + error * dt;
  double derivative = (error - previous_error_) / dt;

  previous_error_ = error;
  integral_ = integral;

  return kp_ * error + kd_ * derivative + ki_ * integral;
}

/**
 * @brief Get the proportional gain (Kp).
 *
 * @return double Current proportional gain.
 */
double PIDController::getKp() const { return kp_; }

/**
 * @brief Get the integral gain (Ki).
 *
 * @return double Current integral gain.
 */
double PIDController::getKi() const { return ki_; }

/**
 * @brief Get the derivative gain (Kd).
 *
 * @return double Current derivative gain.
 */
double PIDController::getKd() const { return kd_; }

/**
 * @brief Set a new proportional gain (Kp).
 *
 * @param kp New proportional gain value.
 */
void PIDController::setKp(double kp) { kp_ = kp; }

/**
 * @brief Set a new integral gain (Ki).
 *
 * @param ki New integral gain value.
 */
void PIDController::setKi(double ki) { ki_ = ki; }

/**
 * @brief Set a new derivative gain (Kd).
 *
 * @param kd New derivative gain value.
 */
void PIDController::setKd(double kd) { kd_ = kd; }

/**
 * @brief Reset the PID controller state.
 *
 * Resets the stored integral and previous error values to zero.
 * This is useful when restarting control loops or reinitializing the system.
 */
void PIDController::reset() {
  previous_error_ = 0.0;
  integral_ = 0.0;
}