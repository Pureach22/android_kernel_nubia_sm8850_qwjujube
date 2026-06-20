__int64 __fastcall lim_fill_pe_session(__int64 a1, __int64 a2, __int64 a3, int a4, _DWORD *a5)
{
  unsigned __int64 v5; // x22
  __int64 v6; // x26
  unsigned __int8 *v12; // x28
  double updated; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w24
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x4
  __int64 v39; // x5
  __int64 v40; // x6
  __int64 v41; // x7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w25
  _BYTE *v51; // x8
  char _11h_power_constraint; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x8
  _BYTE *v62; // x22
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x8
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  _BYTE *v80; // x8
  __int64 v81; // x0
  unsigned __int8 v82; // w1
  int v83; // w8
  _BYTE *v84; // x27
  __int64 v85; // x22
  unsigned int v86; // w24
  _QWORD *vdev_by_id_from_pdev; // x0
  __int64 v88; // x25
  int *cmpt_obj; // x0
  unsigned int *v90; // x8
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  int v99; // w26
  unsigned int v100; // w9
  _BOOL4 v102; // w10
  bool v103; // zf
  int v104; // w8
  _BOOL4 v106; // w10
  bool v107; // zf
  char v108; // w9
  _QWORD *v109; // x0
  __int64 v110; // x25
  unsigned int vdev_wifi_std; // w0
  unsigned int *v112; // x8
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  unsigned int v121; // w26
  int v122; // w8
  unsigned __int8 v123; // w26
  int v124; // w8
  int v125; // w25
  const char *v126; // x2
  const char *v127; // x3
  __int64 v128; // x4
  __int64 v129; // x0
  __int64 v130; // x26
  __int64 v131; // x0
  __int64 v132; // x0
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  int v141; // w26
  int v142; // w26
  bool is_24ghz_ch_freq; // w0
  int v144; // w8
  bool v145; // zf
  int v146; // w9
  char v147; // w8
  char v148; // w8
  const char *v149; // x2
  const char *v150; // x3
  __int64 v151; // x22
  int param; // w0
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  char v161; // w4
  int cb_mode; // w22
  double v163; // d0
  double v164; // d1
  double v165; // d2
  double v166; // d3
  double v167; // d4
  double v168; // d5
  double v169; // d6
  double v170; // d7
  _DWORD *v171; // x27
  double v172; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  unsigned int v180; // w25
  bool v181; // w24
  __int64 v182; // x8
  char v183; // w9
  unsigned int v184; // w8
  __int64 v185; // x10
  int v186; // w9
  unsigned int v187; // w8
  bool v188; // w0
  double v189; // d0
  double v190; // d1
  double v191; // d2
  double v192; // d3
  double v193; // d4
  double v194; // d5
  double v195; // d6
  double v196; // d7
  __int64 v197; // x8
  unsigned int v198; // w9
  _BYTE *v199; // x26
  __int64 v200; // x0
  double v201; // d0
  double v202; // d1
  double v203; // d2
  double v204; // d3
  double v205; // d4
  double v206; // d5
  double v207; // d6
  double v208; // d7
  unsigned int v209; // w25
  __int64 v210; // x24
  int v211; // w23
  int v212; // w27
  unsigned int v213; // w23
  int v214; // w22
  unsigned __int8 *v215; // x8
  _BYTE *v216; // x13
  unsigned __int16 *v217; // x22
  unsigned __int8 v218; // w14
  int v219; // w10
  unsigned int v220; // w9
  unsigned int v221; // w25
  int v222; // w8
  unsigned int v223; // w24
  __int16 v224; // w8
  double v225; // d0
  double v226; // d1
  double v227; // d2
  double v228; // d3
  double v229; // d4
  double v230; // d5
  double v231; // d6
  double v232; // d7
  __int64 v233; // x22
  _BYTE *v234; // x26
  unsigned int v235; // w0
  bool v236; // w0
  __int64 v237; // x9
  __int64 v238; // x8
  __int64 v239; // x9
  unsigned __int8 v240; // w8
  unsigned __int16 ielen_from_bss_description; // w23
  unsigned int v242; // w8
  _BOOL4 v243; // w9
  int v244; // w8
  int v245; // w8
  int v246; // w9
  int v247; // w10
  unsigned int v248; // w0
  bool v249; // w0
  unsigned int v250; // w8
  bool v251; // w0
  __int64 v252; // x8
  double v253; // d0
  double v254; // d1
  double v255; // d2
  double v256; // d3
  double v257; // d4
  double v258; // d5
  double v259; // d6
  double v260; // d7
  unsigned __int8 v261; // w0
  unsigned int v262; // w8
  char v263; // w0
  double v264; // d0
  double v265; // d1
  double v266; // d2
  double v267; // d3
  double v268; // d4
  double v269; // d5
  double v270; // d6
  double v271; // d7
  unsigned __int8 *v272; // x25
  double v273; // d0
  double v274; // d1
  double v275; // d2
  double v276; // d3
  double v277; // d4
  double v278; // d5
  double v279; // d6
  double v280; // d7
  double v281; // d0
  double v282; // d1
  double v283; // d2
  double v284; // d3
  double v285; // d4
  double v286; // d5
  double v287; // d6
  double v288; // d7
  double v289; // d0
  double v290; // d1
  double v291; // d2
  double v292; // d3
  double v293; // d4
  double v294; // d5
  double v295; // d6
  double v296; // d7
  int v297; // w8
  double v298; // d0
  double v299; // d1
  double v300; // d2
  double v301; // d3
  double v302; // d4
  double v303; // d5
  double v304; // d6
  double v305; // d7
  int v306; // w8
  __int64 ext_hdl; // x0
  double v308; // d0
  double v309; // d1
  double v310; // d2
  double v311; // d3
  double v312; // d4
  double v313; // d5
  double v314; // d6
  double v315; // d7
  __int64 v316; // x5
  unsigned int v317; // w10
  int v318; // w13
  int v319; // w16
  unsigned int v320; // w0
  int v321; // w8
  int v322; // w14
  int v323; // w12
  int v324; // w3
  unsigned int v325; // w13
  unsigned int v326; // w14
  unsigned int v327; // w15
  unsigned int v328; // w16
  int v329; // w0
  unsigned int v330; // w3
  int v331; // w15
  int v332; // w16
  int v333; // w14
  unsigned int v334; // w15
  unsigned int v335; // w17
  int v336; // w4
  int v337; // w0
  unsigned int v338; // w3
  int v339; // w4
  unsigned int v340; // w7
  int v341; // w2
  unsigned __int16 v342; // w11
  unsigned int v343; // w17
  unsigned int v344; // w3
  unsigned int v345; // w16
  unsigned int v346; // w17
  unsigned int v347; // w0
  int v348; // w2
  int v349; // w4
  unsigned int v350; // w22
  int v351; // w15
  int v352; // w16
  unsigned int v353; // w23
  int v354; // w2
  unsigned int v355; // w0
  unsigned int v356; // w4
  int v357; // w7
  unsigned int v358; // w23
  int v359; // w17
  unsigned int v360; // w0
  unsigned int v361; // w16
  unsigned int v362; // w30
  int v363; // w4
  unsigned int v364; // w22
  unsigned int v365; // w9
  unsigned int v366; // w1
  unsigned int v367; // w25
  double v368; // d0
  double v369; // d1
  double v370; // d2
  double v371; // d3
  double v372; // d4
  double v373; // d5
  double v374; // d6
  double v375; // d7
  char v376; // w1
  double v377; // d0
  double v378; // d1
  double v379; // d2
  double v380; // d3
  double v381; // d4
  double v382; // d5
  double v383; // d6
  double v384; // d7
  double v385; // d0
  double v386; // d1
  double v387; // d2
  double v388; // d3
  double v389; // d4
  double v390; // d5
  double v391; // d6
  double v392; // d7
  __int64 v393; // x0
  __int64 v394; // x24
  _BYTE *v395; // x0
  _BYTE *v396; // x23
  int v397; // w22
  __int64 v398; // x0
  double v399; // d0
  double v400; // d1
  double v401; // d2
  double v402; // d3
  double v403; // d4
  double v404; // d5
  double v405; // d6
  double v406; // d7
  __int64 v407; // x4
  int v408; // w8
  char v409; // w9
  unsigned int v410; // w8
  unsigned __int8 v411; // w8
  __int64 v412; // x0
  unsigned int v413; // w1
  __int64 psoc_ext_obj_fl; // x0
  double v415; // d0
  double v416; // d1
  double v417; // d2
  double v418; // d3
  double v419; // d4
  double v420; // d5
  double v421; // d6
  double v422; // d7
  __int64 v423; // x24
  __int64 v424; // x24
  unsigned __int8 v425; // w25
  char is_ese_connection; // w0
  int v427; // w24
  int v428; // w25
  double v429; // d0
  double v430; // d1
  double v431; // d2
  double v432; // d3
  double v433; // d4
  double v434; // d5
  double v435; // d6
  double v436; // d7
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  int v438; // w8
  __int64 v439; // x9
  char v440; // w8
  double v441; // d0
  double v442; // d1
  double v443; // d2
  double v444; // d3
  double v445; // d4
  double v446; // d5
  double v447; // d6
  double v448; // d7
  char v449; // w22
  double v450; // d0
  double v451; // d1
  double v452; // d2
  double v453; // d3
  double v454; // d4
  double v455; // d5
  double v456; // d6
  double v457; // d7
  int v458; // w4
  unsigned int v459; // w8
  double v460; // d0
  double v461; // d1
  double v462; // d2
  double v463; // d3
  double v464; // d4
  double v465; // d5
  double v466; // d6
  double v467; // d7
  char v468; // w0
  int v469; // w9
  unsigned __int8 v470; // w10
  unsigned int v471; // w8
  __int16 v472; // w0
  double v473; // d0
  double v474; // d1
  double v475; // d2
  double v476; // d3
  double v477; // d4
  double v478; // d5
  double v479; // d6
  double v480; // d7
  char v481; // w9
  unsigned __int8 v482; // w8
  int v483; // w9
  unsigned __int8 v484; // w8
  __int64 v485; // x0
  __int64 v486; // x0
  __int64 v487; // x23
  unsigned int v488; // w0
  unsigned int ap_capability; // w0
  double v490; // d0
  double v491; // d1
  double v492; // d2
  double v493; // d3
  double v494; // d4
  double v495; // d5
  double v496; // d6
  double v497; // d7
  int v498; // w8
  __int64 v499; // x0
  double v500; // d0
  double v501; // d1
  double v502; // d2
  double v503; // d3
  double v504; // d4
  double v505; // d5
  double v506; // d6
  double v507; // d7
  double v508; // d0
  double v509; // d1
  double v510; // d2
  double v511; // d3
  double v512; // d4
  double v513; // d5
  double v514; // d6
  double v515; // d7
  unsigned int v516; // w8
  int v517; // w8
  __int64 v518; // x0
  double v519; // d0
  double v520; // d1
  double v521; // d2
  double v522; // d3
  double v523; // d4
  double v524; // d5
  double v525; // d6
  double v526; // d7
  const char *v527; // x2
  __int64 v528; // x10
  double v529; // d0
  double v530; // d1
  double v531; // d2
  double v532; // d3
  double v533; // d4
  double v534; // d5
  double v535; // d6
  double v536; // d7
  double v537; // d0
  double v538; // d1
  double v539; // d2
  double v540; // d3
  double v541; // d4
  double v542; // d5
  double v543; // d6
  double v544; // d7
  double v545; // d0
  double v546; // d1
  double v547; // d2
  double v548; // d3
  double v549; // d4
  double v550; // d5
  double v551; // d6
  double v552; // d7
  unsigned int v553; // w3
  double v554; // d0
  double v555; // d1
  double v556; // d2
  double v557; // d3
  double v558; // d4
  double v559; // d5
  double v560; // d6
  double v561; // d7
  int v562; // w1
  __int64 v563; // x0
  double v564; // d0
  double v565; // d1
  double v566; // d2
  double v567; // d3
  double v568; // d4
  double v569; // d5
  double v570; // d6
  double v571; // d7
  unsigned __int8 channel_reg_power_for_freq; // w0
  unsigned __int8 v573; // w8
  int v574; // w10
  unsigned __int8 max_tx_power; // w0
  unsigned int v576; // w22
  int v577; // w8
  unsigned int v578; // w22
  int v579; // w8
  int v580; // w9
  __int16 v581; // w2
  __int64 v582; // x0
  char is_mbssid_enabled; // w0
  int v584; // w8
  double v585; // d0
  double v586; // d1
  double v587; // d2
  double v588; // d3
  double v589; // d4
  double v590; // d5
  double v591; // d6
  double v592; // d7
  char v593; // w21
  char cfg_max_tx_power; // w0
  int v595; // w8
  double v596; // d0
  double v597; // d1
  double v598; // d2
  double v599; // d3
  double v600; // d4
  double v601; // d5
  double v602; // d6
  double v603; // d7
  const char *v604; // x2
  unsigned __int8 v605; // w8
  bool is_5ghz_ch_freq; // w0
  int v608; // [xsp+1Ch] [xbp-1A4h]
  __int64 v609; // [xsp+20h] [xbp-1A0h]
  int v610; // [xsp+2Ch] [xbp-194h]
  unsigned int v611; // [xsp+30h] [xbp-190h]
  __int64 v612; // [xsp+38h] [xbp-188h]
  _DWORD *v613; // [xsp+40h] [xbp-180h]
  _QWORD v614[4]; // [xsp+50h] [xbp-170h] BYREF
  int v615; // [xsp+74h] [xbp-14Ch] BYREF
  __int64 v616; // [xsp+78h] [xbp-148h] BYREF
  __int64 v617; // [xsp+80h] [xbp-140h]
  __int64 v618; // [xsp+88h] [xbp-138h]
  __int64 v619; // [xsp+90h] [xbp-130h]
  unsigned __int8 v620[4]; // [xsp+98h] [xbp-128h] BYREF
  char v621[4]; // [xsp+9Ch] [xbp-124h] BYREF
  char v622[4]; // [xsp+A0h] [xbp-120h] BYREF
  char v623[4]; // [xsp+A4h] [xbp-11Ch] BYREF
  __int64 v624; // [xsp+A8h] [xbp-118h] BYREF
  char v625[4]; // [xsp+B4h] [xbp-10Ch] BYREF
  unsigned __int8 *dest[33]; // [xsp+B8h] [xbp-108h] BYREF

  dest[31] = *(unsigned __int8 **)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned __int8 *)(a2 + 10);
  v6 = *(_QWORD *)(a1 + 8);
  v624 = 0;
  v623[0] = 0;
  v622[0] = 0;
  v621[0] = 0;
  v620[0] = 0;
  v618 = 0;
  v619 = 0;
  v616 = 0;
  v617 = 0;
  if ( v5 >= 7 )
    __break(0x5512u);
  v615 = 0;
  v12 = (unsigned __int8 *)(a2 + 7024);
  memset(v614, 0, sizeof(v614));
  updated = lim_update_rrm_capability();
  v21 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21560), *(_DWORD *)(a3 + 28), updated, v14, v15, v16, v17, v18, v19, v20);
  WORD2(dest[0]) = 0;
  LODWORD(dest[0]) = 0;
  qdf_mem_copy(dest, (const void *)(a2 + 24), 6u);
  if ( wlan_crypto_get_pmksa(*(_QWORD *)(a2 + 16), (__int64)dest, v22, v23, v24, v25, v26, v27, v28, v29) )
  {
    v38 = LOBYTE(dest[0]);
    v39 = BYTE1(dest[0]);
    v40 = BYTE2(dest[0]);
    v41 = BYTE5(dest[0]);
    v12[2984] = 1;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: PMKSA Found for BSSID=%02x:%02x:%02x:**:**:%02x",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "lim_update_sae_config",
      v38,
      v39,
      v40,
      v41);
  }
  if ( (wlan_crypto_get_param(*(_QWORD *)(a2 + 16), 7u) & 0x8000400) != 0
    && *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2360LL) == 1 )
  {
    wlan_mlme_set_sae_single_pmk_bss_cap(
      *(_QWORD *)(a1 + 21552),
      *(unsigned __int8 *)(a2 + 10),
      *(_DWORD *)(*(_QWORD *)(a2 + 112) + 4460LL) != 0);
  }
  lim_set_bcn_probe_filter(a1, a2, v21);
  v12[241] = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1282LL);
  *(_WORD *)(a2 + 7158) = *(_WORD *)(a3 + 16);
  *(_DWORD *)(a2 + 284) = *(_DWORD *)(a3 + 28);
  if ( !(unsigned int)wlan_get_parsed_bss_description_ies(a1, a3, &v624) )
  {
    qdf_mem_set((void *)(a2 + 1628), 0x14u, 0);
    v51 = (_BYTE *)v624;
    v611 = v5;
    if ( *(_BYTE *)(v624 + 3426) )
    {
      qdf_mem_copy((void *)(a2 + 1628), (const void *)(v624 + 3426), 0x14u);
      v51 = (_BYTE *)v624;
    }
    _11h_power_constraint = wlan_get_11h_power_constraint(a1, v51 + 830);
    v61 = *(_QWORD *)(a1 + 8);
    v62 = (_BYTE *)v624;
    LOBYTE(dest[0]) = 0;
    *(_BYTE *)(v61 + 4411) = _11h_power_constraint;
    v625[0] = 0;
    if ( v62 )
    {
      wlan_twt_cfg_get_support_requestor(*(_QWORD *)(a1 + 21552), v625);
      if ( v625[0] == 1 && ((v71 = *(_QWORD *)(v62 + 2253), v62[5192]) || (v71 & 4) != 0) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: TWT is supported, hence disable UAPSD; twt req supp: %d,twt respon supp: %d, QCN_IE: %d",
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          "lim_enable_twt",
          (*(_DWORD *)(*(_QWORD *)(a1 + 8) + 1289LL) >> 1) & 1,
          ((unsigned int)v71 >> 2) & 1);
        LOBYTE(v62) = 1;
      }
      else
      {
        wlan_twt_cfg_get_req_support_for_ht_vht(*(_QWORD *)(a1 + 21552), dest);
        if ( LOBYTE(dest[0]) == 1 && v62[1390] && (*((_WORD *)v62 + 700) & 0x4000) != 0 )
        {
          LOBYTE(v62) = 1;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: TWT is supported for 11n, twt_req_ht_vht %d, ext_cap %d, twt_responder support %d",
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            "lim_enable_twt",
            1);
        }
        else
        {
          LOBYTE(v62) = 0;
        }
      }
    }
    else
    {
      qdf_trace_msg(0x35u, 8u, "%s: ie is null", v53, v54, v55, v56, v57, v58, v59, v60, "lim_enable_twt");
    }
    v80 = (_BYTE *)v624;
    v12[3023] = (unsigned __int8)v62;
    if ( v80 )
    {
      v81 = *(_QWORD *)(a2 + 16);
      if ( *(_DWORD *)(v81 + 16) == 2 )
      {
        if ( (v80[2253] & 4) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: set P2P CLI in WFD R2 mode for id %d",
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            "lim_set_wfd_mode_for_p2p_cli",
            *(unsigned __int8 *)(a2 + 10));
          v81 = *(_QWORD *)(a2 + 16);
          v82 = 1;
        }
        else
        {
          v82 = -1;
        }
        wlan_vdev_set_wfd_mode(v81, v82);
      }
    }
    else
    {
      qdf_trace_msg(0x35u, 8u, "%s: ie is null", v72, v73, v74, v75, v76, v77, v78, v79, "lim_set_wfd_mode_for_p2p_cli");
    }
    v83 = *(_DWORD *)(a2 + 7036);
    v84 = (_BYTE *)v624;
    v85 = *(_QWORD *)(a2 + 112);
    v612 = v6;
    v613 = a5;
    v86 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5748LL);
    if ( (v83 | 2) == 2 )
    {
      vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(a1 + 21560), *(_BYTE *)(a2 + 10), 0x43u);
      if ( vdev_by_id_from_pdev )
      {
        v88 = (__int64)vdev_by_id_from_pdev;
        cmpt_obj = (int *)wlan_vdev_mlme_get_cmpt_obj(
                            (__int64)vdev_by_id_from_pdev,
                            v72,
                            v73,
                            v74,
                            v75,
                            v76,
                            v77,
                            v78,
                            v79);
        if ( cmpt_obj )
        {
          v99 = *cmpt_obj;
          wlan_objmgr_vdev_release_ref(v88, 0x43u, v90, v91, v92, v93, v94, v95, v96, v97, v98);
          if ( v99 )
          {
            v100 = v86 & 0xFFFFFFFE;
            v102 = (v86 & 0xFFFFFFFD) == 5 || v100 == 8;
            v103 = v100 == 10 || v100 == 12;
            v104 = v103;
            if ( v103 )
              v102 = 1;
            if ( !v86 )
              v102 = 1;
            if ( v102 && v99 == 1 )
            {
              v86 = 5;
            }
            else
            {
              v106 = v100 == 8 || v100 == 10;
              if ( v86 )
                v107 = v100 == 12;
              else
                v107 = 1;
              if ( v107 )
                v106 = 1;
              v108 = v107;
              if ( v106 && v99 == 2 )
              {
                v86 = 8;
              }
              else
              {
                if ( !v86 )
                  v104 = 1;
                if ( v104 == 1 && v99 == 3 )
                {
                  v86 = 10;
                }
                else if ( ((unsigned __int8)v108 & (v99 == 4)) != 0 )
                {
                  v86 = 12;
                }
              }
            }
          }
        }
        else
        {
          wlan_objmgr_vdev_release_ref(v88, 0x43u, v90, v91, v92, v93, v94, v95, v96, v97, v98);
        }
      }
      v83 = *(_DWORD *)(a2 + 7036);
    }
    if ( (v83 | 2) == 2 )
    {
      v109 = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(a1 + 21560), *(_BYTE *)(a2 + 10), 0x43u);
      if ( v109 )
      {
        v110 = (__int64)v109;
        vdev_wifi_std = mlme_get_vdev_wifi_std((__int64)v109, v72, v73, v74, v75, v76, v77, v78, v79);
        if ( vdev_wifi_std > 3 )
        {
          v121 = 12;
        }
        else
        {
          v112 = dword_A2FA38;
          v121 = dword_A2FA38[vdev_wifi_std];
        }
        wlan_objmgr_vdev_release_ref(v110, 0x43u, v112, v113, v114, v115, v116, v117, v118, v119, v120);
        if ( v121 < v86 )
          v86 = v121;
      }
    }
    v122 = *(_DWORD *)(v85 + 4384);
    v123 = *(_BYTE *)(a2 + 10);
    if ( v122 )
    {
      if ( v122 == 1 )
      {
        v125 = 3;
        if ( v86 > 0xD )
          goto LABEL_92;
        goto LABEL_116;
      }
      if ( v122 == 2 )
      {
        v124 = 4;
      }
      else if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v85 + 4392)) )
      {
        v124 = 4;
      }
      else
      {
        v124 = 2;
      }
    }
    else
    {
      v124 = 2;
    }
    if ( v84[1256] )
      v124 = 5;
    if ( v84[1408] && *((__int16 *)v84 + 707) != -1 && *((__int16 *)v84 + 709) != -1
      || v84[4876] && *((__int16 *)v84 + 2441) != -1 && *((__int16 *)v84 + 2443) != -1 )
    {
      v124 = 8;
    }
    if ( v84[2252] )
      v125 = 10;
    else
      v125 = v124;
    if ( !v84[2496] )
      goto LABEL_116;
    v129 = wlan_scan_entry_by_bssid_and_security(*(_QWORD *)(a1 + 21560), (unsigned __int8 *)(v85 + 4366), v123);
    if ( v129 )
    {
      v130 = v129;
      v131 = *(_QWORD *)(v129 + 1192);
      if ( v131 )
        _qdf_mem_free(v131);
      v132 = *(_QWORD *)(v130 + 1712);
      if ( v132 )
        _qdf_mem_free(v132);
      _qdf_mem_free(v130);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Downgrade to 11ax mode due to AP security validation failure",
        v133,
        v134,
        v135,
        v136,
        v137,
        v138,
        v139,
        v140,
        "lim_get_bss_11be_mode_allowed");
      goto LABEL_116;
    }
    wlan_get_ielen_from_bss_description(v85 + 4364);
    if ( v86 > 0xD )
    {
LABEL_92:
      v126 = "%s: Invalid self dot11mode %d not supported";
      v127 = "lim_get_intersected_dot11_mode_sta_ap";
      v128 = v86;
LABEL_222:
      qdf_trace_msg(0x35u, 2u, v126, v72, v73, v74, v75, v76, v77, v78, v79, v127, v128);
      v50 = 16;
      goto LABEL_514;
    }
LABEL_116:
    switch ( v86 )
    {
      case 0u:
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: vdev id %d opmode %d self dot11mode %d bss_dot11 mode %d intersected %d bss phy mode %d",
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          "lim_fill_dot11_mode",
          *(unsigned __int8 *)(a2 + 10),
          *(unsigned int *)(a2 + 7036),
          0,
          (unsigned int)v125,
          v125,
          a4);
        *(_BYTE *)(a2 + 154) = v125;
        if ( ((1 << v125) & 0x520) == 0 )
          goto LABEL_234;
        goto LABEL_228;
      case 1u:
        if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v85 + 4392)) && !wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(v85 + 4392)) )
        {
          v128 = *(unsigned int *)(v85 + 4392);
          v126 = "%s: self Dot11mode is 11ABG, BSS freq %d not 2.4 or 5 GHz";
          v127 = "lim_handle_11abg_dot11_mode";
          goto LABEL_222;
        }
        v141 = v125;
        if ( ((1 << v125) & 0x1C) != 0 )
          goto LABEL_206;
        if ( ((1 << v125) & 0x520) != 0 )
        {
          is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v85 + 4392));
          v144 = 2;
          v145 = !is_24ghz_ch_freq;
          v146 = 4;
          goto LABEL_146;
        }
        v126 = "%s: Invalid bss dot11mode %d passed";
        v127 = "lim_handle_11abg_dot11_mode";
        goto LABEL_221;
      case 2u:
        if ( !wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(v85 + 4392)) )
        {
          v128 = *(unsigned int *)(v85 + 4392);
          v126 = "%s: self Dot11mode is 11A and bss freq %d not 5ghz";
          v127 = "lim_handle_11a_dot11_mode";
          goto LABEL_222;
        }
        if ( ((1 << v125) & 0x524) != 0 )
        {
          v141 = 2;
          goto LABEL_206;
        }
        if ( ((1 << v125) & 0x18) != 0 )
          v126 = "%s: Self dot11mode 11A, bss dot11mode %d not compatible";
        else
          v126 = "%s: Invalid bss dot11mode %d passed";
        v127 = "lim_handle_11a_dot11_mode";
        goto LABEL_221;
      case 3u:
        if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v85 + 4392)) )
        {
          v128 = *(unsigned int *)(v85 + 4392);
          v126 = "%s: self Dot11mode is 11B and bss freq %d not 2.4ghz";
          v127 = "lim_handle_11b_dot11_mode";
          goto LABEL_222;
        }
        if ( ((1 << v125) & 0x538) != 0 )
          goto LABEL_138;
        if ( v125 == 2 )
        {
          v126 = "%s: Self dot11mode 11B, bss dot11mode %d not compatible";
          v127 = "lim_handle_11b_dot11_mode";
          goto LABEL_215;
        }
        v126 = "%s: Invalid bss dot11mode %d passed";
        v127 = "lim_handle_11b_dot11_mode";
        goto LABEL_221;
      case 4u:
        if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v85 + 4392)) )
        {
          v128 = *(unsigned int *)(v85 + 4392);
          v126 = "%s: self Dot11mode is 11G and bss freq %d not 2.4ghz";
          v127 = "lim_handle_11g_dot11_mode";
          goto LABEL_222;
        }
        if ( ((1 << v125) & 0x530) != 0 )
          goto LABEL_156;
        if ( v125 == 2 )
        {
          v126 = "%s: Self dot11mode 11G, bss dot11mode %d not compatible";
          v127 = "lim_handle_11g_dot11_mode";
LABEL_215:
          v128 = 2;
          goto LABEL_222;
        }
        if ( v125 != 3 )
        {
          v126 = "%s: Invalid bss dot11mode %d passed";
          v127 = "lim_handle_11g_dot11_mode";
          goto LABEL_221;
        }
LABEL_138:
        v141 = 3;
        goto LABEL_206;
      case 5u:
        if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v85 + 4392)) )
        {
          v128 = *(unsigned int *)(v85 + 4392);
          v126 = "%s: self Dot11mode is 11N and bss freq %d is 6ghz";
          v127 = "lim_handle_11n_dot11_mode";
          goto LABEL_222;
        }
        if ( v125 <= 4 )
        {
          v141 = v125;
          goto LABEL_206;
        }
        v142 = v125;
        if ( v125 != 5 )
          goto LABEL_225;
        goto LABEL_227;
      case 6u:
        if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v85 + 4392)) )
        {
          v128 = *(unsigned int *)(v85 + 4392);
          v126 = "%s: self Dot11mode is 11G ONLY and bss freq %d not 2.4ghz";
          v127 = "lim_handle_11g_only_dot11_mode";
          goto LABEL_222;
        }
        if ( ((1 << v125) & 0x530) != 0 )
        {
LABEL_156:
          v141 = 4;
          goto LABEL_206;
        }
        if ( ((1 << v125) & 0xC) != 0 )
          v126 = "%s: Self dot11mode 11G only, bss dot11mode %d not compatible";
        else
          v126 = "%s: Invalid bss dot11mode %d passed";
        v127 = "lim_handle_11g_only_dot11_mode";
        goto LABEL_221;
      case 7u:
        if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v85 + 4392)) )
        {
          v128 = *(unsigned int *)(v85 + 4392);
          v126 = "%s: self Dot11mode is 11N ONLY and bss freq %d is 6ghz";
          v127 = "lim_handle_11n_only_dot11_mode";
          goto LABEL_222;
        }
        if ( v125 <= 4 )
        {
          v126 = "%s: Self dot11mode 11N only, bss dot11mode %d not compatible";
          v127 = "lim_handle_11n_only_dot11_mode";
          goto LABEL_221;
        }
        v142 = v125;
        if ( v125 == 5 )
          goto LABEL_227;
        if ( v84[1256] )
          goto LABEL_226;
        v149 = "%s: Self dot11mode is 11N ONLY peer is not HT capable";
        v150 = "lim_handle_11n_only_dot11_mode";
        goto LABEL_202;
      case 8u:
        if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v85 + 4392)) )
        {
          v128 = *(unsigned int *)(v85 + 4392);
          v126 = "%s: self Dot11mode is 11AC and bss freq %d is 6ghz";
          v127 = "lim_handle_11ac_dot11_mode";
          goto LABEL_222;
        }
        if ( v84[1408] && *((__int16 *)v84 + 707) != -1 && *((__int16 *)v84 + 709) != -1 )
          goto LABEL_183;
        v148 = v84[4876];
        if ( v148 )
        {
          if ( *((__int16 *)v84 + 2441) == -1 || *((__int16 *)v84 + 2443) == -1 )
            v148 = 0;
          else
LABEL_183:
            v148 = 1;
        }
        if ( v125 <= 4 )
        {
          v141 = v125;
LABEL_206:
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d opmode %d self dot11mode %d bss_dot11 mode %d intersected %d bss phy mode %d",
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            "lim_fill_dot11_mode",
            *(unsigned __int8 *)(a2 + 10),
            *(unsigned int *)(a2 + 7036),
            v86,
            (unsigned int)v125,
            v141,
            a4);
          *(_BYTE *)(a2 + 154) = v141;
          goto LABEL_234;
        }
        v142 = v125;
        if ( v125 != 5 )
        {
          if ( v125 == 10 && (v148 & 1) == 0 )
          {
LABEL_225:
            if ( !v84[1256] )
            {
              is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(v85 + 4392));
              v144 = 4;
              v145 = !is_5ghz_ch_freq;
              v146 = 2;
LABEL_146:
              if ( v145 )
                v141 = v144;
              else
                v141 = v146;
              goto LABEL_206;
            }
LABEL_226:
            v142 = 5;
          }
          else
          {
LABEL_224:
            v142 = 8;
          }
        }
LABEL_227:
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: vdev id %d opmode %d self dot11mode %d bss_dot11 mode %d intersected %d bss phy mode %d",
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          "lim_fill_dot11_mode",
          *(unsigned __int8 *)(a2 + 10),
          *(unsigned int *)(a2 + 7036),
          v86,
          (unsigned int)v125,
          v142,
          a4);
        *(_BYTE *)(a2 + 154) = v142;
LABEL_228:
        v151 = *(_QWORD *)(a2 + 112);
        param = wlan_crypto_get_param(*(_QWORD *)(a2 + 16), 1u);
        if ( param != -1 && (param & 0x18003) != 0 )
        {
          if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v151 + 4392)) )
            v161 = 4;
          else
            v161 = 2;
          *(_BYTE *)(a2 + 154) = v161;
          qdf_trace_msg(
            0x35u,
            4u,
            "%s: HT not supported with TKIP/WEP overriding dot11mode to %d",
            v153,
            v154,
            v155,
            v156,
            v157,
            v158,
            v159,
            v160,
            "lim_verify_dot11_mode_with_crypto");
          v12[2944] = *(_BYTE *)(*(_QWORD *)(a2 + 8608) + 17168LL);
        }
LABEL_234:
        cb_mode = wlan_get_cb_mode(a1, *(unsigned int *)(a2 + 284), v624, a2);
        v171 = v613;
        if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 28))
          && (wlan_cm_get_force_20mhz_in_24ghz(*(_QWORD *)(a2 + 16), v163, v164, v165, v166, v167, v168, v169, v170) & 1) != 0 )
        {
          cb_mode = 0;
        }
        if ( (unsigned int)wlan_get_rate_set(a1, v624, a2) )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Get rate failed vdev id %d",
            v172,
            v173,
            v174,
            v175,
            v176,
            v177,
            v178,
            v179,
            "lim_fill_pe_session",
            *(unsigned __int8 *)(a2 + 10));
          v180 = *(_DWORD *)(a3 + 28);
          v181 = wlan_reg_is_24ghz_ch_freq(v180);
          if ( v181 || wlan_reg_is_5ghz_ch_freq(v180) )
            wlan_populate_basic_rates(a2 + 252, !v181, 1);
        }
        v182 = *(_QWORD *)(a1 + 8);
        if ( *(_BYTE *)(a2 + 154) == 3 )
          v183 = 0;
        else
          v183 = *(_BYTE *)(v182 + 1284);
        *(_BYTE *)(v182 + 5388) = v183;
        v184 = *(unsigned __int16 *)(a3 + 16);
        v185 = *(_QWORD *)(a1 + 8);
        v186 = 10 * v184;
        if ( v184 <= 0x32 )
          v186 = 500;
        if ( *(_WORD *)(a3 + 16) )
          v187 = v186;
        else
          v187 = *(_DWORD *)(v185 + 3476);
        if ( v187 >= *(_DWORD *)(v185 + 3476) )
          v187 = *(_DWORD *)(v185 + 3476);
        *(_DWORD *)(v185 + 3468) = v187;
        v188 = policy_mgr_will_freq_lead_to_mcc(*(_QWORD *)(a1 + 21552), *(_DWORD *)(a3 + 28));
        v197 = *(_QWORD *)(a1 + 8);
        v198 = 200;
        if ( v188 )
        {
          if ( *(_DWORD *)(v197 + 3468) / 5u <= 0xC8 )
            v198 = 200;
          else
            v198 = *(_DWORD *)(v197 + 3468) / 5u;
        }
        *(_DWORD *)(v197 + 3472) = v198;
        v199 = (_BYTE *)v624;
        v610 = cb_mode;
        v200 = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a2 + 16), v189, v190, v191, v192, v193, v194, v195, v196);
        if ( v200 )
        {
          v209 = *(_DWORD *)(a2 + 284);
          v210 = v200;
          v211 = *(_DWORD *)(v200 + 48);
          v212 = *(_DWORD *)(v200 + 60);
          if ( (*(_WORD *)(*(_QWORD *)(a1 + 8) + 1268LL) & 1) != 0
            && (wma_is_rx_ldpc_supported_for_channel(v209) & 1) != 0 )
          {
            v213 = v211 | 0x10;
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: LDPC enable for ch freq[%d]",
              v201,
              v202,
              v203,
              v204,
              v205,
              v206,
              v207,
              v208,
              "lim_set_ldpc_exception",
              v209);
            v214 = v212 & 0xFFFE | 1;
          }
          else
          {
            v214 = v212 & 0xFFFE;
            v213 = v211 & 0xFFFFFFEF;
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: LDPC disable for ch freq[%d]",
              v201,
              v202,
              v203,
              v204,
              v205,
              v206,
              v207,
              v208,
              "lim_set_ldpc_exception",
              v209);
          }
          *(_DWORD *)(v210 + 48) = v213;
          *(_DWORD *)(v210 + 60) = v214 | v212 & 0xFFFF0000;
          v215 = *(unsigned __int8 **)(a1 + 8);
          if ( v199[1408] )
          {
            v171 = v613;
            v216 = v199 + 1408;
            v217 = (unsigned __int16 *)(v199 + 1257);
          }
          else
          {
            v171 = v613;
            v217 = (unsigned __int16 *)(v199 + 1257);
            if ( v199[4876] )
              v216 = v199 + 4876;
            else
              v216 = nullptr;
          }
          v218 = 0;
          if ( v215[2623] && v216 )
          {
            if ( *((_BYTE *)v217 + 3611) )
            {
              v218 = v215[2624];
              if ( *(__int16 *)(v216 + 1) >= 0x2000 )
              {
                if ( v215[2624] >= (unsigned int)(*(unsigned __int16 *)(v216 + 1) >> 13) )
                  v218 = *(unsigned __int16 *)(v216 + 1) >> 13;
                else
                  v218 = v215[2624];
              }
            }
            else
            {
              v218 = v215[2624];
            }
          }
          v219 = v215[2622];
          if ( v219 == 1
            && (!v199[1408]
             || *((__int16 *)v199 + 707) == -1
             || *((__int16 *)v199 + 709) == -1
             || (v217[76] & 0x1000) == 0)
            && (!*((_BYTE *)v217 + 3619)
             || *((__int16 *)v199 + 2441) == -1
             || *((__int16 *)v199 + 2443) == -1
             || (v217[1810] & 0x1000) == 0) )
          {
            v220 = v213 & 0xFFF807FF | (v215[2623] << 12) & 0xFFF8F7FF | ((v218 & 7) << 13);
          }
          else
          {
            v220 = v213 & 0xFFFF07FF | (v215[2623] << 12) | ((v218 & 7) << 13) | (v219 << 11);
            if ( !v215[2622] )
              v220 = v213 & 0xFFF807FF | (v215[2623] << 12) & 0xFFF8F7FF | ((v218 & 7) << 13);
          }
          if ( v215[2668] == 1 && (v220 & 0x1000) != 0 && (v199[1411] & 8) != 0 )
            v221 = v220 | 0x100000;
          else
            v221 = v220 & 0xFFEFFFFF;
          if ( (unsigned int)*(unsigned __int8 *)(a2 + 154) - 8 >= 6 && *(_BYTE *)(a2 + 154) )
          {
            v222 = *(_DWORD *)(a2 + 7036);
          }
          else
          {
            v222 = *(_DWORD *)(a2 + 7036);
            if ( v222 )
              v221 &= ~0x1000u;
          }
          *(_DWORD *)(a2 + 7268) = v221;
          v223 = *(_DWORD *)(v210 + 60);
          *(_WORD *)(a2 + 7266) = v223;
          if ( !v222 )
          {
            v224 = v223;
            if ( (v223 & 0x20) != 0 )
            {
              v224 = *v217 & 0x20 | v223 & 0xFFDF;
              *(_WORD *)(a2 + 7266) = v224;
            }
            if ( (v224 & 0x40) != 0 )
              *(_WORD *)(a2 + 7266) = *v217 & 0x40 | v224 & 0xFFBF;
          }
          if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 284)) )
            *(_DWORD *)(a2 + 7268) &= 0xFFFFFF9F;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: HT cap 0x%x VHT cap 0x%x, AP cap sgi_20 %d sgi_40 %d",
            v225,
            v226,
            v227,
            v228,
            v229,
            v230,
            v231,
            v232,
            "lim_join_req_update_ht_vht_caps",
            v223,
            v221,
            (*v217 >> 5) & 1,
            (*v217 >> 6) & 1);
        }
        v233 = *(_QWORD *)(a2 + 112);
        v234 = (_BYTE *)v624;
        v235 = *(_DWORD *)(v233 + 4392);
        memset(dest, 0, 32);
        v236 = wlan_reg_is_24ghz_ch_freq(v235);
        v237 = 21522;
        if ( v236 )
          v237 = 21512;
        v238 = a1 + v237;
        if ( *(_DWORD *)(*(_QWORD *)(a2 + 16) + 16LL) == 2 )
          v239 = 3;
        else
          v239 = 0;
        v240 = *(_BYTE *)(v238 + v239);
        v12[1628] = v240;
        v12[1611] = v240;
        ielen_from_bss_description = wlan_get_ielen_from_bss_description(v233 + 4364);
        v242 = *(unsigned __int8 *)(a2 + 154);
        LODWORD(dest[1]) = ielen_from_bss_description;
        dest[0] = (unsigned __int8 *)(v233 + 4468);
        v243 = v242 < 0xE;
        dest[2] = (unsigned __int8 *)(v233 + 4366);
        if ( v242 - 10 >= 4 && v242 || !v234[2252] )
        {
          if ( (v243 & (0x3F01u >> v242)) == 0 || !v234[1408] )
          {
            if ( (v243 & (0x3FA1u >> v242)) != 0 && v234[1256] )
            {
              if ( v234[1263] )
                goto LABEL_320;
              if ( v234[1262] )
                goto LABEL_324;
              if ( v234[1261] )
                goto LABEL_316;
            }
LABEL_326:
            v245 = 1;
LABEL_327:
            v246 = (unsigned __int8)v234[1256];
            v247 = (unsigned __int8)v234[1408];
            LODWORD(dest[3]) = v245;
            v248 = *(_DWORD *)(v233 + 4392);
            BYTE4(dest[3]) = v246 != 0;
            BYTE5(dest[3]) = v247 != 0;
            v249 = wlan_reg_is_24ghz_ch_freq(v248);
            v250 = *(_DWORD *)(v233 + 4392);
            BYTE6(dest[3]) = v249;
            v251 = wlan_reg_is_5ghz_ch_freq(v250);
            v252 = *(_QWORD *)(a1 + 8);
            HIBYTE(dest[3]) = v251;
            if ( !*(_BYTE *)(v252 + 2667) )
            {
              v12[1611] = 1;
              v12[1628] = 1;
            }
            if ( (wlan_action_oui_search(*(_QWORD *)(a1 + 21552), dest, 2) & 1) != 0 )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: vdev: %d wmi_vdev_param_abg_mode_tx_chain_num 1",
                v253,
                v254,
                v255,
                v256,
                v257,
                v258,
                v259,
                v260,
                "lim_check_oui_and_update_session",
                *(unsigned __int8 *)(a2 + 10));
              wma_cli_set_command(*(unsigned __int8 *)(a2 + 10), 117, 1, 1);
            }
            v261 = wlan_action_oui_search(*(_QWORD *)(a1 + 21552), dest, 4);
            if ( *(_DWORD *)(a1 + 17164) )
            {
              if ( (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 1072LL) & v261 & 1) != 0 )
              {
                v262 = *(unsigned __int8 *)(a2 + 154);
                if ( v262 <= 9 && ((1 << v262) & 0x301) != 0 )
                  *(_BYTE *)(a2 + 154) = 5;
              }
            }
            v263 = wlan_action_oui_search(*(_QWORD *)(a1 + 21552), dest, 22);
            mlme_set_follow_ap_edca_flag(*(_QWORD *)(a2 + 16), v263 & 1, v264, v265, v266, v267, v268, v269, v270, v271);
            if ( (wlan_action_oui_search(*(_QWORD *)(a1 + 21552), dest, 19) & 1) != 0 )
              mlme_set_reconn_after_assoc_timeout_flag(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a2 + 10), 1);
            if ( (wlan_action_oui_search(*(_QWORD *)(a1 + 21552), dest, 0) & 1) != 0 )
            {
              v272 = dest[0];
              if ( !wlan_get_vendor_ie_ptr_from_oui(&unk_A30388, 3u, dest[0], ielen_from_bss_description)
                || !wlan_get_vendor_ie_ptr_from_oui(&unk_92E833, 3u, v272, ielen_from_bss_description) )
              {
                goto LABEL_344;
              }
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Vendor OUI 3 and Vendor OUI 4 found",
                v273,
                v274,
                v275,
                v276,
                v277,
                v278,
                v279,
                v280,
                "lim_check_vendor_ap_3_present");
            }
            if ( (wlan_action_oui_search(*(_QWORD *)(a1 + 21552), dest, 5) & 1) == 0 )
              goto LABEL_349;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: 1x1 with 1 Chain AP",
              v281,
              v282,
              v283,
              v284,
              v285,
              v286,
              v287,
              v288,
              "lim_check_oui_and_update_session");
LABEL_344:
            if ( !policy_mgr_is_hw_dbs_2x2_capable(*(_QWORD *)(a1 + 21552)) )
            {
              v297 = *(_DWORD *)(a1 + 17164);
              if ( v297 == 2 || v297 == 1 && *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1072LL) == 1 )
              {
                v12[1628] = 1;
                *(_WORD *)(v12 + 1611) = 257;
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: For special ap, NSS: %d force 1x1 %d",
                  v289,
                  v290,
                  v291,
                  v292,
                  v293,
                  v294,
                  v295,
                  v296,
                  "lim_check_oui_and_update_session",
                  1,
                  *(unsigned int *)(a1 + 17164));
              }
            }
LABEL_349:
            if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v233 + 4392))
              && (wlan_action_oui_search(*(_QWORD *)(a1 + 21552), dest, 17) & 1) != 0 )
            {
              v12[3048] = 1;
            }
            if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v233 + 4392))
              && (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 2671LL) & 1) == 0 )
            {
              v306 = *(unsigned __int8 *)(a2 + 154);
              if ( v306 == 8 )
              {
                *(_BYTE *)(a2 + 154) = 5;
                goto LABEL_364;
              }
            }
            else
            {
              v306 = *(unsigned __int8 *)(a2 + 154);
            }
            if ( v306 == 10 )
            {
              ext_hdl = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a2 + 16), v298, v299, v300, v301, v302, v303, v304, v305);
              if ( ext_hdl )
              {
                v316 = *((unsigned __int16 *)v234 + 1136);
                v317 = *(unsigned __int16 *)(ext_hdl + 23918);
                v609 = ext_hdl + 20480;
                v318 = (v317 >> 1) & 1;
                v319 = (v317 >> 2) & 1;
                v320 = ((unsigned int)v316 >> 2) & 1;
                v608 = ((unsigned int)v316 >> 1) & v316 & 1 | (v317 >> 1) & v317 & 1;
                v321 = v318 & ~(v316 & 1 | v317 & 1) & ((unsigned int)v316 >> 1);
                v322 = (v317 >> 3) & 1;
                v323 = (v318 ^ v317 & 1) & ~((unsigned int)v316 >> 1) & v316
                     | (((unsigned int)v316 >> 1) ^ v316) & ~(v317 >> 1) & v317 & 1;
                v324 = v322 ^ v319;
                v325 = v320 & ((unsigned int)v316 >> 3) | v319 & (v317 >> 3);
                v326 = v322 & ~(v320 | v319) & ((unsigned int)v316 >> 3);
                v327 = (((unsigned int)v316 >> 3) ^ ((unsigned int)v316 >> 2)) & ~(v317 >> 3) & v319;
                v328 = v324 & ~((unsigned int)v316 >> 3) & ((unsigned int)v316 >> 2);
                v329 = (v317 >> 4) & 1;
                v330 = ((unsigned int)v316 >> 4) & 1;
                v331 = v328 | v327;
                v332 = (v317 >> 5) & 1;
                v333 = v331 | (2 * (v326 | v325));
                v334 = v330 & ((unsigned int)v316 >> 5) | v329 & (v317 >> 5);
                v335 = (((unsigned int)v316 >> 5) ^ ((unsigned int)v316 >> 4)) & ~(v317 >> 5) & v329;
                v336 = v332 ^ v329;
                v337 = v330 | v329;
                v338 = v336 & ~((unsigned int)v316 >> 5);
                v339 = (v317 >> 6) & 1;
                v340 = ((unsigned int)v316 >> 6) & 1;
                v341 = (v317 >> 7) & 1;
                v342 = ielen_from_bss_description;
                v343 = v338 & ((unsigned int)v316 >> 4) | v335;
                v344 = v340 & ((unsigned int)v316 >> 7) | v339 & (v317 >> 7);
                v345 = v343 | (2 * (v332 & ~v337 & ((unsigned int)v316 >> 5) | v334));
                v346 = (v341 ^ v339) & ~((unsigned int)v316 >> 7) & ((unsigned int)v316 >> 6)
                     | (((unsigned int)v316 >> 7) ^ ((unsigned int)v316 >> 6)) & ~(v317 >> 7) & v339;
                v347 = v341 & ~(v340 | v339) & ((unsigned int)v316 >> 7) | v344;
                v348 = (v317 >> 9) & 1;
                v349 = (v317 >> 8) & 1;
                v350 = ((unsigned int)v316 >> 8) & 1;
                v351 = v345 | v334;
                v352 = v346 | (2 * v347);
                v353 = (v348 ^ v349) & ~((unsigned int)v316 >> 9);
                v354 = v348 & ~(v350 | v349);
                v355 = v350 & ((unsigned int)v316 >> 9) | v349 & (v317 >> 9);
                v356 = v353 & ((unsigned int)v316 >> 8)
                     | (((unsigned int)v316 >> 9) ^ ((unsigned int)v316 >> 8)) & ~(v317 >> 9) & v349;
                v357 = (v317 >> 10) & 1;
                v358 = ((unsigned int)v316 >> 10) & 1;
                v359 = v352 | v344;
                v360 = v356 | (2 * (v354 & ((unsigned int)v316 >> 9) | v355)) | v355;
                v361 = v358 & ((unsigned int)v316 >> 11) | v357 & (v317 >> 11);
                v362 = (unsigned int)v316 >> 15;
                v363 = (v317 >> 12) & 1;
                v364 = ((unsigned int)v316 >> 12) & 1;
                v365 = ((v317 >> 11) & 1 ^ v357) & ~((unsigned int)v316 >> 11) & ((unsigned int)v316 >> 10)
                     | (((unsigned int)v316 >> 11) ^ ((unsigned int)v316 >> 10)) & ~(v317 >> 11) & v357
                     | (2 * ((v317 >> 11) & 1 & ~(v358 | v357) & ((unsigned int)v316 >> 11) | v361));
                v171 = v613;
                v366 = v364 & ((unsigned int)v316 >> 13) | v363 & (v317 >> 13);
                ielen_from_bss_description = v342;
                v367 = ((((v317 >> 14) & 1 ^ (v317 >> 15)) & ~v362 & ((unsigned int)v316 >> 14)
                       | (((unsigned int)v316 >> 14) & 1 ^ v362) & ~(v317 >> 15) & (v317 >> 14)
                       | (2
                        * ((v317 >> 15) & ~(((unsigned int)v316 >> 14) | (v317 >> 14)) & v362
                         | ((unsigned int)v316 >> 14) & v362
                         | (v317 >> 14) & (v317 >> 15)))
                       | ((unsigned int)v316 >> 14) & v362
                       | (v317 >> 14) & (v317 >> 15)) << 14)
                     | (16 * v351)
                     | (v359 << 6)
                     | (v360 << 8)
                     | ((v365 | v361) << 10)
                     | ((((v317 >> 13) & 1 ^ v363) & ~((unsigned int)v316 >> 13) & ((unsigned int)v316 >> 12)
                       | (((unsigned int)v316 >> 13) ^ ((unsigned int)v316 >> 12)) & ~(v317 >> 13) & v363
                       | (2 * ((v317 >> 13) & 1 & ~(v364 | v363) & ((unsigned int)v316 >> 13) | v366))
                       | v366) << 12)
                     | v323
                     | (2 * (v321 | v608))
                     | (4 * (v333 | v325))
                     | v608;
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: HE self rates %x AP rates %x int_mcs %x vendorIE %d",
                  v308,
                  v309,
                  v310,
                  v311,
                  v312,
                  v313,
                  v314,
                  v315,
                  "lim_handle_iot_ap_no_common_he_rates",
                  *(unsigned __int16 *)(v609 + 3436),
                  v316,
                  v367,
                  (unsigned __int8)v234[4872]);
                if ( v234[2252] )
                {
                  if ( v367 == 0xFFFF && (v234[4872] || v234[1408]) )
                  {
                    *(_BYTE *)(a2 + 154) = 8;
                    qdf_trace_msg(
                      0x34u,
                      8u,
                      "%s: No common 11AX rate. Force 11AC connection",
                      v368,
                      v369,
                      v370,
                      v371,
                      v372,
                      v373,
                      v374,
                      v375,
                      "lim_handle_iot_ap_no_common_he_rates");
                  }
                }
              }
            }
LABEL_364:
            v376 = wlan_get_vendor_ie_ptr_from_oui(&unk_A30394, 3u, dest[0], ielen_from_bss_description) != nullptr;
            wlan_mlme_set_ba_2k_jump_iot_ap(*(_QWORD *)(a2 + 16), v376, v377, v378, v379, v380, v381, v382, v383, v384);
            if ( wlan_get_vendor_ie_ptr_from_oui(&unk_A0A094, 4u, dest[0], ielen_from_bss_description) )
            {
              if ( wlan_get_vendor_ie_ptr_from_oui(&unk_A0A099, 4u, dest[0], ielen_from_bss_description) )
              {
                v393 = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a2 + 16), v385, v386, v387, v388, v389, v390, v391, v392);
                if ( v393 )
                {
                  v394 = v393;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: new htc he: %d",
                    v385,
                    v386,
                    v387,
                    v388,
                    v389,
                    v390,
                    v391,
                    v392,
                    "lim_update_he_caps_htc",
                    0);
                  *(_QWORD *)(v394 + 23897) &= ~1uLL;
                }
              }
            }
            v395 = *(_BYTE **)(a2 + 16);
            v396 = (_BYTE *)v624;
            v397 = *(unsigned __int8 *)(v624 + 3449);
            *(_BYTE *)(a2 + 30) = v395[74];
            *(_BYTE *)(a2 + 31) = v395[75];
            *(_BYTE *)(a2 + 32) = v395[76];
            *(_BYTE *)(a2 + 33) = v395[77];
            *(_BYTE *)(a2 + 34) = v395[78];
            *(_BYTE *)(a2 + 35) = v395[79];
            *(_WORD *)(a2 + 248) = 1;
            v398 = wlan_vdev_mlme_get_ext_hdl((__int64)v395, v385, v386, v387, v388, v389, v390, v391, v392);
            if ( !v398 )
            {
LABEL_396:
              if ( *(_DWORD *)(*(_QWORD *)(a2 + 112) + 4452LL) )
              {
                v411 = *(_BYTE *)(v612 + 1774);
                v12[18] = v411;
              }
              else
              {
                v411 = v12[18];
              }
              v412 = *(_QWORD *)(a1 + 21552);
              v413 = *(unsigned __int8 *)(a2 + 10);
              LOBYTE(v617) = v411;
              wlan_cm_roam_cfg_set_value(v412, v413, 0x16u, (unsigned int *)&v616);
              psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(*(_QWORD *)(a1 + 21552));
              if ( psoc_ext_obj_fl )
              {
                v423 = psoc_ext_obj_fl;
                if ( (cm_is_auth_type_11r(
                        psoc_ext_obj_fl,
                        *(_QWORD *)(a2 + 16),
                        *(_BYTE *)(*(_QWORD *)(a2 + 112) + 4408LL) != 0)
                    & 1) != 0
                  && !cm_ese_open_present(*(_QWORD *)(a2 + 16), v423, v397 != 0) )
                {
                  v12[17] = 1;
                }
              }
              v424 = *(_QWORD *)(a1 + 21560);
              v425 = *(_BYTE *)(a2 + 10);
              is_ese_connection = cm_is_ese_connection(
                                    *(_QWORD *)(a2 + 16),
                                    v397 != 0,
                                    v415,
                                    v416,
                                    v417,
                                    v418,
                                    v419,
                                    v420,
                                    v421,
                                    v422);
              wlan_cm_set_ese_assoc(v424, v425, is_ese_connection & 1);
              wlan_cm_roam_cfg_get_value(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a2 + 10), 0xDu, v614);
              v427 = v614[0];
              wlan_cm_roam_cfg_get_value(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a2 + 10), 0x1Cu, v614);
              v428 = v614[0];
              if ( (wlan_cm_is_self_mld_roam_supported(
                      *(_QWORD *)(a1 + 21552),
                      v429,
                      v430,
                      v431,
                      v432,
                      v433,
                      v434,
                      v435,
                      v436)
                  & 1) == 0 )
              {
                if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 28))
                  || ((v458 = *(char *)(a3 + 24), v458 >= 0) ? (v459 = *(char *)(a3 + 24)) : (v459 = -v458),
                      v459 <= v427 - v428) )
                {
                  wlan_cm_set_disable_hi_rssi(*(_QWORD *)(a1 + 21560), *(_BYTE *)(a2 + 10), 1);
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Disabling HI_RSSI, AP freq=%d, rssi=%d",
                    v460,
                    v461,
                    v462,
                    v463,
                    v464,
                    v465,
                    v466,
                    v467,
                    "lim_fill_pe_session",
                    *(unsigned int *)(a3 + 28),
                    (unsigned int)*(char *)(a3 + 24));
                  if ( *(_DWORD *)(a2 + 7036) )
                    goto LABEL_406;
                  goto LABEL_405;
                }
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Enabling HI_RSSI, rssi: %d lookup_th: %d, delta:%d",
                  v450,
                  v451,
                  v452,
                  v453,
                  v454,
                  v455,
                  v456,
                  v457,
                  "lim_fill_pe_session");
              }
              wlan_cm_set_disable_hi_rssi(*(_QWORD *)(a1 + 21560), *(_BYTE *)(a2 + 10), 0);
              if ( *(_DWORD *)(a2 + 7036) )
              {
LABEL_406:
                vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(
                                           &unk_A3038C,
                                           3u,
                                           (unsigned __int8 *)(a3 + 104),
                                           *(_WORD *)a3 - 102);
                v438 = *(unsigned __int8 *)(a2 + 154);
                v12[262] = vendor_ie_ptr_from_oui != nullptr;
                *(_DWORD *)(a2 + 96) = *(_DWORD *)(a3 + 20);
                v12[166] = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1279LL);
                v12[167] = *(_BYTE *)(a1 + 17156);
                if ( (unsigned int)(v438 - 8) >= 6 && v438 )
                {
                  v440 = 0;
                  v439 = 7170;
                }
                else
                {
                  v439 = 7186;
                  v12[146] = 1;
                  v12[161] = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2669LL);
                  v440 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2670LL);
                }
                *(_BYTE *)(a2 + v439) = v440;
                *(_DWORD *)(a2 + 7232) = *(_DWORD *)(a3 + 20);
                handle_ht_capabilityand_ht_info(a1, (unsigned __int8 *)a2);
                *(_DWORD *)(a2 + 164) = v610;
                *(_BYTE *)(a2 + 160) = v610 != 0;
                *(_BYTE *)(a2 + 161) = v610 != 0;
                if ( v610 == 3 )
                {
                  v449 = -2;
                }
                else
                {
                  if ( v610 != 1 )
                  {
                    v470 = 0;
                    v469 = 0;
                    goto LABEL_422;
                  }
                  v449 = 2;
                }
                v468 = wlan_reg_freq_to_chan(
                         *(_QWORD *)(a1 + 21560),
                         *(_DWORD *)(a2 + 284),
                         v441,
                         v442,
                         v443,
                         v444,
                         v445,
                         v446,
                         v447,
                         v448);
                v469 = 1;
                v470 = v468 + v449;
LABEL_422:
                v471 = *(unsigned __int8 *)(a2 + 154);
                v12[150] = v470;
                *(_DWORD *)(a2 + 7176) = v469;
                *(_DWORD *)(a2 + 7180) = v469;
                if ( v471 - 10 < 4 || !v471 )
                {
                  lim_update_session_he_capable(a1, a2);
                  lim_copy_join_req_he_cap(a2);
                  v471 = *(unsigned __int8 *)(a2 + 154);
                }
                if ( v471 <= 0xD && ((1 << v471) & 0x3001) != 0 )
                {
                  v472 = wlan_crypto_get_param(*(_QWORD *)(a2 + 16), 5u);
                  wlan_crypto_set_vdev_param(*(_QWORD *)(a2 + 16), 5u, v472 & 0xBFFF);
                }
                if ( (lim_get_vdev_rmf_capable(a1, a2) & 1) != 0 )
                  v481 = 16;
                else
                  v481 = 0;
                v482 = *v12 & 0xEF | v481;
                v483 = v12[1611];
                *v12 = v482;
                v484 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1283LL);
                *(_DWORD *)(a2 + 88) = 2;
                v12[212] = v484;
                if ( v483 == 1 )
                  v12[1629] = 1;
                v485 = *(_QWORD *)(a2 + 16);
                *(_WORD *)(a2 + 176) = *(_WORD *)(a3 + 18);
                v486 = wlan_vdev_mlme_get_cmpt_obj(v485, v473, v474, v475, v476, v477, v478, v479, v480);
                if ( !v486 )
                {
                  v50 = 16;
                  goto LABEL_514;
                }
                v487 = v486;
                v488 = wlan_get_ielen_from_bss_description(a3);
                ap_capability = lim_extract_ap_capability(a1, a3 + 104, v488, a2 + 178, v12 + 248, v623, a2, v622);
                if ( ap_capability )
                {
                  v50 = ap_capability;
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: extract ap caps failed %d",
                    v490,
                    v491,
                    v492,
                    v493,
                    v494,
                    v495,
                    v496,
                    v497,
                    "lim_fill_pe_session",
                    ap_capability);
LABEL_514:
                  _qdf_mem_free(v624);
                  goto LABEL_515;
                }
                memset(&dest[1], 0, 24);
                v498 = (unsigned __int16)wlan_get_ielen_from_bss_description(a3);
                v499 = *(_QWORD *)(a1 + 21552);
                dest[0] = (unsigned __int8 *)(a3 + 104);
                LODWORD(dest[1]) = v498;
                if ( (wlan_action_oui_search(v499, dest, 21) & 1) != 0 )
                {
                  *(_DWORD *)(a2 + 7268) &= 0xFFEFEFFF;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Disable Beamformee for IoT AP",
                    v500,
                    v501,
                    v502,
                    v503,
                    v504,
                    v505,
                    v506,
                    v507,
                    "lim_disable_bformee_for_iot_ap");
                }
                if ( *(_DWORD *)(a2 + 7036)
                  || wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 28))
                  && ((v516 = *(unsigned __int8 *)(a2 + 154), v516 > 0xD) || ((1 << v516) & 0x3001) == 0) )
                {
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Disable HT D-SMPS",
                    v500,
                    v501,
                    v502,
                    v503,
                    v504,
                    v505,
                    v506,
                    v507,
                    "lim_disable_ht_dynamic_smps");
                  *(_WORD *)(a2 + 7266) |= 0xCu;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Disable HE D-SMPS",
                    v508,
                    v509,
                    v510,
                    v511,
                    v512,
                    v513,
                    v514,
                    v515,
                    "lim_disable_he_dynamic_smps");
                  *(_QWORD *)(v12 + 1657) &= ~0x400000000000uLL;
                }
                memset(&dest[1], 0, 24);
                v517 = (unsigned __int16)wlan_get_ielen_from_bss_description(a3);
                v518 = *(_QWORD *)(a1 + 21552);
                dest[0] = (unsigned __int8 *)(a3 + 104);
                LODWORD(dest[1]) = v517;
                if ( (wlan_action_oui_search(v518, dest, 27) & 1) != 0 )
                {
                  v527 = "%s: Enable HT and HE D-SMPS for this IOT AP";
                  v528 = *(_QWORD *)(v12 + 1657) | 0x400000000000LL;
                  *(_WORD *)(a2 + 7266) = *(_WORD *)(a2 + 7266) & 0xFFF3 | 4;
                  *(_QWORD *)(v12 + 1657) = v528;
                }
                else
                {
                  if ( (wlan_action_oui_is_empty(*(_QWORD *)(a1 + 21552), 27) & 1) == 0
                    || (wlan_action_oui_search(*(_QWORD *)(a1 + 21552), dest, 18) & 1) == 0 )
                  {
LABEL_452:
                    *(_BYTE *)(v487 + 932) = v622[0] ^ 1;
                    if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a3 + 28)) )
                    {
                      if ( !*(_BYTE *)(v624 + 322) )
                        qdf_trace_msg(
                          0x35u,
                          8u,
                          "%s: Channel is 6G but country IE not present",
                          v545,
                          v546,
                          v547,
                          v548,
                          v549,
                          v550,
                          v551,
                          v552,
                          "lim_fill_pe_session");
                      v553 = v12[3044];
                      if ( v553 == 2 )
                      {
                        if ( (wlan_reg_is_indoor_ap_detected(
                                *(_QWORD *)(a1 + 21560),
                                v545,
                                v546,
                                v547,
                                v548,
                                v549,
                                v550,
                                v551,
                                v552)
                            & 1) != 0 )
                        {
                          v553 = 3;
                          v12[3044] = 3;
                        }
                        else
                        {
                          v553 = v12[3044];
                        }
                      }
                      if ( (unsigned int)wlan_reg_get_best_6g_power_type(
                                           *(_QWORD *)(a1 + 21552),
                                           *(_QWORD *)(a1 + 21560),
                                           (unsigned int *)&v615,
                                           v553,
                                           *(_DWORD *)(a3 + 28),
                                           v545,
                                           v546,
                                           v547,
                                           v548,
                                           v549,
                                           v550,
                                           v551,
                                           v552) )
                      {
                        v50 = 11;
                        if ( v171 )
                          *v171 = 23;
                        goto LABEL_514;
                      }
                      v562 = v615;
                      v563 = *(_QWORD *)(a2 + 16);
                      v12[3045] = v615;
                      mlme_set_best_6g_power_type(v563, v562, v554, v555, v556, v557, v558, v559, v560, v561);
                      memcpy(dest, (const void *)(v624 + 322), 0xF8u);
                      lim_iterate_triplets(dest);
                      if ( !*(_WORD *)(v624 + 1430) || !*(_BYTE *)(v624 + 1432) )
                        qdf_trace_msg(
                          0x35u,
                          8u,
                          "%s: TPE not present for 6G channel",
                          v545,
                          v546,
                          v547,
                          v548,
                          v549,
                          v550,
                          v551,
                          v552,
                          "lim_fill_pe_session");
                    }
                    if ( (wlan_reg_is_ext_tpc_supported(
                            *(_QWORD *)(a1 + 21552),
                            v545,
                            v546,
                            v547,
                            v548,
                            v549,
                            v550,
                            v551,
                            v552)
                        & 1) != 0 )
                    {
                      *(_BYTE *)(v487 + 552) = v623[0];
                    }
                    else
                    {
                      channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(
                                                     *(_QWORD *)(a1 + 21560),
                                                     *(_DWORD *)(a2 + 284),
                                                     v564,
                                                     v565,
                                                     v566,
                                                     v567,
                                                     v568,
                                                     v569,
                                                     v570,
                                                     v571);
                      v573 = v623[0];
                      if ( v622[0] )
                        v573 = channel_reg_power_for_freq - v623[0];
                      v574 = v573;
                      if ( !v573 )
                        v573 = channel_reg_power_for_freq;
                      if ( !v574 || v622[0] )
                        v623[0] = v573;
                      *(_BYTE *)(v487 + 536) = channel_reg_power_for_freq;
                      *(_BYTE *)(v487 + 552) = v573;
                      *(_DWORD *)(v487 + 556) = *(_DWORD *)(a2 + 284);
                      max_tx_power = lim_get_max_tx_power(a1, v487);
                      v12[8] = max_tx_power;
                      v12[3018] = max_tx_power;
                    }
                    if ( *(_DWORD *)(a2 + 88) == 2 && !v12[8] )
                      v12[8] = wlan_reg_get_channel_reg_power_for_freq(
                                 *(_QWORD *)(a1 + 21560),
                                 *(_DWORD *)(a2 + 284),
                                 v564,
                                 v565,
                                 v566,
                                 v567,
                                 v568,
                                 v569,
                                 v570,
                                 v571);
                    v576 = *(_DWORD *)(a2 + 284);
                    if ( wlan_reg_is_6ghz_chan_freq(v576) )
                    {
                      v577 = 2;
                    }
                    else if ( wlan_reg_is_5ghz_ch_freq(v576) )
                    {
                      v577 = 1;
                    }
                    else
                    {
                      if ( wlan_reg_is_24ghz_ch_freq(v576) )
                      {
                        v578 = v611;
                        v579 = 0;
                        *(_DWORD *)(a2 + 168) = 0;
LABEL_487:
                        v580 = *(_DWORD *)(a2 + 80);
                        v581 = *(_WORD *)(a2 + 8);
                        *(_DWORD *)(a2 + 7028) = v579;
                        *(_DWORD *)(a2 + 80) = 3;
                        *(_DWORD *)(a2 + 84) = v580;
                        v582 = qdf_trace(53, 1u, v581, 3);
                        is_mbssid_enabled = wma_is_mbssid_enabled(v582);
                        v584 = v12[1610];
                        v12[3020] = is_mbssid_enabled & 1;
                        if ( v584 && (lim_isconnected_on_dfs_freq(a1, *(unsigned int *)(a2 + 284)) & 1) != 0 )
                          v12[168] = 1;
                        if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1061LL) == 1
                          && (*(_WORD *)(a3 + 18) & 0x100) != 0
                          && !*(_DWORD *)(a3 + 20) )
                        {
                          v12[168] = 1;
                        }
                        v593 = 24;
                        if ( (char)wlan_get_cfg_max_tx_power(
                                     *(_QWORD *)(a1 + 21552),
                                     *(_QWORD *)(a1 + 21560),
                                     *(_DWORD *)(a3 + 28)) <= 23 )
                        {
                          cfg_max_tx_power = wlan_get_cfg_max_tx_power(
                                               *(_QWORD *)(a1 + 21552),
                                               *(_QWORD *)(a1 + 21560),
                                               *(_DWORD *)(a3 + 28));
                          if ( cfg_max_tx_power )
                            v593 = cfg_max_tx_power;
                          else
                            v593 = 24;
                        }
                        v595 = (char)v12[8];
                        if ( v593 < v595 )
                          LOBYTE(v595) = v593;
                        v12[10] = v595;
                        v12[9] = 8;
                        qdf_trace_msg(
                          0x35u,
                          8u,
                          "%s: Min session tx power: %d",
                          v585,
                          v586,
                          v587,
                          v588,
                          v589,
                          v590,
                          v591,
                          v592,
                          "lim_fill_pe_session",
                          8);
                        if ( (v12[3023] & 1) == 0 )
                        {
                          if ( (unsigned int)wlan_mlme_get_wmm_mode(*(_QWORD *)(a1 + 21552), v621) )
                          {
                            v604 = "%s: Get wmm_mode failed";
LABEL_503:
                            qdf_trace_msg(
                              0x35u,
                              2u,
                              v604,
                              v596,
                              v597,
                              v598,
                              v599,
                              v600,
                              v601,
                              v602,
                              v603,
                              "lim_fill_pe_session");
                            v50 = 4;
                            goto LABEL_514;
                          }
                          if ( v621[0] != 2
                            && (*(_BYTE *)(v624 + 3426) && *(char *)(v624 + 3428) < 0
                             || *(_BYTE *)(v624 + 3422) && *(char *)(v624 + 3424) < 0) )
                          {
                            if ( (unsigned int)wlan_mlme_get_wmm_uapsd_mask(*(_QWORD *)(a1 + 21552), v620) )
                            {
                              v604 = "%s: Get uapsd_mask failed";
                              goto LABEL_503;
                            }
                            v605 = v620[0];
                          }
                          else
                          {
                            v605 = 0;
                          }
                          v12[249] = v605;
                          *(_BYTE *)(a1 + 13120 + 192LL * v578 + 20) = v605;
                        }
                        if ( v12[248] )
                          *((_WORD *)v12 + 125) = 0;
                        v50 = 0;
                        v12[261] = *(_BYTE *)(a1 + 17157);
                        v12[240] = *(_BYTE *)(a3 + 24);
                        goto LABEL_514;
                      }
                      v577 = 3;
                    }
                    *(_DWORD *)(a2 + 168) = v577;
                    v578 = v611;
                    v579 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 1061LL);
                    goto LABEL_487;
                  }
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Disable HT D-SMPS",
                    v529,
                    v530,
                    v531,
                    v532,
                    v533,
                    v534,
                    v535,
                    v536,
                    "lim_disable_ht_dynamic_smps");
                  *(_WORD *)(a2 + 7266) |= 0xCu;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Disable HE D-SMPS",
                    v537,
                    v538,
                    v539,
                    v540,
                    v541,
                    v542,
                    v543,
                    v544,
                    "lim_disable_he_dynamic_smps");
                  v527 = "%s: Disable HT and HE D-SMPS for this IOT AP";
                  *(_QWORD *)(v12 + 1657) &= ~0x400000000000uLL;
                }
                qdf_trace_msg(
                  0x35u,
                  8u,
                  v527,
                  v519,
                  v520,
                  v521,
                  v522,
                  v523,
                  v524,
                  v525,
                  v526,
                  "lim_cfg_dsmps_for_iot_ap");
                goto LABEL_452;
              }
LABEL_405:
              v12[2768] = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3452LL);
              goto LABEL_406;
            }
            if ( (v396[3426] || v396[3422]) && (*(_DWORD *)(a1 + 17140) != 2 || v396[1256]) )
            {
              v407 = 3;
            }
            else
            {
              if ( (*(_WORD *)(a3 + 18) & 0x200) == 0 )
              {
                v408 = *(unsigned __int8 *)(a2 + 154);
                if ( v408 == 5 )
                  goto LABEL_386;
                LODWORD(v407) = 1;
                goto LABEL_380;
              }
              if ( *(_BYTE *)(a1 + 17144) )
                v407 = 2;
              else
                v407 = 1;
            }
            v408 = *(unsigned __int8 *)(a2 + 154);
            if ( v408 == 5 )
            {
              if ( (_DWORD)v407 != 3 )
                goto LABEL_385;
LABEL_386:
              v409 = 0;
              v410 = 2;
              v407 = 3;
LABEL_395:
              *v12 = *v12 & 0xFC | v409 | v410;
              *(_BYTE *)(v398 + 24007) = v410 >> 1;
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: qos_type %d QOS %d WMM %d",
                v399,
                v400,
                v401,
                v402,
                v403,
                v404,
                v405,
                v406,
                "lim_update_qos",
                v407,
                *v12 & 1,
                (*v12 >> 1) & 1);
              goto LABEL_396;
            }
LABEL_380:
            if ( *(_DWORD *)(a1 + 17140) == 2 )
              v407 = 1;
            else
              v407 = (unsigned int)v407;
            if ( v408 != 8 || (_DWORD)v407 == 3 )
            {
              if ( (_DWORD)v407 == 3 )
              {
                v409 = 0;
                v410 = 2;
                goto LABEL_395;
              }
              if ( (_DWORD)v407 != 2 )
              {
                v409 = 0;
                v410 = 0;
                v407 = 1;
                goto LABEL_395;
              }
              goto LABEL_389;
            }
LABEL_385:
            if ( (_DWORD)v407 != 2 )
              goto LABEL_386;
LABEL_389:
            v410 = 0;
            v409 = 1;
            goto LABEL_395;
          }
          v244 = *((unsigned __int16 *)v234 + 707);
        }
        else
        {
          v244 = *((unsigned __int16 *)v234 + 1136);
        }
        if ( (~v244 & 0xC0) == 0 )
        {
          if ( (~v244 & 0x30) == 0 )
          {
            if ( (~v244 & 0xC) != 0 )
            {
LABEL_316:
              v245 = 2;
              goto LABEL_327;
            }
            goto LABEL_326;
          }
LABEL_324:
          v245 = 3;
          goto LABEL_327;
        }
LABEL_320:
        v245 = 4;
        goto LABEL_327;
      case 9u:
        if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v85 + 4392)) )
        {
          v128 = *(unsigned int *)(v85 + 4392);
          v126 = "%s: self Dot11mode is 11AC and bss freq %d is 6ghz";
          v127 = "lim_handle_11ac_only_dot11_mode";
          goto LABEL_222;
        }
        if ( v84[1408] && *((__int16 *)v84 + 707) != -1 && *((__int16 *)v84 + 709) != -1 )
          goto LABEL_169;
        v147 = v84[4876];
        if ( v147 )
        {
          if ( *((__int16 *)v84 + 2441) == -1 || *((__int16 *)v84 + 2443) == -1 )
            v147 = 0;
          else
LABEL_169:
            v147 = 1;
        }
        if ( (unsigned int)(v125 - 2) < 4 )
        {
          v126 = "%s: Self dot11mode 11AC only, bss dot11mode %d not compatible";
          v127 = "lim_handle_11ac_only_dot11_mode";
LABEL_221:
          v128 = (unsigned int)v125;
          goto LABEL_222;
        }
        v142 = v125;
        if ( v125 == 8 )
          goto LABEL_227;
        if ( (v147 & 1) != 0 )
          goto LABEL_224;
        v149 = "%s: Self dot11mode is 11AC ONLY peer is not VHT capable";
        v150 = "lim_handle_11ac_only_dot11_mode";
LABEL_202:
        qdf_trace_msg(0x35u, 2u, v149, v72, v73, v74, v75, v76, v77, v78, v79, v150);
        v50 = 16;
        goto LABEL_514;
      case 0xAu:
        v141 = v125;
        if ( ((1 << v125) & 0x1C) != 0 )
          goto LABEL_206;
        v142 = v125;
        if ( ((1 << v125) & 0x520) != 0 )
          goto LABEL_227;
        v126 = "%s: Invalid bss dot11mode %d passed";
        v127 = "lim_handle_11ax_dot11_mode";
        goto LABEL_221;
      case 0xBu:
        if ( (unsigned int)(v125 - 2) >= 4 )
        {
          v142 = v125;
          if ( v125 == 10 )
            goto LABEL_227;
        }
        v126 = "%s: Self dot11mode 11AX only, bss dot11mode %d not compatible";
        v127 = "lim_handle_11ax_only_dot11_mode";
        goto LABEL_221;
      case 0xCu:
        v141 = v125;
        if ( ((1 << v125) & 0x1C) != 0 )
          goto LABEL_206;
        v142 = v125;
        if ( ((1 << v125) & 0x520) != 0 )
          goto LABEL_227;
        v126 = "%s: Invalid bss dot11mode %d passed";
        v127 = "lim_handle_11be_dot11_mode";
        goto LABEL_221;
      case 0xDu:
        if ( ((1 << v125) & 0x53C) != 0 )
          v126 = "%s: Self dot11mode 11BE only, bss dot11mode %d not compatible";
        else
          v126 = "%s: Invalid bss dot11mode %d passed";
        v127 = "lim_handle_11be_only_dot11_mode";
        goto LABEL_221;
      default:
        goto LABEL_92;
    }
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: IE parsing failed vdev id %d",
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    "lim_fill_pe_session",
    *(unsigned __int8 *)(a2 + 10));
  v50 = 16;
LABEL_515:
  _ReadStatusReg(SP_EL0);
  return v50;
}
