#ifndef CONTROLSYSTEM_HPP_
#define CONTROLSYSTEM_HPP_

#include <eeros/control/TimeDomain.hpp>
#include <eeros/core/Executor.hpp>
#include <eeros/control/PeripheralInput.hpp>
#include <eeros/control/Mux.hpp>
#include <eeros/control/D.hpp>
#include "customBlocks/FwKinOdom.hpp"
#include "customBlocks/PathPlanner.hpp"
#include "customBlocks/InvKin.hpp"
#include "customBlocks/Controller.hpp"
#include "customBlocks/InvMotMod.hpp"
#include <eeros/control/DeMux.hpp>
#include <eeros/control/PeripheralOutput.hpp>
#include "AutMobRosConstants.hpp"

using namespace eeros::control;

class ControlSystem
{
public:
    ControlSystem(double dt);

    // Define Blocks
    PeripheralInput<> E1, E2;
    Mux<2> E;
    D<eeros::math::Vector2> Ed;
    FwKinOdom fwKinOdom;
    PathPlanner pp;
    InvKin invKin;
    Controller<eeros::math::Vector2> cont;
    InvMotMod<eeros::math::Vector2> invMotMod;
    DeMux<2> M;
    PeripheralOutput<> M1, M2;

    TimeDomain timedomain;
};

#endif // CONTROLSYSTEM_HPP