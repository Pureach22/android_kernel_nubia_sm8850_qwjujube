__int64 __fastcall policy_mgr_valid_sap_conc_channel_check(
        __int64 a1,
        unsigned int *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int *a5)
{
  unsigned int alternate_channel_for_sap; // w26
  __int64 context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x23
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int opmode_from_vdev_id; // w0
  int v31; // w27
  __int64 result; // x0
  char scc_vdev_id; // w25
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  const char *v42; // x2
  __int64 v43; // x3
  int is_sta_sap_scc; // w28
  int is_sta_sap_scc_allowed_on_dfs_chan; // w25
  _DWORD *v46; // x8
  int v47; // w27
  int v48; // w8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  int v57; // w27
  const char *v58; // x2
  int v59; // w25
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned int v84; // w2
  _DWORD *v85; // x8
  unsigned int _5ghz_social_ch_freq; // [xsp+Ch] [xbp-24h]
  unsigned int channel; // [xsp+10h] [xbp-20h]
  int ap_6ghz_capable; // [xsp+14h] [xbp-1Ch]
  unsigned int v89; // [xsp+18h] [xbp-18h]
  unsigned int v90; // [xsp+1Ch] [xbp-14h]
  int v91; // [xsp+20h] [xbp-10h]
  _BYTE v92[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v93; // [xsp+28h] [xbp-8h]

  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  alternate_channel_for_sap = *a2;
  v92[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v20 = context;
    if ( (policy_mgr_is_force_scc(a1) & 1) == 0 )
    {
LABEL_68:
      result = 0;
      goto LABEL_69;
    }
    policy_mgr_get_mcc_scc_switch(a1, v92);
    v21 = policy_mgr_get_context(a1);
    if ( v21 )
    {
      opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(v21 + 8), a4);
      v31 = policy_mgr_qdf_opmode_to_pm_con_mode(a1, opmode_from_vdev_id, a4);
      if ( alternate_channel_for_sap )
        goto LABEL_16;
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid Context",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "policy_mgr_con_mode_by_vdev_id");
      v31 = 7;
      if ( alternate_channel_for_sap )
        goto LABEL_16;
    }
    scc_vdev_id = policy_mgr_fetch_scc_vdev_id(a1, a4, a3);
    if ( (policy_mgr_any_other_vdev_on_same_mac_as_freq(a1, a3, a4) & 1) == 0 )
      goto LABEL_68;
    if ( v31 == 1
      && (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0
      && scc_vdev_id == -1
      && (policy_mgr_is_sta_sap_scc(a1, a3, 1) & 1) == 0
      && v92[0] != 6 )
    {
      v42 = "Mode %d MCC situation in non-dbs hw STA, no SCC freq found %d";
      v43 = 1;
LABEL_71:
      qdf_trace_msg(0x4Fu, 8u, v42, v34, v35, v36, v37, v38, v39, v40, v41, v43, a3);
      result = 16;
      goto LABEL_69;
    }
    alternate_channel_for_sap = a3;
    if ( !a3 )
      goto LABEL_68;
LABEL_16:
    v91 = v31;
    is_sta_sap_scc = policy_mgr_is_sta_sap_scc(a1, alternate_channel_for_sap, 1);
    channel = policy_mgr_mode_specific_get_channel(a1, 5);
    _5ghz_social_ch_freq = wlan_nan_get_5ghz_social_ch_freq(*(_QWORD *)(v20 + 8));
    is_sta_sap_scc_allowed_on_dfs_chan = policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(a1);
    policy_mgr_get_sta_sap_scc_allowed_on_indoor_chnl(a1);
    v46 = *(_DWORD **)(v20 + 360);
    v90 = *a5;
    v89 = a5[3];
    if ( v46 )
    {
      if ( *(v46 - 1) != 157525345 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, _QWORD, unsigned int *))v46)(a1, a4, alternate_channel_for_sap, a5);
    }
    v47 = wlan_mlme_check_chan_param_has_dfs(*(_QWORD *)(v20 + 8), a5, alternate_channel_for_sap);
    ap_6ghz_capable = policy_mgr_get_ap_6ghz_capable(a1, a4, 0);
    v48 = wlan_reg_is_5ghz_ch_freq(alternate_channel_for_sap) & v47;
    v57 = is_sta_sap_scc ^ 1;
    if ( is_sta_sap_scc_allowed_on_dfs_chan & 1 | ((v48 & 1) == 0) || (v57 & 1) != 0 )
    {
      if ( wlan_reg_is_disable_for_pwrmode(
             *(_QWORD *)(v20 + 8),
             alternate_channel_for_sap,
             0,
             v49,
             v50,
             v51,
             v52,
             v53,
             v54,
             v55,
             v56) )
      {
        v58 = "sap not capable on disabled con ch_freq %d";
      }
      else
      {
        if ( v91 == 3
          && wlan_reg_is_passive_or_disable_for_pwrmode(
               *(_QWORD *)(v20 + 8),
               alternate_channel_for_sap,
               0,
               v49,
               v50,
               v51,
               v52,
               v53,
               v54,
               v55,
               v56)
          && ((policy_mgr_is_go_scc_strict(a1) & 1) == 0 || ((v57 | is_sta_sap_scc_allowed_on_dfs_chan) & 1) == 0) )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "Go not capable on dfs/disabled con ch_freq %d",
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            alternate_channel_for_sap);
          v59 = 3;
          if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
          {
LABEL_27:
            alternate_channel_for_sap = policy_mgr_get_alternate_channel_for_sap(a1, a4, a3, 3);
            qdf_trace_msg(
              0x4Fu,
              8u,
              "selected alternate ch %d",
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              alternate_channel_for_sap);
            if ( !alternate_channel_for_sap )
            {
              qdf_trace_msg(
                0x4Fu,
                8u,
                "Sap can't have concurrency on %d in dbs hw",
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                *a2);
              result = 16;
              goto LABEL_69;
            }
            goto LABEL_55;
          }
          goto LABEL_53;
        }
        if ( (((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_is_safe_channel)(a1, alternate_channel_for_sap) & 1) != 0
          || ((unsigned int)policy_mgr_sta_sap_scc_on_lte_coex_chan(a1) & is_sta_sap_scc & 1) != 0
          || (policy_mgr_get_nan_sap_scc_on_lte_coex_chnl(a1) & 1) != 0
          && ((wlan_reg_is_same_band_freqs(channel, alternate_channel_for_sap) & 1) != 0
           || (wlan_reg_is_same_band_freqs(_5ghz_social_ch_freq, alternate_channel_for_sap) & 1) != 0) )
        {
          if ( wlan_reg_is_6ghz_chan_freq(alternate_channel_for_sap)
            && ((wlan_reg_is_6ghz_chan_freq(a3) | ap_6ghz_capable) & 1) == 0 )
          {
            v58 = "sap not capable on 6GHZ con ch_freq %d";
          }
          else
          {
            if ( (wlan_reg_is_etsi_srd_chan_for_freq(
                    *(_QWORD *)(v20 + 8),
                    alternate_channel_for_sap,
                    v49,
                    v50,
                    v51,
                    v52,
                    v53,
                    v54,
                    v55,
                    v56)
                & 1) == 0
              || (policy_mgr_get_srd_enable_for_vdev(a1, a4) & 1) != 0 )
            {
              if ( (policy_mgr_is_sap_go_interface_allowed_on_indoor(*(_QWORD *)(v20 + 8), a4) & 1) != 0 )
              {
                v59 = v91;
                goto LABEL_55;
              }
              qdf_trace_msg(
                0x4Fu,
                8u,
                "sap not capable on indoor con ch_freq %d is_sta_sap_scc:%d",
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                alternate_channel_for_sap,
                is_sta_sap_scc & 1);
LABEL_26:
              v59 = v91;
              if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
                goto LABEL_27;
              if ( v91 == 1 )
              {
                v43 = *a2;
                if ( v92[0] != 6 )
                {
                  v42 = "MCC situation in non-dbs hw STA freq %d SAP freq %d not supported";
                  goto LABEL_71;
                }
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  "MCC situation in non-dbs hw STA freq %d SAP freq %d cc_mode %d",
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  v43,
                  a3,
                  6);
                goto LABEL_54;
              }
LABEL_53:
              qdf_trace_msg(
                0x4Fu,
                8u,
                "MCC situation in non-dbs hw STA freq %d GO freq %d SCC not supported",
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                *a2,
                a3);
LABEL_54:
              alternate_channel_for_sap = 0;
LABEL_55:
              if ( alternate_channel_for_sap != a3 || v90 != *a5 || v89 != a5[3] )
              {
                *a2 = alternate_channel_for_sap;
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  "sap conc result con freq %d bw %d ccfs1 %d org freq %d bw %d ccfs1 %d",
                  v68,
                  v69,
                  v70,
                  v71,
                  v72,
                  v73,
                  v74,
                  v75,
                  alternate_channel_for_sap,
                  *a5,
                  a5[3],
                  a3,
                  v90,
                  v89);
              }
              v84 = *a2;
              if ( *a2 && v59 == 1 )
              {
                if ( (((__int64 (__fastcall *)(_QWORD, __int64))policy_mgr_is_multi_sap_allowed_on_same_band)(
                        *(_QWORD *)(v20 + 8),
                        1)
                    & 1) == 0 )
                {
                  v42 = "Terminating multi sap on same band, con_ch_freq %d sap_ch_freq %d";
                  v43 = alternate_channel_for_sap;
                  goto LABEL_71;
                }
                v84 = *a2;
              }
              if ( v84 )
              {
                v85 = *(_DWORD **)(v20 + 360);
                if ( v85 )
                {
                  if ( *(v85 - 1) != 157525345 )
                    __break(0x8228u);
                  ((void (__fastcall *)(__int64, _QWORD, _QWORD, unsigned int *))v85)(
                    a1,
                    a4,
                    alternate_channel_for_sap,
                    a5);
                }
              }
              goto LABEL_68;
            }
            v58 = "sap not capable on SRD con ch_freq %d";
          }
        }
        else
        {
          v58 = "sap not capable unsafe con ch_freq %d";
        }
      }
    }
    else
    {
      v58 = "sap not capable of DFS SCC on con ch_freq %d";
    }
    qdf_trace_msg(0x4Fu, 8u, v58, v49, v50, v51, v52, v53, v54, v55, v56, alternate_channel_for_sap);
    goto LABEL_26;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Invalid context",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "policy_mgr_valid_sap_conc_channel_check");
  result = 16;
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}
