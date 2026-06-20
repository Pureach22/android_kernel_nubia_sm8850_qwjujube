__int64 __fastcall tdls_is_vdev_authenticated(__int64 a1)
{
  __int64 bsspeer; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  char v11; // w19

  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x11u);
  if ( bsspeer )
  {
    v11 = *(_BYTE *)(bsspeer + 87);
    wlan_objmgr_peer_release_ref(bsspeer, 0x11u, v3, v4, v5, v6, v7, v8, v9, v10);
  }
  else
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: BSS peer for vdev %d is null",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "tdls_is_vdev_authenticated",
      *(unsigned __int8 *)(a1 + 104));
    v11 = 0;
  }
  return v11 & 1;
}
