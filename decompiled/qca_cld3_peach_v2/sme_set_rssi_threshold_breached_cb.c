__int64 __fastcall sme_set_rssi_threshold_breached_cb(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( a1 )
  {
    v12 = qdf_mutex_acquire(a1 + 12848);
    if ( v12 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: sme_acquire_global_lock failed!(status=%d)",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "sme_set_rssi_threshold_breached_cb",
        v12);
    }
    else
    {
      *(_QWORD *)(a1 + 14344) = a2;
      qdf_mutex_release(a1 + 12848);
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid mac context",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_set_rssi_threshold_breached_cb");
    return 4;
  }
  return v12;
}
