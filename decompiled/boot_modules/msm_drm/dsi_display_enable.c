__int64 __fastcall dsi_display_enable(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x8
  int v10; // w0
  long double v12; // q0
  unsigned __int64 v13; // x4
  __int64 v14; // x9
  _DWORD *v15; // x8
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x21
  unsigned int updated; // w0
  __int64 v20; // x3
  const char *v21; // x2
  unsigned __int64 v22; // x4
  __int64 v23; // x9
  _DWORD *v24; // x8
  __int64 v25; // x0
  __int64 v26; // x1
  __int64 v27; // x8
  int v28; // w8
  double v29; // d0
  unsigned int v30; // w0
  __int64 v31; // x3
  const char *v32; // x2
  unsigned int v33; // w21
  int v34; // w7
  char v35; // [xsp+0h] [xbp+0h]
  char v36; // [xsp+0h] [xbp+0h]

  if ( !a1 || (v8 = *(_QWORD *)(a1 + 264)) == 0 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(v8 + 1424) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: no valid mode set for the display\n");
    return 4294967274LL;
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dsi_display_enable",
    9585,
    -1,
    4369,
    *(unsigned __int8 *)(a1 + 848),
    -1059143953,
    a8,
    v35);
  if ( (*(_BYTE *)(a1 + 64) & 1) == 0 && *(_BYTE *)(a1 + 1641) != 1 )
  {
    mutex_lock(a1 + 72);
    v18 = *(_QWORD *)(*(_QWORD *)(a1 + 264) + 1424LL);
    if ( (*(_BYTE *)(v18 + 156) & 8) != 0 )
    {
      updated = dsi_panel_post_switch();
      if ( updated )
        goto LABEL_40;
    }
    else if ( (*(_BYTE *)(a1 + 1217) & 1) == 0 )
    {
      updated = dsi_panel_enable();
      if ( updated )
      {
        v20 = *(_QWORD *)(a1 + 32);
        v21 = "*ERROR* [msm-dsi-error]: [%s] failed to enable DSI panel, rc=%d\n";
LABEL_41:
        v33 = updated;
        drm_dev_printk(0, &unk_248D72, v21, v20);
LABEL_48:
        mutex_unlock(a1 + 72);
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "dsi_display_enable",
          9681,
          -1,
          8738,
          *(unsigned __int8 *)(a1 + 848),
          -1059143953,
          v34,
          v36);
        return v33;
      }
    }
    v22 = *(_QWORD *)(a1 + 1632);
    if ( v22 != -1 )
    {
      v23 = *(_QWORD *)(a1 + 168);
      v24 = *(_DWORD **)(v23 + 2168);
      if ( v24 )
      {
        v25 = *(_QWORD *)(v23 + 2160);
        v26 = *(unsigned int *)(v23 + 2152);
        if ( *(v24 - 1) != 863793901 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD, unsigned __int64))v24)(v25, v26, 0, HIDWORD(v22));
      }
    }
    v27 = *(_QWORD *)(v18 + 184);
    if ( ((*(_BYTE *)(v27 + 3400) & 1) != 0 || *(_BYTE *)(v27 + 3401) == 1)
      && (*(_BYTE *)(v18 + 156) & 0x40) == 0
      && (*(_BYTE *)(*(_QWORD *)(a1 + 264) + 1312LL) & 1) == 0 )
    {
      updated = dsi_panel_update_pps();
      if ( updated )
      {
        v20 = *(_QWORD *)(a1 + 32);
        v21 = "*ERROR* [msm-dsi-error]: [%s] panel pps cmd update failed, rc=%d\n";
        goto LABEL_41;
      }
    }
    if ( (*(_BYTE *)(v18 + 156) & 8) == 0 )
    {
      v28 = *(_DWORD *)(a1 + 888);
      if ( v28 == 2 )
      {
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s:enable command timing eng\n", "dsi_display_enable");
        v30 = dsi_display_cmd_engine_enable(a1);
        if ( v30 )
        {
          v31 = *(_QWORD *)(a1 + 32);
          v32 = "*ERROR* [msm-dsi-error]: [%s]failed to enable DSI cmd engine, rc=%d\n";
          goto LABEL_44;
        }
      }
      else
      {
        if ( v28 != 1 )
        {
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: [%s] Invalid configuration\n",
            *(const char **)(a1 + 32));
          v33 = -22;
          goto LABEL_47;
        }
        v29 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s:enable video timing eng\n", "dsi_display_enable");
        v30 = ((__int64 (__fastcall *)(__int64, double))dsi_display_vid_engine_enable)(a1, v29);
        if ( v30 )
        {
          v31 = *(_QWORD *)(a1 + 32);
          v32 = "*ERROR* [msm-dsi-error]: [%s]failed to enable DSI video engine, rc=%d\n";
LABEL_44:
          v33 = v30;
          drm_dev_printk(0, &unk_248D72, v32, v31);
LABEL_47:
          dsi_panel_disable(*(_QWORD *)(a1 + 264));
          goto LABEL_48;
        }
      }
LABEL_45:
      v33 = 0;
      goto LABEL_48;
    }
    updated = dsi_panel_switch(*(_QWORD *)(a1 + 264));
    if ( !updated )
      goto LABEL_45;
LABEL_40:
    v20 = *(_QWORD *)(a1 + 32);
    v21 = "*ERROR* [msm-dsi-error]: [%s] failed to switch DSI panel mode, rc=%d\n";
    goto LABEL_41;
  }
  dsi_display_config_ctrl_for_cont_splash(a1);
  ((void (__fastcall *)(__int64))dsi_display_config_mgr_for_cont_splash)(a1);
  v10 = dsi_display_splash_res_cleanup(a1);
  if ( v10 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Continuous splash res cleanup failed, rc=%d\n", v10);
    return 4294967274LL;
  }
  *(_BYTE *)(*(_QWORD *)(a1 + 264) + 1973LL) = 1;
  *(double *)&v12 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: cont splash enabled, display enable not required\n");
  v13 = *(_QWORD *)(a1 + 1632);
  if ( v13 == -1 )
    return 0;
  v14 = *(_QWORD *)(a1 + 168);
  v15 = *(_DWORD **)(v14 + 2168);
  if ( !v15 )
    return 0;
  v16 = *(_QWORD *)(v14 + 2160);
  v17 = *(unsigned int *)(v14 + 2152);
  if ( *(v15 - 1) != 863793901 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, _QWORD, unsigned __int64, long double))v15)(v16, v17, 0, HIDWORD(v13), v12);
  return 0;
}
