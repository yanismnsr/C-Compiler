grammar ifcc;

axiom : prog ;

prog : function + ;

function : type IDENTIFIER '(' (type IDENTIFIER (',' type IDENTIFIER)*)? ')' block;

block : '{' ( (instr ';') | block | ifInstr | whileInstr)*  '}' ;

instr : instruction;

instruction :
    returnexp                   # ret
    | declaration               # declareVar
    | affectation               # affect
    | functionCall              # functionCallInstruction
    ;

functionCall : IDENTIFIER '(' (expr (',' expr)*)? ')';

returnexp :
    RETURN expr? ;

declaration :
    type (IDENTIFIER | affectation) (',' (IDENTIFIER | affectation))*
    ;

affectation :
    IDENTIFIER '=' expr
    ;

ifInstr: 'if' '(' expr ')' (instr | block) elseInstr? ;

whileInstr: 'while' '(' expr ')' (instr | block) ;

elseInstr: 'else' (instr | ifInstr | block | whileInstr) ;

expr:
    IDENTIFIER                                                                              # exprIdentifier
    | CONST                                                                                 # exprConst
    | op=(MINUS | ADD | UNARY_NOT | UNARY_NOT_WITH_MINUS) expr                              # unaryExpression
    | expr op=(MULT | DIV) expr                                                             # multdiv
    | expr op=(ADD | MINUS) expr                                                            # addmin
    | expr XOR expr                                                                         # xorOperation
    | '(' expr ')'                                                                          # parenthesis
    | expr COMPARISONOPERATOR expr                                                          # simpleComparison
    | expr CONDOPERATORS expr                                                               # multipleOperatorsComparison
    | functionCall                                                                          # functionCallExpr
    | affectation                                                                           # exprAffectation
    ;

CONDOPERATORS :
    '&' | '|'
    ;

COMPARISONOPERATOR : 
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
XOR : '^';
UNARY_NOT : '!';
UNARY_NOT_WITH_MINUS : '!-';