__int64 __fastcall csr_check_concurrent_channel_overlap(
        __int64 a1,
        unsigned int a2,
        int a3,
        unsigned int a4,
        unsigned int a5)
{
  __int64 v5; // x22
  int v6; // w8
  __int64 v8; // x0
  unsigned int ll_lt_sap_restart_freq; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  unsigned int ll_lt_sap_freq; // w23
  int opmode_from_vdev_id; // w0
  unsigned int v25; // w19
  bool is_24ghz_ch_freq; // w0
  __int64 v27; // x8
  int v28; // w25
  unsigned int v29; // w27
  int v30; // w8
  unsigned int v31; // w26
  unsigned int v32; // w9
  unsigned __int8 is_mlo_ap; // w23
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x27
  __int64 v43; // x25
  unsigned int v44; // w28
  __int64 v45; // x8
  __int64 v46; // x24
  int v47; // w26
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x4
  const char *v65; // x2
  __int64 v66; // x0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  int v75; // w11
  int v76; // w8
  __int64 v77; // x0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x26
  __int64 cmpt_obj; // x0
  unsigned int *v88; // x8
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  int v105; // w7
  bool v106; // zf
  int v107; // w11
  unsigned int v108; // w10
  unsigned int v109; // w10
  unsigned int v110; // w1
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  _BOOL4 v120; // w9
  unsigned int v121; // w8
  unsigned int v122; // w9
  int v123; // w9
  unsigned int v124; // w23
  char is_hw_dbs_capable; // w0
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  int v142; // w8
  bool is_force_scc; // w0
  int v144; // w9
  bool v145; // zf
  unsigned int v146; // w20
  unsigned int v147; // w21
  unsigned int v148; // w22
  unsigned int v149; // w23
  bool v150; // cf
  bool v151; // w8
  bool v152; // cc
  __int64 v153; // x5
  const char *v154; // x6
  __int64 v155; // [xsp+0h] [xbp-90h]
  __int64 v156; // [xsp+8h] [xbp-88h]
  unsigned int v157; // [xsp+44h] [xbp-4Ch]
  unsigned int v158; // [xsp+48h] [xbp-48h]
  _BOOL4 v159; // [xsp+4Ch] [xbp-44h]
  unsigned int v160; // [xsp+50h] [xbp-40h]
  __int64 v161; // [xsp+54h] [xbp-3Ch]
  unsigned int v162; // [xsp+5Ch] [xbp-34h]
  unsigned int v163; // [xsp+60h] [xbp-30h]
  __int64 v164; // [xsp+64h] [xbp-2Ch]
  __int64 v165; // [xsp+6Ch] [xbp-24h] BYREF
  __int64 v166; // [xsp+74h] [xbp-1Ch] BYREF
  unsigned int v167; // [xsp+7Ch] [xbp-14h] BYREF
  _QWORD v168[2]; // [xsp+80h] [xbp-10h] BYREF

  v5 = a1 + 0x4000;
  v168[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned __int8 *)(a1 + 17229);
  v166 = 0;
  if ( !v6 )
  {
LABEL_4:
    result = 0;
    goto LABEL_194;
  }
  v8 = *(_QWORD *)(a1 + 21624);
  v165 = 0;
  if ( policy_mgr_is_vdev_ll_lt_sap(v8, (unsigned __int8)a5) )
  {
    ll_lt_sap_restart_freq = wlan_get_ll_lt_sap_restart_freq(*(_QWORD *)(a1 + 21632), a2, a5, &v165);
    if ( ll_lt_sap_restart_freq != a2 )
    {
      v25 = ll_lt_sap_restart_freq;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: LL_LT_SAP concurrency updated freq %d for vdev %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "csr_check_concurrent_channel_overlap",
        ll_lt_sap_restart_freq,
        (unsigned __int8)a5);
      result = v25;
      goto LABEL_194;
    }
    goto LABEL_4;
  }
  ll_lt_sap_freq = policy_mgr_get_ll_lt_sap_freq(*(_QWORD *)(a1 + 21624));
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), a5);
  v159 = ll_lt_sap_freq
      && (ll_lt_sap_freq == a2
       || opmode_from_vdev_id == 1
       && (policy_mgr_are_2_freq_on_same_mac(*(_QWORD *)(a1 + 21624), a2, ll_lt_sap_freq) & 1) != 0);
  v160 = a4;
  if ( a2 )
  {
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(a2);
    v27 = 17196;
    if ( is_24ghz_ch_freq )
      v27 = 17192;
    v28 = *(unsigned __int8 *)(a1 + v27);
    if ( *(_BYTE *)(a1 + v27) )
    {
      v29 = 10;
      if ( a3 > 2047 )
      {
        if ( a3 >= 0x2000 )
        {
          if ( a3 != 0x2000 && a3 != 0x4000 )
            goto LABEL_39;
        }
        else if ( a3 != 2048 && a3 != 4096 )
        {
          goto LABEL_39;
        }
      }
      else
      {
        if ( a3 <= 255 )
        {
          if ( a3 == 16 || a3 == 64 )
          {
            v29 = 20;
            if ( v28 == 1 )
            {
              v30 = 10;
              goto LABEL_43;
            }
            if ( v28 == 3 )
            {
              v30 = -10;
LABEL_43:
              v31 = v30 + a2;
              goto LABEL_44;
            }
          }
          goto LABEL_39;
        }
        if ( a3 != 256 && a3 != 512 )
        {
LABEL_39:
          v31 = a2;
          goto LABEL_44;
        }
      }
      v32 = (unsigned __int8)(v28 - 6);
      if ( *(_DWORD *)(v5 + 840) == 2 )
      {
        if ( v32 < 4 )
        {
          v30 = dword_B35A18[(unsigned __int8)(v28 - 6)];
          v29 = 40;
          goto LABEL_43;
        }
        v29 = 40;
        v31 = a2;
      }
      else
      {
        if ( v32 < 4 )
        {
          v30 = *(_DWORD *)&a66666666[4 * (unsigned __int8)(v28 - 6) + 16];
          v29 = 20;
          goto LABEL_43;
        }
        v29 = 20;
        v31 = a2;
      }
    }
    else
    {
      v29 = 10;
      v31 = a2;
    }
  }
  else
  {
    v28 = 0;
    v29 = 0;
    v31 = 0;
  }
LABEL_44:
  is_mlo_ap = policy_mgr_is_mlo_ap(*(_QWORD *)(a1 + 21624), a5);
  v157 = v29;
  v158 = v31;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: sap_ch:%d sap_phymode:%d sap_cch:%d sap_hbw:%d chb:%d ml:%d",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "csr_check_concurrent_channel_overlap",
    a2,
    (unsigned int)a3,
    v31,
    v29,
    v28,
    is_mlo_ap & 1);
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v164 = 0;
  v161 = 0;
  v162 = 255;
  v163 = 255;
  while ( 1 )
  {
    if ( !a1 )
      goto LABEL_47;
    v45 = *(_QWORD *)(a1 + 17296);
    if ( !v45 || *(_BYTE *)(v45 + v42 + 1) != 1 || policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21624), v43) )
      goto LABEL_47;
    v46 = *(_QWORD *)(a1 + 17296);
    v47 = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), v43);
    if ( (v47 | 2) == 2 && cm_is_vdevid_connected(*(_QWORD *)(a1 + 21632), v43) )
    {
      if ( !v47
        && (policy_mgr_is_ml_vdev_id(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(v46 + v42)) & 1) != 0
        && (policy_mgr_vdev_is_force_inactive(*(_QWORD *)(a1 + 21624), *(_BYTE *)(v46 + v42)) & 1) != 0 )
      {
        v64 = *(unsigned __int8 *)(v46 + v42);
        v65 = "%s: skip inactive ml sta vdev %d";
LABEL_73:
        qdf_trace_msg(
          0x34u,
          8u,
          v65,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          "csr_check_concurrent_channel_overlap",
          v64);
        goto LABEL_47;
      }
      v77 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              *(_QWORD *)(a1 + 21624),
              *(unsigned __int8 *)(v46 + v42),
              11);
      if ( v77 )
      {
        v86 = v77;
        cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v77, v78, v79, v80, v81, v82, v83, v84, v85);
        if ( cmpt_obj )
        {
          v88 = (unsigned int *)*(unsigned __int8 *)(cmpt_obj + 197);
          if ( (_DWORD)v88 == 1 )
          {
            wlan_objmgr_vdev_release_ref(v86, 0xBu, v88, v89, v90, v91, v92, v93, v94, v95, v96);
            v64 = *(unsigned __int8 *)(v46 + v42);
            v65 = "%s: Skip STA vdev:%d which received CSA";
            goto LABEL_73;
          }
        }
        wlan_objmgr_vdev_release_ref(v86, 0xBu, v88, v89, v90, v91, v92, v93, v94, v95, v96);
      }
      wlan_get_op_chan_freq_info_vdev_id(
        *(_QWORD *)(a1 + 21632),
        *(_BYTE *)(v46 + v42),
        (_DWORD *)&v166 + 1,
        &v166,
        (_DWORD *)&v165 + 1);
      if ( (unsigned int)(HIDWORD(v165) - 1) > 3 )
        v105 = 10;
      else
        v105 = dword_B35968[HIDWORD(v165) - 1];
      v106 = v44 == 0;
      if ( v44 )
        v107 = HIDWORD(v166);
      else
        v107 = v164;
      v108 = v163;
      if ( !v44 )
      {
        v108 = *(unsigned __int8 *)(v46 + v42);
        v44 = HIDWORD(v166);
      }
      LODWORD(v155) = HIDWORD(v165);
      v163 = v108;
      LODWORD(v164) = v107;
      v109 = v162;
      if ( !v106 )
        v109 = *(unsigned __int8 *)(v46 + v42);
      HIDWORD(v161) = v105;
      v162 = v109;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: %d: intf_ch:%d intf_cfreq:%d intf_hbw:%d ch_width %d",
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        "csr_check_concurrent_channel_overlap",
        (unsigned int)v43,
        v155);
    }
    else if ( (v47 & 0xFFFFFFFD) == 1 && *(_DWORD *)(v46 + v42 + 4) )
    {
      if ( (*(_BYTE *)(v46 + v42 + 60) & 1) != 0 )
        goto LABEL_47;
      v168[0] = 0;
      v66 = *(_QWORD *)(a1 + 21632);
      v167 = 0;
      wlan_get_op_chan_freq_info_vdev_id(v66, *(_BYTE *)(v46 + v42), (_DWORD *)v168 + 1, v168, &v167);
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: op_chan_freq:%d freq_seg_0:%d ch_width:%d",
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        "csr_handle_conc_chnl_overlap_for_sap_go",
        HIDWORD(v168[0]),
        LODWORD(v168[0]),
        v167);
      if ( *(_BYTE *)(v5 + 847) || *(_BYTE *)(v5 + 848) )
      {
        if ( a2 )
        {
          v75 = HIDWORD(v161);
        }
        else
        {
          v75 = HIDWORD(v161);
          if ( v47 == 1 )
          {
            a2 = HIDWORD(v168[0]);
            v158 = v168[0];
            if ( v167 - 3 < 2 )
            {
              v76 = 80;
            }
            else if ( v167 == 2 )
            {
              v76 = 40;
            }
            else if ( v167 == 1 )
            {
              v76 = 20;
            }
            else
            {
              v76 = 10;
            }
            v157 = v76;
          }
        }
      }
      else if ( a2 )
      {
        v75 = HIDWORD(v161);
        v120 = (unsigned __int8)v160 == 4 && v47 == 3;
        if ( a2 != HIDWORD(v168[0]) || v120 )
        {
          v166 = v168[0];
          if ( v167 - 3 < 2 )
          {
            v75 = 80;
          }
          else if ( v167 == 2 )
          {
            v75 = 40;
          }
          else if ( v167 == 1 )
          {
            v75 = 20;
          }
          else
          {
            v75 = 10;
          }
        }
      }
      else
      {
        v158 = v168[0];
        v75 = HIDWORD(v161);
        if ( v167 - 3 < 2 )
        {
          v123 = 80;
        }
        else if ( v167 == 2 )
        {
          v123 = 40;
        }
        else if ( v167 == 1 )
        {
          v123 = 20;
        }
        else
        {
          v123 = 10;
        }
        v157 = v123;
        a2 = HIDWORD(v168[0]);
      }
      v121 = HIDWORD(v166);
      HIDWORD(v161) = v75;
      if ( (is_mlo_ap & 1) != 0 && (unsigned __int8)a5 != v43 && !HIDWORD(v166) )
      {
        v121 = a2;
        HIDWORD(v166) = a2;
      }
      v122 = v161;
      if ( v121 )
        v122 = v121;
      LODWORD(v161) = v122;
      v110 = HIDWORD(v166);
      if ( !HIDWORD(v166) )
        goto LABEL_89;
      goto LABEL_87;
    }
    v110 = HIDWORD(v166);
    if ( !HIDWORD(v166) )
      goto LABEL_89;
LABEL_87:
    if ( (wlan_reg_get_channel_state_for_pwrmode(
            *(_QWORD *)(a1 + 21632),
            v110,
            0,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55)
        & 0xFFFFFFFB) == 0 )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: skip vdev %d for intf_ch:%d",
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        "csr_check_concurrent_channel_overlap",
        (unsigned int)v43,
        HIDWORD(v166));
LABEL_46:
      HIDWORD(v166) = 0;
      goto LABEL_47;
    }
    BYTE4(v164) += !wlan_reg_is_24ghz_ch_freq(HIDWORD(v166));
LABEL_89:
    if ( (is_mlo_ap & 1) != 0 )
      break;
    if ( HIDWORD(v166) && (policy_mgr_2_freq_always_on_same_mac(*(_QWORD *)(a1 + 21624), HIDWORD(v166), a2) & 1) != 0 )
      goto LABEL_137;
LABEL_47:
    ++v43;
    v42 += 96;
    if ( v43 == 6 )
      goto LABEL_137;
  }
  if ( !HIDWORD(v166)
    || ((policy_mgr_is_scc_with_this_vdev_id(*(_QWORD *)(a1 + 21624), v43) & 1) != 0
     || (policy_mgr_are_2_freq_on_same_mac(*(_QWORD *)(a1 + 21624), HIDWORD(v166), a2) & 1) == 0)
    && (!HIDWORD(v166)
     || HIDWORD(v166) == a2
     || (policy_mgr_2_freq_always_on_same_mac(*(_QWORD *)(a1 + 21624), HIDWORD(v166), a2) & 1) == 0) )
  {
    goto LABEL_46;
  }
LABEL_137:
  if ( !HIDWORD(v166)
    && v44
    && (_DWORD)v164
    && (policy_mgr_is_ml_vdev_id(*(_QWORD *)(a1 + 21624), v163) & 1) != 0
    && (policy_mgr_is_ml_vdev_id(*(_QWORD *)(a1 + 21624), v162) & 1) != 0 )
  {
    HIDWORD(v166) = policy_mgr_get_conc_freq_if_ml_sta_in_smm(*(_QWORD *)(a1 + 21624), a2, v44, v164);
  }
  if ( (is_mlo_ap & ((unsigned __int8)(BYTE4(v164) + !wlan_reg_is_24ghz_ch_freq(a2)) > 2u)) == 1
    && (policy_mgr_is_sta_sap_scc(*(_QWORD *)(a1 + 21624), v161, 0) & 1) != 0
    && v44
    && (_DWORD)v164 )
  {
    if ( (_DWORD)v161 == v44 )
    {
      if ( v44 != (_DWORD)v164 )
        HIDWORD(v166) = v164;
    }
    else
    {
      HIDWORD(v166) = v44;
    }
  }
  v124 = HIDWORD(v166);
  is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(*(_QWORD *)(a1 + 21624));
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: intf_ch:%d sap_ch:%d cc_switch_mode:%d, dbs:%d",
    v126,
    v127,
    v128,
    v129,
    v130,
    v131,
    v132,
    v133,
    "csr_check_concurrent_channel_overlap",
    v124,
    a2,
    (unsigned __int8)v160,
    is_hw_dbs_capable & 1);
  v142 = HIDWORD(v166);
  if ( !HIDWORD(v166)
    || a2 == HIDWORD(v166)
    || (is_force_scc = policy_mgr_is_force_scc(*(_QWORD *)(a1 + 21624)), v142 = HIDWORD(v166), is_force_scc) )
  {
    v144 = v159;
    if ( v142 )
      v145 = a2 == v142;
    else
      v145 = 1;
    if ( !v145 )
      v144 = 1;
    if ( v144 == 1 )
    {
      if ( policy_mgr_is_force_scc(*(_QWORD *)(a1 + 21624)) )
      {
        ((void (__fastcall *)(_QWORD, char *, _QWORD, _QWORD, _QWORD))policy_mgr_check_scc_channel)(
          *(_QWORD *)(a1 + 21624),
          (char *)&v166 + 4,
          a2,
          (unsigned __int8)a5,
          v160);
        goto LABEL_188;
      }
      v142 = HIDWORD(v166);
    }
    if ( (unsigned __int8)v160 == 4
      && v142 == a2
      && ((unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, char *))policy_mgr_handle_go_sap_fav_channel)(
                          *(_QWORD *)(a1 + 21624),
                          a5,
                          a2,
                          (char *)&v166 + 4)
       || !HIDWORD(v166)
       || HIDWORD(v166) == a2)
      && (wlan_reg_is_24ghz_ch_freq(HIDWORD(v166)) || wlan_reg_is_6ghz_chan_freq(a2))
      && (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, char *, _QWORD))policy_mgr_get_sap_mandatory_channel)(
                         *(_QWORD *)(a1 + 21624),
                         a2,
                         (char *)&v166 + 4,
                         a5) )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: no mandatory channel",
        v134,
        v135,
        v136,
        v137,
        v138,
        v139,
        v140,
        v141,
        "csr_check_concurrent_channel_overlap");
    }
  }
  else
  {
    v146 = v158 - v157;
    v147 = v158 + v157;
    v148 = v166 - HIDWORD(v161);
    v149 = v166 + HIDWORD(v161);
    LODWORD(v156) = HIDWORD(v166);
    LODWORD(v155) = v158 + v157;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: SAP:  OCH: %03d CCH: %03d BW: %d LF: %d HF: %d INTF: OCH: %03d CF: %d BW: %d LF: %d HF: %d",
      v134,
      v135,
      v136,
      v137,
      v138,
      v139,
      v140,
      v141,
      "csr_check_concurrent_channel_overlap",
      a2,
      v158,
      2 * v157,
      v158 - v157,
      v155,
      v156,
      v166,
      2 * HIDWORD(v161),
      v166 - HIDWORD(v161),
      v166 + HIDWORD(v161));
    if ( (v158 - v157 <= v148 || v146 >= v149) && (v147 <= v148 || v147 >= v149) )
    {
      v150 = v146 >= v149 || v149 >= v147;
      v151 = !v150;
      v152 = v147 > v148 && v148 > v146;
      if ( !v152 && !v151 )
        HIDWORD(v166) = 0;
    }
  }
LABEL_188:
  v153 = HIDWORD(v166);
  if ( HIDWORD(v166) == a2 )
  {
    v153 = 0;
    HIDWORD(v166) = 0;
    v154 = "Not";
  }
  else if ( HIDWORD(v166) )
  {
    v154 = "Are";
  }
  else
  {
    v154 = "Not";
  }
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: ##Concurrent Channels (%d, %d) %s Interfering",
    v134,
    v135,
    v136,
    v137,
    v138,
    v139,
    v140,
    v141,
    "csr_check_concurrent_channel_overlap",
    a2,
    v153,
    v154);
  result = HIDWORD(v166);
LABEL_194:
  _ReadStatusReg(SP_EL0);
  return result;
}
