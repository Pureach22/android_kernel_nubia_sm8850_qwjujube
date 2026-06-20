__int64 __fastcall os_if_nan_datapath_event_handler(
        __int64 result,
        __int64 a2,
        int a3,
        unsigned __int8 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _QWORD *v14; // x21
  __int64 v15; // x20
  unsigned __int64 v16; // x8
  int *v17; // x9
  int v18; // t1
  unsigned int v19; // w10
  __int64 v20; // x6
  __int64 v21; // x0
  __int64 v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x3
  __int64 v32; // x8
  _QWORD *v33; // x24
  unsigned __int64 v34; // x25
  unsigned int v35; // w21
  const char *v36; // x2
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x27
  unsigned int v48; // w23
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x2
  __int64 v58; // x8
  unsigned __int8 *v59; // x13
  unsigned int v60; // w12
  unsigned __int64 v61; // x11
  unsigned int v62; // w14
  unsigned int v63; // w15
  unsigned int v64; // t1
  unsigned int *v65; // x9
  __int64 v66; // x8
  unsigned int v67; // w10
  unsigned int v68; // t1
  void (__fastcall *v69)(_QWORD, int *, __int64); // x8
  __int64 v70; // x8
  _QWORD *v71; // x21
  const char *v72; // x3
  __int64 v73; // x0
  __int64 v74; // x8
  __int64 v75; // x22
  __int64 v76; // x0
  __int64 v77; // x8
  __int64 v78; // x23
  __int64 v79; // x0
  _QWORD *v80; // x21
  unsigned int ndi_state; // w0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x4
  const char *v91; // x2
  const char *v92; // x3
  __int64 v93; // x8
  __int64 v94; // x21
  const char *v95; // x0
  unsigned int v96; // w22
  unsigned int v97; // w23
  unsigned int v98; // w21
  int v99; // w22
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  int v108; // w22
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  __int64 (__fastcall *v117)(_QWORD, __int64, unsigned __int8 *, bool); // x8
  __int64 v118; // x1
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  __int64 comp_private_obj; // x0
  __int64 v128; // x0
  __int64 v129; // x19
  unsigned int v130; // w23
  int active_peers; // w0
  int v132; // w22
  __int64 v133; // x0
  __int64 v134; // x21
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  _QWORD *v143; // x24
  unsigned int v144; // w21
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  int v153; // w9
  char v154; // w10
  unsigned __int64 v155; // x8
  __int16 v156; // w9
  __int16 v157; // w10
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  __int64 (__fastcall *v174)(_QWORD, __int64, unsigned __int8 *, bool); // x8
  __int64 v175; // x1
  unsigned int v176; // w0
  int v177; // w8
  __int64 v178; // x6
  const char *v179; // x0
  const char *v180; // x23
  size_t v181; // x22
  double v182; // d0
  double v183; // d1
  double v184; // d2
  double v185; // d3
  double v186; // d4
  double v187; // d5
  double v188; // d6
  double v189; // d7
  const char *v190; // x3
  __int64 v191; // x2
  __int64 v192; // x8
  unsigned __int16 transaction_id; // w24
  __int64 v194; // x0
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  __int64 v203; // x21
  double v204; // d0
  double v205; // d1
  double v206; // d2
  double v207; // d3
  double v208; // d4
  double v209; // d5
  double v210; // d6
  double v211; // d7
  const char *v212; // x2
  int v213; // w9
  char v214; // w10
  int v215; // w8
  double v216; // d0
  double v217; // d1
  double v218; // d2
  double v219; // d3
  double v220; // d4
  double v221; // d5
  double v222; // d6
  double v223; // d7
  double v224; // d0
  double v225; // d1
  double v226; // d2
  double v227; // d3
  double v228; // d4
  double v229; // d5
  double v230; // d6
  double v231; // d7
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  double v240; // d0
  double v241; // d1
  double v242; // d2
  double v243; // d3
  double v244; // d4
  double v245; // d5
  double v246; // d6
  double v247; // d7
  __int64 (__fastcall *v248)(__int64); // x8
  __int64 v249; // x0
  double v250; // d0
  double v251; // d1
  double v252; // d2
  double v253; // d3
  double v254; // d4
  double v255; // d5
  double v256; // d6
  double v257; // d7
  double v258; // d0
  double v259; // d1
  double v260; // d2
  double v261; // d3
  double v262; // d4
  double v263; // d5
  double v264; // d6
  double v265; // d7
  __int64 v266; // x0
  __int64 v267; // x20
  double v268; // d0
  double v269; // d1
  double v270; // d2
  double v271; // d3
  double v272; // d4
  double v273; // d5
  double v274; // d6
  double v275; // d7
  __int64 v276; // x1
  int v277; // w10
  int v278; // w8
  __int16 v279; // w9
  __int16 v280; // w11
  bool v281; // zf
  __int16 v282; // w8
  __int16 v283; // w9
  unsigned __int16 v284; // w8
  __int64 v285; // x0
  unsigned int *v286; // x11
  unsigned int v287; // w13
  unsigned __int64 v288; // x12
  unsigned int v289; // w14
  unsigned int v290; // w15
  unsigned int v291; // t1
  unsigned __int8 *v292; // x9
  __int64 v293; // x8
  unsigned int *v294; // x9
  unsigned int v295; // w10
  unsigned int v296; // t1
  void (__fastcall *v297)(_QWORD, unsigned __int8 *, __int64); // x8
  const char *if_name; // x0
  const char *v299; // x23
  int v300; // w8
  unsigned int v301; // w8
  __int64 v302; // x0
  unsigned int v303; // w1
  double v304; // d0
  double v305; // d1
  double v306; // d2
  double v307; // d3
  double v308; // d4
  double v309; // d5
  double v310; // d6
  double v311; // d7
  double v312; // d0
  double v313; // d1
  double v314; // d2
  double v315; // d3
  double v316; // d4
  double v317; // d5
  double v318; // d6
  double v319; // d7
  void (__fastcall *v320)(__int64, unsigned __int8 *); // x8
  __int64 v321; // x0
  double v322; // d0
  double v323; // d1
  double v324; // d2
  double v325; // d3
  double v326; // d4
  double v327; // d5
  double v328; // d6
  double v329; // d7
  __int64 v330; // x0
  __int64 v331; // x2
  double v332; // d0
  double v333; // d1
  double v334; // d2
  double v335; // d3
  double v336; // d4
  double v337; // d5
  double v338; // d6
  double v339; // d7
  double v340; // d0
  double v341; // d1
  double v342; // d2
  double v343; // d3
  double v344; // d4
  double v345; // d5
  double v346; // d6
  double v347; // d7
  __int64 v348; // x22
  __int64 v349; // x2
  unsigned __int8 *v350; // [xsp+18h] [xbp-F8h]
  __int64 v351; // [xsp+20h] [xbp-F0h] BYREF
  __int64 v352; // [xsp+28h] [xbp-E8h]
  __int64 v353; // [xsp+30h] [xbp-E0h]
  __int64 v354; // [xsp+38h] [xbp-D8h]
  __int64 v355; // [xsp+40h] [xbp-D0h]
  __int64 v356; // [xsp+48h] [xbp-C8h]
  __int64 (__fastcall *v357)(__int64); // [xsp+50h] [xbp-C0h]
  __int64 v358; // [xsp+58h] [xbp-B8h]
  void (__fastcall *v359)(__int64, unsigned __int8 *); // [xsp+60h] [xbp-B0h]
  __int64 (__fastcall *v360)(__int64); // [xsp+68h] [xbp-A8h]
  __int64 (__fastcall *v361)(_QWORD, __int64, unsigned __int8 *, bool); // [xsp+70h] [xbp-A0h]
  __int64 v362; // [xsp+78h] [xbp-98h]
  __int64 (__fastcall *v363)(_QWORD, __int64, unsigned __int8 *, bool); // [xsp+80h] [xbp-90h]
  __int64 v364; // [xsp+88h] [xbp-88h]
  __int64 v365; // [xsp+90h] [xbp-80h]
  __int64 v366; // [xsp+98h] [xbp-78h]
  __int64 v367; // [xsp+A0h] [xbp-70h]
  __int64 v368; // [xsp+A8h] [xbp-68h]
  __int64 v369; // [xsp+B0h] [xbp-60h]
  __int64 v370; // [xsp+B8h] [xbp-58h]
  __int64 v371; // [xsp+C0h] [xbp-50h]
  __int64 v372; // [xsp+C8h] [xbp-48h]
  __int64 v373; // [xsp+D0h] [xbp-40h]
  void (__fastcall *v374)(_QWORD, unsigned __int8 *, __int64); // [xsp+D8h] [xbp-38h]
  int v375; // [xsp+E4h] [xbp-2Ch] BYREF
  __int16 v376; // [xsp+E8h] [xbp-28h]
  unsigned __int64 time_of_the_day_us; // [xsp+EAh] [xbp-26h]
  unsigned __int64 StatusReg; // [xsp+F2h] [xbp-1Eh]
  _BYTE v379[3]; // [xsp+FAh] [xbp-16h]
  char v380; // [xsp+FDh] [xbp-13h]
  __int16 v381; // [xsp+FEh] [xbp-12h]
  __int64 v382; // [xsp+100h] [xbp-10h]

  v382 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 <= 9 )
  {
    if ( a3 > 4 )
    {
      if ( a3 == 5 )
      {
        if ( a4 )
        {
          v79 = _cfg80211_alloc_event_skb(**(_QWORD **)(*(_QWORD *)(a2 + 152) + 24LL), 0, 103, 197, 0, 26, 56, 2080);
          if ( v79 )
          {
            v22 = v79;
            LODWORD(v351) = 4;
            if ( (unsigned int)nla_put(v79, 1, 4, &v351)
              || (LOWORD(v351) = *((_DWORD *)a4 + 2), (unsigned int)nla_put(v22, 2, 2, &v351))
              || (LODWORD(v351) = *((_DWORD *)a4 + 3), (unsigned int)nla_put(v22, 10, 4, &v351))
              || (LODWORD(v351) = *((_DWORD *)a4 + 4), (unsigned int)nla_put(v22, 14, 4, &v351))
              || (LODWORD(v351) = *((_DWORD *)a4 + 5), (unsigned int)nla_put(v22, 15, 4, &v351)) )
            {
              v31 = "os_if_ndp_initiator_rsp_handler";
              goto LABEL_245;
            }
            os_if_cstats_log_ndp_initiator_resp_evt(a2, a4);
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: NDP Initiator rsp sent, tid:%d, instance id:%d, status:%d, reason: %d",
              v322,
              v323,
              v324,
              v325,
              v326,
              v327,
              v328,
              v329,
              "os_if_ndp_initiator_rsp_handler",
              *((unsigned int *)a4 + 2),
              *((unsigned int *)a4 + 3),
              *((unsigned int *)a4 + 4),
              *((unsigned int *)a4 + 5));
            goto LABEL_272;
          }
          v36 = "%s: wlan_cfg80211_vendor_event_alloc failed";
        }
        else
        {
          v36 = "%s: Invalid NDP Initiator response";
        }
        v72 = "os_if_ndp_initiator_rsp_handler";
        goto LABEL_249;
      }
      if ( a3 != 7 )
      {
        if ( a3 != 9 )
          goto LABEL_251;
        if ( a4 )
        {
          v21 = _cfg80211_alloc_event_skb(**(_QWORD **)(*(_QWORD *)(a2 + 152) + 24LL), 0, 103, 197, 0, 26, 48, 2080);
          if ( v21 )
          {
            v22 = v21;
            LODWORD(v351) = 8;
            if ( (unsigned int)nla_put(v21, 1, 4, &v351)
              || (LODWORD(v351) = *((_DWORD *)a4 + 3), (unsigned int)nla_put(v22, 14, 4, &v351))
              || (LODWORD(v351) = *((_DWORD *)a4 + 4), (unsigned int)nla_put(v22, 15, 4, &v351))
              || (LOWORD(v351) = *((_DWORD *)a4 + 2), (unsigned int)nla_put(v22, 2, 2, &v351)) )
            {
              v31 = "os_if_ndp_end_rsp_handler";
LABEL_245:
              qdf_trace_msg(0x48u, 2u, "%s: nla_put api failed", v23, v24, v25, v26, v27, v28, v29, v30, v31);
              v276 = v22;
              goto LABEL_246;
            }
            os_if_cstats_log_ndp_end_rsp_evt(a2, a4);
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: NDP End rsp sent, transaction id: %u, status: %u, reason: %u",
              v304,
              v305,
              v306,
              v307,
              v308,
              v309,
              v310,
              v311,
              "os_if_ndp_end_rsp_handler",
              *((unsigned int *)a4 + 2),
              *((unsigned int *)a4 + 3),
              *((unsigned int *)a4 + 4));
            goto LABEL_272;
          }
          v36 = "%s: wlan_cfg80211_vendor_event_alloc failed";
        }
        else
        {
          v36 = "%s: Invalid ndp end response";
        }
        v72 = "os_if_ndp_end_rsp_handler";
        goto LABEL_249;
      }
      if ( a4 )
      {
        v73 = _cfg80211_alloc_event_skb(**(_QWORD **)(*(_QWORD *)(a2 + 152) + 24LL), 0, 103, 197, 0, 26, 48, 2080);
        if ( v73 )
        {
          v22 = v73;
          LODWORD(v351) = 6;
          if ( (unsigned int)nla_put(v73, 1, 4, &v351)
            || (LOWORD(v351) = *((_DWORD *)a4 + 2), (unsigned int)nla_put(v22, 2, 2, &v351))
            || (LODWORD(v351) = *((_DWORD *)a4 + 3), (unsigned int)nla_put(v22, 14, 4, &v351))
            || (LODWORD(v351) = *((_DWORD *)a4 + 4), (unsigned int)nla_put(v22, 15, 4, &v351)) )
          {
            v31 = "os_if_ndp_responder_rsp_handler";
            goto LABEL_245;
          }
          os_if_cstats_log_ndp_responder_resp_evt(a2, a4);
LABEL_272:
          v330 = v22;
          goto LABEL_273;
        }
        v36 = "%s: wlan_cfg80211_vendor_event_alloc failed";
      }
      else
      {
        v36 = "%s: Invalid NDP Responder response";
      }
      v72 = "os_if_ndp_responder_rsp_handler";
      goto LABEL_249;
    }
    if ( a3 != 1 )
    {
      if ( a3 != 3 )
        goto LABEL_251;
      v35 = *(unsigned __int8 *)(a2 + 104);
      v373 = 0;
      v374 = nullptr;
      v371 = 0;
      v372 = 0;
      v369 = 0;
      v370 = 0;
      v367 = 0;
      v368 = 0;
      v365 = 0;
      v366 = 0;
      v363 = nullptr;
      v364 = 0;
      v361 = nullptr;
      v362 = 0;
      v359 = nullptr;
      v360 = nullptr;
      v357 = nullptr;
      v358 = 0;
      v355 = 0;
      v356 = 0;
      v353 = 0;
      v354 = 0;
      v351 = 0;
      v352 = 0;
      if ( !a4 )
      {
        v36 = "%s: Invalid ndi delete response";
        goto LABEL_99;
      }
      if ( (unsigned int)ucfg_nan_get_callbacks(result, &v351, a5, a6, a7, a8, a9, a10, a11, a12) )
      {
        v36 = "%s: Couldn't get ballback object";
LABEL_99:
        v72 = "os_if_ndp_iface_delete_rsp_handler";
        goto LABEL_249;
      }
      if ( *(_DWORD *)a4 )
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: NDI BSS stop failed with reason %d",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "os_if_ndp_iface_delete_rsp_handler",
          *((unsigned int *)a4 + 1));
      else
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: NDI BSS successfully stopped",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "os_if_ndp_iface_delete_rsp_handler");
      v213 = *(_DWORD *)(a2 + 16);
      v214 = *(_BYTE *)(a2 + 104);
      v375 = 1441828;
      LOBYTE(v376) = v213;
      HIBYTE(v376) = v214;
      time_of_the_day_us = qdf_get_time_of_the_day_us();
      __isb(0xFu);
      StatusReg = _ReadStatusReg(CNTVCT_EL0);
      v215 = *((_DWORD *)a4 + 1);
      v379[2] = *(_DWORD *)a4;
      v380 = v215;
      *(_WORD *)v379 = ucfg_nan_get_ndp_delete_transaction_id(a2, v216, v217, v218, v219, v220, v221, v222, v223);
      wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v375, 0x1Au, v224, v225, v226, v227, v228, v229, v230, v231);
      ucfg_nan_set_ndi_delete_rsp_reason(a2, *((_DWORD *)a4 + 1), v232, v233, v234, v235, v236, v237, v238, v239);
      ucfg_nan_set_ndi_delete_rsp_status(a2, *(_DWORD *)a4, v240, v241, v242, v243, v244, v245, v246, v247);
      v248 = v360;
      v249 = v35;
      if ( *((_DWORD *)v360 - 1) != -1560483463 )
        __break(0x8228u);
LABEL_171:
      result = v248(v249);
      goto LABEL_251;
    }
    v70 = *(_QWORD *)(a2 + 152);
    v373 = 0;
    v374 = nullptr;
    v371 = 0;
    v372 = 0;
    v369 = 0;
    v370 = 0;
    v367 = 0;
    v368 = 0;
    v365 = 0;
    v366 = 0;
    v363 = nullptr;
    v364 = 0;
    v361 = nullptr;
    v362 = 0;
    v359 = nullptr;
    v360 = nullptr;
    v357 = nullptr;
    v358 = 0;
    v355 = 0;
    v356 = 0;
    v353 = 0;
    v354 = 0;
    v71 = *(_QWORD **)(v70 + 24);
    v351 = 0;
    v352 = 0;
    if ( (unsigned int)ucfg_nan_get_callbacks(result, &v351, a5, a6, a7, a8, a9, a10, a11, a12) )
    {
      v36 = "%s: Couldn't get ballback object";
      v72 = "os_if_ndp_iface_create_rsp_handler";
      goto LABEL_249;
    }
    if ( a4 )
    {
      v97 = *(_DWORD *)a4;
      v96 = *((_DWORD *)a4 + 1);
    }
    else
    {
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: Invalid ndi create response",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "os_if_ndp_iface_create_rsp_handler");
      v96 = 9001;
      v97 = 1;
    }
    transaction_id = ucfg_nan_get_ndp_create_transaction_id(a2, a5, a6, a7, a8, a9, a10, a11, a12);
    v194 = _cfg80211_alloc_event_skb(*v71, 0, 103, 197, 0, 26, 48, 3264);
    if ( v194 )
    {
      v203 = v194;
      v375 = 1;
      if ( (unsigned int)nla_put(v194, 1, 4, &v375) )
      {
        v212 = "%s: QCA_WLAN_VENDOR_ATTR_NDP_SUBCMD put fail";
      }
      else
      {
        LOWORD(v375) = transaction_id;
        if ( (unsigned int)nla_put(v203, 2, 2, &v375) )
        {
          v212 = "%s: VENDOR_ATTR_NDP_TRANSACTION_ID put fail";
        }
        else
        {
          v375 = v97;
          if ( (unsigned int)nla_put(v203, 14, 4, &v375) )
          {
            v212 = "%s: VENDOR_ATTR_NDP_DRV_RETURN_TYPE put fail";
          }
          else
          {
            v375 = v96;
            if ( !(unsigned int)nla_put(v203, 15, 4, &v375) )
            {
              qdf_trace_msg(
                0x48u,
                8u,
                "%s: transaction id: %u status code: %u Reason: %u",
                v204,
                v205,
                v206,
                v207,
                v208,
                v209,
                v210,
                v211,
                "os_if_ndp_iface_create_rsp_handler",
                transaction_id,
                v97,
                v96);
              if ( a4 )
              {
                v320 = v359;
                v321 = *(unsigned __int8 *)(a2 + 104);
                if ( *((_DWORD *)v359 - 1) != -1109396929 )
                  __break(0x8228u);
                v320(v321, a4);
                result = _cfg80211_send_event_skb(v203, 3264);
                goto LABEL_251;
              }
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: NDI interface creation failed with reason %d",
                v312,
                v313,
                v314,
                v315,
                v316,
                v317,
                v318,
                v319,
                "os_if_ndp_iface_create_rsp_handler",
                v96);
              _cfg80211_send_event_skb(v203, 3264);
              goto LABEL_262;
            }
            v212 = "%s: VENDOR_ATTR_NDP_DRV_RETURN_VALUE put fail";
          }
        }
      }
      qdf_trace_msg(
        0x48u,
        2u,
        v212,
        v204,
        v205,
        v206,
        v207,
        v208,
        v209,
        v210,
        v211,
        "os_if_ndp_iface_create_rsp_handler");
      sk_skb_reason_drop(0, v203, 2);
    }
    else
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: wlan_cfg80211_vendor_event_alloc failed",
        v195,
        v196,
        v197,
        v198,
        v199,
        v200,
        v201,
        v202,
        "os_if_ndp_iface_create_rsp_handler");
    }
LABEL_262:
    v248 = v357;
    v249 = *(unsigned __int8 *)(a2 + 104);
    if ( *((_DWORD *)v357 - 1) != -1560483463 )
      __break(0x8228u);
    goto LABEL_171;
  }
  if ( a3 <= 12 )
  {
    if ( a3 != 10 )
    {
      if ( a3 != 11 )
      {
        if ( a4 )
        {
          v14 = *(_QWORD **)(*(_QWORD *)(a2 + 152) + 24LL);
          result = _qdf_mem_malloc(4LL * *((unsigned int *)a4 + 2), "os_if_ndp_end_ind_handler", 2101);
          if ( !result )
            goto LABEL_251;
          v15 = result;
          if ( !*((_DWORD *)a4 + 2) )
            goto LABEL_126;
          v16 = 0;
          v17 = (int *)(a4 + 36);
          do
          {
            v18 = *v17;
            v17 += 7;
            *(_DWORD *)(result + 4 * v16++) = v18;
            v19 = *((_DWORD *)a4 + 2);
          }
          while ( v16 < v19 );
          if ( v19 )
            v20 = ((4 * v19 + 7) & 0xFFFFFFFC) + 24;
          else
LABEL_126:
            v20 = 24;
          v133 = _cfg80211_alloc_event_skb(*v14, 0, 103, 197, 0, 26, v20, 2080);
          if ( v133 )
          {
            v134 = v133;
            LODWORD(v351) = 11;
            if ( (unsigned int)nla_put(v133, 1, 4, &v351)
              || (unsigned int)nla_put(v134, 11, (unsigned int)(4 * *((_DWORD *)a4 + 2)), v15) )
            {
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: nla_put api failed",
                v135,
                v136,
                v137,
                v138,
                v139,
                v140,
                v141,
                v142,
                "os_if_ndp_end_ind_handler");
              sk_skb_reason_drop(0, v134, 2);
            }
            else
            {
              _cfg80211_send_event_skb(v134, 2080);
            }
            result = _qdf_mem_free(v15);
            goto LABEL_251;
          }
          _qdf_mem_free(v15);
          v36 = "%s: wlan_cfg80211_vendor_event_alloc failed";
        }
        else
        {
          v36 = "%s: Invalid ndp end indication";
        }
        v72 = "os_if_ndp_end_ind_handler";
        goto LABEL_249;
      }
      if ( !a4 )
      {
        v36 = "%s: Invalid NDP Initiator response";
LABEL_248:
        v72 = "os_if_ndp_confirm_ind_handler";
        goto LABEL_249;
      }
      v74 = *(_QWORD *)(a2 + 152);
      v75 = *((unsigned int *)a4 + 8);
      if ( v74 )
        v76 = *(_QWORD *)(v74 + 80);
      else
        v76 = 0;
      v143 = *(_QWORD **)(v74 + 24);
      v144 = *(unsigned __int8 *)(a2 + 104);
      v373 = 0;
      v374 = nullptr;
      v371 = 0;
      v372 = 0;
      v369 = 0;
      v370 = 0;
      v367 = 0;
      v368 = 0;
      v365 = 0;
      v366 = 0;
      v363 = nullptr;
      v364 = 0;
      v361 = nullptr;
      v362 = 0;
      v359 = nullptr;
      v360 = nullptr;
      v357 = nullptr;
      v358 = 0;
      v355 = 0;
      v356 = 0;
      v353 = 0;
      v354 = 0;
      v351 = 0;
      v352 = 0;
      if ( !(_DWORD)v75 )
      {
LABEL_225:
        if_name = (const char *)os_if_ndi_get_if_name(a2);
        if ( if_name )
        {
          v299 = if_name;
          v181 = strlen(if_name);
          if ( v181 >= 0x11 )
          {
            v190 = "os_if_ndp_confirm_ind_handler";
            goto LABEL_228;
          }
          v300 = *((_DWORD *)a4 + 29);
          if ( v300 )
            v301 = ((v300 + 7) & 0xFFFFFFFC) + 80;
          else
            v301 = 80;
          if ( a4[376] )
            v301 += 4;
          if ( a4[393] )
            v301 += 8;
          if ( a4[396] )
            v301 += 8;
          v302 = _cfg80211_alloc_event_skb(*v143, 0, 103, 197, 0, 26, v301 + 24 * *((_DWORD *)a4 + 8), 2080);
          if ( v302 )
          {
            v22 = v302;
            LODWORD(v351) = 10;
            if ( !(unsigned int)nla_put(v302, 1, 4, &v351) )
            {
              LODWORD(v351) = *((_DWORD *)a4 + 2);
              if ( !(unsigned int)nla_put(v22, 10, 4, &v351)
                && !(unsigned int)nla_put(v22, 13, 6, a4 + 20)
                && !(unsigned int)nla_put(v22, 6, (unsigned int)v181, v299) )
              {
                v331 = *((unsigned int *)a4 + 29);
                if ( !(_DWORD)v331 || !(unsigned int)nla_put(v22, 9, v331, a4 + 120) )
                {
                  LODWORD(v351) = *((_DWORD *)a4 + 7);
                  if ( !(unsigned int)nla_put(v22, 12, 4, &v351) )
                  {
                    LODWORD(v351) = *((_DWORD *)a4 + 3);
                    if ( !(unsigned int)nla_put(v22, 15, 4, &v351) )
                    {
                      LODWORD(v351) = *((_DWORD *)a4 + 8);
                      if ( !(unsigned int)nla_put(v22, 24, 4, &v351)
                        && !(unsigned int)os_if_ndp_confirm_pack_ch_info(v22, a4)
                        && (a4[376] != 1 || !(unsigned int)nla_put(v22, 27, 16, a4 + 377)) )
                      {
                        if ( a4[393] != 1
                          || (LOWORD(v351) = *((_WORD *)a4 + 197), !(unsigned int)nla_put(v22, 28, 2, &v351)) )
                        {
                          if ( a4[396] != 1 || (LOBYTE(v351) = a4[397], !(unsigned int)nla_put(v22, 29, 1, &v351)) )
                          {
                            _cfg80211_send_event_skb(v22, 2080);
                            os_if_cstats_log_ndp_confirm_evt(a2, a4);
                            result = qdf_trace_msg(
                                       0x48u,
                                       8u,
                                       "%s: NDP confim sent, ndp instance id: %d, peer addr: %02x:%02x:%02x:**:**:%02x rs"
                                       "p_code: %d, reason_code: %d",
                                       v332,
                                       v333,
                                       v334,
                                       v335,
                                       v336,
                                       v337,
                                       v338,
                                       v339,
                                       "os_if_ndp_confirm_ind_handler",
                                       *((unsigned int *)a4 + 2),
                                       a4[20],
                                       a4[21],
                                       a4[22],
                                       a4[25],
                                       *((_DWORD *)a4 + 7),
                                       *((_DWORD *)a4 + 3));
                            goto LABEL_251;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            v31 = "os_if_ndp_confirm_ind_handler";
            goto LABEL_245;
          }
          v36 = "%s: wlan_cfg80211_vendor_event_alloc failed";
        }
        else
        {
          v36 = "%s: ifname is null";
        }
        goto LABEL_248;
      }
      if ( (unsigned int)ucfg_nan_get_callbacks(v76, &v351, a5, a6, a7, a8, a9, a10, a11, a12) )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Failed to get NAN callbacks",
          v145,
          v146,
          v147,
          v148,
          v149,
          v150,
          v151,
          v152,
          "os_if_ndp_update_peer_bw");
        goto LABEL_225;
      }
      v191 = *((unsigned int *)a4 + 11);
      if ( (_DWORD)v75 != 1 )
      {
        if ( (unsigned int)v75 >= 3 )
        {
          v286 = (unsigned int *)(a4 + 84);
          v287 = *((_DWORD *)a4 + 11);
          v192 = (v75 - 1) | 1;
          v288 = (v75 - 1) & 0xFFFFFFFFFFFFFFFELL;
          do
          {
            v289 = *(v286 - 5);
            v291 = *v286;
            v286 += 10;
            v290 = v291;
            if ( v289 > (unsigned int)v191 )
              LODWORD(v191) = v289;
            if ( v290 > v287 )
              v287 = v290;
            v288 -= 2LL;
          }
          while ( v288 );
          if ( (unsigned int)v191 <= v287 )
            v191 = v287;
          else
            v191 = (unsigned int)v191;
          if ( v75 - 1 == ((v75 - 1) & 0xFFFFFFFFFFFFFFFELL) )
            goto LABEL_221;
        }
        else
        {
          v192 = 1;
        }
        v292 = &a4[20 * v192];
        v293 = v75 - v192;
        v294 = (unsigned int *)(v292 + 44);
        do
        {
          v296 = *v294;
          v294 += 5;
          v295 = v296;
          if ( v296 <= (unsigned int)v191 )
            v191 = (unsigned int)v191;
          else
            v191 = v295;
          --v293;
        }
        while ( v293 );
      }
LABEL_221:
      v297 = v374;
      if ( v374 )
      {
        if ( *((_DWORD *)v374 - 1) != -674947595 )
          __break(0x8228u);
        v297(v144, a4 + 20, v191);
      }
      goto LABEL_225;
    }
    if ( a4 )
    {
      v80 = *(_QWORD **)(*(_QWORD *)(a2 + 152) + 24LL);
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: NDP Indication, policy: %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "os_if_ndp_indication_handler",
        *((unsigned int *)a4 + 8));
      ndi_state = ucfg_nan_get_ndi_state();
      if ( ndi_state <= 3 )
      {
        v90 = ndi_state;
        if ( ndi_state != 1 )
        {
          v91 = "%s: Data request not allowed in current NDI state: %d";
          v92 = "os_if_ndp_indication_handler";
LABEL_148:
          result = qdf_trace_msg(0x48u, 2u, v91, v82, v83, v84, v85, v86, v87, v88, v89, v92, v90);
          goto LABEL_251;
        }
      }
      v179 = (const char *)os_if_ndi_get_if_name(a2);
      if ( v179 )
      {
        v180 = v179;
        v181 = strlen(v179);
        if ( v181 >= 0x11 )
        {
          v190 = "os_if_ndp_indication_handler";
LABEL_228:
          result = qdf_trace_msg(
                     0x48u,
                     2u,
                     "%s: ifname(%zu) too long",
                     v182,
                     v183,
                     v184,
                     v185,
                     v186,
                     v187,
                     v188,
                     v189,
                     v190,
                     v181);
          goto LABEL_251;
        }
        v277 = *((_DWORD *)a4 + 140);
        v278 = *((_DWORD *)a4 + 74);
        if ( a4[820] )
          v279 = 96;
        else
          v279 = 92;
        v280 = (v277 + 7) & 0xFFFC;
        if ( !v277 )
          v280 = 0;
        v281 = v278 == 0;
        v282 = (v278 + 7) & 0xFFFC;
        v283 = v280 + v279;
        if ( v281 )
          v282 = 0;
        v284 = v283 + v282;
        if ( a4[837] )
          v284 += 12;
        if ( *((_DWORD *)a4 + 211) )
          v284 += 8;
        if ( *((_DWORD *)a4 + 212) )
          v284 += 4;
        v285 = _cfg80211_alloc_event_skb(*v80, 0, 103, 197, 0, 26, v284, 2080);
        if ( v285 )
        {
          v22 = v285;
          LODWORD(v351) = 9;
          if ( !(unsigned int)nla_put(v285, 1, 4, &v351) && !(unsigned int)nla_put(v22, 6, (unsigned int)v181, v180) )
          {
            LODWORD(v351) = *((_DWORD *)a4 + 2);
            if ( !(unsigned int)nla_put(v22, 3, 4, &v351)
              && !(unsigned int)nla_put(v22, 13, 6, a4 + 18)
              && !(unsigned int)nla_put(v22, 5, 6, a4 + 12) )
            {
              LODWORD(v351) = *((_DWORD *)a4 + 6);
              if ( !(unsigned int)nla_put(v22, 10, 4, &v351) )
              {
                v349 = *((unsigned int *)a4 + 74);
                if ( !(_DWORD)v349 || !(unsigned int)nla_put(v22, 9, v349, a4 + 300) )
                {
                  if ( !*((_DWORD *)a4 + 9)
                    || (LODWORD(v351) = *((_DWORD *)a4 + 10), !(unsigned int)nla_put(v22, 8, 4, &v351)) )
                  {
                    if ( !*((_DWORD *)a4 + 140) )
                      goto LABEL_301;
                    LODWORD(v351) = *((_DWORD *)a4 + 139);
                    if ( !(unsigned int)nla_put(v22, 17, 4, &v351)
                      && !(unsigned int)nla_put(v22, 19, *((unsigned int *)a4 + 140), a4 + 564) )
                    {
                      qdf_trace_msg(
                        0x48u,
                        8u,
                        "%s: csid: %d, scid_len: %d",
                        v23,
                        v24,
                        v25,
                        v26,
                        v27,
                        v28,
                        v29,
                        v30,
                        "os_if_ndp_indication_handler",
                        *((unsigned int *)a4 + 139),
                        *((unsigned int *)a4 + 140));
                      ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(
                        51,
                        8,
                        a4 + 564,
                        *((unsigned int *)a4 + 140));
LABEL_301:
                      if ( (a4[820] != 1 || !(unsigned int)nla_put(v22, 27, 16, a4 + 821))
                        && (a4[837] != 1 || !(unsigned int)nla_put(v22, 31, 6, a4 + 838)) )
                      {
                        if ( !*((_DWORD *)a4 + 211)
                          || (LOBYTE(v351) = *((_DWORD *)a4 + 211), !(unsigned int)nla_put(v22, 32, 1, &v351)) )
                        {
                          if ( !*((_DWORD *)a4 + 212) || !(unsigned int)nla_put(v22, 33, 0, 0) )
                          {
                            os_if_cstats_log_ndp_indication_evt(a2, a4);
                            goto LABEL_272;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          v31 = "os_if_ndp_indication_handler";
          goto LABEL_245;
        }
        v36 = "%s: wlan_cfg80211_vendor_event_alloc failed";
      }
      else
      {
        v36 = "%s: ifname is null";
      }
    }
    else
    {
      v36 = "%s: Invalid NDP Indication";
    }
    v72 = "os_if_ndp_indication_handler";
LABEL_249:
    v303 = 2;
    goto LABEL_250;
  }
  if ( a3 == 13 )
  {
    v93 = *(_QWORD *)(a2 + 152);
    if ( v93 )
      v94 = *(_QWORD *)(v93 + 80);
    else
      v94 = 0;
    v130 = *(unsigned __int8 *)(a2 + 104);
    active_peers = ucfg_nan_get_active_peers(a2, a5, a6, a7, a8, a9, a10, a11, a12);
    v373 = 0;
    v374 = nullptr;
    v371 = 0;
    v372 = 0;
    v369 = 0;
    v370 = 0;
    v367 = 0;
    v368 = 0;
    v365 = 0;
    v366 = 0;
    v363 = nullptr;
    v364 = 0;
    v361 = nullptr;
    v362 = 0;
    v359 = nullptr;
    v360 = nullptr;
    v357 = nullptr;
    v358 = 0;
    v355 = 0;
    v356 = 0;
    v353 = 0;
    v354 = 0;
    v351 = 0;
    v352 = 0;
    if ( a4 )
    {
      v132 = active_peers;
      if ( !(unsigned int)ucfg_nan_get_callbacks(v94, &v351, a5, a6, a7, a8, a9, a10, a11, a12) )
      {
        v153 = *(_DWORD *)(a2 + 16);
        v154 = *(_BYTE *)(a2 + 104);
        v375 = 1572909;
        LOBYTE(v376) = v153;
        HIBYTE(v376) = v154;
        time_of_the_day_us = qdf_get_time_of_the_day_us();
        __isb(0xFu);
        v155 = _ReadStatusReg(CNTVCT_EL0);
        v156 = *((_WORD *)a4 + 3);
        StatusReg = v155;
        LOBYTE(v155) = *a4;
        v157 = *(_WORD *)(a4 + 1);
        v381 = v156;
        LOBYTE(v156) = a4[5];
        v379[0] = v155;
        *(_WORD *)&v379[1] = v157;
        v380 = v156;
        wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v375, 0x1Cu, v158, v159, v160, v161, v162, v163, v164, v165);
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: vdev_id: %d, peer_mac: %02x:%02x:%02x:**:**:%02x",
          v166,
          v167,
          v168,
          v169,
          v170,
          v171,
          v172,
          v173,
          "os_if_new_peer_ind_handler",
          v130,
          *a4,
          a4[1],
          a4[2],
          a4[5]);
        v174 = v361;
        v175 = *((unsigned __int16 *)a4 + 3);
        if ( *((_DWORD *)v361 - 1) != -1122627834 )
          __break(0x8228u);
        v176 = v174(v130, v175, a4, v132 == 0);
        if ( !v176 )
        {
          ucfg_nan_set_active_peers(a2, v132 + 1, v82, v83, v84, v85, v86, v87, v88, v89);
          ucfg_nan_cache_ndp_peer_mac_addr(v94, a4, v250, v251, v252, v253, v254, v255, v256, v257);
          result = qdf_trace_msg(
                     0x48u,
                     8u,
                     "%s: num_peers: %d",
                     v258,
                     v259,
                     v260,
                     v261,
                     v262,
                     v263,
                     v264,
                     v265,
                     "os_if_new_peer_ind_handler",
                     (unsigned int)(v132 + 1));
          goto LABEL_251;
        }
        v90 = v176;
        v91 = "%s: new peer handling at HDD failed %d";
        v92 = "os_if_new_peer_ind_handler";
        goto LABEL_148;
      }
      v36 = "%s: failed to get callbacks";
    }
    else
    {
      v36 = "%s: Invalid new NDP peer params";
    }
    v72 = "os_if_new_peer_ind_handler";
    goto LABEL_249;
  }
  if ( a3 != 14 )
  {
    if ( a3 != 15 )
      goto LABEL_251;
    v32 = *(_QWORD *)(a2 + 152);
    v376 = 0;
    v375 = 0;
    v33 = *(_QWORD **)(v32 + 24);
    if ( a4 )
    {
      if ( *((_DWORD *)a4 + 6) )
      {
        v34 = 0;
        v350 = a4 + 76;
        do
        {
          if ( v34 == 255 )
            goto LABEL_310;
          if ( !(unsigned int)ucfg_nan_get_peer_ndi_addr_by_id(a2, *(_DWORD *)&a4[4 * v34 + 108], &v375) )
          {
            v45 = *(_QWORD *)(a2 + 152);
            v46 = v45 ? *(_QWORD *)(v45 + 80) : 0LL;
            v47 = *((unsigned int *)a4 + 5);
            v48 = *(unsigned __int8 *)(a2 + 104);
            v373 = 0;
            v374 = nullptr;
            v371 = 0;
            v372 = 0;
            v369 = 0;
            v370 = 0;
            v367 = 0;
            v368 = 0;
            v365 = 0;
            v366 = 0;
            v363 = nullptr;
            v364 = 0;
            v361 = nullptr;
            v362 = 0;
            v359 = nullptr;
            v360 = nullptr;
            v357 = nullptr;
            v358 = 0;
            v355 = 0;
            v356 = 0;
            v353 = 0;
            v354 = 0;
            v351 = 0;
            v352 = 0;
            if ( (_DWORD)v47 )
            {
              if ( !(unsigned int)ucfg_nan_get_callbacks(v46, &v351, v37, v38, v39, v40, v41, v42, v43, v44) )
              {
                v57 = *((unsigned int *)a4 + 9);
                if ( (_DWORD)v47 != 1 )
                {
                  if ( (unsigned int)v47 < 3 )
                  {
                    v58 = 1;
                    goto LABEL_56;
                  }
                  v59 = v350;
                  v60 = *((_DWORD *)a4 + 9);
                  v58 = (v47 - 1) | 1;
                  v61 = (v47 - 1) & 0xFFFFFFFFFFFFFFFELL;
                  do
                  {
                    v62 = *((_DWORD *)v59 - 5);
                    v64 = *(_DWORD *)v59;
                    v59 += 40;
                    v63 = v64;
                    if ( v62 > (unsigned int)v57 )
                      LODWORD(v57) = v62;
                    if ( v63 > v60 )
                      v60 = v63;
                    v61 -= 2LL;
                  }
                  while ( v61 );
                  if ( (unsigned int)v57 <= v60 )
                    v57 = v60;
                  else
                    v57 = (unsigned int)v57;
                  if ( v47 - 1 != ((v47 - 1) & 0xFFFFFFFFFFFFFFFELL) )
                  {
LABEL_56:
                    v65 = (unsigned int *)&a4[20 * v58 + 36];
                    v66 = v47 - v58;
                    do
                    {
                      v68 = *v65;
                      v65 += 5;
                      v67 = v68;
                      if ( v68 <= (unsigned int)v57 )
                        v57 = (unsigned int)v57;
                      else
                        v57 = v67;
                      --v66;
                    }
                    while ( v66 );
                  }
                }
                v69 = (void (__fastcall *)(_QWORD, int *, __int64))v374;
                if ( v374 )
                {
                  if ( *((_DWORD *)v374 - 1) != -674947595 )
                    __break(0x8228u);
                  v69(v48, &v375, v57);
                }
                goto LABEL_35;
              }
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: Failed to get NAN callbacks",
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                "os_if_ndp_update_peer_bw");
            }
          }
LABEL_35:
          ++v34;
        }
        while ( v34 < *((unsigned int *)a4 + 6) );
      }
      v95 = (const char *)os_if_ndi_get_if_name(a2);
      if ( v95 )
      {
        v90 = (unsigned __int8)strlen(v95);
        if ( (unsigned int)v90 >= 0x11 )
        {
          v91 = "%s: ifname(%d) too long";
          v92 = "os_if_ndp_sch_update_ind_handler";
          goto LABEL_148;
        }
        v177 = *((_DWORD *)a4 + 6);
        if ( v177 )
          v178 = ((4 * v177 + 7) & 0xFFFFFFFC) + 24 * v177 + 36;
        else
          v178 = 36;
        v266 = _cfg80211_alloc_event_skb(*v33, 0, 103, 197, 0, 26, v178, 2080);
        if ( v266 )
        {
          v267 = v266;
          LODWORD(v351) = 12;
          if ( (unsigned int)nla_put(v266, 1, 4, &v351)
            || (unsigned int)nla_put(v267, 5, 6, a4 + 8)
            || (unsigned int)nla_put(v267, 11, (unsigned int)(4 * *((_DWORD *)a4 + 6)), a4 + 108)
            || (LODWORD(v351) = *((_DWORD *)a4 + 4), (unsigned int)nla_put(v267, 22, 4, &v351))
            || (LODWORD(v351) = *((_DWORD *)a4 + 5), (unsigned int)nla_put(v267, 24, 4, &v351))
            || (unsigned int)os_if_ndp_sch_update_pack_ch_info(v267, a4) )
          {
            qdf_trace_msg(
              0x48u,
              2u,
              "%s: nla_put api failed",
              v268,
              v269,
              v270,
              v271,
              v272,
              v273,
              v274,
              v275,
              "os_if_ndp_sch_update_ind_handler");
            v276 = v267;
LABEL_246:
            result = sk_skb_reason_drop(0, v276, 2);
            goto LABEL_251;
          }
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: Flags: %d, num_instance_id: %d",
            v268,
            v269,
            v270,
            v271,
            v272,
            v273,
            v274,
            v275,
            "os_if_ndp_sch_update_ind_handler",
            *((unsigned int *)a4 + 4),
            *((unsigned int *)a4 + 6));
          if ( *((_DWORD *)a4 + 6) )
          {
            v348 = 0;
            while ( v348 != 255 )
            {
              qdf_trace_msg(
                0x48u,
                8u,
                "%s: ndp_instance[%d]: %d",
                v340,
                v341,
                v342,
                v343,
                v344,
                v345,
                v346,
                v347,
                "os_if_ndp_sch_update_ind_handler",
                (unsigned int)v348,
                *(unsigned int *)&a4[4 * v348 + 108]);
              if ( ++v348 >= (unsigned __int64)*((unsigned int *)a4 + 6) )
                goto LABEL_292;
            }
LABEL_310:
            __break(0x5512u);
          }
LABEL_292:
          v330 = v267;
LABEL_273:
          result = _cfg80211_send_event_skb(v330, 2080);
          goto LABEL_251;
        }
        v36 = "%s: wlan_cfg80211_vendor_event_alloc failed";
      }
      else
      {
        v36 = "%s: ifname is null";
      }
    }
    else
    {
      v36 = "%s: Invalid sch update params";
    }
    v72 = "os_if_ndp_sch_update_ind_handler";
    goto LABEL_249;
  }
  v77 = *(_QWORD *)(a2 + 152);
  v373 = 0;
  v374 = nullptr;
  v371 = 0;
  v372 = 0;
  v369 = 0;
  v370 = 0;
  v367 = 0;
  v368 = 0;
  v365 = 0;
  v366 = 0;
  v363 = nullptr;
  v364 = 0;
  v361 = nullptr;
  v362 = 0;
  v359 = nullptr;
  v360 = nullptr;
  v357 = nullptr;
  v358 = 0;
  v355 = 0;
  v356 = 0;
  v353 = 0;
  v354 = 0;
  v351 = 0;
  v352 = 0;
  if ( v77 )
    v78 = *(_QWORD *)(v77 + 80);
  else
    v78 = 0;
  v98 = *(unsigned __int8 *)(a2 + 104);
  v99 = ucfg_nan_get_active_peers(a2, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( (unsigned int)ucfg_nan_get_callbacks(v78, &v351, v100, v101, v102, v103, v104, v105, v106, v107) )
  {
    v36 = "%s: failed to get callbacks";
LABEL_105:
    v72 = "os_if_peer_departed_ind_handler";
    goto LABEL_249;
  }
  if ( !a4 )
  {
    v36 = "%s: Invalid new NDP peer params";
    goto LABEL_105;
  }
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: vdev_id: %d, peer_mac: %02x:%02x:%02x:**:**:%02x",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "os_if_peer_departed_ind_handler",
    v98,
    *a4,
    a4[1],
    a4[2],
    a4[5]);
  v108 = v99 - 1;
  ucfg_nan_set_active_peers(a2, v108, v109, v110, v111, v112, v113, v114, v115, v116);
  v117 = v363;
  v118 = *((unsigned __int16 *)a4 + 3);
  if ( *((_DWORD *)v363 - 1) != -1256243996 )
    __break(0x8228u);
  result = v117(v98, v118, a4, v108 == 0);
  if ( !v108 )
  {
    if ( a2 )
    {
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a2, 0xFu);
      if ( comp_private_obj )
      {
        v128 = osif_request_get(*(_QWORD *)(comp_private_obj + 48));
        if ( v128 )
        {
          v129 = v128;
          osif_request_complete(v128);
          result = osif_request_put(v129);
          goto LABEL_251;
        }
        v36 = "%s: Obsolete request";
        v72 = "os_if_ndp_end_all_handler";
        v303 = 8;
LABEL_250:
        result = qdf_trace_msg(0x48u, v303, v36, a5, a6, a7, a8, a9, a10, a11, a12, v72);
        goto LABEL_251;
      }
    }
    else
    {
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: vdev is null",
        v119,
        v120,
        v121,
        v122,
        v123,
        v124,
        v125,
        v126,
        "nan_get_vdev_priv_obj");
    }
    v36 = "%s: vdev_nan_obj is NULL";
    v72 = "os_if_ndp_end_all_handler";
    goto LABEL_249;
  }
LABEL_251:
  _ReadStatusReg(SP_EL0);
  return result;
}
