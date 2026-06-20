__int64 __fastcall ucfg_dp_update_dhcp_state_on_disassoc(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  _QWORD *peer_by_mac; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x19
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w8
  __int64 v41; // x21
  __int64 v43; // x4
  __int64 v44; // x5
  __int64 v45; // x6
  __int64 v46; // x7

  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_vdev_priv_obj");
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: DP link not found",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "ucfg_dp_update_dhcp_state_on_disassoc");
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: DP link not found",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "ucfg_dp_update_dhcp_state_on_disassoc");
  v20 = comp_private_obj;
  peer_by_mac = wlan_objmgr_get_peer_by_mac(***(_QWORD ***)(comp_private_obj + 32), a2, 0x61u);
  if ( peer_by_mac )
  {
    v30 = (__int64)peer_by_mac;
    v31 = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0x2Eu);
    if ( v31 )
    {
      v40 = *(_DWORD *)(v31 + 20);
      v41 = v31;
      *(_DWORD *)(v31 + 16) = 0;
      if ( v40 == 1 )
        dp_post_dhcp_ind(v20, (unsigned __int8 *)v31, 0, v32, v33, v34, v35, v36, v37, v38, v39);
      *(_DWORD *)(v41 + 20) = 0;
    }
    else
    {
      qdf_trace_msg(0x45u, 2u, "%s: peer is null", v32, v33, v34, v35, v36, v37, v38, v39, "dp_get_peer_priv_obj");
    }
    return wlan_objmgr_peer_release_ref(v30, 0x61u, v32, v33, v34, v35, v36, v37, v38, v39);
  }
  else
  {
    if ( a2 )
    {
      v43 = *a2;
      v44 = a2[1];
      v45 = a2[2];
      v46 = a2[5];
    }
    else
    {
      v45 = 0;
      v43 = 0;
      v44 = 0;
      v46 = 0;
    }
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Peer object not found mac:%02x:%02x:%02x:**:**:%02x",
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             "ucfg_dp_update_dhcp_state_on_disassoc",
             v43,
             v44,
             v45,
             v46);
  }
}
