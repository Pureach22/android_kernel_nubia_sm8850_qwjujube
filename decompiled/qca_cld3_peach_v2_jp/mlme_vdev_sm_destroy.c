__int64 __fastcall mlme_vdev_sm_destroy(
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
  __int64 v10; // x20
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
  __int64 v27; // x8
  __int64 v28; // x2

  v10 = *(_QWORD *)(a1 + 504);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: VDEV CMD lock is disabled!!!",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "mlme_vdev_cmd_mutex_destroy");
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: VDEV SM lock is disabled!!!",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "mlme_vdev_sm_spinlock_destroy");
  v27 = *(_QWORD *)(v10 + 152);
  if ( v27 )
    v28 = *(_QWORD *)(v27 + 80);
  else
    v28 = 0;
  wlan_minidump_remove(v19, v20, v21, v22, v23, v24, v25, v26, *(_QWORD *)(a1 + 488), 112, v28);
  wlan_sm_delete(*(_QWORD *)(a1 + 488));
  return 0;
}
