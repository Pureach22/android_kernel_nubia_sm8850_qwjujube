__int64 __fastcall hdd_sme_roam_callback(
        unsigned __int8 *a1,
        unsigned int *a2,
        int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _DWORD *v12; // x25
  unsigned int v14; // w23
  __int64 e_roam_cmd_status_str; // x24
  __int64 e_csr_roam_result_str; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 result; // x0
  __int64 v37; // x20
  __int64 v38; // x21
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  int v48; // w22
  unsigned int gfp_flags; // w0
  int v50; // w8
  unsigned int v51; // w19
  const char *v52; // x2
  const char *v53; // x3
  __int64 *v54; // x22
  int v55; // w19
  __int64 v56; // x8
  __int64 v57; // x1
  unsigned int v58; // w20
  unsigned int v59; // w21
  unsigned int v60; // w19
  __int64 v61; // x8
  _DWORD *v62; // x21
  __int64 v63; // x21
  __int64 v64; // x4
  unsigned __int8 *v65; // x22
  _DWORD *v66; // x19
  unsigned int v67; // w8
  const char *v68; // x2
  __int64 v69; // x22
  __int64 *v70; // x21
  int v71; // w8
  __int64 vdev_by_user; // x0
  __int64 v73; // x19
  char connected_vdev_by_bssid; // w0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  int v83; // w9
  int v84; // w8
  __int64 v85; // x1
  unsigned __int64 v86; // x23
  int v87; // w10
  int v88; // w22
  unsigned int v89; // w9
  unsigned __int64 v90; // x26
  __int64 v91; // x20
  __int64 v92; // x24
  unsigned int v93; // w9
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  char *v102; // x26
  __int64 v103; // x8
  __int64 v104; // x20
  __int64 v105; // x27
  char *v106; // x26
  __int64 v107; // x28
  __int64 v108; // x8
  __int64 v109; // x8
  char *v110; // x26
  const char *v111; // x2
  const char *v112; // x3
  unsigned __int16 *v113; // x8
  int v114; // w19
  int v115; // w20
  _BOOL4 v116; // w21
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  __int64 v125; // x19
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  char v134; // w8
  unsigned int v135; // w1
  unsigned __int8 *v136; // x20
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  __int64 cmpt_obj; // x0
  char v146; // w23
  __int64 v147; // x0
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  __int64 v156; // x19
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  __int64 v165; // [xsp+0h] [xbp-190h]
  __int64 v166; // [xsp+8h] [xbp-188h]
  __int64 v167; // [xsp+10h] [xbp-180h]
  __int64 v168; // [xsp+18h] [xbp-178h]
  __int64 v169; // [xsp+20h] [xbp-170h]
  __int64 v170; // [xsp+28h] [xbp-168h]
  __int64 v171; // [xsp+30h] [xbp-160h]
  __int64 v172; // [xsp+38h] [xbp-158h]
  __int64 v173; // [xsp+40h] [xbp-150h]
  __int64 v174; // [xsp+48h] [xbp-148h]
  __int64 v175; // [xsp+50h] [xbp-140h]
  __int64 v176; // [xsp+58h] [xbp-138h]
  int v177; // [xsp+68h] [xbp-128h]
  char v178[4]; // [xsp+70h] [xbp-120h] BYREF
  unsigned __int8 n; // [xsp+74h] [xbp-11Ch] BYREF
  size_t n_4; // [xsp+78h] [xbp-118h] BYREF
  __int64 v181; // [xsp+80h] [xbp-110h] BYREF
  __int64 v182; // [xsp+88h] [xbp-108h]
  __int64 v183; // [xsp+90h] [xbp-100h]
  __int64 v184; // [xsp+98h] [xbp-F8h]
  __int64 v185; // [xsp+A0h] [xbp-F0h]
  __int64 v186; // [xsp+A8h] [xbp-E8h]
  __int64 v187; // [xsp+B0h] [xbp-E0h]
  __int64 v188; // [xsp+B8h] [xbp-D8h]
  __int64 v189; // [xsp+C0h] [xbp-D0h]
  __int64 v190; // [xsp+C8h] [xbp-C8h]
  __int64 v191; // [xsp+D0h] [xbp-C0h]
  __int64 v192; // [xsp+D8h] [xbp-B8h]
  __int64 v193; // [xsp+E0h] [xbp-B0h]
  __int64 v194; // [xsp+E8h] [xbp-A8h]
  __int64 v195; // [xsp+F0h] [xbp-A0h]
  __int64 v196; // [xsp+F8h] [xbp-98h]
  __int64 v197; // [xsp+100h] [xbp-90h]
  __int64 v198; // [xsp+108h] [xbp-88h]
  __int64 v199; // [xsp+110h] [xbp-80h]
  __int64 v200; // [xsp+118h] [xbp-78h]
  __int64 v201; // [xsp+120h] [xbp-70h]
  __int64 v202; // [xsp+128h] [xbp-68h]
  __int64 v203; // [xsp+130h] [xbp-60h]
  __int64 v204; // [xsp+138h] [xbp-58h]
  __int64 v205; // [xsp+140h] [xbp-50h]
  __int64 v206; // [xsp+148h] [xbp-48h]
  __int64 v207; // [xsp+150h] [xbp-40h]
  __int64 v208; // [xsp+158h] [xbp-38h]
  __int64 v209; // [xsp+160h] [xbp-30h]
  __int64 v210; // [xsp+168h] [xbp-28h]
  __int64 v211; // [xsp+170h] [xbp-20h]
  __int64 v212; // [xsp+180h] [xbp-10h]

  v212 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_DWORD **)a1;
  if ( **(_DWORD **)a1 != 1885692259 )
  {
    v52 = "%s: Invalid adapter or adapter has invalid magic";
    v53 = "hdd_sme_roam_callback";
    goto LABEL_15;
  }
  v14 = a1[8];
  e_roam_cmd_status_str = get_e_roam_cmd_status_str((unsigned int)a3);
  e_csr_roam_result_str = get_e_csr_roam_result_str(a4);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev %d status %s(%d) result %s(%d)",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "hdd_sme_roam_callback",
    v14,
    e_roam_cmd_status_str,
    (unsigned int)a3,
    e_csr_roam_result_str,
    a4);
  qdf_trace(51, 0x4Au, a1[8], a3);
  result = 0;
  if ( a3 <= 35 )
  {
    if ( a3 > 32 )
    {
      if ( a3 != 33 )
      {
        if ( a3 == 34 )
        {
          if ( a2 && v12 )
          {
            v58 = *((unsigned __int8 *)a2 + 98);
            v59 = *((unsigned __int8 *)a2 + 99);
            v60 = *((unsigned __int16 *)a2 + 50);
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: TSM Ind tid(%d) state(%d) MeasInt(%d)",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "hdd_indicate_tsm_ie",
              v58,
              v59,
              v60);
            snprintf((char *)&n_4, 0x100u, "TSMIE=%d:%d:%d", v58, v59, v60);
          }
          goto LABEL_132;
        }
        goto LABEL_133;
      }
      if ( !a2 )
        goto LABEL_132;
      v63 = *a2;
      v64 = *((unsigned __int8 *)a2 + 4);
      v65 = *((unsigned __int8 **)a2 + 1);
      v66 = *(_DWORD **)a1;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Frame Type = %d Frame Length = %d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_indicate_unprot_mgmt_frame",
        v64,
        (unsigned int)v63);
      if ( (unsigned int)_hdd_validate_adapter(v66, "hdd_indicate_unprot_mgmt_frame") )
        goto LABEL_132;
      if ( (_DWORD)v63 )
      {
        if ( v65 )
        {
          v67 = *v65;
          if ( ((v67 >> 2) & 3) != 0 )
          {
            v68 = "%s: Unexpected frame type %d";
          }
          else
          {
            v136 = a1 + 4096;
            if ( v67 >> 4 == 12 )
            {
              cfg80211_rx_unprot_mlme_mgmt(*((_QWORD *)v66 + 4), v65, v63);
              result = 0;
              ++v136[168];
              goto LABEL_133;
            }
            if ( v67 >> 4 == 10 )
            {
              cfg80211_rx_unprot_mlme_mgmt(*((_QWORD *)v66 + 4), v65, v63);
              result = 0;
              ++v136[169];
              goto LABEL_133;
            }
            v68 = "%s: Unexpected frame subtype %d";
          }
          qdf_trace_msg(0x33u, 3u, v68, v40, v41, v42, v43, v44, v45, v46, v47, "hdd_indicate_unprot_mgmt_frame");
LABEL_132:
          result = 0;
          goto LABEL_133;
        }
        v111 = "%s: frame is NULL";
      }
      else
      {
        v111 = "%s: Frame Length is Invalid ZERO";
      }
      v112 = "hdd_indicate_unprot_mgmt_frame";
      goto LABEL_100;
    }
    if ( a3 == 14 )
    {
      v62 = *(_DWORD **)a1;
      if ( (hdd_cm_is_vdev_associated(a1) & 1) != 0 )
        cfg80211_michael_mic_failure(
          *((_QWORD *)v62 + 4),
          *((_QWORD *)a2 + 11) + 6LL,
          *(unsigned __int8 *)(*((_QWORD *)a2 + 11) + 18LL) ^ 1u,
          *(unsigned __int8 *)(*((_QWORD *)a2 + 11) + 20LL),
          *((_QWORD *)a2 + 11) + 21LL,
          3264);
      goto LABEL_132;
    }
    if ( a3 != 17 )
      goto LABEL_133;
    v54 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
    qdf_trace_msg(0x33u, 8u, "%s: enter", v28, v29, v30, v31, v32, v33, v34, v35, "hdd_roam_set_key_complete_handler");
    if ( a2 )
    {
      if ( v54 && *v54 )
      {
        LODWORD(v165) = *((unsigned __int8 *)a2 + 25);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Set Key completion roam_status =%d roam_result=%d %02x:%02x:%02x:**:**:%02x",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "hdd_roam_set_key_complete_handler",
          17,
          a4,
          *((unsigned __int8 *)a2 + 23),
          *((unsigned __int8 *)a2 + 24),
          v165,
          *((unsigned __int8 *)a2 + 28));
        if ( (hdd_cm_is_vdev_associated(a1) & 1) == 0 )
        {
LABEL_129:
          policy_mgr_restart_opportunistic_timer(*v54, 0);
          v111 = "%s: exit";
          v112 = "hdd_roam_set_key_complete_handler";
LABEL_130:
          v135 = 8;
          goto LABEL_131;
        }
        v55 = *((_DWORD *)a1 + 168);
        if ( a4 != 6
          || (v56 = *(_QWORD *)a1,
              v57 = a1[8],
              a1[686] = 1,
              (sme_neighbor_roam_is11r_assoc(*(_QWORD *)(*(_QWORD *)(v56 + 24) + 16LL), v57) & 1) != 0) )
        {
          a1[685] = 1;
        }
        if ( (unsigned int)(v55 - 1) > 3 )
        {
          if ( a1[685] != 1 )
            goto LABEL_126;
        }
        else if ( a1[686] != 1 || (a1[685] & 1) == 0 )
        {
LABEL_126:
          if ( a1[686] == 1 && a1[685] == 1 )
            *(_WORD *)(a1 + 685) = 0;
          goto LABEL_129;
        }
        v125 = *(_QWORD *)a1;
        LOBYTE(n_4) = 0;
        if ( (ucfg_ipa_is_enabled() & 1) != 0 && !a1[676] && !*(_DWORD *)(v125 + 40) && *((_DWORD *)a1 + 167) >= 3u )
        {
          if ( (unsigned int)hdd_ipa_get_tx_pipe(*(_QWORD *)(v125 + 24), a1, &n_4) )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Failed to get alternate pipe for vdev %d",
              v126,
              v127,
              v128,
              v129,
              v130,
              v131,
              v132,
              v133,
              "hdd_change_sta_state_authenticated",
              a1[8]);
            v134 = 0;
            LOBYTE(n_4) = 0;
          }
          else
          {
            v134 = n_4;
          }
          ucfg_ipa_wlan_evt(
            *(_QWORD *)(*(_QWORD *)(v125 + 24) + 8LL),
            *(_QWORD *)(v125 + 32),
            *(unsigned int *)(v125 + 40),
            a1[8],
            4,
            a1 + 300,
            v134 & 1);
        }
        hdd_cm_set_peer_authenticate(a1, a1 + 300, 0);
        goto LABEL_126;
      }
      v52 = "%s: hdd_ctx or psoc is NULL";
    }
    else
    {
      v52 = "%s: roam_info is NULL";
    }
    v53 = "hdd_roam_set_key_complete_handler";
LABEL_15:
    qdf_trace_msg(0x33u, 2u, v52, a5, a6, a7, a8, a9, a10, a11, a12, v53);
    result = 16;
    goto LABEL_133;
  }
  if ( a3 <= 41 )
  {
    if ( a3 == 36 )
    {
      if ( a2 && v12 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: CCXADJAPREP=%u",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "hdd_indicate_ese_adj_ap_rep_ind",
          *((unsigned __int16 *)a2 + 51));
        snprintf((char *)&n_4, 0x100u, "CCXADJAPREP=%u", *((unsigned __int16 *)a2 + 51));
      }
      goto LABEL_132;
    }
    if ( a3 != 37 )
      goto LABEL_133;
    n = 0;
    if ( !a2 || !v12 )
      goto LABEL_132;
    v61 = *((_QWORD *)a2 + 13);
    if ( *(unsigned __int8 *)(v61 + 2) >= 2u )
    {
      if ( !*(_BYTE *)(v61 + 3) )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Measurement Done but no scan results",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "hdd_indicate_ese_bcn_report_ind");
        v113 = *((unsigned __int16 **)a2 + 13);
        v114 = *v113;
        v115 = *((unsigned __int8 *)v113 + 3);
        v116 = *((_BYTE *)v113 + 2) != 0;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: CCXBCNREP=%d %d %d",
          v117,
          v118,
          v119,
          v120,
          v121,
          v122,
          v123,
          v124,
          "hdd_indicate_ese_bcn_report_no_results",
          *v113,
          *((_BYTE *)v113 + 2) != 0,
          *((unsigned __int8 *)v113 + 3));
        snprintf((char *)&n_4, 0x100u, "CCXBCNREP=%d %d %d", v114, v116, v115);
        goto LABEL_132;
      }
    }
    else if ( !*(_BYTE *)(v61 + 3) )
    {
      goto LABEL_132;
    }
    v86 = 0;
    v87 = 0;
    while ( 1 )
    {
      v210 = 0;
      v211 = 0;
      v88 = 0;
      v208 = 0;
      v209 = 0;
      v206 = 0;
      v207 = 0;
      v204 = 0;
      v205 = 0;
      v202 = 0;
      v203 = 0;
      v200 = 0;
      v201 = 0;
      v198 = 0;
      v199 = 0;
      v196 = 0;
      v197 = 0;
      v194 = 0;
      v195 = 0;
      v192 = 0;
      v193 = 0;
      v190 = 0;
      v191 = 0;
      v188 = 0;
      v189 = 0;
      v186 = 0;
      v187 = 0;
      v184 = 0;
      v185 = 0;
      v182 = 0;
      v183 = 0;
      n_4 = 0;
      v181 = 0;
      v89 = *(unsigned __int8 *)(v61 + 3);
      v177 = v87;
      v178[0] = 0;
      if ( v89 > (unsigned __int8)v87 )
        break;
LABEL_80:
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Sending %d BSS Info",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_indicate_ese_bcn_report_ind",
        (unsigned __int8)v88);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: CCXBCNREP=%d %d %d %d",
        v94,
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        "hdd_indicate_ese_bcn_report_ind",
        **((unsigned __int16 **)a2 + 13),
        *(unsigned __int8 *)(*((_QWORD *)a2 + 13) + 2LL),
        (unsigned __int8)v88,
        (unsigned __int8)v178[0]);
      v102 = (char *)&n_4
           + snprintf(
               (char *)&n_4,
               0x100u,
               "CCXBCNREP=%d %d %d ",
               **((unsigned __int16 **)a2 + 13),
               *(unsigned __int8 *)(*((_QWORD *)a2 + 13) + 2LL),
               (unsigned __int8)v88);
      qdf_mem_copy(v102, v178, 1u);
      if ( (_BYTE)v88 )
      {
        v103 = 8;
        if ( v86 < 8 )
          v103 = v86;
        v104 = 40 * v103 - 320;
        v105 = 0;
        v106 = v102 + 1;
        v107 = 40 * v86;
        while ( v104 + v105 )
        {
          v108 = *((_QWORD *)a2 + 13) + v107 + v105;
          LODWORD(v175) = *(unsigned __int8 *)(v108 + 18);
          LODWORD(v174) = *(unsigned __int8 *)(v108 + 17);
          LODWORD(v176) = *(unsigned __int8 *)(v108 + 19);
          LODWORD(v173) = *(unsigned __int8 *)(v108 + 16);
          LODWORD(v172) = *(unsigned __int8 *)(v108 + 15);
          LODWORD(v171) = *(unsigned __int8 *)(v108 + 14);
          LODWORD(v170) = *(unsigned __int16 *)(v108 + 34);
          LODWORD(v169) = *(unsigned __int16 *)(v108 + 32);
          LODWORD(v168) = *(_DWORD *)(v108 + 28);
          LODWORD(v167) = *(_DWORD *)(v108 + 24);
          LODWORD(v166) = *(_DWORD *)(v108 + 20);
          LODWORD(v165) = *(unsigned __int8 *)(v108 + 13);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: ChanNum(%d) Spare(%d) MeasDuration(%d) PhyType(%d) RecvSigPower(%d) ParentTSF(%u) TargetTSF[0](%u) Targe"
            "tTSF[1](%u) BeaconInterval(%u) CapabilityInfo(%d) BSSID(%02X:%02X:%02X:%02X:%02X:%02X)",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "hdd_indicate_ese_bcn_report_ind",
            *(unsigned __int8 *)(v108 + 8),
            *(unsigned __int8 *)(v108 + 9),
            *(unsigned __int16 *)(v108 + 10),
            *(unsigned __int8 *)(v108 + 12),
            v165,
            v166,
            v167,
            v168,
            v169,
            v170,
            v171,
            v172,
            v173,
            v174,
            v175,
            v176);
          v109 = *((_QWORD *)a2 + 13);
          n = 28;
          qdf_mem_copy(v106, (const void *)(v109 + v107 + v105 + 8), 0x1Cu);
          v110 = &v106[n];
          n = *(_BYTE *)(*((_QWORD *)a2 + 13) + v107 + v105 + 36);
          qdf_mem_copy(v110++, &n, 1u);
          qdf_mem_copy(v110, *(const void **)(*((_QWORD *)a2 + 13) + v107 + v105 + 40), n);
          v105 += 40;
          v106 = &v110[n];
          if ( 40LL * (unsigned __int8)v88 == v105 )
            goto LABEL_71;
        }
        goto LABEL_134;
      }
LABEL_71:
      v61 = *((_QWORD *)a2 + 13);
      v87 = v88 + v177;
      v86 = (unsigned __int8)(v88 + v177);
      if ( *(unsigned __int8 *)(v61 + 3) <= (unsigned int)(unsigned __int8)(v88 + v177) )
        goto LABEL_132;
    }
    v88 = 0;
    v90 = (unsigned __int8)v87;
    if ( (unsigned __int8)v87 <= 8u )
      v91 = 8;
    else
      v91 = (unsigned __int8)v87;
    v92 = 40LL * (unsigned __int8)v87 + 36;
    while ( v91 != v90 )
    {
      v93 = (unsigned __int8)v178[0] + (unsigned __int8)(*(_BYTE *)(v61 + v92) + 29);
      n = *(_BYTE *)(v61 + v92) + 29;
      if ( v93 <= 0xEE )
      {
        v178[0] = v93;
        ++v88;
        LODWORD(v165) = v93;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: i(%d) sizeof bcnReportFields(%d) IeLength(%d) Length of Ie(%d) totLen(%d)",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "hdd_indicate_ese_bcn_report_ind",
          (unsigned int)v90,
          28,
          1,
          *(unsigned __int8 *)(v61 + v92),
          v165);
        v61 = *((_QWORD *)a2 + 13);
        ++v90;
        v92 += 40;
        if ( v90 < *(unsigned __int8 *)(v61 + 3) )
          continue;
      }
      goto LABEL_80;
    }
LABEL_134:
    __break(0x5512u);
  }
  switch ( a3 )
  {
    case '*':
      v69 = *(_QWORD *)a1;
      if ( !*(_QWORD *)a1 )
        goto LABEL_132;
      v70 = *(__int64 **)(v69 + 24);
      if ( !v70 || !v70[2] )
        goto LABEL_132;
      v71 = *(_DWORD *)(v69 + 40);
      LOBYTE(n_4) = 0;
      if ( !v71 )
        sme_start_roaming();
      *((_DWORD *)a1 + 173) = a2[35];
      *((_DWORD *)a1 + 233) = a2[44];
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_roam_channel_switch_handler");
      if ( !vdev_by_user )
      {
        v111 = "%s: Invalid vdev";
        v112 = "hdd_roam_channel_switch_handler";
        goto LABEL_100;
      }
      v73 = vdev_by_user;
      if ( (*(_DWORD *)(v69 + 40) | 2) != 2 )
        goto LABEL_61;
      connected_vdev_by_bssid = wlan_get_connected_vdev_by_bssid(v70[1], a1 + 300, &n_4);
      v83 = (unsigned __int8)n_4;
      v84 = a1[8];
      if ( (connected_vdev_by_bssid & 1) != 0 && v84 == (unsigned __int8)n_4 )
      {
        if ( ucfg_cm_is_vdev_active(v73, v75, v76, v77, v78, v79, v80, v81, v82) )
        {
LABEL_61:
          v85 = system_wq;
          *((_DWORD *)a1 + 1111) = 1;
          queue_work_on(32, v85, a1 + 4448);
          goto LABEL_109;
        }
        v83 = (unsigned __int8)n_4;
        v84 = a1[8];
      }
      LODWORD(v165) = v84;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: BSS %02x:%02x:%02x:**:**:%02x no connected with vdev %d (%d)",
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        "hdd_roam_channel_switch_handler",
        a1[300],
        a1[301],
        a1[302],
        a1[305],
        v165,
        v83);
LABEL_109:
      if ( (unsigned int)policy_mgr_set_hw_mode_on_channel_switch(*v70, a1[8]) )
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: set hw mode change not done",
          v137,
          v138,
          v139,
          v140,
          v141,
          v142,
          v143,
          v144,
          "hdd_roam_channel_switch_handler");
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v73, v137, v138, v139, v140, v141, v142, v143, v144);
      if ( cmpt_obj )
      {
        v146 = *(_BYTE *)(cmpt_obj + 181);
        _hdd_objmgr_put_vdev_by_user(v73, 6, "hdd_roam_channel_switch_handler");
        if ( (v146 & 1) != 0 )
          goto LABEL_116;
      }
      else
      {
        _hdd_objmgr_put_vdev_by_user(v73, 6, "hdd_roam_channel_switch_handler");
      }
      policy_mgr_check_concurrent_intf_and_restart_sap(*v70, a1[1416] != 0);
LABEL_116:
      wlan_twt_concurrency_update(v70);
      if ( (*(_DWORD *)(v69 + 40) | 2) == 2 )
      {
        v147 = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_roam_channel_switch_handler");
        if ( v147 )
        {
          v156 = v147;
          if ( (unsigned int)if_mgr_deliver_event(v147, 0x13u, 0, v148, v149, v150, v151, v152, v153, v154, v155) )
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Failed to deliver CSA complete evt",
              v157,
              v158,
              v159,
              v160,
              v161,
              v162,
              v163,
              v164,
              "hdd_roam_channel_switch_handler");
          _hdd_objmgr_put_vdev_by_user(v156, 6, "hdd_roam_channel_switch_handler");
        }
      }
      goto LABEL_132;
    case '+':
      hdd_ndp_event_handler(a1, a2, 43, a4);
      goto LABEL_132;
    case '1':
      if ( !a2 )
        goto LABEL_132;
      v37 = *(_QWORD *)a1;
      v38 = *((_QWORD *)a2 + 41);
      v181 = 0;
      v182 = 0;
      v39 = *(_QWORD *)(v37 + 24);
      v187 = 0;
      v188 = 0;
      v185 = 0;
      v186 = 0;
      v183 = 0;
      v184 = 0;
      n_4 = 0;
      if ( (unsigned int)_wlan_hdd_validate_context(v39, "wlan_hdd_sae_callback") )
        goto LABEL_132;
      if ( v38 )
      {
        v48 = 1027080;
        gfp_flags = cds_get_gfp_flags();
        v50 = *(_DWORD *)(v38 + 48);
        v51 = gfp_flags;
        switch ( v50 )
        {
          case 25:
            v48 = 1027097;
            break;
          case 24:
            v48 = 1027096;
            break;
          case 9:
            v48 = 1027081;
            break;
        }
        HIDWORD(v185) = v48;
        LODWORD(n_4) = 0;
        qdf_ether_addr_copy((_WORD *)&n_4 + 2, (_WORD *)(v38 + 8));
        qdf_mem_copy((char *)&v181 + 2, (const void *)(v38 + 15), *(unsigned __int8 *)(v38 + 14));
        BYTE2(v185) = *(_BYTE *)(v38 + 14);
        cfg80211_external_auth_request(*(_QWORD *)(v37 + 32), &n_4, v51);
        v111 = "%s: SAE: sent cmd";
        v112 = "wlan_hdd_sae_callback";
        goto LABEL_130;
      }
      v111 = "%s: SAE info in NULL";
      v112 = "wlan_hdd_sae_callback";
LABEL_100:
      v135 = 2;
LABEL_131:
      qdf_trace_msg(0x33u, v135, v111, v40, v41, v42, v43, v44, v45, v46, v47, v112);
      goto LABEL_132;
  }
LABEL_133:
  _ReadStatusReg(SP_EL0);
  return result;
}
