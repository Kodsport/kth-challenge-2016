//Solution by lukasP (Lukáš Poláček)
using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

class Problem
{
    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        StreamReader reader = new StreamReader(bs);
        int[] ss = reader.ReadLine().Split().Select(int.Parse).ToArray();
        int n = ss[0], s = ss[1], k = ss[2];

        List<Double>[] pr = Enumerable.Range(0, 2).Select(
                x => Enumerable.Repeat(0.0, k + 1).ToList()
            ).ToArray();
        pr[0][0] = 1;

        double res = 0;
        foreach (int i in Enumerable.Range(0, n))
        {
            int cur = i % 2;
            int next = cur ^ 1;
            foreach (int j in Enumerable.Range(0, k + 1))
                pr[next][j] = 0;

            foreach (int j in Enumerable.Range(0, k))
            {
                double prob = (double)j / s;
                pr[next][j] += pr[cur][j] * prob;
                pr[next][j + 1] += pr[cur][j] * (1 - prob);
            }
            res += pr[next][k];
        }

        Console.WriteLine(res);
    }
}
