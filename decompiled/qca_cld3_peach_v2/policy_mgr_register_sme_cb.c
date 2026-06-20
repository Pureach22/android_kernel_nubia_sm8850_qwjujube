__int64 __fastcall policy_mgr_register_sme_cb(__int64 a1, _QWORD *a2)
{
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD *v13; // x20

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v13 = (_QWORD *)context;
    *(_QWORD *)(context + 392) = *a2;
    *(_QWORD *)(context + 416) = a2[3];
    if ( (policy_mgr_is_hwmode_offload_enabled(a1, v5, v6, v7, v8, v9, v10, v11, v12) & 1) == 0 )
      v13[51] = a2[2];
    v13[50] = a2[1];
    v13[53] = a2[4];
    v13[54] = a2[5];
    v13[55] = a2[6];
    v13[56] = a2[7];
    v13[57] = a2[8];
    return 0;
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v5, v6, v7, v8, v9, v10, v11, v12, "policy_mgr_register_sme_cb");
    return 16;
  }
}
