__int64 __fastcall policy_mgr_deregister_hdd_cb(__int64 a1)
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
  _QWORD *v10; // x8

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v10 = (_QWORD *)context;
    v10[43] = 0;
    v10[48] = 0;
    v10[36] = 0;
    v10[37] = 0;
    v10[38] = 0;
    v10[39] = 0;
    v10[40] = 0;
    v10[41] = 0;
    v10[45] = 0;
    v10[46] = 0;
    return 0;
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v2, v3, v4, v5, v6, v7, v8, v9, "policy_mgr_deregister_hdd_cb");
    return 16;
  }
}
