__int64 __fastcall cm_sm_deliver_event(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 cm_ctx_fl; // x0
  __int64 v17; // x22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w19

  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d Invalid mode %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "cm_sm_deliver_event",
      *(unsigned __int8 *)(a1 + 168));
    return 11;
  }
  else
  {
    cm_ctx_fl = cm_get_cm_ctx_fl(a1, "cm_sm_deliver_event", 1313);
    if ( cm_ctx_fl )
    {
      v17 = cm_ctx_fl;
      qdf_mutex_acquire(cm_ctx_fl + 8);
      v26 = wlan_sm_dispatch(*(_QWORD *)(v17 + 72), a2, a3, a4, v18, v19, v20, v21, v22, v23, v24, v25);
      qdf_mutex_release(v17 + 8);
      return v26;
    }
    else
    {
      return 16;
    }
  }
}
