__int64 __fastcall dp_mst_bridge_mode_set(
        __int64 a1,
        __int64 a2,
        _QWORD *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v11; // x24
  int v12; // w0
  __int64 v13; // x8
  int v14; // w5
  __int64 v15; // x0
  __int64 v17; // x22
  __int64 v18; // x9
  __int64 v19; // x10
  __int64 v20; // x1
  __int64 v21; // x8
  __int64 v22; // x10
  __int64 v23; // x11
  __int64 v24; // x8
  __int64 v25; // x10
  __int64 v26; // x11
  __int64 v27; // x10
  __int64 v28; // x9
  __int64 v29; // x11
  _DWORD *v30; // x8
  void (__fastcall *v31)(__int64, __int64); // x8
  __int64 v32; // x1
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v35; // x8
  int v36; // w4
  char vars0; // [xsp+0h] [xbp+0h]

  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  if ( a1 && a2 && a3 )
  {
    v11 = *(_QWORD *)(a1 + 384);
    v12 = sde_dbg_base_evtlog;
    v13 = *(_QWORD *)(v11 + 16);
    *(_QWORD *)(a1 + 1344) = v13;
    *(_QWORD *)(a1 + 1352) = *(_QWORD *)(v11 + 24);
    if ( v13 )
      v14 = *(_DWORD *)(v13 + 64);
    else
      v14 = 0;
    sde_evtlog_log(v12, "dp_mst_bridge_mode_set", 1099, 8, 4369, v14, -1059143953, a8, vars0);
    v17 = *(_QWORD *)(a1 + 408);
    memset((void *)(a1 + 544), 0, 0x320u);
    v18 = a3[1];
    v19 = a3[2];
    v20 = *(_QWORD *)(a1 + 1352);
    *(_QWORD *)(a1 + 424) = *a3;
    *(_QWORD *)(a1 + 432) = v18;
    *(_QWORD *)(a1 + 440) = v19;
    v21 = a3[6];
    v23 = a3[3];
    v22 = a3[4];
    *(_QWORD *)(a1 + 464) = a3[5];
    *(_QWORD *)(a1 + 472) = v21;
    *(_QWORD *)(a1 + 448) = v23;
    *(_QWORD *)(a1 + 456) = v22;
    v24 = a3[10];
    v26 = a3[7];
    v25 = a3[8];
    *(_QWORD *)(a1 + 496) = a3[9];
    *(_QWORD *)(a1 + 504) = v24;
    *(_QWORD *)(a1 + 480) = v26;
    *(_QWORD *)(a1 + 488) = v25;
    v27 = a3[12];
    v29 = a3[13];
    v28 = a3[14];
    *(_QWORD *)(a1 + 512) = a3[11];
    *(_QWORD *)(a1 + 536) = v28;
    *(_QWORD *)(a1 + 528) = v29;
    *(_QWORD *)(a1 + 520) = v27;
    v30 = *(_DWORD **)(v17 + 272);
    if ( *(v30 - 1) != 271107547 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD *, __int64))v30)(v17, v20, a3, a1 + 544);
    v31 = *(void (__fastcall **)(__int64, __int64))(v17 + 304);
    v32 = *(_QWORD *)(v11 + 24);
    if ( *((_DWORD *)v31 - 1) != -250558756 )
      __break(0x8228u);
    v31(v17, v32);
    ipc_log_context = get_ipc_log_context();
    StatusReg = _ReadStatusReg(SP_EL0);
    v35 = *(_QWORD *)(a1 + 1344);
    v36 = 0;
    if ( v35 )
      v36 = *(_DWORD *)(v35 + 64);
    ipc_log_string(
      ipc_log_context,
      "[i][%-4d]mst bridge:%d conn:%d mode set complete %s\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(a1 + 400),
      v36,
      (const char *)(a2 + 80));
    if ( (_drm_debug & 4) != 0 )
      return printk(&unk_25DFA0, *(unsigned int *)(StatusReg + 1800));
    else
      return printk(&unk_223B9A, "dp_mst_bridge_mode_set");
  }
  else
  {
    v15 = get_ipc_log_context();
    ipc_log_string(v15, "[e][%-4d]Invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_21CA0C, "dp_mst_bridge_mode_set");
  }
}
