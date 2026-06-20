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
  _QWORD *v46; // x22
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
  __int64 v77; // x0
  int vendor_reg_flags; // w0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned __int16 v87; // w6
  __int64 v88; // x6
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int64 v97; // x23
  __int64 v98; // x9
  __int64 v99; // x10
  unsigned __int64 v100; // x8
  __int64 v101; // x11
  int v102; // w14
  __int64 v103; // x15
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  unsigned int v112; // w8
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  const char *v121; // x2
  __int64 v122; // x0
  unsigned int updated; // w0
  __int64 v125; // [xsp+0h] [xbp-410h]
  __int64 v126; // [xsp+8h] [xbp-408h]
  __int64 v127; // [xsp+10h] [xbp-400h]
  __int64 v128; // [xsp+18h] [xbp-3F8h]
  __int64 v129; // [xsp+20h] [xbp-3F0h]
  __int64 v130; // [xsp+28h] [xbp-3E8h]
  __int64 v131; // [xsp+30h] [xbp-3E0h]
  __int64 v132; // [xsp+40h] [xbp-3D0h]
  int v133; // [xsp+48h] [xbp-3C8h]
  char v134; // [xsp+54h] [xbp-3BCh]
  int v135; // [xsp+58h] [xbp-3B8h]
  unsigned __int8 v136[4]; // [xsp+5Ch] [xbp-3B4h] BYREF
  unsigned int v137; // [xsp+60h] [xbp-3B0h] BYREF
  unsigned int v138; // [xsp+64h] [xbp-3ACh] BYREF
  _QWORD v139[13]; // [xsp+68h] [xbp-3A8h] BYREF
  _DWORD s[102]; // [xsp+D0h] [xbp-340h] BYREF
  _QWORD v141[53]; // [xsp+268h] [xbp-1A8h] BYREF

  v141[51] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v12 = *(__int64 **)(a1 + 24);
  memset(v139, 0, 102);
  v137 = 0;
  v136[0] = 1;
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
    goto LABEL_105;
  }
  qdf_trace_msg(0x33u, 8u, "%s: enter", v4, v5, v6, v7, v8, v9, v10, v11, "hdd_cfg80211_update_acs_config");
  v13 = *(_QWORD *)(a1 + 52824);
  if ( (unsigned int)policy_mgr_get_connection_count(*v12) != 2 )
    goto LABEL_21;
  if ( *(_DWORD *)(v13 + 1996) != 4 )
    goto LABEL_21;
  conn_info = policy_mgr_get_conn_info(&v137);
  if ( (policy_mgr_are_2_freq_on_same_mac(*v12, *((_DWORD *)conn_info + 1), *((_DWORD *)conn_info + 10)) & 1) == 0 )
    goto LABEL_21;
  if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v13 + 1460)) )
  {
    v15 = *(unsigned __int8 *)(v13 + 1440);
    *(_DWORD *)(v13 + 1996) = 1;
    if ( v15 )
    {
      v16 = 4 * v15;
      v17 = 0;
      v18 = 0;
      do
      {
        if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(*(_QWORD *)(v13 + 1432) + v17)) )
          *(_DWORD *)(*(_QWORD *)(v13 + 1432) + 4LL * v18++) = *(_DWORD *)(*(_QWORD *)(v13 + 1432) + v17);
        v17 += 4;
      }
      while ( v16 != v17 );
      goto LABEL_20;
    }
  }
  else
  {
    v20 = *(unsigned __int8 *)(v13 + 1440);
    *(_DWORD *)(v13 + 1996) = 2;
    if ( v20 )
    {
      v21 = 4 * v20;
      v22 = 0;
      v18 = 0;
      do
      {
        if ( wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(*(_QWORD *)(v13 + 1432) + v22))
          || wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(*(_QWORD *)(v13 + 1432) + v22)) )
        {
          *(_DWORD *)(*(_QWORD *)(v13 + 1432) + 4LL * v18++) = *(_DWORD *)(*(_QWORD *)(v13 + 1432) + v22);
        }
        v22 += 4;
      }
      while ( v21 != v22 );
      goto LABEL_20;
    }
  }
  LOBYTE(v18) = 0;
LABEL_20:
  *(_BYTE *)(v13 + 1440) = v18;
LABEL_21:
  v23 = *(_DWORD *)(*(_QWORD *)(a1 + 52824) + 1996LL);
  if ( v23 == 2 )
    v24 = 2;
  else
    v24 = 1;
  if ( v23 == 4 )
    v25 = 0;
  else
    v25 = v24;
  v135 = v25;
  v26 = _qdf_mem_malloc(0x198u, "hdd_cfg80211_update_acs_config", 3179);
  if ( !v26 )
  {
    v19 = -12;
    goto LABEL_105;
  }
  v27 = v26;
  if ( *(_QWORD *)(v13 + 1432) )
  {
    v28 = *(unsigned __int8 *)(v13 + 1440);
    v137 = 0;
    if ( !v28 )
      goto LABEL_57;
    v29 = 0;
    do
    {
      *(_DWORD *)(v26 + 4LL * v29) = *(_DWORD *)(*(_QWORD *)(v13 + 1432) + 4LL * v29);
      v30 = *(unsigned __int8 *)(v13 + 1440);
      v29 = v137 + 1;
      v137 = v29;
    }
    while ( v29 < v30 );
    goto LABEL_58;
  }
  v31 = *(__int64 **)(a1 + 24);
  memset(v141, 0, 0x198u);
  v32 = *v31;
  v33 = v31[1];
  v138 = 0;
  if ( (unsigned int)policy_mgr_get_valid_chans(v32, v141, &v138) )
  {
    v42 = "%s: Failed to get channel list";
    goto LABEL_56;
  }
  if ( !v138 )
    goto LABEL_55;
  v43 = v135;
  v44 = a1;
  v30 = 0;
  v45 = 0;
  v46 = v141;
  v47 = (unsigned int *)v141;
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
LABEL_109:
        __break(0x5512u);
        goto LABEL_110;
      }
      if ( (wlan_reg_is_5ghz_ch_freq(*v47) || wlan_reg_is_6ghz_chan_freq(*v47))
        && !wlan_reg_is_disable_for_pwrmode(v33, *v47, 0, v34, v35, v36, v37, v38, v39, v40, v41) )
      {
        v49 = (unsigned int *)v141 + v45;
        goto LABEL_52;
      }
LABEL_38:
      v43 = v135;
      goto LABEL_39;
    }
    if ( v43 == 1 )
    {
      if ( v45 >= 0x66 )
        goto LABEL_109;
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
  while ( v45 < v138 );
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
  *(_QWORD *)(v13 + 2120) = v50;
  if ( !v50 )
  {
    v46 = nullptr;
    v19 = -12;
    goto LABEL_102;
  }
  v59 = *(_QWORD *)(a1 + 24);
  v60 = *(_QWORD *)(a1 + 52824);
  v134 = a2;
  v61 = *(_QWORD *)(v59 + 16);
  v141[0] = 0;
  v141[1] = 0;
  *(_DWORD *)(v60 + 2128) = v30;
  if ( v30 )
  {
    v132 = a1;
    v62 = 0;
    do
    {
      v63 = v62;
      v64 = *(_QWORD *)(v60 + 2120);
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
        if ( *(_WORD *)(v60 + 1458) == 1 )
          v68 = 2;
        else
          v68 = *(_WORD *)(v60 + 1458) == 0;
        *((_BYTE *)v66 + 14) = wlan_hdd_find_opclass(v61, v67, v68);
        if ( wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(v27 + 4 * v63)) )
        {
          v77 = *(_QWORD *)(v59 + 8);
          LODWORD(v141[0]) = *(unsigned __int16 *)(v60 + 1458);
          wlan_reg_set_channel_params_for_pwrmode(
            v77,
            *v66,
            0,
            (__int64)v141,
            0,
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76);
          v66[8] = *(_WORD *)((char *)v141 + 5);
        }
        *((_DWORD *)v66 + 1) = 0;
        vendor_reg_flags = cds_get_vendor_reg_flags(
                             *(_QWORD *)(v59 + 8),
                             *v66,
                             *(_WORD *)(v60 + 1458),
                             *(_BYTE *)(v60 + 1976) != 0,
                             *(_BYTE *)(v60 + 1977) != 0,
                             v69,
                             v70,
                             v71,
                             v72,
                             v73,
                             v74,
                             v75,
                             v76);
        v87 = v66[4];
        *((_DWORD *)v66 + 1) = vendor_reg_flags;
        if ( (vendor_reg_flags & 0x200) != 0 )
          v66[4] = v87 | 2;
        LODWORD(v128) = *((unsigned __int8 *)v66 + 14);
        LODWORD(v130) = *((unsigned __int8 *)v66 + 16);
        LODWORD(v131) = *((unsigned __int8 *)v66 + 17);
        LODWORD(v129) = *((unsigned __int8 *)v66 + 15);
        LODWORD(v127) = *((char *)v66 + 13);
        LODWORD(v126) = *((char *)v66 + 12);
        LODWORD(v125) = *((char *)v66 + 11);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: freq %d flags %d flagext %d ieee %d maxreg %d maxpw %d minpw %d regClass %d antenna %d seg0 %d seg1 %d",
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          "hdd_update_reg_chan_info",
          *v66,
          v125,
          v126,
          v127,
          v128,
          v129,
          v130,
          v131);
      }
      v62 = v63 + 1;
    }
    while ( v30 != (_DWORD)v63 + 1 );
    a1 = v132;
    v88 = ((4 * v30 + 7) & 0xFFFFFFFC) + 120 * v30 + 72;
  }
  else
  {
    v88 = 76;
  }
  LODWORD(v45) = *(_DWORD *)(*(_QWORD *)(a1 + 52824) + 1420LL);
  v46 = (_QWORD *)_cfg80211_alloc_event_skb(v12[3], a1 + 112, 103, 197, 0, 29, v88, 3264);
  if ( v46 )
  {
    v97 = *(unsigned __int8 *)(v13 + 1440);
    v133 = v45;
    if ( *(_BYTE *)(v13 + 1440) )
    {
      v98 = *(_QWORD *)(v13 + 1432);
      v99 = *(unsigned int *)(v13 + 1972);
      v100 = 0;
      v101 = v13 + 1868;
      do
      {
        if ( 4 * v100 > 0x197 )
          goto LABEL_112;
        v102 = *(_DWORD *)(v98 + 4 * v100);
        s[v100] = v102;
        if ( v100 > 0x65 )
          goto LABEL_112;
        *((_BYTE *)v139 + v100) = 0;
        if ( (_DWORD)v99 )
        {
          v103 = 0;
          while ( 1 )
          {
            if ( v103 == 102 )
              goto LABEL_109;
            if ( v102 == *(_DWORD *)(v101 + 4 * v103 - 408) )
              break;
            if ( v99 == ++v103 )
              goto LABEL_78;
          }
          *((_BYTE *)v139 + v100) = *(_BYTE *)(v101 + v103);
        }
LABEL_78:
        ++v100;
      }
      while ( v100 != v97 );
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: ACS PCL list: len: %d",
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        "hdd_cfg80211_update_acs_config",
        (unsigned int)v97);
      v112 = 0;
      v137 = 0;
      while ( v112 <= 0x65 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: channel_frequency: %u, weight: %u",
          v104,
          v105,
          v106,
          v107,
          v108,
          v109,
          v110,
          v111,
          "hdd_cfg80211_update_acs_config",
          (unsigned int)s[v112],
          *((unsigned __int8 *)v139 + v112));
        v112 = ++v137;
        if ( v137 >= (unsigned int)v97 )
          goto LABEL_90;
      }
LABEL_112:
      __break(1u);
    }
LABEL_90:
    if ( (unsigned int)wlan_mlme_get_external_acs_policy(*v12, v136) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: get_external_acs_policy failed, set default",
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        v120,
        "hdd_cfg80211_update_acs_config");
    LODWORD(v45) = v136[0];
    LOBYTE(v141[0]) = v134;
    if ( (unsigned int)nla_put(v46, 1, 1, v141)
      || (unsigned int)nla_put(v46, 3, 0, 0)
      || (unsigned int)nla_put(v46, 4, 0, 0)
      || (LOBYTE(v141[0]) = *(_BYTE *)(v13 + 1458), (unsigned int)nla_put(v46, 7, 1, v141))
      || (LOBYTE(v141[0]) = v135, (unsigned int)nla_put(v46, 8, 1, v141))
      || (LODWORD(v141[0]) = v133, (unsigned int)nla_put(v46, 9, 4, v141))
      || (unsigned int)nla_put(v46, 10, 4 * v30, v27) )
    {
      v19 = -22;
      v121 = "%s: nla put fail";
      goto LABEL_101;
    }
    updated = hdd_cfg80211_update_pcl(v12, v46, (unsigned int)v97, s, v139);
    if ( updated || (updated = hdd_cfg80211_update_channel_info(v12, v46, v13 + 280)) != 0 )
    {
      v19 = updated;
      goto LABEL_102;
    }
LABEL_110:
    LODWORD(v141[0]) = v45;
    v19 = nla_put(v46, 13, 4, v141);
    if ( !v19 )
    {
      _cfg80211_send_event_skb(v46, 3264);
      _qdf_mem_free(v27);
      _qdf_mem_free(*(_QWORD *)(v13 + 2120));
      goto LABEL_105;
    }
  }
  else
  {
    v19 = -12;
    v121 = "%s: wlan_cfg80211_vendor_event_alloc failed";
LABEL_101:
    qdf_trace_msg(0x33u, 2u, v121, v89, v90, v91, v92, v93, v94, v95, v96, "hdd_cfg80211_update_acs_config");
  }
LABEL_102:
  _qdf_mem_free(v27);
  v122 = *(_QWORD *)(v13 + 2120);
  if ( v122 )
    _qdf_mem_free(v122);
  sk_skb_reason_drop(0, v46, 2);
LABEL_105:
  _ReadStatusReg(SP_EL0);
  return v19;
}
