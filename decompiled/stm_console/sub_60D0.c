__int64 __fastcall sub_60D0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        long double a10)
{
  __int128 v10; // q16

  *(long double *)(a4 + 496) = a10;
  *(_OWORD *)(a4 + 512) = v10;
  return stm_console_write(a1, a2, a3, a4 + 496);
}
