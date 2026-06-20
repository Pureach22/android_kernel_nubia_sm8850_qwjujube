__int64 __fastcall policy_mgr_register_hdd_cb(__int64 a1, _QWORD *a2)
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
    v12[36] = *a2;
    v12[37] = a2[1];
    v12[38] = a2[2];
    v12[39] = a2[3];
    v12[40] = a2[4];
    v12[41] = a2[5];
    v12[43] = a2[7];
    v12[44] = a2[8];
    v12[45] = a2[9];
    v12[46] = a2[10];
    v12[47] = a2[11];
    v12[48] = a2[12];
    v12[42] = a2[6];
    return 0;
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_register_hdd_cb");
    return 16;
  }
}
