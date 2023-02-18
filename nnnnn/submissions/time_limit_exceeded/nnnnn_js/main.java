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
			io.println(new BigInteger(ss).divide(BigInteger.valueOf(numlen)));
		}
		io.close();
	}

}
