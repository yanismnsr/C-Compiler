// Generated from /Users/Yanis/Desktop/Scolaire/INSA/Cours/4IFA/PLD-Compilateur/pld-comp/compiler/ifcc.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ifccParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, RETURN=14, IDENTIFIER=15, CONST=16, 
		COMMENT=17, DIRECTIVE=18, WS=19, MULT=20, DIV=21, ADD=22, MINUS=23;
	public static final int
		RULE_axiom = 0, RULE_prog = 1, RULE_intruction = 2, RULE_returnexp = 3, 
		RULE_declaration = 4, RULE_affectation = 5, RULE_expr = 6, RULE_progBegin = 7, 
		RULE_progEnd = 8, RULE_type = 9;
	private static String[] makeRuleNames() {
		return new String[] {
			"axiom", "prog", "intruction", "returnexp", "declaration", "affectation", 
			"expr", "progBegin", "progEnd", "type"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "';'", "','", "'='", "'('", "')'", "'int'", "'main'", "'{'", "'}'", 
			"'char'", "'long'", "'float'", "'double'", "'return'", null, null, null, 
			null, null, "'*'", "'/'", "'+'", "'-'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, "RETURN", "IDENTIFIER", "CONST", "COMMENT", "DIRECTIVE", 
			"WS", "MULT", "DIV", "ADD", "MINUS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "ifcc.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public ifccParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class AxiomContext extends ParserRuleContext {
		public ProgContext prog() {
			return getRuleContext(ProgContext.class,0);
		}
		public AxiomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_axiom; }
	}

	public final AxiomContext axiom() throws RecognitionException {
		AxiomContext _localctx = new AxiomContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_axiom);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(20);
			prog();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProgContext extends ParserRuleContext {
		public ProgBeginContext progBegin() {
			return getRuleContext(ProgBeginContext.class,0);
		}
		public ProgEndContext progEnd() {
			return getRuleContext(ProgEndContext.class,0);
		}
		public List<IntructionContext> intruction() {
			return getRuleContexts(IntructionContext.class);
		}
		public IntructionContext intruction(int i) {
			return getRuleContext(IntructionContext.class,i);
		}
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
	}

	public final ProgContext prog() throws RecognitionException {
		ProgContext _localctx = new ProgContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_prog);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(22);
			progBegin();
			setState(28);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__5) | (1L << T__9) | (1L << T__10) | (1L << T__11) | (1L << T__12) | (1L << RETURN) | (1L << IDENTIFIER))) != 0)) {
				{
				{
				setState(23);
				intruction();
				setState(24);
				match(T__0);
				}
				}
				setState(30);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(31);
			progEnd();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IntructionContext extends ParserRuleContext {
		public IntructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_intruction; }
	 
		public IntructionContext() { }
		public void copyFrom(IntructionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class RetContext extends IntructionContext {
		public ReturnexpContext returnexp() {
			return getRuleContext(ReturnexpContext.class,0);
		}
		public RetContext(IntructionContext ctx) { copyFrom(ctx); }
	}
	public static class AffectContext extends IntructionContext {
		public AffectationContext affectation() {
			return getRuleContext(AffectationContext.class,0);
		}
		public AffectContext(IntructionContext ctx) { copyFrom(ctx); }
	}
	public static class DeclareVarContext extends IntructionContext {
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public DeclareVarContext(IntructionContext ctx) { copyFrom(ctx); }
	}

	public final IntructionContext intruction() throws RecognitionException {
		IntructionContext _localctx = new IntructionContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_intruction);
		try {
			setState(36);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case RETURN:
				_localctx = new RetContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(33);
				returnexp();
				}
				break;
			case T__5:
			case T__9:
			case T__10:
			case T__11:
			case T__12:
				_localctx = new DeclareVarContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(34);
				declaration();
				}
				break;
			case IDENTIFIER:
				_localctx = new AffectContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(35);
				affectation();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ReturnexpContext extends ParserRuleContext {
		public TerminalNode RETURN() { return getToken(ifccParser.RETURN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ReturnexpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_returnexp; }
	}

	public final ReturnexpContext returnexp() throws RecognitionException {
		ReturnexpContext _localctx = new ReturnexpContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_returnexp);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(38);
			match(RETURN);
			setState(40);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__3) | (1L << IDENTIFIER) | (1L << CONST) | (1L << ADD) | (1L << MINUS))) != 0)) {
				{
				setState(39);
				expr(0);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public List<TerminalNode> IDENTIFIER() { return getTokens(ifccParser.IDENTIFIER); }
		public TerminalNode IDENTIFIER(int i) {
			return getToken(ifccParser.IDENTIFIER, i);
		}
		public List<AffectationContext> affectation() {
			return getRuleContexts(AffectationContext.class);
		}
		public AffectationContext affectation(int i) {
			return getRuleContext(AffectationContext.class,i);
		}
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(42);
			type();
			setState(45);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				{
				setState(43);
				match(IDENTIFIER);
				}
				break;
			case 2:
				{
				setState(44);
				affectation();
				}
				break;
			}
			setState(54);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__1) {
				{
				{
				setState(47);
				match(T__1);
				setState(50);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
				case 1:
					{
					setState(48);
					match(IDENTIFIER);
					}
					break;
				case 2:
					{
					setState(49);
					affectation();
					}
					break;
				}
				}
				}
				setState(56);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AffectationContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(ifccParser.IDENTIFIER, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public AffectationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_affectation; }
	}

	public final AffectationContext affectation() throws RecognitionException {
		AffectationContext _localctx = new AffectationContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_affectation);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(57);
			match(IDENTIFIER);
			setState(58);
			match(T__2);
			setState(59);
			expr(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	 
		public ExprContext() { }
		public void copyFrom(ExprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class MultdivContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode MULT() { return getToken(ifccParser.MULT, 0); }
		public TerminalNode DIV() { return getToken(ifccParser.DIV, 0); }
		public MultdivContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class AddminContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode ADD() { return getToken(ifccParser.ADD, 0); }
		public TerminalNode MINUS() { return getToken(ifccParser.MINUS, 0); }
		public AddminContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprIdentifierContext extends ExprContext {
		public TerminalNode IDENTIFIER() { return getToken(ifccParser.IDENTIFIER, 0); }
		public ExprIdentifierContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class UnaryExpressionContext extends ExprContext {
		public Token op;
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode MINUS() { return getToken(ifccParser.MINUS, 0); }
		public TerminalNode ADD() { return getToken(ifccParser.ADD, 0); }
		public UnaryExpressionContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprConstContext extends ExprContext {
		public TerminalNode CONST() { return getToken(ifccParser.CONST, 0); }
		public ExprConstContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ParenthesisContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ParenthesisContext(ExprContext ctx) { copyFrom(ctx); }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 12;
		enterRecursionRule(_localctx, 12, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(70);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENTIFIER:
				{
				_localctx = new ExprIdentifierContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(62);
				match(IDENTIFIER);
				}
				break;
			case CONST:
				{
				_localctx = new ExprConstContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(63);
				match(CONST);
				}
				break;
			case ADD:
			case MINUS:
				{
				_localctx = new UnaryExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(64);
				((UnaryExpressionContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==ADD || _la==MINUS) ) {
					((UnaryExpressionContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(65);
				expr(4);
				}
				break;
			case T__3:
				{
				_localctx = new ParenthesisContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(66);
				match(T__3);
				setState(67);
				expr(0);
				setState(68);
				match(T__4);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(80);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(78);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
					case 1:
						{
						_localctx = new MultdivContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(72);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(73);
						((MultdivContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==MULT || _la==DIV) ) {
							((MultdivContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(74);
						expr(4);
						}
						break;
					case 2:
						{
						_localctx = new AddminContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(75);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(76);
						((AddminContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==ADD || _la==MINUS) ) {
							((AddminContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(77);
						expr(3);
						}
						break;
					}
					} 
				}
				setState(82);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ProgBeginContext extends ParserRuleContext {
		public ProgBeginContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_progBegin; }
	}

	public final ProgBeginContext progBegin() throws RecognitionException {
		ProgBeginContext _localctx = new ProgBeginContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_progBegin);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(83);
			match(T__5);
			setState(84);
			match(T__6);
			setState(85);
			match(T__3);
			setState(86);
			match(T__4);
			setState(87);
			match(T__7);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProgEndContext extends ParserRuleContext {
		public ProgEndContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_progEnd; }
	}

	public final ProgEndContext progEnd() throws RecognitionException {
		ProgEndContext _localctx = new ProgEndContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_progEnd);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(89);
			match(T__8);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeContext extends ParserRuleContext {
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(91);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__5) | (1L << T__9) | (1L << T__10) | (1L << T__11) | (1L << T__12))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 6:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 3);
		case 1:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\31`\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t\13\3"+
		"\2\3\2\3\3\3\3\3\3\3\3\7\3\35\n\3\f\3\16\3 \13\3\3\3\3\3\3\4\3\4\3\4\5"+
		"\4\'\n\4\3\5\3\5\5\5+\n\5\3\6\3\6\3\6\5\6\60\n\6\3\6\3\6\3\6\5\6\65\n"+
		"\6\7\6\67\n\6\f\6\16\6:\13\6\3\7\3\7\3\7\3\7\3\b\3\b\3\b\3\b\3\b\3\b\3"+
		"\b\3\b\3\b\5\bI\n\b\3\b\3\b\3\b\3\b\3\b\3\b\7\bQ\n\b\f\b\16\bT\13\b\3"+
		"\t\3\t\3\t\3\t\3\t\3\t\3\n\3\n\3\13\3\13\3\13\2\3\16\f\2\4\6\b\n\f\16"+
		"\20\22\24\2\5\3\2\30\31\3\2\26\27\4\2\b\b\f\17\2a\2\26\3\2\2\2\4\30\3"+
		"\2\2\2\6&\3\2\2\2\b(\3\2\2\2\n,\3\2\2\2\f;\3\2\2\2\16H\3\2\2\2\20U\3\2"+
		"\2\2\22[\3\2\2\2\24]\3\2\2\2\26\27\5\4\3\2\27\3\3\2\2\2\30\36\5\20\t\2"+
		"\31\32\5\6\4\2\32\33\7\3\2\2\33\35\3\2\2\2\34\31\3\2\2\2\35 \3\2\2\2\36"+
		"\34\3\2\2\2\36\37\3\2\2\2\37!\3\2\2\2 \36\3\2\2\2!\"\5\22\n\2\"\5\3\2"+
		"\2\2#\'\5\b\5\2$\'\5\n\6\2%\'\5\f\7\2&#\3\2\2\2&$\3\2\2\2&%\3\2\2\2\'"+
		"\7\3\2\2\2(*\7\20\2\2)+\5\16\b\2*)\3\2\2\2*+\3\2\2\2+\t\3\2\2\2,/\5\24"+
		"\13\2-\60\7\21\2\2.\60\5\f\7\2/-\3\2\2\2/.\3\2\2\2\608\3\2\2\2\61\64\7"+
		"\4\2\2\62\65\7\21\2\2\63\65\5\f\7\2\64\62\3\2\2\2\64\63\3\2\2\2\65\67"+
		"\3\2\2\2\66\61\3\2\2\2\67:\3\2\2\28\66\3\2\2\289\3\2\2\29\13\3\2\2\2:"+
		"8\3\2\2\2;<\7\21\2\2<=\7\5\2\2=>\5\16\b\2>\r\3\2\2\2?@\b\b\1\2@I\7\21"+
		"\2\2AI\7\22\2\2BC\t\2\2\2CI\5\16\b\6DE\7\6\2\2EF\5\16\b\2FG\7\7\2\2GI"+
		"\3\2\2\2H?\3\2\2\2HA\3\2\2\2HB\3\2\2\2HD\3\2\2\2IR\3\2\2\2JK\f\5\2\2K"+
		"L\t\3\2\2LQ\5\16\b\6MN\f\4\2\2NO\t\2\2\2OQ\5\16\b\5PJ\3\2\2\2PM\3\2\2"+
		"\2QT\3\2\2\2RP\3\2\2\2RS\3\2\2\2S\17\3\2\2\2TR\3\2\2\2UV\7\b\2\2VW\7\t"+
		"\2\2WX\7\6\2\2XY\7\7\2\2YZ\7\n\2\2Z\21\3\2\2\2[\\\7\13\2\2\\\23\3\2\2"+
		"\2]^\t\4\2\2^\25\3\2\2\2\13\36&*/\648HPR";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}