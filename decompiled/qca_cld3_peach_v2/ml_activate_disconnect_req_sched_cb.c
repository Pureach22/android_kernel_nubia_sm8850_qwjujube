__int64 __fastcall ml_activate_disconnect_req_sched_cb(
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
  __int64 v9; // x19
  double v10; // d0
  unsigned int *v11; // x8
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  v9 = *(_QWORD *)(a1 + 8);
  if ( v9 )
  {
    v10 = ((double (__fastcall *)(_QWORD, __int64, __int64))mlo_disconnect_req)(*(_QWORD *)(a1 + 8), 5, 1);
    wlan_objmgr_vdev_release_ref(v9, 0x5Au, v11, v10, v12, v13, v14, v15, v16, v17, v18);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Null input vdev",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "ml_activate_disconnect_req_sched_cb");
    return 4;
  }
}
