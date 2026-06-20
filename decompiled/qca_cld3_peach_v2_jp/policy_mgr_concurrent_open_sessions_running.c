bool __fastcall policy_mgr_concurrent_open_sessions_running(__int64 a1)
{
  _BYTE *context; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  context = (_BYTE *)policy_mgr_get_context(a1);
  if ( context )
    return (unsigned __int8)(context[988]
                           + context[987]
                           + context[986]
                           + context[985]
                           + context[984]
                           + context[983]
                           + context[982]
                           + context[981]
                           + context[980]
                           + context[979]
                           + context[978]
                           + context[977]
                           + context[976]
                           + context[975]
                           + context[974]
                           + context[973]
                           + context[972]) > 1u;
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Invalid context",
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    "policy_mgr_concurrent_open_sessions_running");
  return 0;
}
