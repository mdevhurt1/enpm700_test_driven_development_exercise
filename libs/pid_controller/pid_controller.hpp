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
    /**
     * @brief Construct a new PIDController object
     * 
     * @param kp 
     * @param ki 
     * @param kd 
     */
    PIDController(double kp, double ki, double kd);

    /**
     * @brief Compute the PID controller output
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