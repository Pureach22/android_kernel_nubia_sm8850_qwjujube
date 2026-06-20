__int64 __fastcall hdd_set_rate_bw(
        __int64 result,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  unsigned __int64 v11; // x8

  v10 = result;
  if ( a2 >= 7 )
  {
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: Unhandled HDD_RATE_BW: %d",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "hdd_map_hdd_bw_to_os",
               a2);
    LOBYTE(v11) = 0;
  }
  else
  {
    v11 = 0x7050403000201uLL >> (8 * (unsigned __int8)a2);
  }
  *(_BYTE *)(v10 + 6) = v11;
  return result;
}
