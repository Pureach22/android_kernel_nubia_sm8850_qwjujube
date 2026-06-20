__int64 __fastcall target_if_vdev_mgr_mac_addr_rsp_timeout(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x23
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  void (__fastcall *v50)(__int64, __int64); // x8

  v11 = *(_QWORD *)(a1 + 2136);
  if ( v11 )
  {
    v15 = ((__int64 (*)(void))wlan_objmgr_get_vdev_by_id_from_psoc)();
    if ( v15 )
    {
      v24 = v15;
      target_if_vdev_mgr_rsp_timer_stop(a1, a2, 6);
      qdf_trace_msg(
        0x68u,
        2u,
        "PSOC_%d VDEV_%d: %s rsp timeout",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        *(unsigned __int8 *)(a1 + 48),
        a3,
        "UPDATE_MAC_ADDR");
      if ( (qdf_is_recovering() & 1) != 0 || (qdf_is_fw_down(v33, v34, v35, v36, v37, v38, v39, v40) & 1) != 0 )
        qdf_trace_msg(
          0x68u,
          8u,
          "PSOC_%d VDEV_%d: Panic not allowed",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          *(unsigned __int8 *)(a1 + 48),
          a3);
      else
        _qdf_trigger_self_recovery();
      v50 = *(void (__fastcall **)(__int64, __int64))(v11 + 1144);
      if ( *((_DWORD *)v50 - 1) != -1710151299 )
        __break(0x8228u);
      v50(v24, 245);
      return wlan_objmgr_vdev_release_ref(v24, 49);
    }
    else
    {
      return qdf_trace_msg(
               0x68u,
               2u,
               "%s: Invalid vdev %d",
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               "target_if_vdev_mgr_mac_addr_rsp_timeout",
               a3);
    }
  }
  else
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "target_if_vdev_mgr_get_rx_ops");
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: No Rx Ops",
             v41,
             v42,
             v43,
             v44,
             v45,
             v46,
             v47,
             v48,
             "target_if_vdev_mgr_mac_addr_rsp_timeout");
  }
}
