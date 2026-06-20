__int64 __fastcall hdd_get_station_info_ex(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x21
  __int64 *v11; // x23
  bool is_disconnected; // w0
  char v13; // w22
  bool v14; // w19
  __int64 vdev_by_user; // x0
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x25
  char v34; // w24
  __int64 v35; // x0
  __int64 v36; // x19
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x25
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x21
  int v55; // w8
  int v56; // w26
  int v57; // w9
  int v58; // w8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w9
  unsigned int v68; // w11
  int v69; // w10
  unsigned int v70; // w11
  int v71; // w9
  unsigned int v72; // w10
  unsigned int v73; // w12
  int v74; // w11
  __int64 v75; // x0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x22
  int v85; // w8
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x21
  __int64 v103; // x21
  __int64 v104; // x21
  unsigned int v105; // w12
  int v106; // w12
  unsigned int v107; // w13
  int v108; // w13
  int v109; // w0
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  __int64 v126; // x21
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  __int64 v135; // x21
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  __int64 v144; // x21
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  __int64 v153; // x21
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  __int64 v162; // x21
  __int64 v163; // x0
  __int64 v164; // x0
  __int64 result; // x0
  unsigned int v166; // w0
  __int64 v167; // x1
  unsigned int v168; // w20
  char v169[4]; // [xsp+0h] [xbp-10h] BYREF
  int v170; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v171; // [xsp+8h] [xbp-8h]

  v171 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)a1;
  v169[0] = 0;
  v11 = *(__int64 **)(v10 + 24);
  ucfg_mc_cp_get_big_data_fw_support(*v11, v169, a2, a3, a4, a5, a6, a7, a8, a9);
  is_disconnected = hdd_cm_is_disconnected(a1);
  v13 = v169[0];
  v14 = is_disconnected;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 0x51u, (__int64)"hdd_get_station_info_ex");
  if ( !vdev_by_user )
  {
    qdf_trace_msg(0x33u, 2u, "%s: vdev is NULL", v17, v18, v19, v20, v21, v22, v23, v24, "hdd_get_station_info_ex");
LABEL_90:
    result = 4294967274LL;
    goto LABEL_91;
  }
  _hdd_objmgr_put_vdev_by_user(
    vdev_by_user,
    0x51u,
    (__int64)"hdd_get_station_info_ex",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24);
  if ( (unsigned int)wlan_hdd_get_station_stats((__int64 *)a1) )
  {
    v33 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: wlan_hdd_get_station_stats fail",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks = v33;
    }
  }
  v34 = v14 & v13;
  wlan_hdd_get_peer_rx_rate_stats(a1);
  if ( !hdd_cm_is_vdev_connected((_DWORD *)a1) )
  {
    v36 = 0;
    if ( (v34 & 1) != 0 )
      goto LABEL_10;
LABEL_15:
    v55 = 0;
    goto LABEL_17;
  }
  v35 = _qdf_mem_malloc(0x200u, "hdd_get_station_info_ex", 2592);
  v36 = v35;
  if ( v35 )
  {
    qdf_mem_copy((void *)(v35 + 32), (const void *)(a1 + 300), 6u);
    if ( (unsigned int)hdd_get_peer_stats(v10, v36) )
    {
      v45 = jiffies;
      if ( hdd_get_station_info_ex___last_ticks_86 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: hdd_get_peer_stats fail",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "hdd_get_station_info_ex");
        hdd_get_station_info_ex___last_ticks_86 = v45;
        if ( (v34 & 1) != 0 )
          goto LABEL_10;
        goto LABEL_15;
      }
    }
  }
  if ( (v34 & 1) == 0 )
    goto LABEL_15;
LABEL_10:
  if ( (unsigned int)wlan_hdd_get_big_data_station_stats((_DWORD *)a1) )
  {
    v54 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks_88 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: wlan_hdd_get_big_data_station_stats fail",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks_88 = v54;
    }
    goto LABEL_84;
  }
  v55 = 80;
LABEL_17:
  v56 = *(_DWORD *)(v10 + 52404);
  if ( *(_BYTE *)(a1 + 4268) )
    v57 = 32;
  else
    v57 = 0;
  v58 = (v57 | v55 | (8 * (v56 != 0))) + hdd_get_uplink_delay_len(v10);
  if ( v36 )
  {
    v67 = *(_DWORD *)(v36 + 468);
    if ( !v67 )
    {
      v71 = 64;
      v72 = *(_DWORD *)(v36 + 472);
      if ( v72 )
        goto LABEL_27;
      goto LABEL_32;
    }
    v68 = v67 - 1;
    if ( v67 == 1 )
    {
      v69 = 0;
    }
    else
    {
      v69 = 0;
      if ( (_WORD)v67 )
      {
        v105 = HIWORD(v68);
        v68 = 0;
        if ( !v105 )
        {
          v69 = v67 & 0x1FFFE;
          v68 = 8 * (v67 & 0x1FFFE);
          v106 = v67 & 0x1FFFE;
          do
            v106 -= 2;
          while ( v106 );
          if ( v67 == v69 )
          {
            v70 = v68 - 8;
            goto LABEL_26;
          }
        }
      }
      else
      {
        v68 = 0;
      }
    }
    v70 = v68 - 8;
    do
    {
      ++v69;
      v70 += 8;
    }
    while ( v67 > (unsigned __int16)v69 );
LABEL_26:
    v71 = v70 + 72;
    v72 = *(_DWORD *)(v36 + 472);
    if ( v72 )
    {
LABEL_27:
      v73 = v72 - 1;
      if ( v72 == 1 )
      {
        v74 = 0;
      }
      else
      {
        v74 = 0;
        if ( (_WORD)v72 )
        {
          v107 = HIWORD(v73);
          v73 = 0;
          if ( !v107 )
          {
            v74 = v72 & 0x1FFFE;
            v73 = 0;
            v108 = v72 & 0x1FFFE;
            do
            {
              v108 -= 2;
              v73 += 16;
            }
            while ( v108 );
            if ( v72 == v74 )
              goto LABEL_33;
          }
        }
        else
        {
          v73 = 0;
        }
      }
      do
      {
        ++v74;
        v73 += 8;
      }
      while ( v72 > (unsigned __int16)v74 );
LABEL_33:
      v58 += v71 + v73;
      goto LABEL_34;
    }
LABEL_32:
    v73 = v72;
    goto LABEL_33;
  }
LABEL_34:
  if ( !v58 )
  {
    v103 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks_90 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to get bcn pmf stats",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks_90 = v103;
    }
    goto LABEL_84;
  }
  v75 = _cfg80211_alloc_reply_skb(v11[3], 103, 197, (unsigned int)(v58 + 16));
  if ( !v75 )
  {
    v104 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks_92 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks_92 = v104;
    }
    goto LABEL_84;
  }
  v84 = v75;
  if ( *(_BYTE *)(a1 + 4268) == 1 )
  {
    v85 = *(_DWORD *)(a1 + 4272);
    *(_BYTE *)(a1 + 4268) = 0;
    v170 = v85;
    if ( (unsigned int)nla_put(v75, 39, 4, &v170)
      || (v170 = *(_DWORD *)(a1 + 4276), (unsigned int)nla_put(v84, 40, 4, &v170))
      || (v170 = *(_DWORD *)(a1 + 4280), (unsigned int)nla_put(v84, 41, 4, &v170))
      || (v170 = *(_DWORD *)(a1 + 4284), (unsigned int)nla_put(v84, 42, 4, &v170)) )
    {
      qdf_trace_msg(0x33u, 2u, "%s: put fail", v86, v87, v88, v89, v90, v91, v92, v93, "hdd_add_pmf_bcn_protect_stats");
      v102 = jiffies;
      if ( hdd_get_station_info_ex___last_ticks_93 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: hdd_add_pmf_bcn_protect_stats fail",
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          v100,
          v101,
          "hdd_get_station_info_ex");
        hdd_get_station_info_ex___last_ticks_93 = v102;
      }
      goto LABEL_83;
    }
  }
  if ( v56 )
  {
    v109 = osif_cm_mac_to_qca_connect_fail_reason(*(_DWORD *)(v10 + 52404));
    if ( v109 )
    {
      v170 = v109;
      if ( (unsigned int)nla_put(v84, 43, 4, &v170) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: put fail",
          v110,
          v111,
          v112,
          v113,
          v114,
          v115,
          v116,
          v117,
          "hdd_add_connect_fail_reason_code");
        v126 = jiffies;
        if ( hdd_get_station_info_ex___last_ticks_95 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: hdd_add_connect_fail_reason_code fail",
            v118,
            v119,
            v120,
            v121,
            v122,
            v123,
            v124,
            v125,
            "hdd_get_station_info_ex");
          hdd_get_station_info_ex___last_ticks_95 = v126;
        }
        goto LABEL_83;
      }
    }
  }
  if ( (v34 & 1) != 0 && (unsigned int)hdd_big_data_pack_resp_nlmsg(v84, a1) )
  {
LABEL_83:
    sk_skb_reason_drop(0, v84, 2);
LABEL_84:
    if ( v36 )
    {
      v163 = *(_QWORD *)(v36 + 480);
      if ( v163 )
      {
        _qdf_mem_free(v163);
        *(_QWORD *)(v36 + 480) = 0;
      }
      v164 = *(_QWORD *)(v36 + 488);
      if ( v164 )
      {
        _qdf_mem_free(v164);
        *(_QWORD *)(v36 + 488) = 0;
      }
      _qdf_mem_free(v36);
    }
    goto LABEL_90;
  }
  if ( (unsigned int)hdd_get_txrx_nss(v10, v84) )
  {
    v135 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks_97 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: hdd_get txrx nss fail",
        v127,
        v128,
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks_97 = v135;
    }
    goto LABEL_83;
  }
  if ( (unsigned int)hdd_add_uplink_delay(v10, v84) )
  {
    v144 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks_99 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: hdd_add_uplink_delay fail",
        v136,
        v137,
        v138,
        v139,
        v140,
        v141,
        v142,
        v143,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks_99 = v144;
    }
    goto LABEL_83;
  }
  if ( v36 && (unsigned int)hdd_add_peer_stats(v84, v36) )
  {
    v153 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks_101 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: hdd_add_peer_stats fail",
        v145,
        v146,
        v147,
        v148,
        v149,
        v150,
        v151,
        v152,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks_101 = v153;
    }
    goto LABEL_83;
  }
  if ( (unsigned int)hdd_add_uplink_jitter(v10, v84) )
  {
    v162 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks_103 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: hdd_add_uplink_jitter fail",
        v154,
        v155,
        v156,
        v157,
        v158,
        v159,
        v160,
        v161,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks_103 = v162;
    }
    goto LABEL_83;
  }
  v166 = cfg80211_vendor_cmd_reply(v84);
  v167 = *(unsigned __int8 *)(a1 + 8);
  v168 = v166;
  hdd_reset_roam_params(*v11, v167);
  if ( v36 )
    _qdf_mem_free(v36);
  result = v168;
LABEL_91:
  _ReadStatusReg(SP_EL0);
  return result;
}
