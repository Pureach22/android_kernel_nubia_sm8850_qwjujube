__int64 __fastcall ucfg_dp_suspend_handler(__int64 a1)
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
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 (*v22)(void); // x8
  __int64 v23; // x0
  __int64 v24; // x21
  unsigned int v25; // w22
  unsigned int v26; // w0
  __int64 result; // x0
  __int64 v28; // x8
  void (__fastcall *v29)(__int64 **, __int64); // x8
  unsigned __int64 StatusReg; // x8
  __int64 v31; // x8
  __int64 v32; // x24
  unsigned __int64 v33; // x22
  __int64 v34; // x0
  _QWORD *v35; // x1
  __int64 v36; // x8
  __int64 v37; // x9
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  _QWORD *v46; // x8
  __int64 v47; // x24
  __int64 v48; // x8
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 (*v58)(void); // x8
  __int64 v59; // x0
  __int64 v60; // x19
  int v61; // w8
  _QWORD *v62; // [xsp+8h] [xbp-28h] BYREF
  _QWORD *v63; // [xsp+10h] [xbp-20h] BYREF
  __int64 v64; // [xsp+18h] [xbp-18h] BYREF
  __int64 v65[2]; // [xsp+20h] [xbp-10h] BYREF

  v65[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v65[0] = 0;
  v63 = nullptr;
  v64 = 0;
  v62 = nullptr;
  context = (__int64 **)_cds_get_context(71, "ucfg_dp_suspend_handler");
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(0x45u, 2u, "%s: DP context not found", v4, v5, v6, v7, v8, v9, v10, v11, "ucfg_dp_suspend_handler");
    result = 16;
    goto LABEL_73;
  }
  v12 = comp_private_obj;
  if ( *(_BYTE *)(comp_private_obj + 371) != 1 )
    goto LABEL_15;
  v13 = _cds_get_context(71, "ucfg_dp_suspend_handler");
  if ( !v13 )
  {
    v25 = 4;
    goto LABEL_60;
  }
  if ( !*(_QWORD *)v13 )
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance:",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "cdp_soc_get_dp_txrx_handle");
LABEL_59:
    v25 = 5;
    goto LABEL_60;
  }
  v22 = *(__int64 (**)(void))(**(_QWORD **)v13 + 624LL);
  if ( !v22 )
    goto LABEL_59;
  if ( *((_DWORD *)v22 - 1) != -1355198606 )
    __break(0x8228u);
  v23 = v22();
  if ( !v23 )
    goto LABEL_59;
  v24 = v23;
  if ( *(_BYTE *)(v23 + 256) != 1 || (v25 = dp_rx_refill_thread_suspend(v23 + 56)) == 0 )
  {
    v26 = dp_rx_tm_suspend(v24 + 16);
    if ( v26 )
    {
      v25 = v26;
      if ( *(_BYTE *)(v24 + 256) == 1 )
        dp_rx_refill_thread_resume(v24 + 56);
      goto LABEL_60;
    }
LABEL_15:
    *(_BYTE *)(v12 + 872) = 1;
    if ( context && *context )
    {
      v28 = **context;
      if ( v28 )
      {
        v29 = *(void (__fastcall **)(__int64 **, __int64))(v28 + 736);
        if ( v29 )
        {
          if ( *((_DWORD *)v29 - 1) != -251540498 )
            __break(0x8228u);
          v29(context, 1);
        }
      }
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        goto LABEL_27;
    }
    else
    {
      qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v4, v5, v6, v7, v8, v9, v10, v11, "cdp_set_tx_pause");
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        goto LABEL_27;
    }
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(v12 + 264);
      *(_QWORD *)(v12 + 272) |= 1uLL;
      goto LABEL_28;
    }
LABEL_27:
    raw_spin_lock(v12 + 264);
LABEL_28:
    dp_get_front_intf_no_lock(v12, v65);
    dp_get_next_intf_no_lock(v12, v65[0], &v64);
    v31 = *(_QWORD *)(v12 + 272);
    if ( (v31 & 1) != 0 )
    {
      *(_QWORD *)(v12 + 272) = v31 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v12 + 264);
      v32 = v65[0];
      if ( !v65[0] )
        goto LABEL_72;
    }
    else
    {
      raw_spin_unlock(v12 + 264);
      v32 = v65[0];
      if ( !v65[0] )
        goto LABEL_72;
    }
    v33 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v33 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v33 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v32 + 3672);
      }
      else
      {
        raw_spin_lock_bh(v32 + 3672);
        *(_QWORD *)(v32 + 3680) |= 1uLL;
      }
      dp_get_front_link_no_lock(v65[0], &v63);
      v34 = v65[0];
      v35 = v63;
      while ( 1 )
      {
        dp_get_next_link_no_lock(v34, v35, &v62);
        v36 = v65[0];
        v37 = *(_QWORD *)(v65[0] + 3680);
        if ( (v37 & 1) != 0 )
          break;
        raw_spin_unlock(v65[0] + 3672);
        v46 = v63;
        if ( !v63 )
          goto LABEL_46;
LABEL_38:
        *((_DWORD *)v46 + 20) |= 8u;
        qdf_trace_msg(
          0x45u,
          8u,
          "%s: sap_tx_block_mask 0x%x",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "ucfg_dp_suspend_handler");
        v47 = v65[0];
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v33 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v33 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v65[0] + 3672);
        }
        else
        {
          raw_spin_lock_bh(v47 + 3672);
          *(_QWORD *)(v47 + 3680) |= 1uLL;
        }
        v35 = v62;
        v34 = v65[0];
        v63 = v62;
      }
      *(_QWORD *)(v65[0] + 3680) = v37 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v36 + 3672);
      v46 = v63;
      if ( v63 )
        goto LABEL_38;
LABEL_46:
      *(_BYTE *)(v65[0] + 3580) = 1;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v33 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v33 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v12 + 264);
      }
      else
      {
        raw_spin_lock_bh(v12 + 264);
        *(_QWORD *)(v12 + 272) |= 1uLL;
      }
      v65[0] = v64;
      dp_get_next_intf_no_lock(v12, v64, &v64);
      v48 = *(_QWORD *)(v12 + 272);
      if ( (v48 & 1) == 0 )
      {
        raw_spin_unlock(v12 + 264);
        v32 = v65[0];
        if ( !v65[0] )
          goto LABEL_72;
        continue;
      }
      *(_QWORD *)(v12 + 272) = v48 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v12 + 264);
      v32 = v65[0];
      if ( !v65[0] )
      {
LABEL_72:
        result = 0;
        goto LABEL_73;
      }
    }
  }
LABEL_60:
  v49 = _cds_get_context(71, "ucfg_dp_suspend_handler");
  if ( v49 )
  {
    if ( !*(_QWORD *)v49 )
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance:",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "cdp_soc_get_dp_txrx_handle");
      result = v25;
      goto LABEL_73;
    }
    v58 = *(__int64 (**)(void))(**(_QWORD **)v49 + 624LL);
    if ( v58 )
    {
      if ( *((_DWORD *)v58 - 1) != -1355198606 )
        __break(0x8228u);
      v59 = v58();
      if ( v59 )
      {
        if ( *(_BYTE *)(v59 + 256) != 1 || (v60 = v59, v61 = dp_rx_refill_thread_resume(v59 + 56), v59 = v60, !v61) )
          dp_rx_tm_resume(v59 + 16);
      }
    }
  }
  result = v25;
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return result;
}
