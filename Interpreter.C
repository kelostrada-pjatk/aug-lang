/*** BNFC-Generated Visitor Design Pattern Interpreter. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Interpreter.H"
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <unordered_map>
using namespace std;

unordered_map<Ident, Integer> numVars;
unordered_map<Ident, String> strVars;

int Interpreter::run(Visitable<void> *v)
{
  v->accept(this);
  return 0;
}

void Interpreter::visitProg(Prog* t) {} //abstract class
void Interpreter::visitStm(Stm* t) {} //abstract class
void Interpreter::visitExp(Exp* t) {} //abstract class
void Interpreter::visitExpBool(ExpBool* t) {} //abstract class
void Interpreter::visitExpNum(ExpNum* t) {} //abstract class
void Interpreter::visitExpStr(ExpStr* t) {} //abstract class

void Interpreter::visitProgram(Program *program)
{
  /* Code For Program Goes Here */

  if (program->liststm_) program->liststm_->accept(this);
}

void Interpreter::visitStmAssignInt(StmAssignInt *stmassignint)
{
  /* Code For StmAssignInt Goes Here */

  Ident ident = visitIdent(stmassignint->ident_);
  Integer value = stmassignint->expnum_->accept(this);

  if (strVars.find(ident) != strVars.end()) {
    cout << "Variable " << ident << " is already declared as String" << endl;
    exit(-1);
  }

  numVars[ident] = value;
}

void Interpreter::visitStmAssignStr(StmAssignStr *stmassignstr)
{
  /* Code For StmAssignStr Goes Here */

  Ident ident = visitIdent(stmassignstr->ident_);
  String value = stmassignstr->expstr_->accept(this);

  if (numVars.find(ident) != numVars.end()) {
    cout << "Variable " << ident << " is already declared as Number" << endl;
    exit(-1);
  }

  strVars[ident] = value;
}

void Interpreter::visitStmIf(StmIf *stmif)
{
  /* Code For StmIf Goes Here */

  if (stmif->expbool_->accept(this)) {
    stmif->stm_->accept(this);
  }
}

void Interpreter::visitStmIfElse(StmIfElse *stmifelse)
{
  /* Code For StmIfElse Goes Here */

  if (stmifelse->expbool_->accept(this)) {
    stmifelse->stm_1->accept(this);
  } else {
    stmifelse->stm_2->accept(this);
  }
}

void Interpreter::visitStmWhileFirst(StmWhileFirst *stmwhilefirst)
{
  /* Code For StmWhileFirst Goes Here */

  while (stmwhilefirst->expbool_->accept(this)) {
    stmwhilefirst->stm_->accept(this);
  }
}

void Interpreter::visitStmWhileSecond(StmWhileSecond *stmwhilesecond)
{
  /* Code For StmWhileSecond Goes Here */

  do {
    stmwhilesecond->stm_->accept(this);
  } while (stmwhilesecond->expbool_->accept(this));
}

void Interpreter::visitStmBlock(StmBlock *stmblock)
{
  /* Code For StmBlock Goes Here */

  stmblock->liststm_->accept(this);
}

void Interpreter::visitStmOutput(StmOutput *stmoutput)
{
  /* Code For StmOutput Goes Here */

  String s = stmoutput->exp_->accept(this);

  cout << s << endl;
}

/*
void Interpreter::visitStmOutputNum(StmOutputNum *stmoutputnum)
{
  Integer i = stmoutputnum->expnum_->accept(this);
  printf("%d\n", i);
}

void Interpreter::visitStmOutputStr(StmOutputStr *stmoutputstr)
{
  String s = stmoutputstr->expstr_->accept(this);
  printf("%s\n", s.c_str());
}
*/

void Interpreter::visitStmExit(StmExit *stmexit)
{
  /* Code For StmExit Goes Here */
  exit(0);
}

String Interpreter::visitExpIsNum(ExpIsNum *expisnum)
{
  /* Code For ExpIsNum Goes Here */

  Integer i = expisnum->expnum_->accept(this);
  return to_string(i);
}

String Interpreter::visitExpIsStr(ExpIsStr *expisstr)
{
  /* Code For ExpIsStr Goes Here */

  return expisstr->expstr_->accept(this);
}

Integer Interpreter::visitEMinus(EMinus *eminus)
{
  /* Code For EMinus Goes Here */

  return -eminus->expnum_->accept(this);
}

Integer Interpreter::visitEAdd(EAdd *eadd)
{
  /* Code For EAdd Goes Here */

  return eadd->expnum_1->accept(this) + eadd->expnum_2->accept(this);
}

Integer Interpreter::visitESub(ESub *esub)
{
  /* Code For ESub Goes Here */

  return esub->expnum_1->accept(this) - esub->expnum_2->accept(this);
}

Integer Interpreter::visitEMul(EMul *emul)
{
  /* Code For EMul Goes Here */

  return emul->expnum_1->accept(this) * emul->expnum_2->accept(this);
}

Integer Interpreter::visitEDiv(EDiv *ediv)
{
  /* Code For EDiv Goes Here */

  return ediv->expnum_1->accept(this) / ediv->expnum_2->accept(this);
}

Integer Interpreter::visitEMod(EMod *emod)
{
  /* Code For EMod Goes Here */

  return emod->expnum_1->accept(this) % emod->expnum_2->accept(this);
}

Integer Interpreter::visitEInt(EInt *eint)
{
  /* Code For EInt Goes Here */

  return visitInteger(eint->integer_);
}

Integer Interpreter::visitENumVar(ENumVar *enumvar)
{
  /* Code For ENumVar Goes Here */

  Ident ident = visitIdent(enumvar->ident_);

  return numVars[ident];
}

Integer Interpreter::visitStmReadInt(StmReadInt *stmreadint)
{
  /* Code For StmReadInt Goes Here */

  Integer i;
  cin >> i;
  return i;
}

Integer Interpreter::visitStmLength(StmLength *stmlength)
{
  /* Code For StmLength Goes Here */

  return stmlength->expstr_->accept(this).length();
}

Integer Interpreter::visitStmPosition(StmPosition *stmposition)
{
  /* Code For StmPosition Goes Here */

  String haystack = stmposition->expstr_1->accept(this);
  String needle = stmposition->expstr_2->accept(this);

  return haystack.find(needle) + 1; 
}

String Interpreter::visitStmConcat(StmConcat *stmconcat)
{
  /* Code For StmConcat Goes Here */

  return stmconcat->expstr_1->accept(this) + stmconcat->expstr_2->accept(this);
}

String Interpreter::visitStmSubstr(StmSubstr *stmsubstr)
{
  /* Code For StmSubstr Goes Here */

  String str = stmsubstr->expstr_->accept(this);
  Integer pos = stmsubstr->expnum_1->accept(this);
  Integer len = stmsubstr->expnum_2->accept(this);

  Integer length = str.length();

  if (pos < 1 || pos > length) {
    return "";
  }

  if (pos + len - 1 > length) {
    return str.substr(pos - 1);
  }

  return str.substr(pos - 1, len);
}

String Interpreter::visitEStr(EStr *estr)
{
  /* Code For EStr Goes Here */

  return visitString(estr->string_);
}

String Interpreter::visitEStrVar(EStrVar *estrvar)
{
  /* Code For EStrVar Goes Here */

  Ident ident = visitIdent(estrvar->ident_);

  return strVars[ident];
}

String Interpreter::visitStmReadStr(StmReadStr *stmreadstr)
{
  /* Code For StmReadStr Goes Here */

  String s;
  cin >> s;
  return s;
}

bool Interpreter::visitEeq(Eeq *eeq)
{
  /* Code For Eeq Goes Here */

  return eeq->expnum_1->accept(this) == eeq->expnum_2->accept(this);
}

bool Interpreter::visitEneq(Eneq *eneq)
{
  /* Code For Eneq Goes Here */

  return eneq->expnum_1->accept(this) != eneq->expnum_2->accept(this);
}

bool Interpreter::visitElt(Elt *elt)
{
  /* Code For Elt Goes Here */

  return elt->expnum_1->accept(this) < elt->expnum_2->accept(this);
}

bool Interpreter::visitEgt(Egt *egt)
{
  /* Code For Egt Goes Here */

  return egt->expnum_1->accept(this) > egt->expnum_2->accept(this);
}

bool Interpreter::visitEle(Ele *ele)
{
  /* Code For Ele Goes Here */

  return ele->expnum_1->accept(this) <= ele->expnum_2->accept(this);
}

bool Interpreter::visitEge(Ege *ege)
{
  /* Code For Ege Goes Here */

  return ege->expnum_1->accept(this) >= ege->expnum_2->accept(this);
}

bool Interpreter::visitOrExp(OrExp *orexp)
{
  /* Code For OrExp Goes Here */

  return orexp->expbool_1->accept(this) || orexp->expbool_2->accept(this);
}

bool Interpreter::visitAndExp(AndExp *andexp)
{
  /* Code For AndExp Goes Here */

  return andexp->expbool_1->accept(this) && andexp->expbool_2->accept(this);
}

bool Interpreter::visitEStrEq(EStrEq *estreq)
{
  /* Code For EStrEq Goes Here */

  return estreq->expstr_1->accept(this) == estreq->expstr_2->accept(this);
}

bool Interpreter::visitEStrNeq(EStrNeq *estrneq)
{
  /* Code For EStrNeq Goes Here */

  return estrneq->expstr_1->accept(this) != estrneq->expstr_2->accept(this);
}

bool Interpreter::visitNotExp(NotExp *notexp)
{
  /* Code For NotExp Goes Here */

  return !notexp->expbool_->accept(this);
}

bool Interpreter::visitTrueVal(TrueVal *trueval)
{
  /* Code For TrueVal Goes Here */

  return true;
}

bool Interpreter::visitFalseVal(FalseVal *falseval)
{
  /* Code For FalseVal Goes Here */

  return false;
}


void Interpreter::visitListStm(ListStm* liststm)
{
  for (ListStm::iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
  }
}


Integer Interpreter::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
  return x;
}

void Interpreter::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void Interpreter::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

String Interpreter::visitString(String x)
{
  /* Code for String Goes Here */
  return x;
}

Ident Interpreter::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
  return x;
}



