__int64 __fastcall dsi_display_prepare(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v9; // x9
  unsigned int v10; // w8
  __int64 v11; // x20
  unsigned int v12; // w0
  __int64 v13; // x5
  __int64 v14; // x4
  unsigned int updated; // w20
  unsigned int v16; // w0
  __int64 v17; // x5
  __int64 v18; // x4
  unsigned int v19; // w0
  unsigned int v20; // w0
  unsigned int v21; // w0
  unsigned int v22; // w0
  char v23; // w22
  unsigned int v24; // w0
  unsigned int v25; // w0
  unsigned int v26; // w0
  unsigned int v27; // w0
  const char **v28; // x22
  unsigned int v29; // w0
  unsigned int v30; // w0
  unsigned int v31; // w0
  unsigned int v32; // w0
  int v33; // w0
  int v34; // w0
  unsigned int v35; // w0
  unsigned int v36; // w0
  int v37; // w7
  unsigned int v39; // w0
  unsigned int v40; // w0
  char v41; // [xsp+0h] [xbp-20h]
  char v42; // [xsp+0h] [xbp-20h]
  _QWORD v43[3]; // [xsp+8h] [xbp-18h] BYREF

  v43[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    if ( *(_QWORD *)(*(_QWORD *)(a1 + 264) + 1424LL) )
    {
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dsi_display_prepare",
        8985,
        -1,
        4369,
        *(unsigned __int8 *)(a1 + 848),
        -1059143953,
        a8,
        v41);
      mutex_lock(a1 + 72);
      v9 = *(_QWORD *)(a1 + 264);
      *(_BYTE *)(a1 + 1642) = 1;
      v10 = *(_DWORD *)(a1 + 160);
      v11 = *(_QWORD *)(v9 + 1424);
      v43[0] = a1;
      v43[1] = dsi_display_clk_ctrl_cb;
      if ( !v10 )
        goto LABEL_20;
      *(_QWORD *)(*(_QWORD *)(a1 + 168) + 2840LL) = *(_QWORD *)(a1 + 1624);
      v12 = dsi_ctrl_clk_cb_register(*(_QWORD **)(a1 + 168), v43);
      if ( v12 )
      {
        v13 = v12;
        v14 = 0;
LABEL_6:
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to register ctrl clk_cb[%d], rc=%d\n",
          *(_QWORD *)(a1 + 32),
          v14,
          v13);
LABEL_13:
        v10 = *(_DWORD *)(a1 + 160);
        goto LABEL_14;
      }
      v16 = dsi_phy_clk_cb_register(*(_QWORD *)(a1 + 192), v43);
      if ( v16 )
      {
        v17 = v16;
        v18 = 0;
      }
      else
      {
        v10 = *(_DWORD *)(a1 + 160);
        if ( v10 < 2 )
        {
LABEL_14:
          if ( v10 )
          {
            if ( a1 != -168 )
            {
              *(_BYTE *)(*(_QWORD *)(a1 + 168) + 2801LL) = 0;
              v10 = *(_DWORD *)(a1 + 160);
            }
            if ( v10 >= 2 && a1 != -216 )
            {
              *(_BYTE *)(*(_QWORD *)(a1 + 216) + 2801LL) = 0;
              v10 = *(_DWORD *)(a1 + 160);
            }
          }
LABEL_20:
          if ( (*(_BYTE *)(a1 + 1641) & 1) == 0 && v10 )
          {
            if ( a1 != -168 )
            {
              dsi_ctrl_isr_configure(*(_QWORD *)(a1 + 168), 1);
              v10 = *(_DWORD *)(a1 + 160);
            }
            if ( v10 >= 2 && a1 != -216 )
              dsi_ctrl_isr_configure(*(_QWORD *)(a1 + 216), 1);
          }
          if ( (*(_BYTE *)(v11 + 156) & 8) == 0 )
            goto LABEL_28;
          if ( *(_BYTE *)(a1 + 64) == 1 )
          {
            if ( *(_DWORD *)(a1 + 888) == 1 )
            {
              drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DMS not supported on first frame\n");
              updated = -22;
              goto LABEL_95;
            }
LABEL_28:
            if ( (*(_BYTE *)(a1 + 1217) & 1) == 0 && (*(_BYTE *)(a1 + 64) & 1) == 0 && (*(_BYTE *)(a1 + 1641) & 1) == 0 )
            {
              v19 = dsi_display_mgr_panel_pre_prepare(a1);
              if ( v19 )
              {
                updated = v19;
                drm_dev_printk(
                  0,
                  &unk_248D72,
                  "*ERROR* [msm-dsi-error]: [%s] panel pre-prepare failed, rc=%d\n",
                  *(_QWORD *)(a1 + 32),
                  v19);
LABEL_95:
                mutex_unlock(a1 + 72);
                sde_evtlog_log(
                  sde_dbg_base_evtlog,
                  "dsi_display_prepare",
                  9136,
                  -1,
                  8738,
                  *(unsigned __int8 *)(a1 + 848),
                  -1059143953,
                  v37,
                  v42);
                goto LABEL_96;
              }
            }
            v20 = dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 1, 1);
            if ( v20 )
            {
              updated = v20;
              drm_dev_printk(
                0,
                &unk_248D72,
                "*ERROR* [msm-dsi-error]: [%s] failed to enable DSI core clocks, rc=%d\n",
                *(const char **)(a1 + 32),
                v20);
LABEL_94:
              dsi_display_mgr_panel_post_unprepare(a1);
              goto LABEL_95;
            }
            if ( *(_BYTE *)(*(_QWORD *)(a1 + 264) + 1962LL) != 1 || (*(_BYTE *)(a1 + 1218) & 1) == 0 )
            {
              v21 = dsi_display_mgr_phy_enable(a1);
              if ( v21 )
              {
                updated = v21;
                drm_dev_printk(
                  0,
                  &unk_248D72,
                  "*ERROR* [msm-dsi-error]: [%s] failed to enable DSI PHY, rc=%d\n",
                  *(const char **)(a1 + 32),
                  v21);
LABEL_93:
                dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 1, 0);
                goto LABEL_94;
              }
            }
            if ( (*(_BYTE *)(a1 + 64) & 1) != 0 )
              v23 = 1;
            else
              v23 = *(_BYTE *)(a1 + 1641);
            if ( *(_BYTE *)(*(_QWORD *)(a1 + 264) + 1962LL) == 1 && *(_BYTE *)(a1 + 1218) == 1 )
            {
              if ( *(_DWORD *)(a1 + 160) )
              {
                updated = dsi_ctrl_update_host_state(*(_QWORD *)(a1 + 168), 5, 1);
                if ( updated )
                  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: host init update failed rc=%d\n", updated);
                if ( *(_DWORD *)(a1 + 160) <= 1u )
                {
                  if ( updated )
                    goto LABEL_62;
                }
                else
                {
                  v25 = dsi_ctrl_update_host_state(*(_QWORD *)(a1 + 216), 5, 1);
                  if ( v25 )
                  {
                    updated = v25;
                    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: host init update failed rc=%d\n", v25);
LABEL_62:
                    drm_dev_printk(
                      0,
                      &unk_248D72,
                      "*ERROR* [msm-dsi-error]: [%s] failed to setup DSI controller, rc=%d\n",
                      *(const char **)(a1 + 32),
                      updated);
LABEL_92:
                    dsi_display_mgr_phy_disable(a1);
                    goto LABEL_93;
                  }
                }
              }
            }
            else if ( *(_DWORD *)(a1 + 160) )
            {
              v26 = dsi_ctrl_host_init(*(_QWORD *)(a1 + 168), v23 & 1);
              if ( v26 )
              {
                updated = v26;
                drm_dev_printk(
                  0,
                  &unk_248D72,
                  "*ERROR* [msm-dsi-error]: [%s] failed to init host_%d, skip_op=%d, rc=%d\n",
                  *(const char **)(a1 + 32),
                  0,
                  v23 & 1,
                  v26);
                goto LABEL_62;
              }
              if ( *(_DWORD *)(a1 + 160) >= 2u )
              {
                v29 = dsi_ctrl_host_init(*(_QWORD *)(a1 + 216), v23 & 1);
                if ( v29 )
                {
                  updated = v29;
                  drm_dev_printk(
                    0,
                    &unk_248D72,
                    "*ERROR* [msm-dsi-error]: [%s] failed to init host_%d, skip_op=%d, rc=%d\n",
                    *(const char **)(a1 + 32),
                    1,
                    v23 & 1,
                    v29);
                  dsi_ctrl_host_deinit(*(_QWORD *)(a1 + 168));
                  goto LABEL_62;
                }
              }
            }
            dsi_display_register_error_handler(a1);
            v35 = dsi_display_ctrl_host_enable(a1);
            if ( v35 )
            {
              updated = v35;
              drm_dev_printk(
                0,
                &unk_248D72,
                "*ERROR* [msm-dsi-error]: [%s] failed to enable DSI host, rc=%d\n",
                *(const char **)(a1 + 32),
                v35);
LABEL_91:
              dsi_display_ctrl_deinit(a1);
              goto LABEL_92;
            }
            v36 = dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 2, 1);
            if ( v36 )
            {
              updated = v36;
              drm_dev_printk(
                0,
                &unk_248D72,
                "*ERROR* [msm-dsi-error]: [%s] failed to enable DSI link clocks, rc=%d\n",
                *(const char **)(a1 + 32),
                v36);
LABEL_90:
              dsi_display_ctrl_host_disable(a1);
              goto LABEL_91;
            }
            if ( *(_BYTE *)(*(_QWORD *)(a1 + 264) + 2024LL) == 1 && *(_DWORD *)(a1 + 888) == 1 )
            {
              v39 = dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1328), 4, 1);
              if ( v39 )
              {
                updated = v39;
                drm_dev_printk(
                  0,
                  &unk_248D72,
                  "*ERROR* [msm-dsi-error]: [%s] failed to enable DSI esync clocks, rc=%d\n",
                  *(const char **)(a1 + 32),
                  v39);
LABEL_114:
                dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 2, 0);
                goto LABEL_90;
              }
            }
            if ( (*(_BYTE *)(a1 + 64) & 1) != 0 || (*(_BYTE *)(a1 + 1641) & 1) != 0 )
            {
LABEL_108:
              updated = 0;
              goto LABEL_95;
            }
            v40 = dsi_display_soft_reset(a1);
            if ( v40 )
            {
              updated = v40;
              drm_dev_printk(
                0,
                &unk_248D72,
                "*ERROR* [msm-dsi-error]: [%s] failed soft reset, rc=%d\n",
                *(_QWORD *)(a1 + 32),
                v40);
            }
            else
            {
              if ( (*(_BYTE *)(a1 + 1217) & 1) != 0 )
                goto LABEL_108;
              updated = dsi_panel_prepare(*(_QWORD *)(a1 + 264));
              if ( !updated )
                goto LABEL_95;
              drm_dev_printk(
                0,
                &unk_248D72,
                "*ERROR* [msm-dsi-error]: [%s] panel prepare failed, rc=%d\n",
                *(_QWORD *)(a1 + 32),
                updated);
            }
            if ( *(_BYTE *)(*(_QWORD *)(a1 + 264) + 2024LL) == 1 && *(_DWORD *)(a1 + 888) == 1 )
              dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1328), 4, 0);
            goto LABEL_114;
          }
          if ( (*(_BYTE *)(a1 + 1641) & 1) != 0 )
            goto LABEL_28;
          v22 = dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 1, 1);
          if ( v22 )
          {
            updated = v22;
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%s] failed to enable DSI core clocks, rc=%d\n",
              *(const char **)(a1 + 32),
              v22);
LABEL_83:
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%s] panel pre-switch failed, rc=%d\n",
              *(_QWORD *)(a1 + 32),
              updated);
            goto LABEL_95;
          }
          if ( *(_DWORD *)(a1 + 160) )
          {
            v27 = ((__int64 (__fastcall *)(_QWORD))dsi_ctrl_host_timing_update)(*(_QWORD *)(a1 + 168));
            if ( v27 )
            {
              updated = v27;
              v28 = (const char **)(a1 + 32);
              drm_dev_printk(
                0,
                &unk_248D72,
                "*ERROR* [msm-dsi-error]: [%s] failed to update host_%d, rc=%d\n",
                *(const char **)(a1 + 32),
                0,
                v27);
LABEL_66:
              drm_dev_printk(
                0,
                &unk_248D72,
                "*ERROR* [msm-dsi-error]: [%s] failed to update DSI controller, rc=%d\n",
                *v28,
                updated);
LABEL_82:
              dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 1, 0);
              goto LABEL_83;
            }
            if ( *(_DWORD *)(a1 + 160) >= 2u )
            {
              v31 = ((__int64 (__fastcall *)(_QWORD))dsi_ctrl_host_timing_update)(*(_QWORD *)(a1 + 216));
              if ( v31 )
              {
                updated = v31;
                v28 = (const char **)(a1 + 32);
                drm_dev_printk(
                  0,
                  &unk_248D72,
                  "*ERROR* [msm-dsi-error]: [%s] failed to update host_%d, rc=%d\n",
                  *(const char **)(a1 + 32),
                  1,
                  v31);
                dsi_ctrl_host_deinit(*(_QWORD *)(a1 + 168));
                goto LABEL_66;
              }
            }
          }
          v32 = dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 2, 1);
          if ( v32 )
          {
            updated = v32;
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%s] failed to enable DSI link clock, rc=%d\n",
              *(const char **)(a1 + 32),
              v32);
            if ( !*(_DWORD *)(a1 + 160) )
              goto LABEL_82;
          }
          else
          {
            if ( *(_BYTE *)(*(_QWORD *)(a1 + 264) + 2024LL) != 1 || *(_DWORD *)(a1 + 888) != 1 )
              goto LABEL_108;
            updated = dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1328), 4, 1);
            if ( !updated )
              goto LABEL_95;
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%s] failed to enable DSI esync clock, rc=%d\n",
              *(const char **)(a1 + 32),
              updated);
            dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 2, 0);
            if ( !*(_DWORD *)(a1 + 160) )
              goto LABEL_82;
          }
          v33 = dsi_ctrl_host_deinit(*(_QWORD *)(a1 + 168));
          if ( v33 )
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%s] failed to deinit host_%d, rc=%d\n",
              *(const char **)(a1 + 32),
              0,
              v33);
          if ( *(_DWORD *)(a1 + 160) >= 2u )
          {
            v34 = dsi_ctrl_host_deinit(*(_QWORD *)(a1 + 216));
            if ( v34 )
              drm_dev_printk(
                0,
                &unk_248D72,
                "*ERROR* [msm-dsi-error]: [%s] failed to deinit host_%d, rc=%d\n",
                *(const char **)(a1 + 32),
                1,
                v34);
          }
          goto LABEL_82;
        }
        *(_QWORD *)(*(_QWORD *)(a1 + 216) + 2840LL) = *(_QWORD *)(a1 + 1624);
        v24 = dsi_ctrl_clk_cb_register(*(_QWORD **)(a1 + 216), v43);
        if ( v24 )
        {
          v13 = v24;
          v14 = 1;
          goto LABEL_6;
        }
        v30 = dsi_phy_clk_cb_register(*(_QWORD *)(a1 + 240), v43);
        if ( !v30 )
          goto LABEL_13;
        v17 = v30;
        v18 = 1;
      }
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to register phy clk_cb[%d], rc=%d\n",
        *(_QWORD *)(a1 + 32),
        v18,
        v17);
      goto LABEL_13;
    }
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: no valid mode set for the display\n");
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
  }
  updated = -22;
LABEL_96:
  _ReadStatusReg(SP_EL0);
  return updated;
}
