import java.io.*;
import java.math.*;

public class main {

	public static void main(String... args) throws Exception {
		Kattio io = new Kattio(System.in, System.out);
		String ss = io.getWord();
		if (ss.equals("0")) io.println("0");
		else {
			int numlen = Math.max(0, ss.length() - 7);
			while (true) {
				String nlstr = String.valueOf(numlen + 1);
				int slen = nlstr.length() + numlen;
				if (slen > ss.length()) break;
				if (slen == ss.length() && nlstr.compareTo(ss.substring(0, nlstr.length())) > 0) {
					break;
				}
				numlen++;
			}
			boolean leading = true;
			int cur = 0;
			for (char c : ss.toCharArray()) {
				cur = 10 * cur + c - '0';
				int div = cur / numlen;
				cur %= numlen;
				if (div != 0) {
					io.print(div);
					leading = false;
				} else if (!leading) io.print(0);
			}
			io.println();
		}
		io.close();
	}

}
