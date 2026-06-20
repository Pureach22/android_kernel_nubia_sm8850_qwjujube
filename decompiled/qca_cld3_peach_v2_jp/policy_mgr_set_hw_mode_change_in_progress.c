__int64 __fastcall policy_mgr_set_hw_mode_change_in_progress(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  context = policy_mgr_get_context(a1);
  if ( !context )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "policy_mgr_set_hw_mode_change_in_progress");
  v12 = context;
  qdf_mutex_acquire(context + 56);
  *(_DWORD *)(v12 + 1668) = a2;
  qdf_mutex_release(v12 + 56);
  return qdf_trace_msg(
           0x4Fu,
           8u,
           "%s: hw_mode_change_in_progress:%d",
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           "policy_mgr_set_hw_mode_change_in_progress",
           a2);
}
