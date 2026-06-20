__int64 __fastcall sta_mlme_vdev_up_send(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: vdev id = %d ",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sta_mlme_vdev_up_send",
    *(unsigned __int8 *)(*(_QWORD *)(a1 + 520) + 168LL));
  result = wma_sta_vdev_up_send(a1, a2, a3);
  if ( !(_DWORD)result )
  {
    mlme_sr_update(*(_QWORD *)(a1 + 520), 1, v15, v16, v17, v18, v19, v20, v21, v22);
    wlan_p2p_validate_ap_assist_dfs_group(*(_QWORD *)(a1 + 520));
    return 0;
  }
  return result;
}
