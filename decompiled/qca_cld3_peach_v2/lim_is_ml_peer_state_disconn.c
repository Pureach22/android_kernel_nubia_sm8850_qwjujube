bool __fastcall lim_is_ml_peer_state_disconn(__int64 a1, __int64 a2, _BYTE *a3)
{
  _QWORD *peer_by_mac; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  _BOOL4 v14; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(a1 + 21624), a3, 7u);
  if ( peer_by_mac )
  {
    v13 = (__int64)peer_by_mac;
    if ( !*(_DWORD *)(a2 + 7036)
      && (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a2 + 16), v5, v6, v7, v8, v9, v10, v11, v12) & 1) != 0
      && *(_QWORD *)(v13 + 784) )
    {
      v14 = wlan_mlo_peer_is_disconnect_progress() == 0;
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: ML peer ctx not found",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "lim_is_ml_peer_state_disconn");
      v14 = 0;
    }
    wlan_objmgr_peer_release_ref(v13, 7u, v15, v16, v17, v18, v19, v20, v21, v22);
  }
  else
  {
    qdf_trace_msg(0x35u, 2u, "%s: peer is NULL", v5, v6, v7, v8, v9, v10, v11, v12, "lim_is_ml_peer_state_disconn");
    return 0;
  }
  return v14;
}
