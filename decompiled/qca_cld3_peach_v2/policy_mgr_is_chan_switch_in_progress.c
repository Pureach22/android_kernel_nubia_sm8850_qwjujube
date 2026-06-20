__int64 __fastcall policy_mgr_is_chan_switch_in_progress(__int64 a1)
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
  __int64 (*v10)(void); // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v10 = *(__int64 (**)(void))(context + 320);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != 799902358 )
        __break(0x8228u);
      if ( (v10() & 1) != 0 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: channel switch is in progress",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "policy_mgr_is_chan_switch_in_progress");
        return 1;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid pm context",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "policy_mgr_is_chan_switch_in_progress");
  }
  return 0;
}
