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
		DIRECTIVE=22, WS=23, MULT=24, DIV=25, ADD=26, MINUS=27;
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
			"WS", "MULT", "DIV", "ADD", "MINUS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'int'", "'main'", "'('", "')'", "','", "'='", "'if'", "'else'", 
			"'{'", "';'", "'}'", "'char'", "'long'", "'float'", "'double'", null, 
			null, "'return'", null, null, null, null, null, "'*'", "'/'", "'+'", 
			"'-'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, "CONDOPERATORS", "COMPARISONOPERATOR", "RETURN", 
			"IDENTIFIER", "CONST", "COMMENT", "DIRECTIVE", "WS", "MULT", "DIV", "ADD", 
			"MINUS"
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\35\u00b8\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\3\2\3\2\3\2\3\2\3\3\3\3\3\3\3\3\3"+
		"\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\n"+
		"\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3\16\3\16\3"+
		"\17\3\17\3\17\3\17\3\17\3\17\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\21\3"+
		"\21\3\21\3\21\5\21t\n\21\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22"+
		"\5\22\177\n\22\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\24\3\24\7\24\u008a"+
		"\n\24\f\24\16\24\u008d\13\24\3\25\6\25\u0090\n\25\r\25\16\25\u0091\3\26"+
		"\3\26\3\26\3\26\7\26\u0098\n\26\f\26\16\26\u009b\13\26\3\26\3\26\3\26"+
		"\3\26\3\26\3\27\3\27\7\27\u00a4\n\27\f\27\16\27\u00a7\13\27\3\27\3\27"+
		"\3\27\3\27\3\30\3\30\3\30\3\30\3\31\3\31\3\32\3\32\3\33\3\33\3\34\3\34"+
		"\4\u0099\u00a5\2\35\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r"+
		"\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33"+
		"\65\34\67\35\3\2\7\4\2>>@@\5\2C\\aac|\5\2\62;C\\c|\3\2\62;\5\2\13\f\17"+
		"\17\"\"\2\u00c0\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3"+
		"\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2"+
		"\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3"+
		"\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2"+
		"\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\3"+
		"9\3\2\2\2\5=\3\2\2\2\7B\3\2\2\2\tD\3\2\2\2\13F\3\2\2\2\rH\3\2\2\2\17J"+
		"\3\2\2\2\21M\3\2\2\2\23R\3\2\2\2\25T\3\2\2\2\27V\3\2\2\2\31X\3\2\2\2\33"+
		"]\3\2\2\2\35b\3\2\2\2\37h\3\2\2\2!s\3\2\2\2#~\3\2\2\2%\u0080\3\2\2\2\'"+
		"\u0087\3\2\2\2)\u008f\3\2\2\2+\u0093\3\2\2\2-\u00a1\3\2\2\2/\u00ac\3\2"+
		"\2\2\61\u00b0\3\2\2\2\63\u00b2\3\2\2\2\65\u00b4\3\2\2\2\67\u00b6\3\2\2"+
		"\29:\7k\2\2:;\7p\2\2;<\7v\2\2<\4\3\2\2\2=>\7o\2\2>?\7c\2\2?@\7k\2\2@A"+
		"\7p\2\2A\6\3\2\2\2BC\7*\2\2C\b\3\2\2\2DE\7+\2\2E\n\3\2\2\2FG\7.\2\2G\f"+
		"\3\2\2\2HI\7?\2\2I\16\3\2\2\2JK\7k\2\2KL\7h\2\2L\20\3\2\2\2MN\7g\2\2N"+
		"O\7n\2\2OP\7u\2\2PQ\7g\2\2Q\22\3\2\2\2RS\7}\2\2S\24\3\2\2\2TU\7=\2\2U"+
		"\26\3\2\2\2VW\7\177\2\2W\30\3\2\2\2XY\7e\2\2YZ\7j\2\2Z[\7c\2\2[\\\7t\2"+
		"\2\\\32\3\2\2\2]^\7n\2\2^_\7q\2\2_`\7p\2\2`a\7i\2\2a\34\3\2\2\2bc\7h\2"+
		"\2cd\7n\2\2de\7q\2\2ef\7c\2\2fg\7v\2\2g\36\3\2\2\2hi\7f\2\2ij\7q\2\2j"+
		"k\7w\2\2kl\7d\2\2lm\7n\2\2mn\7g\2\2n \3\2\2\2op\7(\2\2pt\7(\2\2qr\7~\2"+
		"\2rt\7~\2\2so\3\2\2\2sq\3\2\2\2t\"\3\2\2\2uv\7?\2\2v\177\7?\2\2w\177\t"+
		"\2\2\2xy\7>\2\2y\177\7?\2\2z{\7@\2\2{\177\7?\2\2|}\7#\2\2}\177\7?\2\2"+
		"~u\3\2\2\2~w\3\2\2\2~x\3\2\2\2~z\3\2\2\2~|\3\2\2\2\177$\3\2\2\2\u0080"+
		"\u0081\7t\2\2\u0081\u0082\7g\2\2\u0082\u0083\7v\2\2\u0083\u0084\7w\2\2"+
		"\u0084\u0085\7t\2\2\u0085\u0086\7p\2\2\u0086&\3\2\2\2\u0087\u008b\t\3"+
		"\2\2\u0088\u008a\t\4\2\2\u0089\u0088\3\2\2\2\u008a\u008d\3\2\2\2\u008b"+
		"\u0089\3\2\2\2\u008b\u008c\3\2\2\2\u008c(\3\2\2\2\u008d\u008b\3\2\2\2"+
		"\u008e\u0090\t\5\2\2\u008f\u008e\3\2\2\2\u0090\u0091\3\2\2\2\u0091\u008f"+
		"\3\2\2\2\u0091\u0092\3\2\2\2\u0092*\3\2\2\2\u0093\u0094\7\61\2\2\u0094"+
		"\u0095\7,\2\2\u0095\u0099\3\2\2\2\u0096\u0098\13\2\2\2\u0097\u0096\3\2"+
		"\2\2\u0098\u009b\3\2\2\2\u0099\u009a\3\2\2\2\u0099\u0097\3\2\2\2\u009a"+
		"\u009c\3\2\2\2\u009b\u0099\3\2\2\2\u009c\u009d\7,\2\2\u009d\u009e\7\61"+
		"\2\2\u009e\u009f\3\2\2\2\u009f\u00a0\b\26\2\2\u00a0,\3\2\2\2\u00a1\u00a5"+
		"\7%\2\2\u00a2\u00a4\13\2\2\2\u00a3\u00a2\3\2\2\2\u00a4\u00a7\3\2\2\2\u00a5"+
		"\u00a6\3\2\2\2\u00a5\u00a3\3\2\2\2\u00a6\u00a8\3\2\2\2\u00a7\u00a5\3\2"+
		"\2\2\u00a8\u00a9\7\f\2\2\u00a9\u00aa\3\2\2\2\u00aa\u00ab\b\27\2\2\u00ab"+
		".\3\2\2\2\u00ac\u00ad\t\6\2\2\u00ad\u00ae\3\2\2\2\u00ae\u00af\b\30\3\2"+
		"\u00af\60\3\2\2\2\u00b0\u00b1\7,\2\2\u00b1\62\3\2\2\2\u00b2\u00b3\7\61"+
		"\2\2\u00b3\64\3\2\2\2\u00b4\u00b5\7-\2\2\u00b5\66\3\2\2\2\u00b6\u00b7"+
		"\7/\2\2\u00b78\3\2\2\2\t\2s~\u008b\u0091\u0099\u00a5\4\b\2\2\2\3\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}