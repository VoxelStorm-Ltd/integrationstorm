#include "runge_kutta_4.h"
//#include "vmath.h"
//#include "derivative.h"
//#include "state.h"

namespace integrationstorm {

template<typename T>
runge_kutta_4<T>::runge_kutta_4() {
  /// Default constructor
}

template<typename T>
runge_kutta_4<T>::~runge_kutta_4() {
  /// Default destructor
}

template<typename T>
void runge_kutta_4<T>::integrate(state<T> &thisstate, T time, T delta_time) const {
  /// Integrate physics state forward by dt seconds.
  /// Uses an RK4 integrator to numerically integrate with error O(5).
  derivative<T> const a = evaluate(thisstate, time);
  derivative<T> const b = evaluate(thisstate, time, delta_time * static_cast<T>(0.5), a);
  derivative<T> const c = evaluate(thisstate, time, delta_time * static_cast<T>(0.5), b);
  derivative<T> const d = evaluate(thisstate, time, delta_time, c);

  T constexpr oneoversix = static_cast<T>(1.0) / static_cast<T>(6.0);
  T constexpr two = static_cast<T>(2.0);
  T const oneoversixtime = oneoversix * delta_time;
  thisstate.position         += (a.velocity + ((b.velocity + c.velocity) * two) + d.velocity) * oneoversixtime;
  thisstate.momentum         += (a.force    + ((b.force    + c.force   ) * two) + d.force   ) * oneoversixtime;
  thisstate.orientation      += (a.spin     + ((b.spin     + c.spin    ) * two) + d.spin    ) * oneoversixtime;
  thisstate.angular_momentum += (a.torque   + ((b.torque   + c.torque  ) * two) + d.torque  ) * oneoversixtime;

  thisstate.recalculate();
}

template<typename T>
derivative<T> runge_kutta_4<T>::evaluate(state<T> const &currentstate, T time) const {
  /// Evaluate all derivative values for the physics state at a given time
  derivative<T> output;
  output.velocity = currentstate.velocity;
  output.spin     = currentstate.spin;
  this->get_force_and_torque(currentstate, time, output.force, output.torque);
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
