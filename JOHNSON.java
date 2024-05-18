import java.util.Scanner;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Collections;

class Job {
    int id;  // Job id
    int mt;  // Machine time
    char mn; // Machine name ('A' or 'B')

    Job(int id, int mt, char mn) {
        this.id = id;
        this.mt = mt;
        this.mn = mn;
    }
}

public class Flowshop {
    public static int[] JhonsonJobs(ArrayList<Job> arr, int n) {
        int[] ans = new int[n];
        int l = 0;
        int r = n - 1;
        Collections.sort(arr, Comparator.comparingInt((Job j) -> j.mt));

        while (!arr.isEmpty()) {
            Job j = arr.get(0);
            arr.remove(0);
            int id = j.id;
            if (j.mn == 'A') {
                ans[l] = id;
                l++;
            } else {
                ans[r] = id;
                r--;
            }
            for (int h = 0; h < arr.size(); h++) {
                Job k = arr.get(h);
                if (k.id == id) {
                    arr.remove(h);
                    break; // Ensure only one instance is removed
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of jobs");
        int n = sc.nextInt();
        ArrayList<Job> arr = new ArrayList<>();
        System.out.println("Enter job no \t Machine 1 time \t Machine 2 time");
        for (int i = 0; i < n; i++) {
            System.out.println("Seq " + (i + 1) + "==");
            int id = sc.nextInt();
            int mta = sc.nextInt();
            int mtb = sc.nextInt();
            arr.add(new Job(id, mta, 'A'));
            arr.add(new Job(id, mtb, 'B'));
        }
        int[] ans = JhonsonJobs(arr, n);
        System.out.println("The order of jobs by Johnson are");
        for (int i : ans) {
            System.out.print(i + "->");
        }
        System.out.println();
        // T.C = (nlogn => due to Sorting)
        // S.C = (n => due to creation of ArrayList)
        sc.close();
    }
}
