__int64 __fastcall policy_mgr_set_opportunistic_update(__int64 a1)
{
  __int64 context; // x0
  __int64 v2; // x1
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0
  const char *v12; // x2

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    result = qdf_event_set(context + 2112, v2);
    if ( !(_DWORD)result )
      return result;
    v12 = "%s: set event failed";
  }
  else
  {
    v12 = "%s: Invalid context";
  }
  qdf_trace_msg(0x4Fu, 2u, v12, v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_set_opportunistic_update");
  return 16;
}
