grammar ifcc;

axiom : prog ;

prog : 'int' 'main' '(' ')' block ;

instruction :
    returnexp                   # ret
    | declaration               # declareVar
    | affectation               # affect
    ;

returnexp :
    RETURN expr? ;

declaration :
    type (IDENTIFIER | affectation) (',' (IDENTIFIER | affectation))*
    ;

affectation :
    IDENTIFIER '=' expr
    ;

ifInstr: 'if' '(' expr ')' (instruction | block) elseInstr? ;

elseInstr: 'else' (instruction | ifInstr) ;

block : '{' ( (instruction ';') | block | ifInstr )*  '}' ;

expr:
    IDENTIFIER                                                                              # exprIdentifier
    | CONST                                                                                 # exprConst
    | op=(MINUS | ADD) expr                                                                 # unaryExpression
    | expr op=(MULT | DIV) expr                                                             # multdiv
    | expr op=(ADD | MINUS) expr                                                            # addmin
    | '(' expr ')'                                                                          # parenthesis
    | expr comparisonoperator expr (CONDOPERATORS expr comparisonoperator expr)*            # condition
    ;


comparison : 
    expr comparisonoperator expr
    ;

CONDOPERATORS :
    '&&' | '||'
    ;

comparisonoperator : 
    '==' | '<' | '>' | '<=' | '>=' | '!=';


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
