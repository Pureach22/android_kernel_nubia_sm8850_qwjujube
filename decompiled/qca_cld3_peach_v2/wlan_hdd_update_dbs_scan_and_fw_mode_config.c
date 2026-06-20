__int64 __fastcall wlan_hdd_update_dbs_scan_and_fw_mode_config(
        char a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 *v19; // x19
  const char *v20; // x2
  unsigned int v21; // w1
  __int64 result; // x0
  __int64 v23; // x5
  __int64 v24; // x4
  unsigned int updated_scan_and_fw_mode_config; // w0
  __int64 v26; // x4
  const char *v27; // x2
  _QWORD v28[3]; // [xsp+0h] [xbp-40h] BYREF
  unsigned __int8 v29[4]; // [xsp+18h] [xbp-28h] BYREF
  int v30; // [xsp+1Ch] [xbp-24h] BYREF
  __int64 v31; // [xsp+20h] [xbp-20h] BYREF
  __int64 (__fastcall *v32)(unsigned int, unsigned int, unsigned int, double, double, double, double, double, double, double, double); // [xsp+28h] [xbp-18h]
  __int64 v33; // [xsp+30h] [xbp-10h]
  __int64 v34; // [xsp+38h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v30 = 0;
  context = _cds_get_context(51, (__int64)"wlan_hdd_update_dbs_scan_and_fw_mode_config", a2, a3, a4, a5, a6, a7, a8, a9);
  v29[0] = 1;
  if ( !context )
  {
    v20 = "%s: HDD context is null";
LABEL_7:
    v21 = 2;
    goto LABEL_8;
  }
  v19 = context;
  if ( (policy_mgr_find_if_fw_supports_dbs(*context) & 1) == 0 )
  {
    v20 = "%s: DBS is not supported by HW";
    goto LABEL_7;
  }
  if ( *((_BYTE *)v19 + 6947) != 1 )
  {
    LOBYTE(v33) = a1;
    v31 = 0;
    v32 = policy_mgr_soc_set_dual_mac_cfg_cb;
    if ( (policy_mgr_is_hw_dbs_capable(*v19) & 1) != 0 && (unsigned int)ucfg_policy_mgr_get_chnl_select_plcy(*v19, &v30) )
    {
      v20 = "%s: can't get chnl sel policy, use def";
      goto LABEL_7;
    }
    if ( (unsigned int)ucfg_policy_mgr_get_dual_mac_feature(*v19, v29) )
    {
      v20 = "%s: ucfg_policy_mgr_get_dual_mac_feature failed, use def";
      goto LABEL_7;
    }
    if ( v29[0] == 1 )
    {
      v23 = 0;
      v24 = 0;
    }
    else
    {
      updated_scan_and_fw_mode_config = policy_mgr_get_updated_scan_and_fw_mode_config(
                                          *v19,
                                          (unsigned int *)&v31,
                                          (unsigned int *)&v31 + 1,
                                          v29[0],
                                          v30);
      if ( updated_scan_and_fw_mode_config )
      {
        v26 = updated_scan_and_fw_mode_config;
        v27 = "%s: wma_get_updated_scan_and_fw_mode_config failed %d";
LABEL_22:
        result = qdf_trace_msg(
                   0x33u,
                   2u,
                   v27,
                   v11,
                   v12,
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   "wlan_hdd_update_dbs_scan_and_fw_mode_config",
                   v26);
        goto LABEL_9;
      }
      v24 = (unsigned int)v31;
      v23 = HIDWORD(v31);
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: send scan_cfg: 0x%x fw_mode_cfg: 0x%x to fw",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_hdd_update_dbs_scan_and_fw_mode_config",
      v24,
      v23);
    v28[0] = v31;
    v28[1] = v32;
    v28[2] = v33;
    result = sme_soc_set_dual_mac_config(v28);
    if ( !(_DWORD)result )
    {
      *((_BYTE *)v19 + 6947) = 1;
      goto LABEL_9;
    }
    v26 = (unsigned int)result;
    v27 = "%s: sme_soc_set_dual_mac_config failed %d";
    goto LABEL_22;
  }
  v20 = "%s: dual mac config has already been updated, skip";
  v21 = 8;
LABEL_8:
  result = qdf_trace_msg(
             0x33u,
             v21,
             v20,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             "wlan_hdd_update_dbs_scan_and_fw_mode_config");
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
