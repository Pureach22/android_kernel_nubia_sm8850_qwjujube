__int64 __fastcall sme_set_nud_debug_stats_cb(
        __int64 a1,
        __int64 a2,
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
  unsigned int v14; // w19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  if ( a1 )
  {
    v14 = qdf_mutex_acquire(a1 + 12848);
    if ( v14 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: sme_acquire_global_lock failed!(status=%d)",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "sme_set_nud_debug_stats_cb",
        v14);
    }
    else
    {
      *(_QWORD *)(a1 + 14440) = a2;
      *(_QWORD *)(a1 + 14432) = a3;
      qdf_mutex_release(a1 + 12848);
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: mac_handle is not valid",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_set_nud_debug_stats_cb");
    return 4;
  }
  return v14;
}
