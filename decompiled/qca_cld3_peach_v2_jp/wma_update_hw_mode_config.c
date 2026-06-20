__int64 __fastcall wma_update_hw_mode_config(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  unsigned int v11; // w20
  __int64 v14; // x23
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w10
  __int64 v24; // x8
  _DWORD *v25; // x9
  __int64 v26; // x10
  const char *v27; // x2
  unsigned int v28; // w1
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x21
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  const char *v46; // x2
  unsigned int v47; // w1
  int v49; // w10
  __int64 v50; // x4

  v10 = *(_DWORD *)(a2 + 764);
  v11 = *(_DWORD *)(a2 + 760);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Defaults: scan config:%x FW mode config:%x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_update_hw_mode_config",
    v11,
    v10);
  v14 = *(_QWORD *)(a1 + 24);
  if ( (policy_mgr_find_if_fw_supports_dbs(v14) & 1) == 0 || (policy_mgr_find_if_hwlist_has_dbs(v14) & 1) == 0 )
  {
    v27 = "%s: DBS is not mandatory";
LABEL_7:
    v28 = 8;
LABEL_8:
    qdf_trace_msg(0x36u, v28, v27, v15, v16, v17, v18, v19, v20, v21, v22, "wma_is_dbs_mandatory");
    goto LABEL_9;
  }
  v23 = *(_DWORD *)(a2 + 504);
  v24 = *(unsigned __int8 *)(a2 + 486);
  v25 = (_DWORD *)(a2 + 1072);
  if ( v23 <= 0xA )
  {
    if ( *v25 == v23 )
    {
      v26 = 0;
    }
    else if ( *(_DWORD *)(a2 + 1328) == v23 )
    {
      v26 = 1;
    }
    else if ( *(_DWORD *)(a2 + 1584) == v23 )
    {
      v26 = 2;
    }
    else if ( *(_DWORD *)(a2 + 1840) == v23 )
    {
      v26 = 3;
    }
    else if ( *(_DWORD *)(a2 + 2096) == v23 )
    {
      v26 = 4;
    }
    else if ( *(_DWORD *)(a2 + 2352) == v23 )
    {
      v26 = 5;
    }
    else if ( *(_DWORD *)(a2 + 2608) == v23 )
    {
      v26 = 6;
    }
    else
    {
      if ( *(_DWORD *)(a2 + 2864) != v23 )
      {
LABEL_37:
        v27 = "%s: Invalid MAC PHY capabilities handle";
        v28 = 2;
        goto LABEL_8;
      }
      v26 = 7;
    }
    v25 += 64 * v26;
  }
  if ( !v25 )
    goto LABEL_37;
  if ( *(_BYTE *)(a2 + 486) )
  {
    v49 = 0;
    do
    {
      if ( v25 && !v25[2] )
        v49 |= v25[6];
      --v24;
      v25 += 64;
    }
    while ( v24 );
    if ( (~v49 & 3) == 0 )
    {
      v27 = "%s: Mac0 supports both bands DBS is optional";
      goto LABEL_7;
    }
    v50 = (unsigned __int8)v49;
  }
  else
  {
    v50 = 0;
  }
  qdf_trace_msg(
    0x36u,
    4u,
    "%s: MAC0 does not support both bands %d DBS is mandatory",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "wma_is_dbs_mandatory",
    v50);
  if ( policy_mgr_is_dual_mac_disabled_in_ini(*(_QWORD *)(a1 + 24)) )
  {
    policy_mgr_set_dual_mac_feature(*(_QWORD *)(a1 + 24), 6);
    policy_mgr_set_ch_select_plcy(*(_QWORD *)(a1 + 24), 3);
  }
LABEL_9:
  v37 = *(_QWORD *)(a1 + 24);
  qdf_trace_msg(0x36u, 8u, "%s: Enter", v29, v30, v31, v32, v33, v34, v35, v36, "wma_init_scan_fw_mode_config");
  if ( v37 )
  {
    policy_mgr_init_dbs_config(v37, v11, v10);
    policy_mgr_init_sbs_fw_config(v37, v10);
    v46 = "%s: Exit";
    v47 = 8;
  }
  else
  {
    v46 = "%s: obj psoc is NULL";
    v47 = 2;
  }
  return qdf_trace_msg(0x36u, v47, v46, v38, v39, v40, v41, v42, v43, v44, v45, "wma_init_scan_fw_mode_config");
}
