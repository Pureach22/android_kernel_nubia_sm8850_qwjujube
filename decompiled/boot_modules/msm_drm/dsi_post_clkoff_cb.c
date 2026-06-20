__int64 __fastcall dsi_post_clkoff_cb(__int64 a1, char a2, int a3, int a4)
{
  char v5; // w21
  __int64 result; // x0
  unsigned int v7; // w8
  __int64 v8; // x9
  __int64 *v9; // x22
  __int64 v10; // x0
  int v11; // w20
  __int64 v12; // x21
  __int64 v13; // x9
  __int64 v14; // x0
  int v15; // w0
  unsigned int v16; // w20

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid arg\n", "dsi_post_clkoff_cb");
    return 4294967274LL;
  }
  if ( (a2 & 2) != 0 && a3 == 2 && !a4 && *(_DWORD *)(*(_QWORD *)(a1 + 264) + 1968LL) )
  {
    v5 = a2;
    dsi_display_phy_sw_reset(a1);
    a2 = v5;
    a4 = 0;
  }
  result = 0;
  if ( (a2 & 1) != 0 && !a4 )
  {
    v7 = *(_DWORD *)(a1 + 160);
    if ( !v7 )
      return 0;
    v9 = (__int64 *)(a1 + 168);
    v8 = *(_QWORD *)(a1 + 168);
    if ( v8 )
    {
      v10 = *(_QWORD *)(a1 + 192);
      if ( v10 )
      {
        if ( *(_QWORD *)(v8 + 2432) )
          goto LABEL_24;
        v11 = dsi_phy_set_power_state(v10, 0);
        v12 = a1 + 168;
        if ( v11 )
          goto LABEL_21;
        v7 = *(_DWORD *)(a1 + 160);
      }
    }
    if ( v7 < 2 )
      goto LABEL_23;
    v12 = a1 + 216;
    v13 = *(_QWORD *)(a1 + 216);
    if ( v13 )
    {
      v14 = *(_QWORD *)(a1 + 240);
      if ( v14 )
      {
        if ( !*(_QWORD *)(v13 + 2432) )
        {
          v15 = dsi_phy_set_power_state(v14, 0);
          if ( !v15 )
          {
LABEL_22:
            v7 = *(_DWORD *)(a1 + 160);
LABEL_23:
            if ( !v7 )
              return 0;
            goto LABEL_24;
          }
          v11 = v15;
LABEL_21:
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: [%s] Failed to power off, rc=%d\n",
            *(const char **)(*(_QWORD *)v12 + 16LL),
            v11);
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: [%s] failed to power off PHY, rc=%d\n",
            *(const char **)(a1 + 32),
            v11);
          goto LABEL_22;
        }
      }
    }
LABEL_24:
    if ( *v9 )
    {
      LODWORD(result) = dsi_ctrl_set_power_state(*v9, 0);
      if ( (_DWORD)result )
      {
LABEL_30:
        v16 = result;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] Failed to power off, rc=%d\n",
          *(const char **)(*v9 + 16),
          result);
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to power DSI vregs, rc=%d\n",
          *(const char **)(a1 + 32),
          v16);
        return v16;
      }
      v7 = *(_DWORD *)(a1 + 160);
    }
    if ( v7 >= 2 )
    {
      v9 = (__int64 *)(a1 + 216);
      result = *(_QWORD *)(a1 + 216);
      if ( result )
      {
        result = dsi_ctrl_set_power_state(result, 0);
        if ( (_DWORD)result )
          goto LABEL_30;
      }
      return result;
    }
    return 0;
  }
  return result;
}
