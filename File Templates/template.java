import java.io.*;
import java.util.*;
import java.math.*;

class Solution {
    private final static FastReader in = new FastReader(System.in);
    private final static PrintWriter out = new PrintWriter(System.out);
    private final static RunMode mode = RunMode.SINGLE;

    enum RunMode {
        SINGLE, MULTIPLE, GOOGLE
    }

    public static void main(String[] args) {
        switch (mode) {
            case SINGLE: {
                solve();
                break;
            }
            case MULTIPLE: {
                for (int i = 0, t = in.nextInt(); i < t; i++) {
                    solve();
                }
                out.flush();
                break;
            }
            case GOOGLE: {
                for (int i = 1, t = in.nextInt(); i <= t; i++) {
                    out.printf("Case #%d: ");
                    solve();
                }
                out.flush();
                break;
            }
        }
    }

    private static void solve() {

    }

    static class FastReader {
        private final BufferedReader br;
        private StringTokenizer st;

        public FastReader(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        private String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        private int nextInt() {
            return Integer.parseInt(next());
        }

        private long nextLong() {
            return Long.parseLong(next());
        }

        private double nextDouble() {
            return Double.parseDouble(next());
        }

        private String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}