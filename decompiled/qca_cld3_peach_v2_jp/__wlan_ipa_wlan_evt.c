__int64 __fastcall _wlan_ipa_wlan_evt(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned __int8 *a5,
        char a6,
        __int64 a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  int v21; // w26
  unsigned int v22; // w24
  int v23; // w4
  int v24; // w5
  int v25; // w6
  int v26; // w7
  __int64 result; // x0
  int v28; // w8
  __int64 v29; // x0
  unsigned int *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  const char *v47; // x5
  int v48; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  const char *v57; // x4
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x0
  _QWORD *v67; // x1
  __int64 v68; // x0
  __int64 v69; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x5
  const char *v87; // x2
  unsigned int v88; // w1
  __int64 v89; // x4
  char v90; // w26
  __int64 iface_by_mode_netdev; // x0
  char v92; // w8
  __int64 v93; // x26
  unsigned int v94; // w0
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  int v103; // w26
  int v104; // w3
  int v105; // w4
  int v106; // w5
  int v107; // w6
  int v108; // w7
  const char *v109; // x1
  int v110; // w2
  __int64 v111; // x0
  __int16 v112; // w8
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  __int64 v121; // x4
  const char *v122; // x2
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  unsigned __int8 v131; // w8
  _BYTE *v132; // x9
  __int64 discon; // x0
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  __int64 (__fastcall *v142)(_QWORD); // x8
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  __int16 v151; // w8
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  unsigned int v160; // w0
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
  int v169; // w25
  bool v170; // zf
  __int64 (*v171)(void); // x8
  double v172; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  double v180; // d0
  double v181; // d1
  double v182; // d2
  double v183; // d3
  double v184; // d4
  double v185; // d5
  double v186; // d6
  double v187; // d7
  double v188; // d0
  double v189; // d1
  double v190; // d2
  double v191; // d3
  double v192; // d4
  double v193; // d5
  double v194; // d6
  double v195; // d7
  double v196; // d0
  double v197; // d1
  double v198; // d2
  double v199; // d3
  double v200; // d4
  double v201; // d5
  double v202; // d6
  double v203; // d7
  __int64 v204; // x5
  __int64 v205; // x6
  __int64 v206; // x7
  int v207; // w8
  double v208; // d0
  double v209; // d1
  double v210; // d2
  double v211; // d3
  double v212; // d4
  double v213; // d5
  double v214; // d6
  double v215; // d7
  int v216; // w4
  int v217; // w5
  int v218; // w6
  int v219; // w7
  __int64 v220; // x0
  __int16 v221; // w8
  __int64 (__fastcall *v222)(_QWORD); // x8
  double v223; // d0
  double v224; // d1
  double v225; // d2
  double v226; // d3
  double v227; // d4
  double v228; // d5
  double v229; // d6
  double v230; // d7
  double v231; // d0
  double v232; // d1
  double v233; // d2
  double v234; // d3
  double v235; // d4
  double v236; // d5
  double v237; // d6
  double v238; // d7
  __int64 (*v239)(void); // x8
  double v240; // d0
  double v241; // d1
  double v242; // d2
  double v243; // d3
  double v244; // d4
  double v245; // d5
  double v246; // d6
  double v247; // d7
  __int16 v248; // w8
  unsigned __int8 v249; // w8
  __int64 v250; // x0
  int v251; // w25
  const char *v252; // x2
  const char *v253; // x2
  __int64 v254; // x4
  unsigned int v255; // w1
  char v256; // w5
  double v257; // d0
  double v258; // d1
  double v259; // d2
  double v260; // d3
  double v261; // d4
  double v262; // d5
  double v263; // d6
  double v264; // d7
  __int64 v265; // x0
  __int64 v266; // x27
  __int64 con; // x0
  _DWORD *v268; // x8
  double v269; // d0
  double v270; // d1
  double v271; // d2
  double v272; // d3
  double v273; // d4
  double v274; // d5
  double v275; // d6
  double v276; // d7
  int v277; // w5
  int v278; // w6
  int v279; // w7
  double v280; // d0
  double v281; // d1
  double v282; // d2
  double v283; // d3
  double v284; // d4
  double v285; // d5
  double v286; // d6
  double v287; // d7
  int v288; // w25
  const char *v289; // x2
  __int64 v290; // x0
  _DWORD *v291; // x8
  double v292; // d0
  double v293; // d1
  double v294; // d2
  double v295; // d3
  double v296; // d4
  double v297; // d5
  double v298; // d6
  double v299; // d7
  int v300; // w3
  int v301; // w4
  int v302; // w5
  int v303; // w6
  int v304; // w7
  __int64 v305; // x0
  __int64 v306; // x24
  __int64 v307; // x8
  __int64 v308; // x9
  __int64 v309; // x5
  double v310; // d0
  double v311; // d1
  double v312; // d2
  double v313; // d3
  double v314; // d4
  double v315; // d5
  double v316; // d6
  double v317; // d7
  double v318; // d0
  double v319; // d1
  double v320; // d2
  double v321; // d3
  double v322; // d4
  double v323; // d5
  double v324; // d6
  double v325; // d7
  unsigned int v326; // w25
  double v327; // d0
  double v328; // d1
  double v329; // d2
  double v330; // d3
  double v331; // d4
  double v332; // d5
  double v333; // d6
  double v334; // d7
  int v335; // w3
  int v336; // w4
  int v337; // w5
  int v338; // w6
  int v339; // w7
  _BOOL8 v340; // x1
  _BOOL8 v341; // x1
  __int64 v342; // [xsp+0h] [xbp-40h]
  __int64 v343; // [xsp+8h] [xbp-38h]
  __int64 v344; // [xsp+28h] [xbp-18h] BYREF
  int v345; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v346; // [xsp+38h] [xbp-8h]

  v21 = a6 & 1;
  v346 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v345 = 0;
  v22 = (unsigned __int8)a3;
  if ( a5 )
  {
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: %s: EVT: %d, MAC: %02x:%02x:%02x:**:**:%02x, session_id: %u is_2g_iface %u",
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      "__wlan_ipa_wlan_evt",
      a1 + 296,
      a4,
      *a5,
      a5[1],
      a5[2],
      a5[5],
      (unsigned __int8)a3,
      a6 & 1);
    v23 = *a5;
    v24 = a5[1];
    v25 = a5[2];
    v26 = a5[5];
  }
  else
  {
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: %s: EVT: %d, MAC: %02x:%02x:%02x:**:**:%02x, session_id: %u is_2g_iface %u",
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      "__wlan_ipa_wlan_evt",
      a1 + 296,
      a4,
      0,
      0,
      0,
      0,
      (unsigned __int8)a3,
      a6 & 1);
    v25 = 0;
    v23 = 0;
    v24 = 0;
    v26 = 0;
  }
  LODWORD(v343) = v21;
  wlan_ipa_log_message(
    (int)"__wlan_ipa_wlan_evt",
    (int)"%s: EVT: %d, MAC: %02x:%02x:%02x:**:**:%02x, session_id: %u is_2g_iface %u",
    a1 + 296,
    a4,
    v23,
    v24,
    v25,
    v26,
    v22);
  if ( a4 > 0xD )
  {
LABEL_5:
    result = 4;
    goto LABEL_247;
  }
  v28 = **(_DWORD **)(a7 + 1464);
  if ( (v28 & 0x20) != 0 && (unsigned __int8)a2 != 1 && (v28 & 0x40) == 0 )
    goto LABEL_246;
  v29 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(*(_QWORD *)a7, a3, 37);
  if ( v29 )
  {
    wlan_objmgr_vdev_release_ref(v29, 0x25u, v30, v31, v32, v33, v34, v35, v36, v37, v38);
    if ( !*(_BYTE *)(a7 + 3710) )
      goto LABEL_21;
  }
  else
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: vdev is NULL, session_id: %u",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "__wlan_ipa_wlan_evt",
      v22);
    if ( !*(_BYTE *)(a7 + 3710) )
      goto LABEL_21;
  }
  if ( !*(_DWORD *)(a7 + 1096) )
  {
    if ( a7 != -1064 )
      goto LABEL_21;
    goto LABEL_20;
  }
  if ( !*(_DWORD *)(a7 + 1224) )
  {
    if ( a7 != -1192 )
      goto LABEL_21;
LABEL_20:
    qdf_trace_msg(0x61u, 2u, "%s: sta iface_ctx is NULL", v39, v40, v41, v42, v43, v44, v45, v46, "__wlan_ipa_wlan_evt");
    goto LABEL_21;
  }
  if ( *(_DWORD *)(a7 + 1352) || a7 == -1320 )
    goto LABEL_20;
LABEL_21:
  if ( (**(_BYTE **)(a7 + 1464) & 0x20) == 0 )
    goto LABEL_41;
  v47 = "load";
  if ( (*(_BYTE *)(a7 + 3720) & 1) == 0 )
  {
    if ( *(_BYTE *)(a7 + 3721) != 1 )
      goto LABEL_41;
    v47 = "unload";
  }
  v344 = 0;
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: Event:%d IPA resource %s inprogress",
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    "__wlan_ipa_wlan_evt",
    a4,
    v47);
  v48 = qdf_wait_for_event_completion(a7 + 7392, 0x1F4u);
  if ( *(_BYTE *)(a7 + 3720) )
    v57 = "load";
  else
    v57 = "unload";
  if ( v48 )
  {
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: IPA resource %s timed out",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "__wlan_ipa_wlan_evt",
      v57);
    if ( a4 == 3 )
      wlan_ipa_uc_offload_enable_disable(a7, 0, a3, 0);
    qdf_mutex_acquire(a7 + 7224);
    if ( *(_DWORD *)(a7 + 4032) < 0x14u )
    {
      v66 = _qdf_mem_malloc(0x30u, "__wlan_ipa_wlan_evt", 3930);
      v344 = v66;
      if ( v66 )
        goto LABEL_33;
    }
    else
    {
      qdf_trace_msg(
        0x61u,
        4u,
        "%s: Reached max pending evt count",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        "__wlan_ipa_wlan_evt");
      qdf_list_remove_front((_DWORD *)(a7 + 4016), &v344);
      v66 = v344;
      if ( v344 )
      {
LABEL_33:
        *(_QWORD *)(v66 + 24) = a1;
        *(_BYTE *)(v66 + 32) = a2;
        *(_BYTE *)(v66 + 33) = a3;
        *(_DWORD *)(v66 + 16) = a4;
        *(_BYTE *)(v66 + 40) = *(_BYTE *)(a7 + 3720);
        qdf_mem_copy((void *)(v66 + 34), a5, 6u);
        v67 = (_QWORD *)v344;
        *(_BYTE *)(v344 + 41) = v21;
        qdf_list_insert_back((_QWORD *)(a7 + 4016), v67);
        v68 = qdf_mutex_release(a7 + 7224);
        if ( a4 == 5 || a4 == 3 )
        {
          if ( *(_QWORD *)(a7 + 1088) == a1 && *(unsigned __int8 *)(a7 + 1116) == (unsigned __int8)a3 )
          {
            v69 = a7 + 1064;
          }
          else if ( *(_QWORD *)(a7 + 1216) == a1 && *(unsigned __int8 *)(a7 + 1244) == (unsigned __int8)a3 )
          {
            v69 = a7 + 1192;
          }
          else
          {
            if ( *(_QWORD *)(a7 + 1344) != a1 || *(unsigned __int8 *)(a7 + 1372) != (unsigned __int8)a3 )
            {
LABEL_92:
              if ( (ipa_get_lan_rx_napi(v68) & 1) != 0 && *(_BYTE *)(a7 + 3705) == 1 )
                wlan_ipa_handle_multiple_sap_evt(a7, a4);
              goto LABEL_246;
            }
            v69 = a7 + 1320;
          }
          v68 = wlan_ipa_cleanup_iface(v69, a5);
          goto LABEL_92;
        }
LABEL_246:
        result = 0;
        goto LABEL_247;
      }
    }
    qdf_mutex_release(a7 + 7224);
    result = 2;
    goto LABEL_247;
  }
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: IPA resource %s completed",
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    "__wlan_ipa_wlan_evt",
    v57);
LABEL_41:
  ++*(_DWORD *)(a7 + 4LL * a4 + 3496);
  _qdf_ipa_set_meta_msg_type(&v345, a4);
  result = 0;
  if ( (int)a4 <= 4 )
  {
    if ( (int)a4 <= 2 )
    {
      if ( a4 != 1 )
      {
        if ( a4 != 2 )
          goto LABEL_247;
        qdf_mutex_acquire(a7 + 4040);
        if ( (unsigned __int8)a3 <= 4u )
        {
          if ( *(_BYTE *)(a7 + 7288 + (unsigned __int8)a3) == 5 )
          {
            if ( (unsigned int)wlan_ipa_setup_iface(a7, a1, a2, a3, a5) )
            {
              qdf_mutex_release(a7 + 4040);
              v86 = (unsigned __int8)v345;
              v87 = "%s: %s: Evt: %d, Interface setup failed";
              v88 = 2;
LABEL_160:
              v89 = 0;
              goto LABEL_161;
            }
            if ( (**(_BYTE **)(a7 + 1464) & 0x20) != 0 )
            {
              v250 = qdf_mutex_release(a7 + 4040);
              if ( (ipa_get_lan_rx_napi(v250) & 1) != 0 && *(unsigned __int8 *)(a7 + 3705) >= 2u )
                wlan_ipa_handle_multiple_sap_evt(a7, 2);
              else
                wlan_ipa_uc_offload_enable_disable(a7, 0, a3, 1);
              qdf_mutex_acquire(a7 + 4040);
            }
            if ( *(unsigned __int8 *)(a7 + 1116) == (unsigned __int8)a3 )
            {
              v256 = 0;
            }
            else if ( *(unsigned __int8 *)(a7 + 1244) == (unsigned __int8)a3 )
            {
              v256 = 1;
            }
            else if ( *(unsigned __int8 *)(a7 + 1372) == (unsigned __int8)a3 )
            {
              v256 = 2;
            }
            else
            {
              v256 = 3;
            }
            *(_BYTE *)(a7 + 7288 + (unsigned __int8)a3) = v256;
            qdf_trace_msg(
              0x61u,
              8u,
              "%s: vdev_to_iface[%u]=%u",
              v78,
              v79,
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              "__wlan_ipa_wlan_evt",
              v22);
            goto LABEL_221;
          }
LABEL_98:
          qdf_mutex_release(a7 + 4040);
          result = 0;
          goto LABEL_247;
        }
LABEL_275:
        __break(0x5512u);
        JUMPOUT(0x56DF4C);
      }
      if ( (**(_BYTE **)(a7 + 1464) & 0x20) == 0 )
      {
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: %s: IPA UC OFFLOAD NOT ENABLED",
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          "__wlan_ipa_wlan_evt",
          0);
        result = 0;
        goto LABEL_247;
      }
      qdf_mutex_acquire(a7 + 4040);
      if ( !*(_WORD *)(a7 + 3706) && !*(_WORD *)(a7 + 3708) )
      {
        qdf_mutex_release(a7 + 4040);
        v86 = (unsigned __int8)v345;
        v87 = "%s: %s: Evt: %d, Client already disconnected";
        v89 = a1 + 296;
        v88 = 8;
        goto LABEL_161;
      }
      if ( (wlan_ipa_uc_find_add_assoc_sta(a7, 0, (int)a5) & 1) != 0 )
      {
        v170 = --*(_WORD *)(a7 + 3706) == 0;
        if ( !v170
          || *(_WORD *)(a7 + 3708)
          || *(_BYTE *)(a7 + 6984) != 1
          || *(_BYTE *)(a7 + 3710)
          || (*(_BYTE *)(a7 + 3721) & 1) != 0
          || (*(_BYTE *)(a7 + 3440) & 1) != 0 )
        {
          goto LABEL_274;
        }
        v171 = *(__int64 (**)(void))(a7 + 7384);
        if ( v171 )
        {
          if ( *((_DWORD *)v171 - 1) != 799902358 )
            __break(0x8228u);
          if ( (v171() & 1) != 0 )
          {
            wlan_ipa_uc_disable_pipes(a7, 1, v172, v173, v174, v175, v176, v177, v178, v179);
LABEL_273:
            qdf_trace_msg(
              0x61u,
              4u,
              "%s: last sap client disconnected",
              v180,
              v181,
              v182,
              v183,
              v184,
              v185,
              v186,
              v187,
              "__wlan_ipa_wlan_evt");
LABEL_274:
            qdf_mutex_release(a7 + 4040);
            v121 = *(unsigned __int16 *)(a7 + 3706);
            v122 = "%s: sap_num_connected_sta=%d";
            goto LABEL_64;
          }
          v341 = *(_BYTE *)(a7 + 3710) == 0;
        }
        else
        {
          v341 = 1;
        }
        wlan_ipa_uc_handle_last_discon(a7, v341);
        goto LABEL_273;
      }
      qdf_mutex_release(a7 + 4040);
      if ( a5 )
      {
        v204 = *a5;
        v205 = a5[1];
        v206 = a5[2];
        v207 = a5[5];
      }
      else
      {
        v206 = 0;
        v204 = 0;
        v205 = 0;
        v207 = 0;
      }
      v253 = "%s: %s: STA NOT found, not valid: %02x:%02x:%02x:**:**:%02x";
      v254 = a1 + 296;
      v255 = 8;
LABEL_168:
      LODWORD(v342) = v207;
      qdf_trace_msg(
        0x61u,
        v255,
        v253,
        v196,
        v197,
        v198,
        v199,
        v200,
        v201,
        v202,
        v203,
        "__wlan_ipa_wlan_evt",
        v254,
        v204,
        v205,
        v206,
        v342,
        v343);
      result = 0;
      goto LABEL_247;
    }
    if ( a4 != 3 )
    {
      qdf_mutex_acquire(a7 + 4040);
      v90 = *(_BYTE *)(a7 + 3710);
      if ( v90 )
      {
        iface_by_mode_netdev = wlan_ipa_get_iface_by_mode_netdev(a7, a1, 0, a3);
        if ( iface_by_mode_netdev )
        {
          v92 = v90 - 1;
          v93 = iface_by_mode_netdev;
          *(_BYTE *)(a7 + 3710) = v92;
          wlan_ipa_cleanup_iface(iface_by_mode_netdev, 0);
          iface_by_mode_netdev = v93;
        }
        v94 = wlan_ipa_send_msg(iface_by_mode_netdev, a1, 5, a5);
        if ( v94 )
        {
          v103 = v94;
          qdf_trace_msg(
            0x61u,
            2u,
            "%s: QDF_IPA_STA_DISCONNECT send failed %u",
            v95,
            v96,
            v97,
            v98,
            v99,
            v100,
            v101,
            v102,
            "__wlan_ipa_wlan_evt",
            v94);
          v109 = "QDF_IPA_STA_DISCONNECT send failed %u";
          v110 = v103;
LABEL_97:
          wlan_ipa_log_message((int)"__wlan_ipa_wlan_evt", (int)v109, v110, v104, v105, v106, v107, v108, v342);
          goto LABEL_98;
        }
      }
      v160 = wlan_ipa_setup_iface(a7, a1, a2, a3, a5);
      if ( v160 )
      {
        v169 = v160;
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: wlan_ipa_setup_iface failed %u",
          v161,
          v162,
          v163,
          v164,
          v165,
          v166,
          v167,
          v168,
          "__wlan_ipa_wlan_evt",
          v160);
        v109 = "wlan_ipa_setup_iface failed %u";
        v110 = v169;
        goto LABEL_97;
      }
      if ( *(unsigned __int8 *)(a7 + 1116) == (unsigned __int8)a3 )
      {
        v249 = 0;
      }
      else if ( *(unsigned __int8 *)(a7 + 1244) == (unsigned __int8)a3 )
      {
        v249 = 1;
      }
      else if ( *(unsigned __int8 *)(a7 + 1372) == (unsigned __int8)a3 )
      {
        v249 = 2;
      }
      else
      {
        v249 = 3;
      }
      if ( (unsigned __int8)a3 > 4u )
        goto LABEL_275;
      v266 = a7 + 7288;
      *(_BYTE *)(a7 + 7288 + (unsigned __int8)a3) = v249;
      if ( v249 == 3 )
        goto LABEL_275;
      con = (__int64)qdf_mem_copy((void *)(a7 + ((unsigned __int64)v249 << 7) + 1184), a5, 6u);
      if ( (**(_BYTE **)(a7 + 1464) & 0x40) != 0 && !*(_BYTE *)(a7 + 3710) )
      {
        qdf_mutex_release(a7 + 4040);
        wlan_ipa_uc_offload_enable_disable(a7, 1, a3, 1);
        con = qdf_mutex_acquire(a7 + 4040);
        *(_DWORD *)(a7 + 7444) = 1;
      }
      if ( *(_BYTE *)(a7 + 6984) == 1 && !*(_WORD *)(a7 + 3706) && !*(_BYTE *)(a7 + 3710) )
      {
        con = wlan_ipa_uc_handle_first_con(a7);
        if ( (_DWORD)con )
        {
          v326 = con;
          qdf_mutex_release(a7 + 4040);
          qdf_trace_msg(
            0x61u,
            4u,
            "%s: handle 1st conn failed %d",
            v327,
            v328,
            v329,
            v330,
            v331,
            v332,
            v333,
            v334,
            "__wlan_ipa_wlan_evt",
            v326);
          wlan_ipa_log_message(
            (int)"__wlan_ipa_wlan_evt",
            (int)"handle 1st conn failed %d",
            v326,
            v335,
            v336,
            v337,
            v338,
            v339,
            v342);
          wlan_ipa_uc_offload_enable_disable(a7, 1, a3, 0);
          result = 0;
          *(_BYTE *)(v266 + (unsigned __int8)a3) = 5;
          goto LABEL_247;
        }
      }
      ++*(_BYTE *)(a7 + 3710);
      if ( (ipa_get_lan_rx_napi(con) & 1) != 0 )
      {
        if ( *(_WORD *)(a7 + 3706) )
        {
          v268 = *(_DWORD **)(a7 + 7376);
          if ( v268 )
          {
            if ( *(v268 - 1) != 2130452855 )
              __break(0x8228u);
            ((void (__fastcall *)(_QWORD, __int64))v268)(a3, 1);
          }
        }
      }
      qdf_mutex_release(a7 + 4040);
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: sta_connected=%d vdev_to_iface[%u] %u",
        v269,
        v270,
        v271,
        v272,
        v273,
        v274,
        v275,
        v276,
        "__wlan_ipa_wlan_evt",
        *(unsigned __int8 *)(a7 + 3710),
        v22,
        *(unsigned __int8 *)(v266 + (unsigned __int8)a3));
      wlan_ipa_log_message(
        (int)"__wlan_ipa_wlan_evt",
        (int)"sta_connected=%d vdev_to_iface[%u] %u",
        *(unsigned __int8 *)(a7 + 3710),
        v22,
        *(unsigned __int8 *)(v266 + (unsigned __int8)a3),
        v277,
        v278,
        v279,
        v342);
LABEL_240:
      if ( *(_BYTE *)(a7 + 6984) != 1 )
        goto LABEL_246;
      HIWORD(v345) = 40;
      v305 = _qdf_mem_malloc(0x28u, "__wlan_ipa_wlan_evt", 4565);
      if ( !v305 )
      {
        result = 2;
        goto LABEL_247;
      }
      v306 = v305;
      _qdf_ipa_set_meta_msg_type(&v345, a4);
      if ( *(_DWORD *)(a7 + 1096) == 1
        && *(_QWORD *)(a7 + 1088) == a1
        && *(unsigned __int8 *)(a7 + 1116) == (unsigned __int8)a3 )
      {
        v307 = a7 + 1064;
      }
      else if ( *(_DWORD *)(a7 + 1224) == 1
             && *(_QWORD *)(a7 + 1216) == a1
             && *(unsigned __int8 *)(a7 + 1244) == (unsigned __int8)a3 )
      {
        v307 = a7 + 1192;
      }
      else
      {
        v308 = a1;
        if ( *(_DWORD *)(a7 + 1352) != 1
          || (v308 = a1, *(_QWORD *)(a7 + 1344) != a1)
          || (v308 = a1, *(unsigned __int8 *)(a7 + 1372) != (unsigned __int8)a3) )
        {
LABEL_258:
          _wlan_ipa_set_msg_ifname(v308 + 296, a4, v306);
          qdf_mem_copy((void *)(v306 + 32), a5, 6u);
          v309 = (unsigned __int8)v345;
          *(_WORD *)(v306 + 38) = *(_DWORD *)(a1 + 224);
          qdf_trace_msg(
            0x61u,
            8u,
            "%s: %s: Evt: %d",
            v310,
            v311,
            v312,
            v313,
            v314,
            v315,
            v316,
            v317,
            "__wlan_ipa_wlan_evt",
            v306,
            v309);
          result = ipa_send_msg(&v345, v306, wlan_ipa_msg_free_fn);
          if ( (_DWORD)result )
          {
            qdf_trace_msg(
              0x61u,
              2u,
              "%s: %s: Evt: %d fail",
              v318,
              v319,
              v320,
              v321,
              v322,
              v323,
              v324,
              v325,
              "__wlan_ipa_wlan_evt",
              v306,
              (unsigned __int8)v345);
            _qdf_mem_free(v306);
            result = 16;
          }
          else
          {
            ++*(_QWORD *)(a7 + 3552);
          }
          goto LABEL_247;
        }
        v307 = a7 + 1320;
      }
      v308 = a1;
      if ( v307 )
        v308 = *(_QWORD *)(v307 + 24);
      goto LABEL_258;
    }
    discon = qdf_mutex_acquire(a7 + 4040);
    if ( *(_BYTE *)(a7 + 1448) == 1 && (*(_BYTE *)(a7 + 3440) & 1) == 0 && (*(_BYTE *)(a7 + 3721) & 1) == 0 )
    {
      v142 = *(__int64 (__fastcall **)(_QWORD))(a7 + 7384);
      if ( !v142 )
        goto LABEL_178;
      if ( *((_DWORD *)v142 - 1) != 799902358 )
        __break(0x8228u);
      if ( (v142(discon) & 1) != 0 )
      {
        discon = wlan_ipa_uc_disable_pipes(a7, 1, v134, v135, v136, v137, v138, v139, v140, v141);
      }
      else
      {
LABEL_178:
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: No interface left but WDI pipes are still active",
          v134,
          v135,
          v136,
          v137,
          v138,
          v139,
          v140,
          v141,
          "__wlan_ipa_wlan_evt");
        discon = wlan_ipa_uc_handle_last_discon(a7, 1);
      }
    }
    if ( (**(_BYTE **)(a7 + 1464) & 0x20) != 0 )
    {
      qdf_mutex_release(a7 + 4040);
      wlan_ipa_uc_offload_enable_disable(a7, 0, a3, 0);
      qdf_mutex_acquire(a7 + 4040);
      if ( (unsigned __int8)a3 > 4u )
        goto LABEL_275;
      *(_BYTE *)(a7 + (unsigned __int8)a3 + 7288) = 5;
      discon = qdf_trace_msg(
                 0x61u,
                 8u,
                 "%s: vdev_to_iface[%u]=%u",
                 v257,
                 v258,
                 v259,
                 v260,
                 v261,
                 v262,
                 v263,
                 v264,
                 "__wlan_ipa_wlan_evt",
                 v22,
                 5);
    }
    if ( *(_QWORD *)(a7 + 1088) == a1 && *(unsigned __int8 *)(a7 + 1116) == (unsigned __int8)a3 )
    {
      v265 = a7 + 1064;
    }
    else if ( *(_QWORD *)(a7 + 1216) == a1 && *(unsigned __int8 *)(a7 + 1244) == (unsigned __int8)a3 )
    {
      v265 = a7 + 1192;
    }
    else
    {
      if ( *(_QWORD *)(a7 + 1344) != a1 || *(unsigned __int8 *)(a7 + 1372) != (unsigned __int8)a3 )
      {
LABEL_192:
        if ( (ipa_get_lan_rx_napi(discon) & 1) != 0 && *(_BYTE *)(a7 + 3705) == 1 )
          wlan_ipa_handle_multiple_sap_evt(a7, 3);
        goto LABEL_221;
      }
      v265 = a7 + 1320;
    }
    discon = wlan_ipa_cleanup_iface(v265, a5);
    goto LABEL_192;
  }
  if ( (int)a4 > 6 )
  {
    if ( a4 == 7 )
    {
      qdf_mutex_acquire(a7 + 4040);
      v151 = *(_WORD *)(a7 + 3708);
      if ( !v151 )
      {
        if ( *(_BYTE *)(a7 + 6984) == 1 )
        {
          if ( *(_BYTE *)(a7 + 3710) )
          {
            qdf_trace_msg(
              0x61u,
              8u,
              "%s: IPA pipes already enabled",
              v143,
              v144,
              v145,
              v146,
              v147,
              v148,
              v149,
              v150,
              "__wlan_ipa_wlan_evt");
          }
          else if ( (unsigned int)wlan_ipa_uc_handle_first_con(a7) )
          {
            goto LABEL_170;
          }
          qdf_trace_msg(
            0x61u,
            4u,
            "%s: first sap client connected",
            v152,
            v153,
            v154,
            v155,
            v156,
            v157,
            v158,
            v159,
            "__wlan_ipa_wlan_evt");
          v151 = *(_WORD *)(a7 + 3708);
        }
        else
        {
          v151 = 0;
        }
      }
      *(_WORD *)(a7 + 3708) = v151 + 1;
LABEL_221:
      qdf_mutex_release(a7 + 4040);
      goto LABEL_240;
    }
    if ( a4 != 8 )
      goto LABEL_247;
    v111 = qdf_mutex_acquire(a7 + 4040);
    v112 = *(_WORD *)(a7 + 3708);
    if ( *(_WORD *)(a7 + 3706) )
    {
      *(_WORD *)(a7 + 3708) = v112 - 1;
LABEL_63:
      qdf_mutex_release(a7 + 4040);
      v121 = *(unsigned __int16 *)(a7 + 3708);
      v122 = "%s: sap_num_mlo_connected_sta=%d";
LABEL_64:
      qdf_trace_msg(0x61u, 8u, v122, v113, v114, v115, v116, v117, v118, v119, v120, "__wlan_ipa_wlan_evt", v121);
      goto LABEL_240;
    }
    if ( !*(_WORD *)(a7 + 3708) )
    {
      qdf_mutex_release(a7 + 4040);
      v86 = (unsigned __int8)v345;
      v87 = "%s: %s: Evt: %d, Client already disconnected";
      v88 = 8;
      goto LABEL_160;
    }
    v221 = v112 - 1;
    *(_WORD *)(a7 + 3708) = v221;
    if ( v221
      || *(_BYTE *)(a7 + 6984) != 1
      || *(_BYTE *)(a7 + 3710)
      || (*(_BYTE *)(a7 + 3721) & 1) != 0
      || (*(_BYTE *)(a7 + 3440) & 1) != 0 )
    {
      goto LABEL_63;
    }
    v222 = *(__int64 (__fastcall **)(_QWORD))(a7 + 7384);
    if ( v222 )
    {
      if ( *((_DWORD *)v222 - 1) != 799902358 )
        __break(0x8228u);
      if ( (v222(v111) & 1) != 0 )
      {
        wlan_ipa_uc_disable_pipes(a7, 1, v223, v224, v225, v226, v227, v228, v229, v230);
LABEL_269:
        qdf_trace_msg(
          0x61u,
          4u,
          "%s: last sap client disconnected",
          v231,
          v232,
          v233,
          v234,
          v235,
          v236,
          v237,
          v238,
          "__wlan_ipa_wlan_evt");
        goto LABEL_63;
      }
      v340 = *(_BYTE *)(a7 + 3710) == 0;
    }
    else
    {
      v340 = 1;
    }
    wlan_ipa_uc_handle_last_discon(a7, v340);
    goto LABEL_269;
  }
  if ( a4 == 5 )
  {
    qdf_mutex_acquire(a7 + 4040);
    if ( !*(_BYTE *)(a7 + 3710) )
    {
      qdf_mutex_release(a7 + 4040);
      qdf_trace_msg(
        0x61u,
        4u,
        "%s: %s: Evt: %d, STA already disconnected",
        v208,
        v209,
        v210,
        v211,
        v212,
        v213,
        v214,
        v215,
        "__wlan_ipa_wlan_evt",
        0,
        (unsigned __int8)v345);
      wlan_ipa_log_message(
        (int)"__wlan_ipa_wlan_evt",
        (int)"%s: Evt: %d, STA already disconnected",
        0,
        (unsigned __int8)v345,
        v216,
        v217,
        v218,
        v219,
        v342);
      v220 = wlan_ipa_get_iface_by_mode_netdev(a7, a1, 0, a3);
      if ( v220 )
        wlan_ipa_cleanup_iface(v220, a5);
      goto LABEL_5;
    }
    v131 = *(_BYTE *)(a7 + 3710) - 1;
    v132 = *(_BYTE **)(a7 + 1464);
    *(_BYTE *)(a7 + 3710) = v131;
    if ( (*v132 & 0x20) != 0 )
    {
      if ( *(_BYTE *)(a7 + 1448) == 1
        || !*(_WORD *)(a7 + 3706)
        && ((v251 = v131) != 0
          ? (v252 = "%s: Multiple STA connected")
          : (v252 = "%s: last STA disconnection, disable pipes"),
            qdf_trace_msg(
              0x61u,
              8u,
              v252,
              v123,
              v124,
              v125,
              v126,
              v127,
              v128,
              v129,
              v130,
              "wlan_ipa_sta_last_disconnection"),
            !v251) )
      {
        if ( (*(_BYTE *)(a7 + 3440) & 1) == 0 && (*(_BYTE *)(a7 + 3721) & 1) == 0 )
        {
          v239 = *(__int64 (**)(void))(a7 + 7384);
          if ( !v239 )
            goto LABEL_222;
          if ( *((_DWORD *)v239 - 1) != 799902358 )
            __break(0x8228u);
          if ( (v239() & 1) != 0 )
            wlan_ipa_uc_disable_pipes(a7, 1, v240, v241, v242, v243, v244, v245, v246, v247);
          else
LABEL_222:
            wlan_ipa_uc_handle_last_discon(a7, 1);
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: %s: IPA UC OFFLOAD NOT ENABLED",
        v123,
        v124,
        v125,
        v126,
        v127,
        v128,
        v129,
        v130,
        "__wlan_ipa_wlan_evt",
        0);
    }
    if ( (**(_BYTE **)(a7 + 1464) & 0x40) != 0 )
    {
      if ( *(_WORD *)(a7 + 3706)
        || ((v288 = *(unsigned __int8 *)(a7 + 3710), *(_BYTE *)(a7 + 3710))
          ? (v289 = "%s: Multiple STA connected")
          : (v289 = "%s: last STA disconnection, disable pipes"),
            qdf_trace_msg(
              0x61u,
              8u,
              v289,
              v123,
              v124,
              v125,
              v126,
              v127,
              v128,
              v129,
              v130,
              "wlan_ipa_sta_last_disconnection"),
            !v288) )
      {
        *(_DWORD *)(a7 + 7444) = 0;
        qdf_mutex_release(a7 + 4040);
        wlan_ipa_uc_offload_enable_disable(a7, 1, a3, 0);
        qdf_mutex_acquire(a7 + 4040);
      }
    }
    if ( (unsigned __int8)a3 > 4u )
      goto LABEL_275;
    *(_BYTE *)(a7 + (unsigned __int8)a3 + 7288) = 5;
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: vdev_to_iface[%u]=%u",
      v123,
      v124,
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      "__wlan_ipa_wlan_evt",
      v22,
      5);
    v290 = wlan_ipa_get_iface_by_mode_netdev(a7, a1, 0, a3);
    if ( v290 )
      v290 = wlan_ipa_cleanup_iface(v290, a5);
    if ( (ipa_get_lan_rx_napi(v290) & 1) != 0 )
    {
      if ( *(_WORD *)(a7 + 3706) )
      {
        v291 = *(_DWORD **)(a7 + 7376);
        if ( v291 )
        {
          if ( *(v291 - 1) != 2130452855 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD, _QWORD))v291)(a3, 0);
        }
      }
    }
    qdf_mutex_release(a7 + 4040);
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: sta_connected=%d",
      v292,
      v293,
      v294,
      v295,
      v296,
      v297,
      v298,
      v299,
      "__wlan_ipa_wlan_evt",
      *(unsigned __int8 *)(a7 + 3710));
    wlan_ipa_log_message(
      (int)"__wlan_ipa_wlan_evt",
      (int)"sta_connected=%d",
      *(unsigned __int8 *)(a7 + 3710),
      v300,
      v301,
      v302,
      v303,
      v304,
      v342);
    goto LABEL_240;
  }
  if ( (**(_BYTE **)(a7 + 1464) & 0x20) == 0 )
  {
    v87 = "%s: %s: Evt: %d, IPA UC OFFLOAD NOT ENABLED";
    v89 = a1 + 296;
    v88 = 8;
    v86 = 6;
LABEL_161:
    qdf_trace_msg(0x61u, v88, v87, v70, v71, v72, v73, v74, v75, v76, v77, "__wlan_ipa_wlan_evt", v89, v86);
    result = 0;
    goto LABEL_247;
  }
  qdf_mutex_acquire(a7 + 4040);
  if ( (wlan_ipa_uc_find_add_assoc_sta(a7, 1, (int)a5) & 1) != 0 )
  {
    qdf_mutex_release(a7 + 4040);
    if ( a5 )
    {
      v204 = *a5;
      v205 = a5[1];
      v206 = a5[2];
      v207 = a5[5];
    }
    else
    {
      v206 = 0;
      v204 = 0;
      v205 = 0;
      v207 = 0;
    }
    v253 = "%s: %s: STA found, addr: %02x:%02x:%02x:**:**:%02x";
    v254 = a1 + 296;
    v255 = 2;
    goto LABEL_168;
  }
  v248 = *(_WORD *)(a7 + 3706);
  if ( !v248 )
  {
    if ( *(_BYTE *)(a7 + 6984) == 1 )
    {
      if ( *(_BYTE *)(a7 + 3710) )
      {
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: IPA pipes already enabled",
          v188,
          v189,
          v190,
          v191,
          v192,
          v193,
          v194,
          v195,
          "__wlan_ipa_wlan_evt");
LABEL_142:
        qdf_trace_msg(
          0x61u,
          4u,
          "%s: first sap client connected",
          v152,
          v153,
          v154,
          v155,
          v156,
          v157,
          v158,
          v159,
          "__wlan_ipa_wlan_evt");
        v248 = *(_WORD *)(a7 + 3706);
        goto LABEL_214;
      }
      if ( !(unsigned int)wlan_ipa_uc_handle_first_con(a7) )
        goto LABEL_142;
LABEL_170:
      qdf_trace_msg(
        0x61u,
        4u,
        "%s: %s: handle 1st con fail",
        v152,
        v153,
        v154,
        v155,
        v156,
        v157,
        v158,
        v159,
        "__wlan_ipa_wlan_evt",
        a1 + 296);
      qdf_mutex_release(a7 + 4040);
      result = 8;
      goto LABEL_247;
    }
    v248 = 0;
  }
LABEL_214:
  *(_WORD *)(a7 + 3706) = v248 + 1;
  qdf_mutex_release(a7 + 4040);
  _qdf_ipa_set_meta_msg_type(&v345, 6u);
  if ( (unsigned int)wlan_ipa_set_peer_id(a7, &v345, a1, 6, a5, a3) )
  {
    result = 16;
  }
  else
  {
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: sap_num_connected_sta=%d",
      v280,
      v281,
      v282,
      v283,
      v284,
      v285,
      v286,
      v287,
      "__wlan_ipa_wlan_evt",
      *(unsigned __int16 *)(a7 + 3706));
    result = 0;
  }
LABEL_247:
  _ReadStatusReg(SP_EL0);
  return result;
}
