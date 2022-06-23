grammar ifcc;

axiom : prog ;

prog : progBegin (intruction ';')* progEnd ;

intruction :
    returnexp                   # ret
    | declaration               # declareVar
    | affectation               # affect
    | if                        # ifInstr
    ;

returnexp :
    RETURN expr? ;

declaration :
    type (IDENTIFIER | affectation) (',' (IDENTIFIER | affectation))*
    ;

affectation :
    IDENTIFIER '=' expr
    ;

if: 'if' '(' expr ')' (instruction | block) else? ;

else: 'else' (instruction | block | if) ;

block : '{' instruction* '}' ;

expr:
    IDENTIFIER                      # exprIdentifier
    | CONST                         # exprConst
    | op=(MINUS | ADD) expr         # unaryExpression
    | expr op=(MULT | DIV) expr     # multdiv
    | expr op=(ADD | MINUS) expr    # addmin
    | '(' expr ')'                  # parenthesis
    ;

progBegin : 'int' 'main' '(' ')' '{' ;
progEnd : '}' ;


type :
    'int'
    | 'char'
    | 'long'
    | 'float'
    | 'double'
    ;
RETURN : 'return' ;
IDENTIFIER : [a-zA-Z_][a-zA-Z0-9]* ;
CONST : [0-9]+ ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
MULT : '*' ;
DIV  : '/' ;
ADD : '+' ;
MINUS : '-' ;
