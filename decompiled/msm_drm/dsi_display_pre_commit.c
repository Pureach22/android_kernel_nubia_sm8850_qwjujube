__int64 __fastcall dsi_display_pre_commit(__int64 a1, int *a2)
{
  __int64 v2; // x22
  int v3; // w21
  unsigned int v4; // w20
  __int64 v6; // x23
  unsigned int v7; // w0
  int v8; // w7
  unsigned int v9; // w19
  int v12; // w9
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  size_t v17; // x0
  _BOOL4 v18; // w4
  __int64 v19; // x21
  __int64 v20; // x9
  __int64 v21; // x20
  char v22; // [xsp+0h] [xbp-10h]
  __int16 v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    printk(&unk_25C57C, a2);
    v9 = -22;
    goto LABEL_13;
  }
  if ( *((_QWORD *)a2 + 1) || *((_BYTE *)a2 + 4) != 1 )
    goto LABEL_12;
  v2 = *(_QWORD *)(a1 + 264);
  v3 = *a2;
  if ( v2 && *(_BYTE *)(v2 + 2047) == 1 )
  {
    v4 = *((unsigned __int16 *)a2 + 16);
    mutex_lock(a1 + 72);
    mutex_lock(v2 + 1040);
    v6 = a1;
    *(_BYTE *)(a1 + 1616) = 1;
    if ( v3 )
    {
      v23 = __rev16(v4);
      v7 = mipi_dsi_dcs_write(v2 + 24, 97, &v23, 2);
      v9 = v7;
      if ( (v7 & 0x80000000) != 0 )
      {
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to send arp on command, rc =%d\n", v7);
      }
      else if ( !v7 )
      {
LABEL_21:
        v15 = v6;
        if ( *(_DWORD *)(v6 + 160) )
        {
          dsi_ctrl_setup_avr(*(_QWORD *)(v6 + 168), v3 != 0);
          v15 = v6;
          if ( *(_DWORD *)(v6 + 160) >= 2u )
          {
            dsi_ctrl_setup_avr(*(_QWORD *)(v6 + 216), v3 != 0);
            v15 = v6;
          }
        }
        v9 = 0;
        goto LABEL_37;
      }
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable arp, rc=%d\n", v9);
    }
    else
    {
      v9 = mipi_dsi_dcs_write(v2 + 24, 96, 0, 0);
      if ( (v9 & 0x80000000) != 0 )
      {
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to send arp off command, rc =%d\n", v9);
      }
      else if ( !v9 )
      {
        goto LABEL_21;
      }
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to disable arp, rc=%d\n", v9);
    }
    v15 = v6;
LABEL_37:
    v17 = sde_dbg_base_evtlog;
    v18 = v3 != 0;
    *(_BYTE *)(v15 + 1616) = 0;
    v19 = v15;
    sde_evtlog_log(v17, "dsi_display_arp", 9329, -1, v18, v4, -1059143953, v8, v22);
    mutex_unlock(v2 + 1040);
    mutex_unlock(v19 + 72);
    if ( v9 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s failed to send arp commands\n",
        "dsi_display_pre_commit");
    goto LABEL_13;
  }
  if ( (*(_BYTE *)(v2 + 2044) & 1) != 0 )
  {
LABEL_12:
    v9 = 0;
    goto LABEL_13;
  }
  mutex_lock(a1 + 72);
  v12 = *(_DWORD *)(a1 + 160);
  v13 = a1;
  *(_BYTE *)(a1 + 1616) = 1;
  if ( !v12 )
    goto LABEL_41;
  v14 = *(_QWORD *)(a1 + 264);
  if ( v3 )
  {
    v9 = dsi_panel_send_qsync_on_dcs(v14, 0);
    if ( v9 )
    {
LABEL_17:
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: fail qsync ON cmds rc:%d\n", v9);
LABEL_27:
      v13 = a1;
      goto LABEL_42;
    }
  }
  else
  {
    v9 = dsi_panel_send_qsync_off_dcs(v14, 0);
    if ( v9 )
      goto LABEL_26;
  }
  dsi_ctrl_setup_avr(*(_QWORD *)(a1 + 168), v3 != 0);
  v13 = a1;
  if ( *(_DWORD *)(a1 + 160) >= 2u )
  {
    v16 = *(_QWORD *)(a1 + 264);
    if ( v3 )
    {
      v9 = dsi_panel_send_qsync_on_dcs(v16, 1);
      if ( v9 )
        goto LABEL_17;
      goto LABEL_40;
    }
    v9 = dsi_panel_send_qsync_off_dcs(v16, 1);
    if ( !v9 )
    {
LABEL_40:
      dsi_ctrl_setup_avr(*(_QWORD *)(a1 + 216), v3 != 0);
      v13 = a1;
      goto LABEL_41;
    }
LABEL_26:
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: fail qsync OFF cmds rc:%d\n", v9);
    goto LABEL_27;
  }
LABEL_41:
  v9 = 0;
LABEL_42:
  v20 = *(_QWORD *)(v13 + 264);
  *(_BYTE *)(v13 + 1616) = 0;
  v21 = v13;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dsi_display_qsync",
    9223,
    -1,
    v3 != 0,
    *(_DWORD *)(v20 + 1980),
    v9,
    -1059143953,
    v22);
  mutex_unlock(v21 + 72);
  if ( v9 )
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s failed to send qsync commands\n",
      "dsi_display_pre_commit");
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v9;
}
