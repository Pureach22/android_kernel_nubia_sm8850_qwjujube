__int64 __fastcall dsi_post_clkon_cb(__int64 a1, char a2, unsigned __int8 a3)
{
  int v6; // w22
  unsigned int v7; // w23
  _QWORD *v8; // x24
  unsigned int v9; // w0
  unsigned int v10; // w22
  const char *v11; // x2
  unsigned int v12; // w0
  unsigned int v13; // w8
  unsigned int v14; // w0
  const char *v15; // x3
  unsigned int v16; // w0
  unsigned int v18; // w8
  unsigned int v19; // w8

  if ( (a2 & 2) == 0 || (a3 & 1) == 0 )
    goto LABEL_21;
  v6 = *(unsigned __int8 *)(a1 + 1219);
  if ( v6 != 1 )
    goto LABEL_9;
  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    goto LABEL_9;
  }
  v7 = *(_DWORD *)(a1 + 840);
  if ( v7 < 3 )
  {
    v8 = (_QWORD *)(a1 + 168);
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))dsi_ctrl_setup)(*(_QWORD *)(a1 + 168 + 48LL * v7)) )
    {
LABEL_7:
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI controller setup failed\n");
      goto LABEL_9;
    }
    v19 = *(_DWORD *)(a1 + 160);
    if ( !v19 )
    {
LABEL_10:
      dsi_display_mgr_phy_idle_on(a1);
LABEL_11:
      if ( (unsigned __int8)(*(_BYTE *)(a1 + 1218) & v6) == 1 )
      {
        *(_BYTE *)(a1 + 1218) = 0;
        v9 = dsi_display_set_ulps(a1, 1);
        if ( v9 )
        {
          v10 = v9;
          v11 = "*ERROR* [msm-dsi-error]: %s: Failed to enter ULPS. rc=%d\n";
LABEL_34:
          v15 = "dsi_post_clkon_cb";
LABEL_39:
          drm_dev_printk(0, &unk_248D72, v11, v15, v10);
          return v10;
        }
      }
      if ( *(_DWORD *)(a1 + 160) )
      {
        v10 = dsi_ctrl_phy_reset_config(*(_QWORD *)(a1 + 168), 1);
        if ( v10 || *(_DWORD *)(a1 + 160) >= 2u && (v10 = dsi_ctrl_phy_reset_config(*(_QWORD *)(a1 + 216), 1)) != 0 )
        {
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: [%s] failed to %s phy reset, rc=%d\n",
            *(const char **)(a1 + 32),
            "mask",
            v10);
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: %s: Failed to reset phy, rc=%d\n",
            "dsi_post_clkon_cb",
            v10);
          return v10;
        }
      }
      v12 = dsi_display_set_clamp(a1, 0);
      if ( v12 )
      {
        v10 = v12;
        v11 = "*ERROR* [msm-dsi-error]: %s: Failed to disable dsi clamps. rc=%d\n";
        goto LABEL_34;
      }
LABEL_21:
      if ( (a2 & 2 & a3) != 0 )
      {
        if ( a1 && (*(_BYTE *)(a1 + 64) & 1) == 0 && *(_DWORD *)(a1 + 160) )
        {
          ((void (__fastcall *)(_QWORD))dsi_phy_toggle_resync_fifo)(*(_QWORD *)(a1 + 192));
          v13 = *(_DWORD *)(a1 + 160);
          if ( v13 >= 2 )
          {
            ((void (__fastcall *)(_QWORD))dsi_phy_toggle_resync_fifo)(*(_QWORD *)(a1 + 240));
            v13 = *(_DWORD *)(a1 + 160);
          }
          if ( v13 )
          {
            if ( *(_DWORD *)(*(_QWORD *)(a1 + 264) + 1276LL) != 1 )
            {
              dsi_phy_reset_clk_en_sel(*(_QWORD *)(a1 + 192));
              if ( *(_DWORD *)(a1 + 160) >= 2u )
                dsi_phy_reset_clk_en_sel(*(_QWORD *)(a1 + 240));
            }
          }
        }
        if ( *(_BYTE *)(a1 + 1218) == 1 )
        {
          v14 = dsi_display_set_ulps(a1, 0);
          if ( v14 )
          {
            v10 = v14;
            v11 = "*ERROR* [msm-dsi-error]: %s: failed to disable ulps, rc= %d\n";
            goto LABEL_34;
          }
        }
        if ( *(_BYTE *)(*(_QWORD *)(a1 + 264) + 1275LL) == 1 )
          dsi_display_continuous_clk_ctrl(a1, 1);
        v16 = dsi_display_config_clk_gating(a1, 1);
        if ( v16 )
        {
          v15 = *(const char **)(a1 + 32);
          v10 = v16;
          v11 = "*ERROR* [msm-dsi-error]: [%s] failed to enable clk gating %d\n";
          goto LABEL_39;
        }
      }
      v10 = 0;
      if ( a1 && (a2 & 1) != 0 )
      {
        v18 = *(_DWORD *)(a1 + 160);
        if ( v18 )
        {
          if ( a1 != -168 )
          {
            dsi_ctrl_irq_update(*(_QWORD *)(a1 + 168), 1);
            v18 = *(_DWORD *)(a1 + 160);
          }
          if ( v18 >= 2 && a1 != -216 )
            dsi_ctrl_irq_update(*(_QWORD *)(a1 + 216), 1);
        }
        return 0;
      }
      return v10;
    }
    if ( v7 && *v8 )
    {
      if ( (unsigned int)((__int64 (*)(void))dsi_ctrl_setup)() )
        goto LABEL_7;
      v19 = *(_DWORD *)(a1 + 160);
    }
    if ( v19 >= 2 && v7 != 1 && *(_QWORD *)(a1 + 216) && (unsigned int)((__int64 (*)(void))dsi_ctrl_setup)() )
      goto LABEL_7;
LABEL_9:
    if ( ((*(unsigned __int8 *)(a1 + 1220) | v6) & 1) == 0 )
      goto LABEL_11;
    goto LABEL_10;
  }
  __break(0x5512u);
  return dsi_post_clkoff_cb();
}
