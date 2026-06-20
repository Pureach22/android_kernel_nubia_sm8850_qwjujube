__int64 __fastcall dsi_display_pre_disable(__int64 a1)
{
  unsigned int v2; // w8
  __int64 v3; // x9
  __int64 v4; // x8
  int v5; // w8
  unsigned int v6; // w20

  if ( a1 )
  {
    mutex_lock(a1 + 72);
    v2 = *(_DWORD *)(a1 + 160);
    if ( v2 )
    {
      v3 = *(_QWORD *)(a1 + 168);
      if ( v3 )
      {
        *(_BYTE *)(v3 + 1648) = 0;
        v2 = *(_DWORD *)(a1 + 160);
      }
      if ( v2 >= 2 )
      {
        v4 = *(_QWORD *)(a1 + 216);
        if ( v4 )
          *(_BYTE *)(v4 + 1648) = 0;
      }
    }
    if ( *(_DWORD *)(a1 + 888) == 2 || *(_BYTE *)(a1 + 1032) == 1 )
      dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 3, 1);
    if ( *(_BYTE *)(a1 + 1217) == 1 )
    {
      v5 = *(_DWORD *)(a1 + 888);
      if ( v5 == 2 )
      {
        dsi_panel_switch_cmd_mode_out(*(_QWORD *)(a1 + 264));
        v5 = *(_DWORD *)(a1 + 888);
      }
      if ( v5 == 1 )
        dsi_panel_switch_video_mode_out(*(_QWORD *)(a1 + 264));
      v6 = 0;
    }
    else
    {
      v6 = dsi_panel_pre_disable(*(_QWORD *)(a1 + 264));
      if ( v6 )
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] panel pre-disable failed, rc=%d\n",
          *(const char **)(a1 + 32),
          v6);
    }
    mutex_unlock(a1 + 72);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return (unsigned int)-22;
  }
  return v6;
}
