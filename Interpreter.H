#ifndef INTERPRETER_HEADER
#define INTERPRETER_HEADER
/* You might want to change the above name. */

#include "Absyn.H"


class Interpreter : public Visitor
{
public:
  int run(Visitable<void>* v);

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

  bool visitEeq(Eeq* p);
  bool visitEneq(Eneq* p);
  bool visitElt(Elt* p);
  bool visitEgt(Egt* p);
  bool visitEle(Ele* p);
  bool visitEge(Ege* p);

  Integer visitEMinus(EMinus* p);
  Integer visitEAdd(EAdd* p);
  Integer visitESub(ESub* p);
  Integer visitEMul(EMul* p);
  Integer visitEDiv(EDiv* p);
  Integer visitEMod(EMod* p);
  Integer visitEInt(EInt* p);
  Integer visitENumVar(ENumVar* p);
  Integer visitStmReadInt(StmReadInt* p);
  Integer visitStmLength(StmLength* p);
  Integer visitStmPosition(StmPosition* p);

  String visitStmConcat(StmConcat* p);
  String visitStmSubstr(StmSubstr* p);
  String visitEStr(EStr* p);
  String visitEStrVar(EStrVar* p);
  String visitStmReadStr(StmReadStr* p);

  bool visitOrExp(OrExp* p);
  bool visitAndExp(AndExp* p);
  bool visitEStrEq(EStrEq* p);
  bool visitEStrNeq(EStrNeq* p);
  bool visitNotExp(NotExp* p);
  bool visitTrueVal(TrueVal* p);
  bool visitFalseVal(FalseVal* p);

  void visitListStm(ListStm* p);

  Integer visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  String visitString(String s);
  void visitIdent(String s);

};


#endif
