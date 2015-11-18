#ifndef CRABAPP_H
#define CRABAPP_H

#include "MooseApp.h"

class CrabApp;

template<>
InputParameters validParams<CrabApp>();

class CrabApp : public MooseApp
{
public:
  CrabApp(InputParameters parameters);
  virtual ~CrabApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* CRABAPP_H */
