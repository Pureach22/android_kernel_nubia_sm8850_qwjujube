__int64 __fastcall _sch_beacon_process_for_session(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x23
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  char v25; // w22
  __int64 v26; // x20
  _BYTE *v27; // x25
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w8
  _BOOL4 v37; // w26
  __int64 cmpt_obj; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x20
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w9
  int v57; // w1
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int16 v66; // w8
  __int16 v67; // w9
  __int64 hash_entry; // x0
  __int64 v69; // x22
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  const char *v78; // x2
  double v79; // d0
  __int64 v80; // x0
  int v81; // w8
  __int64 v82; // x21
  const char *v83; // x2
  char *v84; // x22
  char *v85; // x23
  unsigned int omn_channel_width; // w24
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
  unsigned int vht_ch_width; // w9
  unsigned int v104; // w3
  __int64 v105; // x8
  __int64 v106; // x8
  unsigned int v107; // w8
  unsigned int v108; // w8
  __int64 v109; // x10
  __int64 v110; // x11
  int v111; // w12
  __int64 v112; // x9
  __int64 v113; // x10
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  __int64 v122; // x0
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  __int64 v131; // x21
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  const char *v140; // x2
  char v141; // w22
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  int v150; // w28
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  char channel_reg_power_for_freq; // w22
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  bool v168; // w8
  char v169; // w28
  unsigned int v170; // w3
  int v171; // w8
  char v172; // w10
  char v173; // w9
  bool v174; // zf
  char v175; // w10
  char max_tx_power; // w0
  char v177; // w21
  double v178; // d0
  double v179; // d1
  double v180; // d2
  double v181; // d3
  double v182; // d4
  double v183; // d5
  double v184; // d6
  double v185; // d7
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  double v194; // d0
  double v195; // d1
  double v196; // d2
  double v197; // d3
  double v198; // d4
  double v199; // d5
  double v200; // d6
  double v201; // d7
  int v202; // w1
  __int64 v203; // x0
  char v204; // w8
  double v205; // d0
  double v206; // d1
  double v207; // d2
  double v208; // d3
  double v209; // d4
  double v210; // d5
  double v211; // d6
  double v212; // d7
  int v213; // w1
  double v214; // d0
  double v215; // d1
  double v216; // d2
  double v217; // d3
  double v218; // d4
  double v219; // d5
  double v220; // d6
  double v221; // d7
  double v222; // d0
  double v223; // d1
  double v224; // d2
  double v225; // d3
  double v226; // d4
  double v227; // d5
  double v228; // d6
  double v229; // d7
  _BYTE v230[4]; // [xsp+4h] [xbp-4Ch] BYREF
  int v231; // [xsp+8h] [xbp-48h] BYREF
  _BYTE v232[4]; // [xsp+Ch] [xbp-44h] BYREF
  __int64 v233; // [xsp+10h] [xbp-40h] BYREF
  __int64 v234; // [xsp+18h] [xbp-38h]
  __int64 v235; // [xsp+20h] [xbp-30h]
  int v236; // [xsp+28h] [xbp-28h]
  __int16 v237; // [xsp+2Ch] [xbp-24h] BYREF
  __int64 v238; // [xsp+30h] [xbp-20h] BYREF
  _BYTE v239[13]; // [xsp+38h] [xbp-18h]
  __int64 v240; // [xsp+48h] [xbp-8h]

  v240 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a3 + 16);
  v7 = *(_QWORD *)(a2 + 16);
  v236 = 0;
  v234 = 0;
  v235 = 0;
  v233 = 0;
  v232[0] = 0;
  v231 = 0;
  v230[0] = 0;
  result = mlo_is_mld_sta(v6);
  if ( (result & 1) != 0 )
  {
    result = mlo_check_if_all_vdev_up(*(_QWORD *)(a3 + 16));
    if ( (result & 1) == 0 )
    {
      v26 = jiffies;
      if ( _sch_beacon_process_for_session___last_ticks - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: Ignore beacon processing, not all VDEVs are UP",
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   "__sch_beacon_process_for_session");
        _sch_beacon_process_for_session___last_ticks = v26;
      }
      goto LABEL_157;
    }
    if ( (unsigned int)lim_get_bpcc_from_mlo_ie(&sch_beacon_process_bcn, v230) )
      v25 = 0;
    else
      v25 = lim_check_cu_happens(*(_QWORD *)(a3 + 16), *(unsigned __int8 *)(*(_QWORD *)(a3 + 16) + 93LL), v230[0]);
    result = lim_process_ml_reconfig(a1, a3, a2);
  }
  else
  {
    v25 = 1;
  }
  v27 = (_BYTE *)(a3 + 7024);
  if ( *(_BYTE *)(a3 + 10071) == 1 )
    result = lim_process_beacon_eht_op(a3, (__int64)&sch_beacon_process_bcn, v9, v10, v11, v12, v13, v14, v15, v16);
  if ( (v25 & 1) == 0 )
    goto LABEL_157;
  qdf_mem_set(&v233, 0x1Cu, 0);
  v36 = *(_DWORD *)(a3 + 88);
  v37 = 0;
  HIWORD(v234) = 0;
  if ( v36 == 2 )
  {
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a3 + 16), v28, v29, v30, v31, v32, v33, v34, v35);
    if ( cmpt_obj && *(_BYTE *)(cmpt_obj + 197) == 1 )
      cmpt_obj = policy_mgr_sta_sap_dfs_enforce_scc(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a3 + 10));
    if ( dword_917388 != *(_DWORD *)(a3 + 284) )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Channel Change freq from %d --> %d - Ignoring beacon!",
                 v39,
                 v40,
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 "sch_bcn_process_sta");
      goto LABEL_157;
    }
    if ( byte_917CEC )
    {
      result = wma_is_csa_offload_enabled(cmpt_obj);
      if ( (result & 1) != 0 )
      {
        v47 = jiffies;
        if ( sch_bcn_process_sta___last_ticks - jiffies + 125 < 0 )
        {
          result = qdf_trace_msg(
                     0x35u,
                     2u,
                     "%s: Ignore bcn as channel switch IE present and csa offload is enabled",
                     v39,
                     v40,
                     v41,
                     v42,
                     v43,
                     v44,
                     v45,
                     v46,
                     "sch_bcn_process_sta");
          sch_bcn_process_sta___last_ticks = v47;
        }
        goto LABEL_157;
      }
    }
    lim_detect_change_in_ap_capabilities(
      a1,
      (__int64)&sch_beacon_process_bcn,
      a3,
      1,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46);
    LOBYTE(v233) = *(_BYTE *)(a3 + 10);
    qdf_mem_copy((void *)(a3 + 296), &sch_beacon_process_bcn, 8u);
    v56 = *(unsigned __int8 *)(a3 + 308);
    v57 = (unsigned __int8)byte_917393;
    ++*(_DWORD *)(a3 + 304);
    if ( v56 != v57 )
    {
      *(_BYTE *)(a3 + 308) = v57;
      lim_send_set_dtim_period(a1, v57, a3, v48, v49, v50, v51, v52, v53, v54, v55);
    }
    qdf_trace(53, 4u, *(_WORD *)(a3 + 8), sch_beacon_process_bcn);
    qdf_trace(53, 4u, *(_WORD *)(a3 + 8), dword_917344);
    if ( *(unsigned __int16 *)(a3 + 7158) != (unsigned __int16)word_917348 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Beacon interval changed from %d to %d",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        "sch_bcn_process_sta");
      v66 = word_917348;
      v67 = HIWORD(v234) | 1;
      *(_WORD *)(a3 + 7158) = word_917348;
      HIWORD(v234) = v67;
      WORD2(v233) = v66;
    }
    if ( byte_917CE0 )
      *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2960LL) = byte_91738D;
    if ( byte_917CE2 )
      *(_WORD *)(*(_QWORD *)(a1 + 8) + 3402LL) = (unsigned __int8)byte_917393;
    if ( *(_BYTE *)(a1 + 8884) )
      lim_decide_sta_protection(
        a1,
        (__int64)&sch_beacon_process_bcn,
        (__int64)&v233,
        a3,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65);
    if ( byte_917CEB )
      lim_enable_short_preamble(
        a1,
        (((unsigned __int8)byte_9177AC >> 2) & 1) == 0,
        (__int64)&v233,
        a3,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65);
    lim_update_short_slot(
      a1,
      (__int64)&sch_beacon_process_bcn,
      (__int64)&v233,
      a3,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65);
    hash_entry = dph_get_hash_entry(a1, 1u, a3 + 360);
    if ( (!byte_917CE5 || (*v27 & 2) == 0) && (!byte_917CE3 || (*v27 & 1) == 0) )
    {
      if ( byte_917CE4 && (*v27 & 1) != 0 )
      {
        v37 = (byte_9174AB & 0xF) != *(unsigned __int8 *)(a3 + 7156);
        goto LABEL_49;
      }
      goto LABEL_48;
    }
    if ( (byte_917493 & 0xF) != *(_BYTE *)(a3 + 7156) )
    {
      v69 = hash_entry;
      qdf_mem_copy((void *)(hash_entry + 239), &unk_917491, 0x18u);
      if ( (unsigned int)sch_beacon_edca_process(a1, &unk_917491, a3) )
      {
        v78 = "%s: EDCA parameter processing error";
      }
      else
      {
        if ( v69 )
        {
          lim_set_active_edca_params((_BYTE *)a1, (int *)(a3 + 7096), a3);
          lim_send_edca_params(a1, (int *)(a3 + 7136), *(unsigned __int8 *)(a3 + 10), 0);
          sch_qos_concurrency_update(v79);
          goto LABEL_48;
        }
        v78 = "%s: Self Entry missing in Hash Table";
      }
      qdf_trace_msg(0x35u, 2u, v78, v70, v71, v72, v73, v74, v75, v76, v77, "sch_bcn_process_sta");
    }
LABEL_48:
    v37 = 0;
  }
LABEL_49:
  if ( (!*(_BYTE *)(a3 + 7170) || !((unsigned __int8)byte_917D21 | (unsigned __int8)byte_917D04))
    && *(_BYTE *)(a3 + 155)
    && byte_91782C )
  {
    lim_update_sta_run_time_ht_switch_chnl_params(a1, (__int64)&byte_91782C, a3);
  }
  if ( *(_DWORD *)(a3 + 88) == 2 )
  {
    v237 = 0;
    v80 = dph_lookup_hash_entry(
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            a1,
            (unsigned __int8 *)(v7 + 10),
            &v237,
            a3 + 360);
    if ( v80 )
    {
      v81 = *(unsigned __int8 *)(a3 + 9794);
      v82 = v80;
      LODWORD(v238) = 0;
      if ( v81 == 1 )
      {
        v83 = "%s: Ignore opmode change as channel switch is in progress";
      }
      else
      {
        if ( (byte_917E51 & 1) == 0 )
        {
          v84 = &byte_917CF4;
          v85 = &byte_917D04;
          if ( byte_917CF4 || (v84 = &byte_917D30, v85 = &byte_917D40, byte_917D30) )
          {
            if ( *(_BYTE *)(a3 + 7170) && *v85 )
            {
              if ( byte_917D21 )
              {
                lim_update_nss(
                  a1,
                  v80,
                  ((unsigned __int8)byte_917D22 >> 4) & 7,
                  a3,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35);
                omn_channel_width = lim_get_omn_channel_width((__int64)&byte_917D21);
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: OMN IE present in bcn/probe rsp, ie width: %d ch_width: %d",
                  v87,
                  v88,
                  v89,
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  "sch_bcn_update_opmode_change",
                  byte_917D22 & 3,
                  omn_channel_width);
                lim_update_omn_ie_ch_width(
                  *(_QWORD *)(a3 + 16),
                  omn_channel_width,
                  v95,
                  v96,
                  v97,
                  v98,
                  v99,
                  v100,
                  v101,
                  v102);
              }
              vht_ch_width = (unsigned __int8)lim_get_vht_ch_width(
                                                (__int64)v84,
                                                (unsigned __int8 *)v85,
                                                (__int64)&byte_91782C,
                                                (__int64)&unk_9177F0,
                                                &byte_917D21,
                                                v28,
                                                v29,
                                                v30,
                                                v31,
                                                v32,
                                                v33,
                                                v34,
                                                v35);
              if ( vht_ch_width == 4 )
                v104 = 2;
              else
                v104 = vht_ch_width;
              lim_update_channel_width(a1, (_BYTE *)v82, a3, v104, (unsigned int *)&v238);
            }
          }
LABEL_71:
          if ( (*(_BYTE *)(a3 + 10020) & 1) != 0
            || (v105 = *(_QWORD *)(a3 + 16)) == 0
            || (v106 = *(_QWORD *)(v105 + 40)) == 0
            || (unsigned int)(*(_DWORD *)(v106 + 28) - 21) > 9
            || !*(_BYTE *)(a3 + 8740)
            || !byte_917DCC )
          {
LABEL_85:
            v109 = *(_QWORD *)(v82 + 834);
            v110 = *(_QWORD *)(v82 + 839);
            v111 = (unsigned __int8)*(_QWORD *)(v82 + 826);
            v238 = *(_QWORD *)(v82 + 826);
            *(_QWORD *)v239 = v109;
            *(_QWORD *)&v239[5] = v110;
            if ( v111 | (unsigned __int8)qword_917DDE && (unsigned int)qdf_mem_cmp(&v238, &qword_917DDE, 0x15u) )
            {
              v113 = qword_917DDE;
              v112 = qword_917DE6;
              *(_QWORD *)(v82 + 839) = *(__int64 *)((char *)&qword_917DE6 + 5);
              *(_QWORD *)(v82 + 826) = v113;
              *(_QWORD *)(v82 + 834) = v112;
              lim_update_vdev_sr_elements(a3, v82, v28, v29, v30, v31, v32, v33, v34, v35);
              lim_handle_sr_cap(*(_QWORD *)(a3 + 16), 2u, v114, v115, v116, v117, v118, v119, v120, v121);
            }
            goto LABEL_88;
          }
          v107 = *(unsigned __int8 *)(a3 + 8745);
          if ( byte_917E5C && (v107 & 0x3F) != (byte_917E5E & 0x3F) )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: bss color changed from [%d] to [%d]",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "sch_bcn_update_he_ies");
            v108 = *(unsigned __int8 *)(a3 + 8745);
            *(_BYTE *)(a3 + 8745) = v108 & 0xC0 | byte_917E5E & 0x3F;
            if ( v108 >> 7 == (unsigned __int8)byte_917DD1 >> 7 )
            {
LABEL_84:
              lim_send_he_ie_update(v28, v29, v30, v31, v32, v33, v34, v35, a1, a3);
              goto LABEL_85;
            }
          }
          else if ( v107 >> 7 == (unsigned __int8)byte_917DD1 >> 7 )
          {
            goto LABEL_85;
          }
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: color disable flag changed from [%d] to [%d]",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "sch_bcn_update_he_ies");
          *(_BYTE *)(a3 + 8745) = byte_917DD1 & 0x80 | *(_BYTE *)(a3 + 8745) & 0x7F;
          goto LABEL_84;
        }
        v83 = "%s: Ignore opmode change as there is EHT operation information";
      }
      qdf_trace_msg(0x35u, 8u, v83, v28, v29, v30, v31, v32, v33, v34, v35, "sch_bcn_update_opmode_change");
      goto LABEL_71;
    }
  }
LABEL_88:
  v122 = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a3 + 16), v28, v29, v30, v31, v32, v33, v34, v35);
  if ( !v122 )
  {
    v140 = "%s: vdev component object is NULL";
LABEL_106:
    result = qdf_trace_msg(
               0x35u,
               2u,
               v140,
               v123,
               v124,
               v125,
               v126,
               v127,
               v128,
               v129,
               v130,
               "__sch_beacon_process_for_session");
    goto LABEL_157;
  }
  v131 = v122;
  if ( !wlan_reg_is_6ghz_chan_freq(dword_917388) )
  {
    v141 = wlan_mlme_skip_tpe(*(_QWORD *)(a1 + 21624));
    v150 = 0;
    goto LABEL_95;
  }
  if ( !byte_9174AC )
  {
    v140 = "%s: Channel is 6G but country IE not present";
    goto LABEL_106;
  }
  if ( (byte_917DCF & 0x20) != 0 )
  {
    *(_BYTE *)(a3 + 10068) = ((unsigned __int8)byte_917DD9 >> 3) & 0xF;
    if ( (lim_is_ap_power_type_6g_invalid(a3) & 1) != 0 )
    {
      *(_BYTE *)(a3 + 10068) = 4;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: AP power type is invalid, defaulting to MAX_AP_TYPE",
        v132,
        v133,
        v134,
        v135,
        v136,
        v137,
        v138,
        v139,
        "__sch_beacon_process_for_session");
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: AP power type is null, defaulting to MAX_AP_TYPE",
      v123,
      v124,
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      "__sch_beacon_process_for_session");
    *(_BYTE *)(a3 + 10068) = 4;
  }
  v170 = *(unsigned __int8 *)(a3 + 10068);
  if ( v170 == 2 )
  {
    if ( (wlan_reg_is_indoor_ap_detected(*(_QWORD *)(a1 + 21632), v132, v133, v134, v135, v136, v137, v138, v139) & 1) != 0 )
    {
      v170 = 3;
      *(_BYTE *)(a3 + 10068) = 3;
    }
    else
    {
      v170 = *(unsigned __int8 *)(a3 + 10068);
    }
  }
  result = wlan_reg_get_best_6g_power_type(
             *(_QWORD *)(a1 + 21624),
             *(_QWORD *)(a1 + 21632),
             (unsigned int *)&v231,
             v170,
             dword_917388,
             v132,
             v133,
             v134,
             v135,
             v136,
             v137,
             v138,
             v139);
  if ( !(_DWORD)result )
  {
    v202 = v231;
    v203 = *(_QWORD *)(a3 + 16);
    v174 = v231 == *(unsigned __int8 *)(a3 + 10069);
    *(_BYTE *)(a3 + 10069) = v231;
    v150 = !v174;
    mlme_set_best_6g_power_type(v203, v202, v194, v195, v196, v197, v198, v199, v200, v201);
    v141 = 0;
LABEL_95:
    if ( (wlan_reg_is_ext_tpc_supported(*(_QWORD *)(a1 + 21624), v142, v143, v144, v145, v146, v147, v148, v149) & 1) == 0
      || (*(_BYTE *)(a3 + 10070) & 1) != 0 )
    {
      if ( (*(_BYTE *)(a3 + 10070) & 1) == 0 )
      {
        channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(
                                       *(_QWORD *)(a1 + 21632),
                                       *(_DWORD *)(a3 + 284),
                                       v151,
                                       v152,
                                       v153,
                                       v154,
                                       v155,
                                       v156,
                                       v157,
                                       v158);
        if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3538LL) == 1 )
        {
          v168 = byte_917CD1 != 0;
          if ( byte_917CD1 )
            v169 = byte_917CD2;
          else
            v169 = channel_reg_power_for_freq;
          if ( *(_BYTE *)(a1 + 20208) && byte_917CF1 )
          {
            v168 = 0;
            v169 = channel_reg_power_for_freq - byte_9177AE;
          }
        }
        else
        {
          v168 = 0;
          v169 = channel_reg_power_for_freq;
        }
        *(_BYTE *)(v131 + 948) = v168;
        *(_BYTE *)(v131 + 552) = channel_reg_power_for_freq;
        *(_BYTE *)(v131 + 568) = v169;
        *(_DWORD *)(v131 + 572) = *(_DWORD *)(a3 + 284);
        max_tx_power = lim_get_max_tx_power(a1, v131, v160, v161, v162, v163, v164, v165, v166, v167);
        if ( max_tx_power != *(_BYTE *)(a3 + 7032) )
        {
          v177 = max_tx_power;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: New maxTx power %d, old pwr %d",
            v151,
            v152,
            v153,
            v154,
            v155,
            v156,
            v157,
            v158,
            "__sch_beacon_process_for_session",
            (unsigned int)max_tx_power);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: regMax %d, local %d",
            v178,
            v179,
            v180,
            v181,
            v182,
            v183,
            v184,
            v185,
            "__sch_beacon_process_for_session",
            (unsigned int)channel_reg_power_for_freq,
            (unsigned int)v169);
          if ( !(unsigned int)lim_send_set_max_tx_power_req(
                                a1,
                                v177,
                                (unsigned __int8 *)a3,
                                v186,
                                v187,
                                v188,
                                v189,
                                v190,
                                v191,
                                v192,
                                v193) )
            *(_BYTE *)(a3 + 7032) = v177;
        }
      }
      goto LABEL_143;
    }
    lim_parse_tpe_ie(
      a1,
      a3,
      qword_917FD3,
      byte_917FD2,
      v151,
      v152,
      v153,
      v154,
      v155,
      v156,
      v157,
      v158,
      (__int64)&byte_917DCC,
      v232);
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3538LL) != 1 )
      goto LABEL_123;
    v171 = (unsigned __int8)byte_917CD1;
    v172 = byte_917CD2;
    v173 = byte_9177AE;
    if ( !byte_917CD1 )
      v172 = 0;
    v174 = !*(_BYTE *)(a1 + 20208) || byte_917CF1 == 0;
    if ( v174 )
    {
      v173 = v172;
      v175 = 1;
    }
    else
    {
      v175 = 0;
    }
    if ( *(unsigned __int8 *)(v131 + 568) != v173 )
    {
      *(_BYTE *)(v131 + 568) = v173;
      if ( v171 )
        v204 = v175;
      else
        v204 = 0;
      *(_BYTE *)(v131 + 948) = v204;
    }
    else
    {
LABEL_123:
      if ( v141 & 1 | ((v232[0] & 1) == 0) && ((*(unsigned __int8 *)(a3 + 13284) | v150) & 1) == 0 )
      {
LABEL_143:
        if ( byte_91782C )
          v213 = wlan_reg_legacy_chan_to_freq(
                   *(_QWORD *)(a1 + 21632),
                   (unsigned __int8)byte_91782D,
                   v151,
                   v152,
                   v153,
                   v154,
                   v155,
                   v156,
                   v157,
                   v158);
        else
          v213 = dword_917388;
        lim_received_hb_handler(a1, v213, a3);
        if ( v37 )
          lim_send_probe_req_mgmt_frame(a1, a3, nullptr, nullptr, v214, v215, v216, v217, v218, v219, v220, v221);
        if ( !*(_BYTE *)(a1 + 14881) && HIWORD(v234) )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Beacon for session[%d] got changed param change bitmap: 0x%x",
            v214,
            v215,
            v216,
            v217,
            v218,
            v219,
            v220,
            v221,
            "__sch_beacon_process_for_session",
            *(unsigned __int16 *)(a3 + 8));
          lim_send_beacon_params(a1, (unsigned __int16 *)&v233, a3);
        }
        if ( *(_DWORD *)(a3 + 7036) == 2 )
        {
          if ( *(_BYTE *)(a3 + 8673) == 1 )
          {
            lim_p2p_oper_chan_change_confirm_action_frame(
              a1,
              (unsigned __int8 *)(a3 + 24),
              a3,
              v214,
              v215,
              v216,
              v217,
              v218,
              v219,
              v220,
              v221);
            *(_BYTE *)(a3 + 8673) = 0;
          }
          if ( *(_BYTE *)(a3 + 9795) == 1 )
            lim_send_channel_usage_req_notif_cap_action_frame(
              *(unsigned __int8 *)(a3 + 10),
              v214,
              v215,
              v216,
              v217,
              v218,
              v219,
              v220,
              v221);
        }
        lim_process_beacon_eht(a1, a3, (__int64)&sch_beacon_process_bcn, v214, v215, v216, v217, v218, v219, v220, v221);
        result = lim_process_bcn_prb_rsp_t2lm(
                   a1,
                   a3,
                   (char *)&sch_beacon_process_bcn,
                   v222,
                   v223,
                   v224,
                   v225,
                   v226,
                   v227,
                   v228,
                   v229);
        goto LABEL_157;
      }
    }
    if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a3 + 284)) && *(_BYTE *)(a3 + 10069) == 3 )
      lim_set_tpc_power(a1, a3, 0, 1, v205, v206, v207, v208, v209, v210, v211, v212);
    lim_set_tpc_power(a1, a3, 0, 0, v205, v206, v207, v208, v209, v210, v211, v212);
    *(_BYTE *)(a3 + 13284) = 0;
    goto LABEL_143;
  }
LABEL_157:
  _ReadStatusReg(SP_EL0);
  return result;
}
