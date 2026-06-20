__int64 __fastcall sme_set_link_layer_stats_ind_cb(__int64 a1, __int64 a2)
{
  unsigned int v4; // w19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  v4 = qdf_mutex_acquire(a1 + 12848);
  if ( v4 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: sme_acquire_global_lock error",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "sme_set_link_layer_stats_ind_cb");
  }
  else
  {
    *(_QWORD *)(a1 + 13024) = a2;
    qdf_mutex_release(a1 + 12848);
  }
  return v4;
}
