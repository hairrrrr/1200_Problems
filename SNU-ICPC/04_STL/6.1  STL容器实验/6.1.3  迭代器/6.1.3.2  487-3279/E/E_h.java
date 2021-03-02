/* Copyright Howard Cheng (ACM ICPC ECNA 1999) */

import java.io.*;
import java.util.*;

public class E_h {
  static final int MAX_LIST = 100000;
  static final String str = "ABCDEFGHIJKLMNOPRSTUVWXY";
  static int list[] = new int[MAX_LIST];
  static int map[] = new int[256];
  static DataInputStream in = new DataInputStream(System.in);

  static void read_number(int index) throws IOException {
    int i, sum = 0;

    String s = in.readLine();
    
    for (i = 0; i < s.length(); i++) {
      if (s.charAt(i) != '-') {
	sum = sum*10 + map[s.charAt(i)];
      }
      list[index] = sum;
    }
  }

  static void print_duplicate(int n) {
    int i, j, none = 1;

    for (i = 0; i < n; ) {
      for (j = i+1; j < n && list[i] == list[j]; j++)
	;
      if (j-i > 1) {
	int a = list[i] / 10000;
	int b = list[i] % 10000;

	if (a < 10) {
	  System.out.print("00");
	} else if (a < 100) {
	  System.out.print("0");
	}

	System.out.print(a + "-");

	if (b < 10) {
	  System.out.print("000");
	} else if (b < 100) {
	  System.out.print("00");
	} else if (b < 1000) {
	  System.out.print("0");
	}

	System.out.println(b + " " + (j-i));
        none = 0;
      }
      i = j;
    }
    if (none == 1) {
      System.out.println("No duplicates.");
    }
  }

  static void qsort(int start, int end) {
    int num = end - start + 1;
    if (num <= 1) {
      return;
    }

    int pivot = start;

    int temp;
    
    int i, j;
    i = j = start+1;
    for (int k = start+1; k <= end; k++) {
      if (list[k] < list[pivot]) {
	if (i != j) {
	  temp = list[i];
	  list[i] = list[k];
	  list[k] = list[j];
	  list[j] = temp;
	} else {
	  temp = list[i];
	  list[i] = list[k];
	  list[k] = temp;
	}
	i++; j++;
      } else if (list[k] == list[pivot]) {
	temp = list[j];
	list[j++] = list[k];
	list[k] = temp;
      }
    }

    temp = list[i-1];
    list[i-1] = list[start];
    list[start] = temp;

    qsort(start, i-2);
    qsort(j, end);
  }

  public static void main(String[] args) {
    int i, j, n;

    j = 0;
    for (i = 2; i <= 9; i++) {
      map[str.charAt(j++)] = i;
      map[str.charAt(j++)] = i;
      map[str.charAt(j++)] = i;
    }
    for (i = '0'; i <= '9'; i++) {
      map[i] = i - '0';
    }

    String inputline;
    try {
      inputline = in.readLine();
      StringTokenizer stok = new StringTokenizer(inputline);
      n = Integer.parseInt(stok.nextToken());
      
      for (i = 0; i < n; i++) {
	read_number(i);
      }

      qsort(0, n-1);
      print_duplicate(n);
    } catch (IOException e) {
    }
  }
}





