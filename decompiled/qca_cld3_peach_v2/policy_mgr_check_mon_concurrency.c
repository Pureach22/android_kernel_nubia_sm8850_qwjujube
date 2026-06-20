__int64 __fastcall policy_mgr_check_mon_concurrency(__int64 a1)
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
  const char *v12; // x2
  const char *v13; // x3
  char v14; // w20

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    if ( *(_BYTE *)(context + 978) )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: monitor mode already exists, only one is possible",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "policy_mgr_check_mon_concurrency");
      return 8;
    }
    v14 = policy_mgr_mode_specific_connection_count(a1, 1, nullptr);
    if ( (unsigned __int8)policy_mgr_mode_specific_connection_count(a1, 6, nullptr) + v14 )
    {
      v12 = "%s: cannot add monitor mode, due to SAP concurrency";
    }
    else if ( (unsigned __int8)policy_mgr_mode_specific_connection_count(a1, 2, nullptr) )
    {
      v12 = "%s: cannot add monitor mode, due to P2P CLIENT concurrency";
    }
    else if ( (unsigned __int8)policy_mgr_mode_specific_connection_count(a1, 3, nullptr) )
    {
      v12 = "%s: cannot add monitor mode, due to P2P GO concurrency";
    }
    else
    {
      if ( !(unsigned __int8)policy_mgr_mode_specific_connection_count(a1, 5, nullptr) )
        return 0;
      v12 = "%s: cannot add monitor mode, due to NAN concurrency";
    }
    v13 = "policy_mgr_check_mon_concurrency";
  }
  else
  {
    v12 = "%s: Invalid context";
    v13 = "policy_mgr_mode_specific_num_open_sessions";
  }
  qdf_trace_msg(0x4Fu, 2u, v12, v3, v4, v5, v6, v7, v8, v9, v10, v13);
  return 4;
}
