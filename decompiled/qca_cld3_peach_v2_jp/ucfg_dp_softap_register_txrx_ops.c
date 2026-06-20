__int64 __fastcall ucfg_dp_softap_register_txrx_ops(__int64 a1, _QWORD *a2)
{
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 **v13; // x21
  __int64 comp_private_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _DWORD *v23; // x22
  __int64 v24; // x20
  __int64 (__fastcall *v25)(__int64, unsigned int, double, double, double, double, double, double, double, double); // x8
  __int64 (__fastcall *v26)(__int64, unsigned int); // x9
  void *v27; // x10
  __int64 (__fastcall *v28)(__int64, __int64 *, double, double, double, double, double, double, double, double); // x11
  __int64 v30; // x8
  _DWORD *v31; // x8
  __int64 v32; // x1
  __int64 v33; // x0
  _QWORD *v34; // x21
  __int64 v35; // x23
  unsigned __int64 StatusReg; // x8
  _QWORD *v37; // x8
  _QWORD *v38; // x8
  __int64 v39; // x8

  context = _cds_get_context(71, "ucfg_dp_softap_register_txrx_ops");
  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", v5, v6, v7, v8, v9, v10, v11, v12, "dp_get_vdev_priv_obj");
    goto LABEL_6;
  }
  v13 = (__int64 **)context;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
LABEL_6:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: DP link not found",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "ucfg_dp_softap_register_txrx_ops");
    return 4;
  }
  v23 = *(_DWORD **)(comp_private_obj + 32);
  a2[4] = dp_softap_notify_tx_compl_cbk;
  v24 = comp_private_obj;
  if ( (*(_BYTE *)(*(_QWORD *)v23 + 371LL) & 1) != 0 )
  {
    v25 = dp_rx_thread_gro_flush_ind_cbk;
    v26 = dp_rx_flush_packet_cbk;
    v27 = &dp_softap_rx_packet_cbk;
    v28 = dp_rx_pkt_thread_enqueue_cbk;
  }
  else
  {
    v27 = nullptr;
    v26 = nullptr;
    v25 = dp_rx_gro_flush_cbk;
    v28 = (__int64 (__fastcall *)(__int64, __int64 *, double, double, double, double, double, double, double, double))&dp_softap_rx_packet_cbk;
  }
  a2[6] = v28;
  a2[7] = v27;
  a2[8] = v26;
  a2[9] = v25;
  if ( *(_BYTE *)(*(_QWORD *)v23 + 218LL) == 1 && v23[7] != 6 )
  {
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: FISA feature enabled",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "ucfg_dp_softap_register_txrx_ops");
    a2[14] = wlan_dp_rx_fisa_cbk;
    a2[15] = wlan_dp_rx_fisa_flush_by_ctx_id;
  }
  a2[19] = wlan_dp_get_tsf_time;
  a2[20] = wlan_dp_link_cdp_vdev_delete_notification;
  if ( !v13 || !*v13 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v15, v16, v17, v18, v19, v20, v21, v22, "cdp_vdev_register");
LABEL_32:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: vdev register fail",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "ucfg_dp_softap_register_txrx_ops");
    return 16;
  }
  v30 = **v13;
  if ( !v30 )
    goto LABEL_32;
  v31 = *(_DWORD **)(v30 + 272);
  if ( !v31 )
    goto LABEL_32;
  v32 = *(unsigned __int8 *)(v24 + 24);
  if ( *(v31 - 1) != 1635240264 )
    __break(0x8228u);
  v33 = ((__int64 (__fastcall *)(__int64 **, __int64, __int64, _QWORD *))v31)(v13, v32, v24, a2);
  if ( !*a2 )
    goto LABEL_32;
  v34 = (_QWORD *)v33;
  if ( !v33 )
    goto LABEL_32;
  v35 = **(_QWORD **)(v24 + 32);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v35 + 1536);
  }
  else
  {
    raw_spin_lock_bh(v35 + 1536);
    *(_QWORD *)(v35 + 1544) |= 1uLL;
  }
  v37 = (_QWORD *)(v24 + 112);
  do
    v37 = (_QWORD *)*v37;
  while ( v37 != v34 && v37 );
  if ( !v37 )
  {
    *v34 = 0;
    v38 = *(_QWORD **)(v24 + 120);
    v34[1] = v38;
    *v38 = v34;
    *(_QWORD *)(v24 + 120) = v34;
  }
  v39 = *(_QWORD *)(v35 + 1544);
  if ( (v39 & 1) != 0 )
  {
    *(_QWORD *)(v35 + 1544) = v39 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v35 + 1536);
  }
  else
  {
    raw_spin_unlock(v35 + 1536);
  }
  memcpy(v23 + 16, a2, 0xA8u);
  *(_DWORD *)(v24 + 80) &= ~1u;
  return 0;
}
