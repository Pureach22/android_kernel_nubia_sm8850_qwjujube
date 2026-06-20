__int64 __fastcall cm_get_valid_candidate(
        unsigned __int8 *a1,
        __int64 a2,
        unsigned __int8 *a3,
        char *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v14; // x8
  __int64 v15; // x0
  unsigned int v16; // w24
  __int64 v17; // x22
  _QWORD *v20; // x21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  unsigned int v30; // w23
  char v31; // w25
  int param; // w0
  int v33; // w24
  __int64 v34; // x24
  int v35; // w9
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x8
  __int64 v46; // x21
  __int16 v47; // w9
  __int64 v48; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v58; // w25
  unsigned __int64 v59; // x26
  __int64 v60; // x0
  __int64 v61; // x8
  __int64 v62; // x8
  __int64 v63; // x25
  unsigned int v64; // w26
  int v65; // w9
  __int64 v66; // x8
  __int64 v67; // x0
  __int64 v68; // x8
  int v69; // w9
  __int16 v70; // w10
  __int64 v71; // x10
  int v72; // w9
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  char v81; // w26
  _QWORD *v82; // x25
  __int64 v83; // x8
  __int64 v84; // x0
  unsigned int v85; // w25
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  unsigned int v94; // w24
  __int64 system_time; // x0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  char v104; // w28
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
  _QWORD *v121; // x1
  __int64 v122; // x0
  __int64 v123; // x8
  int v124; // w9
  __int16 v125; // w10
  __int64 v126; // x10
  int v127; // w9
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  char v136; // w8
  __int64 v137; // x8
  __int64 v138; // x24
  __int64 v139; // x27
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  unsigned int v148; // w25
  unsigned int v149; // w27
  unsigned int v150; // w28
  char v151; // w0
  int v152; // w27
  unsigned __int8 *v153; // x8
  int v154; // w9
  __int64 v155; // x28
  unsigned __int8 *v156; // x26
  __int64 psoc_ext_obj_fl; // x25
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  __int64 v166; // x0
  const void *v167; // x1
  __int64 v168; // x26
  __int64 scan_result; // x28
  int v170; // w8
  __int64 v171; // x7
  int v172; // w9
  int v173; // w10
  _QWORD *v174; // x1
  _QWORD *v175; // x26
  _QWORD *v176; // x27
  __int64 v177; // x1
  __int64 v178; // x1
  int v179; // t1
  bool v180; // zf
  double v181; // d0
  double v182; // d1
  double v183; // d2
  double v184; // d3
  double v185; // d4
  double v186; // d5
  double v187; // d6
  double v188; // d7
  int v189; // w0
  double v190; // d0
  double v191; // d1
  double v192; // d2
  double v193; // d3
  double v194; // d4
  double v195; // d5
  double v196; // d6
  double v197; // d7
  unsigned __int8 *v198; // x9
  __int64 v199; // x5
  int v200; // w8
  __int64 v201; // x6
  __int64 v202; // x7
  int v203; // w9
  unsigned int v204; // w6
  unsigned __int8 *v205; // x9
  __int64 v206; // x6
  __int64 v207; // x7
  int v208; // w8
  int v209; // w9
  __int64 v210; // x6
  __int64 v211; // x7
  int v212; // w9
  int v213; // w8
  char is_24ghz_ch_freq; // w0
  unsigned int v215; // w8
  __int64 v216; // x10
  __int64 v217; // x11
  __int64 v218; // x9
  _QWORD *v219; // x10
  __int64 v220; // x9
  _QWORD *v221; // x8
  __int64 v222; // x11
  __int64 v223; // x12
  __int64 v224; // x11
  __int64 v225; // x9
  __int64 v226; // x9
  __int64 v227; // x9
  double v228; // d0
  double v229; // d1
  double v230; // d2
  double v231; // d3
  double v232; // d4
  double v233; // d5
  double v234; // d6
  double v235; // d7
  double v236; // d0
  double v237; // d1
  double v238; // d2
  double v239; // d3
  double v240; // d4
  double v241; // d5
  double v242; // d6
  double v243; // d7
  __int64 v244; // x7
  int v245; // w8
  int v246; // w9
  int v247; // w10
  double v248; // d0
  double v249; // d1
  double v250; // d2
  double v251; // d3
  double v252; // d4
  double v253; // d5
  double v254; // d6
  double v255; // d7
  __int64 v256; // x7
  int v257; // w8
  int v258; // w9
  int v259; // w10
  __int64 v260; // [xsp+0h] [xbp-140h]
  __int64 v261; // [xsp+0h] [xbp-140h]
  __int64 v262; // [xsp+0h] [xbp-140h]
  __int64 v263; // [xsp+8h] [xbp-138h]
  __int64 v264; // [xsp+8h] [xbp-138h]
  __int64 v265; // [xsp+8h] [xbp-138h]
  __int64 v266; // [xsp+10h] [xbp-130h]
  __int64 v267; // [xsp+10h] [xbp-130h]
  __int64 v268; // [xsp+10h] [xbp-130h]
  __int64 v269; // [xsp+18h] [xbp-128h]
  __int64 v270; // [xsp+18h] [xbp-128h]
  int v271; // [xsp+18h] [xbp-128h]
  __int64 v272; // [xsp+18h] [xbp-128h]
  unsigned int v273; // [xsp+3Ch] [xbp-104h]
  int v274; // [xsp+3Ch] [xbp-104h]
  unsigned int v275; // [xsp+40h] [xbp-100h]
  unsigned __int8 *v276; // [xsp+40h] [xbp-100h]
  unsigned __int8 sta_mlo_conn_max_num; // [xsp+48h] [xbp-F8h]
  const void *v278; // [xsp+48h] [xbp-F8h]
  int v279; // [xsp+50h] [xbp-F0h]
  __int64 v280; // [xsp+50h] [xbp-F0h]
  char v281[4]; // [xsp+5Ch] [xbp-E4h] BYREF
  _QWORD *v282; // [xsp+60h] [xbp-E0h] BYREF
  _QWORD *v283; // [xsp+68h] [xbp-D8h] BYREF
  _QWORD *v284; // [xsp+70h] [xbp-D0h] BYREF
  _QWORD *v285; // [xsp+78h] [xbp-C8h] BYREF
  unsigned int v286[5]; // [xsp+84h] [xbp-BCh] BYREF
  _QWORD *v287; // [xsp+98h] [xbp-A8h] BYREF
  __int64 v288; // [xsp+A0h] [xbp-A0h]
  __int64 v289; // [xsp+A8h] [xbp-98h]
  __int64 v290; // [xsp+B0h] [xbp-90h]
  _BOOL8 v291; // [xsp+B8h] [xbp-88h]
  __int64 v292; // [xsp+C0h] [xbp-80h]
  __int64 v293; // [xsp+C8h] [xbp-78h]
  __int64 v294; // [xsp+D0h] [xbp-70h]
  __int64 v295; // [xsp+D8h] [xbp-68h]
  __int64 v296; // [xsp+E0h] [xbp-60h]
  __int64 v297; // [xsp+E8h] [xbp-58h]
  __int64 v298; // [xsp+F0h] [xbp-50h]
  __int64 v299; // [xsp+F8h] [xbp-48h]
  __int64 v300; // [xsp+100h] [xbp-40h]
  __int64 v301; // [xsp+108h] [xbp-38h]
  __int64 v302; // [xsp+110h] [xbp-30h]
  __int64 v303; // [xsp+118h] [xbp-28h]
  __int64 v304; // [xsp+120h] [xbp-20h]
  __int64 v305; // [xsp+128h] [xbp-18h]
  __int64 v306; // [xsp+130h] [xbp-10h]

  v306 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)a1;
  v282 = nullptr;
  v283 = nullptr;
  v281[0] = 0;
  v15 = *(_QWORD *)(v14 + 216);
  v16 = *(unsigned __int8 *)(v14 + 168);
  if ( !v15 || (v17 = *(_QWORD *)(v15 + 80)) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: Failed to find psoc",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "cm_get_valid_candidate",
      *(unsigned __int8 *)(v14 + 168),
      *(unsigned int *)(a2 + 16));
    v30 = 16;
    goto LABEL_21;
  }
  v20 = *(_QWORD **)(a2 + 1040);
  LOBYTE(v287) = *(_BYTE *)(v14 + 168);
  *(_WORD *)((char *)&v287 + 1) = -1;
  wlan_objmgr_pdev_iterate_obj_list(
    v15,
    2,
    (void (__fastcall *)(__int64, __int64, __int64))cm_get_vdev_id_with_active_vdev_op,
    (__int64)&v287,
    0,
    0x4Du);
  if ( BYTE2(v287) != 255 )
  {
    v29 = "%s: vdev %d cm_id 0x%x: Abort connection as sta/cli vdev %d is disconnecting";
    goto LABEL_9;
  }
  if ( !*(_QWORD *)(a2 + 1040) || BYTE1(v287) == 255 )
  {
    if ( *(unsigned __int8 *)(a2 + 1049) >= (unsigned int)a1[192] )
    {
      qdf_trace_msg(
        0x68u,
        4u,
        "%s: vdev %d cm_id 0x%x: %d attempts tried, max %d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "cm_get_valid_candidate",
        v16,
        *(unsigned int *)(a2 + 16));
      goto LABEL_10;
    }
    if ( *(_BYTE *)(a2 + 1049) )
    {
      v58 = *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL);
      v59 = qdf_mc_timer_get_system_time() - *(_QWORD *)(a2 + 1056);
      if ( v59 >> 3 >= 0xC35 )
      {
        v94 = *(_DWORD *)(a2 + 24);
        system_time = qdf_mc_timer_get_system_time();
        qdf_trace_msg(
          0x68u,
          4u,
          "%s: vdev %d cm_id 0x%x: Max time allocated (%d ms) for connect completed, cur time %lu, active time %lu and diff %lu",
          v96,
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          "cm_is_time_allowed_for_connect_attempt",
          v58,
          v94,
          25000,
          system_time,
          *(_QWORD *)(a2 + 1056),
          v59);
        goto LABEL_10;
      }
    }
    if ( a3 && v20 )
    {
      v60 = *(_QWORD *)a1;
      v61 = *(_QWORD *)(a2 + 1040);
      LOBYTE(v285) = 1;
      v62 = *(_QWORD *)(v61 + 24);
      v63 = *(_QWORD *)(*(_QWORD *)(v60 + 216) + 80LL);
      v64 = *(_DWORD *)(v62 + 1192);
      v279 = *(_DWORD *)(v62 + 1268);
      wlan_vdev_mlme_is_mlo_vdev(v60, v21, v22, v23, v24, v25, v26, v27, v28);
      wlan_mlme_get_sta_mlo_conn_max_num(v63);
      v65 = *((_DWORD *)a3 + 15);
      if ( v65 == 30 || v65 == 53 )
        goto LABEL_29;
      v153 = a3;
      if ( (v279 & 0x18000C00) != 0 )
      {
        wlan_mlme_get_sae_assoc_retry_count(v63, &v285);
        v153 = a3;
      }
      v154 = *((_DWORD *)v153 + 14);
      if ( v154 == 10 )
      {
        if ( (v279 & 0x18000C00) != 0 || (mlme_get_reconn_after_assoc_timeout_flag(v63, *v153) & 1) != 0 )
          goto LABEL_29;
      }
      else if ( v154 == 6
             && (*(_DWORD *)(*(_QWORD *)(a2 + 1024) + 16LL) == 1 || *(_DWORD *)(a2 + 1032) == 1)
             && (policy_mgr_will_freq_lead_to_mcc(v63, v64) & 1) == 0 )
      {
        v155 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
        v156 = *(unsigned __int8 **)(*(_QWORD *)(a2 + 1040) + 24LL);
        psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(v63, "cm_increase_retry_by_scan_age", 988);
        if ( psoc_ext_obj_fl )
        {
          v166 = _qdf_mem_malloc(0x2D8u, "cm_increase_retry_by_scan_age", 995);
          if ( !v166 )
            goto LABEL_105;
          v276 = v156;
          v167 = v156 + 1;
          *(_BYTE *)(v166 + 16) = 1;
          v168 = v166;
          v278 = v167;
          qdf_mem_copy((void *)(v166 + 70), v167, 6u);
          *(_QWORD *)(v168 + 8) = *(unsigned int *)(psoc_ext_obj_fl + 3680);
          scan_result = scm_get_scan_result(v155, v168);
          _qdf_mem_free(v168);
          if ( scan_result )
          {
            if ( *(_DWORD *)(scan_result + 16) )
            {
              v170 = (int)v278;
              if ( v278 )
              {
                v171 = v276[1];
                v170 = v276[2];
                v172 = v276[3];
                v173 = v276[6];
              }
              else
              {
                v172 = 0;
                v171 = 0;
                v173 = 0;
              }
              v271 = *(_DWORD *)(psoc_ext_obj_fl + 3680);
              LOBYTE(psoc_ext_obj_fl) = 2;
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: vdev %d cm_id 0x%x:  increase try num %d,%02x:%02x:%02x:**:**:%02x age < %d ms",
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                v27,
                v28,
                "cm_increase_retry_by_scan_age",
                *a3,
                *((unsigned int *)a3 + 1),
                2,
                v171,
                v170,
                v172,
                v173,
                v271);
            }
            else
            {
              LOBYTE(psoc_ext_obj_fl) = 0;
            }
            scm_purge_scan_results(scan_result);
          }
          else
          {
LABEL_105:
            LOBYTE(psoc_ext_obj_fl) = 0;
          }
        }
        else
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: vdev %d cm_id 0x%x:  psoc mlme obj is NULL ",
            v158,
            v159,
            v160,
            v161,
            v162,
            v163,
            v164,
            v165,
            "cm_increase_retry_by_scan_age",
            *a3,
            *((unsigned int *)a3 + 1));
        }
        LOBYTE(v285) = (_BYTE)v285 + psoc_ext_obj_fl;
LABEL_29:
        if ( *(unsigned __int8 *)(a2 + 1048) < (unsigned int)(unsigned __int8)v285 )
        {
          v66 = *(_QWORD *)(a2 + 1040);
          v287 = nullptr;
          v288 = 0;
          v289 = 0;
          v67 = *(_QWORD *)a1;
          v68 = *(_QWORD *)(v66 + 24);
          v292 = 0;
          v293 = 0;
          v69 = *(_DWORD *)(v68 + 1192);
          v70 = *(_WORD *)(v68 + 68);
          v290 = v68;
          v291 = 0;
          LODWORD(v289) = v69;
          WORD2(v289) = v70;
          v71 = *(_QWORD *)(v68 + 1824);
          v72 = *(_DWORD *)(v68 + 1);
          WORD2(v288) = *(_WORD *)(v68 + 5);
          LODWORD(v288) = v72;
          v291 = v71 != 0;
          if ( !(unsigned int)if_mgr_deliver_event(v67, 4u, (__int64)&v287, v21, v22, v23, v24, v25, v26, v27, v28) )
          {
            LODWORD(v269) = *((_DWORD *)a3 + 14);
            LODWORD(v266) = *((_DWORD *)a3 + 15);
            LODWORD(v263) = a3[13];
            LODWORD(v260) = a3[10];
            qdf_trace_msg(
              0x68u,
              4u,
              "%s: vdev %d cm_id 0x%x: Retry again with %02x:%02x:%02x:**:**:%02x, status code %d reason %d key_mgmt 0x%x"
              " retry count %d max retry %d",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              "cm_is_retry_with_same_candidate",
              *a3,
              *((unsigned int *)a3 + 1),
              a3[8],
              a3[9],
              v260,
              v263,
              v266,
              v269,
              v279,
              *(unsigned __int8 *)(a2 + 1048),
              (unsigned __int8)v285);
            v81 = 1;
            v82 = v20;
            ++*(_BYTE *)(a2 + 1048);
            goto LABEL_55;
          }
        }
      }
    }
    else if ( !v20 )
    {
      qdf_list_peek_front(*(_QWORD **)(a2 + 1024), &v283);
LABEL_49:
      v121 = v283;
      if ( !v283 )
        goto LABEL_65;
      while ( 1 )
      {
        qdf_list_peek_next(*(_QWORD **)(a2 + 1024), v121, &v282);
        v82 = v283;
        v287 = nullptr;
        v288 = 0;
        v289 = 0;
        v122 = *(_QWORD *)a1;
        v123 = v283[3];
        v292 = 0;
        v293 = 0;
        v124 = *(_DWORD *)(v123 + 1192);
        v125 = *(_WORD *)(v123 + 68);
        v290 = v123;
        v291 = 0;
        LODWORD(v289) = v124;
        WORD2(v289) = v125;
        v126 = *(_QWORD *)(v123 + 1824);
        v127 = *(_DWORD *)(v123 + 1);
        WORD2(v288) = *(_WORD *)(v123 + 5);
        LODWORD(v288) = v127;
        v291 = v126 != 0;
        if ( !(unsigned int)if_mgr_deliver_event(
                              v122,
                              4u,
                              (__int64)&v287,
                              v128,
                              v129,
                              v130,
                              v131,
                              v132,
                              v133,
                              v134,
                              v135) )
          break;
        cm_store_n_send_failed_candidate(a1, *(unsigned int *)(a2 + 16));
        v121 = v282;
        v282 = nullptr;
        v283 = v121;
        if ( !v121 )
          goto LABEL_65;
      }
      if ( !v283 )
      {
LABEL_65:
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: vdev %d cm_id 0x%x: No more candidates left",
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          "cm_get_valid_candidate",
          v16,
          *(unsigned int *)(a2 + 16));
        v31 = 0;
        *(_QWORD *)(a2 + 1040) = 0;
        goto LABEL_11;
      }
      v81 = 0;
      *(_BYTE *)(a2 + 1048) = 0;
LABEL_55:
      v136 = *(_BYTE *)(a2 + 1049);
      *(_QWORD *)(a2 + 1040) = v82;
      LOBYTE(v285) = 0;
      *(_BYTE *)(a2 + 1049) = v136 + 1;
      v137 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
      if ( !v137 || (v138 = *(_QWORD *)(v137 + 80)) == 0 )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: psoc is NULL",
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          "cm_connect_req_update_ml_partner_info");
        goto LABEL_80;
      }
      v139 = v82[3];
      wlan_psoc_mlme_get_11be_capab(*(_QWORD *)(v137 + 80), &v285);
      if ( (v81 & 1) != 0 || ((unsigned __int8)v285 & 1) == 0 || (*(_BYTE *)(a2 + 840) & 1) != 0 )
      {
LABEL_80:
        if ( (v81 & 1) != 0 )
        {
          v30 = 0;
          v31 = 1;
        }
        else
        {
          if ( (*(_BYTE *)(*(_QWORD *)a1 + 60LL) & 2) != 0 )
            cm_override_partner_link_akm(a1, a2);
          v30 = 0;
          v31 = 0;
        }
        goto LABEL_12;
      }
      sta_mlo_conn_max_num = wlan_mlme_get_sta_mlo_conn_max_num(v138);
      cm_get_ml_partner_info(a2 + 24);
      v148 = *(unsigned __int8 *)(a2 + 848);
      v280 = v139;
      v275 = *(_DWORD *)(a2 + 16);
      if ( !*(_BYTE *)(a2 + 848) )
      {
        v204 = 0;
        v152 = 0;
        goto LABEL_132;
      }
      v149 = *(_DWORD *)(v139 + 1192);
      v150 = *(unsigned __int16 *)(a2 + 866);
      v273 = v149;
      if ( (policy_mgr_is_hw_dbs_capable(v138) & 1) != 0 || (wlan_reg_is_24ghz_ch_freq(v150) & 1) != 0 )
      {
        v151 = policy_mgr_2_freq_always_on_same_mac(v138, v149, v150);
        v152 = v148;
        if ( (v151 & 1) == 0 )
        {
          v152 = v148;
          v274 = 0;
          goto LABEL_129;
        }
      }
      else
      {
        v152 = 0;
      }
      v204 = *(unsigned __int8 *)(a2 + 848);
      if ( v204 < 2 )
        goto LABEL_132;
      v150 = *(unsigned __int16 *)(a2 + 914);
      if ( (policy_mgr_is_hw_dbs_capable(v138) & 1) != 0 || (wlan_reg_is_24ghz_ch_freq(v150) & 1) != 0 )
      {
        if ( (policy_mgr_2_freq_always_on_same_mac(v138, v273, v150) & 1) == 0 )
        {
          v213 = 1;
LABEL_128:
          v274 = v213;
LABEL_129:
          is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v150);
          v204 = *(unsigned __int8 *)(a2 + 848);
          if ( (is_24ghz_ch_freq & 1) != 0 )
            v148 = v274;
          else
            v152 = v274;
LABEL_132:
          if ( v148 == v204 && v152 == v204 || (v152 != v204 ? (v215 = v152) : (v215 = v148), !v215) )
          {
LABEL_153:
            if ( sta_mlo_conn_max_num >= 3u && v204 >= 2 )
              cm_adjust_partner_links_based_on_oui(v138, v280, a2 + 848, a2);
            goto LABEL_80;
          }
          v216 = *(_QWORD *)(a2 + 880);
          v217 = *(_QWORD *)(a2 + 888);
          v289 = *(_QWORD *)(a2 + 872);
          v290 = v216;
          v218 = *(_QWORD *)(a2 + 896);
          v219 = *(_QWORD **)(a2 + 856);
          v291 = v217;
          v292 = v218;
          v220 = *(_QWORD *)(a2 + 864);
          v287 = v219;
          v288 = v220;
          if ( v215 > 3 )
LABEL_158:
            __break(0x5512u);
          v221 = (_QWORD *)(a2 + 856 + 48LL * v215);
          v222 = v221[3];
          *(_QWORD *)(a2 + 872) = v221[2];
          *(_QWORD *)(a2 + 880) = v222;
          v223 = v221[5];
          *(_QWORD *)(a2 + 888) = v221[4];
          *(_QWORD *)(a2 + 896) = v223;
          v224 = v221[1];
          *(_QWORD *)(a2 + 856) = *v221;
          *(_QWORD *)(a2 + 864) = v224;
          v225 = v290;
          v221[2] = v289;
          v221[3] = v225;
          v226 = v292;
          v221[4] = v291;
          v221[5] = v226;
          v227 = v288;
          *v221 = v287;
          v221[1] = v227;
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: vdev %d cm_id 0x%x: Updated no. of partner links: %d",
            v140,
            v141,
            v142,
            v143,
            v144,
            v145,
            v146,
            v147,
            "cm_modify_partner_info_based_on_dbs_or_sbs_mode",
            BYTE2(v275),
            v275);
          if ( *(_BYTE *)(a2 + 848) )
          {
            LODWORD(v269) = *(unsigned __int16 *)(a2 + 866);
            LODWORD(v266) = *(unsigned __int8 *)(a2 + 861);
            LODWORD(v263) = *(unsigned __int8 *)(a2 + 858);
            LODWORD(v260) = *(unsigned __int8 *)(a2 + 857);
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: vdev %d cm_id 0x%x: Partner link id: %d mac:%02x:%02x:%02x:**:**:%02x freq: %d",
              v228,
              v229,
              v230,
              v231,
              v232,
              v233,
              v234,
              v235,
              "cm_modify_partner_info_based_on_dbs_or_sbs_mode",
              BYTE2(v275),
              v275,
              *(unsigned __int8 *)(a2 + 862),
              *(unsigned __int8 *)(a2 + 856),
              v260,
              v263,
              v266,
              v269);
            if ( *(unsigned __int8 *)(a2 + 848) > 1u )
            {
              if ( a2 == -904 )
              {
                v246 = 0;
                v244 = 0;
                v245 = 0;
                v247 = 0;
              }
              else
              {
                v244 = *(unsigned __int8 *)(a2 + 904);
                v245 = *(unsigned __int8 *)(a2 + 905);
                v246 = *(unsigned __int8 *)(a2 + 906);
                v247 = *(unsigned __int8 *)(a2 + 909);
              }
              LODWORD(v270) = *(unsigned __int16 *)(a2 + 914);
              LODWORD(v267) = v247;
              LODWORD(v264) = v246;
              LODWORD(v261) = v245;
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: vdev %d cm_id 0x%x: Partner link id: %d mac:%02x:%02x:%02x:**:**:%02x freq: %d",
                v236,
                v237,
                v238,
                v239,
                v240,
                v241,
                v242,
                v243,
                "cm_modify_partner_info_based_on_dbs_or_sbs_mode",
                BYTE2(v275),
                v275,
                *(unsigned __int8 *)(a2 + 910),
                v244,
                v261,
                v264,
                v267,
                v270);
              v204 = *(unsigned __int8 *)(a2 + 848);
              if ( v204 < 3 )
                goto LABEL_153;
              if ( a2 == -952 )
              {
                v258 = 0;
                v256 = 0;
                v257 = 0;
                v259 = 0;
              }
              else
              {
                v256 = *(unsigned __int8 *)(a2 + 952);
                v257 = *(unsigned __int8 *)(a2 + 953);
                v258 = *(unsigned __int8 *)(a2 + 954);
                v259 = *(unsigned __int8 *)(a2 + 957);
              }
              LODWORD(v272) = *(unsigned __int16 *)(a2 + 962);
              LODWORD(v268) = v259;
              LODWORD(v265) = v258;
              LODWORD(v262) = v257;
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: vdev %d cm_id 0x%x: Partner link id: %d mac:%02x:%02x:%02x:**:**:%02x freq: %d",
                v248,
                v249,
                v250,
                v251,
                v252,
                v253,
                v254,
                v255,
                "cm_modify_partner_info_based_on_dbs_or_sbs_mode",
                BYTE2(v275),
                v275,
                *(unsigned __int8 *)(a2 + 958),
                v256,
                v262,
                v265,
                v268,
                v272);
              v204 = *(unsigned __int8 *)(a2 + 848);
              if ( v204 <= 3 )
                goto LABEL_153;
              goto LABEL_158;
            }
          }
          goto LABEL_80;
        }
      }
      else
      {
        v152 = 1;
      }
      v204 = *(unsigned __int8 *)(a2 + 848);
      if ( v204 < 3 )
        goto LABEL_132;
      v150 = *(unsigned __int16 *)(a2 + 962);
      if ( (policy_mgr_is_hw_dbs_capable(v138) & 1) != 0 || (wlan_reg_is_24ghz_ch_freq(v150) & 1) != 0 )
      {
        if ( (policy_mgr_2_freq_always_on_same_mac(v138, v273, v150) & 1) == 0 )
        {
          v213 = 2;
          goto LABEL_128;
        }
      }
      else
      {
        v152 = 2;
      }
      v204 = *(unsigned __int8 *)(a2 + 848);
      if ( v204 > 3 )
        goto LABEL_158;
      goto LABEL_132;
    }
    v83 = *(_QWORD *)a1;
    v286[0] = 0;
    v287 = nullptr;
    v84 = *(_QWORD *)(v83 + 216);
    v85 = *(unsigned __int8 *)(v83 + 168);
    v284 = nullptr;
    v285 = nullptr;
    if ( v84 )
    {
      if ( (unsigned int)cm_connect_fetch_candidates(v84, a1, a2 + 24, &v287, v286) )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: vdev %d cm_id 0x%x: failed to fetch bss: %d",
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          "cm_update_candidate_list",
          v85,
          *(unsigned int *)(a2 + 24),
          v286[0]);
      }
      else if ( (unsigned int)qdf_list_peek_front(v287, &v285) )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev %d cm_id 0x%x: failed to peer front of candidate_list",
          v105,
          v106,
          v107,
          v108,
          v109,
          v110,
          v111,
          v112,
          "cm_update_candidate_list",
          v85,
          *(unsigned int *)(a2 + 24));
      }
      else
      {
        v174 = v285;
        if ( v285 )
        {
          v104 = 0;
          v175 = v20;
          while ( 1 )
          {
            qdf_list_peek_next(v287, v174, &v284);
            v176 = v285;
            v177 = v285[3];
            v179 = *(_DWORD *)(v177 + 1);
            v178 = v177 + 1;
            if ( !(v179 | *(unsigned __int16 *)(v178 + 4))
              || (*(_DWORD *)v178 == -1 ? (v180 = *(__int16 *)(v178 + 4) == -1) : (v180 = 0),
                  v180 || (cm_find_bss_from_candidate_list(*(_QWORD *)(a2 + 1024)) & 1) != 0) )
            {
              v176 = v175;
            }
            else
            {
              if ( (unsigned int)qdf_list_remove_node((__int64)v287, v285) )
              {
                v205 = (unsigned __int8 *)v176[3];
                if ( v205 == (unsigned __int8 *)-1LL )
                {
                  v208 = 0;
                  v206 = 0;
                  v207 = 0;
                  v209 = 0;
                }
                else
                {
                  v206 = v205[1];
                  v207 = v205[2];
                  v208 = v205[3];
                  v209 = v205[6];
                }
                LODWORD(v263) = v209;
                LODWORD(v260) = v208;
                qdf_trace_msg(
                  0x68u,
                  2u,
                  "%s: vdev %d cm_id 0x%x: failed to remove node for %02x:%02x:%02x:**:**:%02x from candidate list",
                  v181,
                  v182,
                  v183,
                  v184,
                  v185,
                  v186,
                  v187,
                  v188,
                  "cm_update_candidate_list",
                  v85,
                  *(unsigned int *)(a2 + 24),
                  v206,
                  v207,
                  v260,
                  v263);
                goto LABEL_43;
              }
              v189 = qdf_list_insert_after(*(_QWORD *)(a2 + 1024), v176, v175);
              v198 = (unsigned __int8 *)v176[3];
              v199 = *(unsigned int *)(a2 + 24);
              v200 = (_DWORD)v198 + 1;
              if ( v189 )
              {
                if ( v198 == (unsigned __int8 *)-1LL )
                {
                  v210 = 0;
                  v211 = 0;
                  v212 = 0;
                }
                else
                {
                  v210 = v198[1];
                  v211 = v198[2];
                  v200 = v198[3];
                  v212 = v198[6];
                }
                LODWORD(v263) = v212;
                LODWORD(v260) = v200;
                qdf_trace_msg(
                  0x68u,
                  2u,
                  "%s: vdev %d cm_id 0x%x: failed to insert node for %02x:%02x:%02x:**:**:%02x to candidate list",
                  v190,
                  v191,
                  v192,
                  v193,
                  v194,
                  v195,
                  v196,
                  v197,
                  "cm_update_candidate_list",
                  v85,
                  v199,
                  v210,
                  v211,
                  v260,
                  v263);
                util_scan_free_cache_entry_0(v176[3]);
                _qdf_mem_free((__int64)v176);
                goto LABEL_43;
              }
              if ( v198 == (unsigned __int8 *)-1LL )
              {
                v201 = 0;
                v202 = 0;
                v203 = 0;
              }
              else
              {
                v201 = v198[1];
                v202 = v198[2];
                v200 = v198[3];
                v203 = v198[6];
              }
              LODWORD(v263) = v203;
              LODWORD(v260) = v200;
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: vdev %d cm_id 0x%x: insert new node %02x:%02x:%02x:**:**:%02x to candidate list",
                v190,
                v191,
                v192,
                v193,
                v194,
                v195,
                v196,
                v197,
                "cm_update_candidate_list",
                v85,
                v199,
                v201,
                v202,
                v260,
                v263);
              v104 = 1;
            }
            v174 = v284;
            v175 = v176;
            v284 = nullptr;
            v285 = v174;
            if ( !v174 )
              goto LABEL_43;
          }
        }
      }
      v104 = 0;
LABEL_43:
      if ( v287 )
        scm_purge_scan_results(v287);
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d cm_id 0x%x: Failed to find pdev",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "cm_update_candidate_list",
        v85,
        *(unsigned int *)(a2 + 24));
      v104 = 0;
    }
    cm_update_dlm_mlo_score(*(_QWORD *)(*(_QWORD *)a1 + 216LL), *(_QWORD **)(a2 + 1024), v20, v281);
    if ( (v281[0] & 1) != 0 || (v104 & 1) != 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev %d cm_id 0x%x: dump updated candidate list",
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        v120,
        "cm_get_valid_candidate",
        v16,
        *(unsigned int *)(a2 + 16));
      cm_print_candidate_list(*(_QWORD **)(a2 + 1024));
    }
    qdf_list_peek_next(*(_QWORD **)(a2 + 1024), v20, &v283);
    goto LABEL_49;
  }
  v29 = "%s: vdev %d cm_id 0x%x: Avoid next candidate as SAP/GO/NDI vdev %d has pending vdev op";
LABEL_9:
  qdf_trace_msg(
    0x68u,
    4u,
    v29,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "cm_is_any_other_vdev_connecting_disconnecting",
    v16,
    *(unsigned int *)(a2 + 16));
LABEL_10:
  v31 = 0;
LABEL_11:
  v30 = 16;
LABEL_12:
  param = wlan_crypto_get_param(*(_QWORD *)a1, 7u);
  if ( v20 )
  {
    if ( (v31 & 1) == 0 )
    {
      v33 = param;
      if ( (util_scan_entry_single_pmk(v17, v20[3]) & 1) != 0 && (v33 & 0x8000400) != 0 )
      {
        v34 = v20[3];
        v304 = 0;
        v305 = 0;
        v302 = 0;
        v303 = 0;
        v300 = 0;
        v301 = 0;
        v298 = 0;
        v299 = 0;
        v296 = 0;
        v297 = 0;
        v294 = 0;
        v295 = 0;
        v292 = 0;
        v293 = 0;
        v290 = 0;
        v291 = 0;
        v288 = 0;
        v289 = 0;
        v287 = nullptr;
        qdf_mem_set(&v287, 0x98u, 0);
        v35 = *(_DWORD *)(v34 + 1);
        v36 = *(_QWORD *)a1;
        WORD2(v287) = *(_WORD *)(v34 + 5);
        LODWORD(v287) = v35;
        wlan_crypto_set_del_pmksa(v36, (__int64)&v287, 0, v37, v38, v39, v40, v41, v42, v43, v44);
        v45 = v20[3];
        if ( *(_DWORD *)(v45 + 1912) | *(unsigned __int16 *)(v45 + 1916) )
        {
          v46 = v45 + 1912;
          if ( v45 != -1912 )
          {
            v304 = 0;
            v305 = 0;
            v302 = 0;
            v303 = 0;
            v300 = 0;
            v301 = 0;
            v298 = 0;
            v299 = 0;
            v296 = 0;
            v297 = 0;
            v294 = 0;
            v295 = 0;
            v292 = 0;
            v293 = 0;
            v290 = 0;
            v291 = 0;
            v288 = 0;
            v289 = 0;
            v287 = nullptr;
            qdf_mem_set(&v287, 0x98u, 0);
            v47 = *(_WORD *)(v46 + 4);
            v48 = *(_QWORD *)a1;
            LODWORD(v287) = *(_DWORD *)v46;
            WORD2(v287) = v47;
            wlan_crypto_set_del_pmksa(v48, (__int64)&v287, 0, v49, v50, v51, v52, v53, v54, v55, v56);
          }
        }
      }
    }
  }
  if ( a4 )
    *a4 = v31;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return v30;
}
