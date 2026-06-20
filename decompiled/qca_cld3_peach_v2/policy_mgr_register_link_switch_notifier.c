__int64 policy_mgr_register_link_switch_notifier()
{
  __int64 result; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  unsigned int v9; // w19

  result = mlo_mgr_register_link_switch_notifier(6, policy_mgr_link_switch_notifier_cb);
  if ( (_DWORD)result )
  {
    if ( (_DWORD)result == 11 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Link switch not supported",
        v1,
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        "policy_mgr_register_link_switch_notifier");
      return 0;
    }
    else
    {
      v9 = result;
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Failed to register link switch notifier for policy mgr!",
        v1,
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        "policy_mgr_register_link_switch_notifier");
      return v9;
    }
  }
  return result;
}
