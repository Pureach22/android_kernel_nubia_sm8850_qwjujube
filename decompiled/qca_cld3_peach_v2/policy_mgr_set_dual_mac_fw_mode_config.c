__int64 __fastcall policy_mgr_set_dual_mac_fw_mode_config(__int64 a1, char a2, char a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x24
  char dbs_scan_config; // w22
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w23
  __int64 result; // x0
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int v37; // w4
  unsigned int updated_scan_config; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x4
  const char *v48; // x2
  unsigned int updated_fw_mode_config; // w0
  __int64 (__fastcall *v50)(_QWORD); // x8
  _QWORD v51[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v52; // [xsp+20h] [xbp-20h] BYREF
  __int64 (__fastcall *v53)(unsigned int, unsigned int, unsigned int, double, double, double, double, double, double, double, double); // [xsp+28h] [xbp-18h]
  __int64 v54; // [xsp+30h] [xbp-10h]
  __int64 v55; // [xsp+38h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v53 = nullptr;
  v54 = 0;
  v52 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: Invalid Context",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "policy_mgr_set_dual_mac_fw_mode_config");
    goto LABEL_22;
  }
  v15 = context;
  dbs_scan_config = policy_mgr_get_dbs_scan_config(a1);
  if ( !policy_mgr_is_dual_mac_disabled_in_ini(a1) )
  {
    v17 = policy_mgr_get_context(a1);
    if ( v17 )
    {
      v26 = (*(unsigned __int8 *)(v17 + 1515) >> 6) & 1;
      goto LABEL_8;
    }
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "policy_mgr_get_dbs_plus_agile_scan_config");
  }
  LOBYTE(v26) = 0;
LABEL_8:
  if ( policy_mgr_is_dual_mac_disabled_in_ini(a1) )
  {
LABEL_12:
    LOBYTE(v37) = 0;
    goto LABEL_13;
  }
  v28 = policy_mgr_get_context(a1);
  if ( !v28 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "policy_mgr_get_single_mac_scan_with_dfs_config");
    goto LABEL_12;
  }
  v37 = (*(unsigned __int8 *)(v28 + 1515) >> 5) & 1;
LABEL_13:
  updated_scan_config = policy_mgr_get_updated_scan_config(a1, (unsigned int *)&v52, dbs_scan_config & 1, v26, v37);
  if ( updated_scan_config )
  {
    v47 = updated_scan_config;
    v48 = "%s: policy_mgr_get_updated_scan_config failed %d";
LABEL_21:
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               v48,
               v39,
               v40,
               v41,
               v42,
               v43,
               v44,
               v45,
               v46,
               "policy_mgr_set_dual_mac_fw_mode_config",
               v47);
    goto LABEL_22;
  }
  updated_fw_mode_config = policy_mgr_get_updated_fw_mode_config(a1, (unsigned int *)&v52 + 1, a2 != 0, a3 != 0);
  if ( updated_fw_mode_config )
  {
    v47 = updated_fw_mode_config;
    v48 = "%s: policy_mgr_get_updated_fw_mode_config failed %d";
    goto LABEL_21;
  }
  v53 = policy_mgr_soc_set_dual_mac_cfg_cb;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: scan_config:%x fw_mode_config:%x",
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    "policy_mgr_set_dual_mac_fw_mode_config",
    (unsigned int)v52,
    HIDWORD(v52));
  v51[0] = v52;
  v51[1] = v53;
  v50 = *(__int64 (__fastcall **)(_QWORD))(v15 + 400);
  v51[2] = v54;
  if ( *((_DWORD *)v50 - 1) != -2033271432 )
    __break(0x8228u);
  result = v50(v51);
  if ( (_DWORD)result )
  {
    v47 = (unsigned int)result;
    v48 = "%s: sme_soc_set_dual_mac_config failed %d";
    goto LABEL_21;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
