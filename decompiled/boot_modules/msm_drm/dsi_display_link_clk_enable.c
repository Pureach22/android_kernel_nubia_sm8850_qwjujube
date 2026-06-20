__int64 __fastcall dsi_display_link_clk_enable(__int64 a1, int a2, int a3, unsigned int a4)
{
  __int64 v6; // x19
  unsigned int v9; // w0
  const char *v10; // x2
  __int64 v11; // x25
  __int64 v12; // x24
  void (__fastcall *v13)(__int64, __int64); // x8
  __int64 v14; // x0
  void (__fastcall *v15)(__int64, __int64); // x8
  __int64 v16; // x0
  unsigned int v17; // w19
  unsigned int v19; // w23
  __int64 v20; // x24
  unsigned int v21; // w0
  const char *v22; // x2
  unsigned int v23; // w21

  v6 = a1 + 48LL * a4;
  if ( (a2 & 1) != 0 )
  {
    v9 = dsi_link_lp_clk_start(v6 + 24, a4);
    if ( v9 )
    {
      v10 = "*ERROR* [msm-dsi-error]: failed to turn on master lp link clocks, rc=%d\n";
LABEL_13:
      v17 = v9;
      drm_dev_printk(0, &unk_248D72, v10, v9);
      return v17;
    }
  }
  v11 = a4;
  if ( (a2 & 2) != 0 )
  {
    v12 = a1 - 48LL * a4;
    if ( (*(_BYTE *)(v12 + 224) & 1) == 0 )
    {
      v13 = *(void (__fastcall **)(__int64, __int64))(v12 + 176);
      v14 = *(_QWORD *)(v12 + 232);
      if ( *((_DWORD *)v13 - 1) != -1297827279 )
        __break(0x8228u);
      v13(v14, 1);
      v15 = *(void (__fastcall **)(__int64, __int64))(v12 + 184);
      v16 = *(_QWORD *)(v12 + 232);
      if ( *((_DWORD *)v15 - 1) != -1297827279 )
        __break(0x8228u);
      v15(v16, 1);
    }
    v9 = dsi_link_hs_clk_start(v6, a4);
    if ( v9 )
    {
      v10 = "*ERROR* [msm-dsi-error]: failed to turn on master hs link clocks, rc=%d\n";
      goto LABEL_13;
    }
  }
  if ( !a3 )
    return 0;
  v19 = 0;
  while ( 1 )
  {
    if ( v19 == v11 )
      goto LABEL_16;
    v20 = a1 + 48LL * (int)v19;
    if ( !v20 )
      goto LABEL_16;
    if ( (a2 & 1) != 0 )
    {
      v21 = dsi_link_lp_clk_start(v20 + 24, v19);
      if ( v21 )
        break;
    }
    if ( (a2 & 2) != 0 )
    {
      v21 = dsi_link_hs_clk_start(a1 + 48LL * (int)v19, v19);
      if ( v21 )
      {
        v22 = "*ERROR* [msm-dsi-error]: failed to turn on hs link clocks, rc=%d\n";
        goto LABEL_26;
      }
    }
LABEL_16:
    if ( a3 == ++v19 )
      return 0;
  }
  v22 = "*ERROR* [msm-dsi-error]: failed to turn on lp link clocks, rc=%d\n";
LABEL_26:
  v23 = v21;
  drm_dev_printk(0, &unk_248D72, v22);
  if ( a2 == 2 )
  {
    dsi_link_hs_clk_stop(v6);
  }
  else if ( a2 == 1 )
  {
    dsi_link_lp_clk_stop(v6 + 24);
  }
  return v23;
}
