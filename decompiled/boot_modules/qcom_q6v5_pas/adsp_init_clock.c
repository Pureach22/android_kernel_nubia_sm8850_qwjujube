__int64 __fastcall adsp_init_clock(_QWORD *a1)
{
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x20
  unsigned __int64 optional; // x0

  v2 = devm_clk_get(*a1, "xo");
  a1[46] = v2;
  if ( v2 < 0xFFFFFFFFFFFFF001LL )
  {
    optional = devm_clk_get_optional(*a1, "aggre2");
    a1[47] = optional;
    if ( optional < 0xFFFFFFFFFFFFF001LL )
      return 0;
    if ( (_DWORD)optional != -517 )
    {
      v3 = optional;
      dev_err(*a1, "failed to get aggre2 clock");
      return v3;
    }
    return 4294966779LL;
  }
  if ( (_DWORD)v2 == -517 )
    return 4294966779LL;
  v3 = v2;
  dev_err(*a1, "failed to get xo clock");
  return v3;
}
