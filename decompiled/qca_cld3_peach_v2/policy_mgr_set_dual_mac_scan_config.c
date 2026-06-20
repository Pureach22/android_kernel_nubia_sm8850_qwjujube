__int64 __fastcall policy_mgr_set_dual_mac_scan_config(__int64 a1, char a2, char a3, char a4)
{
  __int64 context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x23
  unsigned int updated_scan_config; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x4
  const char *v28; // x2
  __int64 result; // x0
  char dbs_config; // w20
  char agile_dfs_config; // w0
  unsigned int updated_fw_mode_config; // w0
  __int64 (__fastcall *v33)(_QWORD); // x8
  _QWORD v34[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v35; // [xsp+20h] [xbp-20h] BYREF
  __int64 (__fastcall *v36)(unsigned int, unsigned int, unsigned int, double, double, double, double, double, double, double, double); // [xsp+28h] [xbp-18h]
  __int64 v37; // [xsp+30h] [xbp-10h]
  __int64 v38; // [xsp+38h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = nullptr;
  v37 = 0;
  v35 = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v17 = context;
    updated_scan_config = policy_mgr_get_updated_scan_config(a1, (unsigned int *)&v35, a2 != 0, a3 != 0, a4 != 0);
    if ( updated_scan_config )
    {
      v27 = updated_scan_config;
      v28 = "%s: policy_mgr_get_updated_scan_config failed %d";
LABEL_11:
      result = qdf_trace_msg(
                 0x4Fu,
                 2u,
                 v28,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 "policy_mgr_set_dual_mac_scan_config",
                 v27);
      goto LABEL_12;
    }
    dbs_config = policy_mgr_get_dbs_config(a1);
    agile_dfs_config = policy_mgr_get_agile_dfs_config(a1);
    updated_fw_mode_config = policy_mgr_get_updated_fw_mode_config(
                               a1,
                               (unsigned int *)&v35 + 1,
                               dbs_config & 1,
                               agile_dfs_config & 1);
    if ( updated_fw_mode_config )
    {
      v27 = updated_fw_mode_config;
      v28 = "%s: policy_mgr_get_updated_fw_mode_config failed %d";
      goto LABEL_11;
    }
    v36 = policy_mgr_soc_set_dual_mac_cfg_cb;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: scan_config:%x fw_mode_config:%x",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "policy_mgr_set_dual_mac_scan_config",
      (unsigned int)v35,
      HIDWORD(v35));
    v34[0] = v35;
    v34[1] = v36;
    v33 = *(__int64 (__fastcall **)(_QWORD))(v17 + 400);
    v34[2] = v37;
    if ( *((_DWORD *)v33 - 1) != -2033271432 )
      __break(0x8228u);
    result = v33(v34);
    if ( (_DWORD)result )
    {
      v27 = (unsigned int)result;
      v28 = "%s: sme_soc_set_dual_mac_config failed %d";
      goto LABEL_11;
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: Invalid Context",
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               "policy_mgr_set_dual_mac_scan_config");
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
