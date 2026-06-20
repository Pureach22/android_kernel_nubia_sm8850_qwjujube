__int64 __fastcall lim_send_assoc_rsp_mgmt_frame(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned __int8 *a4,
        unsigned __int8 a5,
        __int64 a6,
        __int64 a7,
        char a8)
{
  __int64 v15; // x1
  __int64 session_by_vdev_id; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  char *v26; // x27
  char v27; // w25
  __int64 v28; // x22
  _DWORD *v29; // x28
  const char *v30; // x2
  char v31; // w8
  unsigned int v32; // w8
  __int16 v33; // w8
  __int64 v34; // x1
  char v35; // w9
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x0
  char is_mlo_vdev; // w0
  _BOOL8 v46; // x3
  int v47; // w9
  void *v48; // x0
  unsigned int v49; // w25
  void *v50; // x22
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v59; // w23
  __int64 result; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x0
  char v70; // w0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  unsigned int v79; // w22
  _QWORD *v80; // x0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  _BYTE *v89; // x8
  int v90; // w25
  __int64 v91; // x0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  _BYTE *v100; // x27
  char v101; // w26
  _BYTE *v102; // x28
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  unsigned __int8 v111; // w22
  bool is_24ghz_ch_freq; // w0
  char v113; // w8
  unsigned __int8 v114; // w26
  unsigned int packed_assoc_response_size; // w0
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  unsigned int v124; // w25
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  char *v133; // x25
  char *v134; // x0
  char v135; // w8
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  unsigned int v144; // w8
  __int16 v145; // w8
  __int64 v146; // x5
  char *v147; // x25
  char *v148; // x23
  char *v149; // x23
  unsigned int v150; // w0
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  unsigned __int16 v159; // w27
  size_t v160; // x2
  size_t v161; // x2
  __int64 v162; // x5
  __int64 v163; // x6
  __int64 v164; // x7
  int v165; // w8
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  char v174; // w22
  __int64 v175; // x0
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  _QWORD *context; // x0
  int v185; // w0
  unsigned int v186; // w22
  double v187; // d0
  double v188; // d1
  double v189; // d2
  double v190; // d3
  double v191; // d4
  double v192; // d5
  double v193; // d6
  double v194; // d7
  int v195; // [xsp+0h] [xbp-1B0h]
  int v196; // [xsp+8h] [xbp-1A8h]
  int v197; // [xsp+8h] [xbp-1A8h]
  int v198; // [xsp+10h] [xbp-1A0h]
  int v199; // [xsp+10h] [xbp-1A0h]
  int v200; // [xsp+18h] [xbp-198h]
  int v201; // [xsp+20h] [xbp-190h]
  int v202; // [xsp+30h] [xbp-180h]
  int v203; // [xsp+38h] [xbp-178h]
  unsigned int v204; // [xsp+5Ch] [xbp-154h]
  int v205[2]; // [xsp+60h] [xbp-150h]
  char v206; // [xsp+6Ch] [xbp-144h]
  unsigned int v207; // [xsp+70h] [xbp-140h]
  size_t n; // [xsp+74h] [xbp-13Ch]
  char v209; // [xsp+7Ch] [xbp-134h]
  unsigned __int8 v210; // [xsp+80h] [xbp-130h]
  unsigned int v211; // [xsp+84h] [xbp-12Ch]
  const void *v212; // [xsp+88h] [xbp-128h]
  bool v213; // [xsp+90h] [xbp-120h]
  __int64 v214; // [xsp+98h] [xbp-118h] BYREF
  char *v215; // [xsp+A0h] [xbp-110h]
  unsigned __int16 v216; // [xsp+ACh] [xbp-104h] BYREF
  __int64 v217; // [xsp+B0h] [xbp-100h] BYREF
  __int64 v218; // [xsp+B8h] [xbp-F8h]
  __int64 v219; // [xsp+C0h] [xbp-F0h]
  int v220; // [xsp+C8h] [xbp-E8h]
  __int64 v221; // [xsp+D0h] [xbp-E0h] BYREF
  unsigned int v222; // [xsp+DCh] [xbp-D4h] BYREF
  char *v223; // [xsp+E0h] [xbp-D0h] BYREF
  __int64 v224; // [xsp+E8h] [xbp-C8h] BYREF
  __int64 v225; // [xsp+F0h] [xbp-C0h]
  __int64 v226; // [xsp+F8h] [xbp-B8h]
  __int64 v227; // [xsp+100h] [xbp-B0h]
  __int64 v228; // [xsp+108h] [xbp-A8h]
  __int64 v229; // [xsp+110h] [xbp-A0h]
  __int64 v230; // [xsp+118h] [xbp-98h]
  int v231; // [xsp+120h] [xbp-90h]
  __int64 v232; // [xsp+128h] [xbp-88h] BYREF
  __int64 v233; // [xsp+130h] [xbp-80h]
  __int64 v234; // [xsp+138h] [xbp-78h]
  __int64 v235; // [xsp+140h] [xbp-70h]
  __int64 v236; // [xsp+148h] [xbp-68h]
  __int64 v237; // [xsp+150h] [xbp-60h]
  __int64 v238; // [xsp+158h] [xbp-58h]
  __int64 v239; // [xsp+160h] [xbp-50h]
  __int64 v240; // [xsp+168h] [xbp-48h]
  __int64 v241; // [xsp+170h] [xbp-40h]
  __int64 v242; // [xsp+178h] [xbp-38h]
  int v243; // [xsp+180h] [xbp-30h]
  _QWORD v244[2]; // [xsp+188h] [xbp-28h] BYREF
  char v245; // [xsp+198h] [xbp-18h]
  __int64 v246; // [xsp+1A0h] [xbp-10h]

  v246 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *(unsigned __int8 *)(a7 + 10);
  v223 = nullptr;
  v222 = 0;
  v221 = 0;
  v220 = 0;
  v218 = 0;
  v219 = 0;
  v217 = 0;
  v216 = 0;
  v245 = 0;
  v244[0] = 0;
  v244[1] = 0;
  v214 = 0;
  v215 = nullptr;
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, v15);
  if ( session_by_vdev_id )
  {
    v25 = session_by_vdev_id;
    v26 = (char *)(session_by_vdev_id + 7024);
    v209 = *(_BYTE *)(session_by_vdev_id + 10);
    v210 = a5;
    qdf_mem_set(&lim_send_assoc_rsp_mgmt_frame_frm, 0x1310u, 0);
    v27 = *v26;
    word_8D8792 = a2;
    word_8D8794 = a3 | 0xC000;
    v211 = a3;
    if ( a6 )
    {
      populate_dot11f_assoc_rsp_rates(a1, &unk_8D8796, &unk_8D87A4, a6 + 264, a6 + 272);
      v28 = 0;
      v29 = (_DWORD *)(v25 + 88);
      v213 = (unsigned __int16)a2 == 0;
      if ( !(_WORD)a2 && *(_DWORD *)(v25 + 88) == 1 )
      {
        v28 = *(_QWORD *)(*(_QWORD *)(v25 + 384) + 8LL * *(unsigned __int16 *)(a6 + 348));
        if ( v28 )
        {
          if ( *(_BYTE *)(v28 + 3268) )
            populate_dot11_assoc_res_p2p_ie(a1, &unk_8D9914, v28);
        }
      }
      if ( (v27 & 1) != 0 && (*(_WORD *)a6 & 0x80) != 0 )
      {
        populate_dot11f_edca_param_set(a1, &unk_8D87B2, v25);
      }
      else if ( (v27 & 2) != 0 && (*(_WORD *)a6 & 0x40) != 0 )
      {
        populate_dot11f_wmm_params(a1, &unk_8D97EE, v25);
        if ( (*(_WORD *)a6 & 0x100) != 0 )
          populate_dot11f_wmm_caps(&unk_8D9802);
      }
      v31 = *(_BYTE *)(a6 + 32);
      if ( (v31 & 8) != 0 && *(_BYTE *)(v25 + 155) )
      {
        populate_dot11f_ht_caps(a1, v25, &byte_8D88BC);
        v32 = (*(unsigned __int8 *)(a6 + 346) >> 3) & 1;
        if ( v32 >= *(unsigned __int8 *)(v25 + 160) )
          v32 = *(unsigned __int8 *)(v25 + 160);
        if ( v32 )
          v33 = word_8D88BD & 0xFFFD | (2 * v32);
        else
          v33 = word_8D88BD & 0xFFBD;
        word_8D88BD = v33;
        populate_dot11f_ht_info(a1, &qword_8D88F8, v25);
        v31 = *(_BYTE *)(a6 + 32);
      }
      if ( (v31 & 0x10) != 0 && v26[146] )
      {
        populate_dot11f_vht_caps(a1, v25, &byte_8D8998);
        populate_dot11f_vht_operation(a1, v25, &dword_8D89A8);
        v34 = 1;
      }
      else
      {
        v34 = 0;
        if ( *(_BYTE *)(a6 + 39) == 1 && byte_8D88BC )
        {
          v34 = 0;
          byte_8D8901 = 0;
          byte_8D88C1 = 0;
        }
      }
      if ( v26[146] && v28 && (v26[1604] & 1) != 0 && *(_BYTE *)(v28 + 3344) )
      {
        byte_8D9920 = 1;
        v35 = v26[1603];
        byte_8D9924 = 1;
        byte_8D9921 = v35;
        populate_dot11f_vht_caps(a1, v25, &byte_8D9924);
        populate_dot11f_vht_operation(a1, v25, &unk_8D9934);
        v34 = 1;
      }
      populate_dot11f_ext_cap(a1, v34, &unk_8D8942, v25);
      populate_dot11f_qcn_ie(a1, v25, &unk_8D993C, 255);
      if ( *(_BYTE *)(a6 + 38) == 1 && v26[1652] == 1 )
      {
        populate_dot11f_he_caps(
          a1,
          v25,
          *(_DWORD *)(v25 + 7036),
          *(_DWORD *)(v25 + 284),
          *(_DWORD *)(v25 + 7176),
          (int)&qword_8D8CCC);
        populate_dot11f_sr_info(a1, v25, &unk_8D8D1A);
        populate_dot11f_he_operation(a1, v25, (int)&qword_8D8D08);
        populate_dot11f_he_6ghz_cap(a1, v25, &unk_8D8D40);
      }
      if ( *(_BYTE *)(a6 + 68) == 1 && v26[3047] == 1 )
      {
        populate_dot11f_eht_caps(a1, v25, (int)&qword_8D9450);
        populate_dot11f_eht_operation(a1, v25, (int)&qword_8D94AC);
      }
      if ( (unsigned __int16)a2 == 30 )
        populate_dot11f_timeout_interval(
          a1,
          &unk_8D88B4,
          3,
          (*(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 1043LL) - *(unsigned __int8 *)(a6 + 645))
        * (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 1044LL));
      if ( *v29 == 1 && *(_BYTE *)(a6 + 662) )
        ++v26[1651];
    }
    else
    {
      populate_dot11f_supp_rates(a1, 255, &unk_8D8796, v25);
      populate_dot11f_ext_supp_rates(a1, 255, &unk_8D87A4, v25);
      v28 = 0;
      v29 = (_DWORD *)(v25 + 88);
      v213 = (unsigned __int16)a2 == 0;
    }
    qdf_mem_set(&v217, 0x1Cu, 0);
    if ( *v29 == 1 && *(_BYTE *)(v25 + 428) )
      lim_decide_ap_protection(a1, a4, &v217, v25);
    lim_update_short_preamble(a1, a4, &v217, v25);
    lim_update_short_slot_time(a1, a4, &v217, v25);
    v46 = false;
    if ( a6 )
    {
      if ( *(_BYTE *)(a6 + 68) == 1 && (lim_is_mlo_conn(v25, a6) & 1) != 0 && v26[3047] == 1 )
      {
        v44 = *(_QWORD *)(v25 + 16);
        if ( *(_DWORD *)(v44 + 16) == 1 )
        {
          is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v44, v36, v37, v38, v39, v40, v41, v42, v43);
          if ( (unsigned __int16)a2 != 30 && (is_mlo_vdev & 1) != 0 )
            v46 = true;
        }
      }
    }
    populate_dot11f_capabilities(a1, &lim_send_assoc_rsp_mgmt_frame_frm, v25, v46);
    v47 = *(unsigned __int8 *)(a1 + 14881);
    LOBYTE(v217) = *(_BYTE *)(v25 + 10);
    if ( !v47 && HIWORD(v218) )
    {
      sch_set_fixed_beacon_fields(a1, v25);
      lim_send_beacon_params(a1, &v217, v25);
    }
    lim_obss_send_detection_cfg(a1, v25, 0);
    v48 = (void *)_qdf_mem_malloc(0xFFu, "lim_send_assoc_rsp_mgmt_frame", 2441);
    if ( v48 )
    {
      v212 = v48;
      v207 = a2;
      if ( v28 )
      {
        v49 = *(unsigned __int16 *)(v25 + 7304);
        if ( v49 - 1 <= 0xFE )
        {
          v50 = v48;
          qdf_mem_copy(v48, *(const void **)(v25 + 7312), *(unsigned __int16 *)(v25 + 7304));
          qdf_mem_set(v244, 0x11u, 0);
          v216 = v49;
          if ( (unsigned int)lim_strip_extcap_update_struct(a1, v50, &v216, v244) )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: strip off extcap IE failed",
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              "lim_send_assoc_rsp_mgmt_frame");
            v59 = v49;
          }
          else
          {
            v79 = v216;
            lim_merge_extcap_struct(&unk_8D8942, v244, 1);
            v49 = v79;
            populate_dot11f_twt_extended_caps(a1, v25, &unk_8D8942);
            v59 = v79;
          }
LABEL_71:
          populate_dot11f_bcn_prot_extcaps(a1, v25, &unk_8D8942);
          if ( a6 && *(_BYTE *)(a6 + 68) == 1 && (lim_is_mlo_conn(v25, a6) & 1) != 0 )
          {
            if ( v26[3047] != 1 )
            {
              HIDWORD(n) = 0;
              goto LABEL_84;
            }
            v69 = *(_QWORD *)(v25 + 16);
            if ( *(_DWORD *)(v69 + 16) == 1 )
            {
              v70 = wlan_vdev_mlme_is_mlo_vdev(v69, v61, v62, v63, v64, v65, v66, v67, v68);
              HIDWORD(n) = 0;
              if ( (unsigned __int16)v207 != 30 && (v70 & 1) != 0 )
              {
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Populate mlo IEs",
                  v71,
                  v72,
                  v73,
                  v74,
                  v75,
                  v76,
                  v77,
                  v78,
                  "lim_send_assoc_rsp_mgmt_frame");
                HIDWORD(n) = lim_send_assoc_rsp_mgmt_frame_mlo(a1, v25, a6, &lim_send_assoc_rsp_mgmt_frame_frm);
                LODWORD(n) = v49;
                if ( !a4 )
                  goto LABEL_89;
                goto LABEL_85;
              }
LABEL_84:
              LODWORD(n) = v49;
              if ( !a4 )
                goto LABEL_89;
LABEL_85:
              if ( *v29 == 1 )
              {
                v80 = lim_search_pre_auth_list(*(_QWORD *)(v25 + 8608), a4);
                if ( v80 )
                {
                  v89 = (_BYTE *)v80[76];
                  if ( v89 )
                    goto LABEL_90;
                }
                else
                {
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: No preauth node created for %02x:%02x:%02x:**:**:%02x",
                    v81,
                    v82,
                    v83,
                    v84,
                    v85,
                    v86,
                    v87,
                    v88,
                    "lim_get_fils_info",
                    *a4,
                    a4[1],
                    a4[2],
                    a4[5]);
                }
                goto LABEL_96;
              }
LABEL_89:
              v89 = *(_BYTE **)(v25 + 9976);
              if ( v89 )
              {
LABEL_90:
                if ( (v213 & *v89) != 0 )
                  v90 = 16;
                else
                  v90 = 0;
                v206 = a8;
                if ( !a6 )
                  goto LABEL_102;
LABEL_97:
                if ( *(_BYTE *)(a6 + 68) == 1 && v26[3047] == 1 )
                {
                  v91 = _qdf_mem_malloc(0x101u, "lim_send_assoc_rsp_mgmt_frame", 2518);
                  v100 = (_BYTE *)v91;
                  if ( v91 )
                  {
                    v224 = qword_8D8D08;
                    v225 = qword_8D8D10;
                    LOWORD(v226) = word_8D8D18;
                    v236 = qword_8D8918;
                    v237 = qword_8D8920;
                    v238 = qword_8D8928;
                    LOWORD(v239) = word_8D8930;
                    v232 = qword_8D88F8;
                    v233 = unk_8D8900;
                    v234 = qword_8D8908;
                    v235 = qword_8D8910;
                    lim_ieee80211_pack_ehtop(
                      v91,
                      qword_8D94AC,
                      (unsigned int)dword_8D94B4,
                      (unsigned int)dword_8D89A8 | ((unsigned __int64)(unsigned __int16)word_8D89AC << 32),
                      &v224,
                      &v232);
                    v101 = v100[1];
                    LOBYTE(qword_8D94AC) = 0;
                    v102 = (_BYTE *)_qdf_mem_malloc(0x101u, "lim_send_assoc_rsp_mgmt_frame", 2535);
                    if ( v102 )
                    {
                      v111 = v101 + 2;
                      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v25 + 284));
                      v240 = qword_8D9490;
                      v241 = qword_8D9498;
                      v242 = qword_8D94A0;
                      v243 = dword_8D94A8;
                      v236 = qword_8D9470;
                      v237 = qword_8D9478;
                      v238 = qword_8D9480;
                      v239 = qword_8D9488;
                      v232 = qword_8D9450;
                      v233 = qword_8D9458;
                      v234 = qword_8D9460;
                      v235 = qword_8D9468;
                      v228 = qword_8D8CEC;
                      v229 = qword_8D8CF4;
                      v230 = qword_8D8CFC;
                      v231 = dword_8D8D04;
                      v224 = qword_8D8CCC;
                      v225 = qword_8D8CD4;
                      v226 = qword_8D8CDC;
                      v227 = qword_8D8CE4;
                      lim_ieee80211_pack_ehtcap(v102, &v232, &v224, is_24ghz_ch_freq, 0);
                      v113 = v102[1];
                      LOBYTE(qword_8D9450) = 0;
                      v114 = v113 + 2;
                      goto LABEL_103;
                    }
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "%s: malloc failed for eht_cap_ie",
                      v103,
                      v104,
                      v105,
                      v106,
                      v107,
                      v108,
                      v109,
                      v110,
                      "lim_send_assoc_rsp_mgmt_frame");
                  }
                  else
                  {
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "%s: malloc failed for eht_op_ie",
                      v92,
                      v93,
                      v94,
                      v95,
                      v96,
                      v97,
                      v98,
                      v99,
                      "lim_send_assoc_rsp_mgmt_frame");
                    v102 = nullptr;
                  }
LABEL_138:
                  _qdf_mem_free((__int64)v102);
                  _qdf_mem_free((__int64)v100);
                  result = _qdf_mem_free((__int64)v212);
                  goto LABEL_139;
                }
LABEL_102:
                v100 = nullptr;
                v111 = 0;
                v102 = nullptr;
                v114 = 0;
LABEL_103:
                packed_assoc_response_size = dot11f_get_packed_assoc_response_size(
                                               a1,
                                               &lim_send_assoc_rsp_mgmt_frame_frm,
                                               &v222);
                if ( (packed_assoc_response_size & 0x10000000) != 0 )
                {
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: get Association Response size failure (0x%08x)",
                    v116,
                    v117,
                    v118,
                    v119,
                    v120,
                    v121,
                    v122,
                    v123,
                    "lim_send_assoc_rsp_mgmt_frame",
                    packed_assoc_response_size);
                }
                else
                {
                  *(_QWORD *)v205 = v100;
                  if ( packed_assoc_response_size )
                    qdf_trace_msg(
                      0x35u,
                      3u,
                      "%s: get Association Response size warning (0x%08x)",
                      v116,
                      v117,
                      v118,
                      v119,
                      v120,
                      v121,
                      v122,
                      v123,
                      "lim_send_assoc_rsp_mgmt_frame");
                  v124 = v59 + WORD2(n) + v90 + v111 + v114 + v222 + 24;
                  if ( a6 )
                    v124 += *(_DWORD *)(a6 + 48) + *(_DWORD *)(a6 + 64);
                  if ( (unsigned int)cds_packet_alloc(v124, &v223, &v221) )
                  {
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "%s: cds_packet_alloc failed",
                      v125,
                      v126,
                      v127,
                      v128,
                      v129,
                      v130,
                      v131,
                      v132,
                      "lim_send_assoc_rsp_mgmt_frame");
                  }
                  else
                  {
                    v204 = v124;
                    qdf_mem_set(v223, v124, 0);
                    v133 = v223;
                    v134 = v223 + 4;
                    if ( v210 )
                      v135 = 48;
                    else
                      v135 = 16;
                    *v223 = v135;
                    qdf_mem_copy(v134, a4, 6u);
                    v133[10] = *(_BYTE *)(v25 + 30);
                    v133[11] = *(_BYTE *)(v25 + 31);
                    v133[12] = *(_BYTE *)(v25 + 32);
                    v133[13] = *(_BYTE *)(v25 + 33);
                    v133[14] = *(_BYTE *)(v25 + 34);
                    v133[15] = *(_BYTE *)(v25 + 35);
                    qdf_mem_copy(v133 + 16, a4, 6u);
                    v144 = *(unsigned __int16 *)(a1 + 21604);
                    if ( v144 <= 0xFFE )
                      v145 = v144 + 1;
                    else
                      v145 = 2048;
                    *(_WORD *)(a1 + 21604) = v145;
                    *((_WORD *)v133 + 11) = (16 * (v145 & 0xF)) | *((_WORD *)v133 + 11) & 0xFF0F;
                    v146 = (unsigned __int8)(*(_WORD *)(a1 + 21604) >> 4);
                    *((_WORD *)v133 + 11) = (16 * *(_WORD *)(a1 + 21604)) & 0xFF00 | (16 * (v145 & 0xF));
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
                      v136,
                      v137,
                      v138,
                      v139,
                      v140,
                      v141,
                      v142,
                      v143,
                      "lim_populate_mac_header",
                      v145 & 0xF,
                      v146,
                      *(unsigned __int16 *)(a1 + 21604),
                      0);
                    v147 = v223;
                    v148 = v223;
                    v223[16] = *(_BYTE *)(v25 + 24);
                    v149 = v148 + 16;
                    v147[17] = *(_BYTE *)(v25 + 25);
                    v147[18] = *(_BYTE *)(v25 + 26);
                    v147[19] = *(_BYTE *)(v25 + 27);
                    v147[20] = *(_BYTE *)(v25 + 28);
                    v147[21] = *(_BYTE *)(v25 + 29);
                    v150 = dot11f_pack_assoc_response(a1, &lim_send_assoc_rsp_mgmt_frame_frm, v223 + 24, v222, &v222);
                    if ( (v150 & 0x10000000) != 0 )
                    {
                      qdf_trace_msg(
                        0x35u,
                        2u,
                        "%s: Association Response pack failure(0x%08x)",
                        v151,
                        v152,
                        v153,
                        v154,
                        v155,
                        v156,
                        v157,
                        v158,
                        "lim_send_assoc_rsp_mgmt_frame",
                        v150);
                      cds_packet_free(v221);
                    }
                    else
                    {
                      if ( v150 )
                        qdf_trace_msg(
                          0x35u,
                          3u,
                          "%s: Association Response pack warning (0x%08x)",
                          v151,
                          v152,
                          v153,
                          v154,
                          v155,
                          v156,
                          v157,
                          v158,
                          "lim_send_assoc_rsp_mgmt_frame");
                      if ( v111 )
                      {
                        qdf_mem_copy(&v223[v222 + 24], v100, v111);
                        v222 += v111;
                      }
                      if ( v114 )
                      {
                        qdf_mem_copy(&v223[v222 + 24], v102, v114);
                        v222 += v114;
                      }
                      if ( (unsigned int)(n - 1) <= 0xFE )
                      {
                        qdf_mem_copy(&v223[v222 + 24], v212, (unsigned int)n);
                        v222 += n;
                      }
                      v159 = WORD2(n);
                      if ( a6 )
                      {
                        v160 = *(unsigned int *)(a6 + 48);
                        if ( (_DWORD)v160 )
                        {
                          qdf_mem_copy(&v223[v222 + 24], *(const void **)(a6 + 40), v160);
                          v222 += *(_DWORD *)(a6 + 48);
                        }
                        v161 = *(unsigned int *)(a6 + 64);
                        if ( (_DWORD)v161 )
                        {
                          qdf_mem_copy(&v223[v222 + 24], *(const void **)(a6 + 56), v161);
                          v222 += *(_DWORD *)(a6 + 64);
                        }
                        if ( WORD2(n) )
                        {
                          if ( (unsigned int)lim_fill_complete_mlo_ie(v25, HIDWORD(n), &v223[v222 + 24]) )
                          {
                            qdf_trace_msg(
                              0x35u,
                              8u,
                              "%s: assemble ml ie error",
                              v151,
                              v152,
                              v153,
                              v154,
                              v155,
                              v156,
                              v157,
                              v158,
                              "lim_send_assoc_rsp_mgmt_frame");
                            v159 = 0;
                          }
                          v222 += v159;
                        }
                      }
                      if ( v147 == (char *)-4LL )
                      {
                        v164 = 0;
                        v162 = 0;
                        v163 = 0;
                        v165 = 0;
                      }
                      else
                      {
                        v162 = (unsigned __int8)v147[4];
                        v163 = (unsigned __int8)v147[5];
                        v164 = (unsigned __int8)v147[6];
                        v165 = (unsigned __int8)v147[9];
                      }
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "Assoc rsp TX: vdev %d subtype %d to %02x:%02x:%02x:**:**:%02x seq num %d status %d aid %d addn_i"
                        "e_len %d ht %d vht %d vendor vht %d he %d eht %d",
                        v151,
                        v152,
                        v153,
                        v154,
                        v155,
                        v156,
                        v157,
                        v158,
                        *(unsigned __int8 *)(v25 + 10),
                        v210,
                        v162,
                        v163,
                        v164,
                        v165,
                        *(unsigned __int16 *)(a1 + 21604),
                        (unsigned __int16)v207,
                        (unsigned __int16)v211,
                        n,
                        (unsigned __int8)byte_8D88BC,
                        (unsigned __int8)byte_8D8998,
                        (unsigned __int8)byte_8D9920,
                        (unsigned __int8)qword_8D8CCC,
                        (unsigned __int8)qword_8D9450);
                      LOBYTE(v198) = 0;
                      LOBYTE(v195) = (unsigned __int8)qword_8D8CCC != 0;
                      LOBYTE(v196) = (unsigned __int8)qword_8D9450 != 0;
                      lim_cp_stats_cstats_log_assoc_resp_evt(
                        v25,
                        0,
                        v207,
                        v211,
                        v149,
                        v147 + 4,
                        byte_8D88BC != 0,
                        byte_8D8998 != 0,
                        v195,
                        v196,
                        v198);
                      if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v25 + 284))
                        && (*(_DWORD *)(v25 + 7036) & 0xFFFFFFFE) != 2 )
                      {
                        v174 = 0;
                      }
                      else
                      {
                        v174 = 64;
                      }
                      v175 = *(_QWORD *)(a1 + 21624);
                      v100 = *(_BYTE **)v205;
                      v215 = v223 + 30;
                      LODWORD(v214) = v222 - 6;
                      mlme_set_peer_assoc_rsp_ie(
                        v175,
                        a4,
                        (unsigned int *)&v214,
                        v166,
                        v167,
                        v168,
                        v169,
                        v170,
                        v171,
                        v172,
                        v173);
                      qdf_trace(53, 2u, *(_WORD *)(v25 + 8), (unsigned __int8)*(_WORD *)v147 >> 4);
                      v176 = lim_diag_mgmt_tx_event_report(a1, v147, v25, 0, v207);
                      context = _cds_get_context(
                                  54,
                                  (__int64)"lim_send_assoc_rsp_mgmt_frame",
                                  v176,
                                  v177,
                                  v178,
                                  v179,
                                  v180,
                                  v181,
                                  v182,
                                  v183);
                      LOWORD(v203) = 0;
                      LOBYTE(v202) = 0;
                      LOWORD(v201) = 0;
                      if ( (v206 & 1) != 0 )
                      {
                        LOBYTE(v199) = v209;
                        LOBYTE(v197) = v174;
                        LOBYTE(v200) = 0;
                        v185 = wma_tx_packet(
                                 context,
                                 v221,
                                 v204,
                                 3,
                                 1,
                                 7,
                                 lim_tx_complete,
                                 v223,
                                 lim_assoc_rsp_tx_complete,
                                 v197,
                                 v199,
                                 v200,
                                 v201,
                                 12,
                                 v202,
                                 v203);
                      }
                      else
                      {
                        LOBYTE(v200) = 0;
                        LOBYTE(v199) = v209;
                        LOBYTE(v197) = v174;
                        v185 = wma_tx_packet(
                                 context,
                                 v221,
                                 v204,
                                 3,
                                 1,
                                 7,
                                 lim_tx_complete,
                                 v223,
                                 0,
                                 v197,
                                 v199,
                                 v200,
                                 v201,
                                 12,
                                 v202,
                                 v203);
                      }
                      v186 = v185;
                      qdf_trace(53, 5u, *(_WORD *)(v25 + 8), v185);
                      if ( v186 )
                        qdf_trace_msg(
                          0x35u,
                          2u,
                          "%s: Could not Send Re/AssocRsp, retCode=%X",
                          v187,
                          v188,
                          v189,
                          v190,
                          v191,
                          v192,
                          v193,
                          v194,
                          "lim_send_assoc_rsp_mgmt_frame",
                          v186);
                      lim_util_count_sta_add(a1, a6, v25);
                    }
                  }
                }
                goto LABEL_138;
              }
LABEL_96:
              v90 = 0;
              v206 = a8;
              if ( !a6 )
                goto LABEL_102;
              goto LABEL_97;
            }
          }
          n = v49;
          if ( !a4 )
            goto LABEL_89;
          goto LABEL_85;
        }
      }
      else
      {
        v49 = 0;
      }
      v59 = 0;
      goto LABEL_71;
    }
    v30 = "%s: memory alloc failed for add_ie";
  }
  else
  {
    v30 = "%s: pe_session is NULL";
  }
  result = qdf_trace_msg(0x35u, 2u, v30, v17, v18, v19, v20, v21, v22, v23, v24, "lim_send_assoc_rsp_mgmt_frame");
LABEL_139:
  _ReadStatusReg(SP_EL0);
  return result;
}
