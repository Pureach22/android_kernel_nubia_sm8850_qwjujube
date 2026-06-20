__int64 __fastcall dp_mst_bridge_disable(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 ipc_log_context; // x0
  void *v9; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 result; // x0
  __int64 v14; // x20
  __int64 v15; // x24
  int v16; // w7
  __int64 v17; // x8
  __int64 v18; // x21
  __int64 v19; // x22
  int v20; // w5
  __int64 v21; // x1
  int v22; // w4
  _DWORD *v23; // x8
  void (*v24)(void); // x8
  __int64 v25; // x23
  __int64 mst_payload_state; // x0
  __int64 v27; // x0
  void (__fastcall *v28)(__int64, __int64, __int64); // x8
  __int64 v29; // x0
  unsigned __int64 StatusReg; // x21
  __int64 (__fastcall *v31)(__int64, __int64); // x8
  __int64 v32; // x1
  int v33; // w0
  int v34; // w7
  int v35; // w20
  __int64 v36; // x0
  __int64 v37; // x20
  __int64 v38; // x8
  __int64 v39; // x22
  __int64 v40; // x21
  int v41; // w5
  void (__fastcall *v42)(__int64, __int64); // x8
  _DWORD *v43; // x8
  void (__fastcall *v44)(_QWORD); // x8
  __int64 v45; // x0
  unsigned __int64 v46; // x20
  __int64 v47; // x0
  unsigned __int64 v48; // x20
  __int64 v49; // x8
  int v50; // w4
  int v51; // w7
  __int64 v52; // x8
  int v53; // w5
  _QWORD v54[2]; // [xsp+0h] [xbp-10h] BYREF

  v54[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_21CA0C;
LABEL_7:
    result = printk(v9, "dp_mst_bridge_disable");
    goto LABEL_56;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  v11 = *(_QWORD *)(a1 + 1344);
  if ( !v11 )
  {
    v12 = get_ipc_log_context();
    ipc_log_string(v12, "[e][%-4d]Invalid connector\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_2344C7;
    goto LABEL_7;
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_mst_bridge_disable",
    1011,
    8,
    4369,
    *(_DWORD *)(v11 + 64),
    -1059143953,
    a8,
    v54[0]);
  v14 = *(_QWORD *)(a1 + 408);
  v15 = *(_QWORD *)(v14 + 40);
  sde_connector_helper_bridge_disable(*(_QWORD *)(a1 + 1344));
  mutex_lock(v15 + 4136);
  v17 = *(_QWORD *)(a1 + 1344);
  v18 = *(_QWORD *)(*(_QWORD *)(a1 + 408) + 40LL);
  v19 = *(_QWORD *)(v17 + 2776);
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v17 = *(_QWORD *)(a1 + 1344);
  }
  if ( v17 )
    v20 = *(_DWORD *)(v17 + 64);
  else
    v20 = 0;
  sde_evtlog_log(sde_dbg_base_evtlog, "_dp_mst_bridge_pre_disable_part1", 819, 8, 4369, v20, -1059143953, v16, v54[0]);
  if ( *(_DWORD *)(v18 + 4232) == 1 )
  {
    v21 = *(unsigned int *)(a1 + 1360);
    v22 = 0;
    v54[0] = 0;
    if ( (_DWORD)v21 )
    {
      v23 = *(_DWORD **)(*(_QWORD *)(v18 + 4128) + 96LL);
      if ( *(v23 - 1) != -1189901681 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, char *, _QWORD *, _QWORD, _QWORD, _QWORD))v23)(
        v18 + 32,
        v21,
        (char *)v54 + 4,
        v54,
        0,
        0,
        0);
      v22 = v54[0];
    }
    *(_DWORD *)(a1 + 1368) = v22;
    v24 = *(void (**)(void))(*(_QWORD *)(v18 + 4120) + 264LL);
    if ( *((_DWORD *)v24 - 1) != -133057824 )
      __break(0x8228u);
    v24();
  }
  else
  {
    v25 = *(_QWORD *)(v18 + 120);
    mst_payload_state = drm_atomic_get_mst_payload_state(v25, v19);
    if ( mst_payload_state )
    {
      v28 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v18 + 4128) + 24LL);
      if ( *((_DWORD *)v28 - 1) != 775260770 )
        __break(0x8228u);
      v28(v18 + 32, v25, mst_payload_state);
      dp_mst_update_timeslots(v18, a1, v19);
      v29 = get_ipc_log_context();
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(
        v29,
        "[d][%-4d]mst bridge [%d] _pre disable part-1 complete\n",
        *(_DWORD *)(StatusReg + 1800),
        *(_DWORD *)(a1 + 400));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]mst bridge [%d] _pre disable part-1 complete\n",
          *(_DWORD *)(StatusReg + 1800),
          *(_DWORD *)(a1 + 400));
    }
    else
    {
      v27 = get_ipc_log_context();
      ipc_log_string(
        v27,
        "[e][%-4d]mst bridge [%d] _pre disable part-1 failed, null payload\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 400));
      printk(&unk_237BE2, "_dp_mst_bridge_pre_disable_part1");
    }
  }
  v31 = *(__int64 (__fastcall **)(__int64, __int64))(v14 + 96);
  v32 = *(_QWORD *)(a1 + 1352);
  if ( *((_DWORD *)v31 - 1) != -1533774139 )
    __break(0x8228u);
  v33 = v31(v14, v32);
  if ( v33 )
  {
    v35 = v33;
    v36 = get_ipc_log_context();
    ipc_log_string(
      v36,
      "[e][%-4d][%d] DP display pre disable failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 400),
      v35);
    printk(&unk_2456DC, "dp_mst_bridge_disable");
  }
  v37 = *(_QWORD *)(a1 + 408);
  v38 = *(_QWORD *)(a1 + 1344);
  v39 = *(_QWORD *)(v37 + 40);
  v40 = *(_QWORD *)(v38 + 2776);
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v38 = *(_QWORD *)(a1 + 1344);
  }
  if ( v38 )
    v41 = *(_DWORD *)(v38 + 64);
  else
    v41 = 0;
  sde_evtlog_log(sde_dbg_base_evtlog, "_dp_mst_bridge_pre_disable_part2", 862, 8, 4369, v41, -1059143953, v34, v54[0]);
  if ( *(_DWORD *)(v39 + 4232) == 1 )
  {
    v42 = *(void (__fastcall **)(__int64, __int64))(v37 + 288);
    if ( *((_DWORD *)v42 - 1) != 169801067 )
      __break(0x8228u);
    v42(v37, 1);
    drm_dp_send_power_updown_phy(v39 + 32, v40, 0);
    v43 = *(_DWORD **)(v37 + 288);
    if ( *(v43 - 1) != 169801067 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v43)(v37, 0);
  }
  else
  {
    v44 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v39 + 4128) + 64LL);
    if ( *((_DWORD *)v44 - 1) != -81624539 )
      __break(0x8228u);
    v44(v39 + 32);
    v45 = get_ipc_log_context();
    v46 = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      v45,
      "[d][%-4d]mst bridge [%d] _pre disable part-2 complete\n",
      *(_DWORD *)(v46 + 1800),
      *(_DWORD *)(a1 + 400));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]mst bridge [%d] _pre disable part-2 complete\n",
        *(_DWORD *)(v46 + 1800),
        *(_DWORD *)(a1 + 400));
  }
  v47 = get_ipc_log_context();
  v48 = _ReadStatusReg(SP_EL0);
  v49 = *(_QWORD *)(a1 + 1344);
  if ( v49 )
    v50 = *(_DWORD *)(v49 + 64);
  else
    v50 = 0;
  ipc_log_string(
    v47,
    "[i][%-4d]mst bridge:%d conn:%d disable complete\n",
    *(_DWORD *)(v48 + 1800),
    *(_DWORD *)(a1 + 400),
    v50);
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_265180, *(unsigned int *)(v48 + 1800));
  else
    printk(&unk_21CE70, "dp_mst_bridge_disable");
  v52 = *(_QWORD *)(a1 + 1344);
  if ( v52 )
    v53 = *(_DWORD *)(v52 + 64);
  else
    v53 = 0;
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_bridge_disable", 1031, 8, 8738, v53, -1059143953, v51, v54[0]);
  result = mutex_unlock(v15 + 4136);
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return result;
}
