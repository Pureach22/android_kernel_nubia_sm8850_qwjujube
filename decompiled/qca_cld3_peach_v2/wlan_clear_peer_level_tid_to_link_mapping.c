__int64 __fastcall wlan_clear_peer_level_tid_to_link_mapping(__int64 a1)
{
  __int64 bsspeer; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x5Au);
  if ( !bsspeer )
    return qdf_trace_msg(
             0x99u,
             2u,
             "%s: Peer not found",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "wlan_clear_peer_level_tid_to_link_mapping");
  v10 = bsspeer;
  v11 = wlan_t2lm_clear_peer_negotiation();
  return wlan_objmgr_peer_release_ref(v10, 0x5Au, v11, v12, v13, v14, v15, v16, v17, v18);
}
