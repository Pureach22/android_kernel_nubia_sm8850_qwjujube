__int64 __fastcall dp_display_attention_work(__int64 a1)
{
  __int64 v2; // x0
  unsigned __int64 StatusReg; // x22
  int v4; // w7
  int *v5; // x26
  int v6; // w6
  int v7; // w7
  int v8; // w8
  __int64 v9; // x0
  int **v10; // x27
  __int64 (*v11)(void); // x8
  int v12; // w21
  int v13; // w7
  int v14; // w7
  int *v15; // x8
  int v16; // w9
  int v17; // w7
  int v18; // w8
  void (*v19)(void); // x8
  int v20; // w0
  int v21; // w7
  __int64 v22; // x8
  void (__fastcall *v23)(_QWORD); // x8
  __int64 v24; // x0
  __int64 v25; // x1
  __int64 v26; // x2
  __int64 v27; // x3
  __int64 v28; // x4
  __int64 v29; // x5
  __int64 v30; // x6
  int v31; // w7
  __int64 v32; // x1
  __int64 v33; // x2
  __int64 v34; // x3
  __int64 v35; // x4
  __int64 v36; // x5
  __int64 v37; // x6
  int v38; // w7
  void (__fastcall *v39)(_QWORD); // x8
  __int64 v40; // x0
  __int64 v41; // x0
  void (*v43)(void); // x8
  __int64 (*v44)(void); // x8
  __int64 (*v45)(void); // x8
  char v46; // [xsp+0h] [xbp+0h]
  char v47; // [xsp+0h] [xbp+0h]
  char v48; // [xsp+0h] [xbp+0h]

  if ( !g_dp_display || (v2 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v2 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(v2, "[i][%-4d]: +\n", *(_DWORD *)(StatusReg + 1800));
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_2378FD, *(unsigned int *)(StatusReg + 1800));
  else
    printk(&unk_234328, "dp_display_attention_work");
  v5 = (int *)(a1 - 1652);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_attention_work",
    1944,
    8,
    4369,
    *(_DWORD *)(a1 - 1652),
    -1059143953,
    v4,
    v46);
  mutex_lock(a1 + 64);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_attention_work",
    1946,
    8,
    *(_DWORD *)(a1 - 1652),
    -1059143953,
    v6,
    v7,
    v47);
  v8 = *(_DWORD *)(a1 - 1652);
  if ( (v8 & 0x100) != 0 )
  {
    if ( !g_dp_display || (v9 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v9 = 0;
    ipc_log_string(v9, "[i][%-4d]Hpd off, not handling any attention\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_2151F3, *(unsigned int *)(StatusReg + 1800));
    else
      printk(&unk_272BFF, "dp_display_attention_work");
    goto LABEL_28;
  }
  if ( (v8 & 4) == 0 )
  {
    mutex_unlock(a1 + 64);
    goto LABEL_45;
  }
  v10 = (int **)(a1 - 1496);
  v11 = *(__int64 (**)(void))(*(_QWORD *)(a1 - 1496) + 152LL);
  if ( *((_DWORD *)v11 - 1) != -1720141962 )
    __break(0x8228u);
  v12 = v11();
  mutex_unlock(a1 + 64);
  if ( v12 )
  {
    v15 = *v10;
    goto LABEL_30;
  }
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_attention_work", 1965, 8, *v5, **v10, -1059143953, v13, v48);
  v15 = *v10;
  v16 = **v10;
  if ( (v16 & 0x200) != 0 )
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_attention_work", 1968, 8, *v5, 512, -1059143953, v14, v48);
    if ( (*(_BYTE *)(a1 + 168) & 1) != 0 )
      goto LABEL_45;
    if ( (*(_BYTE *)(*(_QWORD *)(a1 - 1488) + 5LL) & 1) != 0 && !(*v10)[2] )
    {
      dp_display_handle_disconnect(a1 - 1664, v25, v26, v27, v28, v29, v30, v31);
      goto LABEL_45;
    }
    goto LABEL_44;
  }
  if ( (v16 & 2) != 0 )
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_attention_work", 1985, 8, *v5, 2, -1059143953, v14, v48);
    dp_display_handle_disconnect(a1 - 1664, v32, v33, v34, v35, v36, v37, v38);
    *(_BYTE *)(*(_QWORD *)(a1 - 1488) + 872LL) = 1;
LABEL_44:
    queue_work_on(32, *(_QWORD *)(a1 - 144), a1 - 32);
    goto LABEL_45;
  }
  if ( (v16 & 0x89) == 0 )
    goto LABEL_30;
  mutex_lock(a1 + 64);
  dp_audio_enable(a1 - 1664, 0);
  v18 = **v10;
  if ( (v18 & 8) != 0 )
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_attention_work", 2006, 8, *v5, 8, -1059143953, v17, v48);
    v19 = *(void (**)(void))(*(_QWORD *)(a1 - 1480) + 56LL);
    if ( *((_DWORD *)v19 - 1) != 1576769688 )
      __break(0x8228u);
    v19();
    v18 = **v10;
  }
  if ( (v18 & 1) != 0 )
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_attention_work", 2011, 8, *v5, 1, -1059143953, v17, v48);
    v43 = *((void (**)(void))*v10 + 23);
    if ( *((_DWORD *)v43 - 1) != 1968921649 )
      __break(0x8228u);
    v43();
    v44 = *(__int64 (**)(void))(*(_QWORD *)(a1 - 1480) + 64LL);
    if ( *((_DWORD *)v44 - 1) != -1393050448 )
      __break(0x8228u);
    v20 = v44();
    v18 = **v10;
  }
  else
  {
    v20 = 0;
  }
  if ( (v18 & 0x80) != 0 )
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_attention_work", 2017, 8, *v5, 128, -1059143953, v17, v48);
    v45 = *(__int64 (**)(void))(*(_QWORD *)(a1 - 1480) + 64LL);
    if ( *((_DWORD *)v45 - 1) != -1393050448 )
      __break(0x8228u);
    v20 = v45();
  }
  if ( v20 )
  {
LABEL_28:
    mutex_unlock(a1 + 64);
    goto LABEL_55;
  }
  dp_audio_enable(a1 - 1664, 1);
  mutex_unlock(a1 + 64);
  v15 = *v10;
  if ( (*(_BYTE *)*v10 & 9) == 0 )
  {
LABEL_30:
    if ( v15[35] )
    {
      v22 = *(_QWORD *)(a1 - 1432);
      if ( v22 )
      {
        v23 = *(void (__fastcall **)(_QWORD))(v22 + 8);
        if ( v23 )
        {
          v24 = *(_QWORD *)(a1 - 1440);
          if ( *((_DWORD *)v23 - 1) != -1066802076 )
            __break(0x8228u);
          v23(v24);
        }
      }
    }
    if ( (*(_BYTE *)(a1 + 168) & 1) == 0 && (*(_BYTE *)(a1 - 1651) & 1) == 0 )
      dp_display_send_hpd_notification(a1 - 1664);
  }
LABEL_45:
  if ( *(_BYTE *)(a1 + 168) == 1 )
  {
    v39 = *(void (__fastcall **)(_QWORD))(a1 + 184);
    if ( v39 )
    {
      if ( *((_DWORD *)v39 - 1) != 251140989 )
        __break(0x8228u);
      v39(a1 - 496);
    }
  }
  if ( !g_dp_display || (v40 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v40 = 0;
  ipc_log_string(
    v40,
    "[d][%-4d]mst_attention_work. mst_active:%d\n",
    *(_DWORD *)(StatusReg + 1800),
    *(unsigned __int8 *)(a1 + 168));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]mst_attention_work. mst_active:%d\n",
      *(_DWORD *)(StatusReg + 1800),
      *(unsigned __int8 *)(a1 + 168));
LABEL_55:
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_attention_work", 2053, 8, 8738, *v5, -1059143953, v21, v48);
  if ( !g_dp_display || (v41 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v41 = 0;
  ipc_log_string(v41, "[i][%-4d]: -\n", *(_DWORD *)(StatusReg + 1800));
  if ( (_drm_debug & 4) != 0 )
    return printk(&unk_252BBB, *(unsigned int *)(StatusReg + 1800));
  else
    return printk(&unk_248849, "dp_display_attention_work");
}
