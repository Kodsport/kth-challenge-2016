import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStream;

import java.util.PriorityQueue;

public class vinyals_nlogn {
static Kattio io = new Kattio(System.in, System.out);

  class PII implements Comparable<PII> {
    int first,second;
    PII(int first_, int second_) {
      first = first_;
      second = second_;
    }
    public int compareTo(PII other) {
      int cmp=Integer.compare(first,other.first);
      if (cmp==0) return Integer.compare(second,other.second);
      return cmp;
    }
  };
  
void moin() {
  int n = io.getInt();
  int[] t = new int[n];
  int[] c = new int[n];
  int[] ans = new int[n];

  PriorityQueue<PII> next = new PriorityQueue<PII>(n);
  for (int i=0;i<n;++i) {
    t[i] = io.getInt();
    c[i] = io.getInt();
    next.add(new PII(t[i],i));
  }
  int worst = t[n-1];
  while(next.size()>0) {
    PII ti = next.poll();
    --c[ti.second];
    if(c[ti.second]>0) {
      int nt=ti.first+t[ti.second];
      nt=Math.max(nt,worst);
      worst=nt;
      ti.first=nt;
      next.add(ti);
    }
    else ans[ti.second]=ti.first;
  }
  for (int a : ans) io.println(a);
}

  public static void main(String[] argv) {
    new vinyals_nlogn().moin();
    io.close();
  }
}
  
/** Simple yet moderately fast I/O routines.
 *
 * Example usage:
 *
 * Kattio io = new Kattio(System.in, System.out);
 *
 * while (io.hasMoreTokens()) {
 *    int n = io.getInt();
 *    double d = io.getDouble();
 *    double ans = d*n;
 *
 *    io.println("Answer: " + ans);
 * }
 *
 * io.close();
 *
 *
 * Some notes:
 *
 * - When done, you should always do io.close() or io.flush() on the
 *   Kattio-instance, otherwise, you may lose output.
 *
 * - The getInt(), getDouble(), and getLong() methods will throw an
 *   exception if there is no more data in the input, so it is generally
 *   a good idea to use hasMoreTokens() to check for end-of-file.
 *
 * @author: Kattis
 */

class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
	super(new BufferedOutputStream(System.out));
	r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
	super(new BufferedOutputStream(o));
	r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
	return peekToken() != null;
    }

    public int getInt() {
	return Integer.parseInt(nextToken());
    }

    public double getDouble() { 
	return Double.parseDouble(nextToken());
    }

    public long getLong() {
	return Long.parseLong(nextToken());
    }

    public String getWord() {
	return nextToken();
    }



    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
	if (token == null) 
	    try {
		while (st == null || !st.hasMoreTokens()) {
		    line = r.readLine();
		    if (line == null) return null;
		    st = new StringTokenizer(line);
		}
		token = st.nextToken();
	    } catch (IOException e) { }
	return token;
    }

    private String nextToken() {
	String ans = peekToken();
	token = null;
	return ans;
    }
}
