__int64 __fastcall wlan_hdd_cfg80211_set_secure_ranging_context(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x25
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x20
  int v28; // w8
  __int64 *v29; // x19
  __int64 v30; // x23
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
  int v47; // w0
  __int64 v48; // x20
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x20
  __int64 v66; // x0
  __int64 v67; // x22
  __int64 vdev_by_user; // x0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x23
  __int64 v78; // x0
  unsigned int *v79; // x8
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  unsigned int *v88; // x8
  unsigned __int8 *v89; // x21
  int v90; // w24
  unsigned int v91; // w0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  unsigned int *v108; // x8
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  unsigned int *v117; // x8
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  unsigned __int8 *v134; // x0
  unsigned __int8 *v135; // x20
  __int64 v136; // x0
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
  int v154; // w8
  unsigned __int16 v155; // w9
  unsigned int *v156; // x8
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  __int64 v165; // x21
  int v166; // w19
  __int64 v167; // x20
  __int64 v168; // x20
  unsigned int v169; // w19
  _QWORD *v170; // x0
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  __int64 v179; // x21
  char v180; // w23
  double v181; // d0
  double v182; // d1
  double v183; // d2
  double v184; // d3
  double v185; // d4
  double v186; // d5
  double v187; // d6
  double v188; // d7
  unsigned __int8 *v189; // x0
  unsigned __int8 *v190; // x21
  unsigned __int8 v191; // w8
  double v192; // d0
  double v193; // d1
  double v194; // d2
  double v195; // d3
  double v196; // d4
  double v197; // d5
  double v198; // d6
  double v199; // d7
  unsigned int v200; // w22
  double v201; // d0
  double v202; // d1
  double v203; // d2
  double v204; // d3
  double v205; // d4
  double v206; // d5
  double v207; // d6
  double v208; // d7
  int v209; // w22
  __int64 v210; // x21
  double v211; // d0
  double v212; // d1
  double v213; // d2
  double v214; // d3
  double v215; // d4
  double v216; // d5
  double v217; // d6
  double v218; // d7
  __int64 v219; // x21
  double v220; // d0
  double v221; // d1
  double v222; // d2
  double v223; // d3
  double v224; // d4
  double v225; // d5
  double v226; // d6
  double v227; // d7
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
  double v244; // d0
  unsigned int *v245; // x8
  double v246; // d1
  double v247; // d2
  double v248; // d3
  double v249; // d4
  double v250; // d5
  double v251; // d6
  double v252; // d7
  unsigned int v253; // w22
  unsigned int *v254; // x8
  double v255; // d0
  double v256; // d1
  double v257; // d2
  double v258; // d3
  double v259; // d4
  double v260; // d5
  double v261; // d6
  double v262; // d7
  double v263; // d0
  double v264; // d1
  double v265; // d2
  double v266; // d3
  double v267; // d4
  double v268; // d5
  double v269; // d6
  double v270; // d7
  unsigned int v271; // w0
  _QWORD *peer_by_mac; // x0
  double v273; // d0
  double v274; // d1
  double v275; // d2
  double v276; // d3
  double v277; // d4
  double v278; // d5
  double v279; // d6
  double v280; // d7
  __int64 v281; // x21
  char is_ltf_keyseed_required_for_peer; // w22
  double v283; // d0
  double v284; // d1
  double v285; // d2
  double v286; // d3
  double v287; // d4
  double v288; // d5
  double v289; // d6
  double v290; // d7
  unsigned __int8 *v291; // x0
  unsigned __int8 *v292; // x21
  unsigned __int8 v293; // w8
  double v294; // d0
  double v295; // d1
  double v296; // d2
  double v297; // d3
  double v298; // d4
  double v299; // d5
  double v300; // d6
  double v301; // d7
  double v302; // d0
  double v303; // d1
  double v304; // d2
  double v305; // d3
  double v306; // d4
  double v307; // d5
  double v308; // d6
  double v309; // d7
  unsigned int v310; // w19
  double v311; // d0
  double v312; // d1
  double v313; // d2
  double v314; // d3
  double v315; // d4
  double v316; // d5
  double v317; // d6
  double v318; // d7
  __int64 v319; // x22
  __int64 *v320; // [xsp+8h] [xbp-68h] BYREF
  int v321; // [xsp+10h] [xbp-60h] BYREF
  __int16 v322; // [xsp+14h] [xbp-5Ch]
  int v323; // [xsp+18h] [xbp-58h] BYREF
  __int16 v324; // [xsp+1Ch] [xbp-54h]
  __int64 v325; // [xsp+20h] [xbp-50h] BYREF
  __int64 v326; // [xsp+28h] [xbp-48h]
  __int64 v327; // [xsp+30h] [xbp-40h]
  __int64 v328; // [xsp+38h] [xbp-38h]
  __int64 v329; // [xsp+40h] [xbp-30h]
  unsigned __int16 *v330; // [xsp+48h] [xbp-28h]
  __int64 v331; // [xsp+50h] [xbp-20h]
  unsigned __int16 *v332; // [xsp+58h] [xbp-18h]
  __int64 v333; // [xsp+60h] [xbp-10h]
  __int64 v334; // [xsp+68h] [xbp-8h]

  v334 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v320 = nullptr;
  result = _osif_vdev_sync_op_start(v8, &v320, (__int64)"wlan_hdd_cfg80211_set_secure_ranging_context");
  if ( (_DWORD)result )
    goto LABEL_50;
  if ( a1 )
  {
    v18 = *(_QWORD *)(a2 + 32);
    v332 = nullptr;
    v333 = 0;
    v330 = nullptr;
    v331 = 0;
    v328 = 0;
    v329 = 0;
    v326 = 0;
    v327 = 0;
    v325 = 0;
    v322 = 0;
    v321 = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__wlan_hdd_cfg80211_set_secure_ranging_context");
    if ( (unsigned int)_nla_parse(&v325, 8, a3, a4, &wifi_pos_pasn_set_ranging_ctx_policy, 31, 0) )
    {
      v27 = jiffies;
      if ( _wlan_hdd_cfg80211_set_secure_ranging_context___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid PASN auth status attributes",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "__wlan_hdd_cfg80211_set_secure_ranging_context");
        _wlan_hdd_cfg80211_set_secure_ranging_context___last_ticks = v27;
      }
      goto LABEL_48;
    }
    if ( !v326 )
    {
      v48 = jiffies;
      if ( _wlan_hdd_cfg80211_set_secure_ranging_context___last_ticks_19 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Action attribute is missing",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "__wlan_hdd_cfg80211_set_secure_ranging_context");
        _wlan_hdd_cfg80211_set_secure_ranging_context___last_ticks_19 = v48;
      }
      goto LABEL_48;
    }
    v28 = *(_DWORD *)(v326 + 4);
    v29 = (__int64 *)(a1 + 1536);
    if ( v28 == 1 )
    {
      if ( !v328 )
      {
        v65 = jiffies;
        if ( _wlan_hdd_cfg80211_set_secure_ranging_context___last_ticks_23 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Peer mac address attribute is missing",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            "__wlan_hdd_cfg80211_set_secure_ranging_context");
          _wlan_hdd_cfg80211_set_secure_ranging_context___last_ticks_23 = v65;
        }
        goto LABEL_48;
      }
      qdf_mem_copy(&v321, (const void *)(v328 + 4), 6u);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Delete PASN peer%02x:%02x:%02x:**:**:%02x",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "__wlan_hdd_cfg80211_set_secure_ranging_context",
        (unsigned __int8)v321,
        BYTE1(v321),
        BYTE2(v321),
        HIBYTE(v322));
      wifi_pos_send_pasn_peer_deauth(*v29, (__int64)&v321, v57, v58, v59, v60, v61, v62, v63, v64);
      goto LABEL_19;
    }
    if ( v28 )
      goto LABEL_19;
    if ( !v330 || *v330 == 4 )
    {
LABEL_11:
      if ( v332 && *v332 != 4 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Set LTF keyseed",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "__wlan_hdd_cfg80211_set_secure_ranging_context");
        v30 = *(_QWORD *)(a2 + 32);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: enter",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "wlan_hdd_cfg80211_send_set_ltf_keyseed");
        if ( (unsigned int)hdd_get_conparam() == 5 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Command not allowed in FTM mode",
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            "wlan_hdd_cfg80211_send_set_ltf_keyseed");
          v47 = -1;
LABEL_49:
          v169 = v47;
          _osif_vdev_sync_op_stop((__int64)v320, (__int64)"wlan_hdd_cfg80211_set_secure_ranging_context");
          result = v169;
LABEL_50:
          _ReadStatusReg(SP_EL0);
          return result;
        }
        if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                              *(_BYTE *)(*(_QWORD *)(v30 + 55520) + 8LL),
                              (__int64)"wlan_hdd_cfg80211_send_set_ltf_keyseed",
                              v39,
                              v40,
                              v41,
                              v42,
                              v43,
                              v44,
                              v45,
                              v46) )
        {
          v47 = _wlan_hdd_validate_context(
                  (__int64)v29,
                  (__int64)"wlan_hdd_cfg80211_send_set_ltf_keyseed",
                  v126,
                  v127,
                  v128,
                  v129,
                  v130,
                  v131,
                  v132,
                  v133);
          if ( v47 )
            goto LABEL_49;
          v134 = (unsigned __int8 *)_qdf_mem_malloc(0x40u, "wlan_hdd_cfg80211_send_set_ltf_keyseed", 507);
          if ( v134 )
          {
            v135 = v134;
            *v134 = *(_BYTE *)(*(_QWORD *)(v30 + 55520) + 8LL);
            v136 = ((__int64 (__fastcall *)(__int64))wlan_objmgr_get_vdev_by_id_from_psoc)(*v29);
            if ( !v136 )
            {
              v210 = jiffies;
              if ( wlan_hdd_cfg80211_send_set_ltf_keyseed___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Vdev is not found for id:%d",
                  v137,
                  v138,
                  v139,
                  v140,
                  v141,
                  v142,
                  v143,
                  v144,
                  "wlan_hdd_cfg80211_send_set_ltf_keyseed",
                  *v135);
                wlan_hdd_cfg80211_send_set_ltf_keyseed___last_ticks = v210;
                v166 = -22;
                goto LABEL_65;
              }
              goto LABEL_64;
            }
            if ( v328 )
            {
              v145 = v136;
              qdf_mem_copy(v135 + 1, (const void *)(v328 + 4), 6u);
              if ( v327 )
                qdf_mem_copy(v135 + 7, (const void *)(v327 + 4), 6u);
              v154 = *v332;
              v155 = v154 - 53;
              v156 = (unsigned int *)(unsigned int)(v154 - 4);
              *((_WORD *)v135 + 31) = (_WORD)v156;
              if ( v155 <= 0xFFEEu )
              {
                wlan_objmgr_vdev_release_ref(v145, 0x28u, v156, v146, v147, v148, v149, v150, v151, v152, v153);
                v165 = jiffies;
                if ( wlan_hdd_cfg80211_send_set_ltf_keyseed___last_ticks_37 - jiffies + 125 < 0 )
                {
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: Invalid key seed length:%d",
                    v157,
                    v158,
                    v159,
                    v160,
                    v161,
                    v162,
                    v163,
                    v164,
                    "wlan_hdd_cfg80211_send_set_ltf_keyseed",
                    *((unsigned __int16 *)v135 + 31));
                  wlan_hdd_cfg80211_send_set_ltf_keyseed___last_ticks_37 = v165;
                  v166 = -22;
                  goto LABEL_65;
                }
                goto LABEL_64;
              }
              qdf_mem_copy(v135 + 14, v332 + 2, (unsigned __int16)v156);
              if ( (wlan_vdev_mlme_is_mlo_vdev(v145, v228, v229, v230, v231, v232, v233, v234, v235) & 1) != 0 )
              {
                v244 = wlan_hdd_cfg80211_send_set_ltf_keyseed_mlo_vdev(v29, v145, v30 + 2688, v135);
                wlan_objmgr_vdev_release_ref(v145, 0x28u, v245, v244, v246, v247, v248, v249, v250, v251, v252);
              }
              else
              {
                v253 = wlan_crypto_set_ltf_keyseed(*v29, v236, v237, v238, v239, v240, v241, v242, v243);
                wlan_objmgr_vdev_release_ref(v145, 0x28u, v254, v255, v256, v257, v258, v259, v260, v261, v262);
                if ( v253 )
                {
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: Set LTF Keyseed failed vdev_id:%d",
                    v263,
                    v264,
                    v265,
                    v266,
                    v267,
                    v268,
                    v269,
                    v270,
                    "wlan_hdd_cfg80211_send_set_ltf_keyseed",
                    *v135);
                  v271 = v253;
LABEL_72:
                  v166 = qdf_status_to_os_return(v271);
                  goto LABEL_65;
                }
              }
              peer_by_mac = wlan_objmgr_get_peer_by_mac(*v29, v135 + 1, 0xDu);
              if ( peer_by_mac )
              {
                v281 = (__int64)peer_by_mac;
                if ( *((_DWORD *)peer_by_mac + 17) == 12 )
                {
                  is_ltf_keyseed_required_for_peer = wifi_pos_is_ltf_keyseed_required_for_peer(
                                                       (__int64)peer_by_mac,
                                                       v273,
                                                       v274,
                                                       v275,
                                                       v276,
                                                       v277,
                                                       v278,
                                                       v279,
                                                       v280);
                  wlan_objmgr_peer_release_ref(v281, 0xDu, v283, v284, v285, v286, v287, v288, v289, v290);
                  if ( (is_ltf_keyseed_required_for_peer & 1) != 0 )
                  {
                    v291 = (unsigned __int8 *)_qdf_mem_malloc(0x1204u, "wlan_hdd_cfg80211_send_set_ltf_keyseed", 616);
                    if ( v291 )
                    {
                      v292 = v291;
                      v293 = *(_BYTE *)(*(_QWORD *)(v30 + 55520) + 8LL);
                      v291[1] = 1;
                      *v291 = v293;
                      qdf_mem_copy(v291 + 4, v135 + 1, 6u);
                      qdf_mem_copy(v292 + 10, v135 + 7, 6u);
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: vdev:%d Send pasn auth status",
                        v294,
                        v295,
                        v296,
                        v297,
                        v298,
                        v299,
                        v300,
                        v301,
                        "wlan_hdd_cfg80211_send_set_ltf_keyseed",
                        *v292);
                      v310 = wifi_pos_send_pasn_auth_status(*v29, v292, v302, v303, v304, v305, v306, v307, v308, v309);
                      _qdf_mem_free((__int64)v292);
                      if ( v310 )
                        qdf_trace_msg(
                          0x33u,
                          2u,
                          "%s: Send PASN auth status failed",
                          v311,
                          v312,
                          v313,
                          v314,
                          v315,
                          v316,
                          v317,
                          v318,
                          "wlan_hdd_cfg80211_send_set_ltf_keyseed");
                      v271 = v310;
                      goto LABEL_72;
                    }
                    v166 = -12;
LABEL_65:
                    _qdf_mem_free((__int64)v135);
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: exit",
                      v220,
                      v221,
                      v222,
                      v223,
                      v224,
                      v225,
                      v226,
                      v227,
                      "wlan_hdd_cfg80211_send_set_ltf_keyseed");
                    v47 = v166;
                    if ( v166 )
                      goto LABEL_49;
                    goto LABEL_19;
                  }
                }
                else
                {
                  wlan_objmgr_peer_release_ref(
                    (__int64)peer_by_mac,
                    0xDu,
                    v273,
                    v274,
                    v275,
                    v276,
                    v277,
                    v278,
                    v279,
                    v280);
                }
              }
              else
              {
                v319 = jiffies;
                if ( wlan_hdd_cfg80211_send_set_ltf_keyseed___last_ticks_40 - jiffies + 125 < 0 )
                {
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: PASN peer is not found",
                    v273,
                    v274,
                    v275,
                    v276,
                    v277,
                    v278,
                    v279,
                    v280,
                    "wlan_hdd_cfg80211_send_set_ltf_keyseed");
                  v166 = 0;
                  wlan_hdd_cfg80211_send_set_ltf_keyseed___last_ticks_40 = v319;
                  goto LABEL_65;
                }
              }
              v166 = 0;
              goto LABEL_65;
            }
            wlan_objmgr_vdev_release_ref(v136, 0x28u, nullptr, v137, v138, v139, v140, v141, v142, v143, v144);
            v219 = jiffies;
            if ( wlan_hdd_cfg80211_send_set_ltf_keyseed___last_ticks_36 - jiffies + 125 >= 0 )
            {
LABEL_64:
              v166 = -22;
              goto LABEL_65;
            }
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: BSSID is not present",
              v211,
              v212,
              v213,
              v214,
              v215,
              v216,
              v217,
              v218,
              "wlan_hdd_cfg80211_send_set_ltf_keyseed");
            wlan_hdd_cfg80211_send_set_ltf_keyseed___last_ticks_36 = v219;
            v166 = -22;
            goto LABEL_65;
          }
LABEL_60:
          v47 = -12;
          goto LABEL_49;
        }
LABEL_48:
        v47 = -22;
        goto LABEL_49;
      }
LABEL_19:
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: exit",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "__wlan_hdd_cfg80211_set_secure_ranging_context");
      v47 = 0;
      goto LABEL_49;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Sec ranging CTX TK",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "__wlan_hdd_cfg80211_set_secure_ranging_context");
    v66 = *(_QWORD *)(v18 + 55520);
    v67 = **(_QWORD **)(v18 + 2712);
    v324 = 0;
    v323 = 0;
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(v66, 0xDu, (__int64)"wlan_cfg80211_set_pasn_key");
    if ( !vdev_by_user )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Key params is NULL",
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        "wlan_cfg80211_set_pasn_key");
      goto LABEL_48;
    }
    v77 = vdev_by_user;
    v78 = _qdf_mem_malloc(0x1B0u, "wlan_cfg80211_set_pasn_key", 267);
    if ( !v78 )
    {
      _hdd_objmgr_put_vdev_by_user(
        v77,
        0xDu,
        (__int64)"wlan_cfg80211_set_pasn_key",
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87);
      v47 = -12;
      goto LABEL_49;
    }
    v88 = (unsigned int *)v331;
    v89 = (unsigned __int8 *)v78;
    if ( v331 )
    {
      v90 = *(_DWORD *)(v331 + 4);
      *(_DWORD *)(v78 + 8) = osif_nl_to_crypto_cipher_type(v90);
      v91 = osif_nl_to_crypto_cipher_len(v90);
      v88 = (unsigned int *)((unsigned int)*v330 - 4);
      *v89 = *v330 - 4;
      if ( (v91 & 0x80000000) != 0 || (unsigned __int8)v88 > 0x30u || v91 > (unsigned __int8)v88 )
      {
        v167 = jiffies;
        if ( wlan_cfg80211_set_pasn_key___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid key length %d",
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            v87,
            "wlan_cfg80211_set_pasn_key",
            (unsigned __int8)v88);
          wlan_cfg80211_set_pasn_key___last_ticks = v167;
        }
      }
      else
      {
        *((_WORD *)v89 + 2) = 0;
        qdf_mem_copy(v89 + 384, v330 + 2, (unsigned __int8)v88);
        if ( v328 )
        {
          qdf_mem_copy(v89 + 16, (const void *)(v328 + 4), 6u);
          qdf_mem_copy(&v323, (const void *)(v328 + 4), 6u);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: PASN unicast key opmode %d, key_len %d",
            v92,
            v93,
            v94,
            v95,
            v96,
            v97,
            v98,
            v99,
            "wlan_cfg80211_set_pasn_key",
            *(unsigned int *)(v77 + 16),
            *v89);
          if ( (unsigned int)ucfg_crypto_set_key_req(v77, v100, v101, v102, v103, v104, v105, v106, v107) )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: PASN set_key failed",
              v109,
              v110,
              v111,
              v112,
              v113,
              v114,
              v115,
              v116,
              "wlan_cfg80211_set_pasn_key");
            _hdd_objmgr_put_vdev_by_user(
              v77,
              0xDu,
              (__int64)"wlan_cfg80211_set_pasn_key",
              v117,
              v118,
              v119,
              v120,
              v121,
              v122,
              v123,
              v124,
              v125);
            _qdf_mem_free((__int64)v89);
            v47 = -14;
            goto LABEL_49;
          }
          _hdd_objmgr_put_vdev_by_user(
            v77,
            0xDu,
            (__int64)"wlan_cfg80211_set_pasn_key",
            v108,
            v109,
            v110,
            v111,
            v112,
            v113,
            v114,
            v115,
            v116);
          _qdf_mem_free((__int64)v89);
          v170 = wlan_objmgr_get_peer_by_mac(v67, &v323, 0xDu);
          if ( !v170 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: PASN peer is not found",
              v171,
              v172,
              v173,
              v174,
              v175,
              v176,
              v177,
              v178,
              "wlan_cfg80211_set_pasn_key");
            v47 = -14;
            goto LABEL_49;
          }
          v179 = (__int64)v170;
          v180 = wifi_pos_is_ltf_keyseed_required_for_peer(
                   (__int64)v170,
                   v171,
                   v172,
                   v173,
                   v174,
                   v175,
                   v176,
                   v177,
                   v178);
          wlan_objmgr_peer_release_ref(v179, 0xDu, v181, v182, v183, v184, v185, v186, v187, v188);
          if ( (v180 & 1) == 0 )
          {
            v189 = (unsigned __int8 *)_qdf_mem_malloc(0x1204u, "wlan_cfg80211_set_pasn_key", 349);
            if ( !v189 )
              goto LABEL_60;
            v190 = v189;
            v191 = *(_BYTE *)(*(_QWORD *)(v18 + 55520) + 8LL);
            v189[1] = 1;
            *v189 = v191;
            qdf_mem_copy(v189 + 4, &v323, 6u);
            if ( v327 )
              qdf_mem_copy(v190 + 10, (const void *)(v327 + 4), 6u);
            v200 = wifi_pos_send_pasn_auth_status(v67, v190, v192, v193, v194, v195, v196, v197, v198, v199);
            if ( v200 )
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Send PASN auth status failed",
                v201,
                v202,
                v203,
                v204,
                v205,
                v206,
                v207,
                v208,
                "wlan_cfg80211_set_pasn_key");
            v209 = qdf_status_to_os_return(v200);
            _qdf_mem_free((__int64)v190);
            v47 = v209;
            if ( v209 )
              goto LABEL_49;
          }
          goto LABEL_11;
        }
        v168 = jiffies;
        v88 = (unsigned int *)(wlan_cfg80211_set_pasn_key___last_ticks_29 - jiffies);
        if ( wlan_cfg80211_set_pasn_key___last_ticks_29 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: BSSID is not present",
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            v87,
            "wlan_cfg80211_set_pasn_key");
          wlan_cfg80211_set_pasn_key___last_ticks_29 = v168;
        }
      }
    }
    _hdd_objmgr_put_vdev_by_user(
      v77,
      0xDu,
      (__int64)"wlan_cfg80211_set_pasn_key",
      v88,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87);
    _qdf_mem_free((__int64)v89);
    goto LABEL_48;
  }
  __break(0x800u);
  return ((__int64 (*)(void))wlan_hdd_cfg80211_send_set_ltf_keyseed_mlo_vdev)();
}
