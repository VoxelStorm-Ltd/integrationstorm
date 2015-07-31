#ifndef INTEGRATIONSTORM_RUNGE_KUTTA_FEHLBERG_54_H_INCLUDED
#define INTEGRATIONSTORM_RUNGE_KUTTA_FEHLBERG_54_H_INCLUDED

#include "base.h"

namespace integrationstorm {

template<typename T>
class runge_kutta_fehlberg_54 : public base<T, runge_kutta_fehlberg_54> {
private:
  // integrator constants adapted from http://www.ma.utexas.edu/CNA/cheney-kincaid/Ccode/CHP10/rk45.c
  static T constexpr a1  = 25.0 / 216.0;
  static T constexpr a2  = 0.0;
  static T constexpr a3  = 1408.0 / 2565.0;
  static T constexpr a4  = 2197.0 / 4104.0;
  static T constexpr a5  = -0.2;
  static T constexpr b1  = 16.0 / 135.0;
  static T constexpr b2  = 0.0;
  static T constexpr b3  = 6656.0 / 12825.0;
  static T constexpr b4  = 28561.0 / 56430.0;
  static T constexpr b5  = -0.1;
  static T constexpr b6  = 2.0 / 55.0;
  static T constexpr c20 = 0.25;
  static T constexpr c21 = 0.25;
  static T constexpr c30 = 0.375;
  static T constexpr c31 = 0.09375;
  static T constexpr c32 = 0.28125;
  static T constexpr c40 = 12.0 / 13.0;
  static T constexpr c41 = 1932.0 / 2197.0;
  static T constexpr c42 = -7200.0 / 2197.0;
  static T constexpr c43 = 7296.0 / 2197.0;
  static T constexpr c50 = 1.0;
  static T constexpr c51 = 439.0 / 216.0;
  static T constexpr c52 = -8.0;
  static T constexpr c53 = c51;
  static T constexpr c54 = -845.0 / 4104.0;
  static T constexpr c60 = 0.5;
  static T constexpr c61 = -8.0 / 27.0;
  static T constexpr c62 = 2.0;
  static T constexpr c63 = -3544.0 / 2565.0;
  static T constexpr c64 = 1859.0 / 4104.0;
  static T constexpr c65 = -0.275;

public:
  runge_kutta_fehlberg_54();
  ~runge_kutta_fehlberg_54();

public:
  void integrate(state<T> &thisstate, T time, T delta_time) const;
};

}

#endif // INTEGRATIONSTORM_RUNGE_KUTTA_FEHLBERG_54_H_INCLUDED
