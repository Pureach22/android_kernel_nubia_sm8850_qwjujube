__int64 __fastcall cm_roam_init_req(__int64 a1, __int64 a2, char a3)
{
  unsigned int v4; // w19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  v4 = a2;
  if ( (wlan_vdev_mlme_get_is_mlo_link(a1, a2) & 1) == 0 )
    return wlan_cm_tgt_send_roam_offload_init(a1, v4, a3 & 1);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: MLO ROAM: skip RSO cmd for link vdev %d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "cm_roam_init_req",
    (unsigned __int8)v4);
  return 0;
}
