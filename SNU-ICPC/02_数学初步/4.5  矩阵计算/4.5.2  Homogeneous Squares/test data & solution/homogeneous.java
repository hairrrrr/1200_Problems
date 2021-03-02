import java.io.*;
import java.util.*;

public class homogeneous {
	public static void main(String [] args) throws Exception {
		Scanner in = new Scanner(new File("homogeneous.in"));
		int n;
		while( (n = in.nextInt()) != 0) {
			int [][] s = new int[n][n];
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					s[i][j] = in.nextInt();
					if (i > 0)
						s[i][j] -= s[0][j];
				}
			}
			boolean homogeneous = true;
			for (int j=1; homogeneous && j<n; j++) {
				for (int i=1; i<n; i++) {
					if (s[i][j] != s[i][0])
						homogeneous = false;
				}
			}
			if (!homogeneous)
				System.out.print("not ");
			System.out.println("homogeneous");
		}
	}
}
