__int64 __fastcall policy_mgr_process_forcescc_for_go(__int64 a1, char a2, int a3, int a4, int a5)
{
  __int64 context; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x8
  __int64 result; // x0
  const char *v20; // x2
  unsigned int v21; // w1

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v20 = "%s: Invalid Context";
LABEL_9:
    v21 = 2;
    return qdf_trace_msg(0x4Fu, v21, v20, v10, v11, v12, v13, v14, v15, v16, v17, "policy_mgr_process_forcescc_for_go");
  }
  v18 = *(_QWORD *)(context + 2096);
  if ( !v18 )
  {
    v20 = "%s: invalid work info";
    goto LABEL_9;
  }
  if ( a5 == 3 )
  {
    *(_BYTE *)(v18 + 32) = a2;
    *(_DWORD *)(v18 + 36) = a3;
    *(_DWORD *)(v18 + 40) = a4;
  }
  result = _qdf_delayed_work_start(context + 1008, 0x3E8u);
  if ( (result & 1) == 0 )
  {
    v20 = "%s: change interface request already queued";
    v21 = 8;
    return qdf_trace_msg(0x4Fu, v21, v20, v10, v11, v12, v13, v14, v15, v16, v17, "policy_mgr_process_forcescc_for_go");
  }
  return result;
}
