__int64 __fastcall hdd_wmmps_helper(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char v11; // w9
  const char *v12; // x2

  if ( a1 )
  {
    if ( a2 )
    {
      v11 = *(_BYTE *)(a2 + 9) - 48;
      *(_BYTE *)(a1 + 41696) = -1;
      *(_BYTE *)(a1 + 41697) = v11;
      return 0;
    }
    v12 = "%s: ptr is NULL";
  }
  else
  {
    v12 = "%s: adapter is NULL";
  }
  qdf_trace_msg(0x33u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_wmmps_helper");
  return 4294967274LL;
}
