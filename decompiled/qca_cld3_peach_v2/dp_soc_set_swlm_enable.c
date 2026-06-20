__int64 __fastcall dp_soc_set_swlm_enable(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char v10; // w10
  __int64 result; // x0
  char v13; // w10

  v10 = *(_BYTE *)(a1 + 19016);
  if ( (v10 & 2) != 0 )
  {
    result = 0;
    v13 = v10 & 0xFE;
    if ( a2 )
      ++v13;
    *(_BYTE *)(a1 + 19016) = v13;
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: SWLM is not initialized", a3, a4, a5, a6, a7, a8, a9, a10, "dp_soc_set_swlm_enable");
    return 16;
  }
  return result;
}
