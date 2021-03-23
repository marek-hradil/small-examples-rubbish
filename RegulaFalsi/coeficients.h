typedef struct
{
    double *value;
    int length;

    double interval_start;
    double interval_end;
    double error;
} Coeficients;

extern Coeficients *load_coeficients_from_file(char *path);
extern double quantify_coeficients(Coeficients *c, double x);
extern double regula_falsi(Coeficients *c);