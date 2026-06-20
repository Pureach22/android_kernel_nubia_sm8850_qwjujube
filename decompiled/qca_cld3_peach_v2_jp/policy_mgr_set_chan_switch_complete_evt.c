__int64 __fastcall policy_mgr_set_chan_switch_complete_evt(__int64 a1)
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
  __int64 (*v11)(void); // x8
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  const char *v22; // x2

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v22 = "%s: Invalid context";
    goto LABEL_10;
  }
  v11 = *(__int64 (**)(void))(context + 320);
  v12 = context;
  if ( v11 )
  {
    if ( *((_DWORD *)v11 - 1) != 799902358 )
      __break(0x8228u);
    if ( (v11() & 1) != 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        4u,
        "%s: Not all channel switch completed",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "policy_mgr_set_chan_switch_complete_evt");
      return 0;
    }
  }
  result = qdf_event_set_all(v12 + 2152, v2);
  if ( (_DWORD)result )
  {
    v22 = "%s: set event failed";
LABEL_10:
    qdf_trace_msg(0x4Fu, 2u, v22, v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_set_chan_switch_complete_evt");
    return 16;
  }
  return result;
}
