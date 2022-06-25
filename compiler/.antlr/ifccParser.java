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
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, CONDOPERATORS=22, RETURN=23, IDENTIFIER=24, 
		CONST=25, COMMENT=26, DIRECTIVE=27, WS=28, MULT=29, DIV=30, ADD=31, MINUS=32;
	public static final int
		RULE_axiom = 0, RULE_prog = 1, RULE_instruction = 2, RULE_returnexp = 3, 
		RULE_declaration = 4, RULE_affectation = 5, RULE_ifInstr = 6, RULE_elseInstr = 7, 
		RULE_block = 8, RULE_expr = 9, RULE_comparison = 10, RULE_comparisonoperator = 11, 
		RULE_type = 12;
	private static String[] makeRuleNames() {
		return new String[] {
			"axiom", "prog", "instruction", "returnexp", "declaration", "affectation", 
			"ifInstr", "elseInstr", "block", "expr", "comparison", "comparisonoperator", 
			"type"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'int'", "'main'", "'('", "')'", "','", "'='", "'if'", "'else'", 
			"'{'", "';'", "'}'", "'=='", "'<'", "'>'", "'<='", "'>='", "'!='", "'char'", 
			"'long'", "'float'", "'double'", null, "'return'", null, null, null, 
			null, null, "'*'", "'/'", "'+'", "'-'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, "CONDOPERATORS", 
			"RETURN", "IDENTIFIER", "CONST", "COMMENT", "DIRECTIVE", "WS", "MULT", 
			"DIV", "ADD", "MINUS"
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
			setState(26);
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
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
	}

	public final ProgContext prog() throws RecognitionException {
		ProgContext _localctx = new ProgContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_prog);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(28);
			match(T__0);
			setState(29);
			match(T__1);
			setState(30);
			match(T__2);
			setState(31);
			match(T__3);
			setState(32);
			block();
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

	public static class InstructionContext extends ParserRuleContext {
		public InstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_instruction; }
	 
		public InstructionContext() { }
		public void copyFrom(InstructionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class RetContext extends InstructionContext {
		public ReturnexpContext returnexp() {
			return getRuleContext(ReturnexpContext.class,0);
		}
		public RetContext(InstructionContext ctx) { copyFrom(ctx); }
	}
	public static class AffectContext extends InstructionContext {
		public AffectationContext affectation() {
			return getRuleContext(AffectationContext.class,0);
		}
		public AffectContext(InstructionContext ctx) { copyFrom(ctx); }
	}
	public static class DeclareVarContext extends InstructionContext {
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public DeclareVarContext(InstructionContext ctx) { copyFrom(ctx); }
	}

	public final InstructionContext instruction() throws RecognitionException {
		InstructionContext _localctx = new InstructionContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_instruction);
		try {
			setState(37);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case RETURN:
				_localctx = new RetContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(34);
				returnexp();
				}
				break;
			case T__0:
			case T__17:
			case T__18:
			case T__19:
			case T__20:
				_localctx = new DeclareVarContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(35);
				declaration();
				}
				break;
			case IDENTIFIER:
				_localctx = new AffectContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(36);
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
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(39);
			match(RETURN);
			setState(41);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				{
				setState(40);
				expr(0);
				}
				break;
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
			setState(43);
			type();
			setState(46);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				{
				setState(44);
				match(IDENTIFIER);
				}
				break;
			case 2:
				{
				setState(45);
				affectation();
				}
				break;
			}
			setState(55);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(48);
				match(T__4);
				setState(51);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
				case 1:
					{
					setState(49);
					match(IDENTIFIER);
					}
					break;
				case 2:
					{
					setState(50);
					affectation();
					}
					break;
				}
				}
				}
				setState(57);
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
			setState(58);
			match(IDENTIFIER);
			setState(59);
			match(T__5);
			setState(60);
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

	public static class IfInstrContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public InstructionContext instruction() {
			return getRuleContext(InstructionContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public ElseInstrContext elseInstr() {
			return getRuleContext(ElseInstrContext.class,0);
		}
		public IfInstrContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifInstr; }
	}

	public final IfInstrContext ifInstr() throws RecognitionException {
		IfInstrContext _localctx = new IfInstrContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_ifInstr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(62);
			match(T__6);
			setState(63);
			match(T__2);
			setState(64);
			expr(0);
			setState(65);
			match(T__3);
			setState(68);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
			case T__17:
			case T__18:
			case T__19:
			case T__20:
			case RETURN:
			case IDENTIFIER:
				{
				setState(66);
				instruction();
				}
				break;
			case T__8:
				{
				setState(67);
				block();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(71);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__7) {
				{
				setState(70);
				elseInstr();
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

	public static class ElseInstrContext extends ParserRuleContext {
		public InstructionContext instruction() {
			return getRuleContext(InstructionContext.class,0);
		}
		public IfInstrContext ifInstr() {
			return getRuleContext(IfInstrContext.class,0);
		}
		public ElseInstrContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_elseInstr; }
	}

	public final ElseInstrContext elseInstr() throws RecognitionException {
		ElseInstrContext _localctx = new ElseInstrContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_elseInstr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(73);
			match(T__7);
			setState(76);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
			case T__17:
			case T__18:
			case T__19:
			case T__20:
			case RETURN:
			case IDENTIFIER:
				{
				setState(74);
				instruction();
				}
				break;
			case T__6:
				{
				setState(75);
				ifInstr();
				}
				break;
			default:
				throw new NoViableAltException(this);
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

	public static class BlockContext extends ParserRuleContext {
		public List<BlockContext> block() {
			return getRuleContexts(BlockContext.class);
		}
		public BlockContext block(int i) {
			return getRuleContext(BlockContext.class,i);
		}
		public List<IfInstrContext> ifInstr() {
			return getRuleContexts(IfInstrContext.class);
		}
		public IfInstrContext ifInstr(int i) {
			return getRuleContext(IfInstrContext.class,i);
		}
		public List<InstructionContext> instruction() {
			return getRuleContexts(InstructionContext.class);
		}
		public InstructionContext instruction(int i) {
			return getRuleContext(InstructionContext.class,i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(78);
			match(T__8);
			setState(86);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__6) | (1L << T__8) | (1L << T__17) | (1L << T__18) | (1L << T__19) | (1L << T__20) | (1L << RETURN) | (1L << IDENTIFIER))) != 0)) {
				{
				setState(84);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case T__0:
				case T__17:
				case T__18:
				case T__19:
				case T__20:
				case RETURN:
				case IDENTIFIER:
					{
					{
					setState(79);
					instruction();
					setState(80);
					match(T__9);
					}
					}
					break;
				case T__8:
					{
					setState(82);
					block();
					}
					break;
				case T__6:
					{
					setState(83);
					ifInstr();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(88);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(89);
			match(T__10);
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
	public static class ConditionContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<ComparisonoperatorContext> comparisonoperator() {
			return getRuleContexts(ComparisonoperatorContext.class);
		}
		public ComparisonoperatorContext comparisonoperator(int i) {
			return getRuleContext(ComparisonoperatorContext.class,i);
		}
		public List<TerminalNode> CONDOPERATORS() { return getTokens(ifccParser.CONDOPERATORS); }
		public TerminalNode CONDOPERATORS(int i) {
			return getToken(ifccParser.CONDOPERATORS, i);
		}
		public ConditionContext(ExprContext ctx) { copyFrom(ctx); }
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
		int _startState = 18;
		enterRecursionRule(_localctx, 18, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(100);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENTIFIER:
				{
				_localctx = new ExprIdentifierContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(92);
				match(IDENTIFIER);
				}
				break;
			case CONST:
				{
				_localctx = new ExprConstContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(93);
				match(CONST);
				}
				break;
			case ADD:
			case MINUS:
				{
				_localctx = new UnaryExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(94);
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
				setState(95);
				expr(5);
				}
				break;
			case T__2:
				{
				_localctx = new ParenthesisContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(96);
				match(T__2);
				setState(97);
				expr(0);
				setState(98);
				match(T__3);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(123);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(121);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
					case 1:
						{
						_localctx = new MultdivContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(102);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(103);
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
						setState(104);
						expr(5);
						}
						break;
					case 2:
						{
						_localctx = new AddminContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(105);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(106);
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
						setState(107);
						expr(4);
						}
						break;
					case 3:
						{
						_localctx = new ConditionContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(108);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(109);
						comparisonoperator();
						setState(110);
						expr(0);
						setState(118);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
						while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
							if ( _alt==1 ) {
								{
								{
								setState(111);
								match(CONDOPERATORS);
								setState(112);
								expr(0);
								setState(113);
								comparisonoperator();
								setState(114);
								expr(0);
								}
								} 
							}
							setState(120);
							_errHandler.sync(this);
							_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
						}
						}
						break;
					}
					} 
				}
				setState(125);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
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

	public static class ComparisonContext extends ParserRuleContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ComparisonoperatorContext comparisonoperator() {
			return getRuleContext(ComparisonoperatorContext.class,0);
		}
		public ComparisonContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_comparison; }
	}

	public final ComparisonContext comparison() throws RecognitionException {
		ComparisonContext _localctx = new ComparisonContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_comparison);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(126);
			expr(0);
			setState(127);
			comparisonoperator();
			setState(128);
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

	public static class ComparisonoperatorContext extends ParserRuleContext {
		public ComparisonoperatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_comparisonoperator; }
	}

	public final ComparisonoperatorContext comparisonoperator() throws RecognitionException {
		ComparisonoperatorContext _localctx = new ComparisonoperatorContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_comparisonoperator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(130);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__11) | (1L << T__12) | (1L << T__13) | (1L << T__14) | (1L << T__15) | (1L << T__16))) != 0)) ) {
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

	public static class TypeContext extends ParserRuleContext {
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(132);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__17) | (1L << T__18) | (1L << T__19) | (1L << T__20))) != 0)) ) {
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
		case 9:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 4);
		case 1:
			return precpred(_ctx, 3);
		case 2:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\"\u0089\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3\3\4\3\4"+
		"\3\4\5\4(\n\4\3\5\3\5\5\5,\n\5\3\6\3\6\3\6\5\6\61\n\6\3\6\3\6\3\6\5\6"+
		"\66\n\6\7\68\n\6\f\6\16\6;\13\6\3\7\3\7\3\7\3\7\3\b\3\b\3\b\3\b\3\b\3"+
		"\b\5\bG\n\b\3\b\5\bJ\n\b\3\t\3\t\3\t\5\tO\n\t\3\n\3\n\3\n\3\n\3\n\3\n"+
		"\7\nW\n\n\f\n\16\nZ\13\n\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3"+
		"\13\3\13\5\13g\n\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\3\13\3\13\3\13\3\13\7\13w\n\13\f\13\16\13z\13\13\7\13|\n\13\f\13\16\13"+
		"\177\13\13\3\f\3\f\3\f\3\f\3\r\3\r\3\16\3\16\3\16\2\3\24\17\2\4\6\b\n"+
		"\f\16\20\22\24\26\30\32\2\6\3\2!\"\3\2\37 \3\2\16\23\4\2\3\3\24\27\2\u008e"+
		"\2\34\3\2\2\2\4\36\3\2\2\2\6\'\3\2\2\2\b)\3\2\2\2\n-\3\2\2\2\f<\3\2\2"+
		"\2\16@\3\2\2\2\20K\3\2\2\2\22P\3\2\2\2\24f\3\2\2\2\26\u0080\3\2\2\2\30"+
		"\u0084\3\2\2\2\32\u0086\3\2\2\2\34\35\5\4\3\2\35\3\3\2\2\2\36\37\7\3\2"+
		"\2\37 \7\4\2\2 !\7\5\2\2!\"\7\6\2\2\"#\5\22\n\2#\5\3\2\2\2$(\5\b\5\2%"+
		"(\5\n\6\2&(\5\f\7\2\'$\3\2\2\2\'%\3\2\2\2\'&\3\2\2\2(\7\3\2\2\2)+\7\31"+
		"\2\2*,\5\24\13\2+*\3\2\2\2+,\3\2\2\2,\t\3\2\2\2-\60\5\32\16\2.\61\7\32"+
		"\2\2/\61\5\f\7\2\60.\3\2\2\2\60/\3\2\2\2\619\3\2\2\2\62\65\7\7\2\2\63"+
		"\66\7\32\2\2\64\66\5\f\7\2\65\63\3\2\2\2\65\64\3\2\2\2\668\3\2\2\2\67"+
		"\62\3\2\2\28;\3\2\2\29\67\3\2\2\29:\3\2\2\2:\13\3\2\2\2;9\3\2\2\2<=\7"+
		"\32\2\2=>\7\b\2\2>?\5\24\13\2?\r\3\2\2\2@A\7\t\2\2AB\7\5\2\2BC\5\24\13"+
		"\2CF\7\6\2\2DG\5\6\4\2EG\5\22\n\2FD\3\2\2\2FE\3\2\2\2GI\3\2\2\2HJ\5\20"+
		"\t\2IH\3\2\2\2IJ\3\2\2\2J\17\3\2\2\2KN\7\n\2\2LO\5\6\4\2MO\5\16\b\2NL"+
		"\3\2\2\2NM\3\2\2\2O\21\3\2\2\2PX\7\13\2\2QR\5\6\4\2RS\7\f\2\2SW\3\2\2"+
		"\2TW\5\22\n\2UW\5\16\b\2VQ\3\2\2\2VT\3\2\2\2VU\3\2\2\2WZ\3\2\2\2XV\3\2"+
		"\2\2XY\3\2\2\2Y[\3\2\2\2ZX\3\2\2\2[\\\7\r\2\2\\\23\3\2\2\2]^\b\13\1\2"+
		"^g\7\32\2\2_g\7\33\2\2`a\t\2\2\2ag\5\24\13\7bc\7\5\2\2cd\5\24\13\2de\7"+
		"\6\2\2eg\3\2\2\2f]\3\2\2\2f_\3\2\2\2f`\3\2\2\2fb\3\2\2\2g}\3\2\2\2hi\f"+
		"\6\2\2ij\t\3\2\2j|\5\24\13\7kl\f\5\2\2lm\t\2\2\2m|\5\24\13\6no\f\3\2\2"+
		"op\5\30\r\2px\5\24\13\2qr\7\30\2\2rs\5\24\13\2st\5\30\r\2tu\5\24\13\2"+
		"uw\3\2\2\2vq\3\2\2\2wz\3\2\2\2xv\3\2\2\2xy\3\2\2\2y|\3\2\2\2zx\3\2\2\2"+
		"{h\3\2\2\2{k\3\2\2\2{n\3\2\2\2|\177\3\2\2\2}{\3\2\2\2}~\3\2\2\2~\25\3"+
		"\2\2\2\177}\3\2\2\2\u0080\u0081\5\24\13\2\u0081\u0082\5\30\r\2\u0082\u0083"+
		"\5\24\13\2\u0083\27\3\2\2\2\u0084\u0085\t\4\2\2\u0085\31\3\2\2\2\u0086"+
		"\u0087\t\5\2\2\u0087\33\3\2\2\2\20\'+\60\659FINVXfx{}";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}