__int64 __fastcall policy_mgr_dump_sbs_concurrency(__int64 a1, const char *a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  size_t v13; // x0
  bool v14; // cf
  __int64 v15; // x8
  size_t v16; // x2
  char *v17; // x0
  __int64 v18; // x21
  __int64 v20; // x0

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "policy_mgr_dump_sbs_concurrency");
  v12 = comp_private_obj;
  v13 = strnlen(a2, 0x12Cu);
  if ( v13 == -1 )
  {
    v20 = _fortify_panic(2, -1, 0);
    return policy_mgr_set_pcl_for_existing_combo(v20);
  }
  else
  {
    if ( v13 <= 0x12B )
    {
      v14 = v13 >= 0x128;
      v15 = v13 + 4;
      if ( v13 >= 0x128 )
        v16 = 299 - v13;
      else
        v16 = 4;
      v17 = (char *)&a2[v13];
      if ( v14 )
        v18 = 299;
      else
        v18 = v15;
      memcpy(v17, " SBS", v16);
      a2[v18] = 0;
    }
    return policy_mgr_dump_dual_mac_concurrency(v12, a2);
  }
}
