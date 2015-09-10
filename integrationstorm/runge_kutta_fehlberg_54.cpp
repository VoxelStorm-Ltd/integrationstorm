#include "runge_kutta_fehlberg_54.h"
#include "vmath.h"

namespace integrationstorm {

template<typename T>
runge_kutta_fehlberg_54<T>::runge_kutta_fehlberg_54() {
  /// Default constructor
}

template<typename T>
runge_kutta_fehlberg_54<T>::~runge_kutta_fehlberg_54() {
  /// Default destructor
}

/*
template<typename T>
void runge_kutta_fehlberg_54<T>::integrate(Vector3<T> &position,
                                           Vector3<T> &velocity,
                                           T time,
                                           T delta_time) const {
  /// adapted from http://www.ma.utexas.edu/CNA/cheney-kincaid/Ccode/CHP10/rk45.c
  /// also see http://people.sc.fsu.edu/~jburkardt/cpp_src/rkf45/rkf45.html
  T const finaltime = time + delta_time;

  // void rk45(float f(float, float), float* t, float* x, float delta_time, float* epsilon)
  Vector3<T> const temp1 = this->get_acceleration(position,
                                                  velocity,                   finaltime) * delta_time;
  Vector3<T> const temp2 = this->get_acceleration(position + temp1 * c21,
                                                  velocity + c20 * delta_time, finaltime) * delta_time;
  Vector3<T> const temp3 = this->get_acceleration(position + temp1 * c31
                                                           + temp2 * c32,
                                                  velocity + c30 * delta_time, finaltime) * delta_time;
  Vector3<T> const temp4 = this->get_acceleration(position + temp1 * c41
                                                           + temp2 * c42
                                                           + temp3 * c43,
                                                  velocity + c40 * delta_time, finaltime) * delta_time;
  Vector3<T> const temp5 = this->get_acceleration(position + temp1 * c51
                                                           + temp2 * c52
                                                           + temp3 * c53
                                                           + temp4 * c54,
                                                  velocity + c50 * delta_time, finaltime) * delta_time;
  Vector3<T> const temp6 = this->get_acceleration(position + temp1 * c61
                                                           + temp2 * c62
                                                           + temp3 * c63
                                                           + temp4 * c64
                                                           + temp5 * c65,
                                                  velocity + c60 * delta_time, finaltime) * delta_time;

  Vector3<T> x4 = position + (temp1 * a1) + (temp3 * a3) + (temp4 * a4) + (temp5 * a5);
  Vector3<T> dx =            (temp1 * b1) + (temp3 * b3) + (temp4 * b4) + (temp5 * b5) + (temp6 * b6);
  // calculate the error in 3 dimensions
  Vector3<T> epsilon(std::fabs(position.x - x4.x),
                     std::fabs(position.y - x4.y),
                     std::fabs(position.z - x4.z));

  position += dx;
  /// NOT COMPLETE - needs to get velocity term properly
  //velocity += get_acceleration(position, velocity, finaltime);
}
*/

template<typename T>
void runge_kutta_fehlberg_54<T>::integrate(state<T> &thisstate, T time, T delta_time) const {
  // TODO
}

// explicitly instantiate acceptable templates
template class runge_kutta_fehlberg_54<float>;
template class runge_kutta_fehlberg_54<double>;

}
