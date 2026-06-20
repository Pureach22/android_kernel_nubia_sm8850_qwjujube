__int64 __fastcall ucfg_spectral_get_version(
        __int64 a1,
        unsigned int *a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  if ( a1 && a2 && a3 )
  {
    *a2 = 3;
    *a3 = 1;
    qdf_trace_msg(
      0x56u,
      8u,
      "%s: Spectral get version %d:%d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "ucfg_spectral_get_version",
      *a2,
      1);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x56u, 2u, "%s: invalid param", a4, a5, a6, a7, a8, a9, a10, a11, "ucfg_spectral_get_version");
    return 4;
  }
}
