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
		T__9=10, T__10=11, T__11=12, T__12=13, RETURN=14, IDENTIFIER=15, CONST=16, 
		COMMENT=17, DIRECTIVE=18, WS=19, MULT=20, DIV=21, ADD=22, MINUS=23;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
			"T__9", "T__10", "T__11", "T__12", "RETURN", "IDENTIFIER", "CONST", "COMMENT", 
			"DIRECTIVE", "WS", "MULT", "DIV", "ADD", "MINUS"
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\31\u0097\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\3\2"+
		"\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\7\3\7\3\b\3\b\3\b\3\b\3"+
		"\b\3\t\3\t\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\f\3\f\3\f\3\f\3\f\3\r\3"+
		"\r\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3\16\3\16\3\16\3\16\3\17\3\17\3\17\3"+
		"\17\3\17\3\17\3\17\3\20\3\20\7\20i\n\20\f\20\16\20l\13\20\3\21\6\21o\n"+
		"\21\r\21\16\21p\3\22\3\22\3\22\3\22\7\22w\n\22\f\22\16\22z\13\22\3\22"+
		"\3\22\3\22\3\22\3\22\3\23\3\23\7\23\u0083\n\23\f\23\16\23\u0086\13\23"+
		"\3\23\3\23\3\23\3\23\3\24\3\24\3\24\3\24\3\25\3\25\3\26\3\26\3\27\3\27"+
		"\3\30\3\30\4x\u0084\2\31\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f"+
		"\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\3\2\6\5"+
		"\2C\\aac|\5\2\62;C\\c|\3\2\62;\5\2\13\f\17\17\"\"\2\u009a\2\3\3\2\2\2"+
		"\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2"+
		"\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2"+
		"\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2"+
		"\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\3\61\3\2\2"+
		"\2\5\63\3\2\2\2\7\65\3\2\2\2\t\67\3\2\2\2\139\3\2\2\2\r;\3\2\2\2\17?\3"+
		"\2\2\2\21D\3\2\2\2\23F\3\2\2\2\25H\3\2\2\2\27M\3\2\2\2\31R\3\2\2\2\33"+
		"X\3\2\2\2\35_\3\2\2\2\37f\3\2\2\2!n\3\2\2\2#r\3\2\2\2%\u0080\3\2\2\2\'"+
		"\u008b\3\2\2\2)\u008f\3\2\2\2+\u0091\3\2\2\2-\u0093\3\2\2\2/\u0095\3\2"+
		"\2\2\61\62\7=\2\2\62\4\3\2\2\2\63\64\7.\2\2\64\6\3\2\2\2\65\66\7?\2\2"+
		"\66\b\3\2\2\2\678\7*\2\28\n\3\2\2\29:\7+\2\2:\f\3\2\2\2;<\7k\2\2<=\7p"+
		"\2\2=>\7v\2\2>\16\3\2\2\2?@\7o\2\2@A\7c\2\2AB\7k\2\2BC\7p\2\2C\20\3\2"+
		"\2\2DE\7}\2\2E\22\3\2\2\2FG\7\177\2\2G\24\3\2\2\2HI\7e\2\2IJ\7j\2\2JK"+
		"\7c\2\2KL\7t\2\2L\26\3\2\2\2MN\7n\2\2NO\7q\2\2OP\7p\2\2PQ\7i\2\2Q\30\3"+
		"\2\2\2RS\7h\2\2ST\7n\2\2TU\7q\2\2UV\7c\2\2VW\7v\2\2W\32\3\2\2\2XY\7f\2"+
		"\2YZ\7q\2\2Z[\7w\2\2[\\\7d\2\2\\]\7n\2\2]^\7g\2\2^\34\3\2\2\2_`\7t\2\2"+
		"`a\7g\2\2ab\7v\2\2bc\7w\2\2cd\7t\2\2de\7p\2\2e\36\3\2\2\2fj\t\2\2\2gi"+
		"\t\3\2\2hg\3\2\2\2il\3\2\2\2jh\3\2\2\2jk\3\2\2\2k \3\2\2\2lj\3\2\2\2m"+
		"o\t\4\2\2nm\3\2\2\2op\3\2\2\2pn\3\2\2\2pq\3\2\2\2q\"\3\2\2\2rs\7\61\2"+
		"\2st\7,\2\2tx\3\2\2\2uw\13\2\2\2vu\3\2\2\2wz\3\2\2\2xy\3\2\2\2xv\3\2\2"+
		"\2y{\3\2\2\2zx\3\2\2\2{|\7,\2\2|}\7\61\2\2}~\3\2\2\2~\177\b\22\2\2\177"+
		"$\3\2\2\2\u0080\u0084\7%\2\2\u0081\u0083\13\2\2\2\u0082\u0081\3\2\2\2"+
		"\u0083\u0086\3\2\2\2\u0084\u0085\3\2\2\2\u0084\u0082\3\2\2\2\u0085\u0087"+
		"\3\2\2\2\u0086\u0084\3\2\2\2\u0087\u0088\7\f\2\2\u0088\u0089\3\2\2\2\u0089"+
		"\u008a\b\23\2\2\u008a&\3\2\2\2\u008b\u008c\t\5\2\2\u008c\u008d\3\2\2\2"+
		"\u008d\u008e\b\24\3\2\u008e(\3\2\2\2\u008f\u0090\7,\2\2\u0090*\3\2\2\2"+
		"\u0091\u0092\7\61\2\2\u0092,\3\2\2\2\u0093\u0094\7-\2\2\u0094.\3\2\2\2"+
		"\u0095\u0096\7/\2\2\u0096\60\3\2\2\2\7\2jpx\u0084\4\b\2\2\2\3\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}