__int64 __fastcall dsi_pwr_set_lp2_load(__int64 a1, char a2)
{
  unsigned int v2; // w8
  __int64 result; // x0
  int v6; // w22
  __int64 v7; // x24
  unsigned int v8; // w21
  unsigned int v9; // w19

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Bad params\n");
    return 4294967274LL;
  }
  v2 = *(_DWORD *)(a1 + 8);
  if ( !v2 )
    return 0;
  result = 0;
  v6 = 0;
  while ( 1 )
  {
    v7 = *(_QWORD *)a1 + 80LL * v6;
    v8 = *(_DWORD *)(v7 + 56);
    if ( v8 )
      break;
LABEL_4:
    if ( ++v6 >= v2 )
      return result;
  }
  if ( (a2 & 1) == 0 )
    v8 = *(_DWORD *)(v7 + 48);
  result = regulator_set_load(*(_QWORD *)v7, v8);
  if ( (result & 0x80000000) == 0 )
  {
    v2 = *(_DWORD *)(a1 + 8);
    goto LABEL_4;
  }
  v9 = result;
  drm_dev_printk(
    0,
    &unk_248D72,
    "*ERROR* [msm-dsi-error]: Set lp2 load (%d) failed for %s, rc=%d",
    v8,
    (const char *)(v7 + 8),
    result);
  return v9;
}
