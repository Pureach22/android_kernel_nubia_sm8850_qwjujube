__int64 __fastcall mon_mlme_vdev_disconnect_peers(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  v9 = *(_QWORD *)(*(_QWORD *)(a1 + 504) + 152LL);
  if ( v9 && (v11 = *(_QWORD *)(v9 + 80)) != 0 )
  {
    tgt_set_pdev_stats_update_period(v11, *(unsigned __int8 *)(v9 + 40), 0);
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: vdev id = %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "mon_mlme_vdev_disconnect_peers",
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL));
    return wlan_vdev_mlme_sm_deliver_evt(*(_QWORD *)(a1 + 504), 0x11u, 0, 0, v20, v21, v22, v23, v24, v25, v26, v27);
  }
  else
  {
    qdf_trace_msg(0x1Fu, 8u, "%s: Invalid psoc", a2, a3, a4, a5, a6, a7, a8, a9, "mon_mlme_vdev_disconnect_peers");
    return 4;
  }
}
