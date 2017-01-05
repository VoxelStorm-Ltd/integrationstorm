#ifndef INTEGRATIONSTORM_BASE_H_INCLUDED
#define INTEGRATIONSTORM_BASE_H_INCLUDED

#include <functional>
#include "vectorstorm/vector/vector3_forward.h"

namespace integrationstorm {

template<typename T> struct state;

template<typename T, template<typename> class DerivedT>
class base {
protected:
  // pointer to function that calculates force and torque at a given state and time
  std::function<void(state<T> const&, T, vec3<T>&, vec3<T>&)> force_func = [](state<T> const &thisstate __attribute__((__unused__)),
                                                                              T time                    __attribute__((__unused__)),
                                                                              vec3<T> &force         __attribute__((__unused__)),
                                                                              vec3<T> &torque        __attribute__((__unused__))){};

protected:
  ~base();                                                                      // prevent destruction through base pointer

public:
  void set_force_func(std::function<void(state<T> const&, T, vec3<T>&, vec3<T>&)> new_func);

  void get_force_and_torque(state<T> const &thisstate, T time, vec3<T> &force, vec3<T> &torque) const;

  void integrate(state<T> &thisstate, T time, T delta_time) const;
};

}

#endif // INTEGRATIONSTORM_BASE_H_INCLUDED
