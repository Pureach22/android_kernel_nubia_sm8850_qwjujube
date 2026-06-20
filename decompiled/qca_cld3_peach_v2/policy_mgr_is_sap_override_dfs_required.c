__int64 __fastcall policy_mgr_is_sap_override_dfs_required(
        __int64 a1,
        unsigned int a2,
        int a3,
        unsigned int a4,
        unsigned int a5,
        char a6,
        unsigned int *a7,
        unsigned int *a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  __int64 v16; // x19
  unsigned int dfs_beaconing_session_id; // w0
  char v26; // w8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  char is_vdev_in_cac_wait; // w24
  unsigned int v36; // w0
  bool is_24ghz_ch_freq; // w23
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int sbs_cut_off_freq; // w0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w8
  unsigned int v56; // w4
  const char *v57; // x2
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  bool v66; // w22
  int v68; // [xsp+0h] [xbp-20h] BYREF
  __int64 v69; // [xsp+4h] [xbp-1Ch]
  __int64 v70; // [xsp+Ch] [xbp-14h]
  int v71; // [xsp+14h] [xbp-Ch]
  __int64 v72; // [xsp+18h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_QWORD *)(a1 + 80);
  v71 = 0;
  v70 = 0;
  v69 = 0;
  if ( !v16 )
    goto LABEL_5;
  if ( !a7 || !a8 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid NULL pointer",
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      a16,
      "policy_mgr_is_sap_override_dfs_required");
    v26 = 0;
    goto LABEL_40;
  }
  dfs_beaconing_session_id = policy_mgr_get_dfs_beaconing_session_id(v16);
  *a7 = dfs_beaconing_session_id;
  if ( dfs_beaconing_session_id == 255 )
    goto LABEL_5;
  if ( (unsigned int)policy_mgr_get_chan_by_session_id(v16, dfs_beaconing_session_id, a8) )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Fail to get channel by vdev id %d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "policy_mgr_is_sap_override_dfs_required",
      *a7);
    v26 = 0;
    goto LABEL_40;
  }
  is_vdev_in_cac_wait = wlan_util_is_vdev_in_cac_wait(a1, 0x18u);
  if ( a2 )
    v36 = a2;
  else
    v36 = a4;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v36);
  if ( (is_vdev_in_cac_wait & 1) != 0 )
  {
    if ( (policy_mgr_is_current_hwmode_dbs(v16) & 1) == 0
      && ((unsigned __int8)policy_mgr_is_current_hwmode_sbs(v16) & 1) == 0 )
    {
      v57 = "%s: CAC in progress, current SMM mode";
      goto LABEL_37;
    }
    if ( !(is_24ghz_ch_freq | ((policy_mgr_is_current_hwmode_dbs(v16) & 1) == 0)) )
    {
      v57 = "%s: CAC in progress, current DBS mode";
      goto LABEL_37;
    }
  }
  if ( (policy_mgr_is_hw_dbs_capable(v16) & 1) == 0 && (policy_mgr_is_hw_sbs_capable(v16) & 1) == 0 )
  {
    v26 = 1;
    goto LABEL_40;
  }
  if ( (policy_mgr_is_hw_sbs_capable(v16) & 1) == 0 )
  {
    if ( is_24ghz_ch_freq )
      goto LABEL_5;
    v57 = "%s: DBS capable, new SAP on non 2ghz";
LABEL_37:
    qdf_trace_msg(0x4Fu, 8u, v57, v38, v39, v40, v41, v42, v43, v44, v45, "policy_mgr_is_sap_override_dfs_required");
    v26 = 1;
    goto LABEL_40;
  }
  sbs_cut_off_freq = policy_mgr_get_sbs_cut_off_freq(v16);
  v55 = a2;
  if ( !a2 && a4 && a5 )
  {
    if ( !is_24ghz_ch_freq )
    {
      v56 = *a8;
      if ( sbs_cut_off_freq < a4 && v56 > sbs_cut_off_freq || (v26 = 0, sbs_cut_off_freq > a5) && v56 < sbs_cut_off_freq )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: con DFS freq %d acs start %d end %d",
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          "policy_mgr_is_sap_override_dfs_required");
        v26 = 1;
      }
      goto LABEL_40;
    }
LABEL_5:
    v26 = 0;
    goto LABEL_40;
  }
  v68 = a3;
  if ( (a6 & 1) != 0 )
  {
    wlan_reg_set_create_punc_bitmap((__int64)&v68, 1);
    v55 = a2;
  }
  v66 = wlan_reg_is_5ghz_ch_freq(v55)
     && (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                        a1,
                        a2,
                        &v68,
                        0,
                        v58,
                        v59,
                        v60,
                        v61,
                        v62,
                        v63,
                        v64,
                        v65) == 2;
  v26 = v66 | policy_mgr_2_freq_always_on_same_mac(v16, a2, *a8);
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return v26 & 1;
}
