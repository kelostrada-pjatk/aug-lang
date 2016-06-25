#ifndef INTERPRETER_HEADER
#define INTERPRETER_HEADER
/* You might want to change the above name. */

#include "Absyn.H"


class Interpreter : public Visitor
{
public:
  void visitProg(Prog* p);
  void visitStm(Stm* p);
  void visitExpBool(ExpBool* p);
  void visitExpNum(ExpNum* p);
  void visitExpStr(ExpStr* p);
  void visitProgram(Program* p);
  void visitStmAssignInt(StmAssignInt* p);
  void visitStmAssignStr(StmAssignStr* p);
  void visitStmIf(StmIf* p);
  void visitStmIfElse(StmIfElse* p);
  void visitStmWhileFirst(StmWhileFirst* p);
  void visitStmWhileSecond(StmWhileSecond* p);
  void visitStmBlock(StmBlock* p);
  void visitStmOutputNum(StmOutputNum* p);
  void visitStmOutputStr(StmOutputStr* p);
  void visitStmExit(StmExit* p);
  void visitEeq(Eeq* p);
  void visitEneq(Eneq* p);
  void visitElt(Elt* p);
  void visitEgt(Egt* p);
  void visitEle(Ele* p);
  void visitEge(Ege* p);
  void visitEMinus(EMinus* p);
  void visitEAdd(EAdd* p);
  void visitESub(ESub* p);
  void visitEMul(EMul* p);
  void visitEDiv(EDiv* p);
  void visitEMod(EMod* p);
  void visitEInt(EInt* p);
  void visitENumVar(ENumVar* p);
  void visitStmReadInt(StmReadInt* p);
  void visitStmLength(StmLength* p);
  void visitStmPosition(StmPosition* p);
  void visitStmConcat(StmConcat* p);
  void visitStmSubstr(StmSubstr* p);
  void visitEStr(EStr* p);
  void visitEStrVar(EStrVar* p);
  void visitStmReadStr(StmReadStr* p);
  void visitOrExp(OrExp* p);
  void visitAndExp(AndExp* p);
  void visitEStrEq(EStrEq* p);
  void visitEStrNeq(EStrNeq* p);
  void visitNotExp(NotExp* p);
  void visitTrueVal(TrueVal* p);
  void visitFalseVal(FalseVal* p);
  void visitListStm(ListStm* p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);

};


#endif
