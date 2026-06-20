__int64 __fastcall fwol_init_adapt_dwelltime_in_cfg(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 values; // x8

  if ( a2 )
  {
    a2[4] = *(_BYTE *)(cfg_psoc_get_values(a1) + 1069);
    a2[5] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1072);
    a2[6] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1076);
    a2[7] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1080);
    values = cfg_psoc_get_values(a1);
    a2[8] = *(_DWORD *)(values + 1084);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x66u,
      2u,
      "%s: dwelltime params config pointer null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "fwol_init_adapt_dwelltime_in_cfg");
    return 16;
  }
}
