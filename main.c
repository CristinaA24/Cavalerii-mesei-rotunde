#include <stdio.h>
#include <stdlib.h>

FILE *fin;
FILE *fout;
int n, a[105][105], x[105], y[105], nrsol;

void citire()
{
    int i, j;
    fscanf(fin, "%d\n", &n);
    while(fscanf(fin, "%d %d", &i, &j) == 2)
        a[i][j] = a[j][i] = 1;
}

void afisare()
{
    int i;
    nrsol++;
    fprintf(fout, "Solutia %d\n", nrsol);
    for(i = 1; i <= n; i++)
        fprintf(fout, "%d ", x[i]);
    fprintf(fout, "%d", x[1]);
    fprintf(fout, "\n");
}

int valid(int k)
{
    if(y[x[k]] != 0) //daca am folosit numarul
        return 0;
    if(k > 1)
        if(a[x[k]][x[k-1]] == 0)
            return 0;
    if(k == n)
        if(a[x[1]][x[n]] == 0)
            return 0;
    return 1;
}


void bkt(int k)
{
    int i;
    if(k == n + 1) //am generat toate sol pana la n
    afisare();
    else
        for(i = 1; i <= n; i++)
    {

        x[k] = i; //pun val curenta pe poz k
        if(valid(k) == 1) //daca val e buna
            {
                y[x[k]] = 1; //marcam vect. de aparitii
                bkt(k + 1);
                y[x[k]] = 0; //demarcam vect. de aparitii
            }

    }
}

int main()
{
    fin = fopen("date.in", "r");
    fout = fopen("date.out", "w");
    citire();
    x[1] = 1;
    y[1] = 1;
    bkt(2);
    fclose(fin);
    fclose(fout);
    return 0;
}