void __fastcall sch_beacon_process(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  __int64 v31; // x21
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x21
  void (__fastcall *v41)(__int64, __int64 *); // x24
  _BYTE *v42; // x25
  __int64 v43; // x9
  __int64 v44; // x0
  __int64 v45; // x22
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int v54; // w8
  _BOOL4 v55; // w26
  __int64 cmpt_obj; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x20
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  int v74; // w9
  int v75; // w1
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int16 v84; // w8
  __int16 v85; // w9
  __int64 hash_entry; // x0
  __int64 v87; // x23
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  const char *v96; // x2
  double v97; // d0
  __int64 v98; // x0
  int v99; // w8
  __int64 v100; // x21
  const char *v101; // x2
  char *v102; // x22
  char *v103; // x23
  unsigned int omn_channel_width; // w24
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
  unsigned int vht_ch_width; // w9
  unsigned int v122; // w3
  __int64 v123; // x8
  __int64 v124; // x8
  unsigned int v125; // w8
  unsigned int v126; // w8
  __int64 v127; // x10
  __int64 v128; // x11
  int v129; // w12
  __int64 v130; // x9
  __int64 v131; // x10
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  __int64 v140; // x0
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  __int64 v149; // x21
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7
  const char *v158; // x2
  char v159; // w22
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  int v168; // w23
  double v169; // d0
  double v170; // d1
  double v171; // d2
  double v172; // d3
  double v173; // d4
  double v174; // d5
  double v175; // d6
  double v176; // d7
  int v177; // w8
  char v178; // w10
  char v179; // w9
  bool v180; // zf
  char v181; // w10
  char channel_reg_power_for_freq; // w22
  double v183; // d0
  double v184; // d1
  double v185; // d2
  double v186; // d3
  double v187; // d4
  double v188; // d5
  double v189; // d6
  double v190; // d7
  bool v191; // w8
  char v192; // w28
  unsigned int v193; // w3
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
  char max_tx_power; // w0
  char v205; // w21
  double v206; // d0
  double v207; // d1
  double v208; // d2
  double v209; // d3
  double v210; // d4
  double v211; // d5
  double v212; // d6
  double v213; // d7
  double v214; // d0
  double v215; // d1
  double v216; // d2
  double v217; // d3
  double v218; // d4
  double v219; // d5
  double v220; // d6
  double v221; // d7
  char v222; // w8
  double v223; // d0
  double v224; // d1
  double v225; // d2
  double v226; // d3
  double v227; // d4
  double v228; // d5
  double v229; // d6
  double v230; // d7
  int v231; // w1
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  int v240; // [xsp+24h] [xbp-6Ch] BYREF
  _BYTE v241[4]; // [xsp+28h] [xbp-68h] BYREF
  __int16 v242; // [xsp+2Ch] [xbp-64h] BYREF
  __int64 v243; // [xsp+30h] [xbp-60h] BYREF
  __int64 v244; // [xsp+38h] [xbp-58h]
  __int64 v245; // [xsp+40h] [xbp-50h]
  __int64 v246; // [xsp+48h] [xbp-48h]
  __int64 v247; // [xsp+50h] [xbp-40h] BYREF
  __int64 v248; // [xsp+58h] [xbp-38h]
  __int64 v249; // [xsp+60h] [xbp-30h] BYREF
  unsigned __int64 v250; // [xsp+68h] [xbp-28h]
  __int64 v251; // [xsp+70h] [xbp-20h] BYREF
  _BYTE v252[13]; // [xsp+78h] [xbp-18h]
  __int64 v253; // [xsp+88h] [xbp-8h]

  v253 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a3 || *(_DWORD *)(a3 + 88) != 2 )
    goto LABEL_166;
  if ( !wlan_cm_is_vdev_connected(*(_QWORD *)(a3 + 16), a4, a5, a6, a7, a8, a9, a10, a11) )
  {
    v31 = jiffies;
    if ( sch_beacon_process___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: vdev %d, drop beacon",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "sch_beacon_process",
        *(unsigned __int8 *)(a3 + 10));
      sch_beacon_process___last_ticks = v31;
    }
    goto LABEL_166;
  }
  if ( (unsigned int)sir_convert_beacon_frame2_struct(a1, a2, (int)&sch_beacon_process_bcn) )
  {
    v30 = jiffies;
    if ( sch_beacon_process___last_ticks_4 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: beacon parsing failed",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "sch_beacon_process");
      sch_beacon_process___last_ticks_4 = v30;
    }
    goto LABEL_166;
  }
  if ( (unsigned int)lim_cmp_ssid((unsigned __int8 *)&byte_84EFFC, a3) )
  {
    v40 = jiffies;
    if ( sch_beacon_process___last_ticks_6 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: ssid mismatch, current %.*sRcvd %.*s from %02x:%02x:%02x:**:**:%02x",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "sch_beacon_process",
        *(unsigned __int8 *)(a3 + 36),
        a3 + 37,
        (unsigned __int8)byte_84EFFC,
        &unk_84EFFD,
        *(unsigned __int8 *)(a3 + 24),
        *(unsigned __int8 *)(a3 + 25),
        *(unsigned __int8 *)(a3 + 26),
        *(unsigned __int8 *)(a3 + 29));
      sch_beacon_process___last_ticks_6 = v40;
    }
    goto LABEL_166;
  }
  *(_BYTE *)(a3 + 251) = byte_84F043;
  v41 = *(void (__fastcall **)(__int64, __int64 *))(a1 + 12440);
  v42 = (_BYTE *)(a3 + 7024);
  if ( v41
    && *(_DWORD *)(a3 + 88) == 2
    && *(unsigned __int8 *)(a3 + 24) == (unsigned __int8)byte_84F48F
    && *(unsigned __int8 *)(a3 + 25) == (unsigned __int8)byte_84F490
    && *(unsigned __int8 *)(a3 + 26) == (unsigned __int8)byte_84F491
    && *(unsigned __int8 *)(a3 + 27) == (unsigned __int8)byte_84F492
    && *(unsigned __int8 *)(a3 + 28) == (unsigned __int8)byte_84F493
    && *(unsigned __int8 *)(a3 + 29) == (unsigned __int8)byte_84F494 )
  {
    v249 = 0;
    v250 = 0;
    v247 = 0;
    v248 = 0;
    v245 = 0;
    v246 = 0;
    v243 = 0;
    v244 = 0;
    qdf_mem_copy((char *)&v247 + 2, &byte_84F48F, 6u);
    qdf_mem_copy(&v249, &sch_beacon_process_bcn, 8u);
    WORD2(v248) = word_84EFF8;
    LODWORD(v248) = dword_84F038;
    BYTE1(v243) = byte_84EFFC;
    qdf_mem_copy((char *)&v243 + 2, &unk_84EFFD, (unsigned __int8)byte_84EFFC);
    v43 = (unsigned __int128)(ktime_get_with_offset(1) * (__int128)0x20C49BA5E353F7CFLL) >> 64;
    v44 = *(_QWORD *)(a1 + 12760);
    LOBYTE(v243) = *(_BYTE *)(a3 + 10);
    v250 = ((v43 >> 7) + ((unsigned __int64)v43 >> 63)) / 0x3E8;
    if ( *((_DWORD *)v41 - 1) != -239266345 )
      __break(0x8238u);
    v41(v44, &v243);
  }
  v45 = *(_QWORD *)(a2 + 16);
  LODWORD(v246) = 0;
  v244 = 0;
  v245 = 0;
  v243 = 0;
  v241[0] = 0;
  v240 = 0;
  qdf_mem_set(&v243, 0x1Cu, 0);
  v54 = *(_DWORD *)(a3 + 88);
  v55 = 0;
  HIWORD(v244) = 0;
  if ( v54 == 2 )
  {
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a3 + 16), v46, v47, v48, v49, v50, v51, v52, v53);
    if ( cmpt_obj && *(_BYTE *)(cmpt_obj + 181) == 1 )
      cmpt_obj = policy_mgr_sta_sap_dfs_enforce_scc(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a3 + 10));
    if ( dword_84F038 != *(_DWORD *)(a3 + 284) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Channel Change freq from %d --> %d - Ignoring beacon!",
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        "sch_bcn_process_sta");
      goto LABEL_166;
    }
    if ( byte_84F99C && (wma_is_csa_offload_enabled(cmpt_obj) & 1) != 0 )
    {
      v65 = jiffies;
      if ( sch_bcn_process_sta___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Ignore bcn as channel switch IE present and csa offload is enabled",
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          "sch_bcn_process_sta");
        sch_bcn_process_sta___last_ticks = v65;
      }
      goto LABEL_166;
    }
    lim_detect_change_in_ap_capabilities(
      a1,
      (__int64)&sch_beacon_process_bcn,
      a3,
      1,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64);
    LOBYTE(v243) = *(_BYTE *)(a3 + 10);
    qdf_mem_copy((void *)(a3 + 296), &sch_beacon_process_bcn, 8u);
    v74 = *(unsigned __int8 *)(a3 + 308);
    v75 = (unsigned __int8)byte_84F043;
    ++*(_DWORD *)(a3 + 304);
    if ( v74 != v75 )
    {
      *(_BYTE *)(a3 + 308) = v75;
      lim_send_set_dtim_period(a1, v75, a3, v66, v67, v68, v69, v70, v71, v72, v73);
    }
    qdf_trace(53, 4u, *(_WORD *)(a3 + 8), sch_beacon_process_bcn);
    qdf_trace(53, 4u, *(_WORD *)(a3 + 8), dword_84EFF4);
    if ( *(unsigned __int16 *)(a3 + 7158) != (unsigned __int16)word_84EFF8 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Beacon interval changed from %d to %d",
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        "sch_bcn_process_sta");
      v84 = word_84EFF8;
      v85 = HIWORD(v244) | 1;
      *(_WORD *)(a3 + 7158) = word_84EFF8;
      HIWORD(v244) = v85;
      WORD2(v243) = v84;
    }
    if ( byte_84F990 )
      *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2760LL) = byte_84F03D;
    if ( byte_84F992 )
      *(_WORD *)(*(_QWORD *)(a1 + 8) + 3202LL) = (unsigned __int8)byte_84F043;
    if ( *(_BYTE *)(a1 + 8884) )
      lim_decide_sta_protection(
        a1,
        (__int64)&sch_beacon_process_bcn,
        (__int64)&v243,
        a3,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83);
    if ( byte_84F99B )
      lim_enable_short_preamble(
        a1,
        (((unsigned __int8)byte_84F45C >> 2) & 1) == 0,
        (__int64)&v243,
        a3,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83);
    lim_update_short_slot(
      a1,
      (__int64)&sch_beacon_process_bcn,
      (__int64)&v243,
      a3,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83);
    hash_entry = dph_get_hash_entry(a1, 1u, a3 + 360);
    if ( (!byte_84F995 || (*v42 & 2) == 0) && (!byte_84F993 || (*v42 & 1) == 0) )
    {
      if ( byte_84F994 && (*v42 & 1) != 0 )
      {
        v55 = (byte_84F15B & 0xF) != *(unsigned __int8 *)(a3 + 7156);
        goto LABEL_59;
      }
      goto LABEL_58;
    }
    if ( (byte_84F143 & 0xF) != *(_BYTE *)(a3 + 7156) )
    {
      v87 = hash_entry;
      qdf_mem_copy((void *)(hash_entry + 239), &unk_84F141, 0x18u);
      if ( (unsigned int)sch_beacon_edca_process(a1, &unk_84F141, a3) )
      {
        v96 = "%s: EDCA parameter processing error";
      }
      else
      {
        if ( v87 )
        {
          lim_set_active_edca_params((_BYTE *)a1, (int *)(a3 + 7096), a3);
          lim_send_edca_params(a1, (int *)(a3 + 7136), *(unsigned __int8 *)(a3 + 10), 0);
          sch_qos_concurrency_update(v97);
          goto LABEL_58;
        }
        v96 = "%s: Self Entry missing in Hash Table";
      }
      qdf_trace_msg(0x35u, 2u, v96, v88, v89, v90, v91, v92, v93, v94, v95, "sch_bcn_process_sta");
    }
LABEL_58:
    v55 = 0;
  }
LABEL_59:
  if ( (!*(_BYTE *)(a3 + 7170) || !((unsigned __int8)byte_84F9D1 | (unsigned __int8)byte_84F9B4))
    && *(_BYTE *)(a3 + 155)
    && byte_84F4DC )
  {
    lim_update_sta_run_time_ht_switch_chnl_params(a1, (__int64)&byte_84F4DC, a3);
  }
  if ( *(_DWORD *)(a3 + 88) == 2 )
  {
    v242 = 0;
    v98 = dph_lookup_hash_entry(
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            a1,
            (unsigned __int8 *)(v45 + 10),
            &v242,
            a3 + 360);
    if ( v98 )
    {
      v99 = *(unsigned __int8 *)(a3 + 9794);
      v100 = v98;
      LODWORD(v251) = 0;
      if ( v99 == 1 )
      {
        v101 = "%s: Ignore opmode change as channel switch is in progress";
      }
      else
      {
        if ( (byte_84FB01 & 1) == 0 )
        {
          v102 = &byte_84F9A4;
          v103 = &byte_84F9B4;
          if ( byte_84F9A4 || (v102 = &byte_84F9E0, v103 = &byte_84F9F0, byte_84F9E0) )
          {
            if ( *(_BYTE *)(a3 + 7170) && *v103 )
            {
              if ( byte_84F9D1 )
              {
                lim_update_nss(
                  a1,
                  v98,
                  ((unsigned __int8)byte_84F9D2 >> 4) & 7,
                  a3,
                  v46,
                  v47,
                  v48,
                  v49,
                  v50,
                  v51,
                  v52,
                  v53);
                omn_channel_width = lim_get_omn_channel_width((__int64)&byte_84F9D1);
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: OMN IE present in bcn/probe rsp, ie width: %d ch_width: %d",
                  v105,
                  v106,
                  v107,
                  v108,
                  v109,
                  v110,
                  v111,
                  v112,
                  "sch_bcn_update_opmode_change",
                  byte_84F9D2 & 3,
                  omn_channel_width);
                lim_update_omn_ie_ch_width(
                  *(_QWORD *)(a3 + 16),
                  omn_channel_width,
                  v113,
                  v114,
                  v115,
                  v116,
                  v117,
                  v118,
                  v119,
                  v120);
              }
              vht_ch_width = (unsigned __int8)lim_get_vht_ch_width(
                                                (__int64)v102,
                                                (unsigned __int8 *)v103,
                                                (__int64)&byte_84F4DC,
                                                (__int64)&unk_84F4A0,
                                                &byte_84F9D1,
                                                v46,
                                                v47,
                                                v48,
                                                v49,
                                                v50,
                                                v51,
                                                v52,
                                                v53);
              if ( vht_ch_width == 4 )
                v122 = 2;
              else
                v122 = vht_ch_width;
              lim_update_channel_width(a1, (_BYTE *)v100, a3, v122, (unsigned int *)&v251);
            }
          }
LABEL_81:
          if ( (*(_BYTE *)(a3 + 10020) & 1) != 0
            || (v123 = *(_QWORD *)(a3 + 16)) == 0
            || (v124 = *(_QWORD *)(v123 + 40)) == 0
            || (unsigned int)(*(_DWORD *)(v124 + 28) - 21) > 9
            || !*(_BYTE *)(a3 + 8740)
            || !byte_84FA7C )
          {
LABEL_95:
            v127 = *(_QWORD *)(v100 + 818);
            v128 = *(_QWORD *)(v100 + 823);
            v129 = (unsigned __int8)*(_QWORD *)(v100 + 810);
            v251 = *(_QWORD *)(v100 + 810);
            *(_QWORD *)v252 = v127;
            *(_QWORD *)&v252[5] = v128;
            if ( v129 | (unsigned __int8)qword_84FA8E && (unsigned int)qdf_mem_cmp(&v251, &qword_84FA8E, 0x15u) )
            {
              v131 = qword_84FA8E;
              v130 = qword_84FA96;
              *(_QWORD *)(v100 + 823) = *(__int64 *)((char *)&qword_84FA96 + 5);
              *(_QWORD *)(v100 + 810) = v131;
              *(_QWORD *)(v100 + 818) = v130;
              lim_update_vdev_sr_elements(a3, v100, v46, v47, v48, v49, v50, v51, v52, v53);
              lim_handle_sr_cap(*(_QWORD *)(a3 + 16), 2u, v132, v133, v134, v135, v136, v137, v138, v139);
            }
            goto LABEL_98;
          }
          v125 = *(unsigned __int8 *)(a3 + 8745);
          if ( byte_84FB0C && (v125 & 0x3F) != (byte_84FB0E & 0x3F) )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: bss color changed from [%d] to [%d]",
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              "sch_bcn_update_he_ies");
            v126 = *(unsigned __int8 *)(a3 + 8745);
            *(_BYTE *)(a3 + 8745) = v126 & 0xC0 | byte_84FB0E & 0x3F;
            if ( v126 >> 7 == (unsigned __int8)byte_84FA81 >> 7 )
            {
LABEL_94:
              lim_send_he_ie_update(v46, v47, v48, v49, v50, v51, v52, v53, a1, a3);
              goto LABEL_95;
            }
          }
          else if ( v125 >> 7 == (unsigned __int8)byte_84FA81 >> 7 )
          {
            goto LABEL_95;
          }
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: color disable flag changed from [%d] to [%d]",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "sch_bcn_update_he_ies");
          *(_BYTE *)(a3 + 8745) = byte_84FA81 & 0x80 | *(_BYTE *)(a3 + 8745) & 0x7F;
          goto LABEL_94;
        }
        v101 = "%s: Ignore opmode change as there is EHT operation information";
      }
      qdf_trace_msg(0x35u, 8u, v101, v46, v47, v48, v49, v50, v51, v52, v53, "sch_bcn_update_opmode_change");
      goto LABEL_81;
    }
  }
LABEL_98:
  v140 = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a3 + 16), v46, v47, v48, v49, v50, v51, v52, v53);
  if ( !v140 )
  {
    v158 = "%s: vdev component object is NULL";
LABEL_129:
    qdf_trace_msg(0x35u, 2u, v158, v141, v142, v143, v144, v145, v146, v147, v148, "__sch_beacon_process_for_session");
    goto LABEL_166;
  }
  v149 = v140;
  if ( !wlan_reg_is_6ghz_chan_freq(dword_84F038) )
  {
    v159 = wlan_mlme_skip_tpe(*(_QWORD *)(a1 + 21552));
    v168 = 0;
    goto LABEL_105;
  }
  if ( !byte_84F15C )
  {
    v158 = "%s: Channel is 6G but country IE not present";
    goto LABEL_129;
  }
  if ( (byte_84FA7F & 0x20) != 0 )
  {
    *(_BYTE *)(a3 + 10068) = ((unsigned __int8)byte_84FA89 >> 3) & 0xF;
    if ( (lim_is_ap_power_type_6g_invalid(a3) & 1) != 0 )
    {
      *(_BYTE *)(a3 + 10068) = 4;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: AP power type is invalid, defaulting to MAX_AP_TYPE",
        v150,
        v151,
        v152,
        v153,
        v154,
        v155,
        v156,
        v157,
        "__sch_beacon_process_for_session");
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: AP power type is null, defaulting to MAX_AP_TYPE",
      v141,
      v142,
      v143,
      v144,
      v145,
      v146,
      v147,
      v148,
      "__sch_beacon_process_for_session");
    *(_BYTE *)(a3 + 10068) = 4;
  }
  v193 = *(unsigned __int8 *)(a3 + 10068);
  if ( v193 == 2 )
  {
    if ( (wlan_reg_is_indoor_ap_detected(*(_QWORD *)(a1 + 21560), v150, v151, v152, v153, v154, v155, v156, v157) & 1) != 0 )
    {
      v193 = 3;
      *(_BYTE *)(a3 + 10068) = 3;
    }
    else
    {
      v193 = *(unsigned __int8 *)(a3 + 10068);
    }
  }
  if ( !(unsigned int)wlan_reg_get_best_6g_power_type(
                        *(_QWORD *)(a1 + 21552),
                        *(_QWORD *)(a1 + 21560),
                        (unsigned int *)&v240,
                        v193,
                        dword_84F038,
                        v150,
                        v151,
                        v152,
                        v153,
                        v154,
                        v155,
                        v156,
                        v157) )
  {
    v202 = v240;
    v203 = *(_QWORD *)(a3 + 16);
    v180 = v240 == *(unsigned __int8 *)(a3 + 10069);
    *(_BYTE *)(a3 + 10069) = v240;
    v168 = !v180;
    mlme_set_best_6g_power_type(v203, v202, v194, v195, v196, v197, v198, v199, v200, v201);
    v159 = 0;
LABEL_105:
    if ( (wlan_reg_is_ext_tpc_supported(*(_QWORD *)(a1 + 21552), v160, v161, v162, v163, v164, v165, v166, v167) & 1) == 0 )
    {
      if ( (*(_BYTE *)(a3 + 10070) & 1) == 0 )
      {
        channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(
                                       *(_QWORD *)(a1 + 21560),
                                       *(_DWORD *)(a3 + 284),
                                       v169,
                                       v170,
                                       v171,
                                       v172,
                                       v173,
                                       v174,
                                       v175,
                                       v176);
        if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3338LL) == 1 )
        {
          v191 = byte_84F981 != 0;
          if ( byte_84F981 )
            v192 = byte_84F982;
          else
            v192 = channel_reg_power_for_freq;
          if ( *(_BYTE *)(a1 + 20136) && byte_84F9A1 )
          {
            v191 = 0;
            v192 = channel_reg_power_for_freq - byte_84F45E;
          }
        }
        else
        {
          v191 = 0;
          v192 = channel_reg_power_for_freq;
        }
        *(_BYTE *)(v149 + 932) = v191;
        *(_BYTE *)(v149 + 536) = channel_reg_power_for_freq;
        *(_BYTE *)(v149 + 552) = v192;
        *(_DWORD *)(v149 + 556) = *(_DWORD *)(a3 + 284);
        max_tx_power = lim_get_max_tx_power(a1, v149, v183, v184, v185, v186, v187, v188, v189, v190);
        if ( max_tx_power != *(_BYTE *)(a3 + 7032) )
        {
          v205 = max_tx_power;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: New maxTx power %d, old pwr %d",
            v169,
            v170,
            v171,
            v172,
            v173,
            v174,
            v175,
            v176,
            "__sch_beacon_process_for_session",
            (unsigned int)max_tx_power);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: regMax %d, local %d",
            v206,
            v207,
            v208,
            v209,
            v210,
            v211,
            v212,
            v213,
            "__sch_beacon_process_for_session",
            (unsigned int)channel_reg_power_for_freq,
            (unsigned int)v192);
          if ( !(unsigned int)lim_send_set_max_tx_power_req(
                                a1,
                                v205,
                                (unsigned __int8 *)a3,
                                v214,
                                v215,
                                v216,
                                v217,
                                v218,
                                v219,
                                v220,
                                v221) )
            *(_BYTE *)(a3 + 7032) = v205;
        }
      }
      goto LABEL_153;
    }
    if ( (*(_BYTE *)(a3 + 10070) & 1) == 0 )
    {
      lim_parse_tpe_ie(
        a1,
        a3,
        qword_84FC83,
        byte_84FC82,
        v169,
        v170,
        v171,
        v172,
        v173,
        v174,
        v175,
        v176,
        (__int64)&byte_84FA7C,
        v241);
      if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3338LL) != 1 )
        goto LABEL_118;
      v177 = (unsigned __int8)byte_84F981;
      v178 = byte_84F982;
      v179 = byte_84F45E;
      if ( !byte_84F981 )
        v178 = 0;
      v180 = !*(_BYTE *)(a1 + 20136) || byte_84F9A1 == 0;
      if ( v180 )
      {
        v179 = v178;
        v181 = 1;
      }
      else
      {
        v181 = 0;
      }
      if ( *(unsigned __int8 *)(v149 + 552) != v179 )
      {
        *(_BYTE *)(v149 + 552) = v179;
        if ( v177 )
          v222 = v181;
        else
          v222 = 0;
        *(_BYTE *)(v149 + 932) = v222;
      }
      else
      {
LABEL_118:
        if ( v159 & 1 | ((v241[0] & 1) == 0) && ((*(unsigned __int8 *)(a3 + 10075) | v168) & 1) == 0 )
          goto LABEL_153;
      }
      if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a3 + 284)) && *(_BYTE *)(a3 + 10069) == 3 )
        lim_set_tpc_power(a1, a3, 0, 1, v223, v224, v225, v226, v227, v228, v229, v230);
      lim_set_tpc_power(a1, a3, 0, 0, v223, v224, v225, v226, v227, v228, v229, v230);
      *(_BYTE *)(a3 + 10075) = 0;
    }
LABEL_153:
    if ( byte_84F4DC )
      v231 = wlan_reg_legacy_chan_to_freq(
               *(_QWORD *)(a1 + 21560),
               (unsigned __int8)byte_84F4DD,
               v169,
               v170,
               v171,
               v172,
               v173,
               v174,
               v175,
               v176);
    else
      v231 = dword_84F038;
    lim_received_hb_handler(a1, v231, a3);
    if ( v55 )
      lim_send_probe_req_mgmt_frame(a1, a3, nullptr, nullptr, v232, v233, v234, v235, v236, v237, v238, v239);
    if ( !*(_BYTE *)(a1 + 14809) && HIWORD(v244) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Beacon for session[%d] got changed param change bitmap: 0x%x",
        v232,
        v233,
        v234,
        v235,
        v236,
        v237,
        v238,
        v239,
        "__sch_beacon_process_for_session",
        *(unsigned __int16 *)(a3 + 8));
      lim_send_beacon_params(a1, (unsigned __int16 *)&v243, a3);
    }
    if ( *(_DWORD *)(a3 + 7036) == 2 )
    {
      if ( *(_BYTE *)(a3 + 8673) == 1 )
      {
        lim_p2p_oper_chan_change_confirm_action_frame(
          a1,
          (unsigned __int8 *)(a3 + 24),
          a3,
          v232,
          v233,
          v234,
          v235,
          v236,
          v237,
          v238,
          v239);
        *(_BYTE *)(a3 + 8673) = 0;
      }
      if ( *(_BYTE *)(a3 + 9795) == 1 )
        lim_send_channel_usage_req_notif_cap_action_frame(
          *(unsigned __int8 *)(a3 + 10),
          v232,
          v233,
          v234,
          v235,
          v236,
          v237,
          v238,
          v239);
    }
  }
LABEL_166:
  _ReadStatusReg(SP_EL0);
}
