__int64 __fastcall tdls_is_vdev_allowed_to_tx(__int64 a1)
{
  char v2; // w19
  __int64 bsspeer; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  if ( !(unsigned int)wlan_vdev_is_up() )
  {
    bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x11u);
    if ( bsspeer )
    {
      v2 = *(_BYTE *)(bsspeer + 87);
      wlan_objmgr_peer_release_ref(bsspeer, 0x11u, v4, v5, v6, v7, v8, v9, v10, v11);
      return v2 & 1;
    }
    qdf_trace_msg(
      0,
      2u,
      "%s: BSS peer for vdev %d is null",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "tdls_is_vdev_authenticated",
      *(unsigned __int8 *)(a1 + 168));
  }
  v2 = 0;
  return v2 & 1;
}
