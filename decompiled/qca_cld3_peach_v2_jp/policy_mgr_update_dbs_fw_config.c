_DWORD *__fastcall policy_mgr_update_dbs_fw_config(__int64 a1)
{
  _DWORD *result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  int v10; // w9

  result = (_DWORD *)policy_mgr_get_context(a1);
  if ( !result )
    return (_DWORD *)qdf_trace_msg(
                       0x4Fu,
                       2u,
                       "%s: Invalid Context",
                       v2,
                       v3,
                       v4,
                       v5,
                       v6,
                       v7,
                       v8,
                       v9,
                       "policy_mgr_update_dbs_fw_config");
  v10 = result[381];
  result[377] = result[379];
  result[379] = v10;
  return result;
}
