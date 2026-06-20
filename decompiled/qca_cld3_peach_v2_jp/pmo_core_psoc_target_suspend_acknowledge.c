__int64 __fastcall pmo_core_psoc_target_suspend_acknowledge(__int64 a1, char a2, __int16 a3)
{
  __int64 comp_private_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x23
  unsigned __int64 StatusReg; // x8
  __int64 v17; // x8
  __int64 v18; // x21
  const char *v19; // x2
  __int64 v20; // x23
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned __int64 v37; // x8
  __int64 v38; // x8
  __int64 v39; // x1
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x8
  _DWORD *v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( !comp_private_obj )
  {
    v18 = 0;
    if ( a1 )
      goto LABEL_9;
    goto LABEL_35;
  }
  v15 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj + 1040);
    v17 = *(_QWORD *)(v15 + 1048);
    v18 = *(_QWORD *)(v15 + 960);
    if ( (v17 & 1) == 0 )
      goto LABEL_6;
    goto LABEL_34;
  }
  raw_spin_lock_bh(comp_private_obj + 1040);
  v17 = *(_QWORD *)(v15 + 1048) | 1LL;
  *(_QWORD *)(v15 + 1048) = v17;
  v18 = *(_QWORD *)(v15 + 960);
  if ( (v17 & 1) != 0 )
  {
LABEL_34:
    *(_QWORD *)(v15 + 1048) = v17 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v15 + 1040);
    if ( a1 )
      goto LABEL_9;
LABEL_35:
    v19 = "%s: psoc is null";
    goto LABEL_36;
  }
LABEL_6:
  raw_spin_unlock(v15 + 1040);
  if ( !a1 )
    goto LABEL_35;
LABEL_9:
  if ( (unsigned int)wlan_objmgr_psoc_try_get_ref(a1, 0xAu, v7, v8, v9, v10, v11, v12, v13, v14) )
  {
    v19 = "%s: Failed to get psoc reference";
LABEL_36:
    qdf_trace_msg(0x4Du, 2u, v19, v7, v8, v9, v10, v11, v12, v13, v14, "pmo_core_psoc_target_suspend_acknowledge");
    return qdf_trace_msg(
             0x4Du,
             8u,
             "%s: exit",
             v50,
             v51,
             v52,
             v53,
             v54,
             v55,
             v56,
             v57,
             "pmo_core_psoc_target_suspend_acknowledge");
  }
  v20 = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( (a2 & 1) == 0 && !_cds_get_context(51, (__int64)"pmo_wow_tx_done_cb", v21, v22, v23, v24, v25, v26, v27, v28) )
    qdf_trace_msg(0x33u, 2u, "%s: Invalid hdd_ctx", v29, v30, v31, v32, v33, v34, v35, v36, "pmo_wow_tx_done_cb");
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v37 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v37 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v37 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v20 + 1040);
    v38 = *(_QWORD *)(v20 + 1048);
  }
  else
  {
    raw_spin_lock_bh(v20 + 1040);
    v38 = *(_QWORD *)(v20 + 1048) | 1LL;
    *(_QWORD *)(v20 + 1048) = v38;
  }
  *(_BYTE *)(v20 + 576) = a2 & 1;
  *(_WORD *)(v20 + 578) = a3;
  if ( (v38 & 1) != 0 )
  {
    *(_QWORD *)(v20 + 1048) = v38 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v20 + 1040);
  }
  else
  {
    raw_spin_unlock(v20 + 1040);
  }
  qdf_event_set(v20 + 496, v39);
  if ( (pmo_tgt_psoc_get_runtime_pm_inprogress(a1) & 1) == 0 )
  {
    if ( (a2 & 1) != 0 )
    {
      qdf_wake_lock_timeout_acquire(v20 + 584, 1000);
    }
    else if ( v18 && *(_QWORD *)v18 && (v48 = *(_QWORD *)(*(_QWORD *)v18 + 136LL)) != 0 )
    {
      v49 = *(_DWORD **)(v48 + 16);
      if ( v49 )
      {
        if ( *(v49 - 1) != -251540498 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v49)(v18, 0);
      }
    }
    else
    {
      qdf_trace_msg(0x45u, 1u, "%s invalid instance", v40, v41, v42, v43, v44, v45, v46, v47, "cdp_process_wow_ack_rsp");
    }
  }
  wlan_objmgr_psoc_release_ref(a1, 0xAu, v40, v41, v42, v43, v44, v45, v46, v47);
  return qdf_trace_msg(
           0x4Du,
           8u,
           "%s: exit",
           v50,
           v51,
           v52,
           v53,
           v54,
           v55,
           v56,
           v57,
           "pmo_core_psoc_target_suspend_acknowledge");
}
