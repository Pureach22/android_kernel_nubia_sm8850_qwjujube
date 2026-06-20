__int64 __fastcall _scm_handle_bcn_probe(unsigned int *a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x22
  unsigned __int8 *v13; // x25
  __int64 pdev_by_id; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 comp_private_obj; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  __int64 v33; // x23
  char v34; // w9
  int v35; // w10
  unsigned int is_valid_rsn_present; // w24
  const char *v37; // x2
  unsigned int *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  int v51; // w9
  _QWORD *v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  _DWORD *v61; // x27
  __int64 v62; // x4
  __int64 v63; // x5
  __int64 v64; // x6
  __int64 v65; // x7
  int v66; // w21
  int v67; // w28
  unsigned __int8 *v68; // x26
  int v69; // w9
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
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x3
  __int64 v95; // x4
  __int64 v96; // x5
  __int64 v97; // x6
  long double v98; // q0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned int v106; // w0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  __int64 v114; // x21
  __int64 v115; // x4
  __int64 v116; // x5
  __int64 v117; // x6
  __int64 v118; // x7
  __int64 v119; // x3
  __int64 v120; // x4
  __int64 v121; // x5
  __int64 v122; // x6
  __int64 v123; // x3
  __int64 v124; // x4
  __int64 v125; // x5
  __int64 v126; // x6
  __int64 v127; // x0
  __int64 v128; // x0
  __int64 v129; // x21
  __int64 v130; // x4
  __int64 v131; // x5
  __int64 v132; // x6
  __int64 v133; // x7
  __int64 v134; // x21
  __int64 v135; // x4
  __int64 v136; // x5
  __int64 v137; // x6
  __int64 v138; // x7
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  void (__fastcall *v146)(__int64, unsigned __int8 *); // x8
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  unsigned int best_6g_power_type; // w0
  __int64 v156; // x21
  __int64 v157; // x4
  __int64 v158; // x5
  __int64 v159; // x6
  __int64 v160; // x7
  unsigned int v161; // w21
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  char v170; // w22
  __int64 v171; // x0
  __int64 v172; // x8
  __int64 v173; // x24
  __int64 v174; // x0
  double v175; // d0
  double v176; // d1
  double v177; // d2
  double v178; // d3
  double v179; // d4
  double v180; // d5
  double v181; // d6
  double v182; // d7
  unsigned __int8 v183; // w21
  _QWORD *v184; // x21
  __int64 v185; // x1
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  __int64 v194; // x4
  __int64 v195; // x5
  __int64 v196; // x6
  __int64 v197; // x7
  double v198; // d0
  double v199; // d1
  double v200; // d2
  double v201; // d3
  double v202; // d4
  double v203; // d5
  double v204; // d6
  double v205; // d7
  __int64 v206; // x0
  __int64 v207; // x8
  __int64 next_node; // x22
  long double v209; // q0
  double v210; // d1
  double v211; // d2
  double v212; // d3
  double v213; // d4
  double v214; // d5
  double v215; // d6
  double v216; // d7
  double v217; // d0
  double v218; // d1
  double v219; // d2
  double v220; // d3
  double v221; // d4
  double v222; // d5
  double v223; // d6
  double v224; // d7
  char v225; // w22
  int v226; // w3
  unsigned int v227; // w0
  unsigned __int8 v228; // w8
  unsigned int v229; // w21
  const char *v230; // x3
  const char *v231; // x4
  const char *v232; // x5
  const char *v233; // x6
  const char *v234; // x7
  int v235; // w0
  int v236; // w0
  int v237; // w0
  int v238; // w0
  const char *v239; // x3
  void (__fastcall *v240)(__int64, unsigned __int8 *); // x8
  __int64 v241; // x27
  __int64 v242; // x23
  _QWORD *v243; // x21
  __int64 v244; // x28
  __int64 v245; // x8
  unsigned int v248; // w9
  __int64 v249; // x8
  __int64 v250; // x22
  unsigned __int64 v251; // x22
  __int64 v252; // x25
  double v253; // d0
  double v254; // d1
  double v255; // d2
  double v256; // d3
  double v257; // d4
  double v258; // d5
  double v259; // d6
  double v260; // d7
  unsigned int v263; // w9
  __int64 v264; // x8
  unsigned int v265; // w21
  unsigned int v266; // w28
  unsigned __int8 *v267; // x28
  int v268; // w9
  __int64 v269; // x21
  __int64 v270; // x4
  __int64 v271; // x5
  __int64 v272; // x6
  __int64 v273; // x7
  int v274; // w9
  int v275; // w10
  unsigned __int8 *i; // x8
  int v277; // t1
  __int64 v278; // x22
  __int64 v279; // x0
  double v280; // d0
  double v281; // d1
  double v282; // d2
  double v283; // d3
  double v284; // d4
  double v285; // d5
  double v286; // d6
  double v287; // d7
  double v288; // d0
  double v289; // d1
  double v290; // d2
  double v291; // d3
  double v292; // d4
  double v293; // d5
  double v294; // d6
  double v295; // d7
  double v296; // d0
  double v297; // d1
  double v298; // d2
  double v299; // d3
  double v300; // d4
  double v301; // d5
  double v302; // d6
  double v303; // d7
  const char *v304; // x2
  __int64 v305; // x8
  __int64 v306; // x0
  __int64 v307; // x21
  char v308; // w8
  _QWORD *v309; // x0
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
  __int64 v326; // x0
  unsigned int v327; // w1
  const char *v328; // x2
  __int64 v329; // x8
  __int64 v330; // x4
  __int64 v331; // x5
  __int64 v332; // x6
  __int64 v333; // x7
  void (__fastcall *v334)(__int64, unsigned __int8 *); // x8
  int v335; // w9
  int v336; // w10
  unsigned __int8 *j; // x8
  int v338; // t1
  __int64 system_time; // x0
  __int64 v340; // x8
  size_t v341; // x2
  int v342; // w8
  _QWORD *v343; // x21
  unsigned __int64 v344; // x12
  __int64 he_6g_params; // x0
  int v346; // w8
  int v347; // w9
  int v348; // w9
  unsigned __int8 *v349; // x1
  void *v350; // x0
  int v351; // w21
  double v352; // d0
  double v353; // d1
  double v354; // d2
  double v355; // d3
  double v356; // d4
  double v357; // d5
  double v358; // d6
  double v359; // d7
  unsigned int v360; // w21
  int v361; // w9
  int v362; // w10
  __int64 v363; // x8
  int v364; // w10
  int v365; // w9
  int v366; // w10
  int v367; // w9
  __int64 v368; // x9
  unsigned __int64 v369; // x8
  unsigned int v372; // w10
  unsigned int v379; // w9
  const char *v380; // x2
  __int64 v381; // [xsp+0h] [xbp-280h]
  __int64 v382; // [xsp+8h] [xbp-278h]
  __int64 v383; // [xsp+10h] [xbp-270h]
  __int64 v384; // [xsp+18h] [xbp-268h]
  __int64 v385; // [xsp+20h] [xbp-260h]
  __int64 v386; // [xsp+28h] [xbp-258h]
  __int64 v387; // [xsp+30h] [xbp-250h]
  __int64 v388; // [xsp+38h] [xbp-248h]
  __int64 v389; // [xsp+40h] [xbp-240h]
  __int64 v390; // [xsp+48h] [xbp-238h]
  __int64 v391; // [xsp+60h] [xbp-220h]
  int v392; // [xsp+68h] [xbp-218h]
  unsigned __int64 v393; // [xsp+68h] [xbp-218h]
  char v394; // [xsp+70h] [xbp-210h]
  _DWORD *v395; // [xsp+70h] [xbp-210h]
  __int64 v396; // [xsp+78h] [xbp-208h]
  unsigned __int8 *v397; // [xsp+78h] [xbp-208h]
  __int64 v398; // [xsp+80h] [xbp-200h]
  __int64 v399; // [xsp+88h] [xbp-1F8h]
  __int64 v400; // [xsp+90h] [xbp-1F0h]
  __int64 v401; // [xsp+98h] [xbp-1E8h]
  int v402; // [xsp+A0h] [xbp-1E0h]
  int v403; // [xsp+A4h] [xbp-1DCh]
  __int64 v404; // [xsp+A8h] [xbp-1D8h]
  __int64 v405; // [xsp+B0h] [xbp-1D0h]
  unsigned __int64 StatusReg; // [xsp+B8h] [xbp-1C8h]
  unsigned int v407; // [xsp+C4h] [xbp-1BCh] BYREF
  __int64 v408; // [xsp+C8h] [xbp-1B8h] BYREF
  _QWORD v409[3]; // [xsp+D0h] [xbp-1B0h] BYREF
  _DWORD s[72]; // [xsp+E8h] [xbp-198h] BYREF
  __int64 v411; // [xsp+208h] [xbp-78h] BYREF
  __int64 v412; // [xsp+210h] [xbp-70h]
  __int64 v413; // [xsp+218h] [xbp-68h]
  __int64 v414; // [xsp+220h] [xbp-60h]
  __int64 v415; // [xsp+228h] [xbp-58h]
  __int64 v416; // [xsp+230h] [xbp-50h]
  __int64 v417; // [xsp+238h] [xbp-48h]
  __int64 v418; // [xsp+240h] [xbp-40h]
  __int64 v419; // [xsp+248h] [xbp-38h]
  __int64 v420; // [xsp+250h] [xbp-30h]
  __int64 v421; // [xsp+258h] [xbp-28h]
  _QWORD v422[4]; // [xsp+260h] [xbp-20h]

  v422[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v408 = 0;
  memset(s, 0, sizeof(s));
  v407 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(0x15u, 2u, "%s: bcn is NULL", v2, v3, v4, v5, v6, v7, v8, v9, "__scm_handle_bcn_probe");
    is_valid_rsn_present = 4;
LABEL_22:
    _ReadStatusReg(SP_EL0);
    return is_valid_rsn_present;
  }
  v10 = *((_QWORD *)a1 + 1);
  if ( !v10 )
  {
    v37 = "%s: rx_data is NULL";
LABEL_11:
    qdf_trace_msg(0x15u, 2u, v37, v2, v3, v4, v5, v6, v7, v8, v9, "__scm_handle_bcn_probe");
    pdev_by_id = 0;
LABEL_12:
    is_valid_rsn_present = 4;
LABEL_13:
    v47 = *((_QWORD *)a1 + 2);
    if ( v47 )
      wlan_objmgr_psoc_release_ref(v47, 0xCu, v39, v40, v41, v42, v43, v44, v45, v46);
    if ( pdev_by_id )
      wlan_objmgr_pdev_release_ref(pdev_by_id, 0xCu, v38, v39, v40, v41, v42, v43, v44, v45, v46);
    v48 = *((_QWORD *)a1 + 1);
    if ( v48 )
      _qdf_mem_free(v48);
    v49 = *((_QWORD *)a1 + 4);
    if ( v49 )
      _qdf_nbuf_free(v49);
    _qdf_mem_free((__int64)a1);
    goto LABEL_22;
  }
  v11 = *((_QWORD *)a1 + 4);
  if ( !v11 )
  {
    v37 = "%s: buf is NULL";
    goto LABEL_11;
  }
  v12 = *((_QWORD *)a1 + 2);
  v13 = *(unsigned __int8 **)(v11 + 224);
  pdev_by_id = wlan_objmgr_get_pdev_by_id(v12, *(_BYTE *)(v10 + 48), 0xCu);
  if ( !pdev_by_id )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: pdev is NULL for pdev %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "__scm_handle_bcn_probe",
      *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 48LL));
    goto LABEL_12;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v12, 3u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_psoc_get_scan_obj_fl",
      "__scm_handle_bcn_probe",
      1282);
    goto LABEL_12;
  }
  v32 = *((_QWORD *)a1 + 4);
  v33 = comp_private_obj;
  v34 = *(_BYTE *)(v32 + 68);
  if ( (v34 & 4) != 0 )
    v35 = *(unsigned __int16 *)(v32 + 66);
  else
    v35 = 0;
  if ( (unsigned int)(*(_DWORD *)(v32 + 112) + v35) <= 0x24 )
  {
    qdf_trace_msg(
      0x15u,
      8u,
      "%s: invalid beacon/probe length",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "__scm_handle_bcn_probe");
    goto LABEL_12;
  }
  if ( *a1 == 128 )
  {
    wlan_reg_is_dfs_for_freq(pdev_by_id, **((_DWORD **)a1 + 1), v24, v25, v26, v27, v28, v29, v30, v31);
    v32 = *((_QWORD *)a1 + 4);
    v34 = *(_BYTE *)(v32 + 68);
  }
  v51 = v34 & 4;
  if ( v51 )
    v51 = *(unsigned __int16 *)(v32 + 66);
  v52 = (_QWORD *)util_scan_unpack_beacon_frame(
                    pdev_by_id,
                    *(_QWORD *)(v32 + 224),
                    (unsigned int)(*(_DWORD *)(v32 + 112) + v51),
                    *a1,
                    *((_QWORD *)a1 + 1));
  v61 = v52;
  if ( !v52 || qdf_list_empty(v52) )
  {
    if ( v13 == (unsigned __int8 *)-16LL )
    {
      v64 = 0;
      v62 = 0;
      v63 = 0;
      v65 = 0;
    }
    else
    {
      v62 = v13[16];
      v63 = v13[17];
      v64 = v13[18];
      v65 = v13[21];
    }
    v380 = "%s: %02x:%02x:%02x:**:**:%02x: failed to unpack %d frame";
    LODWORD(v381) = *a1;
LABEL_360:
    qdf_trace_msg(
      0x15u,
      8u,
      v380,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "__scm_handle_bcn_probe",
      v62,
      v63,
      v64,
      v65,
      v381,
      v382);
    is_valid_rsn_present = 4;
LABEL_361:
    if ( !v61 )
      goto LABEL_13;
    goto LABEL_362;
  }
  v66 = v61[4];
  if ( !v66 )
  {
    is_valid_rsn_present = 0;
LABEL_362:
    _qdf_mem_free((__int64)v61);
    goto LABEL_13;
  }
  v67 = 0;
  v403 = v61[4];
  v404 = v33 + 0x4000;
  StatusReg = _ReadStatusReg(SP_EL0);
  v399 = v33;
  v400 = v12;
  while ( 1 )
  {
    if ( (unsigned int)qdf_list_remove_front(v61, &v408) || !v408 )
    {
      if ( v13 == (unsigned __int8 *)-16LL )
      {
        v64 = 0;
        v62 = 0;
        v63 = 0;
        v65 = 0;
      }
      else
      {
        v62 = v13[16];
        v63 = v13[17];
        v64 = v13[18];
        v65 = v13[21];
      }
      v380 = "%s: %02x:%02x:%02x:**:**:%02x: list remove failure i %d, lsize %d";
      LODWORD(v382) = v66;
      LODWORD(v381) = v67;
      goto LABEL_360;
    }
    v68 = *(unsigned __int8 **)(v408 + 24);
    v405 = v408;
    if ( *(_BYTE *)(v404 + 2355) == 1 && v68[1216] == 1 )
    {
      v413 = 0;
      v414 = 0;
      v411 = 0;
      v412 = 0;
      qdf_mem_set(&v411, 0x20u, 0);
      v69 = *((_DWORD *)v68 + 472) + 65500;
      v411 = *((_QWORD *)v68 + 237) + 36LL;
      LODWORD(v412) = (unsigned __int16)v69;
      if ( (wlan_action_oui_search(v12, &v411, 26) & 1) == 0 )
      {
        if ( v68 == (unsigned __int8 *)-1LL )
        {
          v125 = 0;
          v123 = 0;
          v124 = 0;
          v126 = 0;
        }
        else
        {
          v123 = v68[1];
          v124 = v68[2];
          v125 = v68[3];
          v126 = v68[6];
        }
        LODWORD(v382) = *((_DWORD *)v68 + 298);
        LODWORD(v384) = (char)v68[60];
        LODWORD(v383) = **((_DWORD **)a1 + 1);
        LODWORD(v381) = *((unsigned __int16 *)v68 + 24);
        qdf_trace_msg(
          0x15u,
          8u,
          "%02x:%02x:%02x:**:**:%02x: Drop frame(%d) for chan mismatch, seq %d frame freq %d rx data freq %d RSSI %d",
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v123,
          v124,
          v125,
          v126,
          *a1,
          v381,
          v382,
          v383,
          v384);
        if ( !v68 )
          goto LABEL_39;
        goto LABEL_76;
      }
      LODWORD(v382) = *((_DWORD *)v68 + 298);
      LODWORD(v384) = (char)v68[60];
      LODWORD(v383) = **((_DWORD **)a1 + 1);
      LODWORD(v381) = *((unsigned __int16 *)v68 + 24);
      qdf_trace_msg(
        0x15u,
        8u,
        "%02x:%02x:%02x:**:**:%02x: frame(%d) chan mismatch no-drop by oui, seq %d frame freq %d rx data freq %d RSSI %d",
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v68[1],
        v68[2],
        v68[3],
        v68[6],
        *a1,
        v381,
        v382,
        v383,
        v384);
    }
    if ( *(_BYTE *)(v404 + 2356) == 1
      && (wlan_reg_is_freq_enabled(pdev_by_id, *((_DWORD *)v68 + 298), v53, v54, v55, v56, v57, v58, v59, v60) & 1) == 0 )
    {
      if ( v68 == (unsigned __int8 *)-1LL )
      {
        v121 = 0;
        v119 = 0;
        v120 = 0;
        v122 = 0;
      }
      else
      {
        v119 = v68[1];
        v120 = v68[2];
        v121 = v68[3];
        v122 = v68[6];
      }
      LODWORD(v382) = *((unsigned __int16 *)v68 + 24);
      LODWORD(v383) = (char)v68[60];
      LODWORD(v381) = *((_DWORD *)v68 + 298);
      qdf_trace_msg(
        0x15u,
        8u,
        "%02x:%02x:%02x:**:**:%02x: Drop frame(%d) for invalid freq %d seq %d RSSI %d",
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v119,
        v120,
        v121,
        v122,
        *a1,
        v381,
        v382,
        v383);
      if ( !v68 )
        goto LABEL_39;
LABEL_76:
      v127 = *((_QWORD *)v68 + 165);
      if ( v127 )
        _qdf_mem_free(v127);
      v128 = *((_QWORD *)v68 + 237);
      if ( v128 )
        _qdf_mem_free(v128);
      _qdf_mem_free((__int64)v68);
      goto LABEL_39;
    }
    if ( *((_QWORD *)v68 + 177) )
    {
      is_valid_rsn_present = util_scan_is_valid_rsn_present(v68, s);
      if ( is_valid_rsn_present && (v68[85] != 1 || (unsigned int)qdf_mem_cmp(v68 + 14, "DIRECT-", 7u) || v68[13] != 7) )
      {
        if ( v68 == (unsigned __int8 *)-1LL )
        {
          v96 = 0;
          v94 = 0;
          v95 = 0;
          v97 = 0;
        }
        else
        {
          v94 = v68[1];
          v95 = v68[2];
          v96 = v68[3];
          v97 = v68[6];
        }
        LODWORD(v382) = is_valid_rsn_present;
        LODWORD(v381) = *((_DWORD *)v68 + 298);
        qdf_trace_msg(
          0x15u,
          8u,
          "%02x:%02x:%02x:**:**:%02x: Drop frame(%d) with invalid RSN IE freq %d, parse status %d",
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          *a1,
          v381,
          v382);
        if ( !v68 )
          goto LABEL_40;
LABEL_267:
        v206 = *((_QWORD *)v68 + 165);
        if ( !v206 )
        {
LABEL_269:
          v326 = *((_QWORD *)v68 + 237);
          if ( v326 )
            _qdf_mem_free(v326);
          _qdf_mem_free((__int64)v68);
          goto LABEL_40;
        }
LABEL_268:
        _qdf_mem_free(v206);
        goto LABEL_269;
      }
    }
    else
    {
      is_valid_rsn_present = 0;
    }
    if ( (wlan_cm_get_check_6ghz_security(v12) & 1) != 0 && wlan_reg_is_6ghz_chan_freq(*((_DWORD *)v68 + 298)) )
    {
      if ( !*((_QWORD *)v68 + 177) )
      {
        v129 = jiffies;
        if ( _scm_handle_bcn_probe___last_ticks - jiffies + 125 < 0 )
        {
          if ( v68 == (unsigned __int8 *)-1LL )
          {
            v132 = 0;
            v130 = 0;
            v131 = 0;
            v133 = 0;
          }
          else
          {
            v130 = v68[1];
            v131 = v68[2];
            v132 = v68[3];
            v133 = v68[6];
          }
          LODWORD(v382) = *((_DWORD *)v68 + 298);
          LODWORD(v381) = *a1;
          qdf_trace_msg(
            0x15u,
            4u,
            "%s: %02x:%02x:%02x:**:**:%02x: Drop frame(%d) with No RSN IE in 6GHz(%d)",
            *(double *)&v98,
            v99,
            v100,
            v101,
            v102,
            v103,
            v104,
            v105,
            "__scm_handle_bcn_probe",
            v130,
            v131,
            v132,
            v133,
            v381,
            v382);
          _scm_handle_bcn_probe___last_ticks = v129;
        }
        goto LABEL_220;
      }
      v106 = util_scan_is_valid_rsn_present(v68, s);
      if ( v106 )
      {
        is_valid_rsn_present = v106;
        v114 = jiffies;
        if ( _scm_handle_bcn_probe___last_ticks_13 - jiffies + 125 < 0 )
        {
          if ( v68 == (unsigned __int8 *)-1LL )
          {
            v117 = 0;
            v115 = 0;
            v116 = 0;
            v118 = 0;
          }
          else
          {
            v115 = v68[1];
            v116 = v68[2];
            v117 = v68[3];
            v118 = v68[6];
          }
          LODWORD(v383) = v106;
          LODWORD(v382) = *((_DWORD *)v68 + 298);
          LODWORD(v381) = *a1;
          qdf_trace_msg(
            0x15u,
            4u,
            "%s: %02x:%02x:%02x:**:**:%02x: Drop frame(%d) with invalid RSN IE in 6GHz(%d), parse status %d",
            *(double *)&v98,
            v107,
            v108,
            v109,
            v110,
            v111,
            v112,
            v113,
            "__scm_handle_bcn_probe",
            v115,
            v116,
            v117,
            v118,
            v381,
            v382,
            v383);
          _scm_handle_bcn_probe___last_ticks_13 = v114;
        }
LABEL_220:
        util_scan_free_cache_entry_1(v98);
        v66 = v403;
        goto LABEL_40;
      }
      if ( (s[1] & 0x38002) != 0 )
      {
        v134 = jiffies;
        if ( _scm_handle_bcn_probe___last_ticks_15 - jiffies + 125 < 0 )
        {
          if ( v68 == (unsigned __int8 *)-1LL )
          {
            v137 = 0;
            v135 = 0;
            v136 = 0;
            v138 = 0;
          }
          else
          {
            v135 = v68[1];
            v136 = v68[2];
            v137 = v68[3];
            v138 = v68[6];
          }
          LODWORD(v383) = *((_DWORD *)v68 + 298);
          LODWORD(v382) = s[1];
          LODWORD(v381) = *a1;
          qdf_trace_msg(
            0x15u,
            4u,
            "%s: %02x:%02x:%02x:**:**:%02x: Drop frame(%d) with Invalid sec type %0X for 6GHz(%d)",
            *(double *)&v98,
            v107,
            v108,
            v109,
            v110,
            v111,
            v112,
            v113,
            "__scm_handle_bcn_probe",
            v135,
            v136,
            v137,
            v138,
            v381,
            v382,
            v383);
          _scm_handle_bcn_probe___last_ticks_15 = v134;
        }
LABEL_284:
        util_scan_free_cache_entry_1(v98);
        v66 = v403;
LABEL_39:
        is_valid_rsn_present = 0;
        goto LABEL_40;
      }
      if ( (wlan_cm_6ghz_allowed_for_akm(v12, s[5], s[38], *((_QWORD *)v68 + 224), 0, 0) & 1) == 0 )
      {
        v269 = jiffies;
        if ( _scm_handle_bcn_probe___last_ticks_17 - jiffies + 125 < 0 )
        {
          if ( v68 == (unsigned __int8 *)-1LL )
          {
            v272 = 0;
            v270 = 0;
            v271 = 0;
            v273 = 0;
          }
          else
          {
            v270 = v68[1];
            v271 = v68[2];
            v272 = v68[3];
            v273 = v68[6];
          }
          LODWORD(v383) = *((_DWORD *)v68 + 298);
          LODWORD(v382) = s[5];
          LODWORD(v381) = *a1;
          qdf_trace_msg(
            0x15u,
            4u,
            "%s: %02x:%02x:%02x:**:**:%02x: Drop frame(%d) with Invalid AKM suite %0X for 6GHz(%d)",
            *(double *)&v98,
            v139,
            v140,
            v141,
            v142,
            v143,
            v144,
            v145,
            "__scm_handle_bcn_probe",
            v270,
            v271,
            v272,
            v273,
            v381,
            v382,
            v383);
          _scm_handle_bcn_probe___last_ticks_17 = v269;
        }
        goto LABEL_284;
      }
    }
    if ( *((_DWORD *)v68 + 30) | *((unsigned __int16 *)v68 + 62) )
    {
      v68[50] |= 1u;
      *((_BYTE *)a1 + 25) = 1;
    }
    *((_DWORD *)v68 + 519) = *((_DWORD *)v68 + 13);
    v146 = *(void (__fastcall **)(__int64, unsigned __int8 *))(v33 + 1800);
    if ( v146 )
    {
      if ( *((_DWORD *)v146 - 1) != 1826473788 )
        __break(0x8228u);
      v146(pdev_by_id, v68);
    }
    if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)v68 + 298)) )
    {
      best_6g_power_type = wlan_reg_get_best_6g_power_type(
                             v12,
                             pdev_by_id,
                             &v407,
                             v68[2084],
                             *((_DWORD *)v68 + 298),
                             v147,
                             v148,
                             v149,
                             v150,
                             v151,
                             v152,
                             v153,
                             v154);
      if ( best_6g_power_type )
      {
        is_valid_rsn_present = best_6g_power_type;
        v156 = jiffies;
        if ( _scm_handle_bcn_probe___last_ticks_19 - jiffies + 125 < 0 )
        {
          if ( v68 == (unsigned __int8 *)-1LL )
          {
            v159 = 0;
            v157 = 0;
            v158 = 0;
            v160 = 0;
          }
          else
          {
            v157 = v68[1];
            v158 = v68[2];
            v159 = v68[3];
            v160 = v68[6];
          }
          LODWORD(v383) = v68[2084];
          LODWORD(v382) = *((_DWORD *)v68 + 298);
          LODWORD(v381) = *a1;
          qdf_trace_msg(
            0x15u,
            4u,
            "%s: %02x:%02x:%02x:**:**:%02x: Drop frame(%d) freq %d, as power type %d is not supported",
            v147,
            v148,
            v149,
            v150,
            v151,
            v152,
            v153,
            v154,
            "__scm_handle_bcn_probe",
            v157,
            v158,
            v159,
            v160,
            v381,
            v382,
            v383);
          _scm_handle_bcn_probe___last_ticks_19 = v156;
        }
        if ( v68 )
        {
          v206 = *((_QWORD *)v68 + 165);
          v66 = v403;
          if ( !v206 )
            goto LABEL_269;
          goto LABEL_268;
        }
        v66 = v403;
        goto LABEL_40;
      }
    }
    v161 = *(unsigned __int8 *)(pdev_by_id + 40);
    if ( v161 >= 2 )
    {
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: invalid pdev_id %d",
        v147,
        v148,
        v149,
        v150,
        v151,
        v152,
        v153,
        v154,
        "wlan_pdevid_get_scan_db",
        *(unsigned __int8 *)(pdev_by_id + 40));
LABEL_116:
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: scan_db is NULL",
        v162,
        v163,
        v164,
        v165,
        v166,
        v167,
        v168,
        v169,
        "scm_add_update_entry");
      v12 = v400;
      v66 = v403;
      goto LABEL_117;
    }
    v170 = *((_BYTE *)a1 + 25);
    v171 = wlan_objmgr_psoc_get_comp_private_obj(v400, 3u);
    if ( !v171 )
    {
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: %s:%u, Failed to get scan object",
        v162,
        v163,
        v164,
        v165,
        v166,
        v167,
        v168,
        v169,
        "wlan_psoc_get_scan_obj_fl",
        "wlan_pdevid_get_scan_db",
        57);
      goto LABEL_116;
    }
    v172 = v171 + 1560LL * v161;
    v173 = v172 + 32;
    if ( v172 == -32 )
      goto LABEL_116;
    v174 = wlan_objmgr_psoc_get_comp_private_obj(v400, 3u);
    v66 = v403;
    if ( !v174 )
    {
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: %s:%u, Failed to get scan object",
        v175,
        v176,
        v177,
        v178,
        v179,
        v180,
        v181,
        v182,
        "wlan_psoc_get_scan_obj_fl",
        "scm_add_update_entry",
        1117);
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: scan_obj is NULL",
        v198,
        v199,
        v200,
        v201,
        v202,
        v203,
        v204,
        v205,
        "scm_add_update_entry");
      v12 = v400;
LABEL_117:
      is_valid_rsn_present = 4;
      if ( v68 != (unsigned __int8 *)-1LL )
        goto LABEL_118;
      goto LABEL_265;
    }
    v396 = v174;
    if ( *v68 == 80 && !*((_QWORD *)v68 + 168) )
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: Probe resp doesn't contain SSID",
        v175,
        v176,
        v177,
        v178,
        v179,
        v180,
        v181,
        v182,
        "scm_add_update_entry");
    v183 = v68[6];
    v394 = v170;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v173 + 8);
    }
    else
    {
      raw_spin_lock_bh(v173 + 8);
      *(_QWORD *)(v173 + 16) |= 1uLL;
    }
    v184 = (_QWORD *)(v173 + 24 + 24LL * (v183 & 0x3F));
    v401 = v173 + 24;
    v411 = 0;
    v409[0] = 0;
    qdf_list_peek_front(v184, &v411);
    v185 = v411;
    if ( v411 )
    {
      while ( *(_DWORD *)(v185 + 20) != 306772034 )
      {
        qdf_list_peek_next(v184, (_QWORD *)v185, v409);
        v185 = v409[0];
        v409[0] = 0;
        v411 = v185;
        if ( !v185 )
          goto LABEL_114;
      }
      _X8 = (unsigned int *)(v185 + 16);
      __asm { PRFM            #0x11, [X8] }
      do
        v379 = __ldxr(_X8);
      while ( __stxr(v379 + 1, _X8) );
    }
    else
    {
LABEL_114:
      v185 = 0;
    }
    v207 = *(_QWORD *)(v173 + 16);
    next_node = v185;
    if ( (v207 & 1) == 0 )
    {
      raw_spin_unlock(v173 + 8);
      v402 = v67;
      if ( next_node )
        goto LABEL_129;
LABEL_131:
      v225 = v394;
      v392 = 0;
      v398 = 0;
LABEL_132:
      v68[50] = v68[50] & 0xFE | v225;
      goto LABEL_133;
    }
    *(_QWORD *)(v173 + 16) = v207 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v173 + 8);
    v402 = v67;
    if ( !next_node )
      goto LABEL_131;
LABEL_129:
    while ( (util_is_scan_entry_match(v68, *(_QWORD *)(next_node + 24)) & 1) == 0 )
    {
      next_node = scm_get_next_node(v173, (__int64)v184, next_node);
      if ( !next_node )
        goto LABEL_131;
    }
    v267 = *(unsigned __int8 **)(next_node + 24);
    v268 = *v68;
    v398 = next_node;
    if ( v268 == 80 )
    {
      if ( v267[46] )
        v68[46] = 1;
    }
    else if ( v268 == 128 )
    {
      if ( v267[46] )
      {
        v274 = v68[13];
        if ( v68[13] )
        {
          v275 = v68[14];
          if ( v68[14] )
          {
            for ( i = v68 + 15; ; ++i )
            {
              --v274;
              if ( (v275 | 0x20) != 0x20 )
                break;
              if ( !v274 )
                goto LABEL_292;
              v277 = *i;
              v275 = v277;
            }
            if ( *(_QWORD *)(v396 + 1808) )
            {
              if ( v267 == (unsigned __int8 *)-1LL )
              {
                v332 = 0;
                v330 = 0;
                v331 = 0;
                v333 = 0;
              }
              else
              {
                v330 = v267[1];
                v331 = v267[2];
                v332 = v267[3];
                v333 = v267[6];
              }
              qdf_trace_msg(
                0x15u,
                8u,
                "%s: Hidden AP %02x:%02x:%02x:**:**:%02x switch to non-hidden SSID, So unlink the entry",
                v217,
                v218,
                v219,
                v220,
                v221,
                v222,
                v223,
                v224,
                "scm_copy_info_from_dup_entry",
                v330,
                v331,
                v332,
                v333);
              v334 = *(void (__fastcall **)(__int64, unsigned __int8 *))(v396 + 1808);
              if ( *((_DWORD *)v334 - 1) != 1826473788 )
                __break(0x8228u);
              v334(pdev_by_id, v267);
            }
          }
        }
      }
    }
LABEL_292:
    v335 = v68[13];
    if ( v68[13] && (v336 = v68[14]) != 0 )
    {
      for ( j = v68 + 15; ; ++j )
      {
        --v335;
        if ( (v336 | 0x20) != 0x20 )
          break;
        if ( !v335 )
          goto LABEL_298;
        v338 = *j;
        v336 = v338;
      }
    }
    else
    {
LABEL_298:
      if ( v267[13] )
      {
        system_time = qdf_mc_timer_get_system_time();
        v340 = *((_QWORD *)v267 + 13);
        if ( !((unsigned __int64)(system_time - v340) >> 32) )
        {
          *((_QWORD *)v68 + 13) = v340;
          v341 = v267[13];
          v68[13] = v341;
          qdf_mem_copy(v68 + 14, v267 + 14, v341);
        }
      }
    }
    v342 = *v68;
    v343 = v68 + 88;
    v344 = *((_QWORD *)v68 + 11) - *((_QWORD *)v267 + 12);
    if ( v342 == 128 || v342 == 80 )
    {
      if ( !*((_QWORD *)v68 + 183)
        && (!v68 || !*((_QWORD *)v68 + 171))
        && !*((_QWORD *)v68 + 196)
        && !*((_QWORD *)v68 + 214) )
      {
        v361 = *((_DWORD *)v267 + 298);
        if ( *((_DWORD *)v68 + 298) != v361 )
        {
          v362 = (char)v68[60];
          if ( v362 < -80 || v344 >> 3 <= 0x270 && v362 + 40 < (char)v267[60] )
          {
            *((_DWORD *)v68 + 298) = v361;
            v68[1216] = 1;
          }
        }
      }
      if ( *((_DWORD *)v68 + 520) != *((_DWORD *)v267 + 298) && v344 >> 3 <= 0x270 )
      {
        if ( *((_QWORD *)v68 + 214) )
        {
          v393 = v344;
          he_6g_params = util_scan_get_he_6g_params();
          v344 = v393;
          if ( he_6g_params )
          {
            if ( (*(_BYTE *)(he_6g_params + 1) & 4) != 0 && (char)v68[60] < (char)v267[60] )
            {
              v346 = *((_DWORD *)v267 + 298);
              v68[1216] = 1;
              *((_DWORD *)v68 + 298) = v346;
            }
          }
        }
      }
    }
    if ( v68[1216] == 1 )
    {
      v343 = v267 + 96;
      v68[61] = v267[61];
      *((_DWORD *)v68 + 16) = *((_DWORD *)v267 + 16);
      v68[60] = v267[60];
      *((_DWORD *)v68 + 14) = *((_DWORD *)v267 + 14);
LABEL_315:
      v225 = v394;
      goto LABEL_316;
    }
    if ( v344 >= 0x1389 )
    {
      v347 = v68[61] << 7;
      *((_DWORD *)v68 + 14) = (char)v68[60] << 7;
      *((_DWORD *)v68 + 16) = v347;
      goto LABEL_315;
    }
    v363 = *((unsigned int *)v267 + 16);
    v364 = (char)v68[60];
    *((_DWORD *)v68 + 16) = v363;
    v365 = *((_DWORD *)v267 + 14);
    *((_DWORD *)v68 + 14) = v365;
    if ( v364 <= -21 )
    {
      v366 = v364 << 7;
      if ( v365 == 295 )
        v367 = v366;
      else
        v367 = (v366 - v365 + 8 * v365) >> 3;
      *((_DWORD *)v68 + 14) = v367;
    }
    v368 = v68[61];
    v225 = v394;
    if ( v68[61] )
    {
      if ( (_DWORD)v363 == 127 )
        LODWORD(v369) = (_DWORD)v368 << 7;
      else
        v369 = ((unsigned __int64)(unsigned int)(8 * v363) - v363 + (v368 << 7)) >> 3;
      *((_DWORD *)v68 + 16) = v369;
    }
LABEL_316:
    v348 = *v68;
    *((_QWORD *)v68 + 12) = *v343;
    if ( *v267 != v348 )
    {
      v349 = *((unsigned __int8 **)v267 + 176);
      if ( v349 )
      {
        v350 = *((void **)v68 + 165);
        v351 = v349[1];
        if ( v350 )
          goto LABEL_321;
        v350 = qdf_mem_malloc_atomic_fl(0x101u, (__int64)"scm_update_alt_wcn_ie", 0x2FEu);
        *((_QWORD *)v68 + 165) = v350;
        if ( v350 )
        {
          v349 = *((unsigned __int8 **)v267 + 176);
LABEL_321:
          v360 = v351 + 2;
          qdf_mem_copy(v350, v349, v360);
          *((_DWORD *)v68 + 328) = v360;
          goto LABEL_322;
        }
        qdf_trace_msg(
          0x15u,
          2u,
          "%s: failed to allocate memory",
          v352,
          v353,
          v354,
          v355,
          v356,
          v357,
          v358,
          v359,
          "scm_update_alt_wcn_ie");
      }
    }
LABEL_322:
    qdf_mem_copy(v68 + 1224, v267 + 1224, 0x20u);
    if ( (v68[50] & 1) == 0 )
      v68[50] |= v267[50] & 1;
    v67 = v402;
    v392 = 1;
    if ( (v225 & 1) == 0 )
      goto LABEL_132;
LABEL_133:
    *(_QWORD *)((char *)v422 + 5) = 0;
    v421 = 0;
    v422[0] = 0;
    v419 = 0;
    v420 = 0;
    v417 = 0;
    v418 = 0;
    v415 = 0;
    v416 = 0;
    v226 = *(unsigned __int8 *)(pdev_by_id + 40);
    v413 = 0;
    v414 = 0;
    v411 = 0;
    v412 = 0;
    if ( !v226 )
    {
      v228 = v68[47];
      if ( !v228 )
      {
        if ( (v68[46] & 1) == 0 )
        {
          v229 = 0;
          if ( (v68[1216] & 1) == 0 )
            goto LABEL_161;
          goto LABEL_160;
        }
        v229 = 0;
        goto LABEL_157;
      }
      v229 = 0;
      goto LABEL_139;
    }
    *(double *)&v209 = scnprintf(&v411, 101, "pdev %d ", v226);
    v228 = v68[47];
    v229 = v227;
    if ( v228 )
    {
      if ( v227 > 0x65 )
        goto LABEL_368;
LABEL_139:
      if ( (v228 & 2) != 0 )
        v230 = "[WPA]";
      else
        v230 = (const char *)&unk_98C763;
      if ( (v228 & 8) != 0 )
        v231 = "[RSN]";
      else
        v231 = (const char *)&unk_98C763;
      if ( (v228 & 4) != 0 )
        v232 = "[WAPI]";
      else
        v232 = (const char *)&unk_98C763;
      if ( (v228 & 1) != 0 )
        v233 = "[WEP]";
      else
        v233 = (const char *)&unk_98C763;
      if ( (v228 & 0x10) != 0 )
        v234 = "[RSNO]";
      else
        v234 = (const char *)&unk_98C763;
      *(double *)&v209 = scnprintf((char *)&v411 + v229, 101 - v229, "%s%s%s%s%s", v230, v231, v232, v233, v234);
      v229 += v235;
    }
    if ( (v68[46] & 1) == 0 )
      goto LABEL_158;
    if ( v229 > 0x65 )
      goto LABEL_368;
LABEL_157:
    *(double *)&v209 = scnprintf((char *)&v411 + v229, 101 - v229, "[hidden]");
    v229 += v236;
LABEL_158:
    if ( (v68[1216] & 1) != 0 )
    {
      if ( v229 > 0x65 )
        goto LABEL_368;
LABEL_160:
      *(double *)&v209 = scnprintf((char *)&v411 + v229, 101 - v229, "[Chan mismatch]");
      v229 += v237;
    }
LABEL_161:
    if ( *((_QWORD *)v68 + 172) || *((_QWORD *)v68 + 173) || *((_QWORD *)v68 + 206) )
      break;
LABEL_166:
    if ( *((_DWORD *)v68 + 478) | *((unsigned __int16 *)v68 + 958) )
      *(double *)&v209 = scnprintf(
                           (char *)&v411 + v229,
                           101 - v229,
                           ", MLD %02x:%02x:%02x:**:**:%02x links %d",
                           v68[1912],
                           v68[1913],
                           v68[1914],
                           v68[1917],
                           v68[1918]);
    if ( *v68 == 80 )
      v239 = "prb rsp";
    else
      v239 = "bcn";
    LODWORD(v390) = v68[50] & 1;
    LODWORD(v389) = *((_DWORD *)v68 + 13);
    LODWORD(v388) = v68[61];
    LODWORD(v387) = *((unsigned __int16 *)v68 + 24);
    LODWORD(v386) = *((_DWORD *)v68 + 314);
    LODWORD(v385) = (char)v68[60];
    LODWORD(v384) = *((_DWORD *)v68 + 298);
    LODWORD(v382) = v68[13];
    LODWORD(v381) = v68[6];
    qdf_trace_msg(
      0x15u,
      8u,
      "Rcvd %s(%d): %02x:%02x:%02x:**:**:%02x \"%.*s\" freq %d rssi %d tsf %u seq %d snr %d phy %d gen %d %s",
      *(double *)&v209,
      v210,
      v211,
      v212,
      v213,
      v214,
      v215,
      v216,
      v239,
      *((unsigned int *)v68 + 472),
      v68[1],
      v68[2],
      v68[3],
      v381,
      v382,
      v68 + 14,
      v384,
      v385,
      v386,
      v387,
      v388,
      v389,
      v390,
      &v411);
    v240 = *(void (__fastcall **)(__int64, unsigned __int8 *))(v396 + 1792);
    if ( v240 )
    {
      if ( *((_DWORD *)v240 - 1) != 1826473788 )
        __break(0x8228u);
      v240(pdev_by_id, v68);
    }
    if ( *(_DWORD *)v173 >= 0x1F4u )
    {
      v395 = v61;
      v397 = v13;
      v241 = 0;
      v242 = 0;
      while ( 2 )
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v173 + 8);
        }
        else
        {
          raw_spin_lock_bh(v173 + 8);
          *(_QWORD *)(v173 + 16) |= 1uLL;
        }
        v243 = (_QWORD *)(v401 + 24 * v241);
        v411 = 0;
        v409[0] = 0;
        qdf_list_peek_front(v243, &v411);
        v244 = v411;
        if ( v411 )
        {
          while ( *(_DWORD *)(v244 + 20) != 306772034 )
          {
            qdf_list_peek_next(v243, (_QWORD *)v244, v409);
            v244 = v409[0];
            v409[0] = 0;
            v411 = v244;
            if ( !v244 )
              goto LABEL_185;
          }
          _X8 = (unsigned int *)(v244 + 16);
          __asm { PRFM            #0x11, [X8] }
          do
            v263 = __ldxr(_X8);
          while ( __stxr(v263 + 1, _X8) );
          v245 = *(_QWORD *)(v173 + 16);
          if ( (v245 & 1) != 0 )
          {
LABEL_189:
            *(_QWORD *)(v173 + 16) = v245 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v173 + 8);
            if ( !v244 )
              goto LABEL_177;
LABEL_198:
            while ( 2 )
            {
              if ( v242 )
              {
                v250 = *(_QWORD *)(*(_QWORD *)(v242 + 24) + 88LL);
                v251 = qdf_mc_timer_get_system_time() - v250;
                v252 = *(_QWORD *)(*(_QWORD *)(v244 + 24) + 88LL);
                if ( v251 < qdf_mc_timer_get_system_time() - v252 )
                {
                  scm_scan_entry_put_ref(v173, v242, 1, v253, v254, v255, v256, v257, v258, v259, v260);
                  goto LABEL_201;
                }
              }
              else
              {
LABEL_201:
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
                  || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(v173 + 8);
                }
                else
                {
                  raw_spin_lock_bh(v173 + 8);
                  *(_QWORD *)(v173 + 16) |= 1uLL;
                }
                _X8 = (unsigned int *)(v244 + 16);
                __asm { PRFM            #0x11, [X8] }
                do
                  v248 = __ldxr(_X8);
                while ( __stxr(v248 + 1, _X8) );
                v249 = *(_QWORD *)(v173 + 16);
                if ( (v249 & 1) != 0 )
                {
                  *(_QWORD *)(v173 + 16) = v249 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(v173 + 8);
                }
                else
                {
                  raw_spin_unlock(v173 + 8);
                }
                v242 = v244;
              }
              v244 = scm_get_next_node(v173, (__int64)v243, v244);
              if ( !v244 )
                goto LABEL_177;
              continue;
            }
          }
        }
        else
        {
LABEL_185:
          v244 = 0;
          v245 = *(_QWORD *)(v173 + 16);
          if ( (v245 & 1) != 0 )
            goto LABEL_189;
        }
        raw_spin_unlock(v173 + 8);
        if ( v244 )
          goto LABEL_198;
LABEL_177:
        ++v241;
        v67 = v402;
        if ( v241 != 64 )
          continue;
        break;
      }
      v61 = v395;
      v13 = v397;
      if ( !v242 )
        goto LABEL_251;
      v264 = *(_QWORD *)(v242 + 24);
      if ( v264 == -1 )
      {
        v391 = 0;
        v265 = 0;
        v266 = 0;
      }
      else
      {
        v265 = *(unsigned __int8 *)(v264 + 2);
        v266 = *(unsigned __int8 *)(v264 + 6);
        LODWORD(v391) = *(unsigned __int8 *)(v264 + 3);
        HIDWORD(v391) = *(unsigned __int8 *)(v264 + 1);
      }
      v278 = *(_QWORD *)(v264 + 88);
      v279 = qdf_mc_timer_get_system_time();
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: Flush oldest BSSID: %02x:%02x:%02x:**:**:%02x with age %lu ms",
        v280,
        v281,
        v282,
        v283,
        v284,
        v285,
        v286,
        v287,
        "scm_flush_oldest_entry",
        HIDWORD(v391),
        v265,
        (unsigned int)v391,
        v266,
        v279 - v278);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v173 + 8);
      }
      else
      {
        raw_spin_lock_bh(v173 + 8);
        *(_QWORD *)(v173 + 16) |= 1uLL;
      }
      v67 = v402;
      if ( *(_DWORD *)(v242 + 20) == 306772034 )
      {
        if ( *(_DWORD *)(v242 + 16) )
        {
          *(_DWORD *)(v242 + 20) = 0;
          scm_scan_entry_put_ref(v173, v242, 0, v288, v289, v290, v291, v292, v293, v294, v295);
          goto LABEL_249;
        }
        v304 = "%s: node is already deleted ref 0";
      }
      else
      {
        v304 = "%s: node is already deleted";
      }
      qdf_trace_msg(0x15u, 8u, v304, v288, v289, v290, v291, v292, v293, v294, v295, "scm_scan_entry_del");
LABEL_249:
      scm_scan_entry_put_ref(v173, v242, 0, v296, v297, v298, v299, v300, v301, v302, v303);
      v305 = *(_QWORD *)(v173 + 16);
      if ( (v305 & 1) != 0 )
      {
        *(_QWORD *)(v173 + 16) = v305 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v173 + 8);
      }
      else
      {
        raw_spin_unlock(v173 + 8);
      }
    }
LABEL_251:
    v306 = _qdf_mem_malloc(0x20u, "scm_add_update_entry", 1159);
    if ( v306 )
    {
      *(_QWORD *)(v306 + 24) = v68;
      v12 = v400;
      v307 = v306;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v173 + 8);
      }
      else
      {
        raw_spin_lock_bh(v173 + 8);
        *(_QWORD *)(v173 + 16) |= 1uLL;
      }
      v33 = v399;
      v308 = *(_BYTE *)(*(_QWORD *)(v307 + 24) + 6LL);
      *(_DWORD *)(v307 + 16) = 0;
      *(_DWORD *)(v307 + 20) = 306772034;
      _X9 = (unsigned int *)(v307 + 16);
      __asm { PRFM            #0x11, [X9] }
      do
        v372 = __ldxr(_X9);
      while ( __stxr(v372 + 1, _X9) );
      v309 = (_QWORD *)(v401 + 24LL * (v308 & 0x3F));
      if ( v398 )
      {
        qdf_list_insert_before((__int64)v309, (_QWORD *)v307, (_QWORD *)v398);
        v66 = v403;
        ++*(_DWORD *)v173;
        if ( (v392 & 1) == 0 )
          goto LABEL_278;
        if ( *(_DWORD *)(v398 + 20) == 306772034 )
        {
          if ( *(_DWORD *)(v398 + 16) )
          {
            *(_DWORD *)(v398 + 20) = 0;
            scm_scan_entry_put_ref(v173, v398, 0, v310, v311, v312, v313, v314, v315, v316, v317);
LABEL_277:
            scm_scan_entry_put_ref(v173, v398, 0, v318, v319, v320, v321, v322, v323, v324, v325);
LABEL_278:
            v329 = *(_QWORD *)(v173 + 16);
            if ( (v329 & 1) != 0 )
            {
              *(_QWORD *)(v173 + 16) = v329 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v173 + 8);
            }
            else
            {
              raw_spin_unlock(v173 + 8);
            }
            if ( *((_BYTE *)a1 + 24) == 1 )
              scm_add_rnr_channel_db(pdev_by_id, v68);
            goto LABEL_39;
          }
          v327 = 8;
          v328 = "%s: node is already deleted ref 0";
        }
        else
        {
          v327 = 8;
          v328 = "%s: node is already deleted";
        }
      }
      else
      {
        qdf_list_insert_back(v309, (_QWORD *)v307);
        v66 = v403;
        ++*(_DWORD *)v173;
        if ( (v392 & 1) == 0 )
          goto LABEL_278;
        v327 = 2;
        v328 = "%s: scan node is NULL";
      }
      qdf_trace_msg(0x15u, v327, v328, v310, v311, v312, v313, v314, v315, v316, v317, "scm_scan_entry_del");
      goto LABEL_277;
    }
    v12 = v400;
    if ( v392 )
      scm_scan_entry_put_ref(v173, v398, 1, v186, v187, v188, v189, v190, v191, v192, v193);
    v66 = v403;
    is_valid_rsn_present = 2;
    if ( v68 != (unsigned __int8 *)-1LL )
    {
LABEL_118:
      v194 = v68[1];
      v195 = v68[2];
      v196 = v68[3];
      v197 = v68[6];
      goto LABEL_266;
    }
LABEL_265:
    v196 = 0;
    v194 = 0;
    v195 = 0;
    v197 = 0;
LABEL_266:
    v33 = v399;
    LODWORD(v383) = *((_DWORD *)v68 + 298);
    LODWORD(v382) = *((unsigned __int16 *)v68 + 24);
    LODWORD(v381) = *a1;
    qdf_trace_msg(
      0x15u,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x: Failed to add entry for frame(%d) seq %d freq %d",
      v186,
      v187,
      v188,
      v189,
      v190,
      v191,
      v192,
      v193,
      "__scm_handle_bcn_probe",
      v194,
      v195,
      v196,
      v197,
      v381,
      v382,
      v383);
    if ( v68 )
      goto LABEL_267;
LABEL_40:
    _qdf_mem_free(v405);
    if ( ++v67 == v66 )
      goto LABEL_361;
  }
  if ( v229 <= 0x65 )
  {
    *(double *)&v209 = scnprintf((char *)&v411 + v229, 101 - v229, "[CSA IE]", *(double *)&v209);
    v229 += v238;
    goto LABEL_166;
  }
LABEL_368:
  __break(0x5512u);
  return util_scan_free_cache_entry_1(v209);
}
