// Generated from /Users/Yanis/Desktop/Scolaire/INSA/Cours/4IFA/PLD-Compilateur/pld-comp/compiler/ifcc.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ifccLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, CONDOPERATORS=16, 
		COMPARISONOPERATOR=17, RETURN=18, IDENTIFIER=19, CONST=20, COMMENT=21, 
		DIRECTIVE=22, WS=23, MULT=24, DIV=25, ADD=26, MINUS=27, XOR=28;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
			"T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "CONDOPERATORS", 
			"COMPARISONOPERATOR", "RETURN", "IDENTIFIER", "CONST", "COMMENT", "DIRECTIVE", 
			"WS", "MULT", "DIV", "ADD", "MINUS", "XOR"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", "'{'", "';'", "'}'", "','", "'='", "'if'", "'while'", 
			"'else'", "'int'", "'char'", "'long'", "'float'", "'double'", null, null, 
			"'return'", null, null, null, null, null, "'*'", "'/'", "'+'", "'-'", 
			"'^'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, "CONDOPERATORS", "COMPARISONOPERATOR", "RETURN", 
			"IDENTIFIER", "CONST", "COMMENT", "DIRECTIVE", "WS", "MULT", "DIV", "ADD", 
			"MINUS", "XOR"
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


	public ifccLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "ifcc.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\36\u00b9\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\3\2\3\2\3\3\3\3\3\4\3\4"+
		"\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\n\3"+
		"\13\3\13\3\13\3\13\3\13\3\f\3\f\3\f\3\f\3\r\3\r\3\r\3\r\3\r\3\16\3\16"+
		"\3\16\3\16\3\16\3\17\3\17\3\17\3\17\3\17\3\17\3\20\3\20\3\20\3\20\3\20"+
		"\3\20\3\20\3\21\3\21\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\5\22"+
		"~\n\22\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\24\3\24\7\24\u0089\n\24\f"+
		"\24\16\24\u008c\13\24\3\25\6\25\u008f\n\25\r\25\16\25\u0090\3\26\3\26"+
		"\3\26\3\26\7\26\u0097\n\26\f\26\16\26\u009a\13\26\3\26\3\26\3\26\3\26"+
		"\3\26\3\27\3\27\7\27\u00a3\n\27\f\27\16\27\u00a6\13\27\3\27\3\27\3\27"+
		"\3\27\3\30\3\30\3\30\3\30\3\31\3\31\3\32\3\32\3\33\3\33\3\34\3\34\3\35"+
		"\3\35\4\u0098\u00a4\2\36\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f"+
		"\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63"+
		"\33\65\34\67\359\36\3\2\b\4\2((~~\4\2>>@@\5\2C\\aac|\5\2\62;C\\c|\3\2"+
		"\62;\5\2\13\f\17\17\"\"\2\u00c0\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2"+
		"\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2"+
		"\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2"+
		"\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2"+
		"\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2"+
		"\2\2\67\3\2\2\2\29\3\2\2\2\3;\3\2\2\2\5=\3\2\2\2\7?\3\2\2\2\tA\3\2\2\2"+
		"\13C\3\2\2\2\rE\3\2\2\2\17G\3\2\2\2\21I\3\2\2\2\23L\3\2\2\2\25R\3\2\2"+
		"\2\27W\3\2\2\2\31[\3\2\2\2\33`\3\2\2\2\35e\3\2\2\2\37k\3\2\2\2!r\3\2\2"+
		"\2#}\3\2\2\2%\177\3\2\2\2\'\u0086\3\2\2\2)\u008e\3\2\2\2+\u0092\3\2\2"+
		"\2-\u00a0\3\2\2\2/\u00ab\3\2\2\2\61\u00af\3\2\2\2\63\u00b1\3\2\2\2\65"+
		"\u00b3\3\2\2\2\67\u00b5\3\2\2\29\u00b7\3\2\2\2;<\7*\2\2<\4\3\2\2\2=>\7"+
		"+\2\2>\6\3\2\2\2?@\7}\2\2@\b\3\2\2\2AB\7=\2\2B\n\3\2\2\2CD\7\177\2\2D"+
		"\f\3\2\2\2EF\7.\2\2F\16\3\2\2\2GH\7?\2\2H\20\3\2\2\2IJ\7k\2\2JK\7h\2\2"+
		"K\22\3\2\2\2LM\7y\2\2MN\7j\2\2NO\7k\2\2OP\7n\2\2PQ\7g\2\2Q\24\3\2\2\2"+
		"RS\7g\2\2ST\7n\2\2TU\7u\2\2UV\7g\2\2V\26\3\2\2\2WX\7k\2\2XY\7p\2\2YZ\7"+
		"v\2\2Z\30\3\2\2\2[\\\7e\2\2\\]\7j\2\2]^\7c\2\2^_\7t\2\2_\32\3\2\2\2`a"+
		"\7n\2\2ab\7q\2\2bc\7p\2\2cd\7i\2\2d\34\3\2\2\2ef\7h\2\2fg\7n\2\2gh\7q"+
		"\2\2hi\7c\2\2ij\7v\2\2j\36\3\2\2\2kl\7f\2\2lm\7q\2\2mn\7w\2\2no\7d\2\2"+
		"op\7n\2\2pq\7g\2\2q \3\2\2\2rs\t\2\2\2s\"\3\2\2\2tu\7?\2\2u~\7?\2\2v~"+
		"\t\3\2\2wx\7>\2\2x~\7?\2\2yz\7@\2\2z~\7?\2\2{|\7#\2\2|~\7?\2\2}t\3\2\2"+
		"\2}v\3\2\2\2}w\3\2\2\2}y\3\2\2\2}{\3\2\2\2~$\3\2\2\2\177\u0080\7t\2\2"+
		"\u0080\u0081\7g\2\2\u0081\u0082\7v\2\2\u0082\u0083\7w\2\2\u0083\u0084"+
		"\7t\2\2\u0084\u0085\7p\2\2\u0085&\3\2\2\2\u0086\u008a\t\4\2\2\u0087\u0089"+
		"\t\5\2\2\u0088\u0087\3\2\2\2\u0089\u008c\3\2\2\2\u008a\u0088\3\2\2\2\u008a"+
		"\u008b\3\2\2\2\u008b(\3\2\2\2\u008c\u008a\3\2\2\2\u008d\u008f\t\6\2\2"+
		"\u008e\u008d\3\2\2\2\u008f\u0090\3\2\2\2\u0090\u008e\3\2\2\2\u0090\u0091"+
		"\3\2\2\2\u0091*\3\2\2\2\u0092\u0093\7\61\2\2\u0093\u0094\7,\2\2\u0094"+
		"\u0098\3\2\2\2\u0095\u0097\13\2\2\2\u0096\u0095\3\2\2\2\u0097\u009a\3"+
		"\2\2\2\u0098\u0099\3\2\2\2\u0098\u0096\3\2\2\2\u0099\u009b\3\2\2\2\u009a"+
		"\u0098\3\2\2\2\u009b\u009c\7,\2\2\u009c\u009d\7\61\2\2\u009d\u009e\3\2"+
		"\2\2\u009e\u009f\b\26\2\2\u009f,\3\2\2\2\u00a0\u00a4\7%\2\2\u00a1\u00a3"+
		"\13\2\2\2\u00a2\u00a1\3\2\2\2\u00a3\u00a6\3\2\2\2\u00a4\u00a5\3\2\2\2"+
		"\u00a4\u00a2\3\2\2\2\u00a5\u00a7\3\2\2\2\u00a6\u00a4\3\2\2\2\u00a7\u00a8"+
		"\7\f\2\2\u00a8\u00a9\3\2\2\2\u00a9\u00aa\b\27\2\2\u00aa.\3\2\2\2\u00ab"+
		"\u00ac\t\7\2\2\u00ac\u00ad\3\2\2\2\u00ad\u00ae\b\30\3\2\u00ae\60\3\2\2"+
		"\2\u00af\u00b0\7,\2\2\u00b0\62\3\2\2\2\u00b1\u00b2\7\61\2\2\u00b2\64\3"+
		"\2\2\2\u00b3\u00b4\7-\2\2\u00b4\66\3\2\2\2\u00b5\u00b6\7/\2\2\u00b68\3"+
		"\2\2\2\u00b7\u00b8\7`\2\2\u00b8:\3\2\2\2\b\2}\u008a\u0090\u0098\u00a4"+
		"\4\b\2\2\2\3\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}