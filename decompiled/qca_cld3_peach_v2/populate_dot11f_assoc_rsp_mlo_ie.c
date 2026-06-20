__int64 __fastcall populate_dot11f_assoc_rsp_mlo_ie(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 *a4)
{
  __int64 result; // x0
  __int64 v6; // x27
  __int16 v8; // w9
  __int16 v9; // w8
  __int64 v10; // x9
  __int64 v11; // x8
  __int16 v12; // w8
  __int64 v13; // x9
  char v14; // w10
  char is_hw_emlsr_capable; // w23
  __int16 v16; // w9
  __int16 v17; // w23
  char v18; // w21
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w26
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  char v44; // w24
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int16 v61; // w8
  __int16 v62; // w10
  __int16 v63; // w12
  __int64 v64; // x21
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  char v73; // w10
  char v74; // w9
  unsigned int v75; // w8
  _WORD *v76; // x20
  __int64 v77; // x8
  __int64 v78; // x26
  unsigned __int64 v79; // x20
  unsigned __int64 v80; // x19
  unsigned __int8 *v81; // x23
  unsigned __int8 v82; // w22
  __int64 partner_session_by_link_id; // x0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  _BYTE *v92; // x28
  __int64 v93; // x0
  _WORD *v94; // x25
  __int64 v95; // x24
  _BYTE *v96; // x26
  __int64 v97; // x21
  char v98; // w0
  __int16 v99; // w8
  char v100; // w8
  void *v101; // x0
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  _BYTE *v110; // x24
  unsigned int v111; // w27
  __int64 v112; // x19
  __int16 v113; // w9
  _BYTE *v114; // x22
  void *v115; // x0
  int v116; // w8
  unsigned int v117; // w21
  int v118; // w8
  int v119; // w8
  __int64 v120; // x8
  __int64 v121; // x8
  int v122; // w8
  int v123; // w8
  int v124; // w8
  int v125; // w8
  int vdev_remaining_channel_switch_time; // w0
  __int64 v127; // x11
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  int v129; // w8
  int v130; // w0
  int v131; // w0
  int v132; // w10
  _BOOL4 v133; // w21
  _BOOL4 v134; // w24
  _BOOL4 v135; // w8
  char v136; // w8
  __int64 v137; // x25
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  int v146; // w8
  __int64 v147; // x25
  unsigned __int8 v148; // w21
  int v149; // w8
  unsigned int v150; // w24
  int v151; // w8
  __int64 v152; // x8
  int v153; // w8
  __int64 v154; // x8
  int v155; // w8
  __int64 v156; // x8
  int v157; // w8
  __int64 v158; // x1
  unsigned __int8 *v159; // x20
  _BYTE *v160; // x23
  __int64 v161; // x28
  __int64 v162; // x19
  char v163; // w8
  char *v164; // x0
  __int64 v165; // x24
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  int v174; // w10
  int v175; // w0
  __int64 v176; // x8
  __int16 v177; // w8
  __int64 v178; // [xsp+0h] [xbp-420h]
  __int64 v179; // [xsp+8h] [xbp-418h]
  __int64 v180; // [xsp+18h] [xbp-408h]
  __int64 v181; // [xsp+28h] [xbp-3F8h]
  __int64 v182; // [xsp+30h] [xbp-3F0h]
  int v183; // [xsp+3Ch] [xbp-3E4h]
  unsigned __int64 v184; // [xsp+40h] [xbp-3E0h]
  __int64 v185; // [xsp+48h] [xbp-3D8h]
  unsigned __int64 v186; // [xsp+50h] [xbp-3D0h]
  unsigned int v187; // [xsp+58h] [xbp-3C8h]
  char v188; // [xsp+64h] [xbp-3BCh]
  __int64 v189; // [xsp+68h] [xbp-3B8h]
  _BOOL4 v190; // [xsp+74h] [xbp-3ACh]
  __int64 v191; // [xsp+78h] [xbp-3A8h]
  _BYTE v193[4]; // [xsp+8Ch] [xbp-394h] BYREF
  _WORD v194[2]; // [xsp+90h] [xbp-390h] BYREF
  unsigned __int16 v195; // [xsp+94h] [xbp-38Ch] BYREF
  __int64 v196; // [xsp+98h] [xbp-388h] BYREF
  __int16 v197; // [xsp+A0h] [xbp-380h]
  __int16 v198[2]; // [xsp+A8h] [xbp-378h] BYREF
  unsigned int v199; // [xsp+ACh] [xbp-374h] BYREF
  _WORD v200[2]; // [xsp+B0h] [xbp-370h] BYREF
  int v201; // [xsp+B4h] [xbp-36Ch] BYREF
  _QWORD v202[2]; // [xsp+B8h] [xbp-368h] BYREF
  __int64 v203; // [xsp+C8h] [xbp-358h] BYREF
  int v204; // [xsp+D0h] [xbp-350h]
  __int64 v205; // [xsp+D8h] [xbp-348h] BYREF
  __int64 v206; // [xsp+E0h] [xbp-340h]
  _WORD s[130]; // [xsp+ECh] [xbp-334h] BYREF
  _BYTE v208[16]; // [xsp+1F0h] [xbp-230h] BYREF
  _BYTE v209[16]; // [xsp+200h] [xbp-220h] BYREF
  _BYTE v210[240]; // [xsp+210h] [xbp-210h] BYREF
  _QWORD v211[2]; // [xsp+300h] [xbp-120h]
  _BYTE v212[240]; // [xsp+310h] [xbp-110h] BYREF
  _QWORD v213[4]; // [xsp+400h] [xbp-20h]

  result = 29;
  v213[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v200[0] = 0;
  v194[0] = 0;
  if ( !a1 )
    goto LABEL_279;
  v6 = a2;
  if ( !a2 || !a4 )
    goto LABEL_279;
  *(_QWORD *)((char *)v213 + 7) = 0;
  v213[0] = 0;
  memset(v212, 0, sizeof(v212));
  memset(v209, 0, 14);
  memset(v208, 0, 14);
  *(_QWORD *)((char *)v211 + 7) = 0;
  v211[0] = 0;
  memset(v210, 0, sizeof(v210));
  v204 = 0;
  v202[1] = 0;
  v203 = 0;
  v202[0] = 0;
  v199 = 0;
  v198[0] = 0;
  v196 = 0;
  v197 = 0;
  memset(s, 0, 0x101u);
  v8 = *(_WORD *)(v6 + 10874);
  *(_WORD *)(v6 + 12964) = 255;
  v9 = v8 & 0xFFF8;
  v10 = *(_QWORD *)(v6 + 16);
  *(_BYTE *)(v6 + 12966) = 107;
  *(_WORD *)(v6 + 10874) = v9;
  v11 = *(_QWORD *)(v10 + 1360);
  v195 = 0;
  v205 = 0;
  v206 = 0;
  v193[0] = 0;
  qdf_mem_copy((void *)(v6 + 10877), (const void *)(v11 + 17), 6u);
  v12 = *(_WORD *)(v6 + 10874);
  v13 = *(_QWORD *)(v6 + 16);
  v179 = v6 + 10660;
  *(_WORD *)(v6 + 10874) = v12 | 0x10;
  v14 = *(_BYTE *)(v6 + 10660);
  LOBYTE(v13) = *(_BYTE *)(v13 + 93);
  *(_WORD *)(v6 + 10874) = v12 | 0x30;
  *(_BYTE *)(v6 + 10884) = v14;
  *(_BYTE *)(v6 + 10883) = v13;
  is_hw_emlsr_capable = policy_mgr_is_hw_emlsr_capable(*(_QWORD *)(a1 + 21624));
  wlan_mlme_get_sap_emlsr_mode_enabled(*(_QWORD *)(a1 + 21624), v193);
  if ( (is_hw_emlsr_capable & 1) != 0 && v193[0] == 1 )
  {
    v16 = *(_WORD *)(v6 + 10874);
    *(_BYTE *)(v6 + 10888) = v193[0];
    *(_WORD *)(v6 + 10874) = v16 | 0x80;
    wlan_mlme_get_eml_params(*(_QWORD *)(a1 + 21624), v194);
    v17 = 432;
    *(_WORD *)(v6 + 10888) = *(_WORD *)(v6 + 10888) & 0x87FF | v194[0] & 0x7800;
    v18 = 13;
  }
  else
  {
    v17 = 304;
    v18 = 11;
  }
  *(_WORD *)(v6 + 10874) |= 0x100u;
  lim_get_mlo_vdev_list(v6, &v195, &v205);
  v27 = v195;
  v191 = a1;
  if ( !v195 )
  {
    v44 = 0;
    goto LABEL_32;
  }
  if ( !v205 )
  {
    v44 = v195;
    if ( v195 >= 2u )
      goto LABEL_22;
    goto LABEL_32;
  }
  if ( v205 != *(_QWORD *)(v6 + 16)
    && *(_DWORD *)(v205 + 16) == 1
    && (wlan_vdev_mlme_is_mlo_vdev(v205, v19, v20, v21, v22, v23, v24, v25, v26) & 1) != 0 )
  {
    if ( pe_find_session_by_vdev_id(a1, *(_BYTE *)(v205 + 168), v28, v29, v30, v31, v32, v33, v34, v35) )
    {
      if ( !*(_BYTE *)(a1 + 14881) )
        goto LABEL_21;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: link not active if cac running",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "populate_dot11f_assoc_rsp_mlo_ie");
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: vdev id %d pe session is not created",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "populate_dot11f_assoc_rsp_mlo_ie",
        *(unsigned __int8 *)(v205 + 168));
    }
    LOBYTE(v27) = v27 - 1;
  }
LABEL_21:
  v44 = v27;
  lim_mlo_release_vdev_ref(v205);
  v27 = v195;
  if ( v195 >= 2u )
  {
LABEL_22:
    if ( v206 )
    {
      if ( v206 != *(_QWORD *)(v6 + 16)
        && *(_DWORD *)(v206 + 16) == 1
        && (wlan_vdev_mlme_is_mlo_vdev(v206, v19, v20, v21, v22, v23, v24, v25, v26) & 1) != 0 )
      {
        if ( pe_find_session_by_vdev_id(a1, *(_BYTE *)(v206 + 168), v45, v46, v47, v48, v49, v50, v51, v52) )
        {
          if ( *(_BYTE *)(a1 + 14881) )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: link not active if cac running",
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              "populate_dot11f_assoc_rsp_mlo_ie");
            --v44;
          }
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d pe session is not created",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "populate_dot11f_assoc_rsp_mlo_ie",
            *(unsigned __int8 *)(v206 + 168));
          --v44;
        }
      }
      lim_mlo_release_vdev_ref(v206);
      if ( v195 > 2u )
LABEL_281:
        __break(0x5512u);
    }
    else if ( v27 > 2 )
    {
      goto LABEL_281;
    }
  }
LABEL_32:
  v61 = *(_WORD *)(v6 + 10874);
  v62 = *(_WORD *)(v6 + 10890);
  v63 = *(_WORD *)(v6 + 12967);
  *(_BYTE *)(v6 + 10876) = v18;
  *(_WORD *)(v6 + 10874) = v61 & 0xF9FF;
  *(_WORD *)(v6 + 10890) = v62 & 0xFFF0 | (v44 - 1) & 0xF;
  *(_WORD *)(v6 + 12967) = v61 & 7 | v17 | v63 & 8;
  *(_BYTE *)(v6 + 12969) = v18;
  v64 = v6 + 10660;
  qdf_mem_copy((void *)(v6 + 12970), (const void *)(v6 + 10877), 6u);
  v73 = *(_BYTE *)(v6 + 10874);
  v74 = *(_BYTE *)(v6 + 10884);
  *(_BYTE *)(v6 + 12976) = *(_BYTE *)(v6 + 12976) & 0xF0 | *(_BYTE *)(v6 + 10883) & 0xF;
  *(_BYTE *)(v6 + 12977) = v74;
  v75 = *(unsigned __int16 *)(v6 + 10888);
  if ( v73 < 0 )
  {
    v76 = (_WORD *)(v6 + 12980);
    *(_WORD *)(v6 + 12978) = *(_WORD *)(v6 + 12978) & 0x8000 | v75 & 0x7FFF;
  }
  else
  {
    v76 = (_WORD *)(v6 + 12978);
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: EMLSR support: %d, padding delay: %d, transition delay: %d",
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    "populate_dot11f_assoc_rsp_mlo_ie",
    v75 & 1,
    (v75 >> 1) & 7,
    (v75 >> 4) & 7);
  *v76 = *v76 & 0xFFF0 | *(_WORD *)(v6 + 10890) & 0xF;
  v77 = *(_QWORD *)(v6 + 384);
  *(_WORD *)(v6 + 12962) = (_WORD)v76 - (v6 + 12964) + 2;
  v78 = *(_QWORD *)(v77 + 8LL * *(unsigned __int16 *)(a3 + 348));
  if ( !v78 || !*(_BYTE *)(v78 + 3576) )
  {
    v177 = 0;
    goto LABEL_278;
  }
  v79 = 0;
  v80 = 0;
  v81 = (unsigned __int8 *)(v78 + 3584);
  v178 = 0;
  v180 = v6 + 10898;
  v181 = *(_QWORD *)(v77 + 8LL * *(unsigned __int16 *)(a3 + 348));
  v182 = v6;
  do
  {
    if ( v80 > 4 || v79 == 3 )
      goto LABEL_281;
    v82 = v81[6];
    partner_session_by_link_id = pe_find_partner_session_by_link_id(v6, v82);
    if ( partner_session_by_link_id )
    {
      v92 = (_BYTE *)partner_session_by_link_id;
      v93 = dph_lookup_hash_entry(
              v84,
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              a1,
              v81,
              v200,
              partner_session_by_link_id + 360);
      if ( !v93 )
      {
        lim_mlo_release_vdev_ref(*((_QWORD *)v92 + 2));
        goto LABEL_39;
      }
      v94 = (_WORD *)v93;
      v95 = v180 + 516 * v80;
      v96 = v92 + 7024;
      v189 = *(_QWORD *)(*((_QWORD *)v92 + 48) + 8LL * *(unsigned __int16 *)(v93 + 348));
      *(_WORD *)(v95 + 2) = 0;
      v97 = v95 + 2;
      *(_WORD *)(v95 + 4) = *(_WORD *)(v95 + 4) & 0xFFC0 | v82 & 0xF | 0x30;
      v98 = ((__int64 (*)(void))mlo_get_tsf_sync_support)();
      v99 = *(_WORD *)(v95 + 4);
      if ( (v98 & 1) != 0 )
        v99 |= 0x80u;
      *(_WORD *)(v95 + 4) = v99 | 0x940;
      if ( (((__int64 (*)(void))mlo_get_tsf_sync_support)() & 1) != 0 )
        v100 = 20;
      else
        v100 = 12;
      *(_BYTE *)(v95 + 6) = v100;
      v101 = qdf_mem_copy((void *)(v95 + 7), v92 + 30, 6u);
      *(_WORD *)(v95 + 13) = *((_WORD *)v92 + 3579);
      v185 = v180 + 516 * v80;
      v186 = v80;
      if ( (mlo_get_tsf_sync_support(v101) & 1) != 0 )
      {
        if ( v92[10688] == 1 && *(_BYTE *)(v179 + 28) == 1 )
          v178 = (__int64)(*((_QWORD *)v92 + 1335) - *(_QWORD *)(v6 + 10680)) >> 1;
        *(_QWORD *)(v95 + 15) = v178;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: tsf offset %lld",
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          v109,
          "populate_dot11f_assoc_rsp_mlo_ie",
          v178);
        v110 = (_BYTE *)(v95 + 23);
        v111 = 486;
        v112 = v97;
      }
      else
      {
        v110 = (_BYTE *)(v95 + 15);
        v111 = 494;
        v112 = v97;
      }
      *v110 = 0;
      v110[1] = v92[251];
      v110[2] = v92[10660];
      if ( v92[10177] )
        v113 = 64;
      else
        v113 = 0;
      *((_WORD *)v92 + 5189) = *((_WORD *)v92 + 5189) & 0xFFBF | v113;
      dot11f_pack_ff_capabilities(v191, (__int16 *)v92 + 5189, v110 + 3);
      v198[0] = 0;
      dot11f_pack_ff_status(v191, v198, v110 + 5);
      v114 = v110 + 7;
      qdf_mem_set(v212, 0xFFu, 0);
      qdf_mem_set(v210, 0xFFu, 0);
      qdf_mem_set(v209, 0xEu, 0);
      qdf_mem_set(v208, 0xEu, 0);
      qdf_mem_set(&v196, 0xAu, 0);
      v115 = qdf_mem_set(s, 0x101u, 0);
      populate_dot11f_assoc_rsp_rates((__int64)v115, v209, v208, v94 + 132, v94 + 136);
      v116 = a4[6];
      if ( !v209[0] )
        goto LABEL_66;
      if ( !a4[6] || (unsigned int)qdf_mem_cmp(v209, a4 + 6, 0xEu) )
      {
LABEL_61:
        v199 = 0;
        dot11f_pack_ie_supp_rates(v191, v209, v114, v111, (int *)&v199);
        v117 = 0;
        v114 += v199;
        v111 -= v199;
        if ( (*v96 & 1) == 0 )
          goto LABEL_71;
        goto LABEL_70;
      }
      v116 = a4[6];
      if ( v209[0] )
      {
        if ( !a4[6] )
          goto LABEL_61;
      }
      else
      {
LABEL_66:
        if ( v116 )
        {
          v117 = 1;
          v212[0] = 1;
          if ( (*v96 & 1) != 0 )
            goto LABEL_70;
          goto LABEL_71;
        }
      }
      v117 = 0;
      if ( (*v96 & 1) != 0 )
      {
LABEL_70:
        if ( (*v94 & 0x80) == 0 )
          goto LABEL_71;
        v119 = a4[34];
        if ( !v92[10186] )
          goto LABEL_272;
        if ( !a4[34] || (unsigned int)qdf_mem_cmp(v92 + 10186, a4 + 34, 0x14u) )
          goto LABEL_79;
        v119 = a4[34];
        if ( v92[10186] )
        {
          if ( !a4[34] )
          {
LABEL_79:
            v199 = 0;
            dot11f_pack_ie_edca_param_set(v191, (__int64)(v92 + 10186), v114, v111, (int *)&v199);
            v183 = 0;
            v114 += v199;
            v111 -= v199;
            goto LABEL_72;
          }
        }
        else
        {
LABEL_272:
          if ( v119 )
          {
            v176 = v117++;
            v183 = 0;
            *(_BYTE *)((unsigned __int64)v212 | v176) = 12;
            goto LABEL_72;
          }
        }
        v183 = 0;
LABEL_72:
        v118 = a4[300];
        if ( v92[10260] )
        {
          if ( !a4[300] || (unsigned int)qdf_mem_cmp(v92 + 10260, a4 + 300, 0x3Cu) )
          {
LABEL_75:
            v199 = 0;
            dot11f_pack_ie_ht_caps(v191, (__int64)(v92 + 10260), v114, v111, (int *)&v199);
            v114 += v199;
            v111 -= v199;
LABEL_85:
            if ( !v208[0] )
              goto LABEL_284;
            if ( !a4[20] || (unsigned int)qdf_mem_cmp(v208, a4 + 20, 0xEu) )
              goto LABEL_88;
            if ( v208[0] )
            {
              if ( !a4[20] )
              {
LABEL_88:
                v199 = 0;
                dot11f_pack_ie_ext_supp_rates(v191, v208, v114, v111, (int *)&v199);
                v114 += v199;
                v111 -= v199;
              }
            }
            else
            {
LABEL_284:
              if ( a4[6] )
              {
                v121 = v117++;
                *(_BYTE *)((unsigned __int64)v212 | v121) = 50;
              }
            }
            v122 = a4[360];
            if ( v92[10320] )
            {
              if ( !a4[360] || (unsigned int)qdf_mem_cmp(v92 + 10320, a4 + 360, 0x3Au) )
              {
LABEL_97:
                v199 = 0;
                dot11f_pack_ie_ht_info(v191, (__int64)(v92 + 10320), v114, v111, (int *)&v199);
                v114 += v199;
                v111 -= v199;
LABEL_103:
                v123 = a4[434];
                if ( !v92[10380] )
                  goto LABEL_110;
                if ( !a4[434] || (unsigned int)qdf_mem_cmp(v92 + 10380, a4 + 434, 0x11u) )
                  goto LABEL_106;
                v123 = a4[434];
                if ( v92[10380] )
                {
                  if ( !a4[434] )
                  {
LABEL_106:
                    v199 = 0;
                    dot11f_pack_ie_ext_cap(v191, v92 + 10380, v114, v111, (int *)&v199);
                    v114 += v199;
                    v111 -= v199;
                  }
                }
                else
                {
LABEL_110:
                  if ( v123 )
                    v212[v117++] = 127;
                }
                v124 = a4[520];
                if ( v92[10400] )
                {
                  if ( !a4[520] || (unsigned int)qdf_mem_cmp(v92 + 10400, a4 + 520, 0x10u) )
                  {
LABEL_115:
                    v199 = 0;
                    dot11f_pack_ie_vht_caps(v191, (__int64)(v92 + 10400), v114, v111, (int *)&v199);
                    v114 += v199;
                    v111 -= v199;
LABEL_121:
                    v125 = a4[536];
                    if ( !v92[10416] )
                      goto LABEL_128;
                    if ( !a4[536] || (unsigned int)qdf_mem_cmp(v92 + 10416, a4 + 536, 6u) )
                      goto LABEL_124;
                    v125 = a4[536];
                    if ( v92[10416] )
                    {
                      if ( !a4[536] )
                      {
LABEL_124:
                        v199 = 0;
                        dot11f_pack_ie_vht_operation(v191, (__int64)(v92 + 10416), v114, v111, (int *)&v199);
                        v114 += v199;
                        v111 -= v199;
                      }
                    }
                    else
                    {
LABEL_128:
                      if ( v125 )
                        v212[v117++] = -64;
                    }
                    if ( (unsigned int)wlan_utils_get_vdev_remaining_channel_switch_time(*((_QWORD *)v92 + 2)) )
                    {
                      vdev_remaining_channel_switch_time = wlan_utils_get_vdev_remaining_channel_switch_time(*((_QWORD *)v92 + 2));
                      v201 = vdev_remaining_channel_switch_time;
                      if ( vdev_remaining_channel_switch_time
                        || (wlan_util_vdev_mgr_compute_max_channel_switch_time(*((_QWORD *)v92 + 2), &v201),
                            (vdev_remaining_channel_switch_time = v201) != 0) )
                      {
                        v92[10238] = 1;
                        v92[10239] = (unsigned int)(1000 * vdev_remaining_channel_switch_time) >> 10;
                        v92[10240] = (unsigned int)(1000 * vdev_remaining_channel_switch_time) >> 18;
                        v92[10241] = (unsigned int)(1000 * vdev_remaining_channel_switch_time) >> 26;
                        v199 = 0;
                        dot11f_pack_ie_max_chan_switch_time(v191, v92 + 10238, v114, v111, (int *)&v199);
                        v114 += v199;
                        v111 -= v199;
                      }
                      else
                      {
                        v92[10238] = 0;
                      }
                    }
                    v127 = v189;
                    if ( v189
                      && (vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(
                                                     &unk_969516,
                                                     4u,
                                                     (unsigned __int8 *)(v189 + 1006),
                                                     *(_WORD *)(v189 + 1004)),
                          v127 = v189,
                          vendor_ie_ptr_from_oui) )
                    {
                      v129 = a4[4484];
                      v188 = 1;
                      if ( !a4[4484] )
                        goto LABEL_138;
                    }
                    else
                    {
                      v129 = 0;
                      v188 = 0;
                      if ( a4[4484] )
                      {
LABEL_138:
                        if ( v92[7170] )
                        {
                          v190 = 0;
                          if ( v127 && (v92[8628] & 1) != 0 )
                            v190 = *(_BYTE *)(v127 + 3344) != 0;
                          if ( !v129 )
                          {
LABEL_160:
                            v187 = v117;
                            if ( !v183 || (*v96 & 2) == 0 || (*v94 & 0x40) == 0 )
                            {
                              if ( !v129 )
                              {
                                v134 = 0;
                                goto LABEL_173;
                              }
                              v132 = a4[4190];
                              v133 = 0;
                              goto LABEL_165;
                            }
                            v134 = v92[10206] != 0;
                            v133 = (*v94 & 0x100) != 0 && v92[10226] != 0;
                            if ( v92[10206] )
                              v174 = v129;
                            else
                              v174 = 0;
                            if ( v174 == 1 && a4[4190] )
                            {
                              v175 = qdf_mem_cmp(v92 + 10206, a4 + 4190, 0x14u);
                              v127 = v189;
                              v134 = 1;
                              v135 = v175 == 0;
                            }
                            else
                            {
                              if ( (v129 & 1) == 0 )
                                goto LABEL_174;
                              v132 = a4[4190];
                              if ( !v92[10206] )
                              {
LABEL_165:
                                v134 = 0;
                                if ( v132 )
                                  goto LABEL_174;
                                v135 = 1;
                                goto LABEL_167;
                              }
                              v134 = 1;
                              v135 = 1;
                              if ( !a4[4190] )
                                goto LABEL_174;
                            }
LABEL_167:
                            if ( v133 && v135 && a4[4210] )
                            {
                              if ( !(unsigned int)qdf_mem_cmp(v92 + 10226, a4 + 4210, 3u) )
                                goto LABEL_192;
                              v127 = v189;
                              v133 = 1;
LABEL_174:
                              v136 = v188 ^ 1;
                              if ( !v127 )
                                v136 = 1;
                              if ( (v136 & 1) == 0 )
                              {
                                if ( wlan_get_vendor_ie_ptr_from_oui(
                                       &unk_969516,
                                       4u,
                                       (unsigned __int8 *)(v127 + 1006),
                                       *(_WORD *)(v127 + 1004)) )
                                {
                                  BYTE2(v196) = 0;
                                  LOWORD(v196) = 257;
                                  BYTE4(v196) = 0;
                                }
                                v199 = 0;
                                dot11f_pack_ie_p2_p_assoc_res(v191, &v196, v114, v111, (int *)&v199);
                                v114 += v199;
                                v111 -= v199;
                              }
                              if ( v190 )
                              {
                                qdf_mem_set(v202, 0x1Cu, 0);
                                v137 = v191;
                                LOBYTE(v202[0]) = 1;
                                BYTE1(v202[0]) = v92[8627];
                                populate_dot11f_vht_caps(
                                  v191,
                                  (__int64)v92,
                                  (__int64)v202 + 4,
                                  v138,
                                  v139,
                                  v140,
                                  v141,
                                  v142,
                                  v143,
                                  v144,
                                  v145);
                                populate_dot11f_vht_operation(v191, (__int64)v92, (__int64)&v203 + 4);
                                v199 = 0;
                                dot11f_pack_ie_vendor_vht_ie(v191, v202, v114, v111, (int *)&v199);
                                v114 += v199;
                                v111 -= v199;
                              }
                              else
                              {
                                v137 = v191;
                              }
                              v199 = 0;
                              dot11f_pack_ie_qcn_ie(v137, v92 + 10424, v114, v111, (int *)&v199);
                              v114 += v199;
                              v111 -= v199;
                              if ( v134 )
                              {
                                v199 = 0;
                                dot11f_pack_ie_wmm_params(v137, (__int64)(v92 + 10206), v114, v111, (int *)&v199);
                                v114 += v199;
                                v111 -= v199;
                                if ( !v133 )
                                  goto LABEL_185;
                              }
                              else if ( !v133 )
                              {
LABEL_185:
                                if ( (v188 & 1) != 0 )
                                  goto LABEL_192;
                                goto LABEL_189;
                              }
                              v199 = 0;
                              dot11f_pack_ie_wmm_caps(v191, v92 + 10226, v114, v111, (int *)&v199);
                              v114 += v199;
                              v111 -= v199;
                              if ( (v188 & 1) == 0 )
                              {
LABEL_189:
                                v146 = v190;
                                if ( v92[10424] )
                                  v146 = 1;
                                if ( (((v133 || v134) | v146) & 1) != 0 )
                                  goto LABEL_192;
                                v212[v187] = -35;
                                v148 = v187 + 1;
LABEL_194:
                                v147 = v191;
                                goto LABEL_195;
                              }
LABEL_192:
                              v147 = v191;
                              v148 = v187;
LABEL_195:
                              v149 = a4[1340];
                              if ( !v92[10468] )
                                goto LABEL_206;
                              if ( !a4[1340] || (unsigned int)qdf_mem_cmp(v92 + 10468, a4 + 1340, 0x3Cu) )
                                goto LABEL_198;
                              v149 = a4[1340];
                              if ( v92[10468] )
                              {
                                if ( !a4[1340] )
                                {
LABEL_198:
                                  v199 = 0;
                                  dot11f_pack_ie_he_cap(v147, (__int64)(v92 + 10468), v114, v111, (int *)&v199);
                                  v150 = 0;
                                  v114 += v199;
                                  v111 -= v199;
                                  goto LABEL_209;
                                }
                              }
                              else
                              {
LABEL_206:
                                if ( v149 )
                                {
                                  v150 = 1;
                                  v210[0] = 35;
                                  goto LABEL_209;
                                }
                              }
                              v150 = 0;
LABEL_209:
                              v151 = a4[1400];
                              if ( v92[10528] )
                              {
                                if ( !a4[1400] || (unsigned int)qdf_mem_cmp(v92 + 10528, a4 + 1400, 0x12u) )
                                {
LABEL_212:
                                  v199 = 0;
                                  dot11f_pack_ie_he_op(v147, (__int64)(v92 + 10528), v114, v111, (int *)&v199);
                                  v114 += v199;
                                  v111 -= v199;
LABEL_218:
                                  v153 = a4[1456];
                                  if ( !v92[10546] )
                                    goto LABEL_225;
                                  if ( !a4[1456] || (unsigned int)qdf_mem_cmp(v92 + 10546, a4 + 1456, 4u) )
                                    goto LABEL_221;
                                  v153 = a4[1456];
                                  if ( v92[10546] )
                                  {
                                    if ( !a4[1456] )
                                    {
LABEL_221:
                                      v199 = 0;
                                      dot11f_pack_ie_he_6ghz_band_cap(
                                        v147,
                                        (__int64)(v92 + 10546),
                                        v114,
                                        v111,
                                        (int *)&v199);
                                      v114 += v199;
                                      v111 -= v199;
                                    }
                                  }
                                  else
                                  {
LABEL_225:
                                    if ( v153 )
                                    {
                                      v154 = v150++;
                                      *(_BYTE *)((unsigned __int64)v210 | v154) = 59;
                                    }
                                  }
                                  v155 = a4[3356];
                                  if ( v92[10644] )
                                  {
                                    if ( !a4[3356] || (unsigned int)qdf_mem_cmp(v92 + 10644, a4 + 3356, 0xCu) )
                                    {
LABEL_230:
                                      v199 = 0;
                                      dot11f_pack_ie_eht_op(v147, (__int64)(v92 + 10644), v114, v111, (int *)&v199);
                                      v114 += v199;
                                      v111 -= v199;
LABEL_236:
                                      v184 = v79;
                                      v157 = a4[3264];
                                      if ( !v92[10552] )
                                        goto LABEL_243;
                                      if ( !a4[3264] || (unsigned int)qdf_mem_cmp(v92 + 10552, a4 + 3264, 0x5Cu) )
                                        goto LABEL_239;
                                      v157 = a4[3264];
                                      if ( v92[10552] )
                                      {
                                        if ( !a4[3264] )
                                        {
LABEL_239:
                                          v158 = (__int64)(v92 + 10552);
                                          v159 = v81;
                                          v160 = v92;
                                          v161 = v112;
                                          v199 = 0;
                                          v162 = v147;
                                          dot11f_pack_ie_eht_cap(v147, v158, v114, v111, (int *)&v199);
                                          v114 += v199;
                                          v111 -= v199;
LABEL_246:
                                          v78 = v181;
                                          s[0] = 257;
                                          LOBYTE(s[1]) = v148;
                                          qdf_mem_copy((char *)&s[1] + 1, v212, v148);
                                          v163 = HIBYTE(s[0]);
                                          v164 = (char *)&s[1] + v148 + 1;
                                          *v164 = v150;
                                          HIBYTE(s[0]) = v148 + v163 + 1;
                                          qdf_mem_copy(v164 + 1, v210, v150);
                                          HIBYTE(s[0]) += v150;
                                          if ( LOBYTE(s[0]) )
                                          {
                                            v199 = 0;
                                            a1 = v162;
                                            dot11f_pack_ie_non_inheritance(v162, s, v114, v111, (int *)&v199);
                                            v6 = v182;
                                            v165 = v185;
                                            v114 += v199;
                                          }
                                          else
                                          {
                                            v6 = v182;
                                            v165 = v185;
                                            a1 = v162;
                                          }
                                          *(_WORD *)v165 = (_WORD)v114 - v161;
                                          if ( ((unsigned __int64)&v114[-v161] & 0xFFFE) < 0x102 )
                                          {
                                            *(_BYTE *)(v165 + 3) = (_BYTE)v114 - v161 - 2;
                                          }
                                          else
                                          {
                                            *(_BYTE *)(v165 + 3) = -1;
                                            if ( (unsigned int)lim_add_frag_ie_for_sta_profile(v161, v165) )
                                            {
                                              qdf_trace_msg(
                                                0x35u,
                                                8u,
                                                "%s: add frg ie for sta profile error.",
                                                v166,
                                                v167,
                                                v168,
                                                v169,
                                                v170,
                                                v171,
                                                v172,
                                                v173,
                                                "populate_dot11f_assoc_rsp_mlo_ie");
                                              *(_WORD *)v165 = 257;
                                            }
                                          }
                                          lim_mlo_release_vdev_ref(*((_QWORD *)v160 + 2));
                                          v81 = v159;
                                          v79 = v184;
                                          v80 = v186 + 1;
                                          goto LABEL_39;
                                        }
                                        v159 = v81;
                                        v160 = v92;
                                        v161 = v112;
                                      }
                                      else
                                      {
LABEL_243:
                                        v159 = v81;
                                        v160 = v92;
                                        v161 = v112;
                                        if ( v157 )
                                        {
                                          v162 = v147;
                                          v210[v150++] = 108;
                                          goto LABEL_246;
                                        }
                                      }
                                      v162 = v147;
                                      goto LABEL_246;
                                    }
                                    v155 = a4[3356];
                                    if ( v92[10644] )
                                    {
                                      if ( a4[3356] )
                                        goto LABEL_236;
                                      goto LABEL_230;
                                    }
                                  }
                                  if ( v155 )
                                  {
                                    v156 = v150++;
                                    *(_BYTE *)((unsigned __int64)v210 | v156) = 106;
                                  }
                                  goto LABEL_236;
                                }
                                v151 = a4[1400];
                                if ( v92[10528] )
                                {
                                  if ( a4[1400] )
                                    goto LABEL_218;
                                  goto LABEL_212;
                                }
                              }
                              if ( v151 )
                              {
                                v152 = v150++;
                                *(_BYTE *)((unsigned __int64)v210 | v152) = 36;
                              }
                              goto LABEL_218;
                            }
                            if ( !v135 )
                              goto LABEL_174;
                            if ( v133 )
                            {
                              v148 = v187;
                              if ( a4[4210] )
                                goto LABEL_194;
                              v133 = 1;
                              goto LABEL_174;
                            }
                            if ( !a4[4210] )
                              goto LABEL_192;
LABEL_173:
                            v133 = 0;
                            goto LABEL_174;
                          }
                        }
                        else
                        {
                          v190 = 0;
                          if ( !v129 )
                            goto LABEL_160;
                        }
                        if ( !a4[4500] || !v190 )
                        {
                          if ( v190 == (a4[4500] == 0) )
                            goto LABEL_159;
                        }
                        else
                        {
                          if ( (unsigned int)qdf_mem_cmp(v92 + 10400, a4 + 4500, 0x10u) )
                          {
                            v127 = v189;
                            goto LABEL_159;
                          }
                          v130 = qdf_mem_cmp(v92 + 10416, a4 + 4516, 6u);
                          v127 = v189;
                          if ( v130 )
                            goto LABEL_159;
                        }
                        if ( v92[10424] )
                        {
                          if ( a4[4524] )
                          {
                            v131 = qdf_mem_cmp(v92 + 10424, a4 + 4524, 0x2Cu);
                            v127 = v189;
                            v129 = v131 == 0;
                            goto LABEL_160;
                          }
                        }
                        else if ( !a4[4524] )
                        {
                          v129 = 1;
                          goto LABEL_160;
                        }
LABEL_159:
                        v129 = 0;
                        goto LABEL_160;
                      }
                    }
                    v129 = 1;
                    goto LABEL_138;
                  }
                  v124 = a4[520];
                  if ( v92[10400] )
                  {
                    if ( a4[520] )
                      goto LABEL_121;
                    goto LABEL_115;
                  }
                }
                if ( v124 )
                  v212[v117++] = -65;
                goto LABEL_121;
              }
              v122 = a4[360];
              if ( v92[10320] )
              {
                if ( a4[360] )
                  goto LABEL_103;
                goto LABEL_97;
              }
            }
            if ( v122 )
              v212[v117++] = 61;
            goto LABEL_103;
          }
          v118 = a4[300];
          if ( v92[10260] )
          {
            if ( a4[300] )
              goto LABEL_85;
            goto LABEL_75;
          }
        }
        if ( v118 )
        {
          v120 = v117++;
          *(_BYTE *)((unsigned __int64)v212 | v120) = 45;
        }
        goto LABEL_85;
      }
LABEL_71:
      v183 = 1;
      goto LABEL_72;
    }
LABEL_39:
    ++v79;
    v81 += 48;
  }
  while ( v79 < *(unsigned __int8 *)(v78 + 3576) );
  v64 = v179;
  v177 = v80;
LABEL_278:
  result = 0;
  *(_WORD *)(v64 + 236) = v177;
LABEL_279:
  _ReadStatusReg(SP_EL0);
  return result;
}
