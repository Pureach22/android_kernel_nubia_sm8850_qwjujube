__int64 __fastcall policy_mgr_is_hw_sbs_capable(__int64 a1)
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x8
  char *v39; // x9
  char v40; // t1
  __int64 v41; // x20
  const char *v43; // x2
  unsigned int v44; // w1
  __int64 v45; // x20
  __int64 v46; // x20

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_is_sbs_enable");
LABEL_15:
    v41 = jiffies;
    if ( policy_mgr_is_hw_sbs_capable___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: SBS INI is disabled",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "policy_mgr_is_hw_sbs_capable");
      policy_mgr_is_hw_sbs_capable___last_ticks = v41;
      return 0;
    }
    return 0;
  }
  if ( (*(_BYTE *)(context + 1519) & 4) == 0 )
    goto LABEL_15;
  if ( !policy_mgr_get_context(a1) )
  {
    v43 = "%s: Invalid Context";
    v44 = 2;
    goto LABEL_19;
  }
  if ( !a1 || (v19 = *(_QWORD *)(a1 + 2800)) == 0 || (v20 = *(_QWORD *)(v19 + 16)) == 0 )
  {
    v43 = "%s: Invalid WMI handle";
    v44 = 8;
LABEL_19:
    qdf_trace_msg(0x4Fu, v44, v43, v11, v12, v13, v14, v15, v16, v17, v18, "policy_mgr_find_if_fw_supports_dbs");
LABEL_20:
    v45 = jiffies;
    if ( policy_mgr_is_hw_sbs_capable___last_ticks_47 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: fw doesn't support dual band",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "policy_mgr_is_hw_sbs_capable");
      policy_mgr_is_hw_sbs_capable___last_ticks_47 = v45;
      return 0;
    }
    return 0;
  }
  if ( (wmi_service_enabled(v20, 0x55u, v11, v12, v13, v14, v15, v16, v17, v18) & 1) == 0 )
    goto LABEL_20;
  v29 = policy_mgr_get_context(a1);
  if ( !v29 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "policy_mgr_find_if_hwlist_has_sbs");
LABEL_24:
    v46 = jiffies;
    if ( policy_mgr_is_hw_sbs_capable___last_ticks_49 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: HW mode list has no SBS",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "policy_mgr_is_hw_sbs_capable");
      policy_mgr_is_hw_sbs_capable___last_ticks_49 = v46;
      return 0;
    }
    return 0;
  }
  v38 = *(unsigned int *)(v29 + 1184);
  if ( !(_DWORD)v38 )
    goto LABEL_24;
  v39 = *(char **)(v29 + 1192);
  while ( 1 )
  {
    v40 = *v39;
    v39 += 8;
    if ( (v40 & 0x20) != 0 )
      return 1;
    if ( !--v38 )
      goto LABEL_24;
  }
}
