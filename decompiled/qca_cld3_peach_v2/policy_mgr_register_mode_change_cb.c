__int64 __fastcall policy_mgr_register_mode_change_cb(__int64 a1, __int64 a2)
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
  __int64 v12; // x8

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v12 = context;
    *(_QWORD *)(v12 + 2192) = a2;
    return 0;
  }
  else
  {
    qdf_trace_msg(
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
      "policy_mgr_register_mode_change_cb");
    return 16;
  }
}
