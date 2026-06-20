__int64 __fastcall wlan_vdev_mlme_ser_vdev_restart(
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
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v27; // x2

  if ( !a1 || (v10 = *(_QWORD *)(a1 + 32)) == 0 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: Null input", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_mlme_ser_vdev_restart");
    return 6;
  }
  if ( (wlan_ser_is_vdev_queue_enabled(v10) & 1) == 0 )
    return 4;
  *(_DWORD *)a1 = 21;
  if ( (wlan_serialization_is_cmd_present_in_pending_queue(
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          0,
          (unsigned int *)a1)
      & 1) != 0 )
  {
    v27 = "%s: Start cmd already in the pending queue";
  }
  else
  {
    *(_DWORD *)a1 = 26;
    if ( (wlan_serialization_is_cmd_present_in_pending_queue(
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            0,
            (unsigned int *)a1)
        & 1) != 0 )
    {
      v27 = "%s: Pdev restart already in the pending queue";
    }
    else
    {
      *(_DWORD *)a1 = 25;
      if ( (wlan_serialization_is_cmd_present_in_pending_queue(
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              0,
              (unsigned int *)a1)
          & 1) == 0 )
        return wlan_serialization_request((unsigned int *)a1, v19, v20, v21, v22, v23, v24, v25, v26);
      v27 = "%s: Vdev restart already in the pending queue";
    }
  }
  qdf_trace_msg(0x68u, 8u, v27, v19, v20, v21, v22, v23, v24, v25, v26, "wlan_vdev_mlme_ser_vdev_restart");
  return 5;
}
