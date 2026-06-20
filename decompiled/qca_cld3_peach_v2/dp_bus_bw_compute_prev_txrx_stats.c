__int64 __fastcall dp_bus_bw_compute_prev_txrx_stats(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v11; // x19
  __int64 comp_private_obj; // x20
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *v22; // x21
  __int64 v23; // x19
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v26; // x9
  __int64 v27; // x10
  __int64 context; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x8
  void (*v38)(void); // x8
  __int64 v39; // x8

  v9 = *(_QWORD *)(a1 + 216);
  if ( v9 )
  {
    v11 = *(_QWORD *)(v9 + 80);
    if ( a1 )
      goto LABEL_3;
LABEL_18:
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "dp_get_vdev_priv_obj");
    wlan_objmgr_psoc_get_comp_private_obj(v11, 0x2Eu);
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: No dp_link for objmgr vdev %pK",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "dp_bus_bw_compute_prev_txrx_stats",
             a1);
  }
  v11 = 0;
  if ( !a1 )
    goto LABEL_18;
LABEL_3:
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  v13 = wlan_objmgr_psoc_get_comp_private_obj(v11, 0x2Eu);
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: No dp_link for objmgr vdev %pK",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "dp_bus_bw_compute_prev_txrx_stats",
             a1);
  v22 = *(_QWORD **)(comp_private_obj + 32);
  if ( !v22 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Invalid dp_intf for dp_link %pK (%02x:%02x:%02x:**:**:%02x)",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "dp_bus_bw_compute_prev_txrx_stats",
             comp_private_obj,
             *(unsigned __int8 *)(comp_private_obj + 25),
             *(unsigned __int8 *)(comp_private_obj + 26),
             *(unsigned __int8 *)(comp_private_obj + 27),
             *(unsigned __int8 *)(comp_private_obj + 30));
  v23 = v13;
  result = cds_get_conparam();
  if ( (_DWORD)result != 5 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v23 + 1032);
    }
    else
    {
      raw_spin_lock_bh(v23 + 1032);
      *(_QWORD *)(v23 + 1040) |= 1uLL;
    }
    v26 = v22[361];
    v27 = v22[364];
    v22[421] = v22[362];
    v22[420] = v26;
    v22[422] = v27;
    context = _cds_get_context(71, "dp_bus_bw_compute_prev_txrx_stats");
    if ( context && *(_QWORD *)context && (v37 = *(_QWORD *)(*(_QWORD *)context + 64LL)) != 0 )
    {
      v38 = *(void (**)(void))(v37 + 144);
      if ( v38 )
      {
        if ( *((_DWORD *)v38 - 1) != -1253993452 )
          __break(0x8228u);
        v38();
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        1u,
        "%s invalid instance",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "cdp_get_intra_bss_fwd_pkts_count");
    }
    v39 = *(_QWORD *)(v23 + 1040);
    if ( (v39 & 1) != 0 )
    {
      *(_QWORD *)(v23 + 1040) = v39 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v23 + 1032);
    }
    else
    {
      return raw_spin_unlock(v23 + 1032);
    }
  }
  return result;
}
