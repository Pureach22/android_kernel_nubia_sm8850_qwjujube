__int64 __fastcall dp_bus_bw_compute_reset_prev_txrx_stats(
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
  __int64 comp_private_obj; // x21
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *v22; // x20
  __int64 v23; // x19
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v26; // x8

  v9 = *(_QWORD *)(a1 + 152);
  if ( v9 )
  {
    v11 = *(_QWORD *)(v9 + 80);
    if ( a1 )
      goto LABEL_3;
LABEL_13:
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
             "dp_bus_bw_compute_reset_prev_txrx_stats",
             a1);
  }
  v11 = 0;
  if ( !a1 )
    goto LABEL_13;
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
             "dp_bus_bw_compute_reset_prev_txrx_stats",
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
             "dp_bus_bw_compute_reset_prev_txrx_stats",
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
    v22[424] = 0;
    v22[423] = 0;
    v22[422] = 0;
    v22[421] = 0;
    v22[420] = 0;
    v26 = *(_QWORD *)(v23 + 1040);
    if ( (v26 & 1) != 0 )
    {
      *(_QWORD *)(v23 + 1040) = v26 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v23 + 1032);
    }
    else
    {
      return raw_spin_unlock(v23 + 1032);
    }
  }
  return result;
}
