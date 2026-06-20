__int64 __fastcall policy_mgr_is_sap_go_interface_allowed_on_indoor(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v3; // x19
  char is_sta_sap_scc; // w21
  int opmode_from_vdev_id; // w22
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  __int64 v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  __int64 v29; // x20
  _BYTE v30[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 80);
  v30[0] = 0;
  if ( !v3 || (wlan_reg_is_freq_indoor() & 1) == 0 )
    goto LABEL_14;
  is_sta_sap_scc = policy_mgr_is_sta_sap_scc(v3, a3, 1);
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(a1, a2);
  ucfg_mlme_get_indoor_channel_support(v3, v30);
  result = 1;
  if ( (v30[0] & 1) == 0 )
  {
    if ( wlan_reg_is_6ghz_chan_freq(a3) )
    {
      v18 = jiffies;
      if ( policy_mgr_is_sap_go_interface_allowed_on_indoor___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: SAP operation is not allowed on 6 GHz indoor channel",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "policy_mgr_is_sap_go_interface_allowed_on_indoor");
        result = 0;
        policy_mgr_is_sap_go_interface_allowed_on_indoor___last_ticks = v18;
        goto LABEL_15;
      }
LABEL_21:
      result = 0;
      goto LABEL_15;
    }
    if ( opmode_from_vdev_id == 3 )
    {
      if ( (ucfg_p2p_get_indoor_ch_support(v3) & 1) == 0
        && ((is_sta_sap_scc & 1) == 0 || (policy_mgr_get_sta_sap_scc_allowed_on_indoor_chnl(v3) & 1) == 0) )
      {
        v29 = jiffies;
        if ( policy_mgr_is_sap_go_interface_allowed_on_indoor___last_ticks_155 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: GO operation is not allowed on indoor channel",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "policy_mgr_is_sap_go_interface_allowed_on_indoor");
          result = 0;
          policy_mgr_is_sap_go_interface_allowed_on_indoor___last_ticks_155 = v29;
          goto LABEL_15;
        }
        goto LABEL_21;
      }
    }
    else
    {
      if ( opmode_from_vdev_id != 1 )
      {
        v28 = jiffies;
        if ( policy_mgr_is_sap_go_interface_allowed_on_indoor___last_ticks_157 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: SAP operation is not allowed on indoor channel",
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            "policy_mgr_is_sap_go_interface_allowed_on_indoor");
          result = 0;
          policy_mgr_is_sap_go_interface_allowed_on_indoor___last_ticks_157 = v28;
          goto LABEL_15;
        }
        goto LABEL_21;
      }
      if ( (is_sta_sap_scc & 1) == 0 || (policy_mgr_get_sta_sap_scc_allowed_on_indoor_chnl(v3) & 1) == 0 )
      {
        v19 = jiffies;
        if ( policy_mgr_is_sap_go_interface_allowed_on_indoor___last_ticks_153 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: SAP operation is not allowed on indoor channel",
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            "policy_mgr_is_sap_go_interface_allowed_on_indoor");
          result = 0;
          policy_mgr_is_sap_go_interface_allowed_on_indoor___last_ticks_153 = v19;
          goto LABEL_15;
        }
        goto LABEL_21;
      }
    }
LABEL_14:
    result = 1;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
