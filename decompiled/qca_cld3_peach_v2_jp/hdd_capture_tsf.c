__int64 __fastcall hdd_capture_tsf(
        __int64 a1,
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
  if ( *(_BYTE *)(a1 + 39344) == 1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Periodic TSF sync feature is already running",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_capture_tsf");
    *a2 = 3;
    return 4294967274LL;
  }
  else if ( (unsigned int)hdd_capture_tsf_internal() )
  {
    return 4294967274LL;
  }
  else
  {
    return 0;
  }
}
