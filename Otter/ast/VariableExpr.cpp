#include "Expr.h"
#include <string>

// subclass for variables
class VariableExpr : public Expr
{
    std::string name;

public:
    VariableExpr(const std::string &name) : name(name) {}
};