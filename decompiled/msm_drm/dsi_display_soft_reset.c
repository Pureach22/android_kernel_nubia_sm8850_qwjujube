__int64 __fastcall dsi_display_soft_reset(__int64 a1)
{
  unsigned int v2; // w0
  unsigned int v3; // w19
  int v4; // w4

  if ( !a1 )
    return (unsigned int)-22;
  if ( !*(_DWORD *)(a1 + 160) )
    return 0;
  v2 = dsi_ctrl_soft_reset(*(_QWORD *)(a1 + 168));
  if ( !v2 )
  {
    if ( *(_DWORD *)(a1 + 160) >= 2u )
    {
      v3 = dsi_ctrl_soft_reset(*(_QWORD *)(a1 + 216));
      if ( !v3 )
        return v3;
      v4 = 1;
      goto LABEL_5;
    }
    return 0;
  }
  v3 = v2;
  v4 = 0;
LABEL_5:
  drm_dev_printk(
    0,
    &unk_248D72,
    "*ERROR* [msm-dsi-error]: [%s] failed to soft reset host_%d, rc=%d\n",
    *(const char **)(a1 + 32),
    v4,
    v3);
  return v3;
}
