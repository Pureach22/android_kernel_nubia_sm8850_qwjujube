__int64 __fastcall policy_mgr_get_agile_dfs_config(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0
  unsigned __int8 v12[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = 1;
  policy_mgr_get_dual_mac_feature(a1, v12);
  if ( (unsigned int)v12[0] - 1 < 3 )
    goto LABEL_5;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_get_agile_dfs_config");
LABEL_5:
    result = 0;
    goto LABEL_6;
  }
  result = (*(unsigned __int8 *)(comp_private_obj + 1519) >> 6) & 1;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
