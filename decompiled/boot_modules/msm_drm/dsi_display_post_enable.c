__int64 __fastcall dsi_display_post_enable(__int64 a1)
{
  int v2; // w8
  unsigned int v3; // w20

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return (unsigned int)-22;
  }
  mutex_lock(a1 + 72);
  v2 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 264) + 1424LL) + 156LL);
  if ( (v2 & 0x100) != 0 )
  {
    dsi_panel_switch_cmd_mode_in();
  }
  else
  {
    if ( (v2 & 0x80) == 0 )
    {
      v3 = dsi_display_mgr_panel_post_enable(a1);
      if ( v3 )
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] panel post-enable failed, rc=%d\n",
          *(const char **)(a1 + 32),
          v3);
      goto LABEL_10;
    }
    dsi_panel_switch_video_mode_in();
  }
  v3 = 0;
LABEL_10:
  if ( *(_DWORD *)(a1 + 888) == 2 || *(_BYTE *)(a1 + 1032) == 1 )
    dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 3, 0);
  mutex_unlock(a1 + 72);
  return v3;
}
