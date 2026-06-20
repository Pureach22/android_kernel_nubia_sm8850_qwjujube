__int64 __fastcall nan_set_ndi_vdev_id_for_migrated_peer(__int64 a1, _BYTE *a2, char a3)
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
  __int64 comp_private_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w21

  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2, 0x14u);
  if ( peer_by_mac )
  {
    v13 = (__int64)peer_by_mac;
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0xFu);
    if ( comp_private_obj )
    {
      v23 = 0;
      *(_BYTE *)(comp_private_obj + 72) = a3;
    }
    else
    {
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: NAN peer priv obj is null",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "nan_set_ndi_vdev_id_for_migrated_peer");
      v23 = 29;
    }
    wlan_objmgr_peer_release_ref(v13, 0x14u, v15, v16, v17, v18, v19, v20, v21, v22);
  }
  else
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: peer is null",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "nan_set_ndi_vdev_id_for_migrated_peer");
    return 29;
  }
  return v23;
}
