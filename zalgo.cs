public class Zalgo {
    public static string zalgo(string text, int intensity) {
        Random rnd = new Random();
        string result = "";
        foreach (char ch in text) {
            for (int i = 0; i < intensity; i++) {
                // 768-800 marks the range of unicode where all the characters are diacritics.
                result += (char) rnd.Next(768, 880); // Stacks another diacitic.         
            }
            result += ch; // At the end of all the diacritics for particular character, that character is added.
        }
        return result;
    }
}
public class Program {
    public static void Main(string[] args) {
        string zalgoText = Zalgo.zalgo("Zalgo Text", 8);
        Console.WriteLine(zalgoText);
    }
}
