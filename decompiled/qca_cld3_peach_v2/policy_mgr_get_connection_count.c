__int64 __fastcall policy_mgr_get_connection_count(__int64 a1)
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
  __int64 v10; // x20
  unsigned int v11; // w19

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v10 = context;
    qdf_mutex_acquire(context + 56);
    v11 = BYTE4(qword_8D4F00) + BYTE4(qword_8D4F24) + BYTE4(qword_8D4F48) + BYTE4(qword_8D4F6C) + BYTE4(qword_8D4F90);
    qdf_mutex_release(v10 + 56);
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v2, v3, v4, v5, v6, v7, v8, v9, "policy_mgr_get_connection_count");
    return 0;
  }
  return v11;
}
