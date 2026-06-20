__int64 __fastcall target_if_cfr_rx_tlv_process(
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
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int *v21; // x23
  unsigned int *v22; // x8
  __int64 v23; // x28
  __int64 v24; // x0
  __int64 v25; // x19
  _DWORD *v26; // x10
  unsigned int v27; // w11
  _DWORD *v28; // x9
  __int64 v29; // x10
  const char *v30; // x2
  _DWORD *v31; // x8
  int v32; // w24
  int target_type; // w26
  unsigned __int8 v34; // w22
  unsigned __int64 v35; // x21
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned __int64 StatusReg; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 lut_entry; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  int v62; // w1
  __int64 v63; // x24
  _QWORD *first_vdev; // x0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int *v73; // x8
  unsigned int v74; // w21
  unsigned int v75; // w22
  __int16 v76; // w19
  unsigned int v77; // w25
  __int64 v78; // x0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  int v87; // w8
  __int64 v88; // x22
  int v89; // w8
  char v90; // w26
  const char *v91; // x27
  unsigned int v92; // w9
  unsigned int v93; // w10
  unsigned int v94; // w11
  unsigned __int16 v95; // w25
  __int16 v96; // w8
  __int64 v97; // x19
  __int64 cmpt_obj; // x0
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  __int16 v107; // w8
  int v108; // w8
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  __int64 v125; // x0
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  __int16 v134; // w8
  unsigned __int64 v135; // x8
  int v136; // w19
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  __int16 v145; // w8
  unsigned __int64 v146; // x8
  int v147; // w19
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  __int16 v156; // w8
  unsigned __int64 v157; // x8
  int v158; // w19
  __int64 v159; // x0
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  double v168; // d0
  double v169; // d1
  double v170; // d2
  double v171; // d3
  double v172; // d4
  double v173; // d5
  double v174; // d6
  double v175; // d7
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  double v192; // d0
  double v193; // d1
  double v194; // d2
  double v195; // d3
  double v196; // d4
  double v197; // d5
  double v198; // d6
  double v199; // d7
  double v200; // d0
  double v201; // d1
  double v202; // d2
  double v203; // d3
  double v204; // d4
  double v205; // d5
  double v206; // d6
  double v207; // d7
  __int64 v208; // x0
  unsigned __int64 v209; // x8
  int v210; // w19
  double v211; // d0
  double v212; // d1
  double v213; // d2
  double v214; // d3
  double v215; // d4
  double v216; // d5
  double v217; // d6
  double v218; // d7
  __int16 v219; // w8
  const char *v220; // x2
  __int64 result; // x0
  unsigned __int64 v222; // x8
  int v223; // w19
  double v224; // d0
  double v225; // d1
  double v226; // d2
  double v227; // d3
  double v228; // d4
  double v229; // d5
  double v230; // d6
  double v231; // d7
  __int16 v232; // w8
  unsigned __int64 v233; // x8
  int v234; // w19
  double v235; // d0
  double v236; // d1
  double v237; // d2
  double v238; // d3
  double v239; // d4
  double v240; // d5
  double v241; // d6
  double v242; // d7
  __int16 v243; // w8
  unsigned __int64 v244; // x8
  int v245; // w19
  double v246; // d0
  double v247; // d1
  double v248; // d2
  double v249; // d3
  double v250; // d4
  double v251; // d5
  double v252; // d6
  double v253; // d7
  __int16 v254; // w8
  unsigned __int64 v255; // x8
  int v256; // w19
  unsigned int v257; // w8
  unsigned int v258; // w9
  int v259; // w9
  void (__fastcall *v260)(__int64, __int64, __int64, __int64, __int64, void *, __int64); // x8
  __int64 v261; // x3
  __int64 v262; // x4
  __int64 v263; // x8
  unsigned __int8 v264; // [xsp+2Ch] [xbp-54h]
  __int64 v265; // [xsp+30h] [xbp-50h]
  __int64 v266; // [xsp+38h] [xbp-48h]
  int v267; // [xsp+44h] [xbp-3Ch]
  __int64 v268; // [xsp+50h] [xbp-30h]
  __int64 v269; // [xsp+58h] [xbp-28h]
  int v270; // [xsp+60h] [xbp-20h]
  unsigned int v271; // [xsp+64h] [xbp-1Ch] BYREF
  __int64 v272; // [xsp+68h] [xbp-18h]
  unsigned __int64 v273; // [xsp+70h] [xbp-10h]
  __int64 v274; // [xsp+78h] [xbp-8h]

  v274 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v271 = 0;
  if ( !a1 )
  {
    v220 = "%s: pdev is null\n";
    goto LABEL_123;
  }
  if ( (unsigned int)wlan_objmgr_pdev_try_get_ref(a1, 0x30u, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    v220 = "%s: failed to get pdev reference";
LABEL_123:
    result = qdf_trace_msg(0x6Au, 2u, v220, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cfr_rx_tlv_process");
    if ( a2 )
      result = _qdf_nbuf_free(a2);
    goto LABEL_181;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( !comp_private_obj )
  {
    v30 = "%s: pdev object for CFR is NULL";
    goto LABEL_12;
  }
  v21 = *(unsigned int **)(a2 + 224);
  v22 = (unsigned int *)*((unsigned __int8 *)v21 + 316);
  if ( (_DWORD)v22 != 1 )
    goto LABEL_178;
  v23 = comp_private_obj;
  v24 = *(_QWORD *)(a1 + 80);
  if ( !v24 )
  {
    v30 = "%s: psoc is null\n";
    goto LABEL_12;
  }
  v25 = *(_QWORD *)(v24 + 2136);
  if ( !v25 )
  {
    v30 = "%s: rx_ops is NULL";
    goto LABEL_12;
  }
  v26 = *(_DWORD **)(v24 + 2800);
  if ( !v26 )
  {
    v30 = "%s: tgt_hdl is NULL";
LABEL_12:
    qdf_trace_msg(0x6Au, 2u, v30, v13, v14, v15, v16, v17, v18, v19, v20, "target_if_cfr_rx_tlv_process");
    if ( !a2 )
      goto LABEL_180;
    goto LABEL_179;
  }
  v27 = v26[126];
  v28 = v26 + 268;
  if ( v27 <= 0xA )
  {
    if ( *v28 == v27 )
    {
      v29 = 0;
    }
    else if ( v26[332] == v27 )
    {
      v29 = 1;
    }
    else if ( v26[396] == v27 )
    {
      v29 = 2;
    }
    else if ( v26[460] == v27 )
    {
      v29 = 3;
    }
    else if ( v26[524] == v27 )
    {
      v29 = 4;
    }
    else if ( v26[588] == v27 )
    {
      v29 = 5;
    }
    else if ( v26[652] == v27 )
    {
      v29 = 6;
    }
    else
    {
      if ( v26[716] != v27 )
      {
LABEL_32:
        v32 = 0;
        goto LABEL_33;
      }
      v29 = 7;
    }
    v28 += 64 * v29;
  }
  if ( !v28 )
    goto LABEL_32;
  v31 = &v28[64 * (unsigned __int64)*(unsigned __int8 *)(a1 + 40)];
  if ( !v31 || (v31[5] & 0x40) == 0 )
    goto LABEL_32;
  v32 = 1;
LABEL_33:
  target_type = target_if_cfr_get_target_type(v24, v13, v14, v15, v16, v17, v18, v19, v20);
  v34 = *(_BYTE *)(v23 + 154);
  v35 = v21[81] | ((unsigned __int64)(*((_BYTE *)v21 + 321) & 0xF) << 32);
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, unsigned __int64, unsigned int *, _QWORD))target_if_dbr_cookie_lookup)(
                       a1,
                       1,
                       v35,
                       &v271,
                       v34) )
  {
    qdf_trace_msg(
      0x6Au,
      8u,
      "%s: Cookie lookup failure for addr: 0x%pK",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "target_if_cfr_rx_tlv_process",
      v35);
    if ( !a2 )
      goto LABEL_180;
    goto LABEL_179;
  }
  qdf_trace_msg(
    0x6Au,
    8u,
    "%s: <RXTLV><%u>:buffer address: 0x%pK\n"
    "<WIFIRX_PPDU_START_E> ppdu_id: 0x%04x\n"
    "<WIFIRXPCU_PPDU_END_INFO_E> BB_CAPTURED_CHANNEL = %d\n"
    "<WIFIPHYRX_PKT_END_E> RX_LOCATION_INFO_VALID = %d\n"
    "<WIFIPHYRX_PKT_END_E> RTT_CHE_BUFFER_POINTER_LOW32 = %x\n"
    "<WIFIPHYRX_PKT_END_E> RTT_CHE_BUFFER_POINTER_HIGH8 = %x\n"
    "<WIFIPHYRX_PKT_END_E> CHAN_CAPTURE_STATUS = %d\n",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "target_if_cfr_rx_tlv_process",
    v271,
    v35,
    *v21,
    *((unsigned __int8 *)v21 + 316),
    *((unsigned __int8 *)v21 + 319),
    v21[81],
    *((unsigned __int8 *)v21 + 321),
    *((unsigned __int8 *)v21 + 320));
  v270 = v32;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v23 + 1704);
  }
  else
  {
    raw_spin_lock_bh(v23 + 1704);
    *(_QWORD *)(v23 + 1712) |= 1uLL;
  }
  lut_entry = get_lut_entry(v23, v271, v45, v46, v47, v48, v49, v50, v51, v52);
  if ( !lut_entry )
  {
    qdf_trace_msg(0x6Au, 2u, "%s: lut is NULL", v54, v55, v56, v57, v58, v59, v60, v61, "target_if_cfr_rx_tlv_process");
LABEL_176:
    v263 = *(_QWORD *)(v23 + 1712);
    if ( (v263 & 1) != 0 )
    {
      *(_QWORD *)(v23 + 1712) = v263 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v23 + 1704);
      if ( !a2 )
        goto LABEL_180;
      goto LABEL_179;
    }
    raw_spin_unlock(v23 + 1704);
LABEL_178:
    if ( !a2 )
    {
LABEL_180:
      result = wlan_objmgr_pdev_release_ref(a1, 0x30u, v22, v13, v14, v15, v16, v17, v18, v19, v20);
LABEL_181:
      _ReadStatusReg(SP_EL0);
      return result;
    }
LABEL_179:
    _qdf_nbuf_free(a2);
    goto LABEL_180;
  }
  v62 = *(unsigned __int8 *)(v23 + 153);
  v63 = lut_entry;
  if ( v62 == 255 )
    first_vdev = wlan_objmgr_pdev_get_first_vdev(a1, 0x30u);
  else
    first_vdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, v62, 0x30u);
  v264 = v34;
  v265 = v35;
  v266 = v25;
  if ( !first_vdev )
  {
    qdf_trace_msg(
      0x6Au,
      8u,
      "%s: vdev is null\n",
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      "target_if_cfr_rx_tlv_process");
    goto LABEL_176;
  }
  v73 = (unsigned int *)first_vdev[4];
  v269 = (__int64)first_vdev;
  v74 = v73[4];
  v75 = v73[5];
  v76 = *(_WORD *)v73;
  v77 = v73[7];
  v78 = wlan_objmgr_vdev_release_ref((__int64)first_vdev, 0x30u, v73, v65, v66, v67, v68, v69, v70, v71, v72);
  ++*(_QWORD *)(v23 + 1320);
  *(_WORD *)(v63 + 22) = *v21;
  *(_DWORD *)(v63 + 32) = v21[81];
  *(_DWORD *)(v63 + 36) = *((unsigned __int8 *)v21 + 321);
  v267 = target_type;
  *(_QWORD *)(v63 + 208) = ktime_get(v78) / 1000000;
  target_if_cfr_fill_header(v63 + 40, 0, target_type, 1);
  *(_BYTE *)(v63 + 64) = 1;
  *(_BYTE *)(v63 + 67) = v77;
  *(_WORD *)(v63 + 68) = v76;
  *(_WORD *)(v63 + 70) = v74;
  *(_WORD *)(v63 + 72) = v75;
  *(_BYTE *)(v63 + 74) = 0;
  v268 = a2;
  *(_QWORD *)(v63 + 78) = *((_QWORD *)v21 + 7);
  v87 = v21[9] & 0x7C000000;
  *(_BYTE *)(v63 + 90) = v87 != 0;
  if ( v87 )
    LOBYTE(v87) = *((_BYTE *)v21 + 296);
  *(_BYTE *)(v63 + 91) = v87;
  v88 = 0;
  v89 = *((__int16 *)v21 + 164);
  v272 = 0;
  v273 = 0;
  v90 = 0;
  v91 = "%s: Invalid gain table index reported";
  *(_DWORD *)(v63 + 164) = v89;
  *(_DWORD *)(v63 + 176) = v21[87];
  v92 = v21[84];
  v93 = v21[85];
  v94 = v21[86];
  LODWORD(v272) = v21[83];
  HIDWORD(v272) = v92;
  if ( v270 )
    v95 = -1;
  else
    v95 = 62;
  v273 = __PAIR64__(v94, v93);
  do
  {
    v96 = *((_WORD *)&v272 + v88);
    v97 = v63 + v88;
    *(_BYTE *)(v97 + 168) = v96;
    *(_BYTE *)(v97 + 192) = HIBYTE(v96) & 3;
    if ( (v96 & 0x300) != 0 )
    {
      qdf_trace_msg(
        0x6Au,
        8u,
        "%s: Invalid gain table index reported",
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        "target_if_cfr_rx_tlv_process");
      LOBYTE(v96) = *(_BYTE *)(v97 + 168);
      v90 = 1;
    }
    if ( v95 < (unsigned int)(unsigned __int8)v96 )
      *(_BYTE *)(v97 + 168) = v95;
    ++v88;
  }
  while ( v88 != 8 );
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v269, v79, v80, v81, v82, v83, v84, v85, v86);
  if ( cmpt_obj )
  {
    if ( *(_BYTE *)(cmpt_obj + 196) == 1 )
    {
      if ( *(_DWORD *)(v23 + 1940) )
      {
        *(_WORD *)(v63 + 148) = -1;
        if ( *(_DWORD *)(v23 + 1940) >= 2u )
        {
          *(_WORD *)(v63 + 150) = -1;
          if ( *(_DWORD *)(v23 + 1940) >= 3u )
          {
            *(_WORD *)(v63 + 152) = -1;
            if ( *(_DWORD *)(v23 + 1940) >= 4u )
            {
              *(_WORD *)(v63 + 154) = -1;
              if ( *(_DWORD *)(v23 + 1940) >= 5u )
              {
                *(_WORD *)(v63 + 156) = -1;
                if ( *(_DWORD *)(v23 + 1940) >= 6u )
                {
                  *(_WORD *)(v63 + 158) = -1;
                  if ( *(_DWORD *)(v23 + 1940) >= 7u )
                  {
                    *(_WORD *)(v63 + 160) = -1;
                    if ( *(_DWORD *)(v23 + 1940) >= 8u )
                    {
                      *(_WORD *)(v63 + 162) = -1;
                      if ( *(_DWORD *)(v23 + 1940) > 8u )
                        goto LABEL_185;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( !*(_BYTE *)(v23 + 1442) )
    goto LABEL_158;
  if ( v270 )
  {
    qdf_trace_msg(
      0x6Au,
      8u,
      "%s: Enahced AoA not supported.. Invsetigate",
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      "populate_enh_chain_phase");
    if ( !*(_DWORD *)(v23 + 1940) )
      goto LABEL_158;
    *(_WORD *)(v63 + 148) = -1;
    if ( *(_DWORD *)(v23 + 1940) <= 1u )
      goto LABEL_158;
    *(_WORD *)(v63 + 150) = -1;
    if ( *(_DWORD *)(v23 + 1940) < 3u )
      goto LABEL_158;
    *(_WORD *)(v63 + 152) = -1;
    if ( *(_DWORD *)(v23 + 1940) < 4u )
      goto LABEL_158;
    *(_WORD *)(v63 + 154) = -1;
    if ( *(_DWORD *)(v23 + 1940) < 5u )
      goto LABEL_158;
    *(_WORD *)(v63 + 156) = -1;
    if ( *(_DWORD *)(v23 + 1940) < 6u )
      goto LABEL_158;
    *(_WORD *)(v63 + 158) = -1;
    if ( *(_DWORD *)(v23 + 1940) < 7u )
      goto LABEL_158;
    v107 = -1;
    *(_WORD *)(v63 + 160) = -1;
    if ( *(_DWORD *)(v23 + 1940) < 8u )
      goto LABEL_158;
    goto LABEL_157;
  }
  v108 = *(_DWORD *)(v23 + 1940);
  if ( (v90 & 1) == 0 )
  {
    if ( !v108 )
      goto LABEL_158;
    v135 = *(unsigned __int8 *)(v63 + 168);
    v91 = (const char *)(v23 + 1944);
    if ( v135 > 0x3D )
    {
      LOWORD(v136) = 0;
    }
    else
    {
      v136 = *(unsigned __int16 *)&v91[2 * (61 - v135)];
      if ( v136 == 0xFFFF )
      {
        wlan_vdev_mlme_get_cmpt_obj(v269, v99, v100, v101, v102, v103, v104, v105, v106);
        v145 = -1;
        goto LABEL_92;
      }
    }
    wlan_vdev_mlme_get_cmpt_obj(v269, v99, v100, v101, v102, v103, v104, v105, v106);
    v145 = (v136 + *(_WORD *)(v23 + 2936)) & 0x3FF;
LABEL_92:
    *(_WORD *)(v63 + 148) = v145;
    if ( *(_DWORD *)(v23 + 1940) < 2u )
      goto LABEL_158;
    v146 = *(unsigned __int8 *)(v63 + 169);
    if ( v146 > 0x3D )
    {
      LOWORD(v147) = 0;
    }
    else
    {
      v147 = *(unsigned __int16 *)&v91[2 * (61 - v146) + 124];
      if ( v147 == 0xFFFF )
      {
        wlan_vdev_mlme_get_cmpt_obj(v269, v137, v138, v139, v140, v141, v142, v143, v144);
        v156 = -1;
        goto LABEL_98;
      }
    }
    wlan_vdev_mlme_get_cmpt_obj(v269, v137, v138, v139, v140, v141, v142, v143, v144);
    v156 = (v147 + *(_WORD *)(v23 + 2940)) & 0x3FF;
LABEL_98:
    *(_WORD *)(v63 + 150) = v156;
    if ( *(_DWORD *)(v23 + 1940) < 3u )
      goto LABEL_158;
    v157 = *(unsigned __int8 *)(v63 + 170);
    if ( v157 <= 0x3D )
    {
      v158 = *(unsigned __int16 *)&v91[2 * (61 - v157) + 248];
      if ( v158 == 0xFFFF )
      {
        v159 = wlan_vdev_mlme_get_cmpt_obj(v269, v148, v149, v150, v151, v152, v153, v154, v155);
        if ( v159 )
        {
          v134 = -1;
          if ( (*(_BYTE *)(v159 + 196) & 1) != 0 )
            goto LABEL_115;
        }
        else
        {
          v134 = -1;
        }
LABEL_117:
        *(_WORD *)(v63 + 152) = v134;
        if ( *(_DWORD *)(v23 + 1940) <= 3u )
          goto LABEL_158;
        v209 = *(unsigned __int8 *)(v63 + 171);
        if ( v209 > 0x3D )
        {
          LOWORD(v210) = 0;
        }
        else
        {
          v210 = *(unsigned __int16 *)&v91[2 * (61 - v209) + 372];
          if ( v210 == 0xFFFF )
          {
            wlan_vdev_mlme_get_cmpt_obj(v269, v160, v161, v162, v163, v164, v165, v166, v167);
            v219 = -1;
            goto LABEL_128;
          }
        }
        wlan_vdev_mlme_get_cmpt_obj(v269, v160, v161, v162, v163, v164, v165, v166, v167);
        v219 = (v210 + *(_WORD *)(v23 + 2948)) & 0x3FF;
LABEL_128:
        *(_WORD *)(v63 + 154) = v219;
        if ( *(_DWORD *)(v23 + 1940) < 5u )
          goto LABEL_158;
        v222 = *(unsigned __int8 *)(v63 + 172);
        if ( v222 > 0x3D )
        {
          LOWORD(v223) = 0;
        }
        else
        {
          v223 = *(unsigned __int16 *)&v91[2 * (61 - v222) + 496];
          if ( v223 == 0xFFFF )
          {
            wlan_vdev_mlme_get_cmpt_obj(v269, v211, v212, v213, v214, v215, v216, v217, v218);
            v232 = -1;
            goto LABEL_135;
          }
        }
        wlan_vdev_mlme_get_cmpt_obj(v269, v211, v212, v213, v214, v215, v216, v217, v218);
        v232 = (v223 + *(_WORD *)(v23 + 2952)) & 0x3FF;
LABEL_135:
        *(_WORD *)(v63 + 156) = v232;
        if ( *(_DWORD *)(v23 + 1940) < 6u )
          goto LABEL_158;
        v233 = *(unsigned __int8 *)(v63 + 173);
        if ( v233 > 0x3D )
        {
          LOWORD(v234) = 0;
        }
        else
        {
          v234 = *(unsigned __int16 *)&v91[2 * (61 - v233) + 620];
          if ( v234 == 0xFFFF )
          {
            wlan_vdev_mlme_get_cmpt_obj(v269, v224, v225, v226, v227, v228, v229, v230, v231);
            v243 = -1;
            goto LABEL_143;
          }
        }
        wlan_vdev_mlme_get_cmpt_obj(v269, v224, v225, v226, v227, v228, v229, v230, v231);
        v243 = (v234 + *(_WORD *)(v23 + 2956)) & 0x3FF;
LABEL_143:
        *(_WORD *)(v63 + 158) = v243;
        if ( *(_DWORD *)(v23 + 1940) < 7u )
          goto LABEL_158;
        v244 = *(unsigned __int8 *)(v63 + 174);
        if ( v244 > 0x3D )
        {
          LOWORD(v245) = 0;
        }
        else
        {
          v245 = *(unsigned __int16 *)&v91[2 * (61 - v244) + 744];
          if ( v245 == 0xFFFF )
          {
            wlan_vdev_mlme_get_cmpt_obj(v269, v235, v236, v237, v238, v239, v240, v241, v242);
            v254 = -1;
LABEL_149:
            *(_WORD *)(v63 + 160) = v254;
            if ( *(_DWORD *)(v23 + 1940) < 8u )
              goto LABEL_158;
            v255 = *(unsigned __int8 *)(v63 + 175);
            if ( v255 > 0x3D )
            {
              LOWORD(v256) = 0;
            }
            else
            {
              v256 = *(unsigned __int16 *)&v91[2 * (61 - v255) + 868];
              if ( v256 == 0xFFFF )
              {
                wlan_vdev_mlme_get_cmpt_obj(v269, v246, v247, v248, v249, v250, v251, v252, v253);
                v107 = -1;
                goto LABEL_157;
              }
            }
            wlan_vdev_mlme_get_cmpt_obj(v269, v246, v247, v248, v249, v250, v251, v252, v253);
            v107 = (v256 + *(_WORD *)(v23 + 2964)) & 0x3FF;
LABEL_157:
            *(_WORD *)(v63 + 162) = v107;
            if ( *(_DWORD *)(v23 + 1940) > 8u )
              goto LABEL_185;
            goto LABEL_158;
          }
        }
        wlan_vdev_mlme_get_cmpt_obj(v269, v235, v236, v237, v238, v239, v240, v241, v242);
        v254 = (v245 + *(_WORD *)(v23 + 2960)) & 0x3FF;
        goto LABEL_149;
      }
LABEL_112:
      v208 = wlan_vdev_mlme_get_cmpt_obj(v269, v148, v149, v150, v151, v152, v153, v154, v155);
      if ( v208 && (*(_BYTE *)(v208 + 196) & 1) != 0 )
      {
        v134 = (v158 + *(_WORD *)(v23 + 2944)) & 0x3FF;
        goto LABEL_115;
      }
      v134 = (v158 + *(_WORD *)(v23 + 2944)) & 0x3FF;
      goto LABEL_117;
    }
LABEL_111:
    LOWORD(v158) = 0;
    goto LABEL_112;
  }
  if ( v108 )
  {
    wlan_vdev_mlme_get_cmpt_obj(v269, v99, v100, v101, v102, v103, v104, v105, v106);
    *(_WORD *)(v63 + 148) = -1;
    if ( *(_DWORD *)(v23 + 1940) > 1u )
    {
      wlan_vdev_mlme_get_cmpt_obj(v269, v109, v110, v111, v112, v113, v114, v115, v116);
      *(_WORD *)(v63 + 150) = -1;
      if ( *(_DWORD *)(v23 + 1940) >= 3u )
      {
        v125 = wlan_vdev_mlme_get_cmpt_obj(v269, v117, v118, v119, v120, v121, v122, v123, v124);
        if ( v125 && (*(_BYTE *)(v125 + 196) & 1) != 0 )
        {
          v134 = -1;
LABEL_115:
          *(_WORD *)(v63 + 150) = v134;
          goto LABEL_158;
        }
        *(_WORD *)(v63 + 152) = -1;
        if ( *(_DWORD *)(v23 + 1940) >= 4u )
        {
          wlan_vdev_mlme_get_cmpt_obj(v269, v126, v127, v128, v129, v130, v131, v132, v133);
          *(_WORD *)(v63 + 154) = -1;
          if ( *(_DWORD *)(v23 + 1940) >= 5u )
          {
            wlan_vdev_mlme_get_cmpt_obj(v269, v168, v169, v170, v171, v172, v173, v174, v175);
            *(_WORD *)(v63 + 156) = -1;
            if ( *(_DWORD *)(v23 + 1940) >= 6u )
            {
              wlan_vdev_mlme_get_cmpt_obj(v269, v176, v177, v178, v179, v180, v181, v182, v183);
              *(_WORD *)(v63 + 158) = -1;
              if ( *(_DWORD *)(v23 + 1940) >= 7u )
              {
                wlan_vdev_mlme_get_cmpt_obj(v269, v184, v185, v186, v187, v188, v189, v190, v191);
                *(_WORD *)(v63 + 160) = -1;
                if ( *(_DWORD *)(v23 + 1940) >= 8u )
                {
                  wlan_vdev_mlme_get_cmpt_obj(v269, v192, v193, v194, v195, v196, v197, v198, v199);
                  *(_WORD *)(v63 + 162) = -1;
                  if ( *(_DWORD *)(v23 + 1940) >= 9u )
                  {
                    wlan_vdev_mlme_get_cmpt_obj(v269, v200, v201, v202, v203, v204, v205, v206, v207);
                    __break(0x5512u);
                    goto LABEL_111;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_158:
  *(_WORD *)(v63 + 180) = v21[88];
  *(_WORD *)(v63 + 182) = v21[89];
  *(_BYTE *)(v63 + 188) = v21[9] & 3;
  *(_BYTE *)(v63 + 185) = (v21[9] & 4) != 0;
  *(_BYTE *)(v63 + 189) = (v21[9] & 0xF00000) == 0x100000;
  *(_BYTE *)(v63 + 187) = *((_BYTE *)v21 + 39) & 1;
  *(_BYTE *)(v63 + 184) = (v21[9] & 0x2000000) != 0;
  *(_BYTE *)(v63 + 186) = *((_BYTE *)v21 + 69);
  v257 = *(unsigned __int8 *)(v63 + 91);
  v258 = *(_DWORD *)(v23 + 92);
  if ( v258 < v257 )
  {
    v257 = (unsigned __int8)*(_DWORD *)(v23 + 92);
    *(_BYTE *)(v63 + 91) = v258;
  }
  if ( v267 == 36 )
  {
    *(_DWORD *)(v63 + 116) = *((char *)v21 + 304);
    *(_DWORD *)(v63 + 120) = *((char *)v21 + 305);
    *(_DWORD *)(v63 + 124) = *((char *)v21 + 306);
    *(_DWORD *)(v63 + 128) = *((char *)v21 + 307);
    *(_DWORD *)(v63 + 132) = *((char *)v21 + 308);
    *(_DWORD *)(v63 + 136) = *((char *)v21 + 309);
    *(_DWORD *)(v63 + 140) = *((char *)v21 + 310);
    v259 = *((char *)v21 + 311);
  }
  else
  {
    *(_DWORD *)(v63 + 116) = *((unsigned __int8 *)v21 + 304);
    *(_DWORD *)(v63 + 120) = *((unsigned __int8 *)v21 + 305);
    *(_DWORD *)(v63 + 124) = *((unsigned __int8 *)v21 + 306);
    *(_DWORD *)(v63 + 128) = *((unsigned __int8 *)v21 + 307);
    *(_DWORD *)(v63 + 132) = *((unsigned __int8 *)v21 + 308);
    *(_DWORD *)(v63 + 136) = *((unsigned __int8 *)v21 + 309);
    *(_DWORD *)(v63 + 140) = *((unsigned __int8 *)v21 + 310);
    v259 = *((unsigned __int8 *)v21 + 311);
  }
  *(_DWORD *)(v63 + 144) = v259;
  if ( (*((_BYTE *)v21 + 39) & 0x7C) == 0
    || !v257
    || (qdf_mem_copy((void *)(v63 + 92), (char *)v21 + 422, 6u), *(unsigned __int8 *)(v63 + 91) < 2u)
    || (qdf_mem_copy((void *)(v63 + 98), (char *)v21 + 550, 6u), *(unsigned __int8 *)(v63 + 91) < 3u)
    || (qdf_mem_copy((void *)(v63 + 104), (char *)v21 + 678, 6u), *(unsigned __int8 *)(v63 + 91) < 4u)
    || (qdf_mem_copy((void *)(v63 + 110), (char *)v21 + 806, 6u), *(unsigned __int8 *)(v63 + 91) < 5u)
    || (qdf_mem_copy((void *)(v63 + 116), (char *)v21 + 934, 6u), *(unsigned __int8 *)(v63 + 91) <= 5u) )
  {
    a2 = v268;
    if ( !(unsigned int)correlate_and_relay_enh(a1, v271, v63, 1) )
    {
      v260 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, void *, __int64))(v266 + 224);
      if ( v260 )
      {
        v261 = *(_QWORD *)(v63 + 8);
        v262 = *(unsigned int *)(v63 + 16);
        if ( *((_DWORD *)v260 - 1) != 1435207299 )
          __break(0x8228u);
        v260(a1, v63 + 40, 160, v261, v262, &end_magic, 4);
      }
      dump_metadata(v63 + 40, v271);
      release_lut_entry(a1, v63);
      target_if_dbr_buf_release(a1, 1u, v265, v271, v264);
    }
    goto LABEL_176;
  }
LABEL_185:
  __break(0x5512u);
  return ((__int64 (*)(void))correlate_and_relay_enh)();
}
