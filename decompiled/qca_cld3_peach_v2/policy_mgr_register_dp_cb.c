__int64 __fastcall policy_mgr_register_dp_cb(__int64 a1, _QWORD *a2)
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
  _QWORD *v12; // x8

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v12 = (_QWORD *)context;
    v12[61] = *a2;
    v12[62] = a2[1];
    v12[63] = a2[2];
    v12[64] = a2[3];
    v12[65] = a2[4];
    v12[66] = a2[5];
    return 0;
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_register_dp_cb");
    return 16;
  }
}
