__int64 __fastcall hdd_cfg80211_update_acs_config(__int64 a1, char a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 *v12; // x25
  __int64 v13; // x27
  __int64 *conn_info; // x0
  __int64 v15; // x8
  __int64 v16; // x21
  __int64 v17; // x20
  int v18; // w19
  unsigned int v19; // w21
  __int64 v20; // x8
  __int64 v21; // x21
  __int64 v22; // x20
  int v23; // w8
  int v24; // w9
  int v25; // w8
  __int64 v26; // x0
  __int64 v27; // x20
  int v28; // w8
  unsigned int v29; // w8
  unsigned int v30; // w21
  __int64 *v31; // x19
  __int64 v32; // x0
  __int64 v33; // x23
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  const char *v42; // x2
  int v43; // w9
  __int64 v44; // x28
  unsigned __int64 v45; // x19
  _DWORD *v46; // x22
  unsigned int *v47; // x24
  bool is_disable_for_pwrmode; // w0
  unsigned int *v49; // x8
  __int64 v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x28
  __int64 v60; // x19
  __int64 v61; // x23
  int v62; // w24
  __int64 v63; // x22
  __int64 v64; // x26
  unsigned int v65; // w0
  unsigned __int16 *v66; // x24
  unsigned int v67; // w26
  __int64 v68; // x2
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  char v85; // w0
  __int64 v86; // x0
  int vendor_reg_flags; // w0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  unsigned __int16 v96; // w6
  __int64 v97; // x6
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  __int64 v106; // x23
  __int64 v107; // x9
  __int64 v108; // x10
  unsigned __int64 v109; // x8
  __int64 v110; // x11
  int v111; // w14
  __int64 v112; // x15
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  unsigned int v121; // w8
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  const char *v130; // x2
  __int64 v131; // x0
  unsigned int updated; // w0
  __int64 v134; // [xsp+0h] [xbp-410h]
  __int64 v135; // [xsp+8h] [xbp-408h]
  __int64 v136; // [xsp+10h] [xbp-400h]
  __int64 v137; // [xsp+18h] [xbp-3F8h]
  __int64 v138; // [xsp+20h] [xbp-3F0h]
  __int64 v139; // [xsp+28h] [xbp-3E8h]
  __int64 v140; // [xsp+30h] [xbp-3E0h]
  __int64 v141; // [xsp+40h] [xbp-3D0h]
  int v142; // [xsp+48h] [xbp-3C8h]
  char v143; // [xsp+54h] [xbp-3BCh]
  int v144; // [xsp+58h] [xbp-3B8h]
  unsigned __int8 v145[4]; // [xsp+5Ch] [xbp-3B4h] BYREF
  unsigned int v146; // [xsp+60h] [xbp-3B0h] BYREF
  unsigned int v147; // [xsp+64h] [xbp-3ACh] BYREF
  _QWORD v148[13]; // [xsp+68h] [xbp-3A8h] BYREF
  _DWORD s[102]; // [xsp+D0h] [xbp-340h] BYREF
  _DWORD v150[102]; // [xsp+268h] [xbp-1A8h] BYREF
  __int64 v151; // [xsp+400h] [xbp-10h]

  v151 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v12 = *(__int64 **)(a1 + 24);
  memset(v148, 0, 102);
  v146 = 0;
  v145[0] = 1;
  if ( !v12 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: HDD context is NULL",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_cfg80211_update_acs_config");
    v19 = -22;
    goto LABEL_107;
  }
  qdf_trace_msg(0x33u, 8u, "%s: enter", v4, v5, v6, v7, v8, v9, v10, v11, "hdd_cfg80211_update_acs_config");
  v13 = *(_QWORD *)(a1 + 52832);
  if ( (unsigned int)policy_mgr_get_connection_count(*v12) != 2 )
    goto LABEL_21;
  if ( *(_DWORD *)(v13 + 2004) != 4 )
    goto LABEL_21;
  conn_info = policy_mgr_get_conn_info(&v146);
  if ( (policy_mgr_are_2_freq_on_same_mac(*v12, *((_DWORD *)conn_info + 1), *((_DWORD *)conn_info + 10)) & 1) == 0 )
    goto LABEL_21;
  if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v13 + 1468)) )
  {
    v15 = *(unsigned __int8 *)(v13 + 1448);
    *(_DWORD *)(v13 + 2004) = 1;
    if ( v15 )
    {
      v16 = 4 * v15;
      v17 = 0;
      v18 = 0;
      do
      {
        if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(*(_QWORD *)(v13 + 1440) + v17)) )
          *(_DWORD *)(*(_QWORD *)(v13 + 1440) + 4LL * v18++) = *(_DWORD *)(*(_QWORD *)(v13 + 1440) + v17);
        v17 += 4;
      }
      while ( v16 != v17 );
      goto LABEL_20;
    }
  }
  else
  {
    v20 = *(unsigned __int8 *)(v13 + 1448);
    *(_DWORD *)(v13 + 2004) = 2;
    if ( v20 )
    {
      v21 = 4 * v20;
      v22 = 0;
      v18 = 0;
      do
      {
        if ( wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(*(_QWORD *)(v13 + 1440) + v22))
          || wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(*(_QWORD *)(v13 + 1440) + v22)) )
        {
          *(_DWORD *)(*(_QWORD *)(v13 + 1440) + 4LL * v18++) = *(_DWORD *)(*(_QWORD *)(v13 + 1440) + v22);
        }
        v22 += 4;
      }
      while ( v21 != v22 );
      goto LABEL_20;
    }
  }
  LOBYTE(v18) = 0;
LABEL_20:
  *(_BYTE *)(v13 + 1448) = v18;
LABEL_21:
  v23 = *(_DWORD *)(*(_QWORD *)(a1 + 52832) + 2004LL);
  if ( v23 == 2 )
    v24 = 2;
  else
    v24 = 1;
  if ( v23 == 4 )
    v25 = 0;
  else
    v25 = v24;
  v144 = v25;
  v26 = _qdf_mem_malloc(0x198u, "hdd_cfg80211_update_acs_config", 3179);
  if ( !v26 )
  {
    v19 = -12;
    goto LABEL_107;
  }
  v27 = v26;
  if ( *(_QWORD *)(v13 + 1440) )
  {
    v28 = *(unsigned __int8 *)(v13 + 1448);
    v146 = 0;
    if ( !v28 )
      goto LABEL_57;
    v29 = 0;
    do
    {
      *(_DWORD *)(v26 + 4LL * v29) = *(_DWORD *)(*(_QWORD *)(v13 + 1440) + 4LL * v29);
      v30 = *(unsigned __int8 *)(v13 + 1448);
      v29 = ++v146;
    }
    while ( v146 < v30 );
    goto LABEL_58;
  }
  v31 = *(__int64 **)(a1 + 24);
  memset(v150, 0, sizeof(v150));
  v32 = *v31;
  v33 = v31[1];
  v147 = 0;
  if ( (unsigned int)policy_mgr_get_valid_chans(v32, v150, &v147) )
  {
    v42 = "%s: Failed to get channel list";
    goto LABEL_56;
  }
  if ( !v147 )
    goto LABEL_55;
  v43 = v144;
  v44 = a1;
  v30 = 0;
  v45 = 0;
  v46 = v150;
  v47 = v150;
  do
  {
    if ( v30 > 0x65 )
    {
      a1 = v44;
      goto LABEL_58;
    }
    if ( v43 == 2 )
    {
      if ( v45 > 0x65 )
      {
LABEL_111:
        __break(0x5512u);
        goto LABEL_112;
      }
      if ( (wlan_reg_is_5ghz_ch_freq(*v47) || wlan_reg_is_6ghz_chan_freq(*v47))
        && !wlan_reg_is_disable_for_pwrmode(v33, *v47, 0, v34, v35, v36, v37, v38, v39, v40, v41) )
      {
        v49 = &v150[v45];
        goto LABEL_52;
      }
LABEL_38:
      v43 = v144;
      goto LABEL_39;
    }
    if ( v43 == 1 )
    {
      if ( v45 >= 0x66 )
        goto LABEL_111;
      if ( wlan_reg_is_24ghz_ch_freq(*v47) )
      {
        is_disable_for_pwrmode = wlan_reg_is_disable_for_pwrmode(v33, *v47, 0, v34, v35, v36, v37, v38, v39, v40, v41);
        v49 = v47;
        if ( !is_disable_for_pwrmode )
LABEL_52:
          *(_DWORD *)(v27 + 4LL * v30++) = *v49;
      }
      goto LABEL_38;
    }
LABEL_39:
    ++v45;
    ++v47;
  }
  while ( v45 < v147 );
  a1 = v44;
  if ( v30 )
    goto LABEL_58;
LABEL_55:
  v42 = "%s: no valid channel found";
LABEL_56:
  qdf_trace_msg(0x33u, 2u, v42, v34, v35, v36, v37, v38, v39, v40, v41, "wlan_hdd_sap_get_valid_channellist");
LABEL_57:
  v30 = 0;
LABEL_58:
  v50 = _qdf_mem_malloc(20LL * v30, "hdd_cfg80211_update_acs_config", 3198);
  *(_QWORD *)(v13 + 2136) = v50;
  if ( !v50 )
  {
    v46 = nullptr;
    v19 = -12;
    goto LABEL_104;
  }
  v59 = *(_QWORD *)(a1 + 24);
  v60 = *(_QWORD *)(a1 + 52832);
  v61 = *(_QWORD *)(v59 + 16);
  v143 = a2;
  memset(v150, 0, 24);
  *(_DWORD *)(v60 + 2144) = v30;
  if ( v30 )
  {
    v141 = a1;
    v62 = 0;
    do
    {
      v63 = v62;
      v64 = *(_QWORD *)(v60 + 2136);
      v65 = wlan_reg_freq_to_chan(
              *(_QWORD *)(v59 + 8),
              *(_DWORD *)(v27 + 4LL * v62),
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58);
      if ( (_BYTE)v65 )
      {
        v66 = (unsigned __int16 *)(v64 + 20LL * v62);
        v67 = v65;
        *v66 = *(_DWORD *)(v27 + 4 * v63);
        *((_BYTE *)v66 + 10) = v65;
        *((_BYTE *)v66 + 11) = wlan_reg_get_channel_reg_power_for_freq(
                                 *(_QWORD *)(v59 + 8),
                                 *(_DWORD *)(v27 + 4 * v63),
                                 v51,
                                 v52,
                                 v53,
                                 v54,
                                 v55,
                                 v56,
                                 v57,
                                 v58);
        v66[6] = -25500;
        *((_BYTE *)v66 + 15) = 0;
        if ( *(_WORD *)(v60 + 1466) == 1 )
          v68 = 2;
        else
          v68 = *(_WORD *)(v60 + 1466) == 0;
        *((_BYTE *)v66 + 14) = wlan_hdd_find_opclass(v61, v67, v68);
        if ( wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(v27 + 4 * v63)) )
        {
          v77 = sap_phymode_is_eht(*(unsigned int *)(v60 + 320));
          if ( (v85 & 1) != 0 )
            wlan_reg_set_create_punc_bitmap((__int64)v150, 1);
          v86 = *(_QWORD *)(v59 + 8);
          v150[0] = *(unsigned __int16 *)(v60 + 1466);
          wlan_reg_set_channel_params_for_pwrmode(
            v86,
            *v66,
            0,
            (__int64)v150,
            0,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84);
          v66[8] = *(_WORD *)((char *)&v150[1] + 1);
        }
        *((_DWORD *)v66 + 1) = 0;
        vendor_reg_flags = cds_get_vendor_reg_flags(
                             *(_QWORD *)(v59 + 8),
                             *v66,
                             *(_WORD *)(v60 + 1466),
                             *(_BYTE *)(v60 + 1984) != 0,
                             *(_BYTE *)(v60 + 1985) != 0,
                             v69,
                             v70,
                             v71,
                             v72,
                             v73,
                             v74,
                             v75,
                             v76);
        v96 = v66[4];
        *((_DWORD *)v66 + 1) = vendor_reg_flags;
        if ( (vendor_reg_flags & 0x200) != 0 )
          v66[4] = v96 | 2;
        LODWORD(v137) = *((unsigned __int8 *)v66 + 14);
        LODWORD(v139) = *((unsigned __int8 *)v66 + 16);
        LODWORD(v140) = *((unsigned __int8 *)v66 + 17);
        LODWORD(v138) = *((unsigned __int8 *)v66 + 15);
        LODWORD(v136) = *((char *)v66 + 13);
        LODWORD(v135) = *((char *)v66 + 12);
        LODWORD(v134) = *((char *)v66 + 11);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: freq %d flags %d flagext %d ieee %d maxreg %d maxpw %d minpw %d regClass %d antenna %d seg0 %d seg1 %d",
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          "hdd_update_reg_chan_info",
          *v66,
          v134,
          v135,
          v136,
          v137,
          v138,
          v139,
          v140);
      }
      v62 = v63 + 1;
    }
    while ( v30 != (_DWORD)v63 + 1 );
    a1 = v141;
    v97 = ((4 * v30 + 7) & 0xFFFFFFFC) + 120 * v30 + 72;
  }
  else
  {
    v97 = 76;
  }
  LODWORD(v45) = *(_DWORD *)(*(_QWORD *)(a1 + 52832) + 1428LL);
  v46 = (_DWORD *)_cfg80211_alloc_event_skb(v12[3], a1 + 112, 103, 197, 0, 29, v97, 3264);
  if ( v46 )
  {
    v106 = *(unsigned __int8 *)(v13 + 1448);
    v142 = v45;
    if ( *(_BYTE *)(v13 + 1448) )
    {
      v107 = *(_QWORD *)(v13 + 1440);
      v108 = *(unsigned int *)(v13 + 1980);
      v109 = 0;
      v110 = v13 + 1876;
      do
      {
        if ( 4 * v109 > 0x197 )
          goto LABEL_114;
        v111 = *(_DWORD *)(v107 + 4 * v109);
        s[v109] = v111;
        if ( v109 > 0x65 )
          goto LABEL_114;
        *((_BYTE *)v148 + v109) = 0;
        if ( (_DWORD)v108 )
        {
          v112 = 0;
          while ( 1 )
          {
            if ( v112 == 102 )
              goto LABEL_111;
            if ( v111 == *(_DWORD *)(v110 + 4 * v112 - 408) )
              break;
            if ( v108 == ++v112 )
              goto LABEL_80;
          }
          *((_BYTE *)v148 + v109) = *(_BYTE *)(v110 + v112);
        }
LABEL_80:
        ++v109;
      }
      while ( v109 != v106 );
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: ACS PCL list: len: %d",
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        "hdd_cfg80211_update_acs_config",
        (unsigned int)v106);
      v121 = 0;
      v146 = 0;
      while ( v121 <= 0x65 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: channel_frequency: %u, weight: %u",
          v113,
          v114,
          v115,
          v116,
          v117,
          v118,
          v119,
          v120,
          "hdd_cfg80211_update_acs_config",
          (unsigned int)s[v121],
          *((unsigned __int8 *)v148 + v121));
        v121 = ++v146;
        if ( v146 >= (unsigned int)v106 )
          goto LABEL_92;
      }
LABEL_114:
      __break(1u);
    }
LABEL_92:
    if ( (unsigned int)wlan_mlme_get_external_acs_policy(*v12, v145) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: get_external_acs_policy failed, set default",
        v122,
        v123,
        v124,
        v125,
        v126,
        v127,
        v128,
        v129,
        "hdd_cfg80211_update_acs_config");
    LODWORD(v45) = v145[0];
    LOBYTE(v150[0]) = v143;
    if ( (unsigned int)nla_put(v46, 1, 1, v150)
      || (unsigned int)nla_put(v46, 3, 0, 0)
      || (unsigned int)nla_put(v46, 4, 0, 0)
      || (LOBYTE(v150[0]) = *(_BYTE *)(v13 + 1466), (unsigned int)nla_put(v46, 7, 1, v150))
      || (LOBYTE(v150[0]) = v144, (unsigned int)nla_put(v46, 8, 1, v150))
      || (v150[0] = v142, (unsigned int)nla_put(v46, 9, 4, v150))
      || (unsigned int)nla_put(v46, 10, 4 * v30, v27) )
    {
      v19 = -22;
      v130 = "%s: nla put fail";
      goto LABEL_103;
    }
    updated = hdd_cfg80211_update_pcl(v12, v46, (unsigned int)v106, s, v148);
    if ( updated || (updated = hdd_cfg80211_update_channel_info(v12, v46, v13 + 280)) != 0 )
    {
      v19 = updated;
      goto LABEL_104;
    }
LABEL_112:
    v150[0] = v45;
    v19 = nla_put(v46, 13, 4, v150);
    if ( !v19 )
    {
      _cfg80211_send_event_skb(v46, 3264);
      _qdf_mem_free(v27);
      _qdf_mem_free(*(_QWORD *)(v13 + 2136));
      goto LABEL_107;
    }
  }
  else
  {
    v19 = -12;
    v130 = "%s: wlan_cfg80211_vendor_event_alloc failed";
LABEL_103:
    qdf_trace_msg(0x33u, 2u, v130, v98, v99, v100, v101, v102, v103, v104, v105, "hdd_cfg80211_update_acs_config");
  }
LABEL_104:
  _qdf_mem_free(v27);
  v131 = *(_QWORD *)(v13 + 2136);
  if ( v131 )
    _qdf_mem_free(v131);
  sk_skb_reason_drop(0, v46, 2);
LABEL_107:
  _ReadStatusReg(SP_EL0);
  return v19;
}
