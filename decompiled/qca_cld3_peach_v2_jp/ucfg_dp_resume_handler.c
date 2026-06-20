_BYTE *__fastcall ucfg_dp_resume_handler(__int64 a1)
{
  __int64 **context; // x20
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 v13; // x8
  _DWORD *v14; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x8
  __int64 v17; // x23
  unsigned __int64 v18; // x22
  __int64 v19; // x0
  _QWORD *v20; // x1
  __int64 v21; // x8
  __int64 v22; // x9
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _QWORD *v31; // x8
  __int64 v32; // x23
  __int64 v33; // x8
  _BYTE *result; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 (*v43)(void); // x8
  _BYTE *v44; // x19
  int v45; // w8
  _QWORD *v46; // [xsp+8h] [xbp-28h] BYREF
  _QWORD *v47; // [xsp+10h] [xbp-20h] BYREF
  __int64 v48; // [xsp+18h] [xbp-18h] BYREF
  __int64 v49[2]; // [xsp+20h] [xbp-10h] BYREF

  v49[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49[0] = 0;
  v47 = nullptr;
  v48 = 0;
  v46 = nullptr;
  context = (__int64 **)_cds_get_context(71, "ucfg_dp_resume_handler");
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(0x45u, 2u, "%s: DP context not found", v4, v5, v6, v7, v8, v9, v10, v11, "ucfg_dp_resume_handler");
    result = (_BYTE *)&off_10;
    goto LABEL_60;
  }
  v12 = comp_private_obj;
  *(_BYTE *)(comp_private_obj + 872) = 0;
  if ( context && *context )
  {
    v13 = **context;
    if ( v13 )
    {
      v14 = *(_DWORD **)(v13 + 736);
      if ( v14 )
      {
        if ( *(v14 - 1) != -251540498 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64 **, _QWORD))v14)(context, 0);
      }
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_14;
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v4, v5, v6, v7, v8, v9, v10, v11, "cdp_set_tx_pause");
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_14;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
  {
    raw_spin_lock_bh(v12 + 264);
    *(_QWORD *)(v12 + 272) |= 1uLL;
    goto LABEL_15;
  }
LABEL_14:
  raw_spin_lock(v12 + 264);
LABEL_15:
  dp_get_front_intf_no_lock(v12, v49);
  dp_get_next_intf_no_lock(v12, v49[0], &v48);
  v16 = *(_QWORD *)(v12 + 272);
  if ( (v16 & 1) != 0 )
  {
    *(_QWORD *)(v12 + 272) = v16 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v12 + 264);
    v17 = v49[0];
    if ( !v49[0] )
      goto LABEL_48;
  }
  else
  {
    raw_spin_unlock(v12 + 264);
    v17 = v49[0];
    if ( !v49[0] )
      goto LABEL_48;
  }
  v18 = _ReadStatusReg(SP_EL0);
  do
  {
LABEL_18:
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v18 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v18 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v17 + 3672);
    }
    else
    {
      raw_spin_lock_bh(v17 + 3672);
      *(_QWORD *)(v17 + 3680) |= 1uLL;
    }
    dp_get_front_link_no_lock(v49[0], &v47);
    v19 = v49[0];
    v20 = v47;
    while ( 1 )
    {
      dp_get_next_link_no_lock(v19, v20, &v46);
      v21 = v49[0];
      v22 = *(_QWORD *)(v49[0] + 3680);
      if ( (v22 & 1) != 0 )
        break;
      raw_spin_unlock(v49[0] + 3672);
      v31 = v47;
      if ( !v47 )
        goto LABEL_35;
LABEL_25:
      *((_DWORD *)v31 + 20) &= ~8u;
      qdf_trace_msg(
        0x45u,
        8u,
        "%s: sap_tx_block_mask 0x%x",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "ucfg_dp_resume_handler");
      v32 = v49[0];
      if ( !*((_DWORD *)v47 + 20) )
        *(_BYTE *)(v49[0] + 3580) = 0;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v18 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v18 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v32 + 3672);
      }
      else
      {
        raw_spin_lock_bh(v32 + 3672);
        *(_QWORD *)(v32 + 3680) |= 1uLL;
      }
      v20 = v46;
      v19 = v49[0];
      v47 = v46;
    }
    *(_QWORD *)(v49[0] + 3680) = v22 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v21 + 3672);
    v31 = v47;
    if ( v47 )
      goto LABEL_25;
LABEL_35:
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v18 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v18 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v12 + 264);
    }
    else
    {
      raw_spin_lock_bh(v12 + 264);
      *(_QWORD *)(v12 + 272) |= 1uLL;
    }
    v49[0] = v48;
    dp_get_next_intf_no_lock(v12, v48, &v48);
    v33 = *(_QWORD *)(v12 + 272);
    if ( (v33 & 1) == 0 )
    {
      raw_spin_unlock(v12 + 264);
      v17 = v49[0];
      if ( !v49[0] )
        break;
      goto LABEL_18;
    }
    *(_QWORD *)(v12 + 272) = v33 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v12 + 264);
    v17 = v49[0];
  }
  while ( v49[0] );
LABEL_48:
  if ( *(_BYTE *)(v12 + 371) != 1 )
    goto LABEL_59;
  result = (_BYTE *)_cds_get_context(71, "ucfg_dp_resume_handler");
  if ( result )
  {
    if ( !*(_QWORD *)result )
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance:",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "cdp_soc_get_dp_txrx_handle");
      goto LABEL_59;
    }
    v43 = *(__int64 (**)(void))(**(_QWORD **)result + 624LL);
    if ( !v43 )
      goto LABEL_59;
    if ( *((_DWORD *)v43 - 1) != -1355198606 )
      __break(0x8228u);
    result = (_BYTE *)v43();
    if ( result )
    {
      if ( result[256] != 1 || (v44 = result, v45 = dp_rx_refill_thread_resume(result + 56), result = v44, !v45) )
        dp_rx_tm_resume(result + 16);
LABEL_59:
      result = nullptr;
    }
  }
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
