#include "Expr.h"

// subclass used for numeric literals
class NumberExprAST : public Expr
{
    double val;

public:
    NumberExprAST(double val) : val(val) {}
};