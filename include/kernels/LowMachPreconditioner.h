/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef LOWMACHPRECONDITIONER_H
#define LOWMACHPRECONDITIONER_H

#include "Kernel.h"
#include "EquationOfState.h"

// Forward Declarations
class LowMachPreconditioner;

template<>
InputParameters validParams<LowMachPreconditioner>();

class LowMachPreconditioner : public Kernel
{
public:

  LowMachPreconditioner(const InputParameters & parameters);

protected:

  virtual Real computeQpResidual();

  virtual Real computeQpJacobian();

  virtual Real computeQpOffDiagJacobian( unsigned int jvar );

private:
    // Aux variables:
    const VariableValue & _rhoA;
    const VariableValue & _rhouA_x;
    const VariableValue & _rhouA_y;
    const VariableValue & _rhouA_z;
    const VariableValue & _pressure_old;
    const VariableValue & _pressure_older;
    const VariableValue & _area;
    
    // Equation of state:
    const EquationOfState & _eos;
    
    // Parameters:
    Real _Mach_ref;
    
    // Parameters for jacobian:
    unsigned int _rhoA_nb;
    unsigned int _rhouA_x_nb;
    unsigned int _rhouA_y_nb;
    unsigned int _rhouA_z_nb;
};

#endif // LOWMACHPRECONDITIONER_H
