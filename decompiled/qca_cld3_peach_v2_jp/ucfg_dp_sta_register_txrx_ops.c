__int64 __fastcall ucfg_dp_sta_register_txrx_ops(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 **v11; // x20
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  _DWORD *v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 (__fastcall *v31)(__int64, unsigned int, double, double, double, double, double, double, double, double); // x9
  __int64 (__fastcall *v32)(__int64, unsigned int); // x10
  __int64 (__fastcall *v33)(__int64, _QWORD *, double, double, double, double, double, double, double, double); // x11
  __int64 (__fastcall *v34)(__int64, __int64 *, double, double, double, double, double, double, double, double); // x12
  __int64 result; // x0
  int v36; // w8
  __int64 v37; // x8
  _DWORD *v38; // x8
  __int64 v39; // x1
  __int64 v40; // x0
  _QWORD *v41; // x20
  __int64 v42; // x22
  unsigned __int64 StatusReg; // x8
  _QWORD *v44; // x8
  _QWORD *v45; // x8
  __int64 v46; // x8
  _QWORD v47[21]; // [xsp+0h] [xbp-B0h] BYREF
  __int64 v48; // [xsp+A8h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v47, 0, sizeof(v47));
  context = _cds_get_context(71, "ucfg_dp_sta_register_txrx_ops");
  if ( !a1 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: vdev is null",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "dp_get_vdev_priv_obj",
      v47[0],
      v47[1],
      v47[2],
      v47[3],
      v47[4],
      v47[5],
      v47[6],
      v47[7],
      v47[8],
      v47[9],
      v47[10],
      v47[11],
      v47[12],
      v47[13],
      v47[14],
      v47[15],
      v47[16],
      v47[17],
      v47[18],
      v47[19],
      v47[20],
      v48);
    goto LABEL_6;
  }
  v11 = (__int64 **)context;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
LABEL_6:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: DP link not found",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "ucfg_dp_sta_register_txrx_ops",
      v47[0]);
    result = 4;
    goto LABEL_33;
  }
  v21 = comp_private_obj;
  v22 = *(_DWORD **)(comp_private_obj + 32);
  qdf_mem_set(v47, 0xA8u, 0);
  if ( (*(_BYTE *)(*(_QWORD *)v22 + 371LL) & 1) != 0 )
  {
    v31 = dp_rx_thread_gro_flush_ind_cbk;
    v32 = dp_rx_flush_packet_cbk;
    v33 = dp_rx_packet_cbk;
    v34 = dp_rx_pkt_thread_enqueue_cbk;
  }
  else
  {
    v33 = nullptr;
    v32 = nullptr;
    v31 = dp_rx_gro_flush_cbk;
    v34 = dp_rx_packet_cbk;
  }
  v36 = *(unsigned __int8 *)(*(_QWORD *)v22 + 218LL);
  v47[6] = v34;
  v47[7] = v33;
  v47[8] = v32;
  v47[9] = v31;
  if ( v36 == 1 && v22[7] != 6 )
  {
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: FISA feature enabled",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "ucfg_dp_sta_register_txrx_ops",
      v47[0],
      v47[1],
      v47[2],
      v47[3],
      v47[4],
      v47[5],
      v47[6],
      v47[7],
      v47[8],
      v47[9],
      v47[10],
      v47[11],
      v47[12],
      v47[13],
      v47[14],
      v47[15],
      v47[16],
      v47[17],
      v47[18],
      v47[19],
      v47[20],
      v48);
    v47[14] = wlan_dp_rx_fisa_cbk;
    v47[15] = wlan_dp_rx_fisa_flush_by_ctx_id;
  }
  v47[4] = &dp_sta_notify_tx_comp_cb;
  v47[0] = 0;
  v47[12] = dp_tx_rx_collect_connectivity_stats_info;
  v47[19] = wlan_dp_get_tsf_time;
  v47[20] = wlan_dp_link_cdp_vdev_delete_notification;
  if ( !v11 || !*v11 )
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance:",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "cdp_vdev_register",
      v47[0]);
LABEL_32:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: vdev register fail",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "ucfg_dp_sta_register_txrx_ops",
      v47[0]);
    result = 16;
    goto LABEL_33;
  }
  v37 = **v11;
  if ( !v37 )
    goto LABEL_32;
  v38 = *(_DWORD **)(v37 + 272);
  if ( !v38 )
    goto LABEL_32;
  v39 = *(unsigned __int8 *)(v21 + 24);
  if ( *(v38 - 1) != 1635240264 )
    __break(0x8228u);
  v40 = ((__int64 (__fastcall *)(__int64 **, __int64, __int64, _QWORD *))v38)(v11, v39, v21, v47);
  if ( !v47[0] )
    goto LABEL_32;
  v41 = (_QWORD *)v40;
  if ( !v40 )
    goto LABEL_32;
  v42 = **(_QWORD **)(v21 + 32);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v42 + 1536);
  }
  else
  {
    raw_spin_lock_bh(v42 + 1536);
    *(_QWORD *)(v42 + 1544) |= 1uLL;
  }
  v44 = (_QWORD *)(v21 + 112);
  do
    v44 = (_QWORD *)*v44;
  while ( v44 != v41 && v44 );
  if ( !v44 )
  {
    *v41 = 0;
    v45 = *(_QWORD **)(v21 + 120);
    v41[1] = v45;
    *v45 = v41;
    *(_QWORD *)(v21 + 120) = v41;
  }
  v46 = *(_QWORD *)(v42 + 1544);
  if ( (v46 & 1) != 0 )
  {
    *(_QWORD *)(v42 + 1544) = v46 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v42 + 1536);
  }
  else
  {
    raw_spin_unlock(v42 + 1536);
  }
  memcpy(v22 + 16, v47, 0xA8u);
  result = 0;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
