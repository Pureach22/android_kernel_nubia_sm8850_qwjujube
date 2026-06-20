__int64 __fastcall hdd_vendor_mode_to_bonding_mode(
        unsigned int a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a1 >= 0x1D )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Not supported mode %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_vendor_mode_to_bonding_mode",
      a1,
      v10,
      v11);
    return 4294967274LL;
  }
  else
  {
    *a2 = dword_A055D8[a1];
    return 0;
  }
}
