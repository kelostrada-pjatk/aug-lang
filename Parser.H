#ifndef PARSER_HEADER_FILE
#define PARSER_HEADER_FILE

#include<vector>
#include<string>


class Prog;
class Stm;
class ExpNum;
class ExpStr;
class ExpBool;
class ListStm;

typedef union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Prog* prog_;
  Stm* stm_;
  ExpNum* expnum_;
  ExpStr* expstr_;
  ExpBool* expbool_;
  ListStm* liststm_;
} YYSTYPE;

Prog* pProg(FILE *inp);
Prog* pProg(const char *str);
Stm* pStm(FILE *inp);
Stm* pStm(const char *str);
ExpNum* pExpNum(FILE *inp);
ExpNum* pExpNum(const char *str);
ExpStr* pExpStr(FILE *inp);
ExpStr* pExpStr(const char *str);
ExpBool* pExpBool(FILE *inp);
ExpBool* pExpBool(const char *str);
ListStm* pListStm(FILE *inp);
ListStm* pListStm(const char *str);



#define _ERROR_ 258
#define _SYMB_0 259
#define _SYMB_1 260
#define _SYMB_2 261
#define _SYMB_3 262
#define _SYMB_4 263
#define _SYMB_5 264
#define _SYMB_6 265
#define _SYMB_7 266
#define _SYMB_8 267
#define _SYMB_9 268
#define _SYMB_10 269
#define _SYMB_11 270
#define _SYMB_12 271
#define _SYMB_13 272
#define _SYMB_14 273
#define _SYMB_15 274
#define _SYMB_16 275
#define _SYMB_17 276
#define _SYMB_18 277
#define _SYMB_19 278
#define _SYMB_20 279
#define _SYMB_21 280
#define _SYMB_22 281
#define _SYMB_23 282
#define _SYMB_24 283
#define _SYMB_25 284
#define _SYMB_26 285
#define _SYMB_27 286
#define _SYMB_28 287
#define _SYMB_29 288
#define _SYMB_30 289
#define _SYMB_31 290
#define _SYMB_32 291
#define _SYMB_33 292
#define _SYMB_34 293
#define _SYMB_35 294
#define _SYMB_36 295
#define _SYMB_37 296
#define _STRING_ 297
#define _INTEGER_ 298
#define _IDENT_ 299

extern YYSTYPE yylval;

#endif
