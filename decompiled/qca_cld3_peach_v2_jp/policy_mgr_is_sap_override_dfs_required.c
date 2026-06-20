__int64 __fastcall policy_mgr_is_sap_override_dfs_required(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        __int64 a14,
        unsigned int *a15,
        unsigned int *a16)
{
  __int64 v16; // x19
  unsigned int dfs_beaconing_session_id; // w0
  char v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  char is_vdev_in_cac_wait; // w24
  unsigned int v35; // w0
  bool is_24ghz_ch_freq; // w23
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int sbs_cut_off_freq; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w4
  const char *v55; // x2
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  bool v64; // w22
  unsigned int v66; // [xsp+8h] [xbp-18h] BYREF
  __int64 v67; // [xsp+Ch] [xbp-14h]
  int v68; // [xsp+14h] [xbp-Ch]
  __int64 v69; // [xsp+18h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_QWORD *)(a1 + 80);
  v68 = 0;
  v67 = 0;
  if ( !v16 )
    goto LABEL_5;
  if ( !a15 || !a16 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid NULL pointer",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "policy_mgr_is_sap_override_dfs_required");
    v25 = 0;
    goto LABEL_38;
  }
  dfs_beaconing_session_id = policy_mgr_get_dfs_beaconing_session_id(v16);
  *a15 = dfs_beaconing_session_id;
  if ( dfs_beaconing_session_id == 255 )
    goto LABEL_5;
  if ( (unsigned int)policy_mgr_get_chan_by_session_id(v16, dfs_beaconing_session_id, a16) )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Fail to get channel by vdev id %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "policy_mgr_is_sap_override_dfs_required",
      *a15);
    v25 = 0;
    goto LABEL_38;
  }
  is_vdev_in_cac_wait = wlan_util_is_vdev_in_cac_wait(a1, 0x18u);
  if ( a2 )
    v35 = a2;
  else
    v35 = a4;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v35);
  if ( (is_vdev_in_cac_wait & 1) != 0 )
  {
    if ( (policy_mgr_is_current_hwmode_dbs(v16) & 1) == 0
      && ((unsigned __int8)policy_mgr_is_current_hwmode_sbs(v16) & 1) == 0 )
    {
      v55 = "%s: CAC in progress, current SMM mode";
      goto LABEL_35;
    }
    if ( !(is_24ghz_ch_freq | ((policy_mgr_is_current_hwmode_dbs(v16) & 1) == 0)) )
    {
      v55 = "%s: CAC in progress, current DBS mode";
      goto LABEL_35;
    }
  }
  if ( (policy_mgr_is_hw_dbs_capable(v16) & 1) == 0 && (policy_mgr_is_hw_sbs_capable(v16) & 1) == 0 )
  {
    v25 = 1;
    goto LABEL_38;
  }
  if ( (policy_mgr_is_hw_sbs_capable(v16) & 1) == 0 )
  {
    if ( is_24ghz_ch_freq )
      goto LABEL_5;
    v55 = "%s: DBS capable, new SAP on non 2ghz";
LABEL_35:
    qdf_trace_msg(0x4Fu, 8u, v55, v37, v38, v39, v40, v41, v42, v43, v44, "policy_mgr_is_sap_override_dfs_required");
    v25 = 1;
    goto LABEL_38;
  }
  sbs_cut_off_freq = policy_mgr_get_sbs_cut_off_freq(v16);
  if ( a2 || !a4 || !a5 )
  {
    v66 = a3;
    v64 = wlan_reg_is_5ghz_ch_freq(a2)
       && (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                          a1,
                          a2,
                          &v66,
                          0,
                          v56,
                          v57,
                          v58,
                          v59,
                          v60,
                          v61,
                          v62,
                          v63) == 2;
    v25 = v64 | policy_mgr_2_freq_always_on_same_mac(v16, a2, *a16);
    goto LABEL_38;
  }
  if ( is_24ghz_ch_freq )
  {
LABEL_5:
    v25 = 0;
    goto LABEL_38;
  }
  v54 = *a16;
  if ( sbs_cut_off_freq < a4 && v54 > sbs_cut_off_freq || (v25 = 0, sbs_cut_off_freq > a5) && v54 < sbs_cut_off_freq )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: con DFS freq %d acs start %d end %d",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "policy_mgr_is_sap_override_dfs_required");
    v25 = 1;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return v25 & 1;
}
