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
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, CONDOPERATORS=17, 
		COMPARISONOPERATOR=18, RETURN=19, IDENTIFIER=20, CONST=21, COMMENT=22, 
		DIRECTIVE=23, WS=24, MULT=25, DIV=26, ADD=27, MINUS=28, XOR=29;
	public static final int
		RULE_axiom = 0, RULE_prog = 1, RULE_instr = 2, RULE_instruction = 3, RULE_returnexp = 4, 
		RULE_declaration = 5, RULE_affectation = 6, RULE_ifInstr = 7, RULE_whileInstr = 8, 
		RULE_elseInstr = 9, RULE_block = 10, RULE_expr = 11, RULE_type = 12;
	private static String[] makeRuleNames() {
		return new String[] {
			"axiom", "prog", "instr", "instruction", "returnexp", "declaration", 
			"affectation", "ifInstr", "whileInstr", "elseInstr", "block", "expr", 
			"type"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'int'", "'main'", "'('", "')'", "','", "'='", "'if'", "'while'", 
			"'else'", "'{'", "';'", "'}'", "'char'", "'long'", "'float'", "'double'", 
			null, null, "'return'", null, null, null, null, null, "'*'", "'/'", "'+'", 
			"'-'", "'^'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, "CONDOPERATORS", "COMPARISONOPERATOR", 
			"RETURN", "IDENTIFIER", "CONST", "COMMENT", "DIRECTIVE", "WS", "MULT", 
			"DIV", "ADD", "MINUS", "XOR"
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

	public static class InstrContext extends ParserRuleContext {
		public InstructionContext instruction() {
			return getRuleContext(InstructionContext.class,0);
		}
		public InstrContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_instr; }
	}

	public final InstrContext instr() throws RecognitionException {
		InstrContext _localctx = new InstrContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_instr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(34);
			instruction();
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
		enterRule(_localctx, 6, RULE_instruction);
		try {
			setState(39);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case RETURN:
				_localctx = new RetContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(36);
				returnexp();
				}
				break;
			case T__0:
			case T__12:
			case T__13:
			case T__14:
			case T__15:
				_localctx = new DeclareVarContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(37);
				declaration();
				}
				break;
			case IDENTIFIER:
				_localctx = new AffectContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(38);
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
		enterRule(_localctx, 8, RULE_returnexp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(41);
			match(RETURN);
			setState(43);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				{
				setState(42);
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
		enterRule(_localctx, 10, RULE_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(45);
			type();
			setState(48);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				{
				setState(46);
				match(IDENTIFIER);
				}
				break;
			case 2:
				{
				setState(47);
				affectation();
				}
				break;
			}
			setState(57);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(50);
				match(T__4);
				setState(53);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
				case 1:
					{
					setState(51);
					match(IDENTIFIER);
					}
					break;
				case 2:
					{
					setState(52);
					affectation();
					}
					break;
				}
				}
				}
				setState(59);
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
		enterRule(_localctx, 12, RULE_affectation);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(60);
			match(IDENTIFIER);
			setState(61);
			match(T__5);
			setState(62);
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
		public InstrContext instr() {
			return getRuleContext(InstrContext.class,0);
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
		enterRule(_localctx, 14, RULE_ifInstr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(64);
			match(T__6);
			setState(65);
			match(T__2);
			setState(66);
			expr(0);
			setState(67);
			match(T__3);
			setState(70);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
			case T__12:
			case T__13:
			case T__14:
			case T__15:
			case RETURN:
			case IDENTIFIER:
				{
				setState(68);
				instr();
				}
				break;
			case T__9:
				{
				setState(69);
				block();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(73);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__8) {
				{
				setState(72);
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

	public static class WhileInstrContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public InstrContext instr() {
			return getRuleContext(InstrContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public WhileInstrContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileInstr; }
	}

	public final WhileInstrContext whileInstr() throws RecognitionException {
		WhileInstrContext _localctx = new WhileInstrContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_whileInstr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(75);
			match(T__7);
			setState(76);
			match(T__2);
			setState(77);
			expr(0);
			setState(78);
			match(T__3);
			setState(81);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
			case T__12:
			case T__13:
			case T__14:
			case T__15:
			case RETURN:
			case IDENTIFIER:
				{
				setState(79);
				instr();
				}
				break;
			case T__9:
				{
				setState(80);
				block();
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

	public static class ElseInstrContext extends ParserRuleContext {
		public InstrContext instr() {
			return getRuleContext(InstrContext.class,0);
		}
		public IfInstrContext ifInstr() {
			return getRuleContext(IfInstrContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public WhileInstrContext whileInstr() {
			return getRuleContext(WhileInstrContext.class,0);
		}
		public ElseInstrContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_elseInstr; }
	}

	public final ElseInstrContext elseInstr() throws RecognitionException {
		ElseInstrContext _localctx = new ElseInstrContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_elseInstr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(83);
			match(T__8);
			setState(88);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
			case T__12:
			case T__13:
			case T__14:
			case T__15:
			case RETURN:
			case IDENTIFIER:
				{
				setState(84);
				instr();
				}
				break;
			case T__6:
				{
				setState(85);
				ifInstr();
				}
				break;
			case T__9:
				{
				setState(86);
				block();
				}
				break;
			case T__7:
				{
				setState(87);
				whileInstr();
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
		public List<WhileInstrContext> whileInstr() {
			return getRuleContexts(WhileInstrContext.class);
		}
		public WhileInstrContext whileInstr(int i) {
			return getRuleContext(WhileInstrContext.class,i);
		}
		public List<InstrContext> instr() {
			return getRuleContexts(InstrContext.class);
		}
		public InstrContext instr(int i) {
			return getRuleContext(InstrContext.class,i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(90);
			match(T__9);
			setState(99);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__6) | (1L << T__7) | (1L << T__9) | (1L << T__12) | (1L << T__13) | (1L << T__14) | (1L << T__15) | (1L << RETURN) | (1L << IDENTIFIER))) != 0)) {
				{
				setState(97);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case T__0:
				case T__12:
				case T__13:
				case T__14:
				case T__15:
				case RETURN:
				case IDENTIFIER:
					{
					{
					setState(91);
					instr();
					setState(92);
					match(T__10);
					}
					}
					break;
				case T__9:
					{
					setState(94);
					block();
					}
					break;
				case T__6:
					{
					setState(95);
					ifInstr();
					}
					break;
				case T__7:
					{
					setState(96);
					whileInstr();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(101);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(102);
			match(T__11);
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
	public static class MultipleOperatorsComparisonContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode CONDOPERATORS() { return getToken(ifccParser.CONDOPERATORS, 0); }
		public MultipleOperatorsComparisonContext(ExprContext ctx) { copyFrom(ctx); }
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
	public static class SimpleComparisonContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode COMPARISONOPERATOR() { return getToken(ifccParser.COMPARISONOPERATOR, 0); }
		public SimpleComparisonContext(ExprContext ctx) { copyFrom(ctx); }
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
	public static class XorOperationContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode XOR() { return getToken(ifccParser.XOR, 0); }
		public XorOperationContext(ExprContext ctx) { copyFrom(ctx); }
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
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(113);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENTIFIER:
				{
				_localctx = new ExprIdentifierContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(105);
				match(IDENTIFIER);
				}
				break;
			case CONST:
				{
				_localctx = new ExprConstContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(106);
				match(CONST);
				}
				break;
			case ADD:
			case MINUS:
				{
				_localctx = new UnaryExpressionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(107);
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
				setState(108);
				expr(7);
				}
				break;
			case T__2:
				{
				_localctx = new ParenthesisContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(109);
				match(T__2);
				setState(110);
				expr(0);
				setState(111);
				match(T__3);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(132);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(130);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
					case 1:
						{
						_localctx = new MultdivContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(115);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(116);
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
						setState(117);
						expr(7);
						}
						break;
					case 2:
						{
						_localctx = new AddminContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(118);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(119);
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
						setState(120);
						expr(6);
						}
						break;
					case 3:
						{
						_localctx = new XorOperationContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(121);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(122);
						match(XOR);
						setState(123);
						expr(5);
						}
						break;
					case 4:
						{
						_localctx = new SimpleComparisonContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(124);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(125);
						match(COMPARISONOPERATOR);
						setState(126);
						expr(3);
						}
						break;
					case 5:
						{
						_localctx = new MultipleOperatorsComparisonContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(127);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(128);
						match(CONDOPERATORS);
						setState(129);
						expr(2);
						}
						break;
					}
					} 
				}
				setState(134);
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
			setState(135);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__12) | (1L << T__13) | (1L << T__14) | (1L << T__15))) != 0)) ) {
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
		case 11:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 6);
		case 1:
			return precpred(_ctx, 5);
		case 2:
			return precpred(_ctx, 4);
		case 3:
			return precpred(_ctx, 2);
		case 4:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\37\u008c\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3\3\4\3"+
		"\4\3\5\3\5\3\5\5\5*\n\5\3\6\3\6\5\6.\n\6\3\7\3\7\3\7\5\7\63\n\7\3\7\3"+
		"\7\3\7\5\78\n\7\7\7:\n\7\f\7\16\7=\13\7\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3"+
		"\t\3\t\3\t\5\tI\n\t\3\t\5\tL\n\t\3\n\3\n\3\n\3\n\3\n\3\n\5\nT\n\n\3\13"+
		"\3\13\3\13\3\13\3\13\5\13[\n\13\3\f\3\f\3\f\3\f\3\f\3\f\3\f\7\fd\n\f\f"+
		"\f\16\fg\13\f\3\f\3\f\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\5\rt\n\r\3\r"+
		"\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\7\r\u0085\n\r"+
		"\f\r\16\r\u0088\13\r\3\16\3\16\3\16\2\3\30\17\2\4\6\b\n\f\16\20\22\24"+
		"\26\30\32\2\5\3\2\35\36\3\2\33\34\4\2\3\3\17\22\2\u0096\2\34\3\2\2\2\4"+
		"\36\3\2\2\2\6$\3\2\2\2\b)\3\2\2\2\n+\3\2\2\2\f/\3\2\2\2\16>\3\2\2\2\20"+
		"B\3\2\2\2\22M\3\2\2\2\24U\3\2\2\2\26\\\3\2\2\2\30s\3\2\2\2\32\u0089\3"+
		"\2\2\2\34\35\5\4\3\2\35\3\3\2\2\2\36\37\7\3\2\2\37 \7\4\2\2 !\7\5\2\2"+
		"!\"\7\6\2\2\"#\5\26\f\2#\5\3\2\2\2$%\5\b\5\2%\7\3\2\2\2&*\5\n\6\2\'*\5"+
		"\f\7\2(*\5\16\b\2)&\3\2\2\2)\'\3\2\2\2)(\3\2\2\2*\t\3\2\2\2+-\7\25\2\2"+
		",.\5\30\r\2-,\3\2\2\2-.\3\2\2\2.\13\3\2\2\2/\62\5\32\16\2\60\63\7\26\2"+
		"\2\61\63\5\16\b\2\62\60\3\2\2\2\62\61\3\2\2\2\63;\3\2\2\2\64\67\7\7\2"+
		"\2\658\7\26\2\2\668\5\16\b\2\67\65\3\2\2\2\67\66\3\2\2\28:\3\2\2\29\64"+
		"\3\2\2\2:=\3\2\2\2;9\3\2\2\2;<\3\2\2\2<\r\3\2\2\2=;\3\2\2\2>?\7\26\2\2"+
		"?@\7\b\2\2@A\5\30\r\2A\17\3\2\2\2BC\7\t\2\2CD\7\5\2\2DE\5\30\r\2EH\7\6"+
		"\2\2FI\5\6\4\2GI\5\26\f\2HF\3\2\2\2HG\3\2\2\2IK\3\2\2\2JL\5\24\13\2KJ"+
		"\3\2\2\2KL\3\2\2\2L\21\3\2\2\2MN\7\n\2\2NO\7\5\2\2OP\5\30\r\2PS\7\6\2"+
		"\2QT\5\6\4\2RT\5\26\f\2SQ\3\2\2\2SR\3\2\2\2T\23\3\2\2\2UZ\7\13\2\2V[\5"+
		"\6\4\2W[\5\20\t\2X[\5\26\f\2Y[\5\22\n\2ZV\3\2\2\2ZW\3\2\2\2ZX\3\2\2\2"+
		"ZY\3\2\2\2[\25\3\2\2\2\\e\7\f\2\2]^\5\6\4\2^_\7\r\2\2_d\3\2\2\2`d\5\26"+
		"\f\2ad\5\20\t\2bd\5\22\n\2c]\3\2\2\2c`\3\2\2\2ca\3\2\2\2cb\3\2\2\2dg\3"+
		"\2\2\2ec\3\2\2\2ef\3\2\2\2fh\3\2\2\2ge\3\2\2\2hi\7\16\2\2i\27\3\2\2\2"+
		"jk\b\r\1\2kt\7\26\2\2lt\7\27\2\2mn\t\2\2\2nt\5\30\r\top\7\5\2\2pq\5\30"+
		"\r\2qr\7\6\2\2rt\3\2\2\2sj\3\2\2\2sl\3\2\2\2sm\3\2\2\2so\3\2\2\2t\u0086"+
		"\3\2\2\2uv\f\b\2\2vw\t\3\2\2w\u0085\5\30\r\txy\f\7\2\2yz\t\2\2\2z\u0085"+
		"\5\30\r\b{|\f\6\2\2|}\7\37\2\2}\u0085\5\30\r\7~\177\f\4\2\2\177\u0080"+
		"\7\24\2\2\u0080\u0085\5\30\r\5\u0081\u0082\f\3\2\2\u0082\u0083\7\23\2"+
		"\2\u0083\u0085\5\30\r\4\u0084u\3\2\2\2\u0084x\3\2\2\2\u0084{\3\2\2\2\u0084"+
		"~\3\2\2\2\u0084\u0081\3\2\2\2\u0085\u0088\3\2\2\2\u0086\u0084\3\2\2\2"+
		"\u0086\u0087\3\2\2\2\u0087\31\3\2\2\2\u0088\u0086\3\2\2\2\u0089\u008a"+
		"\t\4\2\2\u008a\33\3\2\2\2\20)-\62\67;HKSZces\u0084\u0086";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}