__int64 __fastcall tgt_vdev_mgr_get_response_timer_info(
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
  unsigned int v10; // w19
  __int64 priv; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v23; // x5

  v10 = a2;
  if ( a2 < 6u )
  {
    priv = mlme_psoc_get_priv(a1);
    if ( priv )
      return priv + 112LL * a2 + 16;
    if ( a1 )
      v23 = *(unsigned __int8 *)(a1 + 48);
    else
      v23 = 255;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d PSOC_%d PSOC_MLME is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "tgt_vdev_mgr_get_response_timer_info",
      v10,
      v23);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Incorrect vdev_id: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tgt_vdev_mgr_get_response_timer_info",
      a2);
  }
  return 0;
}
