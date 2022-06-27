grammar ifcc;

axiom : prog ;

prog : 'int' 'main' '(' ')' block ;

instr : instruction;

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

ifInstr: 'if' '(' comparison ')' (instr | block) elseInstr? ;

whileInstr: 'while' '(' comparison ')' (instr | block) ;

elseInstr: 'else' (instr | ifInstr | block | whileInstr) ;

block : '{' ( (instr ';') | block | ifInstr | whileInstr)*  '}' ;

expr:
    IDENTIFIER                                                                              # exprIdentifier
    | CONST                                                                                 # exprConst
    | op=(MINUS | ADD) expr                                                                 # unaryExpression
    | expr op=(MULT | DIV) expr                                                             # multdiv
    | expr op=(ADD | MINUS) expr                                                            # addmin
    | '(' expr ')'                                                                          # parenthesis
    ;



comparison : 
    expr                                            # unaryComparison
    | expr COMPARISONOPERATOR expr                  # simpleComparison
    | comparison CONDOPERATORS comparison           # multipleOperatorsComparison
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
