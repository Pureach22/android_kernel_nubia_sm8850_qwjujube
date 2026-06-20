__int64 __fastcall hdd_sme_roam_callback(
        unsigned __int8 *a1,
        unsigned int *a2,
        int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _DWORD *v12; // x25
  unsigned int v14; // w23
  __int64 e_roam_cmd_status_str; // x24
  __int64 e_csr_roam_result_str; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 result; // x0
  _DWORD *v37; // x21
  __int64 v38; // x22
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  int v48; // w23
  unsigned int gfp_flags; // w0
  int v50; // w8
  unsigned int v51; // w20
  const char *v52; // x2
  const char *v53; // x3
  __int64 *v54; // x22
  int v55; // w20
  __int64 v56; // x8
  __int64 v57; // x1
  unsigned int v58; // w19
  unsigned int v59; // w21
  unsigned int v60; // w20
  __int64 v61; // x8
  _DWORD *v62; // x21
  __int64 v63; // x21
  __int64 v64; // x4
  unsigned __int8 *v65; // x22
  __int64 v66; // x20
  unsigned int v67; // w8
  const char *v68; // x2
  _DWORD *v69; // x22
  __int64 *v70; // x21
  int v71; // w8
  __int64 vdev_by_user; // x0
  __int64 v73; // x20
  char connected_vdev_by_bssid; // w0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  int v83; // w9
  int v84; // w8
  __int64 v85; // x1
  unsigned __int64 v86; // x23
  int v87; // w10
  int v88; // w24
  unsigned int v89; // w9
  unsigned __int64 v90; // x26
  __int64 v91; // x19
  __int64 v92; // x22
  unsigned int v93; // w9
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  char *v102; // x26
  __int64 v103; // x8
  __int64 v104; // x19
  __int64 v105; // x27
  char *v106; // x26
  __int64 v107; // x28
  __int64 v108; // x8
  __int64 v109; // x8
  char *v110; // x26
  const char *v111; // x2
  const char *v112; // x3
  unsigned __int16 *v113; // x8
  unsigned int v114; // w19
  unsigned int v115; // w20
  _BOOL4 v116; // w21
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  __int64 v125; // x20
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  char v134; // w8
  unsigned int v135; // w1
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  __int64 v144; // x19
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  unsigned int *v153; // x8
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  __int64 peer_mld_addr; // x0
  unsigned int *v171; // x8
  double v172; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  int v180; // w9
  unsigned __int8 *v181; // x19
  double v182; // d0
  double v183; // d1
  double v184; // d2
  double v185; // d3
  double v186; // d4
  double v187; // d5
  double v188; // d6
  double v189; // d7
  __int64 cmpt_obj; // x0
  char v191; // w23
  __int64 v192; // x0
  double v193; // d0
  double v194; // d1
  double v195; // d2
  double v196; // d3
  double v197; // d4
  double v198; // d5
  double v199; // d6
  double v200; // d7
  __int64 v201; // x19
  double v202; // d0
  double v203; // d1
  double v204; // d2
  double v205; // d3
  double v206; // d4
  double v207; // d5
  double v208; // d6
  double v209; // d7
  double v210; // d0
  double v211; // d1
  double v212; // d2
  double v213; // d3
  double v214; // d4
  double v215; // d5
  double v216; // d6
  double v217; // d7
  __int64 v218; // [xsp+0h] [xbp-190h]
  __int64 v219; // [xsp+8h] [xbp-188h]
  __int64 v220; // [xsp+10h] [xbp-180h]
  __int64 v221; // [xsp+18h] [xbp-178h]
  __int64 v222; // [xsp+20h] [xbp-170h]
  __int64 v223; // [xsp+28h] [xbp-168h]
  __int64 v224; // [xsp+30h] [xbp-160h]
  __int64 v225; // [xsp+38h] [xbp-158h]
  __int64 v226; // [xsp+40h] [xbp-150h]
  __int64 v227; // [xsp+48h] [xbp-148h]
  __int64 v228; // [xsp+50h] [xbp-140h]
  __int64 v229; // [xsp+58h] [xbp-138h]
  int v230; // [xsp+60h] [xbp-130h]
  char v231[4]; // [xsp+6Ch] [xbp-124h] BYREF
  int n; // [xsp+70h] [xbp-120h] BYREF
  __int16 n_4; // [xsp+74h] [xbp-11Ch]
  char s[8]; // [xsp+78h] [xbp-118h] BYREF
  __int64 v235; // [xsp+80h] [xbp-110h] BYREF
  __int64 v236; // [xsp+88h] [xbp-108h]
  __int64 v237; // [xsp+90h] [xbp-100h]
  __int64 v238; // [xsp+98h] [xbp-F8h]
  __int64 v239; // [xsp+A0h] [xbp-F0h]
  __int64 v240; // [xsp+A8h] [xbp-E8h]
  __int64 v241; // [xsp+B0h] [xbp-E0h]
  _QWORD v242[27]; // [xsp+B8h] [xbp-D8h] BYREF

  v242[25] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_DWORD **)a1;
  if ( **(_DWORD **)a1 != 1885692259 )
  {
    v52 = "%s: Invalid adapter or adapter has invalid magic";
    v53 = "hdd_sme_roam_callback";
    goto LABEL_15;
  }
  v14 = a1[8];
  e_roam_cmd_status_str = get_e_roam_cmd_status_str((unsigned int)a3);
  e_csr_roam_result_str = get_e_csr_roam_result_str(a4);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev %d status %s(%d) result %s(%d)",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "hdd_sme_roam_callback",
    v14,
    e_roam_cmd_status_str,
    (unsigned int)a3,
    e_csr_roam_result_str,
    a4);
  qdf_trace(51, 0x4Au, a1[8], a3);
  result = 0;
  if ( a3 > 35 )
  {
    if ( a3 <= 41 )
    {
      if ( a3 == 36 )
      {
        if ( a2 && v12 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: CCXADJAPREP=%u",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "hdd_indicate_ese_adj_ap_rep_ind",
            *((unsigned __int16 *)a2 + 51));
          snprintf(s, 0x100u, "CCXADJAPREP=%u", *((unsigned __int16 *)a2 + 51));
        }
        goto LABEL_140;
      }
      if ( a3 == 37 )
      {
        LOBYTE(n) = 0;
        if ( !a2 || !v12 )
          goto LABEL_140;
        v61 = *((_QWORD *)a2 + 13);
        if ( *(unsigned __int8 *)(v61 + 2) >= 2u )
        {
          if ( !*(_BYTE *)(v61 + 3) )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Measurement Done but no scan results",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "hdd_indicate_ese_bcn_report_ind");
            v113 = *((unsigned __int16 **)a2 + 13);
            v114 = *v113;
            v115 = *((unsigned __int8 *)v113 + 3);
            v116 = *((_BYTE *)v113 + 2) != 0;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: CCXBCNREP=%d %d %d",
              v117,
              v118,
              v119,
              v120,
              v121,
              v122,
              v123,
              v124,
              "hdd_indicate_ese_bcn_report_no_results",
              *v113,
              *((_BYTE *)v113 + 2) != 0,
              *((unsigned __int8 *)v113 + 3));
            snprintf(s, 0x100u, "CCXBCNREP=%d %d %d", v114, v116, v115);
            goto LABEL_140;
          }
        }
        else if ( !*(_BYTE *)(v61 + 3) )
        {
          goto LABEL_140;
        }
        v86 = 0;
        v87 = 0;
        while ( 1 )
        {
          v88 = 0;
          v241 = 0;
          memset(v242, 0, 192);
          v239 = 0;
          v240 = 0;
          v237 = 0;
          v238 = 0;
          v235 = 0;
          v236 = 0;
          *(_QWORD *)s = 0;
          v89 = *(unsigned __int8 *)(v61 + 3);
          v230 = v87;
          v231[0] = 0;
          if ( v89 > (unsigned __int8)v87 )
            break;
LABEL_80:
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Sending %d BSS Info",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "hdd_indicate_ese_bcn_report_ind",
            (unsigned __int8)v88);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: CCXBCNREP=%d %d %d %d",
            v94,
            v95,
            v96,
            v97,
            v98,
            v99,
            v100,
            v101,
            "hdd_indicate_ese_bcn_report_ind",
            **((unsigned __int16 **)a2 + 13),
            *(unsigned __int8 *)(*((_QWORD *)a2 + 13) + 2LL),
            (unsigned __int8)v88,
            (unsigned __int8)v231[0]);
          v102 = &s[snprintf(
                      s,
                      0x100u,
                      "CCXBCNREP=%d %d %d ",
                      **((unsigned __int16 **)a2 + 13),
                      *(unsigned __int8 *)(*((_QWORD *)a2 + 13) + 2LL),
                      (unsigned __int8)v88)];
          qdf_mem_copy(v102, v231, 1u);
          if ( (_BYTE)v88 )
          {
            v103 = 8;
            if ( v86 < 8 )
              v103 = v86;
            v104 = 40 * v103 - 320;
            v105 = 0;
            v106 = v102 + 1;
            v107 = 40 * v86;
            while ( v104 + v105 )
            {
              v108 = *((_QWORD *)a2 + 13) + v107 + v105;
              LODWORD(v228) = *(unsigned __int8 *)(v108 + 18);
              LODWORD(v227) = *(unsigned __int8 *)(v108 + 17);
              LODWORD(v229) = *(unsigned __int8 *)(v108 + 19);
              LODWORD(v226) = *(unsigned __int8 *)(v108 + 16);
              LODWORD(v225) = *(unsigned __int8 *)(v108 + 15);
              LODWORD(v224) = *(unsigned __int8 *)(v108 + 14);
              LODWORD(v223) = *(unsigned __int16 *)(v108 + 34);
              LODWORD(v222) = *(unsigned __int16 *)(v108 + 32);
              LODWORD(v221) = *(_DWORD *)(v108 + 28);
              LODWORD(v220) = *(_DWORD *)(v108 + 24);
              LODWORD(v219) = *(_DWORD *)(v108 + 20);
              LODWORD(v218) = *(unsigned __int8 *)(v108 + 13);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: ChanNum(%d) Spare(%d) MeasDuration(%d) PhyType(%d) RecvSigPower(%d) ParentTSF(%u) TargetTSF[0](%u) T"
                "argetTSF[1](%u) BeaconInterval(%u) CapabilityInfo(%d) BSSID(%02X:%02X:%02X:%02X:%02X:%02X)",
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                "hdd_indicate_ese_bcn_report_ind",
                *(unsigned __int8 *)(v108 + 8),
                *(unsigned __int8 *)(v108 + 9),
                *(unsigned __int16 *)(v108 + 10),
                *(unsigned __int8 *)(v108 + 12),
                v218,
                v219,
                v220,
                v221,
                v222,
                v223,
                v224,
                v225,
                v226,
                v227,
                v228,
                v229);
              v109 = *((_QWORD *)a2 + 13);
              LOBYTE(n) = 28;
              qdf_mem_copy(v106, (const void *)(v109 + v107 + v105 + 8), 0x1Cu);
              v110 = &v106[(unsigned __int8)n];
              LOBYTE(n) = *(_BYTE *)(*((_QWORD *)a2 + 13) + v107 + v105 + 36);
              qdf_mem_copy(v110++, &n, 1u);
              qdf_mem_copy(v110, *(const void **)(*((_QWORD *)a2 + 13) + v107 + v105 + 40), (unsigned __int8)n);
              v105 += 40;
              v106 = &v110[(unsigned __int8)n];
              if ( 40LL * (unsigned __int8)v88 == v105 )
                goto LABEL_71;
            }
            goto LABEL_142;
          }
LABEL_71:
          v61 = *((_QWORD *)a2 + 13);
          v87 = v88 + v230;
          v86 = (unsigned __int8)(v88 + v230);
          if ( *(unsigned __int8 *)(v61 + 3) <= (unsigned int)(unsigned __int8)(v88 + v230) )
            goto LABEL_140;
        }
        v88 = 0;
        v90 = (unsigned __int8)v87;
        if ( (unsigned __int8)v87 <= 8u )
          v91 = 8;
        else
          v91 = (unsigned __int8)v87;
        v92 = 40LL * (unsigned __int8)v87 + 36;
        while ( v91 != v90 )
        {
          v93 = (unsigned __int8)v231[0] + (unsigned __int8)(*(_BYTE *)(v61 + v92) + 29);
          LOBYTE(n) = *(_BYTE *)(v61 + v92) + 29;
          if ( v93 <= 0xEE )
          {
            v231[0] = v93;
            ++v88;
            LODWORD(v218) = v93;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: i(%d) sizeof bcnReportFields(%d) IeLength(%d) Length of Ie(%d) totLen(%d)",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "hdd_indicate_ese_bcn_report_ind",
              (unsigned int)v90,
              28,
              1,
              *(unsigned __int8 *)(v61 + v92),
              v218);
            v61 = *((_QWORD *)a2 + 13);
            ++v90;
            v92 += 40;
            if ( v90 < *(unsigned __int8 *)(v61 + 3) )
              continue;
          }
          goto LABEL_80;
        }
LABEL_142:
        __break(0x5512u);
      }
      goto LABEL_141;
    }
    if ( a3 != 42 )
    {
      if ( a3 == 43 )
      {
        hdd_ndp_event_handler(a1, a2, 43, a4);
        goto LABEL_140;
      }
      if ( a3 == 49 )
      {
        if ( !a2 )
          goto LABEL_140;
        v37 = *(_DWORD **)a1;
        v38 = *((_QWORD *)a2 + 41);
        v235 = 0;
        v236 = 0;
        v39 = *((_QWORD *)v37 + 3);
        v241 = 0;
        v242[0] = 0;
        v239 = 0;
        v240 = 0;
        v237 = 0;
        v238 = 0;
        *(_QWORD *)s = 0;
        if ( (unsigned int)_wlan_hdd_validate_context(v39, "wlan_hdd_sae_callback") )
          goto LABEL_140;
        if ( v38 )
        {
          v48 = 1027080;
          gfp_flags = cds_get_gfp_flags();
          v50 = *(_DWORD *)(v38 + 48);
          v51 = gfp_flags;
          switch ( v50 )
          {
            case 25:
              v48 = 1027097;
              break;
            case 24:
              v48 = 1027096;
              break;
            case 9:
              v48 = 1027081;
              break;
          }
          HIDWORD(v239) = v48;
          *(_DWORD *)s = 0;
          qdf_ether_addr_copy(&s[4], (_WORD *)(v38 + 8));
          v144 = *((_QWORD *)a1 + 4);
          if ( !v144 )
            goto LABEL_140;
          n_4 = 0;
          n = 0;
          wlan_objmgr_vdev_get_ref(v144, 5u, v136, v137, v138, v139, v140, v141, v142, v143);
          if ( (wlan_cm_is_sae_auth_addr_conversion_required(v144, v145, v146, v147, v148, v149, v150, v151, v152) & 1) == 0 )
            goto LABEL_128;
          if ( ucfg_cm_is_vdev_roaming(v144, v154, v155, v156, v157, v158, v159, v160, v161) )
          {
            peer_mld_addr = wlan_cm_roaming_get_peer_mld_addr(v144, v162, v163, v164, v165, v166, v167, v168, v169);
            if ( peer_mld_addr )
            {
              v180 = *(_DWORD *)peer_mld_addr;
              n_4 = *(_WORD *)(peer_mld_addr + 4);
              n = v180;
LABEL_127:
              qdf_mem_copy(v242, &n, 6u);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Sending MLD:%02x:%02x:%02x:**:**:%02x to userspace",
                v210,
                v211,
                v212,
                v213,
                v214,
                v215,
                v216,
                v217,
                "wlan_hdd_sae_update_mld_addr",
                (unsigned __int8)n,
                BYTE1(n),
                BYTE2(n),
                HIBYTE(n_4));
LABEL_128:
              wlan_objmgr_vdev_release_ref(v144, 5u, v153, v154, v155, v156, v157, v158, v159, v160, v161);
              qdf_mem_copy((char *)&v235 + 2, (const void *)(v38 + 15), *(unsigned __int8 *)(v38 + 14));
              BYTE2(v239) = *(_BYTE *)(v38 + 14);
              cfg80211_external_auth_request(*((_QWORD *)v37 + 4), s, v51);
              v111 = "%s: SAE: sent cmd";
              v112 = "wlan_hdd_sae_callback";
LABEL_138:
              v135 = 8;
              goto LABEL_139;
            }
          }
          else if ( !(unsigned int)wlan_vdev_get_bss_peer_mld_mac(
                                     v144,
                                     &n,
                                     v162,
                                     v163,
                                     v164,
                                     v165,
                                     v166,
                                     v167,
                                     v168,
                                     v169) )
          {
            goto LABEL_127;
          }
          wlan_objmgr_vdev_release_ref(v144, 5u, v171, v172, v173, v174, v175, v176, v177, v178, v179);
LABEL_140:
          result = 0;
          goto LABEL_141;
        }
        v111 = "%s: SAE info in NULL";
        v112 = "wlan_hdd_sae_callback";
LABEL_100:
        v135 = 2;
LABEL_139:
        qdf_trace_msg(0x33u, v135, v111, v40, v41, v42, v43, v44, v45, v46, v47, v112);
        goto LABEL_140;
      }
      goto LABEL_141;
    }
    v69 = *(_DWORD **)a1;
    if ( !*(_QWORD *)a1 )
      goto LABEL_140;
    v70 = *((__int64 **)v69 + 3);
    if ( !v70 || !v70[2] )
      goto LABEL_140;
    v71 = v69[10];
    s[0] = 0;
    if ( !v71 )
      sme_start_roaming();
    *((_DWORD *)a1 + 175) = a2[35];
    *((_DWORD *)a1 + 235) = a2[44];
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_roam_channel_switch_handler");
    if ( !vdev_by_user )
    {
      v111 = "%s: Invalid vdev";
      v112 = "hdd_roam_channel_switch_handler";
      goto LABEL_100;
    }
    v73 = vdev_by_user;
    if ( (v69[10] | 2) != 2 )
      goto LABEL_61;
    connected_vdev_by_bssid = wlan_get_connected_vdev_by_bssid(v70[1], a1 + 308, s);
    v83 = (unsigned __int8)s[0];
    v84 = a1[8];
    if ( (connected_vdev_by_bssid & 1) != 0 && v84 == (unsigned __int8)s[0] )
    {
      if ( ucfg_cm_is_vdev_active(v73, v75, v76, v77, v78, v79, v80, v81, v82) )
      {
LABEL_61:
        v85 = system_wq;
        *((_DWORD *)a1 + 1501) = 1;
        queue_work_on(32, v85, a1 + 6008);
        goto LABEL_113;
      }
      v83 = (unsigned __int8)s[0];
      v84 = a1[8];
    }
    LODWORD(v218) = v84;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: BSS %02x:%02x:%02x:**:**:%02x no connected with vdev %d (%d)",
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      "hdd_roam_channel_switch_handler",
      a1[308],
      a1[309],
      a1[310],
      a1[313],
      v218,
      v83);
LABEL_113:
    if ( (unsigned int)policy_mgr_set_hw_mode_on_channel_switch(*v70, a1[8]) )
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: set hw mode change not done",
        v182,
        v183,
        v184,
        v185,
        v186,
        v187,
        v188,
        v189,
        "hdd_roam_channel_switch_handler");
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v73, v182, v183, v184, v185, v186, v187, v188, v189);
    if ( cmpt_obj )
    {
      v191 = *(_BYTE *)(cmpt_obj + 197);
      _hdd_objmgr_put_vdev_by_user(v73, 6, "hdd_roam_channel_switch_handler");
      if ( (v191 & 1) != 0 )
        goto LABEL_120;
    }
    else
    {
      _hdd_objmgr_put_vdev_by_user(v73, 6, "hdd_roam_channel_switch_handler");
    }
    policy_mgr_check_concurrent_intf_and_restart_sap(*v70, a1[1424] != 0);
LABEL_120:
    wlan_twt_concurrency_update(v70);
    if ( (v69[10] | 2) == 2 )
    {
      v192 = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_roam_channel_switch_handler");
      if ( v192 )
      {
        v201 = v192;
        if ( (unsigned int)if_mgr_deliver_event(v192, 0x13u, 0, v193, v194, v195, v196, v197, v198, v199, v200) )
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Failed to deliver CSA complete evt",
            v202,
            v203,
            v204,
            v205,
            v206,
            v207,
            v208,
            v209,
            "hdd_roam_channel_switch_handler");
        _hdd_objmgr_put_vdev_by_user(v201, 6, "hdd_roam_channel_switch_handler");
      }
    }
    goto LABEL_140;
  }
  if ( a3 <= 32 )
  {
    if ( a3 == 14 )
    {
      v62 = *(_DWORD **)a1;
      if ( (hdd_cm_is_vdev_associated(a1) & 1) != 0 )
        cfg80211_michael_mic_failure(
          *((_QWORD *)v62 + 4),
          *((_QWORD *)a2 + 11) + 6LL,
          *(unsigned __int8 *)(*((_QWORD *)a2 + 11) + 18LL) ^ 1u,
          *(unsigned __int8 *)(*((_QWORD *)a2 + 11) + 20LL),
          *((_QWORD *)a2 + 11) + 21LL,
          3264);
      goto LABEL_140;
    }
    if ( a3 != 17 )
      goto LABEL_141;
    v54 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
    qdf_trace_msg(0x33u, 8u, "%s: enter", v28, v29, v30, v31, v32, v33, v34, v35, "hdd_roam_set_key_complete_handler");
    if ( a2 )
    {
      if ( v54 && *v54 )
      {
        LODWORD(v218) = *((unsigned __int8 *)a2 + 25);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Set Key completion roam_status =%d roam_result=%d %02x:%02x:%02x:**:**:%02x",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "hdd_roam_set_key_complete_handler",
          17,
          a4,
          *((unsigned __int8 *)a2 + 23),
          *((unsigned __int8 *)a2 + 24),
          v218,
          *((unsigned __int8 *)a2 + 28));
        if ( (hdd_cm_is_vdev_associated(a1) & 1) == 0 )
        {
LABEL_137:
          policy_mgr_restart_opportunistic_timer(*v54, 0);
          v111 = "%s: exit";
          v112 = "hdd_roam_set_key_complete_handler";
          goto LABEL_138;
        }
        v55 = *((_DWORD *)a1 + 170);
        if ( a4 != 6
          || (v56 = *(_QWORD *)a1,
              v57 = a1[8],
              a1[694] = 1,
              (sme_neighbor_roam_is11r_assoc(*(_QWORD *)(*(_QWORD *)(v56 + 24) + 16LL), v57) & 1) != 0) )
        {
          a1[693] = 1;
        }
        if ( (unsigned int)(v55 - 1) > 3 )
        {
          if ( a1[693] != 1 )
            goto LABEL_134;
        }
        else if ( a1[694] != 1 || (a1[693] & 1) == 0 )
        {
LABEL_134:
          if ( a1[694] == 1 && a1[693] == 1 )
            *(_WORD *)(a1 + 693) = 0;
          goto LABEL_137;
        }
        v125 = *(_QWORD *)a1;
        s[0] = 0;
        if ( (ucfg_ipa_is_enabled() & 1) != 0 && !a1[684] && !*(_DWORD *)(v125 + 40) && *((_DWORD *)a1 + 169) >= 3u )
        {
          if ( (unsigned int)hdd_ipa_get_tx_pipe(*(_QWORD *)(v125 + 24), a1, s) )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Failed to get alternate pipe for vdev %d",
              v126,
              v127,
              v128,
              v129,
              v130,
              v131,
              v132,
              v133,
              "hdd_change_sta_state_authenticated",
              a1[8]);
            v134 = 0;
            s[0] = 0;
          }
          else
          {
            v134 = s[0];
          }
          ucfg_ipa_wlan_evt(
            *(_QWORD *)(*(_QWORD *)(v125 + 24) + 8LL),
            *(_QWORD *)(v125 + 32),
            *(unsigned int *)(v125 + 40),
            a1[8],
            4,
            a1 + 308,
            v134 & 1);
        }
        hdd_cm_set_peer_authenticate(a1, a1 + 308, 0);
        goto LABEL_134;
      }
      v52 = "%s: hdd_ctx or psoc is NULL";
    }
    else
    {
      v52 = "%s: roam_info is NULL";
    }
    v53 = "hdd_roam_set_key_complete_handler";
LABEL_15:
    qdf_trace_msg(0x33u, 2u, v52, a5, a6, a7, a8, a9, a10, a11, a12, v53);
    result = 16;
    goto LABEL_141;
  }
  if ( a3 == 33 )
  {
    if ( !a2 )
      goto LABEL_140;
    v63 = *a2;
    v64 = *((unsigned __int8 *)a2 + 4);
    v65 = *((unsigned __int8 **)a2 + 1);
    v66 = *(_QWORD *)a1;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Frame Type = %d Frame Length = %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "hdd_indicate_unprot_mgmt_frame",
      v64,
      (unsigned int)v63);
    if ( (unsigned int)_hdd_validate_adapter(v66, "hdd_indicate_unprot_mgmt_frame") )
      goto LABEL_140;
    if ( (_DWORD)v63 )
    {
      if ( v65 )
      {
        v67 = *v65;
        if ( ((v67 >> 2) & 3) != 0 )
        {
          v68 = "%s: Unexpected frame type %d";
        }
        else
        {
          v181 = a1 + 4096;
          if ( v67 >> 4 == 12 )
          {
            cfg80211_rx_unprot_mlme_mgmt(*(_QWORD *)(v66 + 32), v65, v63);
            result = 0;
            ++v181[440];
            goto LABEL_141;
          }
          if ( v67 >> 4 == 10 )
          {
            cfg80211_rx_unprot_mlme_mgmt(*(_QWORD *)(v66 + 32), v65, v63);
            result = 0;
            ++v181[441];
            goto LABEL_141;
          }
          v68 = "%s: Unexpected frame subtype %d";
        }
        qdf_trace_msg(0x33u, 3u, v68, v40, v41, v42, v43, v44, v45, v46, v47, "hdd_indicate_unprot_mgmt_frame");
        goto LABEL_140;
      }
      v111 = "%s: frame is NULL";
    }
    else
    {
      v111 = "%s: Frame Length is Invalid ZERO";
    }
    v112 = "hdd_indicate_unprot_mgmt_frame";
    goto LABEL_100;
  }
  if ( a3 == 34 )
  {
    if ( a2 && v12 )
    {
      v58 = *((unsigned __int8 *)a2 + 98);
      v59 = *((unsigned __int8 *)a2 + 99);
      v60 = *((unsigned __int16 *)a2 + 50);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: TSM Ind tid(%d) state(%d) MeasInt(%d)",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_indicate_tsm_ie",
        v58,
        v59,
        v60);
      snprintf(s, 0x100u, "TSMIE=%d:%d:%d", v58, v59, v60);
    }
    goto LABEL_140;
  }
LABEL_141:
  _ReadStatusReg(SP_EL0);
  return result;
}
