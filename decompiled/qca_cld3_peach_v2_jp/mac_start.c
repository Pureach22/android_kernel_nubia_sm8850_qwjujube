__int64 __fastcall mac_start(
        int *a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  int v12; // w9

  result = 16;
  if ( a1 && a2 )
  {
    v12 = *a2;
    *a1 = *a2;
    if ( v12 == 1 )
      return 0;
    else
      return pe_start((__int64)a1, a3, a4, a5, a6, a7, a8, a9, a10);
  }
  return result;
}
