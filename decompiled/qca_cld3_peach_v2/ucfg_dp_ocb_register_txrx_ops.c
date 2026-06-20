__int64 __fastcall ucfg_dp_ocb_register_txrx_ops(__int64 a1)
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
  __int64 v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  _DWORD *v32; // x8
  __int64 v33; // x1
  __int64 v34; // x0
  _QWORD *v35; // x20
  __int64 v36; // x22
  unsigned __int64 StatusReg; // x8
  _QWORD *v38; // x8
  _QWORD *v39; // x8
  __int64 v40; // x8
  __int16 v41; // w9
  __int64 result; // x0
  _QWORD v43[21]; // [xsp+0h] [xbp-B0h] BYREF
  __int64 v44; // [xsp+A8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v43, 0, sizeof(v43));
  context = _cds_get_context(71, "ucfg_dp_ocb_register_txrx_ops");
  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", v3, v4, v5, v6, v7, v8, v9, v10, "dp_get_vdev_priv_obj");
    goto LABEL_26;
  }
  v11 = (__int64 **)context;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
LABEL_26:
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
      "ucfg_dp_ocb_register_txrx_ops",
      v43[0],
      v43[1],
      v43[2],
      v43[3],
      v43[4],
      v43[5],
      v43[6],
      v43[7],
      v43[8],
      v43[9],
      v43[10],
      v43[11],
      v43[12],
      v43[13],
      v43[14],
      v43[15],
      v43[16],
      v43[17],
      v43[18],
      v43[19],
      v43[20],
      v44);
    result = 4;
    goto LABEL_27;
  }
  v21 = comp_private_obj;
  v22 = *(_QWORD *)(comp_private_obj + 32);
  qdf_mem_set(v43, 0xA8u, 0);
  v43[6] = dp_rx_packet_cbk;
  v43[12] = dp_tx_rx_collect_connectivity_stats_info;
  v43[20] = wlan_dp_link_cdp_vdev_delete_notification;
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
      v43[0],
      v43[1],
      v43[2],
      v43[3],
      v43[4],
      v43[5],
      v43[6],
      v43[7],
      v43[8],
      v43[9],
      v43[10],
      v43[11],
      v43[12],
      v43[13],
      v43[14],
      v43[15],
      v43[16],
      v43[17],
      v43[18],
      v43[19],
      v43[20],
      v44);
LABEL_24:
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
      "ucfg_dp_ocb_register_txrx_ops",
      v43[0]);
    result = 16;
    goto LABEL_27;
  }
  v31 = **v11;
  if ( !v31 )
    goto LABEL_24;
  v32 = *(_DWORD **)(v31 + 272);
  if ( !v32 )
    goto LABEL_24;
  v33 = *(unsigned __int8 *)(v21 + 24);
  if ( *(v32 - 1) != 1635240264 )
    __break(0x8228u);
  v34 = ((__int64 (__fastcall *)(__int64 **, __int64, __int64, _QWORD *))v32)(v11, v33, v21, v43);
  if ( !v43[0] )
    goto LABEL_24;
  v35 = (_QWORD *)v34;
  if ( !v34 )
    goto LABEL_24;
  v36 = **(_QWORD **)(v21 + 32);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v36 + 1536);
  }
  else
  {
    raw_spin_lock_bh(v36 + 1536);
    *(_QWORD *)(v36 + 1544) |= 1uLL;
  }
  v38 = (_QWORD *)(v21 + 112);
  do
    v38 = (_QWORD *)*v38;
  while ( v38 != v35 && v38 );
  if ( !v38 )
  {
    *v35 = 0;
    v39 = *(_QWORD **)(v21 + 120);
    v35[1] = v39;
    *v39 = v35;
    *(_QWORD *)(v21 + 120) = v35;
  }
  v40 = *(_QWORD *)(v36 + 1544);
  if ( (v40 & 1) != 0 )
  {
    *(_QWORD *)(v36 + 1544) = v40 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v36 + 1536);
  }
  else
  {
    raw_spin_unlock(v36 + 1536);
  }
  memcpy((void *)(v22 + 64), v43, 0xA8u);
  v41 = *(_WORD *)(v21 + 29);
  result = 0;
  *(_DWORD *)(v21 + 70) = *(_DWORD *)(v21 + 25);
  *(_WORD *)(v21 + 74) = v41;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
