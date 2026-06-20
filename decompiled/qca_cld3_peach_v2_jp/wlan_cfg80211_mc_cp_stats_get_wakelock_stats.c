__int64 __fastcall wlan_cfg80211_mc_cp_stats_get_wakelock_stats(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int psoc_wake_lock_stats; // w0
  __int64 result; // x0
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  int v127; // w20
  int v128; // w22
  int v129; // w23
  int v130; // w24
  int v131; // w21
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  int v140; // w22
  __int64 v141; // [xsp+0h] [xbp-80h] BYREF
  __int64 v142; // [xsp+8h] [xbp-78h]
  __int64 v143; // [xsp+10h] [xbp-70h]
  __int64 v144; // [xsp+18h] [xbp-68h]
  __int64 v145; // [xsp+20h] [xbp-60h]
  __int64 v146; // [xsp+28h] [xbp-58h]
  __int64 v147; // [xsp+30h] [xbp-50h]
  __int64 v148; // [xsp+38h] [xbp-48h]
  __int64 v149; // [xsp+40h] [xbp-40h]
  __int64 v150; // [xsp+48h] [xbp-38h]
  __int64 v151; // [xsp+50h] [xbp-30h]
  __int64 v152; // [xsp+58h] [xbp-28h]
  __int64 v153; // [xsp+60h] [xbp-20h]
  __int64 v154; // [xsp+68h] [xbp-18h]
  int v155; // [xsp+74h] [xbp-Ch] BYREF
  __int64 v156; // [xsp+78h] [xbp-8h]

  v156 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v153 = 0;
  v154 = 0;
  v151 = 0;
  v152 = 0;
  v149 = 0;
  v150 = 0;
  v147 = 0;
  v148 = 0;
  v145 = 0;
  v146 = 0;
  v143 = 0;
  v144 = 0;
  v141 = 0;
  v142 = 0;
  psoc_wake_lock_stats = ucfg_mc_cp_stats_get_psoc_wake_lock_stats(a1, (__int64)&v141, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( psoc_wake_lock_stats )
  {
    result = qdf_status_to_os_return(psoc_wake_lock_stats);
  }
  else
  {
    v13 = _cfg80211_alloc_reply_skb(a2, 103, 197, 476);
    if ( v13 )
    {
      v22 = v13;
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: wow_ucast_wake_up_count %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats",
        (unsigned int)v141);
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: wow_bcast_wake_up_count %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats",
        HIDWORD(v141));
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: wow_ipv4_mcast_wake_up_count %d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats",
        (unsigned int)v142);
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: wow_ipv6_mcast_wake_up_count %d",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats",
        HIDWORD(v142));
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: wow_ipv6_mcast_ra_stats %d",
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats",
        (unsigned int)v143);
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: wow_ipv6_mcast_ns_stats %d",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats",
        HIDWORD(v143));
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: wow_ipv6_mcast_na_stats %d",
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats",
        (unsigned int)v144);
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: wow_icmpv4_count %d",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats",
        (unsigned int)v145);
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: wow_icmpv6_count %d",
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats",
        HIDWORD(v145));
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: wow_rssi_breach_wake_up_count %d",
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats",
        (unsigned int)v146);
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: wow_low_rssi_wake_up_count %d",
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats",
        HIDWORD(v146));
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: wow_gscan_wake_up_count %d",
        v103,
        v104,
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats",
        (unsigned int)v147);
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: wow_pno_complete_wake_up_count %d",
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats",
        HIDWORD(v147));
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: wow_pno_match_wake_up_count %d",
        v119,
        v120,
        v121,
        v122,
        v123,
        v124,
        v125,
        v126,
        "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats",
        (unsigned int)v148);
      v128 = v142;
      v127 = HIDWORD(v142);
      v129 = v141;
      v130 = HIDWORD(v141);
      v131 = HIDWORD(v145);
      v155 = 0;
      if ( (unsigned int)nla_put(v22, 1, 4, &v155) )
        goto LABEL_26;
      v155 = 0;
      if ( (unsigned int)nla_put(v22, 2, 4, &v155) )
        goto LABEL_26;
      v155 = 0;
      if ( (unsigned int)nla_put(v22, 3, 4, &v155) )
        goto LABEL_26;
      v155 = 0;
      if ( (unsigned int)nla_put(v22, 4, 4, &v155) )
        goto LABEL_26;
      v155 = 0;
      if ( (unsigned int)nla_put(v22, 5, 4, &v155) )
        goto LABEL_26;
      v155 = 0;
      if ( (unsigned int)nla_put(v22, 6, 4, &v155) )
        goto LABEL_26;
      v140 = v128 + v127;
      v155 = v140 + v129 + v130;
      if ( (unsigned int)nla_put(v22, 7, 4, &v155) )
        goto LABEL_26;
      v155 = v141;
      if ( (unsigned int)nla_put(v22, 8, 4, &v155) )
        goto LABEL_26;
      v155 = v140;
      if ( (unsigned int)nla_put(v22, 9, 4, &v155) )
        goto LABEL_26;
      v155 = HIDWORD(v141);
      if ( (unsigned int)nla_put(v22, 10, 4, &v155) )
        goto LABEL_26;
      v155 = v145;
      if ( (unsigned int)nla_put(v22, 11, 4, &v155) )
        goto LABEL_26;
      v155 = v131;
      if ( (unsigned int)nla_put(v22, 12, 4, &v155) )
        goto LABEL_26;
      v155 = v143;
      if ( (unsigned int)nla_put(v22, 13, 4, &v155) )
        goto LABEL_26;
      v155 = v144;
      if ( (unsigned int)nla_put(v22, 14, 4, &v155) )
        goto LABEL_26;
      v155 = HIDWORD(v143);
      if ( (unsigned int)nla_put(v22, 15, 4, &v155)
        || (v155 = v142, (unsigned int)nla_put(v22, 16, 4, &v155))
        || (v155 = v127, (unsigned int)nla_put(v22, 17, 4, &v155))
        || (v155 = v146, (unsigned int)nla_put(v22, 19, 4, &v155))
        || (v155 = HIDWORD(v146), (unsigned int)nla_put(v22, 20, 4, &v155))
        || (v155 = v147, (unsigned int)nla_put(v22, 21, 4, &v155))
        || (v155 = HIDWORD(v147), (unsigned int)nla_put(v22, 22, 4, &v155))
        || (v155 = v148, (unsigned int)nla_put(v22, 23, 4, &v155)) )
      {
LABEL_26:
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: nla put fail",
          v132,
          v133,
          v134,
          v135,
          v136,
          v137,
          v138,
          v139,
          "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats");
        sk_skb_reason_drop(0, v22, 2);
        result = 4294967274LL;
      }
      else
      {
        cfg80211_vendor_cmd_reply(v22);
        result = 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_cfg80211_mc_cp_stats_send_wake_lock_stats");
      result = 4294967284LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
