#ifndef PRINTER_HEADER
#define PRINTER_HEADER

#include "Absyn.H"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Certain applications may improve performance by changing the buffer size */
#define BUFFER_INITIAL 2000
/* You may wish to change _L_PAREN or _R_PAREN */
#define _L_PAREN '('
#define _R_PAREN ')'

class PrintAbsyn : public Visitor
{
 protected:
  int _n_, _i_;
  /* The following are simple heuristics for rendering terminals */
  /* You may wish to change them */
  void render(Char c);
  void render(String s);
void render(char* s);
  void indent(void);
  void backup(void);
 public:
  PrintAbsyn(void);
  ~PrintAbsyn(void);
  char* print(Visitable* v);

  void visitProg(Prog *p); /* abstract class */
  void visitProgram(Program *p);
  void visitStm(Stm *p); /* abstract class */
  void visitStmAssignInt(StmAssignInt *p);
  void visitStmAssignStr(StmAssignStr *p);
  void visitStmIf(StmIf *p);
  void visitStmIfElse(StmIfElse *p);
  void visitStmWhileFirst(StmWhileFirst *p);
  void visitStmWhileSecond(StmWhileSecond *p);
  void visitStmBlock(StmBlock *p);
  void visitStmOutputNum(StmOutputNum *p);
  void visitStmOutputStr(StmOutputStr *p);
  void visitStmExit(StmExit *p);
  void visitExpBool(ExpBool *p); /* abstract class */
  void visitEeq(Eeq *p);
  void visitEneq(Eneq *p);
  void visitElt(Elt *p);
  void visitEgt(Egt *p);
  void visitEle(Ele *p);
  void visitEge(Ege *p);
  void visitNotExp(NotExp *p);
  void visitTrueVal(TrueVal *p);
  void visitFalseVal(FalseVal *p);
  void visitOrExp(OrExp *p);
  void visitAndExp(AndExp *p);
  void visitEStrEq(EStrEq *p);
  void visitEStrNeq(EStrNeq *p);
  void visitExpNum(ExpNum *p); /* abstract class */
  void visitEMinus(EMinus *p);
  void visitEAdd(EAdd *p);
  void visitESub(ESub *p);
  void visitEMul(EMul *p);
  void visitEDiv(EDiv *p);
  void visitEMod(EMod *p);
  void visitEInt(EInt *p);
  void visitENumVar(ENumVar *p);
  void visitStmReadInt(StmReadInt *p);
  void visitStmLength(StmLength *p);
  void visitStmPosition(StmPosition *p);
  void visitExpStr(ExpStr *p); /* abstract class */
  void visitStmConcat(StmConcat *p);
  void visitStmSubstr(StmSubstr *p);
  void visitEStr(EStr *p);
  void visitEStrVar(EStrVar *p);
  void visitStmReadStr(StmReadStr *p);
  void visitListStm(ListStm* p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufAppend(String str)
  {
    const char* s = str.c_str();
    bufAppend(s);
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};



class ShowAbsyn : public Visitor
{
 public:
  ShowAbsyn(void);
  ~ShowAbsyn(void);
  char* show(Visitable* v);

  void visitProg(Prog *p); /* abstract class */
  void visitProgram(Program *p);
  void visitStm(Stm *p); /* abstract class */
  void visitStmAssignInt(StmAssignInt *p);
  void visitStmAssignStr(StmAssignStr *p);
  void visitStmIf(StmIf *p);
  void visitStmIfElse(StmIfElse *p);
  void visitStmWhileFirst(StmWhileFirst *p);
  void visitStmWhileSecond(StmWhileSecond *p);
  void visitStmBlock(StmBlock *p);
  void visitStmOutputNum(StmOutputNum *p);
  void visitStmOutputStr(StmOutputStr *p);
  void visitStmExit(StmExit *p);
  void visitExpBool(ExpBool *p); /* abstract class */
  void visitEeq(Eeq *p);
  void visitEneq(Eneq *p);
  void visitElt(Elt *p);
  void visitEgt(Egt *p);
  void visitEle(Ele *p);
  void visitEge(Ege *p);
  void visitNotExp(NotExp *p);
  void visitTrueVal(TrueVal *p);
  void visitFalseVal(FalseVal *p);
  void visitOrExp(OrExp *p);
  void visitAndExp(AndExp *p);
  void visitEStrEq(EStrEq *p);
  void visitEStrNeq(EStrNeq *p);
  void visitExpNum(ExpNum *p); /* abstract class */
  void visitEMinus(EMinus *p);
  void visitEAdd(EAdd *p);
  void visitESub(ESub *p);
  void visitEMul(EMul *p);
  void visitEDiv(EDiv *p);
  void visitEMod(EMod *p);
  void visitEInt(EInt *p);
  void visitENumVar(ENumVar *p);
  void visitStmReadInt(StmReadInt *p);
  void visitStmLength(StmLength *p);
  void visitStmPosition(StmPosition *p);
  void visitExpStr(ExpStr *p); /* abstract class */
  void visitStmConcat(StmConcat *p);
  void visitStmSubstr(StmSubstr *p);
  void visitEStr(EStr *p);
  void visitEStrVar(EStrVar *p);
  void visitStmReadStr(StmReadStr *p);
  void visitListStm(ListStm* p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufAppend(String str)
  {
    const char* s = str.c_str();
    bufAppend(s);
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};




#endif

