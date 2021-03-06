/* This Bison file was machine-generated by BNFC */
%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "Absyn.H"
typedef struct yy_buffer_state *YY_BUFFER_STATE;
int yyparse(void);
int yylex(void);
YY_BUFFER_STATE yy_scan_string(const char *str);
void yy_delete_buffer(YY_BUFFER_STATE buf);
int yy_mylinenumber;
int initialize_lexer(FILE * inp);
int yywrap(void)
{
  return 1;
}
void yyerror(const char *str)
{
  extern char *yytext;
  fprintf(stderr,"error: line %d: %s at %s\n", 
    yy_mylinenumber, str, yytext);
}



static Prog* YY_RESULT_Prog_ = 0;
Prog* pProg(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Prog_;
  }
}
Prog* pProg(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Prog_;
  }
}

static Stm* YY_RESULT_Stm_ = 0;
Stm* pStm(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Stm_;
  }
}
Stm* pStm(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Stm_;
  }
}

static Exp* YY_RESULT_Exp_ = 0;
Exp* pExp(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}
Exp* pExp(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

static ExpBool* YY_RESULT_ExpBool_ = 0;
ExpBool* pExpBool(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ExpBool_;
  }
}
ExpBool* pExpBool(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ExpBool_;
  }
}

static ExpNum* YY_RESULT_ExpNum_ = 0;
ExpNum* pExpNum(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ExpNum_;
  }
}
ExpNum* pExpNum(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ExpNum_;
  }
}

static ExpStr* YY_RESULT_ExpStr_ = 0;
ExpStr* pExpStr(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ExpStr_;
  }
}
ExpStr* pExpStr(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ExpStr_;
  }
}

static ListStm* YY_RESULT_ListStm_ = 0;
ListStm* pListStm(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStm_;
  }
}
ListStm* pListStm(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStm_;
  }
}



%}

%union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Prog* prog_;
  Stm* stm_;
  Exp* exp_;
  ExpBool* expbool_;
  ExpNum* expnum_;
  ExpStr* expstr_;
  ListStm* liststm_;
}

%token _ERROR_
%token _SYMB_0    //   :=
%token _SYMB_1    //   print(
%token _SYMB_2    //   )
%token _SYMB_3    //   =
%token _SYMB_4    //   <>
%token _SYMB_5    //   <
%token _SYMB_6    //   >
%token _SYMB_7    //   <=
%token _SYMB_8    //   >=
%token _SYMB_9    //   -
%token _SYMB_10    //   +
%token _SYMB_11    //   *
%token _SYMB_12    //   /
%token _SYMB_13    //   %
%token _SYMB_14    //   length(
%token _SYMB_15    //   position(
%token _SYMB_16    //   ,
%token _SYMB_17    //   (
%token _SYMB_18    //   concatenate(
%token _SYMB_19    //   substring(
%token _SYMB_20    //   ==
%token _SYMB_21    //   !=
%token _SYMB_22    //   ;
%token _SYMB_23    //   and
%token _SYMB_24    //   begin
%token _SYMB_25    //   do
%token _SYMB_26    //   else
%token _SYMB_27    //   end
%token _SYMB_28    //   exit
%token _SYMB_29    //   false
%token _SYMB_30    //   if
%token _SYMB_31    //   not
%token _SYMB_32    //   or
%token _SYMB_33    //   readint
%token _SYMB_34    //   readstr
%token _SYMB_35    //   then
%token _SYMB_36    //   true
%token _SYMB_37    //   while

%type <prog_> Prog
%type <stm_> Stm
%type <exp_> Exp
%type <expbool_> ExpBool3
%type <expnum_> ExpNum2
%type <expnum_> ExpNum3
%type <expnum_> ExpNum4
%type <expnum_> ExpNum5
%type <expnum_> ExpNum
%type <expnum_> ExpNum1
%type <expstr_> ExpStr
%type <expbool_> ExpBool
%type <expbool_> ExpBool1
%type <expbool_> ExpBool2
%type <liststm_> ListStm

%start Prog
%token<string_> _STRING_
%token<int_> _INTEGER_
%token<string_> _IDENT_

%%
Prog : ListStm {  std::reverse($1->begin(),$1->end()) ;$$ = new Program($1); YY_RESULT_Prog_= $$; } 
;
Stm : _IDENT_ _SYMB_0 ExpNum {  $$ = new StmAssignInt($1, $3); YY_RESULT_Stm_= $$; } 
  | _IDENT_ _SYMB_0 ExpStr {  $$ = new StmAssignStr($1, $3); YY_RESULT_Stm_= $$; }
  | _SYMB_30 ExpBool _SYMB_35 Stm {  $$ = new StmIf($2, $4); YY_RESULT_Stm_= $$; }
  | _SYMB_30 ExpBool _SYMB_35 Stm _SYMB_26 Stm {  $$ = new StmIfElse($2, $4, $6); YY_RESULT_Stm_= $$; }
  | _SYMB_37 ExpBool _SYMB_25 Stm {  $$ = new StmWhileFirst($2, $4); YY_RESULT_Stm_= $$; }
  | _SYMB_25 Stm _SYMB_37 ExpBool {  $$ = new StmWhileSecond($2, $4); YY_RESULT_Stm_= $$; }
  | _SYMB_24 ListStm _SYMB_27 {  std::reverse($2->begin(),$2->end()) ;$$ = new StmBlock($2); YY_RESULT_Stm_= $$; }
  | _SYMB_1 Exp _SYMB_2 {  $$ = new StmOutput($2); YY_RESULT_Stm_= $$; }
  | _SYMB_28 {  $$ = new StmExit(); YY_RESULT_Stm_= $$; }
;
Exp : ExpNum {  $$ = new ExpIsNum($1); YY_RESULT_Exp_= $$; } 
  | ExpStr {  $$ = new ExpIsStr($1); YY_RESULT_Exp_= $$; }
;
ExpBool3 : ExpNum _SYMB_3 ExpNum1 {  $$ = new Eeq($1, $3); YY_RESULT_ExpBool_= $$; } 
  | ExpNum _SYMB_4 ExpNum1 {  $$ = new Eneq($1, $3); YY_RESULT_ExpBool_= $$; }
  | ExpNum1 _SYMB_5 ExpNum2 {  $$ = new Elt($1, $3); YY_RESULT_ExpBool_= $$; }
  | ExpNum1 _SYMB_6 ExpNum2 {  $$ = new Egt($1, $3); YY_RESULT_ExpBool_= $$; }
  | ExpNum1 _SYMB_7 ExpNum2 {  $$ = new Ele($1, $3); YY_RESULT_ExpBool_= $$; }
  | ExpNum1 _SYMB_8 ExpNum2 {  $$ = new Ege($1, $3); YY_RESULT_ExpBool_= $$; }
  | _SYMB_31 ExpBool3 {  $$ = new NotExp($2); YY_RESULT_ExpBool_= $$; }
  | _SYMB_36 {  $$ = new TrueVal(); YY_RESULT_ExpBool_= $$; }
  | _SYMB_29 {  $$ = new FalseVal(); YY_RESULT_ExpBool_= $$; }
  | _SYMB_17 ExpBool _SYMB_2 {  $$ = $2; YY_RESULT_ExpBool_= $$; }
;
ExpNum2 : _SYMB_9 ExpNum2 {  $$ = new EMinus($2); YY_RESULT_ExpNum_= $$; } 
  | ExpNum2 _SYMB_10 ExpNum3 {  $$ = new EAdd($1, $3); YY_RESULT_ExpNum_= $$; }
  | ExpNum2 _SYMB_9 ExpNum3 {  $$ = new ESub($1, $3); YY_RESULT_ExpNum_= $$; }
  | ExpNum3 {  $$ = $1; YY_RESULT_ExpNum_= $$; }
;
ExpNum3 : ExpNum3 _SYMB_11 ExpNum4 {  $$ = new EMul($1, $3); YY_RESULT_ExpNum_= $$; } 
  | ExpNum3 _SYMB_12 ExpNum4 {  $$ = new EDiv($1, $3); YY_RESULT_ExpNum_= $$; }
  | ExpNum4 {  $$ = $1; YY_RESULT_ExpNum_= $$; }
;
ExpNum4 : ExpNum4 _SYMB_13 ExpNum5 {  $$ = new EMod($1, $3); YY_RESULT_ExpNum_= $$; } 
  | ExpNum5 {  $$ = $1; YY_RESULT_ExpNum_= $$; }
;
ExpNum5 : _INTEGER_ {  $$ = new EInt($1); YY_RESULT_ExpNum_= $$; } 
  | _IDENT_ {  $$ = new ENumVar($1); YY_RESULT_ExpNum_= $$; }
  | _SYMB_33 {  $$ = new StmReadInt(); YY_RESULT_ExpNum_= $$; }
  | _SYMB_14 ExpStr _SYMB_2 {  $$ = new StmLength($2); YY_RESULT_ExpNum_= $$; }
  | _SYMB_15 ExpStr _SYMB_16 ExpStr _SYMB_2 {  $$ = new StmPosition($2, $4); YY_RESULT_ExpNum_= $$; }
  | _SYMB_17 ExpNum _SYMB_2 {  $$ = $2; YY_RESULT_ExpNum_= $$; }
;
ExpNum : ExpNum1 {  $$ = $1; YY_RESULT_ExpNum_= $$; } 
;
ExpNum1 : ExpNum2 {  $$ = $1; YY_RESULT_ExpNum_= $$; } 
;
ExpStr : _SYMB_18 ExpStr _SYMB_16 ExpStr _SYMB_2 {  $$ = new StmConcat($2, $4); YY_RESULT_ExpStr_= $$; } 
  | _SYMB_19 ExpStr _SYMB_16 ExpNum _SYMB_16 ExpNum _SYMB_2 {  $$ = new StmSubstr($2, $4, $6); YY_RESULT_ExpStr_= $$; }
  | _STRING_ {  $$ = new EStr($1); YY_RESULT_ExpStr_= $$; }
  | _IDENT_ {  $$ = new EStrVar($1); YY_RESULT_ExpStr_= $$; }
  | _SYMB_34 {  $$ = new StmReadStr(); YY_RESULT_ExpStr_= $$; }
;
ExpBool : ExpBool _SYMB_32 ExpBool1 {  $$ = new OrExp($1, $3); YY_RESULT_ExpBool_= $$; } 
  | ExpBool1 {  $$ = $1; YY_RESULT_ExpBool_= $$; }
;
ExpBool1 : ExpBool1 _SYMB_23 ExpBool2 {  $$ = new AndExp($1, $3); YY_RESULT_ExpBool_= $$; } 
  | ExpBool2 {  $$ = $1; YY_RESULT_ExpBool_= $$; }
;
ExpBool2 : ExpStr _SYMB_20 ExpStr {  $$ = new EStrEq($1, $3); YY_RESULT_ExpBool_= $$; } 
  | ExpStr _SYMB_21 ExpStr {  $$ = new EStrNeq($1, $3); YY_RESULT_ExpBool_= $$; }
  | ExpBool3 {  $$ = $1; YY_RESULT_ExpBool_= $$; }
;
ListStm : /* empty */ {  $$ = new ListStm(); YY_RESULT_ListStm_= $$; } 
  | Stm {  $$ = new ListStm() ; $$->push_back($1); YY_RESULT_ListStm_= $$; }
  | Stm _SYMB_22 ListStm {  $3->push_back($1) ; $$ = $3 ; YY_RESULT_ListStm_= $$; }
;

