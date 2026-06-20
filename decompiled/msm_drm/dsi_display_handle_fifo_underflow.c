void __fastcall dsi_display_handle_fifo_underflow(__int64 a1)
{
  __int64 v2; // x8
  unsigned int *v3; // x21
  unsigned int v4; // w8
  __int64 v5; // x0
  __int64 v6; // x0
  int v7; // w6
  int v8; // w7
  int v9; // w0
  int v10; // w5
  int v11; // w4
  int v12; // w0
  int v13; // w6
  int v14; // w7
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  if ( a1 != 1384 )
  {
    v2 = *(_QWORD *)(a1 - 1120);
    if ( v2 )
    {
      if ( !*(_DWORD *)(v2 + 1968) )
      {
        mutex_lock(a1 - 1312);
        v3 = (unsigned int *)(a1 - 1224);
        v4 = *(_DWORD *)(a1 - 1224);
        if ( v4 )
        {
          v5 = *(_QWORD *)(a1 - 1216);
          if ( v5 )
          {
            if ( (dsi_ctrl_validate_host_state(v5) & 1) == 0 )
            {
LABEL_21:
              mutex_unlock(a1 - 1312);
              return;
            }
            v4 = *v3;
          }
          if ( v4 >= 2 )
          {
            v6 = *(_QWORD *)(a1 - 1168);
            if ( v6 )
            {
              if ( (dsi_ctrl_validate_host_state(v6) & 1) == 0 )
                goto LABEL_21;
            }
          }
        }
        drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: handle DSI FIFO underflow error\n");
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "dsi_display_handle_fifo_underflow",
          8715,
          -1,
          4369,
          -1059143953,
          v7,
          v8,
          vars0);
        dsi_display_clk_ctrl(*(_QWORD *)(a1 - 64), 3, 1);
        if ( *v3 )
        {
          v9 = dsi_ctrl_soft_reset(*(_QWORD *)(a1 - 1216));
          if ( v9 )
          {
            v10 = v9;
            v11 = 0;
          }
          else
          {
            if ( *v3 < 2 )
              goto LABEL_20;
            v12 = dsi_ctrl_soft_reset(*(_QWORD *)(a1 - 1168));
            if ( !v12 )
              goto LABEL_20;
            v10 = v12;
            v11 = 1;
          }
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: [%s] failed to soft reset host_%d, rc=%d\n",
            *(const char **)(a1 - 1352),
            v11,
            v10);
        }
LABEL_20:
        dsi_display_clk_ctrl(*(_QWORD *)(a1 - 64), 3, 0);
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "dsi_display_handle_fifo_underflow",
          8722,
          -1,
          8738,
          -1059143953,
          v13,
          v14,
          vars0a);
        goto LABEL_21;
      }
    }
  }
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Invalid recovery use case\n");
}
