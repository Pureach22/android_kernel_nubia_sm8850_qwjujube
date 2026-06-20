__int64 __fastcall policy_mgr_restart_opportunistic_timer(__int64 a1, char a2)
{
  __int64 result; // x0
  __int64 context; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  unsigned int v15; // w19
  const char *v16; // x2

  if ( (policy_mgr_is_hwmode_offload_enabled(a1) & 1) != 0 )
    return 11;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v15 = 16;
    v16 = "%s: Invalid context";
    goto LABEL_9;
  }
  if ( (a2 & 1) != 0 && *(_DWORD *)(context + 268) != 21 )
    return 16;
  v14 = context;
  qdf_mc_timer_stop(context + 120);
  result = qdf_mc_timer_start(v14 + 120, 0x1388u);
  if ( (_DWORD)result )
  {
    v15 = result;
    v16 = "%s: failed to start opportunistic timer";
LABEL_9:
    qdf_trace_msg(0x4Fu, 2u, v16, v6, v7, v8, v9, v10, v11, v12, v13, "policy_mgr_restart_opportunistic_timer");
    return v15;
  }
  return result;
}
