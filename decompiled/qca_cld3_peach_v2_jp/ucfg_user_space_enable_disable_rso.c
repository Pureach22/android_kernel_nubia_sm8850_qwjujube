__int64 __fastcall ucfg_user_space_enable_disable_rso(__int64 a1, unsigned int a2, char a3)
{
  __int64 v6; // x21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  char v15; // w23
  unsigned int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w22
  unsigned int v26; // w19
  __int64 result; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  char v36[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+8h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 80);
  v36[0] = 0;
  ucfg_mlme_is_lfr_enabled(v6, v36);
  if ( (v36[0] & 1) != 0 )
  {
    v15 = a3 ^ 1;
    if ( (unsigned int)mlme_get_roam_state(v6, a2) == 1 )
    {
      v16 = cm_roam_send_disable_config(v6, a2, v15 & 1);
      if ( v16 )
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: ROAM: update fast roaming failed, status: %d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "ucfg_user_space_enable_disable_rso",
          v16);
    }
    wlan_mlme_set_usr_disabled_roaming(v6, v15 & 1);
    if ( (a3 & 1) != 0 )
    {
      cm_roam_send_disable_config(v6, a2, 0);
      mlme_get_supplicant_disabled_roaming(v6, a2);
      v25 = 2;
LABEL_14:
      mlme_set_supplicant_disabled_roaming(v6, a2, v15 & 1);
      result = cm_roam_state_change(a1, a2, v25, 0x27u, 0, 0);
      goto LABEL_15;
    }
    if ( (mlme_get_supplicant_disabled_roaming(v6, a2) & 1) == 0 )
    {
      v25 = 3;
      goto LABEL_14;
    }
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: ROAM_CONFIG: RSO already disabled by supplicant",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "ucfg_user_space_enable_disable_rso");
    result = 6;
  }
  else
  {
    if ( (a3 & 1) != 0 )
      v26 = 16;
    else
      v26 = 0;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: ROAM_CONFIG: Fast roam ini is disabled. is_fast_roam_enabled %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "ucfg_user_space_enable_disable_rso",
      a3 & 1);
    result = v26;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
