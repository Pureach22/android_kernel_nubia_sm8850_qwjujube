__int64 __fastcall policy_mgr_update_dbs_req_config(__int64 a1, int a2, int a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  result = policy_mgr_get_context(a1);
  if ( !result )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "policy_mgr_update_dbs_req_config");
  *(_DWORD *)(result + 1520) = a2;
  *(_DWORD *)(result + 1524) = a3;
  return result;
}
