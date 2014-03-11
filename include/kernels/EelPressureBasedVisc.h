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

#ifndef EELPRESSUREBASEDVISC_H
#define EELPRESSUREBASEDVISC_H

#include "Kernel.h"
#include "EquationOfState.h"

class EelPressureBasedVisc;

template<>
InputParameters validParams<EelPressureBasedVisc>();
class EelPressureBasedVisc : public Kernel
{
public:

  EelPressureBasedVisc(const std::string & name,
             InputParameters parameters);

protected:
 
  virtual Real computeQpResidual();

  virtual Real computeQpJacobian();

  virtual Real computeQpOffDiagJacobian( unsigned int jvar );

private:
    // Viscosity type:
    enum ViscosityType
    {
        JST = 0,
        HMP = 1,
        ST = 2
    };
    // Name of the viscosity:
    std::string _visc_name;
    MooseEnum _visc_type;
    // Coupled variables
    VariableGradient & _grad_press;
    // Name of the postprocessors:
    std::string _average_press_nm;
    std::string _average_grad_press_nm;
    // Parameter:
    Real _alpha;
};

#endif // EELPRESSUREBASEDVISC_H
