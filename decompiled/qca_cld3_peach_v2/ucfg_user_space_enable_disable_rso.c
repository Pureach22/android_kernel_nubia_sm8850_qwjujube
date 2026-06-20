__int64 __fastcall ucfg_user_space_enable_disable_rso(__int64 a1, unsigned int a2, char a3)
{
  __int64 v6; // x22
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
  unsigned int v25; // w19
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w2
  char v44[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v45; // [xsp+8h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 80);
  v44[0] = 0;
  ucfg_mlme_is_lfr_enabled(v6, v44);
  if ( (v44[0] & 1) != 0 )
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
    }
    else if ( (mlme_get_supplicant_disabled_roaming(v6, a2) & 1) != 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: ROAM_CONFIG: RSO already disabled by supplicant",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "ucfg_user_space_enable_disable_rso");
      v25 = 6;
      goto LABEL_19;
    }
    mlme_set_supplicant_disabled_roaming(v6, a2, v15 & 1);
    if ( (mlo_is_ml_connection_in_progress(v6, a2) & 1) != 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: mlo connection in progress",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "ucfg_user_space_enable_disable_rso");
      v25 = 0;
    }
    else
    {
      if ( (a3 & 1) != 0 )
        v42 = 2;
      else
        v42 = 3;
      v25 = cm_roam_state_change(a1, a2, v42, 0x27u, 0, 0);
    }
  }
  else
  {
    if ( (a3 & 1) != 0 )
      v25 = 16;
    else
      v25 = 0;
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
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return v25;
}
