__int64 __fastcall policy_mgr_decr_session_set_pcl(__int64 a1, unsigned int a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  int v23; // w0

  if ( !policy_mgr_get_context(a1) )
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
             "policy_mgr_decr_session_set_pcl");
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))policy_mgr_decr_active_session)(a1, a2, a3) )
    return qdf_trace_msg(
             0x4Fu,
             8u,
             "%s: Invalid active session",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "policy_mgr_decr_session_set_pcl");
  v23 = policy_mgr_mode_specific_connection_count(a1, 0, nullptr);
  if ( a2 && v23 )
    polic_mgr_send_pcl_to_fw(a1, a2);
  result = policy_mgr_is_hw_dbs_capable(a1);
  if ( (result & 1) != 0 )
    return policy_mgr_check_n_start_opportunistic_timer(a1);
  return result;
}
