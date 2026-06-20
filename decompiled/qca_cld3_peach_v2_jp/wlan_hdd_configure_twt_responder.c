__int64 __fastcall wlan_hdd_configure_twt_responder(__int64 *a1, char a2, unsigned int a3)
{
  __int64 v6; // x0
  unsigned int opmode_from_vdev_id; // w21
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int8 is_twt_enabled; // w23
  const char *v25; // x2
  char is_hw_dbs_capable; // w0
  __int64 result; // x0
  _BYTE v28[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v29[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v30[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a1[1];
  v30[0] = 0;
  v29[0] = 0;
  v28[0] = 0;
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(v6, a3);
  if ( opmode_from_vdev_id == 3 && !wlan_vdev_p2p_is_wfd_r2_mode(*a1, a3, v8, v9, v10, v11, v12, v13, v14, v15) )
  {
    v25 = "%s:  P2P GO is in R1 mode";
    goto LABEL_21;
  }
  is_twt_enabled = ucfg_twt_cfg_is_twt_enabled(*a1);
  ucfg_twt_get_responder(*a1, v30);
  ucfg_twt_tgt_caps_get_resp_disable_per_vdev(*a1, v28);
  if ( (v28[0] & 1) == 0 )
  {
    is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(*a1);
    if ( opmode_from_vdev_id == 1
      && (is_hw_dbs_capable & 1) == 0
      && !policy_mgr_is_vdev_ll_lt_sap(*a1, (unsigned __int8)a3) )
    {
      ucfg_twt_cfg_set_responder(*a1, 0);
    }
  }
  ucfg_twt_cfg_get_responder(*a1, v29);
  if ( !v29[0] && (a2 & 1) == 0 )
  {
    v25 = "%s: TWT responder already disable, skip";
LABEL_21:
    result = qdf_trace_msg(0x33u, 8u, v25, v16, v17, v18, v19, v20, v21, v22, v23, "wlan_hdd_configure_twt_responder");
    goto LABEL_22;
  }
  if ( (v30[0] & is_twt_enabled & 1) == 0 || (a2 & 1) == 0 )
    ucfg_twt_cfg_set_responder(*a1, 0);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: cfg80211 TWT responder: %d, enable twt: %d, twt_res_cfg: %d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "wlan_hdd_configure_twt_responder",
    a2 & 1,
    is_twt_enabled & 1);
  if ( (is_twt_enabled & 1) != 0 && (a2 & 1) != 0 && v29[0] )
    hdd_send_twt_responder_enable_cmd(a1, a3);
  else
    hdd_send_twt_responder_disable_cmd(a1, 0, a3);
  result = osif_twt_send_responder_disable_per_vdev(*a1, a3, opmode_from_vdev_id, v29[0]);
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
