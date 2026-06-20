__int64 __fastcall policy_mgr_get_current_pref_hw_mode_dual_dbs(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int current_pref_hw_mode_dbs_1x1; // w19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int preferred_dbs_action_table; // w0
  const char *v20; // x2

  if ( !wlan_objmgr_psoc_get_comp_private_obj(a1, 6u) )
  {
    v20 = "%s: Invalid Context";
    goto LABEL_10;
  }
  current_pref_hw_mode_dbs_1x1 = policy_mgr_get_current_pref_hw_mode_dbs_1x1(a1);
  qdf_trace_msg(
    0x4Fu,
    4u,
    "%s: next_action %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "policy_mgr_get_current_pref_hw_mode_dual_dbs",
    current_pref_hw_mode_dbs_1x1);
  if ( current_pref_hw_mode_dbs_1x1 == 2 )
  {
    preferred_dbs_action_table = policy_mgr_get_preferred_dbs_action_table(a1, 0xFFu, 0, 0);
    if ( preferred_dbs_action_table == 10 )
    {
      current_pref_hw_mode_dbs_1x1 = 11;
      goto LABEL_8;
    }
    if ( preferred_dbs_action_table == 12 )
    {
      current_pref_hw_mode_dbs_1x1 = 13;
LABEL_8:
      qdf_trace_msg(
        0x4Fu,
        4u,
        "%s: preferred_dbs %d",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "policy_mgr_get_current_pref_hw_mode_dual_dbs",
        current_pref_hw_mode_dbs_1x1);
      return current_pref_hw_mode_dbs_1x1;
    }
    v20 = "%s: DBS1 and DBS2 hw mode not supported";
LABEL_10:
    qdf_trace_msg(0x4Fu, 2u, v20, v2, v3, v4, v5, v6, v7, v8, v9, "policy_mgr_get_current_pref_hw_mode_dual_dbs");
    return 0;
  }
  return current_pref_hw_mode_dbs_1x1;
}
