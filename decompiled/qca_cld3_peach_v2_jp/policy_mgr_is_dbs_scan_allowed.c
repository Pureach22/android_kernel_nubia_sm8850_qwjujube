bool __fastcall policy_mgr_is_dbs_scan_allowed(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 context; // x0
  __int64 v13; // x8
  char *v14; // x9
  _BOOL8 result; // x0
  char v16; // t1
  const char *v17; // x2
  const char *v18; // x3
  unsigned int v19; // w1
  __int64 v20; // x0

  if ( !policy_mgr_get_context(a1) )
  {
    v17 = "%s: Invalid Context";
    v18 = "policy_mgr_is_dbs_scan_allowed";
LABEL_16:
    v19 = 2;
    goto LABEL_17;
  }
  if ( !policy_mgr_get_context(a1) )
  {
    v17 = "%s: Invalid Context";
    v18 = "policy_mgr_find_if_fw_supports_dbs";
    goto LABEL_16;
  }
  if ( !a1 || (v10 = *(_QWORD *)(a1 + 2800)) == 0 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
  {
    v17 = "%s: Invalid WMI handle";
    v18 = "policy_mgr_find_if_fw_supports_dbs";
    v19 = 8;
LABEL_17:
    qdf_trace_msg(0x4Fu, v19, v17, v2, v3, v4, v5, v6, v7, v8, v9, v18);
    return 0;
  }
  if ( (wmi_service_enabled(v11, 0x55u, v2, v3, v4, v5, v6, v7, v8, v9) & 1) == 0 )
    return 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v17 = "%s: Invalid Context";
    v18 = "policy_mgr_find_if_hwlist_has_dbs";
    goto LABEL_16;
  }
  v13 = *(unsigned int *)(context + 1184);
  if ( !(_DWORD)v13 )
    return 0;
  v14 = *(char **)(context + 1192);
  result = 0;
  while ( 1 )
  {
    v16 = *v14;
    v14 += 8;
    if ( v16 < 0 )
      break;
    if ( !--v13 )
      return result;
  }
  v20 = policy_mgr_get_context(a1);
  if ( !v20 )
  {
    v17 = "%s: pm_ctx is NULL";
    v18 = "policy_mgr_get_dual_mac_feature";
    goto LABEL_16;
  }
  return ((*(_BYTE *)(v20 + 2207) - 1) & 0xFB) != 0;
}
