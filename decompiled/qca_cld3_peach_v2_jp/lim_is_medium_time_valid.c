__int64 __fastcall lim_is_medium_time_valid(
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
  __int64 result; // x0

  if ( !*(_BYTE *)(a1 + 1628) )
    return 1;
  result = 1;
  if ( !*(_WORD *)(a2 + 70)
    && (*(_WORD *)(a1
                 + ((0xCC880440uLL >> (((unsigned __int64)*(unsigned __int16 *)(a2 + 17) >> 9) & 0x1C)) & 0xC)
                 + 1632)
      & 0x10) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: medium time 0 and ACM is mandatory. ADDTS failed",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "lim_is_medium_time_valid");
    return 0;
  }
  return result;
}
