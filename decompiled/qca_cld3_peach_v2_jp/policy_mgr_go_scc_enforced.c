bool __fastcall policy_mgr_go_scc_enforced(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  const char *v13; // x3
  __int64 v14; // x0

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v13 = "policy_mgr_go_scc_enforced";
    goto LABEL_5;
  }
  v11 = context;
  if ( (unsigned int)policy_mgr_get_mcc_to_scc_switch_mode(a1) == 5 )
    return 1;
  if ( *(_BYTE *)(v11 + 2232) )
  {
    v14 = policy_mgr_get_context(a1);
    if ( v14 )
      return (unsigned int)*(unsigned __int8 *)(v14 + 2200) - 3 < 4;
    v13 = "policy_mgr_is_force_scc";
LABEL_5:
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v3, v4, v5, v6, v7, v8, v9, v10, v13);
  }
  return 0;
}
