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
  __int64 v41; // x8
  int v42; // w8
  __int64 v43; // x10
  unsigned int v44; // w11
  int v45; // w8
  char v46; // w9
  bool v47; // w9
  bool is_24ghz_ch_freq; // w0
  __int64 v49; // x8
  __int64 v50; // x2
  char v51; // w8
  char cb_mode_for_freq; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  int v61; // w8
  _BYTE *v62; // x8
  __int16 v63; // w8
  __int64 v64; // x0
  __int64 cmpt_obj; // x0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x24
  unsigned int v75; // w0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned int v84; // w3
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  const char *v93; // x2
  int v94; // w1
  __int64 v95; // x0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  unsigned int v104; // w23
  char max_tx_power; // w0
  unsigned __int8 channel_reg_power_for_freq; // w0
  unsigned __int8 v107; // w8
  int v108; // w10
  unsigned int v109; // w0
  int v111; // w8
  __int16 v112; // w2
  char v113; // w9
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  int v122; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v123[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v124[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v125[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v126; // [xsp+18h] [xbp-8h]

  v126 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = _qdf_mem_malloc(0xD80u, "lim_fill_ft_session", 630);
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
    if ( *(_BYTE *)(v11 + 3436) )
      qdf_mem_copy((void *)(a3 + 1628), (const void *)(v11 + 3436), 0x14u);
    v17 = *(unsigned __int8 *)(v11 + 46);
    *(_BYTE *)(a3 + 252) = v17;
    qdf_mem_copy((void *)(a3 + 253), (const void *)(v11 + 47), v17);
    v18 = *(unsigned __int8 *)(v11 + 59);
    *(_BYTE *)(a3 + 265) = v18;
    qdf_mem_copy((void *)(a3 + 266), (const void *)(v11 + 60), v18);
    v19 = *(unsigned __int8 *)(v11 + 12);
    *(_BYTE *)(a3 + 36) = v19;
    qdf_mem_copy((void *)(a3 + 37), (const void *)(v11 + 13), v19);
    v28 = wlan_reg_freq_to_chan(a1[2695], *(_DWORD *)(a2 + 28), v20, v21, v22, v23, v24, v25, v26, v27);
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
    if ( v41 && (*(_BYTE *)(a1[1] + 1510LL) & 1) == 0 )
    {
      v42 = *(_DWORD *)(v41 + 4);
      goto LABEL_42;
    }
    if ( a5 )
    {
      if ( a5 - 21 >= 0xA )
      {
        if ( a5 - 11 >= 0xA )
        {
          if ( a5 > 0xA )
            LOBYTE(v42) = 0;
          else
            LOBYTE(v42) = byte_A095F0[a5 - 1];
          goto LABEL_42;
        }
LABEL_41:
        LOBYTE(v42) = 8;
        goto LABEL_42;
      }
LABEL_35:
      LOBYTE(v42) = 10;
      goto LABEL_42;
    }
    v43 = a1[1];
    v44 = *(_DWORD *)(v43 + 5748);
    if ( v39 )
      LOBYTE(v42) = 2;
    else
      LOBYTE(v42) = 4;
    if ( v44 > 0xB )
    {
LABEL_42:
      *(_BYTE *)(a3 + 154) = v42;
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
        (unsigned __int8)v42,
        a5);
      v45 = *(unsigned __int8 *)(a3 + 154);
      if ( (unsigned int)(v45 - 8) >= 6 && *(_BYTE *)(a3 + 154) )
        goto LABEL_51;
      if ( !*(_BYTE *)(v11 + 2484) || *(__int16 *)(v11 + 2490) == -1 || *(__int16 *)(v11 + 2494) == -1 )
      {
        v46 = *(_BYTE *)(v11 + 2544);
        if ( v46 )
        {
          if ( *(__int16 *)(v11 + 2550) == -1 )
          {
LABEL_51:
            v46 = 0;
            goto LABEL_52;
          }
          v46 = *(__int16 *)(v11 + 2554) != -1;
        }
      }
      else
      {
        v46 = 1;
      }
LABEL_52:
      *(_BYTE *)(a3 + 7170) = v46;
      v47 = ((unsigned int)(v45 - 7) < 7 || v45 == 5 || !v45) && *(_BYTE *)(v11 + 1200) != 0;
      *(_BYTE *)(a3 + 155) = v47;
      if ( ((unsigned int)(v45 - 10) < 4 || !v45) && *(_BYTE *)(v11 + 2640) )
      {
        lim_update_session_he_capable(a1, a3);
        lim_copy_join_req_he_cap(a3);
      }
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 284));
      v49 = 21522;
      if ( is_24ghz_ch_freq )
        v49 = 21512;
      v50 = *(unsigned int *)(a3 + 284);
      v51 = *((_BYTE *)a1 + v49);
      *(_BYTE *)(a3 + 8652) = v51;
      *(_BYTE *)(a3 + 8635) = v51;
      cb_mode_for_freq = lim_get_cb_mode_for_freq(a1, a3, v50);
      v61 = *(unsigned __int8 *)(v11 + 1260);
      if ( *(_BYTE *)(v11 + 1260) )
      {
        if ( cb_mode_for_freq && (*(_BYTE *)(v11 + 1262) & 4) != 0 )
          v61 = (*(unsigned __int16 *)(v11 + 1201) >> 1) & 1;
        else
          v61 = 0;
      }
      *(_BYTE *)(a3 + 160) = v61;
      *(_BYTE *)(a3 + 161) = v61;
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
        if ( v61 )
        {
          *(_DWORD *)(a3 + 7176) = 1;
          if ( *(_BYTE *)(v11 + 2501) )
          {
            *(_DWORD *)(a3 + 7176) = *(unsigned __int8 *)(v11 + 2501) + 1;
            *(_BYTE *)(a3 + 7174) = *(_BYTE *)(v11 + 2502);
            *(_BYTE *)(a3 + 7184) = *(_BYTE *)(v11 + 2503);
            goto LABEL_89;
          }
          if ( *(_BYTE *)(v11 + 2561) )
          {
            *(_DWORD *)(a3 + 7176) = *(unsigned __int8 *)(v11 + 2561) + 1;
            *(_BYTE *)(a3 + 7174) = *(_BYTE *)(v11 + 2562);
            *(_BYTE *)(a3 + 7184) = *(_BYTE *)(v11 + 2563);
LABEL_89:
            v62 = *(_BYTE **)(a4 + 16);
            *(_BYTE *)(a3 + 30) = v62[74];
            *(_BYTE *)(a3 + 31) = v62[75];
            *(_BYTE *)(a3 + 32) = v62[76];
            *(_BYTE *)(a3 + 33) = v62[77];
            *(_BYTE *)(a3 + 34) = v62[78];
            *(_BYTE *)(a3 + 35) = v62[79];
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
            LODWORD(v62) = *(_DWORD *)(a4 + 92);
            *(_WORD *)(a3 + 248) = 1;
            *(_DWORD *)(a3 + 92) = (_DWORD)v62;
            *(_DWORD *)(a3 + 96) = *(_DWORD *)(a2 + 20);
            if ( (_DWORD)v62 )
              qdf_trace_msg(
                0x35u,
                3u,
                "%s: Invalid bss type",
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                v60,
                "lim_fill_ft_session");
            else
              *(_DWORD *)(a3 + 88) = 2;
            v63 = *(_WORD *)(a2 + 18);
            *(_WORD *)(a3 + 176) = v63;
            *(_WORD *)(a3 + 234) = v63;
            if ( *(_BYTE *)(a1[1] + 1284LL) == 1 && (v63 & 0x400) != 0 )
              *(_BYTE *)(a3 + 250) = 1;
            v64 = *(_QWORD *)(a4 + 16);
            v125[0] = 0;
            v124[0] = 0;
            v123[0] = 0;
            v122 = 0;
            cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v64, v53, v54, v55, v56, v57, v58, v59, v60);
            if ( !cmpt_obj )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: vdev component object is NULL",
                v66,
                v67,
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                "lim_fill_session_power_info");
              best_6g_power_type = 16;
LABEL_103:
              v93 = "%s: Failed to fill power info in ft session";
              goto LABEL_119;
            }
            v74 = cmpt_obj;
            v75 = wlan_get_ielen_from_bss_description(a2);
            lim_extract_ap_capability(a1, a2 + 104, v75, a3 + 178, v125, v124, a3, v123);
            *(_BYTE *)(v74 + 932) = v123[0] ^ 1;
            if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 28)) )
            {
              v84 = *(unsigned __int8 *)(a3 + 10068);
              if ( v84 == 2 )
              {
                if ( (wlan_reg_is_indoor_ap_detected(a1[2695], v76, v77, v78, v79, v80, v81, v82, v83) & 1) != 0 )
                {
                  v84 = 3;
                  *(_BYTE *)(a3 + 10068) = 3;
                }
                else
                {
                  v84 = *(unsigned __int8 *)(a3 + 10068);
                }
              }
              best_6g_power_type = wlan_reg_get_best_6g_power_type(
                                     a1[2694],
                                     a1[2695],
                                     (unsigned int *)&v122,
                                     v84,
                                     *(_DWORD *)(a2 + 28),
                                     v76,
                                     v77,
                                     v78,
                                     v79,
                                     v80,
                                     v81,
                                     v82,
                                     v83);
              if ( best_6g_power_type )
                goto LABEL_103;
              v94 = v122;
              v95 = *(_QWORD *)(a3 + 16);
              *(_BYTE *)(a3 + 10069) = v122;
              mlme_set_best_6g_power_type(v95, v94, v85, v86, v87, v88, v89, v90, v91, v92);
            }
            if ( (wlan_reg_is_ext_tpc_supported(a1[2694], v76, v77, v78, v79, v80, v81, v82, v83) & 1) != 0 )
            {
              v104 = 0;
              *(_BYTE *)(v74 + 552) = v124[0];
              max_tx_power = *(_BYTE *)(a3 + 7032);
              if ( max_tx_power )
              {
LABEL_117:
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Reg max: %d local pwr: %d, max tx pwr: %d",
                  v96,
                  v97,
                  v98,
                  v99,
                  v100,
                  v101,
                  v102,
                  v103,
                  "lim_fill_session_power_info",
                  v104,
                  v124[0],
                  (unsigned int)max_tx_power);
                v109 = lim_set_session_channel_params(a1, a3);
                if ( !v109 )
                {
                  *(_BYTE *)(a3 + 236) = *(_BYTE *)(a3 + 178);
                  *(_BYTE *)(a3 + 7041) = *(_BYTE *)(a4 + 7041);
                  *(_BYTE *)(a3 + 8624) = *(_BYTE *)(v11 + 2574);
                  if ( !wlan_cm_is_vdev_roam_sync_inprogress(
                          *(_QWORD *)(a4 + 16),
                          v85,
                          v86,
                          v87,
                          v88,
                          v89,
                          v90,
                          v91,
                          v92) )
                  {
                    v111 = *(_DWORD *)(a3 + 80);
                    v112 = *(_WORD *)(a3 + 8);
                    *(_DWORD *)(a3 + 80) = 6;
                    *(_DWORD *)(a3 + 84) = v111;
                    qdf_trace(53, 1u, v112, 6);
                  }
                  v113 = *v12;
                  *(_DWORD *)(a3 + 424) = *(_DWORD *)(a4 + 424);
                  *v12 = v113 & 0xEF | *(_BYTE *)(a4 + 7024) & 0x10;
                  lim_init_obss_params(a1, a3);
                  *(_BYTE *)(a3 + 8653) = 1;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: FT enable smps: %d mode: %d supported nss 1x1: %d",
                    v114,
                    v115,
                    v116,
                    v117,
                    v118,
                    v119,
                    v120,
                    v121,
                    "lim_fill_ft_session",
                    *(unsigned __int8 *)(a1[1] + 1280LL),
                    *(unsigned __int8 *)(a1[1] + 1281LL),
                    1);
                  best_6g_power_type = 0;
                  goto LABEL_120;
                }
                best_6g_power_type = v109;
                v93 = "%s: Failed to set session channel params";
LABEL_119:
                qdf_trace_msg(0x35u, 2u, v93, v85, v86, v87, v88, v89, v90, v91, v92, "lim_fill_ft_session");
LABEL_120:
                _qdf_mem_free(v11);
                goto LABEL_121;
              }
            }
            else
            {
              channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(
                                             a1[2695],
                                             *(_DWORD *)(a3 + 284),
                                             v96,
                                             v97,
                                             v98,
                                             v99,
                                             v100,
                                             v101,
                                             v102,
                                             v103);
              v107 = v124[0];
              LOBYTE(v104) = channel_reg_power_for_freq;
              if ( v123[0] )
                v107 = channel_reg_power_for_freq - v124[0];
              v108 = v107;
              if ( !v107 )
                v107 = channel_reg_power_for_freq;
              if ( !v108 || v123[0] )
                v124[0] = v107;
              *(_BYTE *)(v74 + 536) = channel_reg_power_for_freq;
              *(_BYTE *)(v74 + 552) = v107;
              *(_DWORD *)(v74 + 556) = *(_DWORD *)(a3 + 284);
              max_tx_power = lim_get_max_tx_power(a1, v74);
              v104 = (char)v104;
              *(_BYTE *)(a3 + 7032) = max_tx_power;
              *(_BYTE *)(a3 + 10042) = max_tx_power;
              if ( max_tx_power )
                goto LABEL_117;
            }
            max_tx_power = wlan_reg_get_channel_reg_power_for_freq(
                             a1[2695],
                             *(_DWORD *)(a3 + 284),
                             v96,
                             v97,
                             v98,
                             v99,
                             v100,
                             v101,
                             v102,
                             v103);
            *(_BYTE *)(a3 + 7032) = max_tx_power;
            goto LABEL_117;
          }
          goto LABEL_83;
        }
      }
      else
      {
        *(_BYTE *)(a3 + 7173) = 0;
        if ( v61 )
        {
          *(_DWORD *)(a3 + 7176) = 1;
LABEL_83:
          if ( (*(_DWORD *)(v11 + 1262) & 3) == 3 )
          {
            *(_BYTE *)(a3 + 7174) = v30 - 2;
            goto LABEL_89;
          }
          if ( (*(_DWORD *)(v11 + 1262) & 3) == 1 )
          {
            *(_BYTE *)(a3 + 7174) = v30 + 2;
            goto LABEL_89;
          }
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: Invalid sec ch offset",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "lim_fill_ft_session");
        }
      }
      *(_DWORD *)(a3 + 7176) = 0;
      *(_BYTE *)(a3 + 7174) = 0;
      *(_BYTE *)(a3 + 7184) = 0;
      goto LABEL_89;
    }
    if ( ((1 << v44) & 0xC01) != 0 )
    {
      if ( *(_BYTE *)(v11 + 2640) )
        goto LABEL_35;
      if ( (*(_BYTE *)(v11 + 2484) || *(_BYTE *)(v11 + 2540)) && (v39 || (*(_BYTE *)(v43 + 2671) & 1) != 0) )
        goto LABEL_41;
      if ( *(_BYTE *)(v11 + 1200) )
        goto LABEL_33;
    }
    else
    {
      if ( ((1 << v44) & 0xA0) != 0 )
      {
LABEL_32:
        if ( !*(_BYTE *)(v11 + 1200) )
          goto LABEL_42;
        goto LABEL_33;
      }
      if ( ((1 << v44) & 0x300) == 0 )
        goto LABEL_42;
    }
    if ( (*(_BYTE *)(v11 + 2484) || *(_BYTE *)(v11 + 2540)) && (v39 || (*(_BYTE *)(v43 + 2671) & 1) != 0) )
      goto LABEL_41;
    if ( !*(_BYTE *)(v11 + 1200) )
      goto LABEL_32;
LABEL_33:
    LOBYTE(v42) = 5;
    goto LABEL_42;
  }
  best_6g_power_type = 2;
LABEL_121:
  _ReadStatusReg(SP_EL0);
  return best_6g_power_type;
}
