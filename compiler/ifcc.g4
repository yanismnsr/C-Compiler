grammar ifcc;

axiom : prog ;

prog : progBegin (intruction ';')* progEnd ;

intruction : 
    return                      # ret
    | RETURN IDENTIFIER         # retIdent
    | declaration               # declareVar
    | affectation               # affect
    ;

return : 
    RETURN (CONST | IDENTIFIER)? ;

declaration : 
    type IDENTIFIER (',' IDENTIFIER)*
    ;

affectation : 
    IDENTIFIER '=' expr
    ;

expr:
    IDENTIFIER                      # exprIdentifier   
    | CONST                         # exprConst
    | expr op=(MULT | DIV) expr     # multdiv
    | expr op=(ADD | MINUS) expr    # addmin
    | '(' expr ')'                  # parenthesis
    | MINUS expr                    # unaryMinus
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