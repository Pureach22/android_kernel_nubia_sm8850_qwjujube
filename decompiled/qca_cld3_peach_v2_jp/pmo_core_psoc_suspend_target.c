__int64 __fastcall pmo_core_psoc_suspend_target(__int64 a1, char a2)
{
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x8
  __int64 v16; // x22
  __int64 v17; // x21
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x8
  _DWORD *v27; // x8
  unsigned int v28; // w20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  _BYTE v46[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v47; // [xsp+8h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46[0] = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( !comp_private_obj )
  {
    v16 = 0;
    goto LABEL_8;
  }
  v13 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(comp_private_obj + 1040);
      v15 = *(_QWORD *)(v13 + 1048) | 1LL;
      *(_QWORD *)(v13 + 1048) = v15;
      v16 = *(_QWORD *)(v13 + 960);
      if ( (v15 & 1) == 0 )
        goto LABEL_6;
LABEL_23:
      *(_QWORD *)(v13 + 1048) = v15 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v13 + 1040);
      goto LABEL_8;
    }
  }
  raw_spin_lock(comp_private_obj + 1040);
  v15 = *(_QWORD *)(v13 + 1048);
  v16 = *(_QWORD *)(v13 + 960);
  if ( (v15 & 1) != 0 )
    goto LABEL_23;
LABEL_6:
  raw_spin_unlock(v13 + 1040);
LABEL_8:
  qdf_trace_msg(0x4Du, 8u, "%s: enter", v5, v6, v7, v8, v9, v10, v11, v12, "pmo_core_psoc_suspend_target");
  v17 = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( v16 && *(_QWORD *)v16 && (v26 = *(_QWORD *)(*(_QWORD *)v16 + 136LL)) != 0 )
  {
    v27 = *(_DWORD **)(v26 + 24);
    if ( v27 )
    {
      if ( *(v27 - 1) != -251540498 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v27)(v16, 0);
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "cdp_process_target_suspend_req");
  }
  qdf_event_reset(v17 + 496);
  v46[0] = a2;
  v28 = pmo_tgt_psoc_send_supend_req(a1, v46);
  if ( !v28 )
  {
    pmo_tgt_update_target_suspend_flag(a1, 1);
    v28 = qdf_wait_for_event_completion(v17 + 496, 0xFA0u);
    if ( v28 )
    {
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: Failed to get ACK from firmware for pdev suspend",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "pmo_core_psoc_suspend_target");
      pmo_tgt_update_target_suspend_flag(a1, 0);
      if ( (*(_BYTE *)(v17 + 533) & 1) == 0 )
        _qdf_trigger_self_recovery();
    }
    else
    {
      pmo_tgt_update_target_suspend_acked_flag(a1, 1);
    }
  }
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v29, v30, v31, v32, v33, v34, v35, v36, "pmo_core_psoc_suspend_target");
  _ReadStatusReg(SP_EL0);
  return v28;
}
