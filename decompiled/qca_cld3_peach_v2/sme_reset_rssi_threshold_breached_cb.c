__int64 __fastcall sme_reset_rssi_threshold_breached_cb(
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
  unsigned int v10; // w19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( a1 )
  {
    v10 = qdf_mutex_acquire(a1 + 12848);
    if ( v10 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: sme_acquire_global_lock failed!(status=%d)",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "sme_set_rssi_threshold_breached_cb",
        v10);
    }
    else
    {
      *(_QWORD *)(a1 + 14344) = 0;
      qdf_mutex_release(a1 + 12848);
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid mac context",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "sme_set_rssi_threshold_breached_cb");
    return 4;
  }
  return v10;
}
