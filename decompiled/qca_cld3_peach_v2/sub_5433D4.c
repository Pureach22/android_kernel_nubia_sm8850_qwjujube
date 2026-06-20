__int64 __fastcall sub_5433D4(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        long double a11)
{
  long double *v11; // x18
  __int128 v12; // q24

  *((_OWORD *)v11 - 1) = v12;
  *v11 = a11;
  return dp_rxdma_err_process(a1, a2, a3, a4);
}
