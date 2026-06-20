__int64 __fastcall policy_mgr_reset_hw_mode_change(
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
  __int64 context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 result; // x0
  const char *v38; // x2

  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Clear hw mode change and connection update evt",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "policy_mgr_reset_hw_mode_change");
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v19 = context;
    qdf_mutex_acquire(context + 56);
    *(_DWORD *)(v19 + 1668) = 0;
    qdf_mutex_release(v19 + 56);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: hw_mode_change_in_progress:%d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "policy_mgr_set_hw_mode_change_in_progress",
      0);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "policy_mgr_set_hw_mode_change_in_progress");
  }
  v28 = policy_mgr_get_context(a1);
  if ( v28 )
  {
    result = qdf_event_reset(v28 + 16);
    if ( !(_DWORD)result )
      return result;
    v38 = "%s: clear event failed";
  }
  else
  {
    v38 = "%s: Invalid context";
  }
  return qdf_trace_msg(0x4Fu, 2u, v38, v29, v30, v31, v32, v33, v34, v35, v36, "policy_mgr_reset_connection_update");
}
