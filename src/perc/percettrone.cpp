#include "percettrone.h"
#include <stdio.h>
#include <math.h>
#include <oleauto.h>

/*
 * v_w: vettore di dimensione  n_dend+1  di pesi dendritici
 * v_x: vettore degli  n_dend+1  (con bias) input al percettrone
 * n_dend: numero di dendriti
 */
double perc_calc_output(double v_w[], double v_x[], int n_dend)
{
  double a = 0;
  // Somma pesata degli stimoli di ingresso
  for (int i = 0; i < n_dend + 1; i++)
    a = a + v_w[i] * v_x[i];

  // Attivazione del percettrone
  printf("\nInput %lf\n", a);
  for (int i = 0; i < n_dend; i++)
    printf("%d%lf*%lf=", i, v_w[i], v_x[i]);
  return a;
}

// Funzione di attivazione
double activ_function(const double summed_input)
{
  const double r = tanh(summed_input);
  return r;
}

// Derivata della funzione di attivazione
double dactiv_function(const double summed_input)
{
  const double r = tanh(summed_input);
  return 1 - r * r;
}

/*
 * v_s: vettore delle somme dei canali dendritici per gli n_perc percettroni (out)
 * v_y: vettore degli output per gli n_perc percettroni (out)
 * v_w: vettore dei pesi dendritici per gli n_perc percettroni (in)
 * v_x: vettore degli input al percettrone (uguale per tutti gli n_perc percettroni) (in)
 * n_perc: numero di percettroni nello strato (in)
 * n_dend: numero di dendriti per percettrone (in)
 */
void layer_feed_forward(double v_s[], double v_y[], double v_w[], double v_x[], int n_perc, int n_dend)
{
  for(int i=0; i < n_perc; i++)
  {
    v_s[i] = perc_calc_output(v_w + i * (n_dend + 1), v_w, n_dend);
    v_s[i] = activ_function(v_s[i]);
  }
}