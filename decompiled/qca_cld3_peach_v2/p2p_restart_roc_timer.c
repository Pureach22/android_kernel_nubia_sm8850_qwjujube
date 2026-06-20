__int64 __fastcall p2p_restart_roc_timer(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int v10; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19
  const char *v20; // x2
  __int64 result; // x0

  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 56) != 21 )
    return 16;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: roc restart duration:%d",
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    "p2p_restart_roc_timer",
    *(unsigned int *)(a1 + 48));
  v10 = qdf_mc_timer_stop_sync(a1 + 56);
  if ( v10 )
  {
    v19 = v10;
    v20 = "%s: Failed to stop roc timer";
  }
  else
  {
    result = qdf_mc_timer_start(a1 + 56, *(_DWORD *)(a1 + 48));
    if ( !(_DWORD)result )
      return result;
    v19 = result;
    v20 = "%s: Remain on Channel timer start failed";
  }
  qdf_trace_msg(0x4Eu, 2u, v20, v11, v12, v13, v14, v15, v16, v17, v18, "p2p_restart_roc_timer");
  return v19;
}
