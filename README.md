# IntegrationStorm

A small C++ templated library for iterative integration, by [VoxelStorm](https://github.com/VoxelStorm-Ltd) & [Armchair Software](https://github.com/Armchair-Software).

Developed for use in an unannounced flight simulation for temporally discretised physics engine calculations - a clean-room ground up design, with reference to implementation of [YASim](https://wiki.flightgear.org/YASim) for verification (but not re-using any YASim code).

Not actively maintained, and provided without support, in the hope that it may be useful.

## Dependencies
- [VectorStorm](https://github.com/Armchair-Software/vectorstorm) vector maths library

## Integration algorithms provided:
- Euler
- Runge Kutta 4
- Runge Kutta Fehlberg 54

### Integrator functions
```cpp
  void set_force_func(std::function<void(state<T> const&, T, vec3<T>&, vec3<T>&)> new_func);
  void get_force_and_torque(state<T> const &thisstate, T time, vec3<T> &force, vec3<T> &torque) const;
  void integrate(state<T> &thisstate, T time, T delta_time) const;
```

### State members
```cpp
struct state {
  /// Physics state for the integrator
  // primary physics state
  vec3<T> position;                  // the position of the centre of mass in world coordinates (meters).
  vec3<T> momentum;                  // the momentum in kilogram meters per second.
  quat<T> orientation;               // the orientation represented by a unit quat.
  vec3<T> angular_momentum;          // angular momentum vector.

  // secondary state
  vec3<T> velocity;                  // velocity in meters per second (calculated from momentum).
  quat<T> spin;                      // quaternion rate of change in orientation.
  vec3<T> angular_velocity;          // angular velocity (calculated from angularMomentum).

  // constant state
  T mass = 1.0f;                     // total mass of the rigid body, in kg, equivalent of _airplane._model._body._totalMass in yasim
  T mass_inv = 1.0f;                 // inverse of the mass used to convert momentum to velocity.
  vec3<T> centre_of_gravity;         // centre of gravity of the rigid body, equivalent of _airplane._model._body._cg in yasim
  mat3<T> inertia_tensor;            // inertia tensor, equivalent of _airplane._model._body._tI in yasim
  mat3<T> inertia_tensor_inv;        // cached value of inverted inertia tensor, equivalent of _airplane._model._body._invI in yasim

  float _gyro[3];

  // Externally determined quantities
  float _force[3];
  float _torque[3];
  float _spin[3];

  void recalculate();
};
```

## Usage

```cpp
integrationstorm::runge_kutta_4<double> integrator; // the integrator to use
integrationstorm::state<double> state; // this holds the state for our simulation

state.orientation.assign(1, 0, 0, 0); // assign initial orientation

integrator.set_force_func([this](integrationstorm::state<double> const &thisstate,
                                 double time,
                                 vec3d &force,
                                 vec3d &torque){
  // define the function that returns your model's force and torque over the given time period
});

// in your physics loop:
double time_total = 1000;
constexpr double time_tick = 10;
integrate(state, time_total, time_tick);
// then inspect state and update renderable objects accordingly
```

Full documentation TODO.  Pull requests welcome.
