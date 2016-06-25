/*** BNFC-Generated Pretty Printer and Abstract Syntax Viewer ***/

#include <string>
#include "Printer.H"
#define INDENT_WIDTH 2


//You may wish to change render
void PrintAbsyn::render(Char c)
{
  if (c == '{')
  {
     bufAppend('\n');
     indent();
     bufAppend(c);
     _n_ = _n_ + INDENT_WIDTH;
     bufAppend('\n');
     indent();
  }
  else if (c == '(' || c == '[')
     bufAppend(c);
  else if (c == ')' || c == ']')
  {
     backup();
     bufAppend(c);
  }
  else if (c == '}')
  {
     int t;
     _n_ = _n_ - INDENT_WIDTH;
     for (t=0; t<INDENT_WIDTH; t++) {
       backup();
     }
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == ',')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == ';')
  {
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == 0) return;
  else
  {
     bufAppend(' ');
     bufAppend(c);
     bufAppend(' ');
  }
}
void PrintAbsyn::render(String s_)
{
  const char *s = s_.c_str() ;
  if(strlen(s) > 0)
  {
    bufAppend(s);
    bufAppend(' ');
  }
}
void PrintAbsyn::render(char* s)
{
  if(strlen(s) > 0)
  {
    bufAppend(s);
    bufAppend(' ');
  }
}
void PrintAbsyn::indent()
{
  int n = _n_;
  while (n > 0)
  {
    bufAppend(' ');
    n--;
  }
}
void PrintAbsyn::backup()
{
  if (buf_[cur_ - 1] == ' ')
  {
    buf_[cur_ - 1] = 0;
    cur_--;
  }
}
PrintAbsyn::PrintAbsyn(void)
{
  _i_ = 0; _n_ = 0;
  buf_ = 0;
  bufReset();
}

PrintAbsyn::~PrintAbsyn(void)
{
}

char* PrintAbsyn::print(Visitable *v)
{
  _i_ = 0; _n_ = 0;
  bufReset();
  v->accept(this);
  return buf_;
}
void PrintAbsyn::visitProg(Prog*p) {} //abstract class

void PrintAbsyn::visitProgram(Program* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->liststm_) {_i_ = 0; p->liststm_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStm(Stm*p) {} //abstract class

void PrintAbsyn::visitStmAssignInt(StmAssignInt* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render(":=");
  _i_ = 0; p->expnum_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmAssignStr(StmAssignStr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render(":=");
  _i_ = 0; p->expstr_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmIf(StmIf* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("if");
  _i_ = 0; p->expbool_->accept(this);
  render("then");
  _i_ = 0; p->stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmIfElse(StmIfElse* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("if");
  _i_ = 0; p->expbool_->accept(this);
  render("then");
  _i_ = 0; p->stm_1->accept(this);
  render("else");
  _i_ = 0; p->stm_2->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmWhileFirst(StmWhileFirst* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("while");
  _i_ = 0; p->expbool_->accept(this);
  render("do");
  _i_ = 0; p->stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmWhileSecond(StmWhileSecond* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("do");
  _i_ = 0; p->stm_->accept(this);
  render("while");
  _i_ = 0; p->expbool_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmBlock(StmBlock* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("begin");
  if(p->liststm_) {_i_ = 0; p->liststm_->accept(this);}  render("end");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmOutputNum(StmOutputNum* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("print(");
  _i_ = 0; p->expnum_->accept(this);
  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmOutputStr(StmOutputStr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("print(");
  _i_ = 0; p->expstr_->accept(this);
  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmExit(StmExit* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("exit");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitExpBool(ExpBool*p) {} //abstract class

void PrintAbsyn::visitEeq(Eeq* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 0; p->expnum_1->accept(this);
  render('=');
  _i_ = 1; p->expnum_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEneq(Eneq* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 0; p->expnum_1->accept(this);
  render("<>");
  _i_ = 1; p->expnum_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitElt(Elt* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 1; p->expnum_1->accept(this);
  render('<');
  _i_ = 2; p->expnum_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEgt(Egt* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 1; p->expnum_1->accept(this);
  render('>');
  _i_ = 2; p->expnum_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEle(Ele* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 1; p->expnum_1->accept(this);
  render("<=");
  _i_ = 2; p->expnum_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEge(Ege* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 1; p->expnum_1->accept(this);
  render(">=");
  _i_ = 2; p->expnum_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitNotExp(NotExp* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  render("not");
  _i_ = 3; p->expbool_->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTrueVal(TrueVal* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  render("true");

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitFalseVal(FalseVal* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  render("false");

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOrExp(OrExp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->expbool_1->accept(this);
  render("or");
  _i_ = 1; p->expbool_2->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAndExp(AndExp* p)
{
  int oldi = _i_;
  if (oldi > 1) render(_L_PAREN);

  _i_ = 1; p->expbool_1->accept(this);
  render("and");
  _i_ = 2; p->expbool_2->accept(this);

  if (oldi > 1) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEStrEq(EStrEq* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 0; p->expstr_1->accept(this);
  render("==");
  _i_ = 0; p->expstr_2->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEStrNeq(EStrNeq* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 0; p->expstr_1->accept(this);
  render("!=");
  _i_ = 0; p->expstr_2->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitExpNum(ExpNum*p) {} //abstract class

void PrintAbsyn::visitEMinus(EMinus* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  render('-');
  _i_ = 2; p->expnum_->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAdd(EAdd* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 2; p->expnum_1->accept(this);
  render('+');
  _i_ = 3; p->expnum_2->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitESub(ESub* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 2; p->expnum_1->accept(this);
  render('-');
  _i_ = 3; p->expnum_2->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEMul(EMul* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 3; p->expnum_1->accept(this);
  render('*');
  _i_ = 4; p->expnum_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEDiv(EDiv* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 3; p->expnum_1->accept(this);
  render('/');
  _i_ = 4; p->expnum_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEMod(EMod* p)
{
  int oldi = _i_;
  if (oldi > 4) render(_L_PAREN);

  _i_ = 4; p->expnum_1->accept(this);
  render('%');
  _i_ = 5; p->expnum_2->accept(this);

  if (oldi > 4) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEInt(EInt* p)
{
  int oldi = _i_;
  if (oldi > 5) render(_L_PAREN);

  visitInteger(p->integer_);

  if (oldi > 5) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitENumVar(ENumVar* p)
{
  int oldi = _i_;
  if (oldi > 5) render(_L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 5) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmReadInt(StmReadInt* p)
{
  int oldi = _i_;
  if (oldi > 5) render(_L_PAREN);

  render("readint");

  if (oldi > 5) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmLength(StmLength* p)
{
  int oldi = _i_;
  if (oldi > 5) render(_L_PAREN);

  render("length(");
  _i_ = 0; p->expstr_->accept(this);
  render(')');

  if (oldi > 5) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmPosition(StmPosition* p)
{
  int oldi = _i_;
  if (oldi > 5) render(_L_PAREN);

  render("position(");
  _i_ = 0; p->expstr_1->accept(this);
  render(',');
  _i_ = 0; p->expstr_2->accept(this);
  render(')');

  if (oldi > 5) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitExpStr(ExpStr*p) {} //abstract class

void PrintAbsyn::visitStmConcat(StmConcat* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("concatenate(");
  _i_ = 0; p->expstr_1->accept(this);
  render(',');
  _i_ = 0; p->expstr_2->accept(this);
  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmSubstr(StmSubstr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("substring(");
  _i_ = 0; p->expstr_->accept(this);
  render(',');
  _i_ = 0; p->expnum_1->accept(this);
  render(',');
  _i_ = 0; p->expnum_2->accept(this);
  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEStr(EStr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitString(p->string_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEStrVar(EStrVar* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmReadStr(StmReadStr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("readstr");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListStm(ListStm *liststm)
{
  for (ListStm::const_iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != liststm->end() - 1) render(';');
  }
}void PrintAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void PrintAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void PrintAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void PrintAbsyn::visitString(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void PrintAbsyn::visitIdent(String s)
{
  render(s);
}

ShowAbsyn::ShowAbsyn(void)
{
  buf_ = 0;
  bufReset();
}

ShowAbsyn::~ShowAbsyn(void)
{
}

char* ShowAbsyn::show(Visitable *v)
{
  bufReset();
  v->accept(this);
  return buf_;
}
void ShowAbsyn::visitProg(Prog* p) {} //abstract class

void ShowAbsyn::visitProgram(Program* p)
{
  bufAppend('(');
  bufAppend("Program");
  bufAppend(' ');
  bufAppend('[');
  if (p->liststm_)  p->liststm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitStm(Stm* p) {} //abstract class

void ShowAbsyn::visitStmAssignInt(StmAssignInt* p)
{
  bufAppend('(');
  bufAppend("StmAssignInt");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expnum_)  p->expnum_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitStmAssignStr(StmAssignStr* p)
{
  bufAppend('(');
  bufAppend("StmAssignStr");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expstr_)  p->expstr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitStmIf(StmIf* p)
{
  bufAppend('(');
  bufAppend("StmIf");
  bufAppend(' ');
  bufAppend('[');
  if (p->expbool_)  p->expbool_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitStmIfElse(StmIfElse* p)
{
  bufAppend('(');
  bufAppend("StmIfElse");
  bufAppend(' ');
  bufAppend('[');
  if (p->expbool_)  p->expbool_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  p->stm_1->accept(this);
  bufAppend(' ');
  p->stm_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitStmWhileFirst(StmWhileFirst* p)
{
  bufAppend('(');
  bufAppend("StmWhileFirst");
  bufAppend(' ');
  bufAppend('[');
  if (p->expbool_)  p->expbool_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitStmWhileSecond(StmWhileSecond* p)
{
  bufAppend('(');
  bufAppend("StmWhileSecond");
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->expbool_)  p->expbool_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitStmBlock(StmBlock* p)
{
  bufAppend('(');
  bufAppend("StmBlock");
  bufAppend(' ');
  bufAppend('[');
  if (p->liststm_)  p->liststm_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitStmOutputNum(StmOutputNum* p)
{
  bufAppend('(');
  bufAppend("StmOutputNum");
  bufAppend(' ');
  bufAppend('[');
  if (p->expnum_)  p->expnum_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitStmOutputStr(StmOutputStr* p)
{
  bufAppend('(');
  bufAppend("StmOutputStr");
  bufAppend(' ');
  bufAppend('[');
  if (p->expstr_)  p->expstr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitStmExit(StmExit* p)
{
  bufAppend("StmExit");
}
void ShowAbsyn::visitExpBool(ExpBool* p) {} //abstract class

void ShowAbsyn::visitEeq(Eeq* p)
{
  bufAppend('(');
  bufAppend("Eeq");
  bufAppend(' ');
  p->expnum_1->accept(this);
  bufAppend(' ');
  p->expnum_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEneq(Eneq* p)
{
  bufAppend('(');
  bufAppend("Eneq");
  bufAppend(' ');
  p->expnum_1->accept(this);
  bufAppend(' ');
  p->expnum_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitElt(Elt* p)
{
  bufAppend('(');
  bufAppend("Elt");
  bufAppend(' ');
  p->expnum_1->accept(this);
  bufAppend(' ');
  p->expnum_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEgt(Egt* p)
{
  bufAppend('(');
  bufAppend("Egt");
  bufAppend(' ');
  p->expnum_1->accept(this);
  bufAppend(' ');
  p->expnum_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEle(Ele* p)
{
  bufAppend('(');
  bufAppend("Ele");
  bufAppend(' ');
  p->expnum_1->accept(this);
  bufAppend(' ');
  p->expnum_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEge(Ege* p)
{
  bufAppend('(');
  bufAppend("Ege");
  bufAppend(' ');
  p->expnum_1->accept(this);
  bufAppend(' ');
  p->expnum_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitNotExp(NotExp* p)
{
  bufAppend('(');
  bufAppend("NotExp");
  bufAppend(' ');
  bufAppend('[');
  if (p->expbool_)  p->expbool_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitTrueVal(TrueVal* p)
{
  bufAppend("TrueVal");
}
void ShowAbsyn::visitFalseVal(FalseVal* p)
{
  bufAppend("FalseVal");
}
void ShowAbsyn::visitOrExp(OrExp* p)
{
  bufAppend('(');
  bufAppend("OrExp");
  bufAppend(' ');
  p->expbool_1->accept(this);
  bufAppend(' ');
  p->expbool_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitAndExp(AndExp* p)
{
  bufAppend('(');
  bufAppend("AndExp");
  bufAppend(' ');
  p->expbool_1->accept(this);
  bufAppend(' ');
  p->expbool_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEStrEq(EStrEq* p)
{
  bufAppend('(');
  bufAppend("EStrEq");
  bufAppend(' ');
  p->expstr_1->accept(this);
  bufAppend(' ');
  p->expstr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEStrNeq(EStrNeq* p)
{
  bufAppend('(');
  bufAppend("EStrNeq");
  bufAppend(' ');
  p->expstr_1->accept(this);
  bufAppend(' ');
  p->expstr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitExpNum(ExpNum* p) {} //abstract class

void ShowAbsyn::visitEMinus(EMinus* p)
{
  bufAppend('(');
  bufAppend("EMinus");
  bufAppend(' ');
  bufAppend('[');
  if (p->expnum_)  p->expnum_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEAdd(EAdd* p)
{
  bufAppend('(');
  bufAppend("EAdd");
  bufAppend(' ');
  p->expnum_1->accept(this);
  bufAppend(' ');
  p->expnum_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitESub(ESub* p)
{
  bufAppend('(');
  bufAppend("ESub");
  bufAppend(' ');
  p->expnum_1->accept(this);
  bufAppend(' ');
  p->expnum_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEMul(EMul* p)
{
  bufAppend('(');
  bufAppend("EMul");
  bufAppend(' ');
  p->expnum_1->accept(this);
  bufAppend(' ');
  p->expnum_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEDiv(EDiv* p)
{
  bufAppend('(');
  bufAppend("EDiv");
  bufAppend(' ');
  p->expnum_1->accept(this);
  bufAppend(' ');
  p->expnum_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEMod(EMod* p)
{
  bufAppend('(');
  bufAppend("EMod");
  bufAppend(' ');
  p->expnum_1->accept(this);
  bufAppend(' ');
  p->expnum_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEInt(EInt* p)
{
  bufAppend('(');
  bufAppend("EInt");
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(')');
}
void ShowAbsyn::visitENumVar(ENumVar* p)
{
  bufAppend('(');
  bufAppend("ENumVar");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitStmReadInt(StmReadInt* p)
{
  bufAppend("StmReadInt");
}
void ShowAbsyn::visitStmLength(StmLength* p)
{
  bufAppend('(');
  bufAppend("StmLength");
  bufAppend(' ');
  bufAppend('[');
  if (p->expstr_)  p->expstr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitStmPosition(StmPosition* p)
{
  bufAppend('(');
  bufAppend("StmPosition");
  bufAppend(' ');
  p->expstr_1->accept(this);
  bufAppend(' ');
  p->expstr_2->accept(this);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitExpStr(ExpStr* p) {} //abstract class

void ShowAbsyn::visitStmConcat(StmConcat* p)
{
  bufAppend('(');
  bufAppend("StmConcat");
  bufAppend(' ');
  p->expstr_1->accept(this);
  bufAppend(' ');
  p->expstr_2->accept(this);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitStmSubstr(StmSubstr* p)
{
  bufAppend('(');
  bufAppend("StmSubstr");
  bufAppend(' ');
  bufAppend('[');
  if (p->expstr_)  p->expstr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  p->expnum_1->accept(this);
  bufAppend(' ');
  p->expnum_2->accept(this);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEStr(EStr* p)
{
  bufAppend('(');
  bufAppend("EStr");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
void ShowAbsyn::visitEStrVar(EStrVar* p)
{
  bufAppend('(');
  bufAppend("EStrVar");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitStmReadStr(StmReadStr* p)
{
  bufAppend("StmReadStr");
}
void ShowAbsyn::visitListStm(ListStm *liststm)
{
  for (ListStm::const_iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != liststm->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void ShowAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void ShowAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void ShowAbsyn::visitString(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void ShowAbsyn::visitIdent(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


