bool __fastcall csr_if_peer_present(__int64 a1, unsigned __int8 *a2, unsigned __int8 *a3)
{
  _QWORD *peer_by_mac_n_vdev; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _QWORD *v14; // x19
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  int v19; // w8
  int v20; // w9
  int v21; // w10
  int v22; // w11

  peer_by_mac_n_vdev = wlan_objmgr_get_peer_by_mac_n_vdev(
                         *(_QWORD *)(a1 + 21624),
                         *(_BYTE *)(*(_QWORD *)(a1 + 21632) + 40LL),
                         a2,
                         a3,
                         0xBu);
  v14 = peer_by_mac_n_vdev;
  if ( !peer_by_mac_n_vdev )
  {
    if ( a3 )
    {
      v15 = *a3;
      v16 = a3[1];
      v17 = a3[2];
      v18 = a3[5];
      if ( a2 )
      {
LABEL_5:
        v19 = *a2;
        v20 = a2[1];
        v21 = a2[2];
        v22 = a2[5];
LABEL_8:
        qdf_trace_msg(
          0x34u,
          4u,
          "%s: peer not found for mac: %02x:%02x:%02x:**:**:%02xand bssid: %02x:%02x:%02x:**:**:%02x",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "csr_if_peer_present",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22);
        return v14 != nullptr;
      }
    }
    else
    {
      v17 = 0;
      v15 = 0;
      v16 = 0;
      v18 = 0;
      if ( a2 )
        goto LABEL_5;
    }
    v21 = 0;
    v19 = 0;
    v20 = 0;
    v22 = 0;
    goto LABEL_8;
  }
  wlan_objmgr_peer_release_ref((__int64)peer_by_mac_n_vdev, 0xBu, v6, v7, v8, v9, v10, v11, v12, v13);
  return v14 != nullptr;
}
