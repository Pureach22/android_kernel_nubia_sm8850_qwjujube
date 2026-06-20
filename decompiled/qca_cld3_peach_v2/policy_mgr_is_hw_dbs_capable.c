__int64 __fastcall policy_mgr_is_hw_dbs_capable(__int64 a1)
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
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  char *v33; // x9
  char v34; // t1
  const char *v35; // x2
  const char *v36; // x3
  unsigned int v37; // w1

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
    return 0;
  }
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v35 = "%s: Invalid Context";
    v36 = "policy_mgr_is_dbs_enable";
LABEL_18:
    v37 = 2;
LABEL_19:
    qdf_trace_msg(0x4Fu, v37, v35, v13, v14, v15, v16, v17, v18, v19, v20, v36);
    return 0;
  }
  if ( (*(_DWORD *)(context + 1516) & 0x80000000) == 0 )
    return 0;
  if ( !policy_mgr_get_context(a1) )
  {
    v35 = "%s: Invalid Context";
    v36 = "policy_mgr_find_if_fw_supports_dbs";
    goto LABEL_18;
  }
  if ( !a1 || (v21 = *(_QWORD *)(a1 + 2800)) == 0 || (v22 = *(_QWORD *)(v21 + 16)) == 0 )
  {
    v35 = "%s: Invalid WMI handle";
    v36 = "policy_mgr_find_if_fw_supports_dbs";
    v37 = 8;
    goto LABEL_19;
  }
  if ( (wmi_service_enabled(v22, 0x55u, v13, v14, v15, v16, v17, v18, v19, v20) & 1) == 0 )
    return 0;
  v23 = policy_mgr_get_context(a1);
  if ( !v23 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "policy_mgr_find_if_hwlist_has_dbs");
    goto LABEL_24;
  }
  v32 = *(unsigned int *)(v23 + 1184);
  if ( !(_DWORD)v32 )
  {
LABEL_24:
    qdf_trace_msg(0x4Fu, 8u, "HW mode list has no DBS", v24, v25, v26, v27, v28, v29, v30, v31);
    return 0;
  }
  v33 = *(char **)(v23 + 1192);
  while ( 1 )
  {
    v34 = *v33;
    v33 += 8;
    if ( v34 < 0 )
      return 1;
    if ( !--v32 )
      goto LABEL_24;
  }
}
