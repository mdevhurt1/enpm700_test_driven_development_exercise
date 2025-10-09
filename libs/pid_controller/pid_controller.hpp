/**
 * @file pid_controller.hpp
 * @author Marcus Hurt (mhurt@umd.edu)
 * @brief PID controller class definition
 * @version 0.1
 * @date 2025-10-06
 *
 * @copyright Copyright (c) 2025
 *
 * This class contains the declaration of a simple PID controller class.
 */

#pragma once

class PIDController {
 public:
  /**
   * @brief Construct a new PIDController object
   *
   * @param kp - proportional gain
   * @param ki - integral gain
   * @param kd - derivative gain
   */
  PIDController(double kp, double ki, double kd);

  /**
   * @brief Compute the PID controller output velocity command
   *
   * @param setpoint - desired value
   * @param measured_value - current value
   * @param dt - timestep
   * @return double
   */
  double compute(double setpoint, double measured_value, double dt);

  double getKp() const;
  double getKi() const;
  double getKd() const;

  void setKp(double kp);
  void setKi(double ki);
  void setKd(double kd);

  /**
   * @brief Reset the PID controller state (integral and previous error)
   *
   */
  void reset();

 private:
  double kp_;
  double ki_;
  double kd_;
  double integral_;
  double previous_error_;
};