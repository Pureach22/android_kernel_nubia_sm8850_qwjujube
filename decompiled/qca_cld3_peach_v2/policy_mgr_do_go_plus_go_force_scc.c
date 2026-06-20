__int64 __fastcall policy_mgr_do_go_plus_go_force_scc(__int64 a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  __int64 context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x23
  unsigned int v18; // w24
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  _DWORD *v28; // x8

  context = policy_mgr_get_context(a1);
  if ( !context )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             "policy_mgr_do_go_plus_go_force_scc");
  v17 = context;
  v18 = (unsigned __int8)policy_mgr_mode_specific_connection_count(a1, 3, 0);
  result = qdf_trace_msg(
             0x4Fu,
             8u,
             "%s: Total p2p go connection %d",
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             "policy_mgr_do_go_plus_go_force_scc",
             v18);
  if ( v18 >= 2 )
  {
    v28 = *(_DWORD **)(v17 + 336);
    if ( v28 )
    {
      if ( *(v28 - 1) != -1125204353 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64))v28)(a1, a2, 5);
    }
    return policy_mgr_change_sap_channel_with_csa(a1, a2, a3, a4, 1);
  }
  return result;
}
