__int64 __fastcall dp_altmode_notify(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v4; // w25
  char v5; // w9
  int v6; // w19
  unsigned int v7; // w21
  int v8; // w23
  int v9; // w22
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x26
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  int v21; // w8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  void (__fastcall *v25)(_QWORD); // x8
  int v26; // w9
  int v27; // w8
  __int64 v28; // x0
  int v29; // w8
  __int64 v30; // x8
  __int64 v31; // x0
  unsigned int v32; // w21
  __int64 v33; // x0
  void (__fastcall **v34)(_QWORD); // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  int v38; // w20
  __int64 v39; // x0
  int v40; // w2
  __int64 v42; // x0
  __int64 v43; // x0
  void (__fastcall *v44)(_QWORD); // x8
  _QWORD v45[2]; // [xsp+30h] [xbp-10h] BYREF

  v45[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a2[8];
  v5 = *(_BYTE *)(a1 + 37);
  v6 = *a2;
  v7 = a2[1];
  v8 = (v4 >> 6) & 1;
  v9 = v4 & 0x3F;
  *(_BYTE *)(a1 + 32) = (v4 & 0x40) != 0;
  *(_BYTE *)(a1 + 33) = v4 >> 7;
  *(_BYTE *)(a1 + 35) = (v5 | (0xFFFFFFFFFFFFFFD6LL >> v4)) & 1;
  ipc_log_context = get_ipc_log_context(a1);
  StatusReg = _ReadStatusReg(SP_EL0);
  v12 = ipc_log_string(ipc_log_context, "[d][%-4d]payload=0x%x\n", *(_DWORD *)(StatusReg + 1800), v4);
  if ( (_drm_debug & 4) != 0 )
    v12 = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]payload=0x%x\n", *(_DWORD *)(StatusReg + 1800), v4);
  v13 = get_ipc_log_context(v12);
  v14 = ipc_log_string(
          v13,
          "[d][%-4d]port_index=%d, orientation=%d, pin=%d, hpd_state=%d\n",
          *(_DWORD *)(StatusReg + 1800),
          v6,
          v7,
          v9,
          v8);
  if ( (_drm_debug & 4) != 0 )
    v14 = _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]port_index=%d, orientation=%d, pin=%d, hpd_state=%d\n",
            *(_DWORD *)(StatusReg + 1800),
            v6,
            v7,
            v9,
            v8);
  v15 = get_ipc_log_context(v14);
  v16 = ipc_log_string(
          v15,
          "[d][%-4d]multi_func=%d, hpd_high=%d, hpd_irq=%d\n",
          *(_DWORD *)(StatusReg + 1800),
          *(unsigned __int8 *)(a1 + 35),
          *(unsigned __int8 *)(a1 + 32),
          *(unsigned __int8 *)(a1 + 33));
  if ( (_drm_debug & 4) != 0 )
    v16 = _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]multi_func=%d, hpd_high=%d, hpd_irq=%d\n",
            *(_DWORD *)(StatusReg + 1800),
            *(unsigned __int8 *)(a1 + 35),
            *(unsigned __int8 *)(a1 + 32),
            *(unsigned __int8 *)(a1 + 33));
  v17 = get_ipc_log_context(v16);
  ipc_log_string(v17, "[d][%-4d]connected=%d\n", *(_DWORD *)(StatusReg + 1800), *(unsigned __int8 *)(a1 + 104));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]connected=%d\n",
      *(_DWORD *)(StatusReg + 1800),
      *(unsigned __int8 *)(a1 + 104));
  v18 = sde_evtlog_log(sde_dbg_base_evtlog, "dp_altmode_notify", 150, 8, v4, v6, v7, v9, (v4 & 0x40) != 0);
  if ( edid_ctl )
  {
    v22 = snprintf((char *)(edid_ctl + 20), 0xCu, "0x%02X%02X%02X%02X\n", a2[12], a2[13], a2[14], a2[15]);
    v23 = get_ipc_log_context(v22);
    ipc_log_string(
      v23,
      "[i][%-4d]: connected = %d, orientation = %d, pin = %d, hpd_state = %d, dp_productvdo = %s\n",
      *(_DWORD *)(StatusReg + 1800),
      *(unsigned __int8 *)(a1 + 104),
      v7,
      v9,
      v8,
      (const char *)(edid_ctl + 20));
    if ( (_drm_debug & 4) != 0 )
    {
      v20 = printk(&unk_222DE0, *(unsigned int *)(StatusReg + 1800));
      v21 = *(unsigned __int8 *)(a1 + 104);
      if ( (v4 & 0x3F) == 0 )
        goto LABEL_27;
    }
    else
    {
      v20 = printk(&unk_2306EB, "dp_altmode_notify");
      v21 = *(unsigned __int8 *)(a1 + 104);
      if ( (v4 & 0x3F) == 0 )
        goto LABEL_27;
    }
  }
  else
  {
    v19 = get_ipc_log_context(v18);
    ipc_log_string(v19, "[w][%-4d]edid_ctl = NULL\n", *(_DWORD *)(StatusReg + 1800));
    v20 = printk(&unk_260DC8, "dp_altmode_notify");
    v21 = *(unsigned __int8 *)(a1 + 104);
    if ( (v4 & 0x3F) == 0 )
    {
LABEL_27:
      if ( v21 )
      {
        v30 = *(_QWORD *)(a1 + 16);
        *(_BYTE *)(a1 + 104) = 0;
        *(_BYTE *)(a1 + 34) = 0;
        *(_DWORD *)(a1 + 28) = 0;
        if ( v30 && *(_QWORD *)(v30 + 8) )
        {
          v42 = get_ipc_log_context(v20);
          ipc_log_string(v42, "[i][%-4d]: dp_cb disconnect\n", *(_DWORD *)(StatusReg + 1800));
          if ( (_drm_debug & 4) != 0 )
            printk(&unk_22613F, *(unsigned int *)(StatusReg + 1800));
          else
            printk(&unk_23E09B, "dp_altmode_notify");
          v43 = *(_QWORD *)(a1 + 8);
          v44 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 16) + 8LL);
          if ( *((_DWORD *)v44 - 1) != 711998475 )
            __break(0x8228u);
          v44(v43);
        }
        v31 = dp_altmode_set_usb_dp_mode(a1);
        v32 = v31;
        if ( (_DWORD)v31 )
        {
          v33 = get_ipc_log_context(v31);
          ipc_log_string(v33, "[e][%-4d]failed to clear usb dp mode, rc: %d\n", *(_DWORD *)(StatusReg + 1800), v32);
          printk(&unk_22980F, "dp_altmode_notify");
        }
        goto LABEL_40;
      }
LABEL_39:
      v32 = 0;
      goto LABEL_40;
    }
  }
  if ( (v21 & 1) != 0 )
  {
    if ( (*(_BYTE *)a1 & 1) != 0 )
      goto LABEL_39;
    v24 = *(_QWORD *)(a1 + 16);
    if ( !v24 )
      goto LABEL_39;
    v25 = *(void (__fastcall **)(_QWORD))(v24 + 16);
    if ( !v25 )
      goto LABEL_39;
LABEL_36:
    v35 = *(_QWORD *)(a1 + 8);
    if ( *((_DWORD *)v25 - 1) != 711998475 )
      __break(0x8228u);
    v25(v35);
    goto LABEL_39;
  }
  v26 = *(unsigned __int8 *)(a1 + 35);
  *(_BYTE *)a1 = 0;
  *(_BYTE *)(a1 + 104) = 1;
  *(_BYTE *)(a1 + 34) = 1;
  if ( v26 )
    v27 = 2;
  else
    v27 = 4;
  *(_DWORD *)(a1 + 108) = v27;
  v28 = get_ipc_log_context(v20);
  ipc_log_string(
    v28,
    "[d][%-4d]Connected=%d, lanes=%d\n",
    *(_DWORD *)(StatusReg + 1800),
    *(unsigned __int8 *)(a1 + 104),
    *(_DWORD *)(a1 + 108));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]Connected=%d, lanes=%d\n",
      *(_DWORD *)(StatusReg + 1800),
      *(unsigned __int8 *)(a1 + 104),
      *(_DWORD *)(a1 + 108));
  if ( v7 > 2 )
    v29 = 0;
  else
    v29 = dword_29D180[v7];
  *(_DWORD *)(a1 + 28) = v29;
  v32 = dp_altmode_set_usb_dp_mode(a1);
  if ( !v32 )
  {
    v34 = *(void (__fastcall ***)(_QWORD))(a1 + 16);
    if ( !v34 )
      goto LABEL_39;
    v25 = *v34;
    if ( !v25 )
      goto LABEL_39;
    goto LABEL_36;
  }
LABEL_40:
  v36 = *(_QWORD *)(a1 + 96);
  v45[0] = 17;
  BYTE4(v45[0]) = v6;
  v37 = altmode_send_data(v36, v45, 8);
  v38 = v37;
  v39 = get_ipc_log_context(v37);
  v40 = *(_DWORD *)(StatusReg + 1800);
  if ( v38 < 0 )
  {
    ipc_log_string(v39, "[e][%-4d]failed: %d\n", v40, v38);
    printk(&unk_23A86E, "dp_altmode_send_pan_ack");
  }
  else
  {
    ipc_log_string(v39, "[d][%-4d]port=%d\n", v40, v6);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]port=%d\n", *(_DWORD *)(StatusReg + 1800), v6);
  }
  _ReadStatusReg(SP_EL0);
  return v32;
}
