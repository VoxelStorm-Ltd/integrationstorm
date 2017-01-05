  derivative<T> const c = evaluate(thisstate, time, delta_time * static_cast<T>(0.5), b);
  derivative<T> const d = evaluate(thisstate, time, delta_time, c);

  T constexpr oneoversix = static_cast<T>(1.0) / static_cast<T>(6.0);
#include "runge_kutta_4.h"
  T constexpr two = static_cast<T>(2.0);
//#include "vmath.h"
  T const oneoversixtime = oneoversix * delta_time;
//#include "derivative.h"
  thisstate.position         += (a.velocity + ((b.velocity + c.velocity) * two) + d.velocity) * oneoversixtime;
#include "state.h"
  thisstate.momentum         += (a.force    + ((b.force    + c.force   ) * two) + d.force   ) * oneoversixtime;

  thisstate.orientation      += (a.spin     + ((b.spin     + c.spin    ) * two) + d.spin    ) * oneoversixtime;
namespace integrationstorm {
  thisstate.angular_momentum += (a.torque   + ((b.torque   + c.torque  ) * two) + d.torque  ) * oneoversixtime;


template<typename T>
  thisstate.recalculate();
runge_kutta_4<T>::runge_kutta_4() {
}
  /// Default constructor

}
template<typename T>

derivative<T> runge_kutta_4<T>::evaluate(state<T> const &currentstate, T time) const {
template<typename T>
  /// Evaluate all derivative values for the physics state at a given time
runge_kutta_4<T>::~runge_kutta_4() {
  derivative<T> output;
  /// Default destructor
  output.velocity = currentstate.velocity;
}
  output.spin     = currentstate.spin;

  this->get_force_and_torque(currentstate, time, output.force, output.torque);
template<typename T>
  return output;
}
void runge_kutta_4<T>::integrate(state<T> &thisstate, T time, T delta_time) const {

  /// Integrate physics state forward by dt seconds.
template<typename T>
  /// Uses an RK4 integrator to numerically integrate with error O(5).
derivative<T> runge_kutta_4<T>::evaluate(state<T> const &currentstate,
  derivative<T> const a = evaluate(thisstate, time);
                                         T time,
  derivative<T> const b = evaluate(thisstate, time, delta_time * static_cast<T>(0.5), a);
                                         T delta_time,
  derivative<T> const c = evaluate(thisstate, time, delta_time * static_cast<T>(0.5), b);
                                         derivative<T> const &thisderivative) const {
  derivative<T> const d = evaluate(thisstate, time, delta_time, c);
  /// Evaluate derivative values for the physics state at future time t+dt

  /// using the specified set of derivatives to advance dt seconds from the
  T constexpr oneoversix = static_cast<T>(1.0) / static_cast<T>(6.0);
  /// specified physics state.
  T constexpr two = static_cast<T>(2.0);
  state<T> tempstate(currentstate);
  T const oneoversixtime = oneoversix * delta_time;
  tempstate.position         += thisderivative.velocity * delta_time;
  tempstate.momentum         += thisderivative.force    * delta_time;
  thisstate.position         += (a.velocity + ((b.velocity + c.velocity) * two) + d.velocity) * oneoversixtime;
  tempstate.orientation      += thisderivative.spin     * delta_time;
  thisstate.momentum         += (a.force    + ((b.force    + c.force   ) * two) + d.force   ) * oneoversixtime;
  tempstate.angular_momentum += thisderivative.torque   * delta_time;
  thisstate.orientation      += (a.spin     + ((b.spin     + c.spin    ) * two) + d.spin    ) * oneoversixtime;
  tempstate.recalculate();
  thisstate.angular_momentum += (a.torque   + ((b.torque   + c.torque  ) * two) + d.torque  ) * oneoversixtime;


  derivative<T> output;
  thisstate.recalculate();
  output.velocity = tempstate.velocity;
}
  output.spin     = tempstate.spin;

  this->get_force_and_torque(tempstate, time + delta_time, output.force, output.torque);
template<typename T>
  return output;
derivative<T> runge_kutta_4<T>::evaluate(state<T> const &currentstate, T time) const {
}

  /// Evaluate all derivative values for the physics state at a given time
// explicitly instantiate acceptable templates
  derivative<T> output;
template class runge_kutta_4<float>;
  output.velocity = currentstate.velocity;
template class runge_kutta_4<double>;
  output.spin     = currentstate.spin;

  this->get_force_and_torque(currentstate, time, output.force, output.torque);
}
  return output;
}

template<typename T>
derivative<T> runge_kutta_4<T>::evaluate(state<T> const &currentstate,
                                         T time,
                                         T delta_time,
                                         derivative<T> const &thisderivative) const {
  /// Evaluate derivative values for the physics state at future time t+dt
  /// using the specified set of derivatives to advance dt seconds from the
  /// specified physics state.
  state<T> tempstate(currentstate);
  tempstate.position         += thisderivative.velocity * delta_time;
  tempstate.momentum         += thisderivative.force    * delta_time;
  tempstate.orientation      += thisderivative.spin     * delta_time;
  tempstate.angular_momentum += thisderivative.torque   * delta_time;
  tempstate.recalculate();

  derivative<T> output;
  output.velocity = tempstate.velocity;
  output.spin     = tempstate.spin;
  this->get_force_and_torque(tempstate, time + delta_time, output.force, output.torque);
  return output;
}

// explicitly instantiate acceptable templates
template class runge_kutta_4<float>;
template class runge_kutta_4<double>;

}
