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

#ifndef EELMOMENTUMHRHOUDBC_H
#define EELMOMENTUMHRHOUDBC_H

#include "NodalBC.h"

//Forward Declarations
class EelMomentumHRhoUDBC;

template<>
InputParameters validParams<EelMomentumHRhoUDBC>();

/**
 * Implements a Dirichlet BC where scalar const Variable is coupled in
 */
class EelMomentumHRhoUDBC : public NodalBC
{
public:

  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
  EelMomentumHRhoUDBC(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();

    Real _rhou;
    const VariableValue & _area;
};

#endif // EELMOMENTUMHRHOUDBC_H
