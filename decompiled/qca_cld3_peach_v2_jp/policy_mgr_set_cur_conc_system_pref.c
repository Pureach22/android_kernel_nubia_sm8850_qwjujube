__int64 __fastcall policy_mgr_set_cur_conc_system_pref(__int64 a1, unsigned __int8 a2)
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
  __int64 v12; // x20
  __int64 result; // x0

  context = policy_mgr_get_context(a1);
  if ( !context )
    return qdf_trace_msg(
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
             "policy_mgr_set_cur_conc_system_pref");
  v12 = context;
  result = qdf_trace_msg(
             0x4Fu,
             8u,
             "%s: conc_system_pref %hu",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "policy_mgr_set_cur_conc_system_pref",
             a2);
  *(_BYTE *)(v12 + 2104) = a2;
  return result;
}
