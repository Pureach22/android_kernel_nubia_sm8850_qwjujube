__int64 __fastcall policy_mgr_complete_action(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w8
  int v21; // w3
  __int64 result; // x0
  __int64 v23; // x20

  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
  {
    if ( (unsigned __int8)a3 == 12 )
      v20 = 1;
    else
      v20 = 2;
    if ( (unsigned __int8)a3 == 10 )
      v21 = 0;
    else
      v21 = v20;
    result = policy_mgr_nss_update(a1, a2, a3, v21, a4, a5, a6);
    if ( (_DWORD)result )
      return policy_mgr_next_actions(a1, a5, (unsigned __int8)a3, a4, a6);
  }
  else
  {
    v23 = jiffies;
    if ( policy_mgr_complete_action___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: driver isn't dbs capable, no further action needed",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "policy_mgr_complete_action");
      policy_mgr_complete_action___last_ticks = v23;
    }
    return 11;
  }
  return result;
}
