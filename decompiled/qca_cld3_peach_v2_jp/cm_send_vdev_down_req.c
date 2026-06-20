__int64 __fastcall cm_send_vdev_down_req(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  v2 = _qdf_mem_malloc(8u, "cm_send_vdev_down_req", 355);
  if ( !v2 )
    return 2;
  *(_DWORD *)v2 = 0;
  *(_BYTE *)(v2 + 4) = *(_BYTE *)(a1 + 104);
  return wlan_vdev_mlme_sm_deliver_evt(a1, 0x1Au, 8u, v2, v3, v4, v5, v6, v7, v8, v9, v10);
}
