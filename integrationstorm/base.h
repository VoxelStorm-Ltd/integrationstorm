#pragma once

#include <functional>
#include "vectorstorm/vector/vector3_forward.h"

namespace integrationstorm {

template<typename T> struct state;

template<typename T, template<typename> class DerivedT>
class base {
protected:
  // pointer to function that calculates force and torque at a given state and time
  std::function<void(state<T> const&, T, vec3<T>&, vec3<T>&)> force_func = [](state<T> const &thisstate [[maybe_unused]],
                                                                              T time                    [[maybe_unused]],
                                                                              vec3<T> &force            [[maybe_unused]],
                                                                              vec3<T> &torque           [[maybe_unused]]){};

protected:
  base();                                                                       // this base class is not to be instantiated
  ~base();                                                                      // prevent destruction through base pointer

public:
  void set_force_func(std::function<void(state<T> const&, T, vec3<T>&, vec3<T>&)> new_func);

  void get_force_and_torque(state<T> const &thisstate, T time, vec3<T> &force, vec3<T> &torque) const;

  void integrate(state<T> &thisstate, T time, T delta_time) const;
};

}
