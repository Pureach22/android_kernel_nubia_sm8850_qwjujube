__int64 __fastcall lim_fill_pe_session(__int64 a1, __int64 a2, __int64 a3, int a4, _DWORD *a5)
{
  unsigned __int64 v5; // x22
  __int64 v6; // x27
  unsigned __int8 *v11; // x28
  double updated; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w24
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x25
  __int64 v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x4
  __int64 v40; // x5
  __int64 v41; // x6
  __int64 v42; // x7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w25
  _BYTE *v52; // x8
  char _11h_power_constraint; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x8
  _BYTE *v63; // x22
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  _BYTE *v81; // x8
  __int64 v82; // x0
  unsigned __int8 v83; // w1
  int v84; // w8
  _BYTE *v85; // x23
  __int64 v86; // x22
  unsigned int v87; // w24
  _QWORD *vdev_by_id_from_pdev; // x0
  __int64 v89; // x25
  int *cmpt_obj; // x0
  unsigned int *v91; // x8
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  int v100; // w26
  unsigned int v101; // w9
  _BOOL4 v103; // w10
  bool v104; // zf
  int v105; // w8
  _BOOL4 v107; // w10
  bool v108; // zf
  char v109; // w9
  _QWORD *v110; // x0
  __int64 v111; // x25
  unsigned int vdev_wifi_std; // w0
  unsigned int *v113; // x8
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  unsigned int v122; // w26
  int v123; // w8
  unsigned __int8 v124; // w26
  int v125; // w8
  int v126; // w25
  __int64 v127; // x0
  __int64 v128; // x26
  char is_eht_allowed_for_current_security; // w27
  __int64 v130; // x0
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  __int64 v139; // x26
  unsigned __int16 v140; // w0
  int v141; // w8
  bool is_24ghz_ch_freq; // w0
  bool v143; // zf
  int v144; // w9
  const char *v145; // x2
  const char *v146; // x3
  unsigned int v147; // w8
  __int64 v148; // x4
  bool v149; // w9
  bool v150; // w9
  const char *v151; // x2
  const char *v152; // x3
  unsigned int v153; // w0
  bool v154; // w9
  int v156; // w22
  __int64 v157; // x0
  __int64 v158; // x22
  int param; // w0
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  char v168; // w4
  int cb_mode; // w22
  double v170; // d0
  double v171; // d1
  double v172; // d2
  double v173; // d3
  double v174; // d4
  double v175; // d5
  double v176; // d6
  double v177; // d7
  double v178; // d0
  double v179; // d1
  double v180; // d2
  double v181; // d3
  double v182; // d4
  double v183; // d5
  double v184; // d6
  double v185; // d7
  unsigned int v186; // w25
  bool v187; // w24
  __int64 v188; // x8
  char v189; // w9
  unsigned int v190; // w8
  __int64 v191; // x10
  int v192; // w9
  unsigned int v193; // w8
  bool v194; // w0
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  __int64 v203; // x8
  unsigned int v204; // w9
  _BYTE *v205; // x26
  __int64 v206; // x0
  double v207; // d0
  double v208; // d1
  double v209; // d2
  double v210; // d3
  double v211; // d4
  double v212; // d5
  double v213; // d6
  double v214; // d7
  unsigned __int8 *v215; // x22
  unsigned int v216; // w25
  int v217; // w28
  int v218; // w27
  __int64 v219; // x24
  _WORD *v220; // x19
  unsigned int v221; // w28
  int v222; // w23
  unsigned __int8 *v223; // x8
  _BYTE *v224; // x13
  unsigned int v225; // w11
  unsigned __int8 v226; // w14
  int v227; // w10
  int v228; // w11
  unsigned int v229; // w9
  unsigned int v230; // w11
  unsigned int v231; // w25
  int v232; // w8
  unsigned int v233; // w24
  __int16 v234; // w8
  double v235; // d0
  double v236; // d1
  double v237; // d2
  double v238; // d3
  double v239; // d4
  double v240; // d5
  double v241; // d6
  double v242; // d7
  __int64 v243; // x22
  _BYTE *v244; // x27
  unsigned int v245; // w0
  bool v246; // w0
  __int64 v247; // x9
  __int64 v248; // x8
  __int64 v249; // x9
  unsigned __int8 v250; // w8
  unsigned __int16 ielen_from_bss_description; // w19
  unsigned int v252; // w8
  _BOOL4 v253; // w9
  int v254; // w8
  int v255; // w8
  int v256; // w9
  int v257; // w10
  unsigned int v258; // w0
  bool v259; // w0
  unsigned int v260; // w8
  bool v261; // w0
  __int64 v262; // x8
  double v263; // d0
  double v264; // d1
  double v265; // d2
  double v266; // d3
  double v267; // d4
  double v268; // d5
  double v269; // d6
  double v270; // d7
  unsigned __int8 v271; // w0
  unsigned int v272; // w8
  char v273; // w0
  double v274; // d0
  double v275; // d1
  double v276; // d2
  double v277; // d3
  double v278; // d4
  double v279; // d5
  double v280; // d6
  double v281; // d7
  unsigned __int8 *v282; // x25
  double v283; // d0
  double v284; // d1
  double v285; // d2
  double v286; // d3
  double v287; // d4
  double v288; // d5
  double v289; // d6
  double v290; // d7
  double v291; // d0
  double v292; // d1
  double v293; // d2
  double v294; // d3
  double v295; // d4
  double v296; // d5
  double v297; // d6
  double v298; // d7
  double v299; // d0
  double v300; // d1
  double v301; // d2
  double v302; // d3
  double v303; // d4
  double v304; // d5
  double v305; // d6
  double v306; // d7
  int v307; // w8
  double v308; // d0
  double v309; // d1
  double v310; // d2
  double v311; // d3
  double v312; // d4
  double v313; // d5
  double v314; // d6
  double v315; // d7
  int v316; // w8
  __int64 ext_hdl; // x0
  __int64 v318; // x5
  unsigned int v319; // w10
  int v320; // w13
  int v321; // w16
  unsigned int v322; // w0
  int v323; // w8
  int v324; // w14
  int v325; // w12
  int v326; // w3
  unsigned int v327; // w13
  unsigned int v328; // w14
  unsigned int v329; // w15
  unsigned int v330; // w16
  int v331; // w0
  unsigned int v332; // w3
  int v333; // w15
  int v334; // w16
  int v335; // w14
  unsigned int v336; // w15
  unsigned int v337; // w17
  int v338; // w4
  int v339; // w0
  unsigned int v340; // w3
  int v341; // w4
  unsigned int v342; // w7
  int v343; // w2
  unsigned int v344; // w17
  unsigned int v345; // w3
  unsigned int v346; // w16
  unsigned int v347; // w17
  unsigned int v348; // w0
  int v349; // w2
  int v350; // w4
  unsigned int v351; // w22
  int v352; // w15
  int v353; // w16
  unsigned int v354; // w23
  int v355; // w2
  unsigned int v356; // w0
  unsigned int v357; // w4
  int v358; // w7
  unsigned int v359; // w23
  int v360; // w17
  int v361; // w3
  unsigned int v362; // w0
  unsigned int v363; // w16
  unsigned int v364; // w2
  int v365; // w4
  int v366; // w3
  unsigned int v367; // w7
  unsigned int v368; // w1
  unsigned int v369; // w2
  unsigned int v370; // w3
  int v371; // w4
  unsigned int v372; // w25
  char v373; // w1
  double v374; // d0
  double v375; // d1
  double v376; // d2
  double v377; // d3
  double v378; // d4
  double v379; // d5
  double v380; // d6
  double v381; // d7
  double v382; // d0
  double v383; // d1
  double v384; // d2
  double v385; // d3
  double v386; // d4
  double v387; // d5
  double v388; // d6
  double v389; // d7
  __int64 v390; // x0
  __int64 v391; // x24
  _BYTE *v392; // x0
  _BYTE *v393; // x24
  int v394; // w22
  __int64 v395; // x0
  double v396; // d0
  double v397; // d1
  double v398; // d2
  double v399; // d3
  double v400; // d4
  double v401; // d5
  double v402; // d6
  double v403; // d7
  __int64 v404; // x4
  int v405; // w8
  char v406; // w9
  unsigned int v407; // w8
  unsigned __int8 v408; // w8
  __int64 v409; // x0
  unsigned int v410; // w1
  __int64 psoc_ext_obj_fl; // x0
  double v412; // d0
  double v413; // d1
  double v414; // d2
  double v415; // d3
  double v416; // d4
  double v417; // d5
  double v418; // d6
  double v419; // d7
  __int64 v420; // x24
  __int64 v421; // x24
  char v422; // w25
  char is_ese_connection; // w0
  int v424; // w24
  int v425; // w25
  double v426; // d0
  double v427; // d1
  double v428; // d2
  double v429; // d3
  double v430; // d4
  double v431; // d5
  double v432; // d6
  double v433; // d7
  int v434; // w22
  double v435; // d0
  double v436; // d1
  double v437; // d2
  double v438; // d3
  double v439; // d4
  double v440; // d5
  double v441; // d6
  double v442; // d7
  int v443; // w4
  unsigned int v444; // w8
  double v445; // d0
  double v446; // d1
  double v447; // d2
  double v448; // d3
  double v449; // d4
  double v450; // d5
  double v451; // d6
  double v452; // d7
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  int v454; // w8
  double v455; // d0
  double v456; // d1
  double v457; // d2
  double v458; // d3
  double v459; // d4
  double v460; // d5
  double v461; // d6
  double v462; // d7
  char v463; // w22
  char v464; // w0
  int v465; // w9
  unsigned __int8 v466; // w10
  unsigned int v467; // w8
  __int16 v468; // w0
  double v469; // d0
  double v470; // d1
  double v471; // d2
  double v472; // d3
  double v473; // d4
  double v474; // d5
  double v475; // d6
  double v476; // d7
  char v477; // w9
  unsigned __int8 v478; // w8
  int v479; // w9
  unsigned __int8 v480; // w8
  __int64 v481; // x0
  __int64 v482; // x0
  __int64 v483; // x23
  unsigned int v484; // w0
  unsigned int ap_capability; // w0
  double v486; // d0
  double v487; // d1
  double v488; // d2
  double v489; // d3
  double v490; // d4
  double v491; // d5
  double v492; // d6
  double v493; // d7
  int v495; // w8
  __int64 v496; // x0
  double v497; // d0
  double v498; // d1
  double v499; // d2
  double v500; // d3
  double v501; // d4
  double v502; // d5
  double v503; // d6
  double v504; // d7
  double v505; // d0
  double v506; // d1
  double v507; // d2
  double v508; // d3
  double v509; // d4
  double v510; // d5
  double v511; // d6
  double v512; // d7
  unsigned int v513; // w8
  int v514; // w8
  __int64 v515; // x0
  double v516; // d0
  double v517; // d1
  double v518; // d2
  double v519; // d3
  double v520; // d4
  double v521; // d5
  double v522; // d6
  double v523; // d7
  const char *v524; // x2
  __int64 v525; // x10
  double v526; // d0
  double v527; // d1
  double v528; // d2
  double v529; // d3
  double v530; // d4
  double v531; // d5
  double v532; // d6
  double v533; // d7
  double v534; // d0
  double v535; // d1
  double v536; // d2
  double v537; // d3
  double v538; // d4
  double v539; // d5
  double v540; // d6
  double v541; // d7
  double v542; // d0
  double v543; // d1
  double v544; // d2
  double v545; // d3
  double v546; // d4
  double v547; // d5
  double v548; // d6
  double v549; // d7
  unsigned int v550; // w3
  double v551; // d0
  double v552; // d1
  double v553; // d2
  double v554; // d3
  double v555; // d4
  double v556; // d5
  double v557; // d6
  double v558; // d7
  int v559; // w1
  __int64 v560; // x0
  double v561; // d0
  double v562; // d1
  double v563; // d2
  double v564; // d3
  double v565; // d4
  double v566; // d5
  double v567; // d6
  double v568; // d7
  unsigned __int8 channel_reg_power_for_freq; // w0
  unsigned __int8 v570; // w8
  int v571; // w10
  unsigned __int8 max_tx_power; // w0
  unsigned int v573; // w22
  int v574; // w8
  unsigned int v575; // w22
  int v576; // w8
  int v577; // w9
  __int16 v578; // w2
  __int64 v579; // x0
  char is_mbssid_enabled; // w0
  int v581; // w8
  double v582; // d0
  double v583; // d1
  double v584; // d2
  double v585; // d3
  double v586; // d4
  double v587; // d5
  double v588; // d6
  double v589; // d7
  char v590; // w21
  char cfg_max_tx_power; // w0
  int v592; // w8
  double v593; // d0
  double v594; // d1
  double v595; // d2
  double v596; // d3
  double v597; // d4
  double v598; // d5
  double v599; // d6
  double v600; // d7
  const char *v601; // x2
  unsigned __int8 v602; // w8
  bool is_5ghz_ch_freq; // w0
  int v604; // [xsp+1Ch] [xbp-1A4h]
  _DWORD *v605; // [xsp+20h] [xbp-1A0h]
  unsigned int v606; // [xsp+28h] [xbp-198h]
  __int64 v607; // [xsp+30h] [xbp-190h]
  __int64 v608; // [xsp+30h] [xbp-190h]
  __int64 v609; // [xsp+38h] [xbp-188h]
  __int64 v610; // [xsp+40h] [xbp-180h]
  int v612; // [xsp+4Ch] [xbp-174h]
  _QWORD v613[4]; // [xsp+50h] [xbp-170h] BYREF
  int v614; // [xsp+74h] [xbp-14Ch] BYREF
  __int64 v615; // [xsp+78h] [xbp-148h] BYREF
  __int64 v616; // [xsp+80h] [xbp-140h]
  __int64 v617; // [xsp+88h] [xbp-138h]
  __int64 v618; // [xsp+90h] [xbp-130h]
  unsigned __int8 v619[4]; // [xsp+98h] [xbp-128h] BYREF
  char v620[4]; // [xsp+9Ch] [xbp-124h] BYREF
  char v621[4]; // [xsp+A0h] [xbp-120h] BYREF
  char v622[4]; // [xsp+A4h] [xbp-11Ch] BYREF
  __int64 v623; // [xsp+A8h] [xbp-118h] BYREF
  char v624[4]; // [xsp+B4h] [xbp-10Ch] BYREF
  unsigned __int8 *dest[33]; // [xsp+B8h] [xbp-108h] BYREF

  dest[31] = *(unsigned __int8 **)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned __int8 *)(a2 + 10);
  v6 = *(_QWORD *)(a1 + 8);
  v623 = 0;
  v622[0] = 0;
  v621[0] = 0;
  v620[0] = 0;
  v619[0] = 0;
  v617 = 0;
  v618 = 0;
  v615 = 0;
  v616 = 0;
  if ( v5 >= 7 )
    __break(0x5512u);
  v614 = 0;
  v11 = (unsigned __int8 *)(a2 + 7024);
  memset(v613, 0, sizeof(v613));
  updated = lim_update_rrm_capability();
  v20 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21632), *(_DWORD *)(a3 + 28), updated, v13, v14, v15, v16, v17, v18, v19);
  WORD2(dest[0]) = 0;
  LODWORD(dest[0]) = 0;
  qdf_mem_copy(dest, (const void *)(a2 + 24), 6u);
  v29 = *(_QWORD *)(a2 + 16);
  if ( v29 )
  {
    if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a2 + 16), v21, v22, v23, v24, v25, v26, v27, v28) & 1) != 0 )
    {
      v30 = *(_QWORD *)(v29 + 184);
      if ( v30 )
        qdf_mem_copy(dest, (const void *)(v30 + 792), 6u);
    }
  }
  if ( wlan_crypto_get_pmksa(*(_QWORD *)(a2 + 16), (__int64)dest, v21, v22, v23, v24, v25, v26, v27, v28) )
  {
    v39 = LOBYTE(dest[0]);
    v40 = BYTE1(dest[0]);
    v41 = BYTE2(dest[0]);
    v42 = BYTE5(dest[0]);
    v11[2984] = 1;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: PMKSA Found for BSSID=%02x:%02x:%02x:**:**:%02x",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "lim_update_sae_config",
      v39,
      v40,
      v41,
      v42);
  }
  if ( (wlan_crypto_get_param(*(_QWORD *)(a2 + 16), 7u) & 0x8000400) != 0
    && *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2564LL) == 1 )
  {
    wlan_mlme_set_sae_single_pmk_bss_cap(
      *(_QWORD *)(a1 + 21624),
      *(unsigned __int8 *)(a2 + 10),
      *(_DWORD *)(*(_QWORD *)(a2 + 112) + 4644LL) != 0);
  }
  lim_set_bcn_probe_filter(a1, a2, v20);
  v11[241] = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1302LL);
  *(_WORD *)(a2 + 7158) = *(_WORD *)(a3 + 16);
  *(_DWORD *)(a2 + 284) = *(_DWORD *)(a3 + 28);
  if ( !(unsigned int)wlan_get_parsed_bss_description_ies(a1, a3, &v623) )
  {
    qdf_mem_set((void *)(a2 + 1628), 0x14u, 0);
    v52 = (_BYTE *)v623;
    v606 = v5;
    if ( *(_BYTE *)(v623 + 3426) )
    {
      qdf_mem_copy((void *)(a2 + 1628), (const void *)(v623 + 3426), 0x14u);
      v52 = (_BYTE *)v623;
    }
    _11h_power_constraint = wlan_get_11h_power_constraint(a1, v52 + 830);
    v62 = *(_QWORD *)(a1 + 8);
    v63 = (_BYTE *)v623;
    LOBYTE(dest[0]) = 0;
    *(_BYTE *)(v62 + 4627) = _11h_power_constraint;
    v624[0] = 0;
    if ( v63 )
    {
      wlan_twt_cfg_get_support_requestor(*(_QWORD *)(a1 + 21624), v624);
      if ( v624[0] == 1 && ((v72 = *(_QWORD *)(v63 + 2253), v63[5192]) || (v72 & 4) != 0) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: TWT is supported, hence disable UAPSD; twt req supp: %d,twt respon supp: %d, QCN_IE: %d",
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          "lim_enable_twt",
          (*(_DWORD *)(*(_QWORD *)(a1 + 8) + 1309LL) >> 1) & 1,
          ((unsigned int)v72 >> 2) & 1);
        LOBYTE(v63) = 1;
      }
      else
      {
        wlan_twt_cfg_get_req_support_for_ht_vht(*(_QWORD *)(a1 + 21624), dest);
        if ( LOBYTE(dest[0]) == 1 && v63[1390] && (*((_WORD *)v63 + 700) & 0x4000) != 0 )
        {
          LOBYTE(v63) = 1;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: TWT is supported for 11n, twt_req_ht_vht %d, ext_cap %d, twt_responder support %d",
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            "lim_enable_twt",
            1);
        }
        else
        {
          LOBYTE(v63) = 0;
        }
      }
    }
    else
    {
      qdf_trace_msg(0x35u, 8u, "%s: ie is null", v54, v55, v56, v57, v58, v59, v60, v61, "lim_enable_twt");
    }
    v81 = (_BYTE *)v623;
    v11[3023] = (unsigned __int8)v63;
    if ( v81 )
    {
      v82 = *(_QWORD *)(a2 + 16);
      if ( *(_DWORD *)(v82 + 16) == 2 )
      {
        if ( (v81[2253] & 4) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: set P2P CLI in WFD R2 mode for id %d",
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            "lim_set_wfd_mode_for_p2p_cli",
            *(unsigned __int8 *)(a2 + 10));
          v82 = *(_QWORD *)(a2 + 16);
          v83 = 1;
        }
        else
        {
          v83 = -1;
        }
        wlan_vdev_set_wfd_mode(v82, v83);
      }
    }
    else
    {
      qdf_trace_msg(0x35u, 8u, "%s: ie is null", v73, v74, v75, v76, v77, v78, v79, v80, "lim_set_wfd_mode_for_p2p_cli");
    }
    v84 = *(_DWORD *)(a2 + 7036);
    v605 = a5;
    v85 = (_BYTE *)v623;
    v86 = *(_QWORD *)(a2 + 112);
    v87 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5964LL);
    if ( (v84 | 2) == 2 )
    {
      vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(a1 + 21632), *(_BYTE *)(a2 + 10), 0x43u);
      if ( vdev_by_id_from_pdev )
      {
        v89 = (__int64)vdev_by_id_from_pdev;
        cmpt_obj = (int *)wlan_vdev_mlme_get_cmpt_obj(
                            (__int64)vdev_by_id_from_pdev,
                            v73,
                            v74,
                            v75,
                            v76,
                            v77,
                            v78,
                            v79,
                            v80);
        if ( cmpt_obj )
        {
          v100 = *cmpt_obj;
          wlan_objmgr_vdev_release_ref(v89, 0x43u, v91, v92, v93, v94, v95, v96, v97, v98, v99);
          if ( v100 )
          {
            v101 = v87 & 0xFFFFFFFE;
            v103 = (v87 & 0xFFFFFFFD) == 5 || v101 == 8;
            v104 = v101 == 10 || v101 == 12;
            v105 = v104;
            if ( v104 )
              v103 = 1;
            if ( !v87 )
              v103 = 1;
            if ( v103 && v100 == 1 )
            {
              v87 = 5;
            }
            else
            {
              v107 = v101 == 8 || v101 == 10;
              if ( v87 )
                v108 = v101 == 12;
              else
                v108 = 1;
              if ( v108 )
                v107 = 1;
              v109 = v108;
              if ( v107 && v100 == 2 )
              {
                v87 = 8;
              }
              else
              {
                if ( !v87 )
                  v105 = 1;
                if ( v105 == 1 && v100 == 3 )
                {
                  v87 = 10;
                }
                else if ( ((unsigned __int8)v109 & (v100 == 4)) != 0 )
                {
                  v87 = 12;
                }
              }
            }
          }
        }
        else
        {
          wlan_objmgr_vdev_release_ref(v89, 0x43u, v91, v92, v93, v94, v95, v96, v97, v98, v99);
        }
      }
      v84 = *(_DWORD *)(a2 + 7036);
    }
    if ( (v84 | 2) == 2 )
    {
      v110 = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(a1 + 21632), *(_BYTE *)(a2 + 10), 0x43u);
      if ( v110 )
      {
        v111 = (__int64)v110;
        vdev_wifi_std = mlme_get_vdev_wifi_std((__int64)v110, v73, v74, v75, v76, v77, v78, v79, v80);
        if ( vdev_wifi_std > 3 )
        {
          v122 = 12;
        }
        else
        {
          v113 = dword_B35898;
          v122 = dword_B35898[vdev_wifi_std];
        }
        wlan_objmgr_vdev_release_ref(v111, 0x43u, v113, v114, v115, v116, v117, v118, v119, v120, v121);
        if ( v122 < v87 )
          v87 = v122;
      }
    }
    v123 = *(_DWORD *)(v86 + 4568);
    v124 = *(_BYTE *)(a2 + 10);
    if ( v123 )
    {
      if ( v123 == 1 )
      {
        v126 = 3;
LABEL_124:
        v141 = v126;
        switch ( v87 )
        {
          case 0u:
            goto LABEL_236;
          case 1u:
            if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v86 + 4576))
              && !wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(v86 + 4576)) )
            {
              v148 = *(unsigned int *)(v86 + 4576);
              v145 = "%s: self Dot11mode is 11ABG, BSS freq %d not 2.4 or 5 GHz";
              v146 = "lim_handle_11abg_dot11_mode";
              goto LABEL_357;
            }
            if ( ((1 << v126) & 0x1520) != 0 )
            {
              is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v86 + 4576));
              v141 = 2;
              v143 = !is_24ghz_ch_freq;
              v144 = 4;
              goto LABEL_129;
            }
            v141 = v126;
            if ( ((1 << v126) & 0x1C) == 0 )
            {
              v145 = "%s: Invalid bss dot11mode %d passed";
              v146 = "lim_handle_11abg_dot11_mode";
              goto LABEL_356;
            }
            goto LABEL_236;
          case 2u:
            if ( !wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(v86 + 4576)) )
            {
              v148 = *(unsigned int *)(v86 + 4576);
              v145 = "%s: self Dot11mode is 11A and bss freq %d not 5ghz";
              v146 = "lim_handle_11a_dot11_mode";
              goto LABEL_357;
            }
            if ( ((1 << v126) & 0x1524) != 0 )
              goto LABEL_146;
            if ( ((1 << v126) & 0x18) != 0 )
              v145 = "%s: Self dot11mode 11A, bss dot11mode %d not compatible";
            else
              v145 = "%s: Invalid bss dot11mode %d passed";
            v146 = "lim_handle_11a_dot11_mode";
            goto LABEL_356;
          case 3u:
            if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v86 + 4576)) )
            {
              v148 = *(unsigned int *)(v86 + 4576);
              v145 = "%s: self Dot11mode is 11B and bss freq %d not 2.4ghz";
              v146 = "lim_handle_11b_dot11_mode";
              goto LABEL_357;
            }
            if ( ((1 << v126) & 0x1538) != 0 )
              goto LABEL_149;
            if ( v126 == 2 )
            {
              v145 = "%s: Self dot11mode 11B, bss dot11mode %d not compatible";
              v146 = "lim_handle_11b_dot11_mode";
              goto LABEL_344;
            }
            v145 = "%s: Invalid bss dot11mode %d passed";
            v146 = "lim_handle_11b_dot11_mode";
            goto LABEL_356;
          case 4u:
            if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v86 + 4576)) )
            {
              v148 = *(unsigned int *)(v86 + 4576);
              v145 = "%s: self Dot11mode is 11G and bss freq %d not 2.4ghz";
              v146 = "lim_handle_11g_dot11_mode";
              goto LABEL_357;
            }
            if ( ((1 << v126) & 0x1530) != 0 )
              goto LABEL_159;
            if ( v126 == 2 )
            {
              v145 = "%s: Self dot11mode 11G, bss dot11mode %d not compatible";
              v146 = "lim_handle_11g_dot11_mode";
LABEL_344:
              v148 = 2;
              goto LABEL_357;
            }
            if ( v126 != 3 )
            {
              v145 = "%s: Invalid bss dot11mode %d passed";
              v146 = "lim_handle_11g_dot11_mode";
              goto LABEL_356;
            }
LABEL_149:
            v141 = 3;
            goto LABEL_236;
          case 5u:
            if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v86 + 4576)) )
            {
              v148 = *(unsigned int *)(v86 + 4576);
              v145 = "%s: self Dot11mode is 11N and bss freq %d is 6ghz";
              v146 = "lim_handle_11n_dot11_mode";
              goto LABEL_357;
            }
            v141 = v126;
            if ( ((1 << v126) & 0x3C) != 0 )
              goto LABEL_236;
            if ( ((1 << v126) & 0x1500) == 0 )
            {
              v145 = "%s: Invalid bss dot11mode %d passed";
              v146 = "lim_handle_11n_dot11_mode";
              goto LABEL_356;
            }
            if ( v85[1256] )
              goto LABEL_220;
            v153 = *(_DWORD *)(v86 + 4576);
            goto LABEL_552;
          case 6u:
            if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v86 + 4576)) )
            {
              v148 = *(unsigned int *)(v86 + 4576);
              v145 = "%s: self Dot11mode is 11G ONLY and bss freq %d not 2.4ghz";
              v146 = "lim_handle_11g_only_dot11_mode";
              goto LABEL_357;
            }
            if ( ((1 << v126) & 0x1530) != 0 )
              goto LABEL_159;
            if ( ((1 << v126) & 0xC) != 0 )
              v145 = "%s: Self dot11mode 11G only, bss dot11mode %d not compatible";
            else
              v145 = "%s: Invalid bss dot11mode %d passed";
            v146 = "lim_handle_11g_only_dot11_mode";
            goto LABEL_356;
          case 7u:
            if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v86 + 4576)) )
            {
              v148 = *(unsigned int *)(v86 + 4576);
              v145 = "%s: self Dot11mode is 11N ONLY and bss freq %d is 6ghz";
              v146 = "lim_handle_11n_only_dot11_mode";
              goto LABEL_357;
            }
            if ( ((1 << v126) & 0x1C) != 0 )
            {
              v145 = "%s: Self dot11mode 11N only, bss dot11mode %d not compatible";
            }
            else
            {
              if ( ((1 << v126) & 0x1500) != 0 )
              {
                if ( v85[1256] )
                  goto LABEL_220;
                v151 = "%s: Self dot11mode is 11N ONLY peer is not HT capable";
                v152 = "lim_handle_11n_only_dot11_mode";
LABEL_351:
                qdf_trace_msg(0x35u, 2u, v151, v73, v74, v75, v76, v77, v78, v79, v80, v152);
                v51 = 16;
                goto LABEL_470;
              }
              v141 = v126;
              if ( v126 == 5 )
                goto LABEL_236;
              v145 = "%s: Invalid bss dot11mode %d passed";
            }
            v146 = "lim_handle_11n_only_dot11_mode";
            goto LABEL_356;
          case 8u:
            if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v86 + 4576)) )
            {
              v148 = *(unsigned int *)(v86 + 4576);
              v145 = "%s: self Dot11mode is 11AC and bss freq %d is 6ghz";
              v146 = "lim_handle_11ac_dot11_mode";
              goto LABEL_357;
            }
            v154 = v85[1408] && *((__int16 *)v85 + 707) != -1 && *((__int16 *)v85 + 709) != -1
                || v85[4876] && *((__int16 *)v85 + 2441) != -1 && *((__int16 *)v85 + 2443) != -1;
            v141 = v126;
            if ( ((1 << v126) & 0x13C) != 0 )
              goto LABEL_236;
            if ( ((1 << v126) & 0x1400) == 0 )
            {
              v145 = "%s: Invalid bss dot11mode %d passed";
              v146 = "lim_handle_11ac_dot11_mode";
              goto LABEL_356;
            }
            if ( v154 )
              goto LABEL_224;
            if ( v85[1256] )
              goto LABEL_220;
            v153 = *(_DWORD *)(v86 + 4576);
LABEL_552:
            is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(v153);
            v141 = 4;
            v143 = !is_5ghz_ch_freq;
            v144 = 2;
LABEL_129:
            if ( !v143 )
              v141 = v144;
            goto LABEL_236;
          case 9u:
            if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v86 + 4576)) )
            {
              v148 = *(unsigned int *)(v86 + 4576);
              v145 = "%s: self Dot11mode is 11AC and bss freq %d is 6ghz";
              v146 = "lim_handle_11ac_only_dot11_mode";
              goto LABEL_357;
            }
            v150 = v85[1408] && *((__int16 *)v85 + 707) != -1 && *((__int16 *)v85 + 709) != -1
                || v85[4876] && *((__int16 *)v85 + 2441) != -1 && *((__int16 *)v85 + 2443) != -1;
            if ( v126 <= 7 )
            {
              v145 = "%s: Self dot11mode 11AC only, bss dot11mode %d not compatible";
              v146 = "lim_handle_11ac_only_dot11_mode";
              goto LABEL_356;
            }
            v141 = v126;
            if ( v126 == 8 )
              goto LABEL_236;
            if ( v150 )
            {
LABEL_224:
              v141 = 8;
              goto LABEL_236;
            }
            v151 = "%s: Self dot11mode is 11AC ONLY peer is not VHT capable";
            v152 = "lim_handle_11ac_only_dot11_mode";
            goto LABEL_351;
          case 0xAu:
            v149 = v85[1408] && *((__int16 *)v85 + 707) != -1 && *((__int16 *)v85 + 709) != -1
                || v85[4876] && *((__int16 *)v85 + 2441) != -1 && *((__int16 *)v85 + 2443) != -1;
            v141 = v126;
            if ( ((1 << v126) & 0x53C) != 0 )
              goto LABEL_236;
            if ( v126 != 12 )
            {
              v145 = "%s: Invalid bss dot11mode %d passed";
              v146 = "lim_handle_11ax_dot11_mode";
              goto LABEL_356;
            }
            if ( v85[2252] )
            {
              v149 = 1;
              v141 = 10;
            }
            else
            {
              v141 = 8;
            }
            if ( v149 )
              goto LABEL_236;
            if ( v85[1256] )
            {
LABEL_220:
              v141 = 5;
              goto LABEL_236;
            }
            if ( wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(v86 + 4576)) )
            {
LABEL_146:
              v141 = 2;
              goto LABEL_236;
            }
            if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v86 + 4576)) )
            {
LABEL_159:
              v141 = 4;
              goto LABEL_236;
            }
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Invalid bss dot11mode %d freq %d",
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              "lim_handle_11ax_dot11_mode",
              12,
              *(unsigned int *)(v86 + 4576));
            v51 = 16;
            goto LABEL_470;
          case 0xBu:
            if ( v126 <= 8 )
              goto LABEL_133;
            v141 = v126;
            if ( v126 == 10 )
              goto LABEL_236;
            if ( !v85[2252] )
            {
LABEL_133:
              v145 = "%s: Self dot11mode 11AX only, bss dot11mode %d not compatible";
              v146 = "lim_handle_11ax_only_dot11_mode";
              goto LABEL_356;
            }
            v141 = 10;
            goto LABEL_236;
          case 0xCu:
            v147 = v126 - 2;
            if ( (unsigned int)(v126 - 2) < 0xB && ((0x54Fu >> v147) & 1) != 0 )
            {
              v141 = dword_AFC12C[v147];
              goto LABEL_236;
            }
            v145 = "%s: Invalid bss dot11mode %d passed";
            v146 = "lim_handle_11be_dot11_mode";
            goto LABEL_356;
          case 0xDu:
            if ( ((1 << v126) & 0x53C) != 0 )
            {
              v145 = "%s: Self dot11mode 11BE only, bss dot11mode %d not compatible";
              goto LABEL_156;
            }
            v141 = v126;
            if ( v126 != 12 )
            {
              v145 = "%s: Invalid bss dot11mode %d passed";
LABEL_156:
              v146 = "lim_handle_11be_only_dot11_mode";
LABEL_356:
              v148 = (unsigned int)v126;
LABEL_357:
              qdf_trace_msg(0x35u, 2u, v145, v73, v74, v75, v76, v77, v78, v79, v80, v146, v148);
              v51 = 16;
              goto LABEL_470;
            }
LABEL_236:
            if ( v141 != 12 || (unsigned int)(a4 - 21) >= 0xA )
              v156 = v141;
            else
              v156 = 10;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: vdev id %d opmode %d self dot11mode %d bss_dot11 mode %d intersected %d bss phy mode %d",
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              "lim_fill_dot11_mode",
              *(unsigned __int8 *)(a2 + 10),
              *(unsigned int *)(a2 + 7036),
              v87,
              (unsigned int)v126,
              v156,
              a4);
            v157 = *(_QWORD *)(a2 + 16);
            if ( v156 != 12 && (*(_DWORD *)(v157 + 60) & 2) != 0 )
              goto LABEL_469;
            *(_BYTE *)(a2 + 154) = v156;
            if ( (unsigned __int8)v156 <= 0xCu && ((1 << v156) & 0x1520) != 0 )
            {
              v158 = *(_QWORD *)(a2 + 112);
              param = wlan_crypto_get_param(v157, 1u);
              if ( param != -1 && (param & 0x18003) != 0 )
              {
                if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v158 + 4576)) )
                  v168 = 4;
                else
                  v168 = 2;
                *(_BYTE *)(a2 + 154) = v168;
                qdf_trace_msg(
                  0x35u,
                  4u,
                  "%s: HT not supported with TKIP/WEP overriding dot11mode to %d",
                  v160,
                  v161,
                  v162,
                  v163,
                  v164,
                  v165,
                  v166,
                  v167,
                  "lim_verify_dot11_mode_with_crypto");
                v11[2944] = *(_BYTE *)(*(_QWORD *)(a2 + 8608) + 17240LL);
              }
            }
            cb_mode = wlan_get_cb_mode(a1, *(unsigned int *)(a2 + 284), v623, a2);
            if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 28))
              && (wlan_cm_get_force_20mhz_in_24ghz(*(_QWORD *)(a2 + 16), v170, v171, v172, v173, v174, v175, v176, v177)
                & 1) != 0 )
            {
              cb_mode = 0;
            }
            if ( (unsigned int)wlan_get_rate_set(a1, v623, a2) )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: Get rate failed vdev id %d",
                v178,
                v179,
                v180,
                v181,
                v182,
                v183,
                v184,
                v185,
                "lim_fill_pe_session",
                *(unsigned __int8 *)(a2 + 10));
              v186 = *(_DWORD *)(a3 + 28);
              v187 = wlan_reg_is_24ghz_ch_freq(v186);
              if ( v187 || wlan_reg_is_5ghz_ch_freq(v186) )
                wlan_populate_basic_rates(a2 + 252, !v187, 1);
            }
            v188 = *(_QWORD *)(a1 + 8);
            if ( *(_BYTE *)(a2 + 154) == 3 )
              v189 = 0;
            else
              v189 = *(_BYTE *)(v188 + 1304);
            v609 = a3;
            *(_BYTE *)(v188 + 5604) = v189;
            v190 = *(unsigned __int16 *)(a3 + 16);
            v191 = *(_QWORD *)(a1 + 8);
            v192 = 10 * v190;
            if ( v190 <= 0x32 )
              v192 = 500;
            if ( *(_WORD *)(a3 + 16) )
              v193 = v192;
            else
              v193 = *(_DWORD *)(v191 + 3688);
            if ( v193 >= *(_DWORD *)(v191 + 3688) )
              v193 = *(_DWORD *)(v191 + 3688);
            *(_DWORD *)(v191 + 3680) = v193;
            v194 = policy_mgr_will_freq_lead_to_mcc(*(_QWORD *)(a1 + 21624), *(_DWORD *)(a3 + 28));
            v203 = *(_QWORD *)(a1 + 8);
            v204 = 200;
            if ( v194 )
            {
              if ( *(_DWORD *)(v203 + 3680) / 5u <= 0xC8 )
                v204 = 200;
              else
                v204 = *(_DWORD *)(v203 + 3680) / 5u;
            }
            *(_DWORD *)(v203 + 3684) = v204;
            v205 = (_BYTE *)v623;
            v612 = cb_mode;
            v608 = v6;
            v206 = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a2 + 16), v195, v196, v197, v198, v199, v200, v201, v202);
            if ( v206 )
            {
              v215 = v11;
              v216 = *(_DWORD *)(a2 + 284);
              v217 = *(_DWORD *)(v206 + 48);
              v218 = *(_DWORD *)(v206 + 60);
              v219 = v206;
              v220 = v205 + 1257;
              if ( (*(_WORD *)(*(_QWORD *)(a1 + 8) + 1288LL) & 1) != 0
                && (wma_is_rx_ldpc_supported_for_channel(v216) & 1) != 0 )
              {
                v221 = v217 | 0x10;
                qdf_trace_msg(
                  0x34u,
                  8u,
                  "%s: LDPC enable for ch freq[%d]",
                  v207,
                  v208,
                  v209,
                  v210,
                  v211,
                  v212,
                  v213,
                  v214,
                  "lim_set_ldpc_exception",
                  v216);
                v222 = v218 & 0xFFFE | 1;
              }
              else
              {
                v222 = v218 & 0xFFFE;
                v221 = v217 & 0xFFFFFFEF;
                qdf_trace_msg(
                  0x34u,
                  8u,
                  "%s: LDPC disable for ch freq[%d]",
                  v207,
                  v208,
                  v209,
                  v210,
                  v211,
                  v212,
                  v213,
                  v214,
                  "lim_set_ldpc_exception",
                  v216);
              }
              *(_DWORD *)(v219 + 48) = v221;
              *(_DWORD *)(v219 + 60) = v222 | v218 & 0xFFFF0000;
              v223 = *(unsigned __int8 **)(a1 + 8);
              if ( v205[1408] )
              {
                v224 = v205 + 1408;
              }
              else if ( v205[4876] )
              {
                v224 = v205 + 4876;
              }
              else
              {
                v224 = nullptr;
              }
              v225 = v221 & 0xFFFF07FF | (v223[2827] << 12);
              v11 = v215;
              v226 = 0;
              if ( v223[2827] && v224 )
              {
                if ( v205[4868] )
                {
                  v226 = v223[2828];
                  if ( *(__int16 *)(v224 + 1) >= 0x2000 )
                  {
                    if ( v223[2828] >= (unsigned int)(*(unsigned __int16 *)(v224 + 1) >> 13) )
                      v226 = *(unsigned __int16 *)(v224 + 1) >> 13;
                    else
                      v226 = v223[2828];
                  }
                }
                else
                {
                  v226 = v223[2828];
                }
              }
              v227 = v223[2826];
              v228 = v225 | ((v226 & 7) << 13);
              if ( v227 == 1
                && (!v205[1408]
                 || *((__int16 *)v205 + 707) == -1
                 || *((__int16 *)v205 + 709) == -1
                 || (*(_WORD *)(v205 + 1409) & 0x1000) == 0)
                && (!v205[4876]
                 || *((__int16 *)v205 + 2441) == -1
                 || *((__int16 *)v205 + 2443) == -1
                 || (*(_WORD *)(v205 + 4877) & 0x1000) == 0) )
              {
                v229 = v228 & 0xFFF8F7FF;
              }
              else
              {
                v229 = v228 | (v227 << 11);
                v230 = v228 & 0xFFF8F7FF;
                if ( !v223[2826] )
                  v229 = v230;
              }
              if ( v223[2872] == 1 && (v229 & 0x1000) != 0 && (v205[1411] & 8) != 0 )
                v231 = v229 | 0x100000;
              else
                v231 = v229 & 0xFFEFFFFF;
              if ( (unsigned int)*(unsigned __int8 *)(a2 + 154) - 8 >= 6 && *(_BYTE *)(a2 + 154) )
              {
                v232 = *(_DWORD *)(a2 + 7036);
              }
              else
              {
                v232 = *(_DWORD *)(a2 + 7036);
                if ( v232 )
                  v231 &= ~0x1000u;
              }
              *(_DWORD *)(a2 + 7268) = v231;
              v233 = *(_DWORD *)(v219 + 60);
              *(_WORD *)(a2 + 7266) = v233;
              if ( !v232 )
              {
                v234 = v233;
                if ( (v233 & 0x20) != 0 )
                {
                  v234 = *v220 & 0x20 | v233 & 0xFFDF;
                  *(_WORD *)(a2 + 7266) = v234;
                }
                if ( (v234 & 0x40) != 0 )
                  *(_WORD *)(a2 + 7266) = *v220 & 0x40 | v234 & 0xFFBF;
              }
              if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 284)) )
                *(_DWORD *)(a2 + 7268) &= 0xFFFFFF9F;
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: HT cap 0x%x VHT cap 0x%x, AP cap sgi_20 %d sgi_40 %d",
                v235,
                v236,
                v237,
                v238,
                v239,
                v240,
                v241,
                v242,
                "lim_join_req_update_ht_vht_caps",
                v233,
                v231,
                ((unsigned __int16)*v220 >> 5) & 1,
                ((unsigned __int16)*v220 >> 6) & 1);
            }
            v243 = *(_QWORD *)(a2 + 112);
            v244 = (_BYTE *)v623;
            v245 = *(_DWORD *)(v243 + 4576);
            memset(dest, 0, 32);
            v246 = wlan_reg_is_24ghz_ch_freq(v245);
            v247 = 21594;
            if ( v246 )
              v247 = 21584;
            v248 = a1 + v247;
            if ( *(_DWORD *)(*(_QWORD *)(a2 + 16) + 16LL) == 2 )
              v249 = 3;
            else
              v249 = 0;
            v250 = *(_BYTE *)(v248 + v249);
            v11[1628] = v250;
            v11[1611] = v250;
            ielen_from_bss_description = wlan_get_ielen_from_bss_description(v243 + 4548);
            v252 = *(unsigned __int8 *)(a2 + 154);
            LODWORD(dest[1]) = ielen_from_bss_description;
            dest[0] = (unsigned __int8 *)(v243 + 4652);
            v253 = v252 < 0xE;
            dest[2] = (unsigned __int8 *)(v243 + 4550);
            if ( v252 - 10 >= 4 && v252 || !v244[2252] )
            {
              if ( (v253 & (0x3F01u >> v252)) == 0 || !v244[1408] )
              {
                if ( (v253 & (0x3FA1u >> v252)) != 0 && v244[1256] )
                {
                  if ( v244[1263] )
                    goto LABEL_338;
                  if ( v244[1262] )
                    goto LABEL_342;
                  if ( v244[1261] )
                    goto LABEL_334;
                }
LABEL_359:
                v255 = 1;
LABEL_360:
                v256 = (unsigned __int8)v244[1256];
                v257 = (unsigned __int8)v244[1408];
                LODWORD(dest[3]) = v255;
                v258 = *(_DWORD *)(v243 + 4576);
                BYTE4(dest[3]) = v256 != 0;
                BYTE5(dest[3]) = v257 != 0;
                v259 = wlan_reg_is_24ghz_ch_freq(v258);
                v260 = *(_DWORD *)(v243 + 4576);
                BYTE6(dest[3]) = v259;
                v261 = wlan_reg_is_5ghz_ch_freq(v260);
                v262 = *(_QWORD *)(a1 + 8);
                HIBYTE(dest[3]) = v261;
                if ( !*(_BYTE *)(v262 + 2871) )
                {
                  v11[1611] = 1;
                  v11[1628] = 1;
                }
                if ( (wlan_action_oui_search(*(_QWORD *)(a1 + 21624), dest, 2) & 1) != 0 )
                {
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: vdev: %d wmi_vdev_param_abg_mode_tx_chain_num 1",
                    v263,
                    v264,
                    v265,
                    v266,
                    v267,
                    v268,
                    v269,
                    v270,
                    "lim_check_oui_and_update_session",
                    *(unsigned __int8 *)(a2 + 10));
                  wma_cli_set_command(*(unsigned __int8 *)(a2 + 10), 117, 1, 1);
                }
                v271 = wlan_action_oui_search(*(_QWORD *)(a1 + 21624), dest, 4);
                if ( *(_DWORD *)(a1 + 17236) )
                {
                  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 1072LL) & v271 & 1) != 0 )
                  {
                    v272 = *(unsigned __int8 *)(a2 + 154);
                    if ( v272 <= 9 && ((1 << v272) & 0x301) != 0 )
                      *(_BYTE *)(a2 + 154) = 5;
                  }
                }
                v273 = wlan_action_oui_search(*(_QWORD *)(a1 + 21624), dest, 22);
                mlme_set_follow_ap_edca_flag(
                  *(_QWORD *)(a2 + 16),
                  v273 & 1,
                  v274,
                  v275,
                  v276,
                  v277,
                  v278,
                  v279,
                  v280,
                  v281);
                if ( (wlan_action_oui_search(*(_QWORD *)(a1 + 21624), dest, 19) & 1) != 0 )
                  mlme_set_reconn_after_assoc_timeout_flag(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a2 + 10), 1);
                if ( (wlan_action_oui_search(*(_QWORD *)(a1 + 21624), dest, 0) & 1) != 0 )
                {
                  v282 = dest[0];
                  if ( !wlan_get_vendor_ie_ptr_from_oui(&unk_B35EA8, 3u, dest[0], ielen_from_bss_description)
                    || !wlan_get_vendor_ie_ptr_from_oui(&unk_A0D8A8, 3u, v282, ielen_from_bss_description) )
                  {
                    goto LABEL_377;
                  }
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Vendor OUI 3 and Vendor OUI 4 found",
                    v283,
                    v284,
                    v285,
                    v286,
                    v287,
                    v288,
                    v289,
                    v290,
                    "lim_check_vendor_ap_3_present");
                }
                if ( (wlan_action_oui_search(*(_QWORD *)(a1 + 21624), dest, 5) & 1) == 0 )
                  goto LABEL_382;
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: 1x1 with 1 Chain AP",
                  v291,
                  v292,
                  v293,
                  v294,
                  v295,
                  v296,
                  v297,
                  v298,
                  "lim_check_oui_and_update_session");
LABEL_377:
                if ( !policy_mgr_is_hw_dbs_2x2_capable(*(_QWORD *)(a1 + 21624)) )
                {
                  v307 = *(_DWORD *)(a1 + 17236);
                  if ( v307 == 2 || v307 == 1 && *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1072LL) == 1 )
                  {
                    v11[1628] = 1;
                    *(_WORD *)(v11 + 1611) = 257;
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: For special ap, NSS: %d force 1x1 %d",
                      v299,
                      v300,
                      v301,
                      v302,
                      v303,
                      v304,
                      v305,
                      v306,
                      "lim_check_oui_and_update_session",
                      1,
                      *(unsigned int *)(a1 + 17236));
                  }
                }
LABEL_382:
                if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v243 + 4576))
                  && (wlan_action_oui_search(*(_QWORD *)(a1 + 21624), dest, 17) & 1) != 0 )
                {
                  *(_BYTE *)(a2 + 13281) = 1;
                }
                if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v243 + 4576))
                  && (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 2875LL) & 1) == 0 )
                {
                  v316 = *(unsigned __int8 *)(a2 + 154);
                  if ( v316 == 8 )
                  {
                    *(_BYTE *)(a2 + 154) = 5;
                    goto LABEL_397;
                  }
                }
                else
                {
                  v316 = *(unsigned __int8 *)(a2 + 154);
                }
                if ( v316 == 10 )
                {
                  ext_hdl = wlan_vdev_mlme_get_ext_hdl(
                              *(_QWORD *)(a2 + 16),
                              v308,
                              v309,
                              v310,
                              v311,
                              v312,
                              v313,
                              v314,
                              v315);
                  if ( ext_hdl )
                  {
                    v318 = *((unsigned __int16 *)v244 + 1136);
                    v319 = *(unsigned __int16 *)(ext_hdl + 23918);
                    v610 = ext_hdl + 20480;
                    v320 = (v319 >> 1) & 1;
                    v321 = (v319 >> 2) & 1;
                    v322 = ((unsigned int)v318 >> 2) & 1;
                    v604 = ((unsigned int)v318 >> 1) & v318 & 1 | (v319 >> 1) & v319 & 1;
                    v323 = v320 & ~(v318 & 1 | v319 & 1) & ((unsigned int)v318 >> 1);
                    v324 = (v319 >> 3) & 1;
                    v325 = (v320 ^ v319 & 1) & ~((unsigned int)v318 >> 1) & v318
                         | (((unsigned int)v318 >> 1) ^ v318) & ~(v319 >> 1) & v319 & 1;
                    v326 = v324 ^ v321;
                    v327 = v322 & ((unsigned int)v318 >> 3) | v321 & (v319 >> 3);
                    v328 = v324 & ~(v322 | v321) & ((unsigned int)v318 >> 3);
                    v329 = (((unsigned int)v318 >> 3) ^ ((unsigned int)v318 >> 2)) & ~(v319 >> 3) & v321;
                    v330 = v326 & ~((unsigned int)v318 >> 3) & ((unsigned int)v318 >> 2);
                    v331 = (v319 >> 4) & 1;
                    v332 = ((unsigned int)v318 >> 4) & 1;
                    v333 = v330 | v329;
                    v334 = (v319 >> 5) & 1;
                    v335 = v333 | (2 * (v328 | v327));
                    v336 = v332 & ((unsigned int)v318 >> 5) | v331 & (v319 >> 5);
                    v337 = (((unsigned int)v318 >> 5) ^ ((unsigned int)v318 >> 4)) & ~(v319 >> 5) & v331;
                    v338 = v334 ^ v331;
                    v339 = v332 | v331;
                    v340 = v338 & ~((unsigned int)v318 >> 5);
                    v341 = (v319 >> 6) & 1;
                    v342 = ((unsigned int)v318 >> 6) & 1;
                    v343 = (v319 >> 7) & 1;
                    v344 = v340 & ((unsigned int)v318 >> 4) | v337;
                    v345 = v342 & ((unsigned int)v318 >> 7) | v341 & (v319 >> 7);
                    v346 = v344 | (2 * (v334 & ~v339 & ((unsigned int)v318 >> 5) | v336));
                    v347 = (v343 ^ v341) & ~((unsigned int)v318 >> 7) & ((unsigned int)v318 >> 6)
                         | (((unsigned int)v318 >> 7) ^ ((unsigned int)v318 >> 6)) & ~(v319 >> 7) & v341;
                    v348 = v343 & ~(v342 | v341) & ((unsigned int)v318 >> 7) | v345;
                    v349 = (v319 >> 9) & 1;
                    v350 = (v319 >> 8) & 1;
                    v351 = ((unsigned int)v318 >> 8) & 1;
                    v352 = v346 | v336;
                    v353 = v347 | (2 * v348);
                    v354 = (v349 ^ v350) & ~((unsigned int)v318 >> 9);
                    v355 = v349 & ~(v351 | v350);
                    v356 = v351 & ((unsigned int)v318 >> 9) | v350 & (v319 >> 9);
                    v357 = v354 & ((unsigned int)v318 >> 8)
                         | (((unsigned int)v318 >> 9) ^ ((unsigned int)v318 >> 8)) & ~(v319 >> 9) & v350;
                    v358 = (v319 >> 10) & 1;
                    v359 = ((unsigned int)v318 >> 10) & 1;
                    v360 = v353 | v345;
                    v361 = (v319 >> 11) & 1;
                    v362 = v357 | (2 * (v355 & ((unsigned int)v318 >> 9) | v356)) | v356;
                    v363 = v359 & ((unsigned int)v318 >> 11) | v358 & (v319 >> 11);
                    v364 = (((unsigned int)v318 >> 11) ^ ((unsigned int)v318 >> 10)) & ~(v319 >> 11) & v358;
                    v365 = v361 ^ v358;
                    v366 = v361 & ~(v359 | v358);
                    v367 = ((unsigned int)v318 >> 14) & ((unsigned int)v318 >> 15) | (v319 >> 14) & (v319 >> 15);
                    v368 = v366 & ((unsigned int)v318 >> 11);
                    v369 = v365 & ~((unsigned int)v318 >> 11) & ((unsigned int)v318 >> 10) | v364;
                    v370 = v319 >> 13;
                    v371 = (v319 >> 12) & 1;
                    v372 = ((((v319 >> 14)
                            & 1
                            ^ (v319 >> 15))
                           & ~((unsigned int)v318 >> 15)
                           & ((unsigned int)v318 >> 14)
                           | (((unsigned int)v318 >> 14)
                            & 1
                            ^ ((unsigned int)v318 >> 15))
                           & ~(v319 >> 15)
                           & (v319 >> 14)
                           | (2
                            * ((v319 >> 15) & ~(((unsigned int)v318 >> 14) | (v319 >> 14)) & ((unsigned int)v318 >> 15)
                             | v367))
                           | v367) << 14)
                         | (16 * v352)
                         | (v360 << 6)
                         | (v362 << 8)
                         | ((v369 | (2 * (v368 | v363)) | v363) << 10)
                         | ((((v319 >> 13) & 1 ^ v371) & ~((unsigned int)v318 >> 13) & ((unsigned int)v318 >> 12)
                           | (((unsigned int)v318 >> 13) ^ ((unsigned int)v318 >> 12)) & ~v370 & v371
                           | (2
                            * ((v319 >> 13) & 1 & ~(((unsigned int)v318 >> 12) & 1 | v371) & ((unsigned int)v318 >> 13)
                             | ((unsigned int)v318 >> 12) & 1 & ((unsigned int)v318 >> 13)
                             | v371 & v370))
                           | ((unsigned int)v318 >> 12) & 1 & ((unsigned int)v318 >> 13)
                           | v371 & v370) << 12)
                         | v325
                         | (2 * (v323 | v604))
                         | (4 * (v335 | v327))
                         | v604;
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
                      *(unsigned __int16 *)(v610 + 3436),
                      v318,
                      v372,
                      (unsigned __int8)v244[4872]);
                    if ( v244[2252] )
                    {
                      if ( v372 == 0xFFFF && (v244[4872] || v244[1408]) )
                      {
                        *(_BYTE *)(a2 + 154) = 8;
                        qdf_trace_msg(
                          0x34u,
                          8u,
                          "%s: No common 11AX rate. Force 11AC connection",
                          v308,
                          v309,
                          v310,
                          v311,
                          v312,
                          v313,
                          v314,
                          v315,
                          "lim_handle_iot_ap_no_common_he_rates");
                      }
                    }
                  }
                }
LABEL_397:
                lim_update_eht_caps_mcs(a1, a2, v308, v309, v310, v311, v312, v313, v314, v315);
                v373 = wlan_get_vendor_ie_ptr_from_oui(&unk_B35EB4, 3u, dest[0], ielen_from_bss_description) != nullptr;
                wlan_mlme_set_ba_2k_jump_iot_ap(
                  *(_QWORD *)(a2 + 16),
                  v373,
                  v374,
                  v375,
                  v376,
                  v377,
                  v378,
                  v379,
                  v380,
                  v381);
                if ( wlan_get_vendor_ie_ptr_from_oui(&unk_AFC120, 4u, dest[0], ielen_from_bss_description) )
                {
                  if ( wlan_get_vendor_ie_ptr_from_oui(&unk_AFC125, 4u, dest[0], ielen_from_bss_description) )
                  {
                    v390 = wlan_vdev_mlme_get_ext_hdl(
                             *(_QWORD *)(a2 + 16),
                             v382,
                             v383,
                             v384,
                             v385,
                             v386,
                             v387,
                             v388,
                             v389);
                    if ( v390 )
                    {
                      v391 = v390;
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "%s: new htc he: %d",
                        v382,
                        v383,
                        v384,
                        v385,
                        v386,
                        v387,
                        v388,
                        v389,
                        "lim_update_he_caps_htc",
                        0);
                      *(_QWORD *)(v391 + 23897) &= ~1uLL;
                    }
                  }
                }
                v392 = *(_BYTE **)(a2 + 16);
                v393 = (_BYTE *)v623;
                v394 = *(unsigned __int8 *)(v623 + 3449);
                *(_BYTE *)(a2 + 30) = v392[74];
                *(_BYTE *)(a2 + 31) = v392[75];
                *(_BYTE *)(a2 + 32) = v392[76];
                *(_BYTE *)(a2 + 33) = v392[77];
                *(_BYTE *)(a2 + 34) = v392[78];
                *(_BYTE *)(a2 + 35) = v392[79];
                *(_WORD *)(a2 + 248) = 1;
                v395 = wlan_vdev_mlme_get_ext_hdl((__int64)v392, v382, v383, v384, v385, v386, v387, v388, v389);
                if ( !v395 )
                {
LABEL_429:
                  if ( *(_DWORD *)(*(_QWORD *)(a2 + 112) + 4636LL) )
                  {
                    v408 = *(_BYTE *)(v608 + 1978);
                    v11[18] = v408;
                  }
                  else
                  {
                    v408 = v11[18];
                  }
                  v409 = *(_QWORD *)(a1 + 21624);
                  v410 = *(unsigned __int8 *)(a2 + 10);
                  LOBYTE(v616) = v408;
                  wlan_cm_roam_cfg_set_value(v409, v410, 0x16u, (unsigned int *)&v615);
                  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(*(_QWORD *)(a1 + 21624));
                  if ( psoc_ext_obj_fl )
                  {
                    v420 = psoc_ext_obj_fl;
                    if ( (cm_is_auth_type_11r(
                            psoc_ext_obj_fl,
                            *(_QWORD *)(a2 + 16),
                            *(_BYTE *)(*(_QWORD *)(a2 + 112) + 4592LL) != 0)
                        & 1) != 0
                      && !cm_ese_open_present(*(_QWORD *)(a2 + 16), v420, v394 != 0) )
                    {
                      v11[17] = 1;
                    }
                  }
                  v421 = *(_QWORD *)(a1 + 21632);
                  v422 = *(_BYTE *)(a2 + 10);
                  is_ese_connection = cm_is_ese_connection(
                                        *(_QWORD *)(a2 + 16),
                                        v394 != 0,
                                        v412,
                                        v413,
                                        v414,
                                        v415,
                                        v416,
                                        v417,
                                        v418,
                                        v419);
                  wlan_cm_set_ese_assoc(v421, v422, is_ese_connection & 1);
                  wlan_cm_roam_cfg_get_value(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a2 + 10), 0xDu, v613);
                  v424 = v613[0];
                  wlan_cm_roam_cfg_get_value(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a2 + 10), 0x1Cu, v613);
                  v425 = v613[0];
                  if ( (wlan_cm_is_self_mld_roam_supported(
                          *(_QWORD *)(a1 + 21624),
                          v426,
                          v427,
                          v428,
                          v429,
                          v430,
                          v431,
                          v432,
                          v433)
                      & 1) != 0 )
                  {
                    wlan_cm_set_disable_hi_rssi(*(_QWORD *)(a1 + 21632), *(_BYTE *)(a2 + 10), 0);
                    v434 = v612;
                  }
                  else
                  {
                    v434 = v612;
                    if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v609 + 28))
                      && ((v443 = *(char *)(v609 + 24), v443 >= 0) ? (v444 = *(char *)(v609 + 24)) : (v444 = -v443),
                          v444 > v424 - v425) )
                    {
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "%s: Enabling HI_RSSI, rssi: %d lookup_th: %d, delta:%d",
                        v435,
                        v436,
                        v437,
                        v438,
                        v439,
                        v440,
                        v441,
                        v442,
                        "lim_fill_pe_session");
                      wlan_cm_set_disable_hi_rssi(*(_QWORD *)(a1 + 21632), *(_BYTE *)(a2 + 10), 0);
                    }
                    else
                    {
                      wlan_cm_set_disable_hi_rssi(*(_QWORD *)(a1 + 21632), *(_BYTE *)(a2 + 10), 1);
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "%s: Disabling HI_RSSI, AP freq=%d, rssi=%d",
                        v445,
                        v446,
                        v447,
                        v448,
                        v449,
                        v450,
                        v451,
                        v452,
                        "lim_fill_pe_session",
                        *(unsigned int *)(v609 + 28),
                        (unsigned int)*(char *)(v609 + 24));
                    }
                  }
                  if ( !*(_DWORD *)(a2 + 7036) )
                    v11[2768] = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3664LL);
                  vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(
                                             &unk_B35EAC,
                                             3u,
                                             (unsigned __int8 *)(v609 + 104),
                                             *(_WORD *)v609 - 102);
                  v454 = *(unsigned __int8 *)(a2 + 154);
                  v11[262] = vendor_ie_ptr_from_oui != nullptr;
                  *(_DWORD *)(a2 + 96) = *(_DWORD *)(v609 + 20);
                  v11[168] = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1299LL);
                  v11[169] = *(_BYTE *)(a1 + 17228);
                  if ( (unsigned int)(v454 - 8) >= 6 && v454 )
                  {
                    v11[146] = 0;
                  }
                  else
                  {
                    v11[146] = 1;
                    v11[163] = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2873LL);
                    v11[164] = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2874LL);
                  }
                  *(_DWORD *)(a2 + 7232) = *(_DWORD *)(v609 + 20);
                  handle_ht_capabilityand_ht_info(a1, (unsigned __int8 *)a2);
                  *(_DWORD *)(a2 + 164) = v434;
                  *(_BYTE *)(a2 + 160) = v434 != 0;
                  *(_BYTE *)(a2 + 161) = v434 != 0;
                  if ( v434 == 3 )
                  {
                    v463 = -2;
                  }
                  else
                  {
                    if ( v434 != 1 )
                    {
                      v466 = 0;
                      v465 = 0;
                      goto LABEL_455;
                    }
                    v463 = 2;
                  }
                  v464 = wlan_reg_freq_to_chan(
                           *(_QWORD *)(a1 + 21632),
                           *(_DWORD *)(a2 + 284),
                           v455,
                           v456,
                           v457,
                           v458,
                           v459,
                           v460,
                           v461,
                           v462);
                  v465 = 1;
                  v466 = v464 + v463;
LABEL_455:
                  v467 = *(unsigned __int8 *)(a2 + 154);
                  v11[150] = v466;
                  *(_DWORD *)(a2 + 7176) = v465;
                  *(_DWORD *)(a2 + 7180) = v465;
                  if ( v467 - 10 < 4 || !v467 )
                  {
                    lim_update_session_he_capable(a1, a2);
                    lim_copy_join_req_he_cap(a2);
                    v467 = *(unsigned __int8 *)(a2 + 154);
                  }
                  if ( v467 <= 0xD && ((1 << v467) & 0x3001) != 0 )
                  {
                    lim_update_session_eht_capable(a2, 1);
                    v468 = wlan_crypto_get_param(*(_QWORD *)(a2 + 16), 5u);
                    wlan_crypto_set_vdev_param(*(_QWORD *)(a2 + 16), 5u, v468 & 0xBFFF);
                    lim_copy_join_req_eht_cap(a2);
                  }
                  if ( (lim_get_vdev_rmf_capable(a1, a2) & 1) != 0 )
                    v477 = 16;
                  else
                    v477 = 0;
                  v478 = *v11 & 0xEF | v477;
                  v479 = v11[1611];
                  *v11 = v478;
                  v480 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1303LL);
                  *(_DWORD *)(a2 + 88) = 2;
                  v11[212] = v480;
                  if ( v479 == 1 )
                    v11[1629] = 1;
                  v481 = *(_QWORD *)(a2 + 16);
                  *(_WORD *)(a2 + 176) = *(_WORD *)(v609 + 18);
                  v482 = wlan_vdev_mlme_get_cmpt_obj(v481, v469, v470, v471, v472, v473, v474, v475, v476);
                  if ( !v482 )
                  {
LABEL_469:
                    v51 = 16;
                    goto LABEL_470;
                  }
                  v483 = v482;
                  v484 = wlan_get_ielen_from_bss_description(v609);
                  ap_capability = lim_extract_ap_capability(a1, v609 + 104, v484, a2 + 178, v11 + 248, v622, a2, v621);
                  if ( ap_capability )
                  {
                    v51 = ap_capability;
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "%s: extract ap caps failed %d",
                      v486,
                      v487,
                      v488,
                      v489,
                      v490,
                      v491,
                      v492,
                      v493,
                      "lim_fill_pe_session",
                      ap_capability);
                    goto LABEL_470;
                  }
                  memset(&dest[1], 0, 24);
                  v495 = (unsigned __int16)wlan_get_ielen_from_bss_description(v609);
                  v496 = *(_QWORD *)(a1 + 21624);
                  dest[0] = (unsigned __int8 *)(v609 + 104);
                  LODWORD(dest[1]) = v495;
                  if ( (wlan_action_oui_search(v496, dest, 21) & 1) != 0 )
                  {
                    *(_DWORD *)(a2 + 7268) &= 0xFFEFEFFF;
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: Disable Beamformee for IoT AP",
                      v497,
                      v498,
                      v499,
                      v500,
                      v501,
                      v502,
                      v503,
                      v504,
                      "lim_disable_bformee_for_iot_ap");
                  }
                  if ( *(_DWORD *)(a2 + 7036)
                    || wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v609 + 28))
                    && ((v513 = *(unsigned __int8 *)(a2 + 154), v513 > 0xD)
                     || ((1 << v513) & 0x3001) == 0
                     || a2 && !v11[3672]) )
                  {
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: Disable HT D-SMPS",
                      v497,
                      v498,
                      v499,
                      v500,
                      v501,
                      v502,
                      v503,
                      v504,
                      "lim_disable_ht_dynamic_smps");
                    *(_WORD *)(a2 + 7266) |= 0xCu;
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: Disable HE D-SMPS",
                      v505,
                      v506,
                      v507,
                      v508,
                      v509,
                      v510,
                      v511,
                      v512,
                      "lim_disable_he_dynamic_smps");
                    *(_QWORD *)(v11 + 1657) &= ~0x400000000000uLL;
                  }
                  memset(&dest[1], 0, 24);
                  v514 = (unsigned __int16)wlan_get_ielen_from_bss_description(v609);
                  v515 = *(_QWORD *)(a1 + 21624);
                  dest[0] = (unsigned __int8 *)(v609 + 104);
                  LODWORD(dest[1]) = v514;
                  if ( (wlan_action_oui_search(v515, dest, 27) & 1) != 0 )
                  {
                    v524 = "%s: Enable HT and HE D-SMPS for this IOT AP";
                    v525 = *(_QWORD *)(v11 + 1657) | 0x400000000000LL;
                    *(_WORD *)(a2 + 7266) = *(_WORD *)(a2 + 7266) & 0xFFF3 | 4;
                    *(_QWORD *)(v11 + 1657) = v525;
                  }
                  else
                  {
                    if ( (wlan_action_oui_is_empty(*(_QWORD *)(a1 + 21624), 27) & 1) == 0
                      || (wlan_action_oui_search(*(_QWORD *)(a1 + 21624), dest, 18) & 1) == 0 )
                    {
LABEL_489:
                      *(_BYTE *)(v483 + 948) = v621[0] ^ 1;
                      if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v609 + 28)) )
                      {
                        if ( !*(_BYTE *)(v623 + 322) )
                          qdf_trace_msg(
                            0x35u,
                            8u,
                            "%s: Channel is 6G but country IE not present",
                            v542,
                            v543,
                            v544,
                            v545,
                            v546,
                            v547,
                            v548,
                            v549,
                            "lim_fill_pe_session");
                        v550 = v11[3044];
                        if ( v550 == 2 )
                        {
                          if ( (wlan_reg_is_indoor_ap_detected(
                                  *(_QWORD *)(a1 + 21632),
                                  v542,
                                  v543,
                                  v544,
                                  v545,
                                  v546,
                                  v547,
                                  v548,
                                  v549)
                              & 1) != 0 )
                          {
                            v550 = 3;
                            v11[3044] = 3;
                          }
                          else
                          {
                            v550 = v11[3044];
                          }
                        }
                        if ( (unsigned int)wlan_reg_get_best_6g_power_type(
                                             *(_QWORD *)(a1 + 21624),
                                             *(_QWORD *)(a1 + 21632),
                                             (unsigned int *)&v614,
                                             v550,
                                             *(_DWORD *)(v609 + 28),
                                             v542,
                                             v543,
                                             v544,
                                             v545,
                                             v546,
                                             v547,
                                             v548,
                                             v549) )
                        {
                          v51 = 11;
                          if ( v605 )
                            *v605 = 23;
                          goto LABEL_470;
                        }
                        v559 = v614;
                        v560 = *(_QWORD *)(a2 + 16);
                        v11[3045] = v614;
                        mlme_set_best_6g_power_type(v560, v559, v551, v552, v553, v554, v555, v556, v557, v558);
                        memcpy(dest, (const void *)(v623 + 322), 0xF8u);
                        lim_iterate_triplets(dest);
                        if ( !*(_WORD *)(v623 + 1430) || !*(_BYTE *)(v623 + 1432) )
                          qdf_trace_msg(
                            0x35u,
                            8u,
                            "%s: TPE not present for 6G channel",
                            v542,
                            v543,
                            v544,
                            v545,
                            v546,
                            v547,
                            v548,
                            v549,
                            "lim_fill_pe_session");
                      }
                      if ( (wlan_reg_is_ext_tpc_supported(
                              *(_QWORD *)(a1 + 21624),
                              v542,
                              v543,
                              v544,
                              v545,
                              v546,
                              v547,
                              v548,
                              v549)
                          & 1) != 0 )
                      {
                        *(_BYTE *)(v483 + 568) = v622[0];
                      }
                      else
                      {
                        channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(
                                                       *(_QWORD *)(a1 + 21632),
                                                       *(_DWORD *)(a2 + 284),
                                                       v561,
                                                       v562,
                                                       v563,
                                                       v564,
                                                       v565,
                                                       v566,
                                                       v567,
                                                       v568);
                        v570 = v622[0];
                        if ( v621[0] )
                          v570 = channel_reg_power_for_freq - v622[0];
                        v571 = v570;
                        if ( !v570 )
                          v570 = channel_reg_power_for_freq;
                        if ( !v571 || v621[0] )
                          v622[0] = v570;
                        *(_BYTE *)(v483 + 552) = channel_reg_power_for_freq;
                        *(_BYTE *)(v483 + 568) = v570;
                        *(_DWORD *)(v483 + 572) = *(_DWORD *)(a2 + 284);
                        max_tx_power = lim_get_max_tx_power(a1, v483);
                        v11[8] = max_tx_power;
                        v11[3018] = max_tx_power;
                      }
                      if ( *(_DWORD *)(a2 + 88) == 2 && !v11[8] )
                        v11[8] = wlan_reg_get_channel_reg_power_for_freq(
                                   *(_QWORD *)(a1 + 21632),
                                   *(_DWORD *)(a2 + 284),
                                   v561,
                                   v562,
                                   v563,
                                   v564,
                                   v565,
                                   v566,
                                   v567,
                                   v568);
                      v573 = *(_DWORD *)(a2 + 284);
                      if ( wlan_reg_is_6ghz_chan_freq(v573) )
                      {
                        v574 = 2;
                      }
                      else if ( wlan_reg_is_5ghz_ch_freq(v573) )
                      {
                        v574 = 1;
                      }
                      else
                      {
                        if ( wlan_reg_is_24ghz_ch_freq(v573) )
                        {
                          v575 = v606;
                          v576 = 0;
                          *(_DWORD *)(a2 + 168) = 0;
LABEL_524:
                          v577 = *(_DWORD *)(a2 + 80);
                          v578 = *(_WORD *)(a2 + 8);
                          *(_DWORD *)(a2 + 7028) = v576;
                          *(_DWORD *)(a2 + 80) = 3;
                          *(_DWORD *)(a2 + 84) = v577;
                          v579 = qdf_trace(53, 1u, v578, 3);
                          is_mbssid_enabled = wma_is_mbssid_enabled(v579);
                          v581 = v11[1610];
                          v11[3020] = is_mbssid_enabled & 1;
                          if ( v581 && (lim_isconnected_on_dfs_freq(a1, *(unsigned int *)(a2 + 284)) & 1) != 0 )
                            v11[170] = 1;
                          if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1061LL) == 1
                            && (*(_WORD *)(v609 + 18) & 0x100) != 0
                            && !*(_DWORD *)(v609 + 20) )
                          {
                            v11[170] = 1;
                          }
                          v590 = 24;
                          if ( (char)wlan_get_cfg_max_tx_power(
                                       *(_QWORD *)(a1 + 21624),
                                       *(_QWORD *)(a1 + 21632),
                                       *(_DWORD *)(v609 + 28)) <= 23 )
                          {
                            cfg_max_tx_power = wlan_get_cfg_max_tx_power(
                                                 *(_QWORD *)(a1 + 21624),
                                                 *(_QWORD *)(a1 + 21632),
                                                 *(_DWORD *)(v609 + 28));
                            if ( cfg_max_tx_power )
                              v590 = cfg_max_tx_power;
                            else
                              v590 = 24;
                          }
                          v592 = (char)v11[8];
                          if ( v590 < v592 )
                            LOBYTE(v592) = v590;
                          v11[10] = v592;
                          v11[9] = 8;
                          qdf_trace_msg(
                            0x35u,
                            8u,
                            "%s: Min session tx power: %d",
                            v582,
                            v583,
                            v584,
                            v585,
                            v586,
                            v587,
                            v588,
                            v589,
                            "lim_fill_pe_session",
                            8);
                          if ( (v11[3023] & 1) == 0 )
                          {
                            if ( (unsigned int)wlan_mlme_get_wmm_mode(*(_QWORD *)(a1 + 21624), v620) )
                            {
                              v601 = "%s: Get wmm_mode failed";
LABEL_540:
                              qdf_trace_msg(
                                0x35u,
                                2u,
                                v601,
                                v593,
                                v594,
                                v595,
                                v596,
                                v597,
                                v598,
                                v599,
                                v600,
                                "lim_fill_pe_session");
                              v51 = 4;
LABEL_470:
                              _qdf_mem_free(v623);
                              goto LABEL_471;
                            }
                            if ( v620[0] != 2
                              && (*(_BYTE *)(v623 + 3426) && *(char *)(v623 + 3428) < 0
                               || *(_BYTE *)(v623 + 3422) && *(char *)(v623 + 3424) < 0) )
                            {
                              if ( (unsigned int)wlan_mlme_get_wmm_uapsd_mask(*(_QWORD *)(a1 + 21624), v619) )
                              {
                                v601 = "%s: Get uapsd_mask failed";
                                goto LABEL_540;
                              }
                              v602 = v619[0];
                            }
                            else
                            {
                              v602 = 0;
                            }
                            v11[249] = v602;
                            *(_BYTE *)(a1 + 13192 + 192LL * v575 + 20) = v602;
                          }
                          if ( v11[248] )
                            *((_WORD *)v11 + 125) = 0;
                          v51 = 0;
                          v11[261] = *(_BYTE *)(a1 + 17229);
                          v11[240] = *(_BYTE *)(v609 + 24);
                          goto LABEL_470;
                        }
                        v574 = 3;
                      }
                      *(_DWORD *)(a2 + 168) = v574;
                      v575 = v606;
                      v576 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 1061LL);
                      goto LABEL_524;
                    }
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: Disable HT D-SMPS",
                      v526,
                      v527,
                      v528,
                      v529,
                      v530,
                      v531,
                      v532,
                      v533,
                      "lim_disable_ht_dynamic_smps");
                    *(_WORD *)(a2 + 7266) |= 0xCu;
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: Disable HE D-SMPS",
                      v534,
                      v535,
                      v536,
                      v537,
                      v538,
                      v539,
                      v540,
                      v541,
                      "lim_disable_he_dynamic_smps");
                    v524 = "%s: Disable HT and HE D-SMPS for this IOT AP";
                    *(_QWORD *)(v11 + 1657) &= ~0x400000000000uLL;
                  }
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    v524,
                    v516,
                    v517,
                    v518,
                    v519,
                    v520,
                    v521,
                    v522,
                    v523,
                    "lim_cfg_dsmps_for_iot_ap");
                  goto LABEL_489;
                }
                if ( (v393[3426] || v393[3422]) && (*(_DWORD *)(a1 + 17212) != 2 || v393[1256]) )
                {
                  v404 = 3;
                }
                else
                {
                  if ( (*(_WORD *)(v609 + 18) & 0x200) == 0 )
                  {
                    v405 = *(unsigned __int8 *)(a2 + 154);
                    if ( v405 == 5 )
                      goto LABEL_419;
                    LODWORD(v404) = 1;
                    goto LABEL_413;
                  }
                  if ( *(_BYTE *)(a1 + 17216) )
                    v404 = 2;
                  else
                    v404 = 1;
                }
                v405 = *(unsigned __int8 *)(a2 + 154);
                if ( v405 == 5 )
                {
                  if ( (_DWORD)v404 != 3 )
                    goto LABEL_418;
LABEL_419:
                  v406 = 0;
                  v407 = 2;
                  v404 = 3;
LABEL_428:
                  *v11 = *v11 & 0xFC | v406 | v407;
                  *(_BYTE *)(v395 + 24007) = v407 >> 1;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: qos_type %d QOS %d WMM %d",
                    v396,
                    v397,
                    v398,
                    v399,
                    v400,
                    v401,
                    v402,
                    v403,
                    "lim_update_qos",
                    v404,
                    *v11 & 1,
                    (*v11 >> 1) & 1);
                  goto LABEL_429;
                }
LABEL_413:
                if ( *(_DWORD *)(a1 + 17212) == 2 )
                  v404 = 1;
                else
                  v404 = (unsigned int)v404;
                if ( v405 != 8 || (_DWORD)v404 == 3 )
                {
                  if ( (_DWORD)v404 == 3 )
                  {
                    v406 = 0;
                    v407 = 2;
                    goto LABEL_428;
                  }
                  if ( (_DWORD)v404 != 2 )
                  {
                    v406 = 0;
                    v407 = 0;
                    v404 = 1;
                    goto LABEL_428;
                  }
                  goto LABEL_422;
                }
LABEL_418:
                if ( (_DWORD)v404 != 2 )
                  goto LABEL_419;
LABEL_422:
                v407 = 0;
                v406 = 1;
                goto LABEL_428;
              }
              v254 = *((unsigned __int16 *)v244 + 707);
            }
            else
            {
              v254 = *((unsigned __int16 *)v244 + 1136);
            }
            if ( (~v254 & 0xC0) == 0 )
            {
              if ( (~v254 & 0x30) == 0 )
              {
                if ( (~v254 & 0xC) != 0 )
                {
LABEL_334:
                  v255 = 2;
                  goto LABEL_360;
                }
                goto LABEL_359;
              }
LABEL_342:
              v255 = 3;
              goto LABEL_360;
            }
LABEL_338:
            v255 = 4;
            goto LABEL_360;
          default:
            v145 = "%s: Invalid self dot11mode %d not supported";
            v146 = "lim_get_intersected_dot11_mode_sta_ap";
            v148 = v87;
            goto LABEL_357;
        }
      }
      if ( v123 == 2 )
      {
        v125 = 4;
      }
      else if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v86 + 4576)) )
      {
        v125 = 4;
      }
      else
      {
        v125 = 2;
      }
    }
    else
    {
      v125 = 2;
    }
    if ( v85[1256] )
      v125 = 5;
    if ( v85[1408] && *((__int16 *)v85 + 707) != -1 && *((__int16 *)v85 + 709) != -1
      || v85[4876] && *((__int16 *)v85 + 2441) != -1 && *((__int16 *)v85 + 2443) != -1 )
    {
      v125 = 8;
    }
    if ( v85[2252] )
      v126 = 10;
    else
      v126 = v125;
    if ( v85[2496] )
    {
      v607 = v6;
      v127 = wlan_scan_entry_by_bssid_and_security(*(_QWORD *)(a1 + 21632), (unsigned __int8 *)(v86 + 4550), v124);
      if ( !v127 )
        goto LABEL_119;
      v128 = v127;
      is_eht_allowed_for_current_security = wlan_cm_is_eht_allowed_for_current_security(
                                              *(_QWORD *)(*(_QWORD *)(a1 + 21632) + 80LL),
                                              v127,
                                              0);
      if ( *(_QWORD *)(v128 + 1320) )
        _qdf_mem_free(*(_QWORD *)(v128 + 1320));
      v130 = *(_QWORD *)(v128 + 1896);
      if ( v130 )
        _qdf_mem_free(v130);
      _qdf_mem_free(v128);
      if ( (is_eht_allowed_for_current_security & 1) == 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Downgrade to 11ax mode due to AP security validation failure",
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          v137,
          v138,
          "lim_get_bss_11be_mode_allowed");
      }
      else
      {
LABEL_119:
        v139 = *(_QWORD *)(a1 + 21624);
        v140 = wlan_get_ielen_from_bss_description(v86 + 4548);
        if ( (mlme_get_bss_11be_allowed(v139, (unsigned __int8 *)(v86 + 4550), v86 + 4652, v140) & 1) != 0 )
          v126 = 12;
      }
      v6 = v607;
    }
    goto LABEL_124;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: IE parsing failed vdev id %d",
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    "lim_fill_pe_session",
    *(unsigned __int8 *)(a2 + 10));
  v51 = 16;
LABEL_471:
  _ReadStatusReg(SP_EL0);
  return v51;
}
