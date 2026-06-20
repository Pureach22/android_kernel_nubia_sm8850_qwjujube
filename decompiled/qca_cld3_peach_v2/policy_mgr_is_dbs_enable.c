__int64 __fastcall policy_mgr_is_dbs_enable(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x20
  __int64 context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( policy_mgr_is_dual_mac_disabled_in_ini(a1) )
  {
    v10 = jiffies;
    if ( policy_mgr_is_dbs_enable___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: DBS is disabled from ini",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "policy_mgr_is_dbs_enable");
      policy_mgr_is_dbs_enable___last_ticks = v10;
      return 0;
    }
  }
  else
  {
    context = policy_mgr_get_context(a1);
    if ( context )
      return *(_DWORD *)(context + 1516) >> 31;
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v13, v14, v15, v16, v17, v18, v19, v20, "policy_mgr_is_dbs_enable");
  }
  return 0;
}
