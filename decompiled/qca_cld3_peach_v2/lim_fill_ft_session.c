__int64 __fastcall lim_fill_ft_session(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4, unsigned int a5)
{
  __int64 v10; // x0
  __int64 v11; // x19
  char *v12; // x27
  char v13; // w8
  char v14; // w8
  int v15; // w8
  unsigned __int16 ielen_from_bss_description; // w0
  size_t v17; // x2
  size_t v18; // x2
  size_t v19; // x2
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  char v28; // w0
  unsigned int v29; // w26
  char v30; // w24
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  int v39; // w9
  unsigned int best_6g_power_type; // w23
  unsigned __int64 v41; // x8
  __int64 v42; // x10
  unsigned int v43; // w11
  unsigned int v44; // w8
  char v45; // w9
  bool v46; // w9
  bool is_24ghz_ch_freq; // w0
  __int64 v48; // x8
  __int64 v49; // x2
  char v50; // w8
  char cb_mode_for_freq; // w0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int v60; // w8
  __int64 v61; // x9
  char v62; // w8
  _BYTE *v63; // x8
  __int16 v64; // w8
  __int64 v65; // x0
  __int64 cmpt_obj; // x0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x24
  unsigned int v76; // w0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned int v85; // w3
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  const char *v94; // x2
  int v95; // w1
  __int64 v96; // x0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  unsigned int v105; // w23
  char max_tx_power; // w0
  unsigned __int8 channel_reg_power_for_freq; // w0
  unsigned __int8 v108; // w8
  int v109; // w10
  unsigned int v110; // w0
  int v112; // w8
  __int16 v113; // w2
  char v114; // w9
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  int v123; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v124[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v125[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v126[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v127; // [xsp+18h] [xbp-8h]

  v127 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = _qdf_mem_malloc(0x1A08u, "lim_fill_ft_session", 630);
  if ( v10 )
  {
    v11 = v10;
    v12 = (char *)(a3 + 7024);
    v13 = *(_BYTE *)(a3 + 7024) & 0xFD | (2 * ((*(_BYTE *)(a4 + 7024) & 2) != 0));
    *(_BYTE *)(a3 + 7024) = v13;
    v14 = v13 & 0xFE | *(_BYTE *)(a4 + 7024) & 1;
    *(_BYTE *)(a3 + 7024) = v14;
    *(_BYTE *)(a3 + 7024) = v14 & 0xFB | *(_BYTE *)(a4 + 7024) & 4;
    *(_DWORD *)(a3 + 7028) = *(_DWORD *)(a4 + 7028);
    *(_BYTE *)(a3 + 7364) = *(_BYTE *)(a4 + 7364);
    v15 = *(_DWORD *)(a4 + 156);
    *(_QWORD *)(a3 + 112) = 0;
    *(_DWORD *)(a3 + 156) = v15;
    *(_BYTE *)(a3 + 10) = *(_BYTE *)(a4 + 10);
    ielen_from_bss_description = wlan_get_ielen_from_bss_description(a2);
    lim_extract_ap_capabilities((int)a1, a2 + 104, ielen_from_bss_description, (void *)v11);
    qdf_mem_set((void *)(a3 + 1628), 0x14u, 0);
    if ( *(_BYTE *)(v11 + 6640) )
      qdf_mem_copy((void *)(a3 + 1628), (const void *)(v11 + 6640), 0x14u);
    v17 = *(unsigned __int8 *)(v11 + 46);
    *(_BYTE *)(a3 + 252) = v17;
    qdf_mem_copy((void *)(a3 + 253), (const void *)(v11 + 47), v17);
    v18 = *(unsigned __int8 *)(v11 + 59);
    *(_BYTE *)(a3 + 265) = v18;
    qdf_mem_copy((void *)(a3 + 266), (const void *)(v11 + 60), v18);
    v19 = *(unsigned __int8 *)(v11 + 12);
    *(_BYTE *)(a3 + 36) = v19;
    qdf_mem_copy((void *)(a3 + 37), (const void *)(v11 + 13), v19);
    v28 = wlan_reg_freq_to_chan(a1[2704], *(_DWORD *)(a2 + 28), v20, v21, v22, v23, v24, v25, v26, v27);
    v29 = *(_DWORD *)(a2 + 28);
    v30 = v28;
    *(_DWORD *)(a3 + 188) = v29;
    *(_DWORD *)(a3 + 284) = v29;
    if ( wlan_reg_is_6ghz_chan_freq(v29) )
    {
      v39 = 2;
    }
    else if ( wlan_reg_is_5ghz_ch_freq(v29) )
    {
      v39 = 1;
    }
    else if ( wlan_reg_is_24ghz_ch_freq(v29) )
    {
      v39 = 0;
    }
    else
    {
      v39 = 3;
    }
    *(_DWORD *)(a3 + 168) = v39;
    v41 = *(_QWORD *)(a4 + 7432);
    if ( v41 && (*(_BYTE *)(a1[1] + 1714LL) & 1) == 0 )
    {
      LODWORD(v41) = *(_DWORD *)(v41 + 4);
      goto LABEL_42;
    }
    if ( a5 )
    {
      if ( a5 - 21 >= 0xA )
      {
        if ( a5 - 11 >= 0xA )
        {
          if ( a5 - 5 >= 6 )
          {
            if ( a5 - 31 >= 0xA )
            {
              if ( a5 > 4 )
                LOBYTE(v41) = 0;
              else
                v41 = 0x604030200uLL >> (8 * (unsigned __int8)a5);
            }
            else
            {
              LOBYTE(v41) = 12;
            }
            goto LABEL_42;
          }
LABEL_34:
          LOBYTE(v41) = 5;
          goto LABEL_42;
        }
LABEL_41:
        LOBYTE(v41) = 8;
        goto LABEL_42;
      }
LABEL_36:
      LOBYTE(v41) = 10;
      goto LABEL_42;
    }
    v42 = a1[1];
    v43 = *(_DWORD *)(v42 + 5964);
    if ( v39 )
      LOBYTE(v41) = 2;
    else
      LOBYTE(v41) = 4;
    if ( v43 > 0xB )
    {
LABEL_42:
      *(_BYTE *)(a3 + 154) = v41;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: dot11mode: %d bss_phymode %d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "lim_fill_ft_session",
        (unsigned __int8)v41,
        a5);
      v44 = *(unsigned __int8 *)(a3 + 154);
      if ( v44 - 8 >= 6 && *(_BYTE *)(a3 + 154) )
        goto LABEL_51;
      if ( !*(_BYTE *)(v11 + 2484) || *(__int16 *)(v11 + 2490) == -1 || *(__int16 *)(v11 + 2494) == -1 )
      {
        v45 = *(_BYTE *)(v11 + 2544);
        if ( v45 )
        {
          if ( *(__int16 *)(v11 + 2550) == -1 )
          {
LABEL_51:
            v45 = 0;
            goto LABEL_52;
          }
          v45 = *(__int16 *)(v11 + 2554) != -1;
        }
      }
      else
      {
        v45 = 1;
      }
LABEL_52:
      *(_BYTE *)(a3 + 7170) = v45;
      v46 = (v44 - 7 < 7 || v44 == 5 || !v44) && *(_BYTE *)(v11 + 1200) != 0;
      *(_BYTE *)(a3 + 155) = v46;
      if ( (v44 - 10 < 4 || !v44) && *(_BYTE *)(v11 + 2640) )
      {
        lim_update_session_he_capable(a1, a3);
        lim_copy_join_req_he_cap(a3);
        v44 = *(unsigned __int8 *)(a3 + 154);
      }
      if ( v44 <= 0xD && ((1 << v44) & 0x3001) != 0 && *(_BYTE *)(v11 + 2740) )
      {
        lim_update_session_eht_capable(a3, 1);
        lim_copy_join_req_eht_cap(a3);
      }
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 284));
      v48 = 21594;
      if ( is_24ghz_ch_freq )
        v48 = 21584;
      v49 = *(unsigned int *)(a3 + 284);
      v50 = *((_BYTE *)a1 + v48);
      *(_BYTE *)(a3 + 8652) = v50;
      *(_BYTE *)(a3 + 8635) = v50;
      cb_mode_for_freq = lim_get_cb_mode_for_freq(a1, a3, v49);
      v60 = *(unsigned __int8 *)(v11 + 1260);
      if ( *(_BYTE *)(v11 + 1260) )
      {
        if ( cb_mode_for_freq && (*(_BYTE *)(v11 + 1262) & 4) != 0 )
          v60 = (*(unsigned __int16 *)(v11 + 1201) >> 1) & 1;
        else
          v60 = 0;
      }
      *(_BYTE *)(a3 + 160) = v60;
      *(_BYTE *)(a3 + 161) = v60;
      if ( *(_BYTE *)(v11 + 2484)
        && *(__int16 *)(v11 + 2490) != -1
        && *(__int16 *)(v11 + 2494) != -1
        && *(_BYTE *)(v11 + 2500)
        && *(_BYTE *)(a3 + 7170)
        || *(_BYTE *)(v11 + 2544)
        && *(__int16 *)(v11 + 2550) != -1
        && *(__int16 *)(v11 + 2554) != -1
        && *(_BYTE *)(v11 + 2560)
        && *(_BYTE *)(a3 + 7170) )
      {
        *(_BYTE *)(a3 + 7173) = 1;
        if ( v60 )
        {
          *(_DWORD *)(a3 + 7176) = 1;
          if ( *(_BYTE *)(v11 + 2501) )
          {
            v61 = 7186;
            *(_DWORD *)(a3 + 7176) = *(unsigned __int8 *)(v11 + 2501) + 1;
            *(_BYTE *)(a3 + 7174) = *(_BYTE *)(v11 + 2502);
            v62 = *(_BYTE *)(v11 + 2503);
            goto LABEL_93;
          }
          if ( *(_BYTE *)(v11 + 2561) )
          {
            v61 = 7186;
            *(_DWORD *)(a3 + 7176) = *(unsigned __int8 *)(v11 + 2561) + 1;
            *(_BYTE *)(a3 + 7174) = *(_BYTE *)(v11 + 2562);
            v62 = *(_BYTE *)(v11 + 2563);
LABEL_93:
            *(_BYTE *)(a3 + v61) = v62;
            v63 = *(_BYTE **)(a4 + 16);
            *(_BYTE *)(a3 + 30) = v63[74];
            *(_BYTE *)(a3 + 31) = v63[75];
            *(_BYTE *)(a3 + 32) = v63[76];
            *(_BYTE *)(a3 + 33) = v63[77];
            *(_BYTE *)(a3 + 34) = v63[78];
            *(_BYTE *)(a3 + 35) = v63[79];
            *(_BYTE *)(a3 + 182) = *(_BYTE *)(a2 + 2);
            *(_BYTE *)(a3 + 183) = *(_BYTE *)(a2 + 3);
            *(_BYTE *)(a3 + 184) = *(_BYTE *)(a2 + 4);
            *(_BYTE *)(a3 + 185) = *(_BYTE *)(a2 + 5);
            *(_BYTE *)(a3 + 186) = *(_BYTE *)(a2 + 6);
            *(_BYTE *)(a3 + 187) = *(_BYTE *)(a2 + 7);
            *(_BYTE *)(a3 + 8618) = *(_BYTE *)(a4 + 24);
            *(_BYTE *)(a3 + 8619) = *(_BYTE *)(a4 + 25);
            *(_BYTE *)(a3 + 8620) = *(_BYTE *)(a4 + 26);
            *(_BYTE *)(a3 + 8621) = *(_BYTE *)(a4 + 27);
            *(_BYTE *)(a3 + 8622) = *(_BYTE *)(a4 + 28);
            *(_BYTE *)(a3 + 8623) = *(_BYTE *)(a4 + 29);
            *(_WORD *)(a3 + 7158) = *(_WORD *)(a2 + 16);
            LODWORD(v63) = *(_DWORD *)(a4 + 92);
            *(_WORD *)(a3 + 248) = 1;
            *(_DWORD *)(a3 + 92) = (_DWORD)v63;
            *(_DWORD *)(a3 + 96) = *(_DWORD *)(a2 + 20);
            if ( (_DWORD)v63 )
              qdf_trace_msg(
                0x35u,
                3u,
                "%s: Invalid bss type",
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                "lim_fill_ft_session");
            else
              *(_DWORD *)(a3 + 88) = 2;
            v64 = *(_WORD *)(a2 + 18);
            *(_WORD *)(a3 + 176) = v64;
            *(_WORD *)(a3 + 234) = v64;
            if ( *(_BYTE *)(a1[1] + 1304LL) == 1 && (v64 & 0x400) != 0 )
              *(_BYTE *)(a3 + 250) = 1;
            v65 = *(_QWORD *)(a4 + 16);
            v126[0] = 0;
            v125[0] = 0;
            v124[0] = 0;
            v123 = 0;
            cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v65, v52, v53, v54, v55, v56, v57, v58, v59);
            if ( !cmpt_obj )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: vdev component object is NULL",
                v67,
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                "lim_fill_session_power_info");
              best_6g_power_type = 16;
LABEL_107:
              v94 = "%s: Failed to fill power info in ft session";
              goto LABEL_123;
            }
            v75 = cmpt_obj;
            v76 = wlan_get_ielen_from_bss_description(a2);
            lim_extract_ap_capability(a1, a2 + 104, v76, a3 + 178, v126, v125, a3, v124);
            *(_BYTE *)(v75 + 948) = v124[0] ^ 1;
            if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 28)) )
            {
              v85 = *(unsigned __int8 *)(a3 + 10068);
              if ( v85 == 2 )
              {
                if ( (wlan_reg_is_indoor_ap_detected(a1[2704], v77, v78, v79, v80, v81, v82, v83, v84) & 1) != 0 )
                {
                  v85 = 3;
                  *(_BYTE *)(a3 + 10068) = 3;
                }
                else
                {
                  v85 = *(unsigned __int8 *)(a3 + 10068);
                }
              }
              best_6g_power_type = wlan_reg_get_best_6g_power_type(
                                     a1[2703],
                                     a1[2704],
                                     (unsigned int *)&v123,
                                     v85,
                                     *(_DWORD *)(a2 + 28),
                                     v77,
                                     v78,
                                     v79,
                                     v80,
                                     v81,
                                     v82,
                                     v83,
                                     v84);
              if ( best_6g_power_type )
                goto LABEL_107;
              v95 = v123;
              v96 = *(_QWORD *)(a3 + 16);
              *(_BYTE *)(a3 + 10069) = v123;
              mlme_set_best_6g_power_type(v96, v95, v86, v87, v88, v89, v90, v91, v92, v93);
            }
            if ( (wlan_reg_is_ext_tpc_supported(a1[2703], v77, v78, v79, v80, v81, v82, v83, v84) & 1) != 0 )
            {
              v105 = 0;
              *(_BYTE *)(v75 + 568) = v125[0];
              max_tx_power = *(_BYTE *)(a3 + 7032);
              if ( max_tx_power )
              {
LABEL_121:
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Reg max: %d local pwr: %d, max tx pwr: %d",
                  v97,
                  v98,
                  v99,
                  v100,
                  v101,
                  v102,
                  v103,
                  v104,
                  "lim_fill_session_power_info",
                  v105,
                  v125[0],
                  (unsigned int)max_tx_power);
                v110 = lim_set_session_channel_params(a1, a3);
                if ( !v110 )
                {
                  *(_BYTE *)(a3 + 236) = *(_BYTE *)(a3 + 178);
                  *(_BYTE *)(a3 + 7041) = *(_BYTE *)(a4 + 7041);
                  *(_BYTE *)(a3 + 8624) = *(_BYTE *)(v11 + 2574);
                  if ( !wlan_cm_is_vdev_roam_sync_inprogress(
                          *(_QWORD *)(a4 + 16),
                          v86,
                          v87,
                          v88,
                          v89,
                          v90,
                          v91,
                          v92,
                          v93) )
                  {
                    v112 = *(_DWORD *)(a3 + 80);
                    v113 = *(_WORD *)(a3 + 8);
                    *(_DWORD *)(a3 + 80) = 6;
                    *(_DWORD *)(a3 + 84) = v112;
                    qdf_trace(53, 1u, v113, 6);
                  }
                  v114 = *v12;
                  *(_DWORD *)(a3 + 424) = *(_DWORD *)(a4 + 424);
                  *v12 = v114 & 0xEF | *(_BYTE *)(a4 + 7024) & 0x10;
                  lim_init_obss_params(a1, a3);
                  *(_BYTE *)(a3 + 8653) = 1;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: FT enable smps: %d mode: %d supported nss 1x1: %d",
                    v115,
                    v116,
                    v117,
                    v118,
                    v119,
                    v120,
                    v121,
                    v122,
                    "lim_fill_ft_session",
                    *(unsigned __int8 *)(a1[1] + 1300LL),
                    *(unsigned __int8 *)(a1[1] + 1301LL),
                    1);
                  best_6g_power_type = 0;
                  goto LABEL_124;
                }
                best_6g_power_type = v110;
                v94 = "%s: Failed to set session channel params";
LABEL_123:
                qdf_trace_msg(0x35u, 2u, v94, v86, v87, v88, v89, v90, v91, v92, v93, "lim_fill_ft_session");
LABEL_124:
                _qdf_mem_free(v11);
                goto LABEL_125;
              }
            }
            else
            {
              channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(
                                             a1[2704],
                                             *(_DWORD *)(a3 + 284),
                                             v97,
                                             v98,
                                             v99,
                                             v100,
                                             v101,
                                             v102,
                                             v103,
                                             v104);
              v108 = v125[0];
              LOBYTE(v105) = channel_reg_power_for_freq;
              if ( v124[0] )
                v108 = channel_reg_power_for_freq - v125[0];
              v109 = v108;
              if ( !v108 )
                v108 = channel_reg_power_for_freq;
              if ( !v109 || v124[0] )
                v125[0] = v108;
              *(_BYTE *)(v75 + 552) = channel_reg_power_for_freq;
              *(_BYTE *)(v75 + 568) = v108;
              *(_DWORD *)(v75 + 572) = *(_DWORD *)(a3 + 284);
              max_tx_power = lim_get_max_tx_power(a1, v75);
              v105 = (char)v105;
              *(_BYTE *)(a3 + 7032) = max_tx_power;
              *(_BYTE *)(a3 + 10042) = max_tx_power;
              if ( max_tx_power )
                goto LABEL_121;
            }
            max_tx_power = wlan_reg_get_channel_reg_power_for_freq(
                             a1[2704],
                             *(_DWORD *)(a3 + 284),
                             v97,
                             v98,
                             v99,
                             v100,
                             v101,
                             v102,
                             v103,
                             v104);
            *(_BYTE *)(a3 + 7032) = max_tx_power;
            goto LABEL_121;
          }
          goto LABEL_87;
        }
      }
      else
      {
        *(_BYTE *)(a3 + 7173) = 0;
        if ( v60 )
        {
          *(_DWORD *)(a3 + 7176) = 1;
LABEL_87:
          if ( (*(_DWORD *)(v11 + 1262) & 3) == 3 )
          {
            v62 = v30 - 2;
            v61 = 7174;
            goto LABEL_93;
          }
          if ( (*(_DWORD *)(v11 + 1262) & 3) == 1 )
          {
            v62 = v30 + 2;
            v61 = 7174;
            goto LABEL_93;
          }
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: Invalid sec ch offset",
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            "lim_fill_ft_session");
        }
      }
      v62 = 0;
      v61 = 7186;
      *(_DWORD *)(a3 + 7176) = 0;
      *(_BYTE *)(a3 + 7174) = 0;
      goto LABEL_93;
    }
    if ( ((1 << v43) & 0xC01) != 0 )
    {
      if ( *(_BYTE *)(v11 + 2640) )
        goto LABEL_36;
      if ( (*(_BYTE *)(v11 + 2484) || *(_BYTE *)(v11 + 2540)) && (v39 || (*(_BYTE *)(v42 + 2875) & 1) != 0) )
        goto LABEL_41;
      if ( *(_BYTE *)(v11 + 1200) )
        goto LABEL_34;
    }
    else
    {
      if ( ((1 << v43) & 0xA0) != 0 )
        goto LABEL_33;
      if ( ((1 << v43) & 0x300) == 0 )
        goto LABEL_42;
    }
    if ( (*(_BYTE *)(v11 + 2484) || *(_BYTE *)(v11 + 2540)) && (v39 || (*(_BYTE *)(v42 + 2875) & 1) != 0) )
      goto LABEL_41;
    if ( *(_BYTE *)(v11 + 1200) )
      goto LABEL_34;
LABEL_33:
    if ( !*(_BYTE *)(v11 + 1200) )
      goto LABEL_42;
    goto LABEL_34;
  }
  best_6g_power_type = 2;
LABEL_125:
  _ReadStatusReg(SP_EL0);
  return best_6g_power_type;
}
