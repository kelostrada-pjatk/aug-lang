/*** BNFC-Generated Visitor Design Pattern Interpreter. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Interpreter.H"



void Interpreter::visitProg(Prog* t) {} //abstract class
void Interpreter::visitStm(Stm* t) {} //abstract class
void Interpreter::visitExpBool(ExpBool* t) {} //abstract class
void Interpreter::visitExpNum(ExpNum* t) {} //abstract class
void Interpreter::visitExpStr(ExpStr* t) {} //abstract class

void Interpreter::visitProgram(Program *program)
{
  /* Code For Program Goes Here */

  program->liststm_->accept(this);

}

void Interpreter::visitStmAssignInt(StmAssignInt *stmassignint)
{
  /* Code For StmAssignInt Goes Here */

  visitIdent(stmassignint->ident_);
  stmassignint->expnum_->accept(this);

}

void Interpreter::visitStmAssignStr(StmAssignStr *stmassignstr)
{
  /* Code For StmAssignStr Goes Here */

  visitIdent(stmassignstr->ident_);
  stmassignstr->expstr_->accept(this);

}

void Interpreter::visitStmIf(StmIf *stmif)
{
  /* Code For StmIf Goes Here */

  stmif->expbool_->accept(this);
  stmif->stm_->accept(this);

}

void Interpreter::visitStmIfElse(StmIfElse *stmifelse)
{
  /* Code For StmIfElse Goes Here */

  stmifelse->expbool_->accept(this);
  stmifelse->stm_1->accept(this);
  stmifelse->stm_2->accept(this);

}

void Interpreter::visitStmWhileFirst(StmWhileFirst *stmwhilefirst)
{
  /* Code For StmWhileFirst Goes Here */

  stmwhilefirst->expbool_->accept(this);
  stmwhilefirst->stm_->accept(this);

}

void Interpreter::visitStmWhileSecond(StmWhileSecond *stmwhilesecond)
{
  /* Code For StmWhileSecond Goes Here */

  stmwhilesecond->stm_->accept(this);
  stmwhilesecond->expbool_->accept(this);

}

void Interpreter::visitStmBlock(StmBlock *stmblock)
{
  /* Code For StmBlock Goes Here */

  stmblock->liststm_->accept(this);

}

void Interpreter::visitStmOutputNum(StmOutputNum *stmoutputnum)
{
  /* Code For StmOutputNum Goes Here */

  stmoutputnum->expnum_->accept(this);

}

void Interpreter::visitStmOutputStr(StmOutputStr *stmoutputstr)
{
  /* Code For StmOutputStr Goes Here */

  stmoutputstr->expstr_->accept(this);

}

void Interpreter::visitStmExit(StmExit *stmexit)
{
  /* Code For StmExit Goes Here */


}

void Interpreter::visitEMinus(EMinus *eminus)
{
  /* Code For EMinus Goes Here */

  eminus->expnum_->accept(this);

}

void Interpreter::visitEAdd(EAdd *eadd)
{
  /* Code For EAdd Goes Here */

  eadd->expnum_1->accept(this);
  eadd->expnum_2->accept(this);

}

void Interpreter::visitESub(ESub *esub)
{
  /* Code For ESub Goes Here */

  esub->expnum_1->accept(this);
  esub->expnum_2->accept(this);

}

void Interpreter::visitEMul(EMul *emul)
{
  /* Code For EMul Goes Here */

  emul->expnum_1->accept(this);
  emul->expnum_2->accept(this);

}

void Interpreter::visitEDiv(EDiv *ediv)
{
  /* Code For EDiv Goes Here */

  ediv->expnum_1->accept(this);
  ediv->expnum_2->accept(this);

}

void Interpreter::visitEMod(EMod *emod)
{
  /* Code For EMod Goes Here */

  emod->expnum_1->accept(this);
  emod->expnum_2->accept(this);

}

void Interpreter::visitEInt(EInt *eint)
{
  /* Code For EInt Goes Here */

  visitInteger(eint->integer_);

}

void Interpreter::visitENumVar(ENumVar *enumvar)
{
  /* Code For ENumVar Goes Here */

  visitIdent(enumvar->ident_);

}

void Interpreter::visitStmReadInt(StmReadInt *stmreadint)
{
  /* Code For StmReadInt Goes Here */


}

void Interpreter::visitStmLength(StmLength *stmlength)
{
  /* Code For StmLength Goes Here */

  stmlength->expstr_->accept(this);

}

void Interpreter::visitStmPosition(StmPosition *stmposition)
{
  /* Code For StmPosition Goes Here */

  stmposition->expstr_1->accept(this);
  stmposition->expstr_2->accept(this);

}

void Interpreter::visitStmConcat(StmConcat *stmconcat)
{
  /* Code For StmConcat Goes Here */

  stmconcat->expstr_1->accept(this);
  stmconcat->expstr_2->accept(this);

}

void Interpreter::visitStmSubstr(StmSubstr *stmsubstr)
{
  /* Code For StmSubstr Goes Here */

  stmsubstr->expstr_->accept(this);
  stmsubstr->expnum_1->accept(this);
  stmsubstr->expnum_2->accept(this);

}

void Interpreter::visitEStr(EStr *estr)
{
  /* Code For EStr Goes Here */

  visitString(estr->string_);

}

void Interpreter::visitEStrVar(EStrVar *estrvar)
{
  /* Code For EStrVar Goes Here */

  visitIdent(estrvar->ident_);

}

void Interpreter::visitStmReadStr(StmReadStr *stmreadstr)
{
  /* Code For StmReadStr Goes Here */


}

void Interpreter::visitEeq(Eeq *eeq)
{
  /* Code For Eeq Goes Here */

  eeq->expnum_1->accept(this);
  eeq->expnum_2->accept(this);

}

void Interpreter::visitEneq(Eneq *eneq)
{
  /* Code For Eneq Goes Here */

  eneq->expnum_1->accept(this);
  eneq->expnum_2->accept(this);

}

void Interpreter::visitElt(Elt *elt)
{
  /* Code For Elt Goes Here */

  elt->expnum_1->accept(this);
  elt->expnum_2->accept(this);

}

void Interpreter::visitEgt(Egt *egt)
{
  /* Code For Egt Goes Here */

  egt->expnum_1->accept(this);
  egt->expnum_2->accept(this);

}

void Interpreter::visitEle(Ele *ele)
{
  /* Code For Ele Goes Here */

  ele->expnum_1->accept(this);
  ele->expnum_2->accept(this);

}

void Interpreter::visitEge(Ege *ege)
{
  /* Code For Ege Goes Here */

  ege->expnum_1->accept(this);
  ege->expnum_2->accept(this);

}

void Interpreter::visitOrExp(OrExp *orexp)
{
  /* Code For OrExp Goes Here */

  orexp->expbool_1->accept(this);
  orexp->expbool_2->accept(this);

}

void Interpreter::visitAndExp(AndExp *andexp)
{
  /* Code For AndExp Goes Here */

  andexp->expbool_1->accept(this);
  andexp->expbool_2->accept(this);

}

void Interpreter::visitEStrEq(EStrEq *estreq)
{
  /* Code For EStrEq Goes Here */

  estreq->expstr_1->accept(this);
  estreq->expstr_2->accept(this);

}

void Interpreter::visitEStrNeq(EStrNeq *estrneq)
{
  /* Code For EStrNeq Goes Here */

  estrneq->expstr_1->accept(this);
  estrneq->expstr_2->accept(this);

}

void Interpreter::visitNotExp(NotExp *notexp)
{
  /* Code For NotExp Goes Here */

  notexp->expbool_->accept(this);

}

void Interpreter::visitTrueVal(TrueVal *trueval)
{
  /* Code For TrueVal Goes Here */


}

void Interpreter::visitFalseVal(FalseVal *falseval)
{
  /* Code For FalseVal Goes Here */


}


void Interpreter::visitListStm(ListStm* liststm)
{
  for (ListStm::iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
  }
}


void Interpreter::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
}

void Interpreter::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void Interpreter::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

void Interpreter::visitString(String x)
{
  /* Code for String Goes Here */
}

void Interpreter::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}



