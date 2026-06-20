__int64 __fastcall hdd_set_tdls_scan_type(
        __int64 *a1,
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
  if ( a2 < 2 )
  {
    cfg_tdls_set_scan_enable(*a1, a2 != 0, a3, a4, a5, a6, a7, a8, a9, a10);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Incorrect value of tdls scan type: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_set_tdls_scan_type",
      a2);
    return 4294967274LL;
  }
}
