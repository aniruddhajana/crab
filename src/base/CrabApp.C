#include "CrabApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<CrabApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

CrabApp::CrabApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  CrabApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  CrabApp::associateSyntax(_syntax, _action_factory);
}

CrabApp::~CrabApp()
{
}

// External entry point for dynamic application loading
extern "C" void CrabApp__registerApps() { CrabApp::registerApps(); }
void
CrabApp::registerApps()
{
  registerApp(CrabApp);
}

// External entry point for dynamic object registration
extern "C" void CrabApp__registerObjects(Factory & factory) { CrabApp::registerObjects(factory); }
void
CrabApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void CrabApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { CrabApp::associateSyntax(syntax, action_factory); }
void
CrabApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
