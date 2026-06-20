__int64 __fastcall policy_mgr_process_force_scc_for_nan(__int64 a1)
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
  __int64 v10; // x8
  __int64 result; // x0
  const char *v12; // x2
  unsigned int v13; // w1

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v12 = "%s: Invalid Context";
LABEL_7:
    v13 = 2;
    return qdf_trace_msg(0x4Fu, v13, v12, v2, v3, v4, v5, v6, v7, v8, v9, "policy_mgr_process_force_scc_for_nan");
  }
  v10 = *(_QWORD *)(context + 2096);
  if ( !v10 )
  {
    v12 = "%s: invalid work info";
    goto LABEL_7;
  }
  *(_BYTE *)(v10 + 52) = 1;
  result = _qdf_delayed_work_start(context + 1008, 0);
  if ( (result & 1) != 0 )
    return result;
  v12 = "%s: change interface request already queued";
  v13 = 8;
  return qdf_trace_msg(0x4Fu, v13, v12, v2, v3, v4, v5, v6, v7, v8, v9, "policy_mgr_process_force_scc_for_nan");
}
