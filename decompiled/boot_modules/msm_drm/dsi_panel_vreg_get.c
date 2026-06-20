unsigned __int64 __fastcall dsi_panel_vreg_get(__int64 a1)
{
  int v2; // w8
  int v3; // w21
  unsigned __int64 v4; // x0
  __int64 v5; // x8
  unsigned __int64 v8; // x20
  __int64 v9; // x22
  int v10; // w21
  bool v11; // cf

  if ( !*(_DWORD *)(a1 + 1448) )
    return 0;
  v2 = 0;
  while ( 1 )
  {
    v3 = v2;
    v4 = devm_regulator_get(*(_QWORD *)(a1 + 1216), *(_QWORD *)(a1 + 1440) + 80LL * v2 + 8);
    v5 = *(_QWORD *)(a1 + 1440);
    if ( v4 >= 0xFFFFFFFFFFFFF001LL && (_DWORD)v4 != 0 )
      break;
    *(_QWORD *)(v5 + 80LL * v3) = v4;
    v2 = v3 + 1;
    if ( (unsigned int)(v3 + 1) >= *(_DWORD *)(a1 + 1448) )
      return 0;
  }
  v8 = v4;
  drm_dev_printk(
    0,
    &unk_248D72,
    "*ERROR* [msm-dsi-error]: failed to get %s regulator\n",
    (const char *)(v5 + 80LL * v3 + 8));
  if ( ((v3 - 1) & 0x80000000) == 0 )
  {
    v9 = 80LL * (unsigned int)(v3 - 1);
    v10 = -v3;
    do
    {
      devm_regulator_put(*(_QWORD *)(*(_QWORD *)(a1 + 1440) + v9));
      v11 = __CFADD__(v10++, 1);
      *(_QWORD *)(*(_QWORD *)(a1 + 1440) + v9) = 0;
      v9 -= 80;
    }
    while ( !v11 );
  }
  return v8;
}
