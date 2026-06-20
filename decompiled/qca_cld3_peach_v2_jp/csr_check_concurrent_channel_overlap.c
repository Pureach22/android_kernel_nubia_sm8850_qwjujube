__int64 __fastcall csr_check_concurrent_channel_overlap(
        __int64 a1,
        unsigned int a2,
        int a3,
        unsigned int a4,
        unsigned int a5)
{
  __int64 v5; // x25
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
  unsigned int ll_lt_sap_freq; // w24
  int opmode_from_vdev_id; // w0
  unsigned int v25; // w19
  bool is_24ghz_ch_freq; // w0
  __int64 v27; // x8
  int v28; // w22
  unsigned int v29; // w24
  unsigned int v30; // w26
  unsigned int v31; // w9
  int v32; // w8
  unsigned __int8 is_mlo_ap; // w27
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x22
  __int64 v43; // x23
  int v44; // w24
  __int64 v45; // x8
  __int64 v46; // x26
  int v47; // w28
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x28
  __int64 cmpt_obj; // x0
  unsigned int *v67; // x8
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  int v93; // w12
  int v94; // w8
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  int v103; // w7
  int v104; // w9
  unsigned int v105; // w1
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  _BOOL4 v115; // w9
  unsigned int v116; // w8
  unsigned int v117; // w9
  int v118; // w9
  unsigned int v119; // w23
  char is_hw_dbs_capable; // w0
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  int v137; // w8
  bool is_force_scc; // w0
  int v139; // w9
  bool v140; // zf
  unsigned int v141; // w20
  unsigned int v142; // w21
  unsigned int v143; // w22
  unsigned int v144; // w23
  bool v145; // cf
  bool v146; // w8
  bool v147; // cc
  __int64 v148; // x5
  const char *v149; // x6
  __int64 v150; // [xsp+0h] [xbp-90h]
  __int64 v151; // [xsp+8h] [xbp-88h]
  unsigned int v152; // [xsp+4Ch] [xbp-44h]
  unsigned int v153; // [xsp+50h] [xbp-40h]
  _BOOL4 v154; // [xsp+54h] [xbp-3Ch]
  unsigned int v155; // [xsp+58h] [xbp-38h]
  __int64 v156; // [xsp+5Ch] [xbp-34h]
  __int64 v157; // [xsp+64h] [xbp-2Ch]
  __int64 v158; // [xsp+6Ch] [xbp-24h] BYREF
  __int64 v159; // [xsp+74h] [xbp-1Ch] BYREF
  unsigned int v160; // [xsp+7Ch] [xbp-14h] BYREF
  _QWORD v161[2]; // [xsp+80h] [xbp-10h] BYREF

  v5 = a1 + 0x4000;
  v161[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned __int8 *)(a1 + 17157);
  v159 = 0;
  if ( !v6 )
  {
LABEL_4:
    result = 0;
    goto LABEL_174;
  }
  v8 = *(_QWORD *)(a1 + 21552);
  v158 = 0;
  if ( policy_mgr_is_vdev_ll_lt_sap(v8, (unsigned __int8)a5) )
  {
    ll_lt_sap_restart_freq = wlan_get_ll_lt_sap_restart_freq(*(_QWORD *)(a1 + 21560), a2, a5, &v158);
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
      goto LABEL_174;
    }
    goto LABEL_4;
  }
  ll_lt_sap_freq = policy_mgr_get_ll_lt_sap_freq(*(_QWORD *)(a1 + 21552));
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), a5);
  v154 = ll_lt_sap_freq
      && (ll_lt_sap_freq == a2
       || opmode_from_vdev_id == 1
       && (policy_mgr_are_2_freq_on_same_mac(*(_QWORD *)(a1 + 21552), a2, ll_lt_sap_freq) & 1) != 0);
  v155 = a4;
  if ( a2 )
  {
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(a2);
    v27 = 17124;
    if ( is_24ghz_ch_freq )
      v27 = 17120;
    v28 = *(unsigned __int8 *)(a1 + v27);
    if ( *(_BYTE *)(a1 + v27) )
    {
      v29 = 10;
      if ( a3 > 511 )
      {
        if ( a3 != 512 && a3 != 2048 && a3 != 4096 )
          goto LABEL_34;
      }
      else
      {
        if ( a3 == 16 || a3 == 64 )
        {
          v29 = 20;
          if ( v28 == 1 )
          {
            v32 = 10;
          }
          else
          {
            if ( v28 != 3 )
            {
LABEL_34:
              v30 = a2;
              goto LABEL_39;
            }
            v32 = -10;
          }
LABEL_38:
          v30 = v32 + a2;
          goto LABEL_39;
        }
        if ( a3 != 256 )
          goto LABEL_34;
      }
      v31 = (unsigned __int8)(v28 - 6);
      if ( *(_DWORD *)(v5 + 768) == 2 )
      {
        if ( v31 >= 4 )
        {
          v29 = 40;
          v30 = a2;
          goto LABEL_39;
        }
        v32 = dword_A2FB98[(unsigned __int8)(v28 - 6)];
        v29 = 40;
      }
      else
      {
        if ( v31 >= 4 )
        {
          v29 = 20;
          v30 = a2;
          goto LABEL_39;
        }
        v32 = dword_A2FB48[(unsigned __int8)(v28 - 6)];
        v29 = 20;
      }
      goto LABEL_38;
    }
    v29 = 10;
    v30 = a2;
  }
  else
  {
    v28 = 0;
    v29 = 0;
    v30 = 0;
  }
LABEL_39:
  is_mlo_ap = policy_mgr_is_mlo_ap(*(_QWORD *)(a1 + 21552), a5);
  v152 = v30;
  v153 = v29;
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
    v30,
    v29,
    v28,
    is_mlo_ap & 1);
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v157 = 0;
  v156 = 0;
  while ( 1 )
  {
    if ( !a1 )
      goto LABEL_42;
    v45 = *(_QWORD *)(a1 + 17224);
    if ( !v45 || *(_BYTE *)(v45 + v42 + 1) != 1 || policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21552), v43) )
      goto LABEL_42;
    v46 = *(_QWORD *)(a1 + 17224);
    v47 = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), v43);
    if ( (v47 | 2) == 2 && cm_is_vdevid_connected(*(_QWORD *)(a1 + 21560), v43) )
    {
      v56 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              *(_QWORD *)(a1 + 21552),
              *(unsigned __int8 *)(v46 + v42),
              11);
      if ( v56 )
      {
        v65 = v56;
        cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v56, v57, v58, v59, v60, v61, v62, v63, v64);
        if ( cmpt_obj )
        {
          v67 = (unsigned int *)*(unsigned __int8 *)(cmpt_obj + 181);
          if ( (_DWORD)v67 == 1 )
          {
            wlan_objmgr_vdev_release_ref(v65, 0xBu, v67, v68, v69, v70, v71, v72, v73, v74, v75);
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: Skip STA vdev:%d which received CSA",
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              v83,
              "csr_check_concurrent_channel_overlap",
              *(unsigned __int8 *)(v46 + v42));
            goto LABEL_42;
          }
        }
        wlan_objmgr_vdev_release_ref(v65, 0xBu, v67, v68, v69, v70, v71, v72, v73, v74, v75);
      }
      wlan_get_op_chan_freq_info_vdev_id(
        *(_QWORD *)(a1 + 21560),
        *(_BYTE *)(v46 + v42),
        (_DWORD *)&v159 + 1,
        &v159,
        (_DWORD *)&v158 + 1);
      v103 = (unsigned int)(HIDWORD(v158) - 1) > 3 ? 10 : dword_A2FAD8[HIDWORD(v158) - 1];
      v104 = v157;
      if ( v44 )
        v104 = HIDWORD(v159);
      else
        v44 = HIDWORD(v159);
      HIDWORD(v156) = v103;
      LODWORD(v157) = v104;
      LODWORD(v150) = HIDWORD(v158);
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: %d: intf_ch:%d intf_cfreq:%d intf_hbw:%d ch_width %d",
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        "csr_check_concurrent_channel_overlap",
        (unsigned int)v43,
        v150);
    }
    else if ( (v47 & 0xFFFFFFFD) == 1 && *(_DWORD *)(v46 + v42 + 4) )
    {
      if ( (*(_BYTE *)(v46 + v42 + 60) & 1) != 0 )
        goto LABEL_42;
      v161[0] = 0;
      v84 = *(_QWORD *)(a1 + 21560);
      v160 = 0;
      wlan_get_op_chan_freq_info_vdev_id(v84, *(_BYTE *)(v46 + v42), (_DWORD *)v161 + 1, v161, &v160);
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: op_chan_freq:%d freq_seg_0:%d ch_width:%d",
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        "csr_handle_conc_chnl_overlap_for_sap_go",
        HIDWORD(v161[0]),
        LODWORD(v161[0]),
        v160);
      if ( *(_BYTE *)(v5 + 775) || *(_BYTE *)(v5 + 776) )
      {
        if ( a2 )
        {
          v93 = HIDWORD(v156);
        }
        else
        {
          v93 = HIDWORD(v156);
          if ( v47 == 1 )
          {
            a2 = HIDWORD(v161[0]);
            v152 = v161[0];
            if ( v160 - 3 < 2 )
            {
              v94 = 80;
            }
            else if ( v160 == 2 )
            {
              v94 = 40;
            }
            else if ( v160 == 1 )
            {
              v94 = 20;
            }
            else
            {
              v94 = 10;
            }
            v153 = v94;
          }
        }
      }
      else if ( a2 )
      {
        v93 = HIDWORD(v156);
        v115 = (unsigned __int8)v155 == 4 && v47 == 3;
        if ( a2 != HIDWORD(v161[0]) || v115 )
        {
          v159 = v161[0];
          if ( v160 - 3 < 2 )
          {
            v93 = 80;
          }
          else if ( v160 == 2 )
          {
            v93 = 40;
          }
          else if ( v160 == 1 )
          {
            v93 = 20;
          }
          else
          {
            v93 = 10;
          }
        }
      }
      else
      {
        v93 = HIDWORD(v156);
        v152 = v161[0];
        if ( v160 - 3 < 2 )
        {
          v118 = 80;
        }
        else if ( v160 == 2 )
        {
          v118 = 40;
        }
        else if ( v160 == 1 )
        {
          v118 = 20;
        }
        else
        {
          v118 = 10;
        }
        v153 = v118;
        a2 = HIDWORD(v161[0]);
      }
      v116 = HIDWORD(v159);
      HIDWORD(v156) = v93;
      if ( (is_mlo_ap & 1) != 0 && (unsigned __int8)a5 != v43 && !HIDWORD(v159) )
      {
        v116 = a2;
        HIDWORD(v159) = a2;
      }
      v117 = v156;
      if ( v116 )
        v117 = v116;
      LODWORD(v156) = v117;
      v105 = HIDWORD(v159);
      if ( !HIDWORD(v159) )
        goto LABEL_75;
      goto LABEL_73;
    }
    v105 = HIDWORD(v159);
    if ( !HIDWORD(v159) )
      goto LABEL_75;
LABEL_73:
    if ( (wlan_reg_get_channel_state_for_pwrmode(
            *(_QWORD *)(a1 + 21560),
            v105,
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
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        "csr_check_concurrent_channel_overlap",
        (unsigned int)v43,
        HIDWORD(v159));
LABEL_41:
      HIDWORD(v159) = 0;
      goto LABEL_42;
    }
    BYTE4(v157) += !wlan_reg_is_24ghz_ch_freq(HIDWORD(v159));
LABEL_75:
    if ( (is_mlo_ap & 1) != 0 )
      break;
    if ( HIDWORD(v159) && (policy_mgr_2_freq_always_on_same_mac(*(_QWORD *)(a1 + 21552), HIDWORD(v159), a2) & 1) != 0 )
      goto LABEL_123;
LABEL_42:
    ++v43;
    v42 += 96;
    if ( v43 == 6 )
      goto LABEL_123;
  }
  if ( !HIDWORD(v159)
    || ((policy_mgr_is_scc_with_this_vdev_id(*(_QWORD *)(a1 + 21552), v43) & 1) != 0
     || (policy_mgr_are_2_freq_on_same_mac(*(_QWORD *)(a1 + 21552), HIDWORD(v159), a2) & 1) == 0)
    && (!HIDWORD(v159)
     || HIDWORD(v159) == a2
     || (policy_mgr_2_freq_always_on_same_mac(*(_QWORD *)(a1 + 21552), HIDWORD(v159), a2) & 1) == 0) )
  {
    goto LABEL_41;
  }
LABEL_123:
  if ( (is_mlo_ap & ((unsigned __int8)(BYTE4(v157) + !wlan_reg_is_24ghz_ch_freq(a2)) > 2u)) == 1
    && (policy_mgr_is_sta_sap_scc(*(_QWORD *)(a1 + 21552), v156, 0) & 1) != 0
    && v44
    && (_DWORD)v157 )
  {
    if ( (_DWORD)v156 == v44 )
    {
      if ( v44 != (_DWORD)v157 )
        HIDWORD(v159) = v157;
    }
    else
    {
      HIDWORD(v159) = v44;
    }
  }
  v119 = HIDWORD(v159);
  is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(*(_QWORD *)(a1 + 21552));
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: intf_ch:%d sap_ch:%d cc_switch_mode:%d, dbs:%d",
    v121,
    v122,
    v123,
    v124,
    v125,
    v126,
    v127,
    v128,
    "csr_check_concurrent_channel_overlap",
    v119,
    a2,
    (unsigned __int8)v155,
    is_hw_dbs_capable & 1);
  v137 = HIDWORD(v159);
  if ( !HIDWORD(v159)
    || a2 == HIDWORD(v159)
    || (is_force_scc = policy_mgr_is_force_scc(*(_QWORD *)(a1 + 21552)), v137 = HIDWORD(v159), is_force_scc) )
  {
    v139 = v154;
    if ( v137 )
      v140 = a2 == v137;
    else
      v140 = 1;
    if ( !v140 )
      v139 = 1;
    if ( v139 == 1 )
    {
      if ( policy_mgr_is_force_scc(*(_QWORD *)(a1 + 21552)) )
      {
        ((void (__fastcall *)(_QWORD, char *, _QWORD, _QWORD, _QWORD))policy_mgr_check_scc_channel)(
          *(_QWORD *)(a1 + 21552),
          (char *)&v159 + 4,
          a2,
          (unsigned __int8)a5,
          v155);
        goto LABEL_168;
      }
      v137 = HIDWORD(v159);
    }
    if ( (unsigned __int8)v155 == 4
      && v137 == a2
      && ((unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, char *))policy_mgr_handle_go_sap_fav_channel)(
                          *(_QWORD *)(a1 + 21552),
                          a5,
                          a2,
                          (char *)&v159 + 4)
       || !HIDWORD(v159)
       || HIDWORD(v159) == a2)
      && (wlan_reg_is_24ghz_ch_freq(HIDWORD(v159)) || wlan_reg_is_6ghz_chan_freq(a2))
      && (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, char *, _QWORD))policy_mgr_get_sap_mandatory_channel)(
                         *(_QWORD *)(a1 + 21552),
                         a2,
                         (char *)&v159 + 4,
                         a5) )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: no mandatory channel",
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        v135,
        v136,
        "csr_check_concurrent_channel_overlap");
    }
  }
  else
  {
    v141 = v152 - v153;
    v142 = v152 + v153;
    v143 = v159 - HIDWORD(v156);
    v144 = v159 + HIDWORD(v156);
    LODWORD(v151) = HIDWORD(v159);
    LODWORD(v150) = v152 + v153;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: SAP:  OCH: %03d CCH: %03d BW: %d LF: %d HF: %d INTF: OCH: %03d CF: %d BW: %d LF: %d HF: %d",
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      v135,
      v136,
      "csr_check_concurrent_channel_overlap",
      a2,
      v152,
      2 * v153,
      v152 - v153,
      v150,
      v151,
      v159,
      2 * HIDWORD(v156),
      v159 - HIDWORD(v156),
      v159 + HIDWORD(v156));
    if ( (v152 - v153 <= v143 || v141 >= v144) && (v142 <= v143 || v142 >= v144) )
    {
      v145 = v141 >= v144 || v144 >= v142;
      v146 = !v145;
      v147 = v142 > v143 && v143 > v141;
      if ( !v147 && !v146 )
        HIDWORD(v159) = 0;
    }
  }
LABEL_168:
  v148 = HIDWORD(v159);
  if ( HIDWORD(v159) == a2 )
  {
    v148 = 0;
    HIDWORD(v159) = 0;
    v149 = "Not";
  }
  else if ( HIDWORD(v159) )
  {
    v149 = "Are";
  }
  else
  {
    v149 = "Not";
  }
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: ##Concurrent Channels (%d, %d) %s Interfering",
    v129,
    v130,
    v131,
    v132,
    v133,
    v134,
    v135,
    v136,
    "csr_check_concurrent_channel_overlap",
    a2,
    v148,
    v149);
  result = HIDWORD(v159);
LABEL_174:
  _ReadStatusReg(SP_EL0);
  return result;
}
