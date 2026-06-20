__int64 __fastcall hdd_cm_connect_success_pre_user_update(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char v12; // w28
  _QWORD *context; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x22
  __int64 *link_info_by_vdev; // x0
  __int64 v33; // x23
  __int64 v34; // x20
  int v35; // w9
  int v36; // w6
  int v37; // w7
  const void *v38; // x4
  unsigned __int8 v39; // w2
  const char *v40; // x2
  __int64 result; // x0
  __int64 v42; // x27
  __int64 v43; // x8
  __int64 v44; // x26
  __int64 v45; // x0
  int v46; // w9
  __int64 v47; // x25
  __int64 vdev_by_user; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x19
  __int64 v58; // x24
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 crypto_params; // x0
  unsigned int *v62; // x19
  __int64 v63; // x19
  char v64; // w8
  double v65; // d0
  int v66; // w0
  __int64 v67; // x0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  int v83; // w9
  __int64 v84; // x8
  __int64 v85; // x4
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  _DWORD *v94; // x19
  const char *v95; // x2
  const char *v96; // x3
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x1
  __int64 v106; // x8
  unsigned int v107; // w9
  char is_ap_supports_immediate_power_save; // w0
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  __int64 v117; // x9
  double started; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  char is_link_switch_connect_resp; // w25
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  __int64 v135; // x8
  unsigned int v136; // w26
  __int64 v137; // x27
  _QWORD *v138; // x19
  __int64 link_info_by_ieee_link_id; // x0
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  __int64 v148; // x24
  unsigned int v149; // w28
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7
  const char *v158; // x2
  __int64 v159; // x4
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  __int64 v168; // x0
  double v169; // d0
  double v170; // d1
  double v171; // d2
  double v172; // d3
  double v173; // d4
  double v174; // d5
  double v175; // d6
  double v176; // d7
  __int64 v177; // x26
  __int64 cmpt_obj; // x0
  double v179; // d0
  double v180; // d1
  double v181; // d2
  double v182; // d3
  double v183; // d4
  double v184; // d5
  double v185; // d6
  double v186; // d7
  char v187; // w8
  int v188; // w15
  __int64 v189; // x15
  __int64 v190; // x16
  __int64 v191; // x9
  double v192; // d0
  double v193; // d1
  double v194; // d2
  double v195; // d3
  double v196; // d4
  double v197; // d5
  double v198; // d6
  double v199; // d7
  __int64 v200; // x8
  __int64 v201; // x0
  _BOOL4 v202; // w8
  unsigned int v203; // w28
  unsigned __int8 acm_mask; // w0
  int v205; // w19
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
  __int64 v222; // x19
  int v223; // w24
  __int64 v224; // x28
  int v225; // w8
  const char *v226; // x2
  double v227; // d0
  double v228; // d1
  double v229; // d2
  double v230; // d3
  double v231; // d4
  double v232; // d5
  double v233; // d6
  double v234; // d7
  __int64 v235; // x19
  __int64 v236; // x8
  __int64 v237; // x26
  __int64 v238; // x0
  __int64 v239; // x1
  unsigned __int8 v240; // w2
  double v241; // d0
  double v242; // d1
  double v243; // d2
  double v244; // d3
  double v245; // d4
  double v246; // d5
  double v247; // d6
  double v248; // d7
  unsigned int v249; // w28
  __int64 comp_private_obj; // x0
  __int64 v251; // x27
  __int64 v252; // x2
  double v253; // d0
  double v254; // d1
  double v255; // d2
  double v256; // d3
  double v257; // d4
  double v258; // d5
  double v259; // d6
  double v260; // d7
  _BOOL4 v261; // w26
  __int64 v262; // x19
  _BYTE *v263; // x8
  const char *v264; // x8
  int v265; // w24
  double v266; // d0
  double v267; // d1
  double v268; // d2
  double v269; // d3
  double v270; // d4
  double v271; // d5
  double v272; // d6
  double v273; // d7
  double v274; // d0
  double v275; // d1
  double v276; // d2
  double v277; // d3
  double v278; // d4
  double v279; // d5
  double v280; // d6
  double v281; // d7
  __int64 v282; // x0
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
  double v307; // d0
  double v308; // d1
  double v309; // d2
  double v310; // d3
  double v311; // d4
  double v312; // d5
  double v313; // d6
  double v314; // d7
  __int64 v315; // x8
  __int64 (__fastcall *v316)(_QWORD); // x8
  __int64 v317; // x3
  __int64 v318; // x5
  __int64 v319; // x8
  __int64 v320; // x2
  bool v321; // zf
  __int64 *v322; // x4
  double v323; // d0
  double v324; // d1
  double v325; // d2
  double v326; // d3
  double v327; // d4
  double v328; // d5
  double v329; // d6
  double v330; // d7
  char v331; // w8
  char v332; // w8
  char v333; // w8
  unsigned int v334; // w8
  __int64 v335; // x26
  char v336; // w8
  char v337; // w8
  char v338; // w8
  char v339; // w8
  char v340; // w8
  __int64 v341; // x0
  unsigned int v342; // w8
  __int64 v343; // x19
  unsigned int v344; // w24
  void *v345; // x0
  _BOOL4 v346; // [xsp+8h] [xbp-78h]
  unsigned int v347; // [xsp+Ch] [xbp-74h]
  _DWORD *v348; // [xsp+10h] [xbp-70h]
  __int64 v349; // [xsp+18h] [xbp-68h]
  unsigned __int8 v350; // [xsp+24h] [xbp-5Ch]
  __int64 v351; // [xsp+28h] [xbp-58h]
  char v352; // [xsp+34h] [xbp-4Ch]
  char v353; // [xsp+34h] [xbp-4Ch]
  _QWORD *v354; // [xsp+38h] [xbp-48h]
  char v355[4]; // [xsp+40h] [xbp-40h] BYREF
  char v356[4]; // [xsp+44h] [xbp-3Ch] BYREF
  __int64 v357; // [xsp+48h] [xbp-38h] BYREF
  __int64 v358; // [xsp+50h] [xbp-30h]
  __int64 v359; // [xsp+58h] [xbp-28h]
  __int64 v360; // [xsp+60h] [xbp-20h]
  __int64 v361; // [xsp+68h] [xbp-18h]
  int v362; // [xsp+70h] [xbp-10h]
  __int64 v363; // [xsp+78h] [xbp-8h]

  v363 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_BYTE *)(a2 + 1);
  v356[0] = 0;
  context = _cds_get_context(71, (__int64)"hdd_cm_connect_success_pre_user_update", a3, a4, a5, a6, a7, a8, a9, a10);
  v355[0] = 0;
  v22 = _cds_get_context(51, (__int64)"hdd_cm_connect_success_pre_user_update", v14, v15, v16, v17, v18, v19, v20, v21);
  if ( !v22 )
  {
    v40 = "%s: hdd_ctx is NULL";
LABEL_7:
    result = qdf_trace_msg(
               0x33u,
               2u,
               v40,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               "hdd_cm_connect_success_pre_user_update");
    goto LABEL_156;
  }
  v31 = (__int64)v22;
  link_info_by_vdev = (__int64 *)hdd_get_link_info_by_vdev(v22);
  if ( !link_info_by_vdev )
  {
    v40 = "%s: Invalid vdev";
    goto LABEL_7;
  }
  v33 = *link_info_by_vdev;
  v34 = (__int64)link_info_by_vdev;
  hdd_cm_update_rssi_snr_by_bssid(link_info_by_vdev, v23, v24, v25, v26, v27, v28, v29, v30);
  v35 = *(_DWORD *)(a2 + 60);
  *(_DWORD *)(*(_QWORD *)v34 + 52404LL) = v35;
  *(_DWORD *)(v34 + 844) = v35;
  *(_DWORD *)(v34 + 1540) = v35;
  hdd_init_scan_reject_params(v31);
  qdf_mem_set((void *)(v34 + 916), 0x18u, 0);
  qdf_get_time_of_the_day_in_hr_min_sec_usec(v34 + 916, 24);
  hdd_setup_tsf_sync(v33);
  v36 = *(_DWORD *)(a2 + 4);
  if ( (*(_BYTE *)(a2 + 1) & 4) != 0 )
  {
    v38 = (const void *)(a2 + 8);
    v39 = 21;
    v37 = 0;
  }
  else
  {
    v37 = *(_DWORD *)(a2 + 60);
    v38 = (const void *)(a2 + 8);
    v39 = 18;
    v36 = *(_DWORD *)(a2 + 56) | (v36 << 16);
  }
  wlan_rec_debug_log((char *)&off_0 + 1, *(_BYTE *)a2, v39, 0, v38, 0, v36, v37);
  v42 = *(_QWORD *)v34;
  v354 = context;
  if ( *(_QWORD *)v34 && (v43 = *(_QWORD *)(v42 + 24)) != 0 )
    v44 = *(_QWORD *)(v43 + 16);
  else
    v44 = 0;
  v45 = _qdf_mem_malloc(0x1490u, "hdd_cm_save_connect_info", 1393);
  if ( !v45 )
    goto LABEL_29;
  v46 = *(_DWORD *)(a2 + 8);
  v47 = v45;
  *(_WORD *)(v34 + 312) = *(_WORD *)(a2 + 12);
  *(_DWORD *)(v34 + 308) = v46;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(v34, 97, "hdd_cm_save_connect_info");
  if ( vdev_by_user )
  {
    v57 = a1;
    v58 = vdev_by_user;
    ucfg_dp_conn_info_set_bssid(vdev_by_user, (int *)(a2 + 8), v49, v50, v51, v52, v53, v54, v55, v56);
    v59 = v58;
    a1 = v57;
    _hdd_objmgr_put_vdev_by_user(v59, 97, "hdd_cm_save_connect_info");
  }
  *(_DWORD *)(v34 + 80) = wlan_reg_get_max_phymode(
                            *(_QWORD *)(*(_QWORD *)(v42 + 24) + 8LL),
                            8u,
                            *(_DWORD *)(a2 + 48),
                            v49,
                            v50,
                            v51,
                            v52,
                            v53,
                            v54,
                            v55,
                            v56);
  v60 = *(_QWORD *)(v34 + 32);
  *(_DWORD *)(v34 + 844) = *(_DWORD *)(a2 + 60);
  crypto_params = wlan_crypto_vdev_get_crypto_params(v60);
  if ( crypto_params )
  {
    v62 = (unsigned int *)crypto_params;
    sme_fill_enc_type(v34 + 680, *(unsigned int *)(crypto_params + 4));
    sme_fill_auth_type(v34 + 676, *v62, v62[5], v62[1]);
    *(_DWORD *)(v34 + 888) = *(_DWORD *)(v34 + 676);
  }
  v63 = *(_QWORD *)(*(_QWORD *)(v34 + 32) + 40LL);
  *(_DWORD *)(v34 + 700) = *(_DWORD *)(a2 + 48);
  qdf_mem_copy((void *)(v34 + 317), (const void *)(a2 + 15), *(unsigned __int8 *)(a2 + 14));
  qdf_mem_copy((void *)(v34 + 849), (const void *)(a2 + 15), *(unsigned __int8 *)(a2 + 14));
  v64 = *(_BYTE *)(a2 + 14);
  *(_BYTE *)(v34 + 316) = v64;
  *(_BYTE *)(v34 + 848) = v64;
  v65 = sme_phy_mode_to_dot11mode(*(unsigned int *)(v63 + 28));
  *(_DWORD *)(v34 + 688) = v66;
  v67 = *(_QWORD *)(v34 + 32);
  *(_DWORD *)(v34 + 940) = *(_DWORD *)(v63 + 24);
  if ( (wlan_vdev_mlme_is_mlo_vdev(v67, v65, v68, v69, v70, v71, v72, v73, v74) & 1) != 0 )
  {
    v83 = *(_DWORD *)(a2 + 153);
    *(_WORD *)(v34 + 984) = *(_WORD *)(a2 + 157);
    *(_DWORD *)(v34 + 980) = v83;
  }
  v84 = *(_QWORD *)(a2 + 80);
  v85 = *(unsigned int *)(a2 + 72);
  if ( !v84 || (unsigned int)v85 <= 0x23 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: beacon len is invalid %d",
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      "hdd_cm_save_connect_info",
      v85);
LABEL_28:
    _qdf_mem_free(v47);
    goto LABEL_29;
  }
  if ( (dot11f_unpack_beacon_i_es(v44, v84 + 36, (unsigned int)(v85 - 36), v47, 0) & 0x10000000) != 0 )
  {
    v95 = "%s: Failed to parse beacon ie";
    v96 = "hdd_cm_save_connect_info";
LABEL_27:
    qdf_trace_msg(0x33u, 2u, v95, v86, v87, v88, v89, v90, v91, v92, v93, v96);
    goto LABEL_28;
  }
  if ( *(_BYTE *)(v47 + 1390) )
  {
    v94 = (_DWORD *)(v47 + 1392);
    *(_BYTE *)(v34 + 692) = (*(_DWORD *)(v47 + 1392) & 0x1000) != 0;
  }
  else
  {
    v94 = nullptr;
  }
  v168 = _hdd_objmgr_get_vdev_by_user(v34, 88, "hdd_cm_save_connect_info");
  if ( v168 )
  {
    v177 = v168;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v168, v169, v170, v171, v172, v173, v174, v175, v176);
    if ( cmpt_obj )
      v187 = *(_BYTE *)(cmpt_obj + 23);
    else
      v187 = 0;
    *(_BYTE *)(v34 + 695) = v187;
    *(_BYTE *)(v34 + 996) = wlan_mlme_get_ap_nss(v177, v179, v180, v181, v182, v183, v184, v185, v186);
    ucfg_wlan_vdev_mgr_get_param(v177, 0xBu, v34 + 696);
    v348 = v94;
    v349 = a1;
    v353 = v12;
    if ( v42 && (v200 = *(_QWORD *)(v42 + 24)) != 0 && (v351 = *(_QWORD *)(v200 + 16)) != 0 )
    {
      v347 = *(_DWORD *)(v34 + 676);
      v201 = wlan_vdev_mlme_get_cmpt_obj(v177, v192, v193, v194, v195, v196, v197, v198, v199);
      if ( v201 )
      {
        v202 = *(_BYTE *)(v47 + 3426) || *(_BYTE *)(v47 + 3422) || *(_BYTE *)(v47 + 1256) != 0;
        v346 = v202;
        v203 = *(unsigned __int8 *)(*(_QWORD *)(v201 + 536) + 24007LL);
        acm_mask = sme_qos_get_acm_mask(v351, 0, v47);
        v205 = acm_mask;
        v350 = acm_mask;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: qap is %d, qos_connection is %d, acm_mask is 0x%x",
          v206,
          v207,
          v208,
          v209,
          v210,
          v211,
          v212,
          v213,
          "hdd_wmm_cm_connect",
          v346,
          v203,
          acm_mask);
        *(_BYTE *)(v42 + 3000) = v346;
        *(_BYTE *)(v42 + 3001) = v203;
        if ( v205 )
          ((void (__fastcall *)(__int64, __int64, _BYTE *, __int64))qdf_trace_hex_dump)(53, 8, acm_mask_bit, 4);
        v222 = 0;
        v223 = v346 & v203;
        v224 = v42 + 1880;
        do
        {
          if ( v223 && (v350 & acm_mask_bit[v222]) != 0 )
          {
            v225 = *(unsigned __int8 *)(v224 + 6);
            *(_BYTE *)v224 = 1;
            *(_WORD *)(v224 + 4) = 0;
            if ( v225 == 1 && *(_DWORD *)(v224 + 24) != 1 )
              *(_BYTE *)(v224 + 5) = 1;
            if ( (sme_neighbor_roam_is11r_assoc(v351, *(unsigned __int8 *)(*(_QWORD *)(v42 + 52832) + 8LL)) & 1) == 0
              && ((csr_is_auth_type_ese(v347) & 1) == 0 && (v347 != 1 || !*(_BYTE *)(v47 + 3449))
               || (*(_BYTE *)(*(_QWORD *)(v351 + 8) + 1766LL) & 1) == 0) )
            {
              *(_WORD *)(v224 + 5) = 0;
            }
          }
          else
          {
            *(_BYTE *)v224 = 0;
            *(_BYTE *)(v224 + 5) = 1;
          }
          ++v222;
          v224 += 280;
        }
        while ( v222 != 4 );
        goto LABEL_90;
      }
      v226 = "%s: vdev component object is NULL";
    }
    else
    {
      v226 = "%s: mac handle is null";
    }
    qdf_trace_msg(0x33u, 2u, v226, v192, v193, v194, v195, v196, v197, v198, v199, "hdd_wmm_cm_connect");
LABEL_90:
    if ( v348 )
      ucfg_dp_conn_info_set_arp_service(v177, (*v348 & 0x1000) != 0, v214, v215, v216, v217, v218, v219, v220, v221);
    _hdd_objmgr_put_vdev_by_user(v177, 88, "hdd_cm_save_connect_info");
    a1 = v349;
    v12 = v353;
  }
  _qdf_mem_free(v47);
  v235 = *(_QWORD *)v34;
  if ( *(_QWORD *)v34 && (v236 = *(_QWORD *)(v235 + 24)) != 0 && (v237 = *(_QWORD *)(v236 + 16)) != 0 )
  {
    v238 = _qdf_mem_malloc(0x1310u, "hdd_cm_save_bss_info", 1178);
    if ( v238 )
    {
      v47 = v238;
      qdf_mem_set((void *)(v34 + 772), 4u, 0);
      v239 = *(_QWORD *)(a2 + 80);
      if ( v239 )
        sme_get_hs20vendor_ie(v237, v239, *(unsigned int *)(a2 + 72), v34 + 772);
      if ( !(unsigned int)sme_unpack_assoc_rsp(v237, a2, v47) )
      {
        v332 = *(_BYTE *)(v34 + 771);
        if ( *(_BYTE *)(v47 + 520) )
        {
          *(_BYTE *)(v34 + 771) = v332 | 2;
          hdd_copy_vht_caps((_WORD *)(v34 + 759), v47 + 520);
          v333 = *(_BYTE *)(v34 + 771);
        }
        else
        {
          v333 = v332 & 0xFD;
          *(_BYTE *)(v34 + 771) = v333;
        }
        if ( *(_BYTE *)(v47 + 300) )
        {
          *(_BYTE *)(v34 + 771) = v333 | 1;
          hdd_copy_ht_caps((_WORD *)(v34 + 733), v47 + 300);
        }
        else
        {
          *(_BYTE *)(v34 + 771) = v333 & 0xFE;
        }
        if ( (*(_BYTE *)(a2 + 1) & 4) != 0 )
        {
          v334 = *(_DWORD *)(v34 + 836) + 1;
          *(_DWORD *)(v34 + 836) = v334;
          if ( v334 >= 0x3E8 )
          {
            v335 = jiffies;
            if ( hdd_cm_update_roam_count___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Resetting the roam_count value to 0",
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                "hdd_cm_update_roam_count");
              hdd_cm_update_roam_count___last_ticks = v335;
            }
            *(_DWORD *)(v34 + 836) = 0;
          }
        }
        v336 = *(_BYTE *)(v34 + 771);
        if ( *(_BYTE *)(v47 + 360) )
        {
          *(_BYTE *)(v34 + 771) = v336 | 0x10;
          hdd_copy_ht_operation(v34 + 80, v47 + 360);
          v337 = *(_BYTE *)(v34 + 771);
        }
        else
        {
          v337 = v336 & 0xEF;
          *(_BYTE *)(v34 + 771) = v337;
        }
        if ( *(_BYTE *)(v47 + 536) )
        {
          *(_BYTE *)(v34 + 771) = v337 | 0x20;
          hdd_copy_vht_operation(v34 + 80, v47 + 536);
          v338 = *(_BYTE *)(v34 + 771);
        }
        else
        {
          v338 = v337 & 0xDF;
          *(_BYTE *)(v34 + 771) = v338;
        }
        if ( *(_BYTE *)(v47 + 1340) )
        {
          *(_BYTE *)(v34 + 771) = v338 | 0x40;
          hdd_copy_he_caps((_BYTE *)(v34 + 80), v47 + 1340);
          v339 = *(_BYTE *)(v34 + 771);
        }
        else
        {
          v339 = v338 & 0xBF;
          *(_BYTE *)(v34 + 771) = v339;
        }
        v340 = v339 & 0xFB | (4 * (*(_BYTE *)(v47 + 3264) != 0));
        *(_BYTE *)(v34 + 771) = v340;
        *(_BYTE *)(v34 + 771) = v340 & 0x7F | ((*(_BYTE *)(v47 + 3356) != 0) << 7);
        if ( !*(_DWORD *)(v235 + 40) )
        {
          hdd_cleanup_conn_info(v34);
          hdd_copy_eht_operation(v34 + 80, (_BYTE *)(v47 + 3356));
          qdf_mem_copy((void *)(v34 + 1000), (const void *)(v34 + 304), 0x2B8u);
          hdd_copy_he_operation((_DWORD *)(v34 + 80), v47 + 1400);
          v341 = *(_QWORD *)(v34 + 968);
          if ( v341 )
          {
            _qdf_mem_free(v341);
            *(_QWORD *)(v34 + 968) = 0;
            *(_DWORD *)(v34 + 960) = 0;
          }
          if ( *(_QWORD *)(a2 + 80) )
          {
            v342 = *(_DWORD *)(a2 + 72);
            if ( v342 >= 0x19 )
            {
              v343 = a1;
              v344 = v342 - 24;
              v345 = (void *)_qdf_mem_malloc(v342 - 24, "hdd_cm_update_prev_ap_ie", 1133);
              *(_QWORD *)(v34 + 968) = v345;
              if ( v345 )
                qdf_mem_copy(v345, (const void *)(*(_QWORD *)(a2 + 80) + 24LL), v344);
              else
                v344 = 0;
              *(_DWORD *)(v34 + 960) = v344;
              a1 = v343;
            }
          }
        }
        goto LABEL_28;
      }
      v95 = "%s: could not parse assoc response";
      v96 = "hdd_cm_save_bss_info";
      goto LABEL_27;
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: mac handle is null",
      v227,
      v228,
      v229,
      v230,
      v231,
      v232,
      v233,
      v234,
      "hdd_cm_save_bss_info");
  }
LABEL_29:
  hdd_add_beacon_filter(v31, *(unsigned __int8 *)(v34 + 8));
  v105 = *(unsigned int *)(v33 + 40);
  *(_BYTE *)(v33 + 38933) = (*(_DWORD *)(v34 + 676) & 0xFFFFFFFE) == 12;
  if ( (_DWORD)v105 )
    goto LABEL_40;
  v106 = *(_QWORD *)(a2 + 80);
  if ( v106 )
  {
    v107 = *(_DWORD *)(a2 + 72);
    if ( v107 >= 0x25 )
    {
      is_ap_supports_immediate_power_save = wlan_hdd_is_ap_supports_immediate_power_save(
                                              (unsigned __int8 *)(v106 + 36),
                                              v107 - 36,
                                              v97,
                                              v98,
                                              v99,
                                              v100,
                                              v101,
                                              v102,
                                              v103,
                                              v104);
      if ( v33 )
      {
        if ( (*(_QWORD *)(v33 + 1640) & 1) != 0 )
        {
          v117 = v33 + 52840;
        }
        else
        {
          v117 = v33 + 58928;
          if ( v33 == -58928 || (*(_QWORD *)(v33 + 1640) & 2) == 0 )
          {
            v117 = v33 + 65016;
            if ( v33 == -65016 || (*(_QWORD *)(v33 + 1640) & 4) == 0 )
              goto LABEL_38;
          }
        }
        do
        {
          v188 = *(_DWORD *)v117;
          *(_BYTE *)(v117 + 1696) = is_ap_supports_immediate_power_save & 1;
          LODWORD(v189) = 73 * ((unsigned int)(v117 - v188 - 52840) >> 3) + 1;
          if ( (unsigned __int8)v189 > 2u )
            break;
          v189 = (unsigned __int8)v189;
          v117 = 0;
          v190 = v33 + 52840 + 6088LL * (unsigned __int8)v189;
          do
          {
            if ( v117 )
              break;
            v191 = *(_QWORD *)(v33 + 1640) >> v189++;
            v117 = (v191 << 63 >> 63) & v190;
            v190 += 6088;
          }
          while ( v189 != 3 );
        }
        while ( v117 );
      }
LABEL_38:
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: ap_supports_immediate_power_save flag [%d]",
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        "hdd_cm_connect_success_pre_user_update",
        *(unsigned __int8 *)(v34 + 1696));
      v105 = *(unsigned int *)(v33 + 40);
      goto LABEL_40;
    }
  }
  v105 = 0;
LABEL_40:
  started = hdd_green_ap_start_state_mc(v31, v105, 1);
  hdd_cm_handle_assoc_event(a1, (unsigned __int8 *)(a2 + 8), started, v119, v120, v121, v122, v123, v124, v125);
  is_link_switch_connect_resp = ucfg_cm_is_link_switch_connect_resp(a2);
  if ( (is_link_switch_connect_resp & 1) != 0 )
  {
    v135 = *(_QWORD *)(a1 + 216);
    v136 = *(unsigned __int8 *)(a1 + 93);
    LODWORD(v357) = 8;
    if ( v135 && (v137 = *(_QWORD *)(v135 + 80)) != 0 )
    {
      v138 = (_QWORD *)a1;
      link_info_by_ieee_link_id = hdd_get_link_info_by_ieee_link_id(v33, v136, 0);
      if ( link_info_by_ieee_link_id )
      {
        v148 = link_info_by_ieee_link_id;
        v352 = v12;
        v149 = *(unsigned __int8 *)(link_info_by_ieee_link_id + 1697);
        wlan_mlme_get_sta_ch_width((__int64)v138, &v357, nullptr);
        if ( v149 == 8 )
        {
          v158 = "%s: no cached bandwidth for the link %u";
          v159 = v136;
        }
        else
        {
          if ( (_DWORD)v357 != v149 )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: send vdev id:%u, chwidth:%u",
              v150,
              v151,
              v152,
              v153,
              v154,
              v155,
              v156,
              v157,
              "hdd_cm_mlme_send_standby_link_chn_width",
              *(unsigned __int8 *)(v148 + 8),
              v149);
            v240 = *(_BYTE *)(v148 + 8);
            a1 = (__int64)v138;
            wlan_mlme_send_ch_width_update_with_notify(
              v137,
              v138,
              v240,
              v149,
              v241,
              v242,
              v243,
              v244,
              v245,
              v246,
              v247,
              v248);
            goto LABEL_103;
          }
          v158 = "%s: user config max bd same as connection ch bw:%u";
          v159 = v149;
        }
        qdf_trace_msg(
          0x33u,
          8u,
          v158,
          v150,
          v151,
          v152,
          v153,
          v154,
          v155,
          v156,
          v157,
          "hdd_cm_mlme_send_standby_link_chn_width",
          v159);
        a1 = (__int64)v138;
LABEL_103:
        v12 = v352;
        goto LABEL_104;
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Link info not found by linkid:%u",
        v140,
        v141,
        v142,
        v143,
        v144,
        v145,
        v146,
        v147,
        "hdd_cm_mlme_send_standby_link_chn_width",
        v136);
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to get PSOC Object",
        v127,
        v128,
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        "hdd_cm_mlme_send_standby_link_chn_width");
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: send standby link chn width fail",
      v160,
      v161,
      v162,
      v163,
      v164,
      v165,
      v166,
      v167,
      "hdd_cm_connect_success_pre_user_update");
  }
LABEL_104:
  v249 = v12 & 4;
  if ( policy_mgr_is_mcc_in_24G(*(_QWORD *)v31) && *(_BYTE *)(v31 + 1136) )
    wlan_hdd_set_mas(v33);
  if ( !((v249 != 0) | is_link_switch_connect_resp & 1) )
  {
    *(_DWORD *)(v33 + 1776) = 0;
    *(_BYTE *)(v33 + 1808) = 1;
    wlan_hdd_netif_queue_control(v33, 8, 1);
    wait_for_completion_timeout(v33 + 1776, 15);
    *(_BYTE *)(v33 + 1808) = 0;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
  v251 = comp_private_obj;
  if ( comp_private_obj )
    v252 = *(unsigned __int8 *)(*(_QWORD *)(comp_private_obj + 536) + 24006LL);
  else
    v252 = 0;
  hdd_wmm_assoc(v33, 0, v252);
  v261 = (is_link_switch_connect_resp & 1) == 0
      && ((*(_BYTE *)(a2 + 1) & 3) != 0 || *(_DWORD *)(v34 + 676) >= 3u && *(_BYTE *)(a2 + 152) != 1);
  v262 = v33 + 71144;
  if ( v249 )
  {
    ucfg_mlme_get_roaming_offload(*(_QWORD *)v31, v356);
    if ( v356[0] != 1 )
    {
      v264 = "AUTHENTICATED";
      if ( v261 )
      {
        v264 = "CONNECTED";
        v265 = 2;
      }
      else
      {
        v265 = 3;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: sta: %02x:%02x:%02x:**:**:%02xChanging TL state to %s",
        v253,
        v254,
        v255,
        v256,
        v257,
        v258,
        v259,
        v260,
        "hdd_cm_set_peer_authenticate",
        *(unsigned __int8 *)(a2 + 8),
        *(unsigned __int8 *)(a2 + 9),
        *(unsigned __int8 *)(a2 + 10),
        *(unsigned __int8 *)(a2 + 13),
        v264);
      v262 = v33 + 71144;
      hdd_change_peer_state((unsigned __int8 *)v34, a2 + 8, v265, v266, v267, v268, v269, v270, v271, v272, v273);
      hdd_conn_set_authenticated(v34, !v261, v274, v275, v276, v277, v278, v279, v280, v281);
      v282 = hdd_objmgr_set_peer_mlme_auth_state(*(_QWORD *)(v34 + 32), !v261);
      if ( (is_link_switch_connect_resp & 1) == 0 )
        goto LABEL_131;
      goto LABEL_142;
    }
    v263 = *(_BYTE **)(a2 + 144);
    if ( v263 && *v263 != 2 )
    {
      wlan_acquire_peer_key_wakelock(a1, (unsigned __int8 *)(a2 + 8), v253, v254, v255, v256, v257, v258, v259, v260);
      v261 = 1;
    }
    else
    {
      v261 = 0;
    }
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: is_roam_offload %d is_roam %d vdev repurpose %d is_auth_required %d",
    v253,
    v254,
    v255,
    v256,
    v257,
    v258,
    v259,
    v260,
    "hdd_cm_connect_success_pre_user_update",
    (unsigned __int8)v356[0],
    v249 >> 2,
    is_link_switch_connect_resp & 1,
    v261);
  v282 = hdd_roam_register_sta(
           (__int64 *)v34,
           (unsigned __int8 *)(a2 + 8),
           v261,
           v291,
           v292,
           v293,
           v294,
           v295,
           v296,
           v297,
           v298);
  if ( (is_link_switch_connect_resp & 1) == 0 )
  {
LABEL_131:
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Enabling queues",
      v283,
      v284,
      v285,
      v286,
      v287,
      v288,
      v289,
      v290,
      "hdd_cm_connect_success_pre_user_update");
    v282 = hdd_cm_netif_queue_enable(v33, v299, v300, v301, v302, v303, v304, v305, v306);
    if ( !*(_DWORD *)(v33 + 40) )
    {
      if ( v354 && *v354 && (v315 = *(_QWORD *)(*v354 + 64LL)) != 0 )
      {
        v316 = *(__int64 (__fastcall **)(_QWORD))(v315 + 248);
        if ( v316 )
        {
          if ( *((_DWORD *)v316 - 1) != -1106481425 )
            __break(0x8228u);
          v282 = v316(v354);
        }
      }
      else
      {
        v282 = qdf_trace_msg(
                 0x89u,
                 8u,
                 "%s: Invalid Instance",
                 v307,
                 v308,
                 v309,
                 v310,
                 v311,
                 v312,
                 v313,
                 v314,
                 "cdp_reset_rx_hw_ext_stats");
      }
    }
    if ( *(_WORD *)v262 )
      v282 = hdd_vdev_send_sta_keep_alive_interval(v34, v31, *(_WORD *)v262);
  }
LABEL_142:
  if ( v251 )
  {
    v317 = *(unsigned __int8 *)(v34 + 8);
    v318 = *(unsigned int *)(v33 + 40);
    v319 = *(_QWORD *)(v251 + 536) + 20480LL;
    v320 = *(unsigned __int8 *)(*(_QWORD *)(v251 + 536) + 23960LL);
    v321 = *(_QWORD *)(v251 + 536) == -23964;
    v362 = 0;
    v360 = 0;
    v361 = 0;
    v358 = 0;
    v359 = 0;
    v357 = 0;
    if ( v321 )
    {
      v322 = nullptr;
    }
    else
    {
      v322 = &v357;
      HIDWORD(v357) = *(_DWORD *)(v319 + 3484);
      v358 = *(_QWORD *)(v319 + 3488);
      v359 = *(_QWORD *)(v319 + 3496);
      LODWORD(v360) = *(_DWORD *)(v319 + 3504);
      BYTE4(v360) = *(_BYTE *)(v319 + 3508);
      LODWORD(v361) = *(_DWORD *)(v319 + 3512);
      BYTE4(v361) = *(_BYTE *)(v319 + 3516);
      v362 = *(_DWORD *)(v319 + 3520);
    }
    v282 = os_if_wifi_pos_send_peer_status(a2 + 8, 1, v320, v317, v322, v318);
  }
  if ( !(v261 | ((ucfg_ipa_is_enabled(v282) & 1) == 0)) )
  {
    if ( (unsigned int)hdd_ipa_get_tx_pipe(v31, v34, v355) )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Failed to get alternate pipe for vdev %d",
        v323,
        v324,
        v325,
        v326,
        v327,
        v328,
        v329,
        v330,
        "hdd_cm_connect_success_pre_user_update",
        *(unsigned __int8 *)(v34 + 8));
      v331 = 0;
      v355[0] = 0;
    }
    else
    {
      v331 = v355[0];
    }
    ucfg_ipa_wlan_evt(
      *(_QWORD *)(v31 + 8),
      *(_QWORD *)(v33 + 32),
      *(unsigned int *)(v33 + 40),
      *(unsigned __int8 *)(v34 + 8),
      4,
      a2 + 8,
      v331 & 1);
  }
  result = qdf_dp_trace_mgmt_pkt(5, *(_BYTE *)(v34 + 8), 0xFFu, 3, 28);
  if ( v249 )
    result = ucfg_dp_nud_indicate_roam();
  if ( *(_BYTE *)(v262 + 57) == 1 )
    result = hdd_enable_active_apf_mode(v34);
LABEL_156:
  _ReadStatusReg(SP_EL0);
  return result;
}
