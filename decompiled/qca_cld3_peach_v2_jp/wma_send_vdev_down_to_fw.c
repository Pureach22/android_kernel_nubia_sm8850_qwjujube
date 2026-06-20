__int64 __fastcall wma_send_vdev_down_to_fw(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 cmpt_obj; // x0
  const char *v22; // x2

  v11 = *(_QWORD *)(*(_QWORD *)(a1 + 520) + 488LL * a2);
  if ( (wma_is_vdev_valid(a2, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
  {
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v11, v12, v13, v14, v15, v16, v17, v18, v19);
    if ( cmpt_obj )
      return vdev_mgr_down_send(cmpt_obj, v12, v13, v14, v15, v16, v17, v18, v19);
    v22 = "%s: Failed to get vdev mlme obj for vdev id %d";
  }
  else
  {
    v22 = "%s: Invalid vdev id:%d";
  }
  qdf_trace_msg(0x36u, 2u, v22, v12, v13, v14, v15, v16, v17, v18, v19, "wma_send_vdev_down_to_fw", a2);
  return 16;
}
