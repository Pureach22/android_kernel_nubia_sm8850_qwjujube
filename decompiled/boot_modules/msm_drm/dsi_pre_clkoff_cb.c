__int64 __fastcall dsi_pre_clkoff_cb(__int64 a1, unsigned int a2, char a3, int a4)
{
  char v6; // w22
  int v8; // w24
  unsigned int v9; // w20
  __int64 v10; // x8
  unsigned int v11; // w9
  char v12; // w8
  __int64 v13; // x8
  int v14; // w0
  unsigned int v15; // w8
  unsigned int *v16; // x21

  v6 = a2;
  v8 = (a4 == 0) & (a2 >> 1);
  v9 = 0;
  if ( (a3 & 1) != 0 && v8 )
  {
    v10 = *(_QWORD *)(a1 + 264);
    if ( *(_DWORD *)(v10 + 1968) )
    {
      v11 = *(_DWORD *)(a1 + 160);
      if ( v11 )
      {
        if ( *(_QWORD *)(a1 + 168) )
        {
          ((void (__fastcall *)(_QWORD))dsi_phy_lane_reset)(*(_QWORD *)(a1 + 192));
          dsi_ctrl_soft_reset(*(_QWORD *)(a1 + 168));
          v11 = *(_DWORD *)(a1 + 160);
        }
        if ( v11 >= 2 && *(_QWORD *)(a1 + 216) )
        {
          ((void (__fastcall *)(_QWORD))dsi_phy_lane_reset)(*(_QWORD *)(a1 + 240));
          dsi_ctrl_soft_reset(*(_QWORD *)(a1 + 216));
        }
        v10 = *(_QWORD *)(a1 + 264);
      }
    }
    if ( *(_BYTE *)(v10 + 1275) == 1 )
    {
      dsi_display_continuous_clk_ctrl(a1, 0);
      v10 = *(_QWORD *)(a1 + 264);
    }
    if ( (*(_BYTE *)(v10 + 1973) & 1) != 0 )
    {
      if ( *(_BYTE *)(v10 + 1961) != 1 )
      {
LABEL_15:
        v9 = 0;
        goto LABEL_19;
      }
    }
    else if ( (*(_BYTE *)(v10 + 1962) & 1) == 0 )
    {
      goto LABEL_15;
    }
    v9 = dsi_display_set_ulps(a1, 1);
    if ( v9 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: failed enable ulps, rc = %d\n",
        "dsi_pre_clkoff_cb",
        v9);
  }
LABEL_19:
  v12 = v8 ^ 1;
  if ( (a3 & 2) == 0 )
    v12 = 1;
  if ( (v12 & 1) == 0 )
  {
    v9 = dsi_display_config_clk_gating(a1, 0);
    if ( v9 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to disable clk gating, rc=%d\n",
        *(const char **)(a1 + 32),
        v9);
  }
  if ( (v6 & 1) != 0 && !a4 )
  {
    v13 = *(_QWORD *)(a1 + 264);
    if ( (*(_BYTE *)(v13 + 1973) & 1) != 0 || *(_BYTE *)(v13 + 1962) == 1 )
    {
      dsi_display_mgr_phy_idle_off(a1);
      v14 = dsi_display_set_clamp(a1, 1);
      if ( v14 )
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: %s: Failed to enable dsi clamps. rc=%d\n",
          "dsi_pre_clkoff_cb",
          v14);
      if ( !*(_DWORD *)(a1 + 160) )
        goto LABEL_38;
      v9 = dsi_ctrl_phy_reset_config(*(_QWORD *)(a1 + 168), 0);
      if ( v9 )
      {
LABEL_32:
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to %s phy reset, rc=%d\n",
          *(const char **)(a1 + 32),
          "unmask",
          v9);
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: %s: Failed to reset phy, rc=%d\n",
          "dsi_pre_clkoff_cb",
          v9);
        goto LABEL_39;
      }
      if ( *(_DWORD *)(a1 + 160) >= 2u )
      {
        v9 = dsi_ctrl_phy_reset_config(*(_QWORD *)(a1 + 216), 0);
        if ( v9 )
          goto LABEL_32;
      }
      else
      {
LABEL_38:
        v9 = 0;
      }
    }
    else
    {
      v9 = dsi_display_set_ulps(a1, 0);
      if ( v9 )
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: %s: failed to disable ulps. rc=%d\n",
          "dsi_pre_clkoff_cb",
          v9);
    }
LABEL_39:
    if ( a1 )
    {
      v16 = (unsigned int *)(a1 + 160);
      v15 = *(_DWORD *)(a1 + 160);
      if ( !v15 )
        return v9;
      if ( a1 != -168 )
      {
        dsi_ctrl_irq_update(*(_QWORD *)(a1 + 168), 0);
        v15 = *v16;
      }
      if ( v15 < 2 )
        goto LABEL_48;
      if ( a1 == -216 )
      {
LABEL_49:
        if ( *(_QWORD *)(a1 + 168) )
        {
          ((void (*)(void))dsi_ctrl_cache_misr)();
          v15 = *(_DWORD *)(a1 + 160);
        }
        if ( v15 >= 2 && *(_QWORD *)(a1 + 216) )
          ((void (*)(void))dsi_ctrl_cache_misr)();
        return v9;
      }
      dsi_ctrl_irq_update(*(_QWORD *)(a1 + 216), 0);
    }
    else
    {
      v16 = (_DWORD *)&unk_A0;
    }
    v15 = *v16;
LABEL_48:
    if ( !v15 )
      return v9;
    goto LABEL_49;
  }
  return v9;
}
