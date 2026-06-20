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
  _QWORD *context; // x23
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
  __int64 v42; // x24
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
  __int64 v57; // x27
  __int64 v58; // x0
  __int64 crypto_params; // x0
  unsigned int *v60; // x19
  __int64 v61; // x19
  char v62; // w8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x8
  __int64 v72; // x4
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  _DWORD *v81; // x19
  const char *v82; // x2
  const char *v83; // x3
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 v92; // x1
  __int64 v93; // x8
  unsigned int v94; // w9
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  unsigned int v103; // w24
  double started; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  char is_link_switch_connect_resp; // w27
  __int64 comp_private_obj; // x0
  __int64 v114; // x26
  __int64 v115; // x2
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  unsigned int v124; // w25
  __int64 v125; // x19
  _BYTE *v126; // x8
  const char *v127; // x8
  int v128; // w28
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  __int64 v145; // x0
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
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
  double v170; // d0
  double v171; // d1
  double v172; // d2
  double v173; // d3
  double v174; // d4
  double v175; // d5
  double v176; // d6
  double v177; // d7
  __int64 v178; // x8
  __int64 (__fastcall *v179)(_QWORD); // x8
  __int64 v180; // x3
  __int64 v181; // x5
  __int64 v182; // x8
  __int64 v183; // x2
  bool v184; // zf
  __int64 *v185; // x4
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  char v194; // w8
  __int64 v195; // x0
  double v196; // d0
  double v197; // d1
  double v198; // d2
  double v199; // d3
  double v200; // d4
  double v201; // d5
  double v202; // d6
  double v203; // d7
  __int64 v204; // x26
  __int64 cmpt_obj; // x0
  double v206; // d0
  double v207; // d1
  double v208; // d2
  double v209; // d3
  double v210; // d4
  double v211; // d5
  double v212; // d6
  double v213; // d7
  char v214; // w8
  double v215; // d0
  double v216; // d1
  double v217; // d2
  double v218; // d3
  double v219; // d4
  double v220; // d5
  double v221; // d6
  double v222; // d7
  __int64 v223; // x8
  __int64 v224; // x0
  _BOOL4 v225; // w27
  unsigned int v226; // w26
  unsigned __int8 acm_mask; // w0
  int v228; // w19
  double v229; // d0
  double v230; // d1
  double v231; // d2
  double v232; // d3
  double v233; // d4
  double v234; // d5
  double v235; // d6
  double v236; // d7
  double v237; // d0
  double v238; // d1
  double v239; // d2
  double v240; // d3
  double v241; // d4
  double v242; // d5
  double v243; // d6
  double v244; // d7
  __int64 v245; // x19
  int v246; // w27
  __int64 v247; // x26
  int v248; // w8
  const char *v249; // x2
  double v250; // d0
  double v251; // d1
  double v252; // d2
  double v253; // d3
  double v254; // d4
  double v255; // d5
  double v256; // d6
  double v257; // d7
  __int64 v258; // x19
  __int64 v259; // x8
  __int64 v260; // x26
  __int64 v261; // x0
  __int64 v262; // x1
  char v263; // w8
  char v264; // w8
  unsigned int v265; // w8
  __int64 v266; // x26
  char v267; // w8
  char v268; // w8
  char v269; // w8
  char v270; // w8
  char v271; // w8
  __int64 v272; // x0
  unsigned int v273; // w8
  unsigned int v274; // w26
  void *v275; // x0
  unsigned int v276; // [xsp+Ch] [xbp-74h]
  __int64 v277; // [xsp+10h] [xbp-70h]
  _DWORD *v278; // [xsp+18h] [xbp-68h]
  unsigned __int8 v279; // [xsp+24h] [xbp-5Ch]
  __int64 v280; // [xsp+28h] [xbp-58h]
  _QWORD *v281; // [xsp+30h] [xbp-50h]
  __int64 v282; // [xsp+38h] [xbp-48h]
  _BYTE v283[4]; // [xsp+40h] [xbp-40h] BYREF
  char v284[4]; // [xsp+44h] [xbp-3Ch] BYREF
  __int64 v285; // [xsp+48h] [xbp-38h] BYREF
  __int64 v286; // [xsp+50h] [xbp-30h]
  __int64 v287; // [xsp+58h] [xbp-28h]
  __int64 v288; // [xsp+60h] [xbp-20h]
  __int64 v289; // [xsp+68h] [xbp-18h]
  int v290; // [xsp+70h] [xbp-10h]
  __int64 v291; // [xsp+78h] [xbp-8h]

  v291 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_BYTE *)(a2 + 1);
  v284[0] = 0;
  context = _cds_get_context(71, (__int64)"hdd_cm_connect_success_pre_user_update", a3, a4, a5, a6, a7, a8, a9, a10);
  v283[0] = 0;
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
    goto LABEL_84;
  }
  v31 = (__int64)v22;
  link_info_by_vdev = (__int64 *)hdd_get_link_info_by_vdev(v22);
  if ( !link_info_by_vdev )
  {
    v40 = "%s: Invalid vdev";
    goto LABEL_7;
  }
  v281 = context;
  v33 = *link_info_by_vdev;
  v34 = (__int64)link_info_by_vdev;
  hdd_cm_update_rssi_snr_by_bssid(link_info_by_vdev, v23, v24, v25, v26, v27, v28, v29, v30);
  v35 = *(_DWORD *)(a2 + 60);
  *(_DWORD *)(*(_QWORD *)v34 + 52404LL) = v35;
  *(_DWORD *)(v34 + 836) = v35;
  *(_DWORD *)(v34 + 1516) = v35;
  hdd_init_scan_reject_params(v31);
  qdf_mem_set((void *)(v34 + 908), 0x18u, 0);
  qdf_get_time_of_the_day_in_hr_min_sec_usec(v34 + 908, 24);
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
  v282 = a1;
  if ( *(_QWORD *)v34 && (v43 = *(_QWORD *)(v42 + 24)) != 0 )
    v44 = *(_QWORD *)(v43 + 16);
  else
    v44 = 0;
  v45 = _qdf_mem_malloc(0x1490u, "hdd_cm_save_connect_info", 1393);
  if ( !v45 )
    goto LABEL_27;
  v46 = *(_DWORD *)(a2 + 8);
  v47 = v45;
  *(_WORD *)(v34 + 304) = *(_WORD *)(a2 + 12);
  *(_DWORD *)(v34 + 300) = v46;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(v34, 97, "hdd_cm_save_connect_info");
  if ( vdev_by_user )
  {
    v57 = vdev_by_user;
    ucfg_dp_conn_info_set_bssid(vdev_by_user, (int *)(a2 + 8), v49, v50, v51, v52, v53, v54, v55, v56);
    _hdd_objmgr_put_vdev_by_user(v57, 97, "hdd_cm_save_connect_info");
  }
  *(_DWORD *)(v34 + 80) = wlan_reg_get_max_phymode(
                            *(_QWORD *)(*(_QWORD *)(v42 + 24) + 8LL),
                            7u,
                            *(_DWORD *)(a2 + 48),
                            v49,
                            v50,
                            v51,
                            v52,
                            v53,
                            v54,
                            v55,
                            v56);
  v58 = *(_QWORD *)(v34 + 32);
  *(_DWORD *)(v34 + 836) = *(_DWORD *)(a2 + 60);
  crypto_params = wlan_crypto_vdev_get_crypto_params(v58);
  if ( crypto_params )
  {
    v60 = (unsigned int *)crypto_params;
    sme_fill_enc_type(v34 + 672, *(unsigned int *)(crypto_params + 4));
    sme_fill_auth_type(v34 + 668, *v60, v60[5], v60[1]);
    *(_DWORD *)(v34 + 880) = *(_DWORD *)(v34 + 668);
  }
  v61 = *(_QWORD *)(*(_QWORD *)(v34 + 32) + 40LL);
  *(_DWORD *)(v34 + 692) = *(_DWORD *)(a2 + 48);
  qdf_mem_copy((void *)(v34 + 309), (const void *)(a2 + 15), *(unsigned __int8 *)(a2 + 14));
  qdf_mem_copy((void *)(v34 + 841), (const void *)(a2 + 15), *(unsigned __int8 *)(a2 + 14));
  v62 = *(_BYTE *)(a2 + 14);
  *(_BYTE *)(v34 + 308) = v62;
  *(_BYTE *)(v34 + 840) = v62;
  *(_DWORD *)(v34 + 680) = sme_phy_mode_to_dot11mode(*(unsigned int *)(v61 + 28));
  *(_DWORD *)(v34 + 932) = *(_DWORD *)(v61 + 24);
  v71 = *(_QWORD *)(a2 + 80);
  v72 = *(unsigned int *)(a2 + 72);
  if ( !v71 || (unsigned int)v72 <= 0x23 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: beacon len is invalid %d",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "hdd_cm_save_connect_info",
      v72);
LABEL_26:
    _qdf_mem_free(v47);
    goto LABEL_27;
  }
  if ( (dot11f_unpack_beacon_i_es(v44, v71 + 36, (unsigned int)(v72 - 36), v47, 0) & 0x10000000) != 0 )
  {
    v82 = "%s: Failed to parse beacon ie";
    v83 = "hdd_cm_save_connect_info";
LABEL_25:
    qdf_trace_msg(0x33u, 2u, v82, v73, v74, v75, v76, v77, v78, v79, v80, v83);
    goto LABEL_26;
  }
  if ( *(_BYTE *)(v47 + 1390) )
  {
    v81 = (_DWORD *)(v47 + 1392);
    *(_BYTE *)(v34 + 684) = (*(_DWORD *)(v47 + 1392) & 0x1000) != 0;
  }
  else
  {
    v81 = nullptr;
  }
  v195 = _hdd_objmgr_get_vdev_by_user(v34, 88, "hdd_cm_save_connect_info");
  if ( v195 )
  {
    v204 = v195;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v195, v196, v197, v198, v199, v200, v201, v202, v203);
    if ( cmpt_obj )
      v214 = *(_BYTE *)(cmpt_obj + 23);
    else
      v214 = 0;
    *(_BYTE *)(v34 + 687) = v214;
    *(_BYTE *)(v34 + 968) = wlan_mlme_get_ap_nss(v204, v206, v207, v208, v209, v210, v211, v212, v213);
    ucfg_wlan_vdev_mgr_get_param(v204, 0xBu, v34 + 688);
    v277 = v204;
    v278 = v81;
    if ( v42 && (v223 = *(_QWORD *)(v42 + 24)) != 0 && (v280 = *(_QWORD *)(v223 + 16)) != 0 )
    {
      v276 = *(_DWORD *)(v34 + 668);
      v224 = wlan_vdev_mlme_get_cmpt_obj(v204, v215, v216, v217, v218, v219, v220, v221, v222);
      if ( v224 )
      {
        v225 = *(_BYTE *)(v47 + 3426) || *(_BYTE *)(v47 + 3422) || *(_BYTE *)(v47 + 1256) != 0;
        v226 = *(unsigned __int8 *)(*(_QWORD *)(v224 + 520) + 24007LL);
        acm_mask = sme_qos_get_acm_mask(v280, 0, v47);
        v228 = acm_mask;
        v279 = acm_mask;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: qap is %d, qos_connection is %d, acm_mask is 0x%x",
          v229,
          v230,
          v231,
          v232,
          v233,
          v234,
          v235,
          v236,
          "hdd_wmm_cm_connect",
          v225,
          v226,
          acm_mask);
        *(_BYTE *)(v42 + 3000) = v225;
        *(_BYTE *)(v42 + 3001) = v226;
        if ( v228 )
          ((void (__fastcall *)(__int64, __int64, _BYTE *, __int64))qdf_trace_hex_dump)(53, 8, acm_mask_bit, 4);
        v245 = 0;
        v246 = v225 & v226;
        v247 = v42 + 1880;
        do
        {
          if ( v246 && (v279 & acm_mask_bit[v245]) != 0 )
          {
            v248 = *(unsigned __int8 *)(v247 + 6);
            *(_BYTE *)v247 = 1;
            *(_WORD *)(v247 + 4) = 0;
            if ( v248 == 1 && *(_DWORD *)(v247 + 24) != 1 )
              *(_BYTE *)(v247 + 5) = 1;
            if ( (sme_neighbor_roam_is11r_assoc(v280, *(unsigned __int8 *)(*(_QWORD *)(v42 + 52824) + 8LL)) & 1) == 0
              && ((csr_is_auth_type_ese(v276) & 1) == 0 && (v276 != 1 || !*(_BYTE *)(v47 + 3449))
               || (*(_BYTE *)(*(_QWORD *)(v280 + 8) + 1562LL) & 1) == 0) )
            {
              *(_WORD *)(v247 + 5) = 0;
            }
          }
          else
          {
            *(_BYTE *)v247 = 0;
            *(_BYTE *)(v247 + 5) = 1;
          }
          ++v245;
          v247 += 280;
        }
        while ( v245 != 4 );
        goto LABEL_115;
      }
      v249 = "%s: vdev component object is NULL";
    }
    else
    {
      v249 = "%s: mac handle is null";
    }
    qdf_trace_msg(0x33u, 2u, v249, v215, v216, v217, v218, v219, v220, v221, v222, "hdd_wmm_cm_connect");
LABEL_115:
    if ( v278 )
      ucfg_dp_conn_info_set_arp_service(v277, (*v278 & 0x1000) != 0, v237, v238, v239, v240, v241, v242, v243, v244);
    _hdd_objmgr_put_vdev_by_user(v277, 88, "hdd_cm_save_connect_info");
  }
  _qdf_mem_free(v47);
  v258 = *(_QWORD *)v34;
  if ( *(_QWORD *)v34 && (v259 = *(_QWORD *)(v258 + 24)) != 0 && (v260 = *(_QWORD *)(v259 + 16)) != 0 )
  {
    v261 = _qdf_mem_malloc(0x1310u, "hdd_cm_save_bss_info", 1178);
    if ( v261 )
    {
      v47 = v261;
      qdf_mem_set((void *)(v34 + 764), 4u, 0);
      v262 = *(_QWORD *)(a2 + 80);
      if ( v262 )
        sme_get_hs20vendor_ie(v260, v262, *(unsigned int *)(a2 + 72), v34 + 764);
      if ( !(unsigned int)sme_unpack_assoc_rsp(v260, a2, v47) )
      {
        v263 = *(_BYTE *)(v34 + 763);
        if ( *(_BYTE *)(v47 + 520) )
        {
          *(_BYTE *)(v34 + 763) = v263 | 2;
          hdd_copy_vht_caps((_WORD *)(v34 + 751), v47 + 520);
          v264 = *(_BYTE *)(v34 + 763);
        }
        else
        {
          v264 = v263 & 0xFD;
          *(_BYTE *)(v34 + 763) = v264;
        }
        if ( *(_BYTE *)(v47 + 300) )
        {
          *(_BYTE *)(v34 + 763) = v264 | 1;
          hdd_copy_ht_caps((_WORD *)(v34 + 725), v47 + 300);
        }
        else
        {
          *(_BYTE *)(v34 + 763) = v264 & 0xFE;
        }
        if ( (*(_BYTE *)(a2 + 1) & 4) != 0 )
        {
          v265 = *(_DWORD *)(v34 + 828) + 1;
          *(_DWORD *)(v34 + 828) = v265;
          if ( v265 >= 0x3E8 )
          {
            v266 = jiffies;
            if ( hdd_cm_update_roam_count___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Resetting the roam_count value to 0",
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                "hdd_cm_update_roam_count");
              hdd_cm_update_roam_count___last_ticks = v266;
            }
            *(_DWORD *)(v34 + 828) = 0;
          }
        }
        v267 = *(_BYTE *)(v34 + 763);
        if ( *(_BYTE *)(v47 + 360) )
        {
          *(_BYTE *)(v34 + 763) = v267 | 0x10;
          hdd_copy_ht_operation(v34 + 80, v47 + 360);
          v268 = *(_BYTE *)(v34 + 763);
        }
        else
        {
          v268 = v267 & 0xEF;
          *(_BYTE *)(v34 + 763) = v268;
        }
        if ( *(_BYTE *)(v47 + 536) )
        {
          *(_BYTE *)(v34 + 763) = v268 | 0x20;
          hdd_copy_vht_operation(v34 + 80, v47 + 536);
          v269 = *(_BYTE *)(v34 + 763);
        }
        else
        {
          v269 = v268 & 0xDF;
          *(_BYTE *)(v34 + 763) = v269;
        }
        if ( *(_BYTE *)(v47 + 1340) )
        {
          *(_BYTE *)(v34 + 763) = v269 | 0x40;
          hdd_copy_he_caps((_BYTE *)(v34 + 80), v47 + 1340);
          v270 = *(_BYTE *)(v34 + 763);
        }
        else
        {
          v270 = v269 & 0xBF;
          *(_BYTE *)(v34 + 763) = v270;
        }
        v271 = v270 & 0xFB | (4 * (*(_BYTE *)(v47 + 3264) != 0));
        *(_BYTE *)(v34 + 763) = v271;
        *(_BYTE *)(v34 + 763) = v271 & 0x7F | ((*(_BYTE *)(v47 + 3356) != 0) << 7);
        if ( !*(_DWORD *)(v258 + 40) )
        {
          hdd_cleanup_conn_info(v34);
          qdf_mem_copy((void *)(v34 + 976), (const void *)(v34 + 296), 0x2A8u);
          hdd_copy_he_operation((_DWORD *)(v34 + 80), v47 + 1400);
          v272 = *(_QWORD *)(v34 + 960);
          if ( v272 )
          {
            _qdf_mem_free(v272);
            *(_QWORD *)(v34 + 960) = 0;
            *(_DWORD *)(v34 + 952) = 0;
          }
          if ( *(_QWORD *)(a2 + 80) )
          {
            v273 = *(_DWORD *)(a2 + 72);
            if ( v273 >= 0x19 )
            {
              v274 = v273 - 24;
              v275 = (void *)_qdf_mem_malloc(v273 - 24, "hdd_cm_update_prev_ap_ie", 1133);
              *(_QWORD *)(v34 + 960) = v275;
              if ( v275 )
                qdf_mem_copy(v275, (const void *)(*(_QWORD *)(a2 + 80) + 24LL), v274);
              else
                v274 = 0;
              *(_DWORD *)(v34 + 952) = v274;
            }
          }
        }
        goto LABEL_26;
      }
      v82 = "%s: could not parse assoc response";
      v83 = "hdd_cm_save_bss_info";
      goto LABEL_25;
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: mac handle is null",
      v250,
      v251,
      v252,
      v253,
      v254,
      v255,
      v256,
      v257,
      "hdd_cm_save_bss_info");
  }
LABEL_27:
  hdd_add_beacon_filter(v31, *(unsigned __int8 *)(v34 + 8));
  v92 = *(unsigned int *)(v33 + 40);
  *(_BYTE *)(v33 + 38933) = (*(_DWORD *)(v34 + 668) & 0xFFFFFFFE) == 12;
  if ( !(_DWORD)v92 )
  {
    v93 = *(_QWORD *)(a2 + 80);
    if ( v93 && (v94 = *(_DWORD *)(a2 + 72), v94 >= 0x25) )
    {
      *(_BYTE *)(*(_QWORD *)(v33 + 52824) + 1656LL) = wlan_hdd_is_ap_supports_immediate_power_save(
                                                        (unsigned __int8 *)(v93 + 36),
                                                        v94 - 36,
                                                        v84,
                                                        v85,
                                                        v86,
                                                        v87,
                                                        v88,
                                                        v89,
                                                        v90,
                                                        v91)
                                                    & 1;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: ap_supports_immediate_power_save flag [%d]",
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        "hdd_cm_connect_success_pre_user_update",
        *(unsigned __int8 *)(v34 + 1656));
      v92 = *(unsigned int *)(v33 + 40);
    }
    else
    {
      v92 = 0;
    }
  }
  v103 = v12 & 4;
  started = hdd_green_ap_start_state_mc(v31, v92, 1);
  hdd_cm_handle_assoc_event(v282, (unsigned __int8 *)(a2 + 8), started, v105, v106, v107, v108, v109, v110, v111);
  is_link_switch_connect_resp = ucfg_cm_is_link_switch_connect_resp(a2);
  if ( policy_mgr_is_mcc_in_24G(*(_QWORD *)v31) && *(_BYTE *)(v31 + 1136) )
    wlan_hdd_set_mas(v33);
  if ( !((v103 != 0) | is_link_switch_connect_resp & 1) )
  {
    *(_DWORD *)(v33 + 1776) = 0;
    *(_BYTE *)(v33 + 1808) = 1;
    wlan_hdd_netif_queue_control(v33, 8, 1);
    wait_for_completion_timeout(v33 + 1776, 15);
    *(_BYTE *)(v33 + 1808) = 0;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v282, 0);
  v114 = comp_private_obj;
  if ( comp_private_obj )
    v115 = *(unsigned __int8 *)(*(_QWORD *)(comp_private_obj + 520) + 24006LL);
  else
    v115 = 0;
  hdd_wmm_assoc(v33, 0, v115);
  if ( (is_link_switch_connect_resp & 1) != 0
    || (*(_BYTE *)(a2 + 1) & 3) == 0 && (*(_DWORD *)(v34 + 668) < 3u || *(_BYTE *)(a2 + 152) == 1) )
  {
    v124 = 0;
    v125 = v33 + 57392;
    if ( (v12 & 4) == 0 )
      goto LABEL_58;
  }
  else
  {
    v124 = 1;
    v125 = v33 + 57392;
    if ( (v12 & 4) == 0 )
      goto LABEL_58;
  }
  ucfg_mlme_get_roaming_offload(*(_QWORD *)v31, v284);
  if ( v284[0] != 1 )
  {
    v127 = "AUTHENTICATED";
    if ( v124 )
    {
      v127 = "CONNECTED";
      v128 = 2;
    }
    else
    {
      v128 = 3;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: sta: %02x:%02x:%02x:**:**:%02xChanging TL state to %s",
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      "hdd_cm_set_peer_authenticate",
      *(unsigned __int8 *)(a2 + 8),
      *(unsigned __int8 *)(a2 + 9),
      *(unsigned __int8 *)(a2 + 10),
      *(unsigned __int8 *)(a2 + 13),
      v127);
    hdd_change_peer_state((unsigned __int8 *)v34, a2 + 8, v128, v129, v130, v131, v132, v133, v134, v135, v136);
    hdd_conn_set_authenticated(v34, v124 ^ 1, v137, v138, v139, v140, v141, v142, v143, v144);
    v145 = hdd_objmgr_set_peer_mlme_auth_state(*(_QWORD *)(v34 + 32), v124 ^ 1);
    if ( (is_link_switch_connect_resp & 1) == 0 )
      goto LABEL_59;
    goto LABEL_70;
  }
  v126 = *(_BYTE **)(a2 + 144);
  if ( v126 && *v126 != 2 )
  {
    wlan_acquire_peer_key_wakelock(v282, (unsigned __int8 *)(a2 + 8), v116, v117, v118, v119, v120, v121, v122, v123);
    v124 = 1;
  }
  else
  {
    v124 = 0;
  }
LABEL_58:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: is_roam_offload %d is_roam %d vdev repurpose %d is_auth_required %d",
    v116,
    v117,
    v118,
    v119,
    v120,
    v121,
    v122,
    v123,
    "hdd_cm_connect_success_pre_user_update",
    (unsigned __int8)v284[0],
    v103 >> 2,
    is_link_switch_connect_resp & 1,
    v124);
  v145 = hdd_roam_register_sta(
           (__int64 *)v34,
           (unsigned __int8 *)(a2 + 8),
           v124,
           v154,
           v155,
           v156,
           v157,
           v158,
           v159,
           v160,
           v161);
  if ( (is_link_switch_connect_resp & 1) == 0 )
  {
LABEL_59:
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Enabling queues",
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      v152,
      v153,
      "hdd_cm_connect_success_pre_user_update");
    v145 = hdd_cm_netif_queue_enable(v33, v162, v163, v164, v165, v166, v167, v168, v169);
    if ( !*(_DWORD *)(v33 + 40) )
    {
      if ( v281 && *v281 && (v178 = *(_QWORD *)(*v281 + 64LL)) != 0 )
      {
        v179 = *(__int64 (__fastcall **)(_QWORD))(v178 + 248);
        if ( v179 )
        {
          if ( *((_DWORD *)v179 - 1) != -1106481425 )
            __break(0x8228u);
          v145 = v179(v281);
        }
      }
      else
      {
        v145 = qdf_trace_msg(
                 0x89u,
                 8u,
                 "%s: Invalid Instance",
                 v170,
                 v171,
                 v172,
                 v173,
                 v174,
                 v175,
                 v176,
                 v177,
                 "cdp_reset_rx_hw_ext_stats");
      }
    }
    if ( *(_WORD *)v125 )
      v145 = hdd_vdev_send_sta_keep_alive_interval(v34, v31, *(_WORD *)v125);
  }
LABEL_70:
  if ( v114 )
  {
    v180 = *(unsigned __int8 *)(v34 + 8);
    v181 = *(unsigned int *)(v33 + 40);
    v182 = *(_QWORD *)(v114 + 520) + 20480LL;
    v183 = *(unsigned __int8 *)(*(_QWORD *)(v114 + 520) + 23960LL);
    v184 = *(_QWORD *)(v114 + 520) == -23964;
    v290 = 0;
    v288 = 0;
    v289 = 0;
    v286 = 0;
    v287 = 0;
    v285 = 0;
    if ( v184 )
    {
      v185 = nullptr;
    }
    else
    {
      v185 = &v285;
      HIDWORD(v285) = *(_DWORD *)(v182 + 3484);
      v286 = *(_QWORD *)(v182 + 3488);
      v287 = *(_QWORD *)(v182 + 3496);
      LODWORD(v288) = *(_DWORD *)(v182 + 3504);
      BYTE4(v288) = *(_BYTE *)(v182 + 3508);
      LODWORD(v289) = *(_DWORD *)(v182 + 3512);
      BYTE4(v289) = *(_BYTE *)(v182 + 3516);
      v290 = *(_DWORD *)(v182 + 3520);
    }
    v145 = os_if_wifi_pos_send_peer_status(a2 + 8, 1, v183, v180, v185, v181);
  }
  if ( !(v124 & 1 | ((ucfg_ipa_is_enabled(v145) & 1) == 0)) )
  {
    if ( (unsigned int)hdd_ipa_get_tx_pipe(v31, v34, v283) )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Failed to get alternate pipe for vdev %d",
        v186,
        v187,
        v188,
        v189,
        v190,
        v191,
        v192,
        v193,
        "hdd_cm_connect_success_pre_user_update",
        *(unsigned __int8 *)(v34 + 8));
      v194 = 0;
      v283[0] = 0;
    }
    else
    {
      v194 = v283[0];
    }
    ucfg_ipa_wlan_evt(
      *(_QWORD *)(v31 + 8),
      *(_QWORD *)(v33 + 32),
      *(unsigned int *)(v33 + 40),
      *(unsigned __int8 *)(v34 + 8),
      4,
      a2 + 8,
      v194 & 1);
  }
  result = qdf_dp_trace_mgmt_pkt(5, *(_BYTE *)(v34 + 8), 0xFFu, 3, 28);
  if ( v103 )
    result = ucfg_dp_nud_indicate_roam();
  if ( *(_BYTE *)(v125 + 57) == 1 )
    result = hdd_enable_active_apf_mode(v34);
LABEL_84:
  _ReadStatusReg(SP_EL0);
  return result;
}
