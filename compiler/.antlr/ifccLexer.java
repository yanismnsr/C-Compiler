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
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, CONDOPERATORS=17, 
		COMPARISONOPERATOR=18, RETURN=19, IDENTIFIER=20, CONST=21, COMMENT=22, 
		DIRECTIVE=23, WS=24, MULT=25, DIV=26, ADD=27, MINUS=28;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
			"T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "CONDOPERATORS", 
			"COMPARISONOPERATOR", "RETURN", "IDENTIFIER", "CONST", "COMMENT", "DIRECTIVE", 
			"WS", "MULT", "DIV", "ADD", "MINUS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'int'", "'main'", "'('", "')'", "','", "'='", "'if'", "'while'", 
			"'else'", "'{'", "';'", "'}'", "'char'", "'long'", "'float'", "'double'", 
			null, null, "'return'", null, null, null, null, null, "'*'", "'/'", "'+'", 
			"'-'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, "CONDOPERATORS", "COMPARISONOPERATOR", 
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\36\u00bc\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\3\2\3\2\3\2\3\2\3\3\3\3"+
		"\3\3\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\b\3\t\3\t\3\t\3"+
		"\t\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\16"+
		"\3\16\3\16\3\17\3\17\3\17\3\17\3\17\3\20\3\20\3\20\3\20\3\20\3\20\3\21"+
		"\3\21\3\21\3\21\3\21\3\21\3\21\3\22\3\22\3\23\3\23\3\23\3\23\3\23\3\23"+
		"\3\23\3\23\3\23\5\23\u0083\n\23\3\24\3\24\3\24\3\24\3\24\3\24\3\24\3\25"+
		"\3\25\7\25\u008e\n\25\f\25\16\25\u0091\13\25\3\26\6\26\u0094\n\26\r\26"+
		"\16\26\u0095\3\27\3\27\3\27\3\27\7\27\u009c\n\27\f\27\16\27\u009f\13\27"+
		"\3\27\3\27\3\27\3\27\3\27\3\30\3\30\7\30\u00a8\n\30\f\30\16\30\u00ab\13"+
		"\30\3\30\3\30\3\30\3\30\3\31\3\31\3\31\3\31\3\32\3\32\3\33\3\33\3\34\3"+
		"\34\3\35\3\35\4\u009d\u00a9\2\36\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23"+
		"\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31"+
		"\61\32\63\33\65\34\67\359\36\3\2\b\4\2((~~\4\2>>@@\5\2C\\aac|\5\2\62;"+
		"C\\c|\3\2\62;\5\2\13\f\17\17\"\"\2\u00c3\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3"+
		"\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2"+
		"\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35"+
		"\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)"+
		"\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2"+
		"\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\3;\3\2\2\2\5?\3\2\2\2\7D\3\2\2\2\t"+
		"F\3\2\2\2\13H\3\2\2\2\rJ\3\2\2\2\17L\3\2\2\2\21O\3\2\2\2\23U\3\2\2\2\25"+
		"Z\3\2\2\2\27\\\3\2\2\2\31^\3\2\2\2\33`\3\2\2\2\35e\3\2\2\2\37j\3\2\2\2"+
		"!p\3\2\2\2#w\3\2\2\2%\u0082\3\2\2\2\'\u0084\3\2\2\2)\u008b\3\2\2\2+\u0093"+
		"\3\2\2\2-\u0097\3\2\2\2/\u00a5\3\2\2\2\61\u00b0\3\2\2\2\63\u00b4\3\2\2"+
		"\2\65\u00b6\3\2\2\2\67\u00b8\3\2\2\29\u00ba\3\2\2\2;<\7k\2\2<=\7p\2\2"+
		"=>\7v\2\2>\4\3\2\2\2?@\7o\2\2@A\7c\2\2AB\7k\2\2BC\7p\2\2C\6\3\2\2\2DE"+
		"\7*\2\2E\b\3\2\2\2FG\7+\2\2G\n\3\2\2\2HI\7.\2\2I\f\3\2\2\2JK\7?\2\2K\16"+
		"\3\2\2\2LM\7k\2\2MN\7h\2\2N\20\3\2\2\2OP\7y\2\2PQ\7j\2\2QR\7k\2\2RS\7"+
		"n\2\2ST\7g\2\2T\22\3\2\2\2UV\7g\2\2VW\7n\2\2WX\7u\2\2XY\7g\2\2Y\24\3\2"+
		"\2\2Z[\7}\2\2[\26\3\2\2\2\\]\7=\2\2]\30\3\2\2\2^_\7\177\2\2_\32\3\2\2"+
		"\2`a\7e\2\2ab\7j\2\2bc\7c\2\2cd\7t\2\2d\34\3\2\2\2ef\7n\2\2fg\7q\2\2g"+
		"h\7p\2\2hi\7i\2\2i\36\3\2\2\2jk\7h\2\2kl\7n\2\2lm\7q\2\2mn\7c\2\2no\7"+
		"v\2\2o \3\2\2\2pq\7f\2\2qr\7q\2\2rs\7w\2\2st\7d\2\2tu\7n\2\2uv\7g\2\2"+
		"v\"\3\2\2\2wx\t\2\2\2x$\3\2\2\2yz\7?\2\2z\u0083\7?\2\2{\u0083\t\3\2\2"+
		"|}\7>\2\2}\u0083\7?\2\2~\177\7@\2\2\177\u0083\7?\2\2\u0080\u0081\7#\2"+
		"\2\u0081\u0083\7?\2\2\u0082y\3\2\2\2\u0082{\3\2\2\2\u0082|\3\2\2\2\u0082"+
		"~\3\2\2\2\u0082\u0080\3\2\2\2\u0083&\3\2\2\2\u0084\u0085\7t\2\2\u0085"+
		"\u0086\7g\2\2\u0086\u0087\7v\2\2\u0087\u0088\7w\2\2\u0088\u0089\7t\2\2"+
		"\u0089\u008a\7p\2\2\u008a(\3\2\2\2\u008b\u008f\t\4\2\2\u008c\u008e\t\5"+
		"\2\2\u008d\u008c\3\2\2\2\u008e\u0091\3\2\2\2\u008f\u008d\3\2\2\2\u008f"+
		"\u0090\3\2\2\2\u0090*\3\2\2\2\u0091\u008f\3\2\2\2\u0092\u0094\t\6\2\2"+
		"\u0093\u0092\3\2\2\2\u0094\u0095\3\2\2\2\u0095\u0093\3\2\2\2\u0095\u0096"+
		"\3\2\2\2\u0096,\3\2\2\2\u0097\u0098\7\61\2\2\u0098\u0099\7,\2\2\u0099"+
		"\u009d\3\2\2\2\u009a\u009c\13\2\2\2\u009b\u009a\3\2\2\2\u009c\u009f\3"+
		"\2\2\2\u009d\u009e\3\2\2\2\u009d\u009b\3\2\2\2\u009e\u00a0\3\2\2\2\u009f"+
		"\u009d\3\2\2\2\u00a0\u00a1\7,\2\2\u00a1\u00a2\7\61\2\2\u00a2\u00a3\3\2"+
		"\2\2\u00a3\u00a4\b\27\2\2\u00a4.\3\2\2\2\u00a5\u00a9\7%\2\2\u00a6\u00a8"+
		"\13\2\2\2\u00a7\u00a6\3\2\2\2\u00a8\u00ab\3\2\2\2\u00a9\u00aa\3\2\2\2"+
		"\u00a9\u00a7\3\2\2\2\u00aa\u00ac\3\2\2\2\u00ab\u00a9\3\2\2\2\u00ac\u00ad"+
		"\7\f\2\2\u00ad\u00ae\3\2\2\2\u00ae\u00af\b\30\2\2\u00af\60\3\2\2\2\u00b0"+
		"\u00b1\t\7\2\2\u00b1\u00b2\3\2\2\2\u00b2\u00b3\b\31\3\2\u00b3\62\3\2\2"+
		"\2\u00b4\u00b5\7,\2\2\u00b5\64\3\2\2\2\u00b6\u00b7\7\61\2\2\u00b7\66\3"+
		"\2\2\2\u00b8\u00b9\7-\2\2\u00b98\3\2\2\2\u00ba\u00bb\7/\2\2\u00bb:\3\2"+
		"\2\2\b\2\u0082\u008f\u0095\u009d\u00a9\4\b\2\2\2\3\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}