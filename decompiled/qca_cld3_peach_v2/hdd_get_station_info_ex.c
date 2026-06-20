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
  char v13; // w24
  bool v14; // w19
  __int64 vdev_by_user; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x22
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 result; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x25
  char v53; // w24
  __int64 v54; // x0
  __int64 v55; // x19
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x25
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x21
  int v74; // w8
  int v75; // w25
  int v76; // w9
  int v77; // w8
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  unsigned int v86; // w9
  unsigned int v87; // w11
  int v88; // w10
  unsigned int v89; // w11
  int v90; // w9
  unsigned int v91; // w10
  unsigned int v92; // w12
  int v93; // w11
  __int64 v94; // x0
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 v103; // x22
  int v104; // w8
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  __int64 v121; // x21
  __int64 v122; // x21
  __int64 v123; // x21
  unsigned int v124; // w12
  int v125; // w12
  unsigned int v126; // w13
  int v127; // w13
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  __int64 v136; // x21
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  __int64 v145; // x21
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  __int64 v154; // x21
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7
  __int64 v163; // x21
  double v164; // d0
  double v165; // d1
  double v166; // d2
  double v167; // d3
  double v168; // d4
  double v169; // d5
  double v170; // d6
  double v171; // d7
  __int64 v172; // x21
  __int64 v173; // x0
  __int64 v174; // x0
  unsigned int v175; // w0
  __int64 v176; // x1
  unsigned int v177; // w20
  char v178[4]; // [xsp+0h] [xbp-10h] BYREF
  int v179; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v180; // [xsp+8h] [xbp-8h]

  v180 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)a1;
  v178[0] = 0;
  v11 = *(__int64 **)(v10 + 24);
  ucfg_mc_cp_get_big_data_fw_support(*v11, v178, a2, a3, a4, a5, a6, a7, a8, a9);
  is_disconnected = hdd_cm_is_disconnected(a1);
  v13 = v178[0];
  v14 = is_disconnected;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 0x51u, (__int64)"hdd_get_station_info_ex");
  if ( !vdev_by_user )
  {
    qdf_trace_msg(0x33u, 2u, "%s: vdev is NULL", v16, v17, v18, v19, v20, v21, v22, v23, "hdd_get_station_info_ex");
LABEL_90:
    result = 4294967274LL;
    goto LABEL_91;
  }
  v24 = vdev_by_user;
  if ( (mlo_is_link_recfg_in_progress(vdev_by_user) & 1) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: link reconfig already in progress",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "hdd_get_station_info_ex");
    _hdd_objmgr_put_vdev_by_user(
      v24,
      6u,
      (__int64)"hdd_get_station_info_ex",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42);
    result = 4294967280LL;
    goto LABEL_91;
  }
  _hdd_objmgr_put_vdev_by_user(
    v24,
    0x51u,
    (__int64)"hdd_get_station_info_ex",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33);
  if ( (unsigned int)wlan_hdd_get_station_stats((_QWORD *)a1) )
  {
    v52 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: wlan_hdd_get_station_stats fail",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks = v52;
    }
  }
  v53 = v14 & v13;
  wlan_hdd_get_peer_rx_rate_stats(a1);
  if ( hdd_cm_is_vdev_connected((_DWORD *)a1) )
  {
    v54 = _qdf_mem_malloc(0x200u, "hdd_get_station_info_ex", 2592);
    v55 = v54;
    if ( v54 )
    {
      qdf_mem_copy((void *)(v54 + 32), (const void *)(a1 + 308), 6u);
      if ( (unsigned int)hdd_get_peer_stats(v10, v55) )
      {
        v64 = jiffies;
        if ( hdd_get_station_info_ex___last_ticks_87 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: hdd_get_peer_stats fail",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "hdd_get_station_info_ex");
          hdd_get_station_info_ex___last_ticks_87 = v64;
        }
      }
    }
    if ( (v53 & 1) != 0 )
      goto LABEL_14;
LABEL_18:
    v74 = 0;
    goto LABEL_20;
  }
  v55 = 0;
  if ( (v53 & 1) == 0 )
    goto LABEL_18;
LABEL_14:
  if ( (unsigned int)wlan_hdd_get_big_data_station_stats((_DWORD *)a1) )
  {
    v73 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks_89 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: wlan_hdd_get_big_data_station_stats fail",
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks_89 = v73;
    }
    goto LABEL_84;
  }
  v74 = 80;
LABEL_20:
  v75 = *(_DWORD *)(v10 + 52404);
  if ( *(_BYTE *)(a1 + 4540) )
    v76 = 32;
  else
    v76 = 0;
  v77 = (v76 | v74 | (8 * (v75 != 0))) + hdd_get_uplink_delay_len(v10);
  if ( v55 )
  {
    v86 = *(_DWORD *)(v55 + 468);
    if ( !v86 )
    {
      v90 = 64;
      v91 = *(_DWORD *)(v55 + 472);
      if ( v91 )
        goto LABEL_30;
      goto LABEL_35;
    }
    v87 = v86 - 1;
    if ( v86 == 1 )
    {
      v88 = 0;
    }
    else
    {
      v88 = 0;
      if ( (_WORD)v86 )
      {
        v124 = HIWORD(v87);
        v87 = 0;
        if ( !v124 )
        {
          v88 = v86 & 0x1FFFE;
          v87 = 8 * (v86 & 0x1FFFE);
          v125 = v86 & 0x1FFFE;
          do
            v125 -= 2;
          while ( v125 );
          if ( v86 == v88 )
          {
            v89 = v87 - 8;
            goto LABEL_29;
          }
        }
      }
      else
      {
        v87 = 0;
      }
    }
    v89 = v87 - 8;
    do
    {
      ++v88;
      v89 += 8;
    }
    while ( v86 > (unsigned __int16)v88 );
LABEL_29:
    v90 = v89 + 72;
    v91 = *(_DWORD *)(v55 + 472);
    if ( v91 )
    {
LABEL_30:
      v92 = v91 - 1;
      if ( v91 == 1 )
      {
        v93 = 0;
      }
      else
      {
        v93 = 0;
        if ( (_WORD)v91 )
        {
          v126 = HIWORD(v92);
          v92 = 0;
          if ( !v126 )
          {
            v93 = v91 & 0x1FFFE;
            v92 = 0;
            v127 = v91 & 0x1FFFE;
            do
            {
              v127 -= 2;
              v92 += 16;
            }
            while ( v127 );
            if ( v91 == v93 )
              goto LABEL_36;
          }
        }
        else
        {
          v92 = 0;
        }
      }
      do
      {
        ++v93;
        v92 += 8;
      }
      while ( v91 > (unsigned __int16)v93 );
LABEL_36:
      v77 += v90 + v92;
      goto LABEL_37;
    }
LABEL_35:
    v92 = v91;
    goto LABEL_36;
  }
LABEL_37:
  if ( !v77 )
  {
    v122 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks_91 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to get bcn pmf stats",
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks_91 = v122;
    }
    goto LABEL_84;
  }
  v94 = _cfg80211_alloc_reply_skb(v11[3], 103, 197, (unsigned int)(v77 + 16));
  if ( !v94 )
  {
    v123 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks_93 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks_93 = v123;
    }
    goto LABEL_84;
  }
  v103 = v94;
  if ( *(_BYTE *)(a1 + 4540) == 1 )
  {
    v104 = *(_DWORD *)(a1 + 4544);
    *(_BYTE *)(a1 + 4540) = 0;
    v179 = v104;
    if ( (unsigned int)nla_put(v94, 39, 4, &v179)
      || (v179 = *(_DWORD *)(a1 + 4548), (unsigned int)nla_put(v103, 40, 4, &v179))
      || (v179 = *(_DWORD *)(a1 + 4552), (unsigned int)nla_put(v103, 41, 4, &v179))
      || (v179 = *(_DWORD *)(a1 + 4556), (unsigned int)nla_put(v103, 42, 4, &v179)) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: put fail",
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        "hdd_add_pmf_bcn_protect_stats");
      v121 = jiffies;
      if ( hdd_get_station_info_ex___last_ticks_94 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: hdd_add_pmf_bcn_protect_stats fail",
          v113,
          v114,
          v115,
          v116,
          v117,
          v118,
          v119,
          v120,
          "hdd_get_station_info_ex");
        hdd_get_station_info_ex___last_ticks_94 = v121;
      }
      goto LABEL_83;
    }
  }
  if ( v75 && (unsigned int)hdd_add_connect_fail_reason_code(v103, v10) )
  {
    v136 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks_96 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: hdd_add_connect_fail_reason_code fail",
        v128,
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        v135,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks_96 = v136;
    }
    goto LABEL_83;
  }
  if ( (v53 & 1) != 0 && (unsigned int)hdd_big_data_pack_resp_nlmsg(v103, a1) )
  {
LABEL_83:
    sk_skb_reason_drop(0, v103, 2);
LABEL_84:
    if ( v55 )
    {
      v173 = *(_QWORD *)(v55 + 480);
      if ( v173 )
      {
        _qdf_mem_free(v173);
        *(_QWORD *)(v55 + 480) = 0;
      }
      v174 = *(_QWORD *)(v55 + 488);
      if ( v174 )
      {
        _qdf_mem_free(v174);
        *(_QWORD *)(v55 + 488) = 0;
      }
      _qdf_mem_free(v55);
    }
    goto LABEL_90;
  }
  if ( (unsigned int)hdd_get_txrx_nss(v10, v103) )
  {
    v145 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks_98 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: hdd_get txrx nss fail",
        v137,
        v138,
        v139,
        v140,
        v141,
        v142,
        v143,
        v144,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks_98 = v145;
    }
    goto LABEL_83;
  }
  if ( (unsigned int)hdd_add_uplink_delay(v10, v103) )
  {
    v154 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks_100 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: hdd_add_uplink_delay fail",
        v146,
        v147,
        v148,
        v149,
        v150,
        v151,
        v152,
        v153,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks_100 = v154;
    }
    goto LABEL_83;
  }
  if ( v55 && (unsigned int)hdd_add_peer_stats(v103, v55) )
  {
    v163 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks_102 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: hdd_add_peer_stats fail",
        v155,
        v156,
        v157,
        v158,
        v159,
        v160,
        v161,
        v162,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks_102 = v163;
    }
    goto LABEL_83;
  }
  if ( (unsigned int)hdd_add_uplink_jitter(v10, v103) )
  {
    v172 = jiffies;
    if ( hdd_get_station_info_ex___last_ticks_104 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: hdd_add_uplink_jitter fail",
        v164,
        v165,
        v166,
        v167,
        v168,
        v169,
        v170,
        v171,
        "hdd_get_station_info_ex");
      hdd_get_station_info_ex___last_ticks_104 = v172;
    }
    goto LABEL_83;
  }
  v175 = cfg80211_vendor_cmd_reply(v103);
  v176 = *(unsigned __int8 *)(a1 + 8);
  v177 = v175;
  hdd_reset_roam_params(*v11, v176);
  if ( v55 )
    _qdf_mem_free(v55);
  result = v177;
LABEL_91:
  _ReadStatusReg(SP_EL0);
  return result;
}
