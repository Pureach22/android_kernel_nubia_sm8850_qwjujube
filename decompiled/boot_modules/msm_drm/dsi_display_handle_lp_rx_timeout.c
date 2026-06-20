void __fastcall dsi_display_handle_lp_rx_timeout(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  unsigned int *v4; // x21
  unsigned int v5; // w9
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  int v9; // w6
  int v10; // w7
  __int64 v11; // x0
  unsigned int v12; // w9
  __int64 *v13; // x23
  unsigned int v14; // w8
  unsigned int v15; // w2
  __int64 v16; // x10
  __int64 (__fastcall *v17)(__int64, __int64); // x9
  __int64 v18; // x0
  int v19; // w6
  int v20; // w7
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  if ( a1 != 1448 )
  {
    v1 = *(_QWORD *)(a1 - 1184);
    if ( v1 )
    {
      if ( *(_DWORD *)(v1 + 1352) == 1 && !*(_DWORD *)(v1 + 1968) )
      {
        v2 = a1 - 1376;
        mutex_lock(a1 - 1376);
        v4 = (unsigned int *)(a1 - 1288);
        v5 = *(_DWORD *)(a1 - 1288);
        if ( v5 )
        {
          v6 = a1;
          v7 = *(_QWORD *)(a1 - 1280);
          if ( v7 )
          {
            if ( (dsi_ctrl_validate_host_state(v7) & 1) == 0 )
            {
LABEL_31:
              mutex_unlock(v2);
              return;
            }
            v5 = *v4;
            v6 = a1;
          }
          if ( v5 >= 2 )
          {
            v8 = *(_QWORD *)(v6 - 1232);
            if ( v8 )
            {
              if ( (dsi_ctrl_validate_host_state(v8) & 1) == 0 )
                goto LABEL_31;
            }
          }
        }
        drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: handle DSI LP RX Timeout error\n");
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "dsi_display_handle_lp_rx_timeout",
          8837,
          -1,
          4369,
          -1059143953,
          v9,
          v10,
          vars0);
        v11 = dsi_display_clk_ctrl(*(_QWORD *)(a1 - 128), 3, 1);
        v12 = *(_DWORD *)(a1 - 612);
        if ( v12 < 3 )
        {
          v13 = (__int64 *)(a1 - 1280);
          v11 = ((__int64 (__fastcall *)(_QWORD))dsi_ctrl_get_hw_version)(*(_QWORD *)(a1 - 1280 + 48LL * v12));
          if ( (unsigned int)v11 < 0x20020001 )
            goto LABEL_30;
          v14 = *v4;
          if ( *v4 )
          {
            dsi_ctrl_reset(*v13, 0x1F0000u);
            v11 = ((__int64 (__fastcall *)(_QWORD))dsi_phy_lane_reset)(*(_QWORD *)(a1 - 1256));
            v14 = *v4;
            if ( *v4 >= 2 )
            {
              dsi_ctrl_reset(*(_QWORD *)(a1 - 1232), 0x1F0000u);
              v11 = ((__int64 (__fastcall *)(_QWORD))dsi_phy_lane_reset)(*(_QWORD *)(a1 - 1208));
              v14 = *v4;
            }
          }
          v15 = *(_DWORD *)(a1 - 612);
          if ( v15 <= 2 )
          {
            v16 = v13[6 * v15];
            v17 = *(__int64 (__fastcall **)(__int64, __int64))(v16 + 2144);
            if ( !v17 )
            {
LABEL_25:
              if ( v14 )
              {
                ((void (__fastcall *)(__int64, __int64))dsi_ctrl_vid_engine_en)(*v13, 1);
                if ( *v4 >= 2 )
                  ((void (__fastcall *)(_QWORD, __int64))dsi_ctrl_vid_engine_en)(*(_QWORD *)(a1 - 1232), 1);
              }
              _const_udelay(859000);
              goto LABEL_30;
            }
            v18 = *(_QWORD *)(v16 + 2136);
            if ( *((_DWORD *)v17 - 1) != 863793901 )
              __break(0x8229u);
            if ( (v17(v18, 2) & 0x80000000) == 0 )
            {
              v14 = *v4;
              goto LABEL_25;
            }
            _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Target is in suspend/shutdown\n");
LABEL_30:
            dsi_display_clk_ctrl(*(_QWORD *)(a1 - 128), 3, 0);
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "dsi_display_handle_lp_rx_timeout",
              8884,
              -1,
              8738,
              -1059143953,
              v19,
              v20,
              vars0a);
            goto LABEL_31;
          }
        }
        __break(0x5512u);
        dsi_display_cb_error_handler(v11);
        return;
      }
    }
  }
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Invalid recovery use case\n");
}
