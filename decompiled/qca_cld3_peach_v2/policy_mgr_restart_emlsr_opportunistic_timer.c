__int64 __fastcall policy_mgr_restart_emlsr_opportunistic_timer(__int64 a1)
{
  __int64 context; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  unsigned int v11; // w19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v10 = context;
    qdf_mc_timer_stop(context + 2712);
    v11 = qdf_mc_timer_start(v10 + 2712, 0x1388u);
    if ( v11 )
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: failed to start emlsr timer, %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "policy_mgr_restart_emlsr_opportunistic_timer",
        v11);
    else
      qdf_trace_msg(0x4Fu, 8u, "emlsr timer restarted", v12, v13, v14, v15, v16, v17, v18, v19);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid context",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "policy_mgr_restart_emlsr_opportunistic_timer");
    return 16;
  }
  return v11;
}
