/**
 * @file pid_controller.hpp
 * @author Marcus Hurt (mhurt@umd.edu)
 * @brief PID controller class definition
 * @version 0.1
 * @date 2025-10-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #pragma once


class PIDController {
public:
    PIDController(double kp, double ki, double kd);

    double compute(double setpoint, double measured_value, double dt);

    double getKp() const;
    double getKi() const;
    double getKd() const;

    void reset();

private:
    double kp_;
    double ki_;
    double kd_;
    double integral_;
    double previous_error_;
};