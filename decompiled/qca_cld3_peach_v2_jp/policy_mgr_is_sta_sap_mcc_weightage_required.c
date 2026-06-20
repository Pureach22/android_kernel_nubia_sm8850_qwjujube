__int64 __fastcall policy_mgr_is_sta_sap_mcc_weightage_required(__int64 a1, __int64 a2, unsigned int a3)
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
  __int64 v15; // x22
  _DWORD *v16; // x8
  unsigned int v17; // w24
  unsigned int v18; // w23
  int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w4
  bool is_24ghz_ch_freq; // w22
  char v30; // w8
  char ap_6ghz_capable; // w23
  char is_sta_sap_scc_allowed_on_dfs_chan; // w24
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  char v43; // w21
  unsigned int v44; // [xsp+4h] [xbp-2Ch] BYREF
  int v45; // [xsp+8h] [xbp-28h] BYREF
  char v46; // [xsp+Ch] [xbp-24h]
  _QWORD v47[2]; // [xsp+10h] [xbp-20h] BYREF
  int v48; // [xsp+20h] [xbp-10h]
  __int64 v49; // [xsp+28h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v48 = 0;
  v47[0] = 0;
  v47[1] = 0;
  v44 = 4;
  v45 = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v15 = context;
    if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0
      && (unsigned int)policy_mgr_get_mcc_to_scc_switch_mode(a1) == 6
      && (unsigned __int8)policy_mgr_get_mode_specific_conn_info(a1, v47, &v45, 1) )
    {
      v16 = *(_DWORD **)(v15 + 368);
      v17 = v47[0];
      v18 = (unsigned __int8)v45;
      if ( !v16 )
        goto LABEL_16;
      if ( *(v16 - 1) != -333933844 )
        __break(0x8228u);
      v19 = ((__int64 (__fastcall *)(__int64, _QWORD, unsigned int *))v16)(a1, v18, &v44);
      v28 = v44;
      if ( !v19 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: acs_band: %d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "policy_mgr_is_sta_sap_mcc_weightage_required",
          v44);
        v28 = v44;
      }
      if ( v28 <= 1 )
      {
        is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v17);
        if ( !v17 )
          goto LABEL_18;
      }
      else
      {
LABEL_16:
        is_24ghz_ch_freq = 0;
        if ( !v17 )
          goto LABEL_18;
      }
      if ( !wlan_reg_is_6ghz_chan_freq(v17) )
      {
        ap_6ghz_capable = policy_mgr_get_ap_6ghz_capable(a1, v18, 0);
LABEL_20:
        is_sta_sap_scc_allowed_on_dfs_chan = policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(a1);
        v34 = policy_mgr_get_context(a1);
        if ( v34 )
        {
          v43 = *(_BYTE *)(v34 + 2214) ^ 1;
          if ( !is_24ghz_ch_freq )
          {
LABEL_25:
            if ( ((ap_6ghz_capable & 1) != 0 || !wlan_reg_is_6ghz_chan_freq(a3))
              && is_sta_sap_scc_allowed_on_dfs_chan & 1
               | ((wlan_reg_is_dfs_for_freq(a2, a3, v35, v36, v37, v38, v39, v40, v41, v42) & 1) == 0) )
            {
              v30 = wlan_reg_is_freq_indoor() & v43;
              goto LABEL_15;
            }
LABEL_29:
            v30 = 1;
            goto LABEL_15;
          }
        }
        else
        {
          qdf_trace_msg(
            0x4Fu,
            2u,
            "%s: pm_ctx is NULL",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "policy_mgr_get_sta_sap_scc_allowed_on_indoor_chnl");
          v43 = 1;
          if ( !is_24ghz_ch_freq )
            goto LABEL_25;
        }
        if ( !wlan_reg_is_24ghz_ch_freq(a3) )
          goto LABEL_29;
        goto LABEL_25;
      }
LABEL_18:
      ap_6ghz_capable = 1;
      goto LABEL_20;
    }
    v30 = 0;
  }
  else
  {
    qdf_trace_msg(
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
      "policy_mgr_is_sta_sap_mcc_weightage_required");
    v30 = 0;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v30 & 1;
}
