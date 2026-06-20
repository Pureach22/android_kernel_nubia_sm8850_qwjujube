__int64 __fastcall spss_init_clock(_QWORD *a1)
{
  unsigned __int64 v2; // x0
  __int64 v4; // x8
  unsigned __int64 v5; // x19

  v2 = devm_clk_get(*a1, "xo");
  a1[2] = v2;
  if ( v2 < 0xFFFFFFFFFFFFF001LL )
    return 0;
  if ( (_DWORD)v2 == -517 )
    return 4294966779LL;
  v4 = *a1;
  v5 = v2;
  dev_err(v4, "failed to get xo clock\n");
  return v5;
}
