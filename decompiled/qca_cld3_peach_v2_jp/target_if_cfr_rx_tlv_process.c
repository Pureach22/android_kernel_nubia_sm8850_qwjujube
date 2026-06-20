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
  __int64 v25; // x22
  int target_type; // w26
  unsigned __int8 v27; // w21
  unsigned __int64 v28; // x19
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  unsigned __int64 StatusReg; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 lut_entry; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w1
  __int64 v57; // x24
  _QWORD *first_vdev; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int *v67; // x8
  unsigned int v68; // w21
  unsigned int v69; // w22
  __int16 v70; // w19
  unsigned int v71; // w25
  __int64 v72; // x0
  __int64 v73; // x1
  __int64 v74; // x2
  __int64 v75; // x3
  __int64 v76; // x4
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  int v85; // w8
  __int64 v86; // x22
  char v87; // w26
  int v88; // w8
  unsigned int v89; // w9
  unsigned int v90; // w10
  __int16 v91; // w8
  __int64 v92; // x21
  __int64 cmpt_obj; // x0
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  int v102; // w8
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  __int64 v119; // x0
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  __int16 v128; // w8
  unsigned __int64 v129; // x8
  __int64 v130; // x27
  int v131; // w19
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  __int16 v140; // w8
  unsigned __int64 v141; // x8
  int v142; // w19
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  __int16 v151; // w8
  unsigned __int64 v152; // x8
  int v153; // w19
  __int64 v154; // x0
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7
  double v163; // d0
  double v164; // d1
  double v165; // d2
  double v166; // d3
  double v167; // d4
  double v168; // d5
  double v169; // d6
  double v170; // d7
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  double v179; // d0
  double v180; // d1
  double v181; // d2
  double v182; // d3
  double v183; // d4
  double v184; // d5
  double v185; // d6
  double v186; // d7
  double v187; // d0
  double v188; // d1
  double v189; // d2
  double v190; // d3
  double v191; // d4
  double v192; // d5
  double v193; // d6
  double v194; // d7
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  __int64 v203; // x0
  unsigned __int64 v204; // x8
  int v205; // w19
  double v206; // d0
  double v207; // d1
  double v208; // d2
  double v209; // d3
  double v210; // d4
  double v211; // d5
  double v212; // d6
  double v213; // d7
  __int16 v214; // w8
  unsigned __int64 v215; // x8
  int v216; // w19
  double v217; // d0
  double v218; // d1
  double v219; // d2
  double v220; // d3
  double v221; // d4
  double v222; // d5
  double v223; // d6
  double v224; // d7
  __int16 v225; // w8
  const char *v226; // x2
  __int64 result; // x0
  unsigned __int64 v228; // x8
  int v229; // w19
  double v230; // d0
  double v231; // d1
  double v232; // d2
  double v233; // d3
  double v234; // d4
  double v235; // d5
  double v236; // d6
  double v237; // d7
  __int16 v238; // w8
  unsigned __int64 v239; // x8
  int v240; // w19
  double v241; // d0
  double v242; // d1
  double v243; // d2
  double v244; // d3
  double v245; // d4
  double v246; // d5
  double v247; // d6
  double v248; // d7
  __int16 v249; // w8
  unsigned __int64 v250; // x8
  int v251; // w19
  __int16 v252; // w8
  unsigned int v253; // w8
  unsigned int v254; // w9
  int v255; // w9
  void (__fastcall *v256)(__int64, __int64, __int64, __int64, __int64, void *, __int64); // x8
  __int64 v257; // x3
  __int64 v258; // x4
  __int64 v259; // x8
  __int64 v260; // [xsp+28h] [xbp-58h]
  unsigned __int8 v261; // [xsp+34h] [xbp-4Ch]
  __int64 v262; // [xsp+38h] [xbp-48h]
  __int64 v263; // [xsp+40h] [xbp-40h]
  int v264; // [xsp+4Ch] [xbp-34h]
  __int64 v265; // [xsp+58h] [xbp-28h]
  unsigned int v266; // [xsp+64h] [xbp-1Ch] BYREF
  __int64 v267; // [xsp+68h] [xbp-18h]
  unsigned __int64 v268; // [xsp+70h] [xbp-10h]
  __int64 v269; // [xsp+78h] [xbp-8h]

  v269 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v266 = 0;
  if ( !a1 )
  {
    v226 = "%s: pdev is null\n";
    goto LABEL_93;
  }
  if ( (unsigned int)wlan_objmgr_pdev_try_get_ref(a1, 0x30u, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    v226 = "%s: failed to get pdev reference";
LABEL_93:
    result = qdf_trace_msg(0x6Au, 2u, v226, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cfr_rx_tlv_process");
    if ( a2 )
      result = _qdf_nbuf_free(a2);
    goto LABEL_143;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( !comp_private_obj )
  {
    v37 = "%s: pdev object for CFR is NULL";
    goto LABEL_12;
  }
  v21 = *(unsigned int **)(a2 + 224);
  v22 = (unsigned int *)*((unsigned __int8 *)v21 + 316);
  if ( (_DWORD)v22 != 1 )
    goto LABEL_140;
  v23 = comp_private_obj;
  v24 = *(_QWORD *)(a1 + 80);
  if ( !v24 )
  {
    v37 = "%s: psoc is null\n";
    goto LABEL_12;
  }
  v25 = *(_QWORD *)(v24 + 2136);
  if ( !v25 )
  {
    v37 = "%s: rx_ops is NULL";
    goto LABEL_12;
  }
  if ( !*(_QWORD *)(v24 + 2800) )
  {
    v37 = "%s: tgt_hdl is NULL";
LABEL_12:
    qdf_trace_msg(0x6Au, 2u, v37, v13, v14, v15, v16, v17, v18, v19, v20, "target_if_cfr_rx_tlv_process");
    if ( !a2 )
      goto LABEL_142;
    goto LABEL_141;
  }
  target_type = target_if_cfr_get_target_type(v24, v13, v14, v15, v16, v17, v18, v19, v20);
  v27 = *(_BYTE *)(v23 + 154);
  v28 = v21[81] | ((unsigned __int64)(*((_BYTE *)v21 + 321) & 0xF) << 32);
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, unsigned __int64, unsigned int *, _QWORD))target_if_dbr_cookie_lookup)(
                       a1,
                       1,
                       v28,
                       &v266,
                       v27) )
  {
    qdf_trace_msg(
      0x6Au,
      8u,
      "%s: Cookie lookup failure for addr: 0x%pK",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "target_if_cfr_rx_tlv_process",
      v28);
    if ( !a2 )
      goto LABEL_142;
    goto LABEL_141;
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
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "target_if_cfr_rx_tlv_process",
    v266,
    v28,
    *v21,
    *((unsigned __int8 *)v21 + 316),
    *((unsigned __int8 *)v21 + 319),
    v21[81],
    *((unsigned __int8 *)v21 + 321),
    *((unsigned __int8 *)v21 + 320));
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
  lut_entry = get_lut_entry(v23, v266, v39, v40, v41, v42, v43, v44, v45, v46);
  if ( !lut_entry )
  {
    qdf_trace_msg(0x6Au, 2u, "%s: lut is NULL", v48, v49, v50, v51, v52, v53, v54, v55, "target_if_cfr_rx_tlv_process");
LABEL_138:
    v259 = *(_QWORD *)(v23 + 1712);
    if ( (v259 & 1) != 0 )
    {
      *(_QWORD *)(v23 + 1712) = v259 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v23 + 1704);
      if ( !a2 )
        goto LABEL_142;
      goto LABEL_141;
    }
    raw_spin_unlock(v23 + 1704);
LABEL_140:
    if ( !a2 )
    {
LABEL_142:
      result = wlan_objmgr_pdev_release_ref(a1, 0x30u, v22, v13, v14, v15, v16, v17, v18, v19, v20);
LABEL_143:
      _ReadStatusReg(SP_EL0);
      return result;
    }
LABEL_141:
    _qdf_nbuf_free(a2);
    goto LABEL_142;
  }
  v56 = *(unsigned __int8 *)(v23 + 153);
  v57 = lut_entry;
  if ( v56 == 255 )
    first_vdev = wlan_objmgr_pdev_get_first_vdev(a1, 0x30u);
  else
    first_vdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, v56, 0x30u);
  v260 = v25;
  v261 = v27;
  v262 = v28;
  if ( !first_vdev )
  {
    qdf_trace_msg(
      0x6Au,
      8u,
      "%s: vdev is null\n",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "target_if_cfr_rx_tlv_process");
    goto LABEL_138;
  }
  v67 = (unsigned int *)first_vdev[4];
  v263 = (__int64)first_vdev;
  v68 = v67[4];
  v69 = v67[5];
  v70 = *(_WORD *)v67;
  v71 = v67[7];
  v72 = wlan_objmgr_vdev_release_ref((__int64)first_vdev, 0x30u, v67, v59, v60, v61, v62, v63, v64, v65, v66);
  ++*(_QWORD *)(v23 + 1320);
  *(_WORD *)(v57 + 22) = *v21;
  *(_DWORD *)(v57 + 32) = v21[81];
  *(_DWORD *)(v57 + 36) = *((unsigned __int8 *)v21 + 321);
  v264 = target_type;
  *(_QWORD *)(v57 + 208) = ktime_get(v72, v73, v74, v75, v76) / 1000000;
  target_if_cfr_fill_header(v57 + 40, 0, target_type, 1);
  *(_BYTE *)(v57 + 64) = 1;
  *(_BYTE *)(v57 + 67) = v71;
  *(_WORD *)(v57 + 68) = v70;
  *(_WORD *)(v57 + 70) = v68;
  *(_WORD *)(v57 + 72) = v69;
  *(_BYTE *)(v57 + 74) = 0;
  v265 = a2;
  *(_QWORD *)(v57 + 78) = *((_QWORD *)v21 + 7);
  v85 = v21[9] & 0x7C000000;
  *(_BYTE *)(v57 + 90) = v85 != 0;
  if ( v85 )
    LOBYTE(v85) = *((_BYTE *)v21 + 296);
  *(_BYTE *)(v57 + 91) = v85;
  v86 = 0;
  v87 = 0;
  v88 = *((__int16 *)v21 + 164);
  v267 = 0;
  v268 = 0;
  *(_DWORD *)(v57 + 164) = v88;
  *(_DWORD *)(v57 + 176) = v21[87];
  v89 = v21[84];
  v90 = v21[85];
  LODWORD(v267) = v21[83];
  HIDWORD(v267) = v89;
  v268 = __PAIR64__(v21[86], v90);
  do
  {
    v91 = *((_WORD *)&v267 + v86);
    v92 = v57 + v86;
    *(_BYTE *)(v92 + 168) = v91;
    *(_BYTE *)(v92 + 192) = HIBYTE(v91) & 3;
    if ( (v91 & 0x300) != 0 )
    {
      qdf_trace_msg(
        0x6Au,
        8u,
        "%s: Invalid gain table index reported",
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        "target_if_cfr_rx_tlv_process");
      LOBYTE(v91) = *(_BYTE *)(v92 + 168);
      v87 = 1;
    }
    if ( (unsigned __int8)v91 >= 0x3Fu )
      *(_BYTE *)(v92 + 168) = 62;
    ++v86;
  }
  while ( v86 != 8 );
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v263, v77, v78, v79, v80, v81, v82, v83, v84);
  if ( cmpt_obj )
  {
    if ( *(_BYTE *)(cmpt_obj + 180) == 1 )
    {
      if ( *(_DWORD *)(v23 + 1940) )
      {
        *(_WORD *)(v57 + 148) = -1;
        if ( *(_DWORD *)(v23 + 1940) >= 2u )
        {
          *(_WORD *)(v57 + 150) = -1;
          if ( *(_DWORD *)(v23 + 1940) >= 3u )
          {
            *(_WORD *)(v57 + 152) = -1;
            if ( *(_DWORD *)(v23 + 1940) >= 4u )
            {
              *(_WORD *)(v57 + 154) = -1;
              if ( *(_DWORD *)(v23 + 1940) >= 5u )
              {
                *(_WORD *)(v57 + 156) = -1;
                if ( *(_DWORD *)(v23 + 1940) >= 6u )
                {
                  *(_WORD *)(v57 + 158) = -1;
                  if ( *(_DWORD *)(v23 + 1940) >= 7u )
                  {
                    *(_WORD *)(v57 + 160) = -1;
                    if ( *(_DWORD *)(v23 + 1940) >= 8u )
                    {
                      *(_WORD *)(v57 + 162) = -1;
                      if ( *(_DWORD *)(v23 + 1940) > 8u )
                        goto LABEL_149;
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
    goto LABEL_120;
  v102 = *(_DWORD *)(v23 + 1940);
  if ( (v87 & 1) == 0 )
  {
    if ( !v102 )
      goto LABEL_120;
    v129 = *(unsigned __int8 *)(v57 + 168);
    v130 = v23 + 1944;
    if ( v129 > 0x3D )
    {
      LOWORD(v131) = 0;
    }
    else
    {
      v131 = *(unsigned __int16 *)(v130 + 2 * (61 - v129));
      if ( v131 == 0xFFFF )
      {
        wlan_vdev_mlme_get_cmpt_obj(v263, v94, v95, v96, v97, v98, v99, v100, v101);
        v140 = -1;
        goto LABEL_56;
      }
    }
    wlan_vdev_mlme_get_cmpt_obj(v263, v94, v95, v96, v97, v98, v99, v100, v101);
    v140 = (v131 + *(_WORD *)(v23 + 2936)) & 0x3FF;
LABEL_56:
    *(_WORD *)(v57 + 148) = v140;
    if ( *(_DWORD *)(v23 + 1940) < 2u )
      goto LABEL_120;
    v141 = *(unsigned __int8 *)(v57 + 169);
    if ( v141 > 0x3D )
    {
      LOWORD(v142) = 0;
    }
    else
    {
      v142 = *(unsigned __int16 *)(v130 + 2 * (61 - v141) + 124);
      if ( v142 == 0xFFFF )
      {
        wlan_vdev_mlme_get_cmpt_obj(v263, v132, v133, v134, v135, v136, v137, v138, v139);
        v151 = -1;
        goto LABEL_62;
      }
    }
    wlan_vdev_mlme_get_cmpt_obj(v263, v132, v133, v134, v135, v136, v137, v138, v139);
    v151 = (v142 + *(_WORD *)(v23 + 2940)) & 0x3FF;
LABEL_62:
    *(_WORD *)(v57 + 150) = v151;
    if ( *(_DWORD *)(v23 + 1940) < 3u )
      goto LABEL_120;
    v152 = *(unsigned __int8 *)(v57 + 170);
    if ( v152 > 0x3D )
    {
      LOWORD(v153) = 0;
    }
    else
    {
      v153 = *(unsigned __int16 *)(v130 + 2 * (61 - v152) + 248);
      if ( v153 == 0xFFFF )
      {
        v154 = wlan_vdev_mlme_get_cmpt_obj(v263, v143, v144, v145, v146, v147, v148, v149, v150);
        if ( v154 )
        {
          v128 = -1;
          if ( (*(_BYTE *)(v154 + 180) & 1) != 0 )
            goto LABEL_79;
        }
        else
        {
          v128 = -1;
        }
LABEL_81:
        *(_WORD *)(v57 + 152) = v128;
        if ( *(_DWORD *)(v23 + 1940) <= 3u )
          goto LABEL_120;
        v204 = *(unsigned __int8 *)(v57 + 171);
        if ( v204 > 0x3D )
        {
          LOWORD(v205) = 0;
        }
        else
        {
          v205 = *(unsigned __int16 *)(v130 + 2 * (61 - v204) + 372);
          if ( v205 == 0xFFFF )
          {
            wlan_vdev_mlme_get_cmpt_obj(v263, v155, v156, v157, v158, v159, v160, v161, v162);
            v214 = -1;
            goto LABEL_87;
          }
        }
        wlan_vdev_mlme_get_cmpt_obj(v263, v155, v156, v157, v158, v159, v160, v161, v162);
        v214 = (v205 + *(_WORD *)(v23 + 2948)) & 0x3FF;
LABEL_87:
        *(_WORD *)(v57 + 154) = v214;
        if ( *(_DWORD *)(v23 + 1940) < 5u )
          goto LABEL_120;
        v215 = *(unsigned __int8 *)(v57 + 172);
        if ( v215 > 0x3D )
        {
          LOWORD(v216) = 0;
        }
        else
        {
          v216 = *(unsigned __int16 *)(v130 + 2 * (61 - v215) + 496);
          if ( v216 == 0xFFFF )
          {
            wlan_vdev_mlme_get_cmpt_obj(v263, v206, v207, v208, v209, v210, v211, v212, v213);
            v225 = -1;
            goto LABEL_98;
          }
        }
        wlan_vdev_mlme_get_cmpt_obj(v263, v206, v207, v208, v209, v210, v211, v212, v213);
        v225 = (v216 + *(_WORD *)(v23 + 2952)) & 0x3FF;
LABEL_98:
        *(_WORD *)(v57 + 156) = v225;
        if ( *(_DWORD *)(v23 + 1940) < 6u )
          goto LABEL_120;
        v228 = *(unsigned __int8 *)(v57 + 173);
        if ( v228 > 0x3D )
        {
          LOWORD(v229) = 0;
        }
        else
        {
          v229 = *(unsigned __int16 *)(v130 + 2 * (61 - v228) + 620);
          if ( v229 == 0xFFFF )
          {
            wlan_vdev_mlme_get_cmpt_obj(v263, v217, v218, v219, v220, v221, v222, v223, v224);
            v238 = -1;
            goto LABEL_106;
          }
        }
        wlan_vdev_mlme_get_cmpt_obj(v263, v217, v218, v219, v220, v221, v222, v223, v224);
        v238 = (v229 + *(_WORD *)(v23 + 2956)) & 0x3FF;
LABEL_106:
        *(_WORD *)(v57 + 158) = v238;
        if ( *(_DWORD *)(v23 + 1940) < 7u )
          goto LABEL_120;
        v239 = *(unsigned __int8 *)(v57 + 174);
        if ( v239 > 0x3D )
        {
          LOWORD(v240) = 0;
        }
        else
        {
          v240 = *(unsigned __int16 *)(v130 + 2 * (61 - v239) + 744);
          if ( v240 == 0xFFFF )
          {
            wlan_vdev_mlme_get_cmpt_obj(v263, v230, v231, v232, v233, v234, v235, v236, v237);
            v249 = -1;
            goto LABEL_113;
          }
        }
        wlan_vdev_mlme_get_cmpt_obj(v263, v230, v231, v232, v233, v234, v235, v236, v237);
        v249 = (v240 + *(_WORD *)(v23 + 2960)) & 0x3FF;
LABEL_113:
        *(_WORD *)(v57 + 160) = v249;
        if ( *(_DWORD *)(v23 + 1940) < 8u )
          goto LABEL_120;
        v250 = *(unsigned __int8 *)(v57 + 175);
        if ( v250 > 0x3D )
        {
          LOWORD(v251) = 0;
        }
        else
        {
          v251 = *(unsigned __int16 *)(v130 + 2 * (61 - v250) + 868);
          if ( v251 == 0xFFFF )
          {
            cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v263, v241, v242, v243, v244, v245, v246, v247, v248);
            v252 = -1;
            goto LABEL_119;
          }
        }
        cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v263, v241, v242, v243, v244, v245, v246, v247, v248);
        v252 = (v251 + *(_WORD *)(v23 + 2964)) & 0x3FF;
LABEL_119:
        *(_WORD *)(v57 + 162) = v252;
        if ( *(_DWORD *)(v23 + 1940) > 8u )
          goto LABEL_149;
        goto LABEL_120;
      }
    }
    v203 = wlan_vdev_mlme_get_cmpt_obj(v263, v143, v144, v145, v146, v147, v148, v149, v150);
    if ( v203 && (*(_BYTE *)(v203 + 180) & 1) != 0 )
    {
      v128 = (v153 + *(_WORD *)(v23 + 2944)) & 0x3FF;
      goto LABEL_79;
    }
    v128 = (v153 + *(_WORD *)(v23 + 2944)) & 0x3FF;
    goto LABEL_81;
  }
  if ( v102 )
  {
    wlan_vdev_mlme_get_cmpt_obj(v263, v94, v95, v96, v97, v98, v99, v100, v101);
    *(_WORD *)(v57 + 148) = -1;
    if ( *(_DWORD *)(v23 + 1940) > 1u )
    {
      wlan_vdev_mlme_get_cmpt_obj(v263, v103, v104, v105, v106, v107, v108, v109, v110);
      *(_WORD *)(v57 + 150) = -1;
      if ( *(_DWORD *)(v23 + 1940) >= 3u )
      {
        v119 = wlan_vdev_mlme_get_cmpt_obj(v263, v111, v112, v113, v114, v115, v116, v117, v118);
        if ( v119 && (*(_BYTE *)(v119 + 180) & 1) != 0 )
        {
          v128 = -1;
LABEL_79:
          *(_WORD *)(v57 + 150) = v128;
          goto LABEL_120;
        }
        *(_WORD *)(v57 + 152) = -1;
        if ( *(_DWORD *)(v23 + 1940) >= 4u )
        {
          wlan_vdev_mlme_get_cmpt_obj(v263, v120, v121, v122, v123, v124, v125, v126, v127);
          *(_WORD *)(v57 + 154) = -1;
          if ( *(_DWORD *)(v23 + 1940) >= 5u )
          {
            wlan_vdev_mlme_get_cmpt_obj(v263, v163, v164, v165, v166, v167, v168, v169, v170);
            *(_WORD *)(v57 + 156) = -1;
            if ( *(_DWORD *)(v23 + 1940) >= 6u )
            {
              wlan_vdev_mlme_get_cmpt_obj(v263, v171, v172, v173, v174, v175, v176, v177, v178);
              *(_WORD *)(v57 + 158) = -1;
              if ( *(_DWORD *)(v23 + 1940) >= 7u )
              {
                wlan_vdev_mlme_get_cmpt_obj(v263, v179, v180, v181, v182, v183, v184, v185, v186);
                *(_WORD *)(v57 + 160) = -1;
                if ( *(_DWORD *)(v23 + 1940) >= 8u )
                {
                  wlan_vdev_mlme_get_cmpt_obj(v263, v187, v188, v189, v190, v191, v192, v193, v194);
                  *(_WORD *)(v57 + 162) = -1;
                  if ( *(_DWORD *)(v23 + 1940) >= 9u )
                  {
                    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v263, v195, v196, v197, v198, v199, v200, v201, v202);
                    goto LABEL_149;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_120:
  *(_WORD *)(v57 + 180) = v21[88];
  *(_WORD *)(v57 + 182) = v21[89];
  *(_BYTE *)(v57 + 188) = v21[9] & 3;
  *(_BYTE *)(v57 + 185) = (v21[9] & 4) != 0;
  *(_BYTE *)(v57 + 189) = (v21[9] & 0xF00000) == 0x100000;
  *(_BYTE *)(v57 + 187) = *((_BYTE *)v21 + 39) & 1;
  *(_BYTE *)(v57 + 184) = (v21[9] & 0x2000000) != 0;
  *(_BYTE *)(v57 + 186) = *((_BYTE *)v21 + 69);
  v253 = *(unsigned __int8 *)(v57 + 91);
  v254 = *(_DWORD *)(v23 + 92);
  if ( v254 < v253 )
  {
    v253 = (unsigned __int8)*(_DWORD *)(v23 + 92);
    *(_BYTE *)(v57 + 91) = v254;
  }
  if ( v264 == 36 )
  {
    *(_DWORD *)(v57 + 116) = *((char *)v21 + 304);
    *(_DWORD *)(v57 + 120) = *((char *)v21 + 305);
    *(_DWORD *)(v57 + 124) = *((char *)v21 + 306);
    *(_DWORD *)(v57 + 128) = *((char *)v21 + 307);
    *(_DWORD *)(v57 + 132) = *((char *)v21 + 308);
    *(_DWORD *)(v57 + 136) = *((char *)v21 + 309);
    *(_DWORD *)(v57 + 140) = *((char *)v21 + 310);
    v255 = *((char *)v21 + 311);
  }
  else
  {
    *(_DWORD *)(v57 + 116) = *((unsigned __int8 *)v21 + 304);
    *(_DWORD *)(v57 + 120) = *((unsigned __int8 *)v21 + 305);
    *(_DWORD *)(v57 + 124) = *((unsigned __int8 *)v21 + 306);
    *(_DWORD *)(v57 + 128) = *((unsigned __int8 *)v21 + 307);
    *(_DWORD *)(v57 + 132) = *((unsigned __int8 *)v21 + 308);
    *(_DWORD *)(v57 + 136) = *((unsigned __int8 *)v21 + 309);
    *(_DWORD *)(v57 + 140) = *((unsigned __int8 *)v21 + 310);
    v255 = *((unsigned __int8 *)v21 + 311);
  }
  *(_DWORD *)(v57 + 144) = v255;
  if ( (*((_BYTE *)v21 + 39) & 0x7C) == 0
    || !v253
    || (qdf_mem_copy((void *)(v57 + 92), (char *)v21 + 422, 6u), *(unsigned __int8 *)(v57 + 91) < 2u)
    || (qdf_mem_copy((void *)(v57 + 98), (char *)v21 + 550, 6u), *(unsigned __int8 *)(v57 + 91) < 3u)
    || (qdf_mem_copy((void *)(v57 + 104), (char *)v21 + 678, 6u), *(unsigned __int8 *)(v57 + 91) < 4u)
    || (qdf_mem_copy((void *)(v57 + 110), (char *)v21 + 806, 6u), *(unsigned __int8 *)(v57 + 91) < 5u)
    || (cmpt_obj = (__int64)qdf_mem_copy((void *)(v57 + 116), (char *)v21 + 934, 6u),
        *(unsigned __int8 *)(v57 + 91) <= 5u) )
  {
    a2 = v265;
    if ( !(unsigned int)correlate_and_relay_enh(a1) )
    {
      v256 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, void *, __int64))(v260 + 224);
      if ( v256 )
      {
        v257 = *(_QWORD *)(v57 + 8);
        v258 = *(unsigned int *)(v57 + 16);
        if ( *((_DWORD *)v256 - 1) != 1435207299 )
          __break(0x8228u);
        v256(a1, v57 + 40, 160, v257, v258, &end_magic, 4);
      }
      dump_metadata(v57 + 40, v266);
      release_lut_entry(a1, v57);
      target_if_dbr_buf_release(a1, 1u, v262, v266, v261);
    }
    goto LABEL_138;
  }
LABEL_149:
  __break(0x5512u);
  return correlate_and_relay_enh(cmpt_obj);
}
