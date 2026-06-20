__int64 __fastcall cm_get_valid_candidate(
        unsigned __int8 *a1,
        __int64 a2,
        unsigned __int8 *a3,
        char *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v14; // x8
  __int64 v15; // x0
  unsigned int v16; // w24
  __int64 v17; // x22
  _QWORD *v20; // x21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  unsigned int v30; // w24
  char v31; // w25
  int param; // w0
  int v33; // w23
  __int64 v34; // x21
  int v35; // w9
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v46; // w25
  unsigned __int64 v47; // x26
  int v48; // w10
  unsigned __int8 *v49; // x8
  __int64 v50; // x9
  __int64 v51; // x8
  __int64 v52; // x0
  __int64 v53; // x8
  unsigned int v54; // w9
  int v55; // w9
  char v56; // w8
  char v57; // w9
  __int64 v58; // x8
  __int64 v59; // x0
  unsigned int v60; // w25
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w24
  __int64 system_time; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x5
  const char *v80; // x2
  const char *v81; // x3
  unsigned int v82; // w1
  __int64 v83; // x4
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  char v92; // w28
  _QWORD *v93; // x1
  _QWORD *v94; // x26
  __int64 v95; // x0
  __int64 v96; // x8
  unsigned int v97; // w9
  int v98; // w9
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  char v107; // w8
  unsigned int v108; // w26
  __int64 v109; // x25
  int v110; // w9
  __int64 v111; // x28
  unsigned __int8 *v112; // x26
  __int64 psoc_ext_obj_fl; // x25
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  __int64 v122; // x0
  const void *v123; // x1
  __int64 v124; // x26
  __int64 scan_result; // x28
  int v126; // w8
  __int64 v127; // x7
  int v128; // w9
  int v129; // w10
  _QWORD *v130; // x1
  _QWORD *v131; // x26
  _QWORD *v132; // x27
  __int64 v133; // x1
  __int64 v134; // x1
  int v135; // t1
  bool v136; // zf
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  int v145; // w0
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  unsigned __int8 *v154; // x9
  __int64 v155; // x5
  int v156; // w8
  __int64 v157; // x6
  __int64 v158; // x7
  int v159; // w9
  unsigned __int8 *v160; // x9
  __int64 v161; // x6
  __int64 v162; // x7
  int v163; // w8
  int v164; // w9
  __int64 v165; // x6
  __int64 v166; // x7
  int v167; // w9
  __int64 v168; // [xsp+0h] [xbp-130h]
  __int64 v169; // [xsp+8h] [xbp-128h]
  __int64 v170; // [xsp+10h] [xbp-120h]
  __int64 v171; // [xsp+18h] [xbp-118h]
  int v172; // [xsp+18h] [xbp-118h]
  unsigned __int8 *v173; // [xsp+40h] [xbp-F0h]
  const void *v174; // [xsp+48h] [xbp-E8h]
  int v175; // [xsp+54h] [xbp-DCh]
  _QWORD *v176; // [xsp+58h] [xbp-D8h] BYREF
  _QWORD *v177; // [xsp+60h] [xbp-D0h] BYREF
  _QWORD *v178; // [xsp+68h] [xbp-C8h] BYREF
  _QWORD *v179; // [xsp+70h] [xbp-C0h] BYREF
  unsigned int v180[3]; // [xsp+7Ch] [xbp-B4h] BYREF
  _QWORD *v181; // [xsp+88h] [xbp-A8h] BYREF
  __int64 v182; // [xsp+90h] [xbp-A0h]
  __int64 v183; // [xsp+98h] [xbp-98h]
  __int64 v184; // [xsp+A0h] [xbp-90h]
  __int64 v185; // [xsp+A8h] [xbp-88h]
  __int64 v186; // [xsp+B0h] [xbp-80h]
  __int64 v187; // [xsp+B8h] [xbp-78h]
  __int64 v188; // [xsp+C0h] [xbp-70h]
  __int64 v189; // [xsp+C8h] [xbp-68h]
  __int64 v190; // [xsp+D0h] [xbp-60h]
  __int64 v191; // [xsp+D8h] [xbp-58h]
  __int64 v192; // [xsp+E0h] [xbp-50h]
  __int64 v193; // [xsp+E8h] [xbp-48h]
  __int64 v194; // [xsp+F0h] [xbp-40h]
  __int64 v195; // [xsp+F8h] [xbp-38h]
  __int64 v196; // [xsp+100h] [xbp-30h]
  __int64 v197; // [xsp+108h] [xbp-28h]
  __int64 v198; // [xsp+110h] [xbp-20h]
  __int64 v199; // [xsp+118h] [xbp-18h]
  __int64 v200; // [xsp+120h] [xbp-10h]

  v200 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)a1;
  v176 = nullptr;
  v177 = nullptr;
  v15 = *(_QWORD *)(v14 + 152);
  v16 = *(unsigned __int8 *)(v14 + 104);
  if ( !v15 || (v17 = *(_QWORD *)(v15 + 80)) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: Failed to find psoc",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "cm_get_valid_candidate",
      *(unsigned __int8 *)(v14 + 104),
      *(unsigned int *)(a2 + 16));
    v30 = 16;
    goto LABEL_19;
  }
  v20 = *(_QWORD **)(a2 + 864);
  LOBYTE(v181) = *(_BYTE *)(v14 + 104);
  *(_WORD *)((char *)&v181 + 1) = -1;
  wlan_objmgr_pdev_iterate_obj_list(
    v15,
    2,
    (void (__fastcall *)(__int64, __int64, __int64))cm_get_vdev_id_with_active_vdev_op,
    (__int64)&v181,
    0,
    0x4Du);
  if ( BYTE2(v181) != 255 )
  {
    v29 = "%s: vdev %d cm_id 0x%x: Abort connection as sta/cli vdev %d is disconnecting";
    goto LABEL_9;
  }
  if ( *(_QWORD *)(a2 + 864) && BYTE1(v181) != 255 )
  {
    v29 = "%s: vdev %d cm_id 0x%x: Avoid next candidate as SAP/GO/NDI vdev %d has pending vdev op";
LABEL_9:
    qdf_trace_msg(
      0x68u,
      4u,
      v29,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "cm_is_any_other_vdev_connecting_disconnecting",
      v16,
      *(unsigned int *)(a2 + 16));
LABEL_10:
    v31 = 0;
    goto LABEL_11;
  }
  if ( *(unsigned __int8 *)(a2 + 873) >= (unsigned int)a1[192] )
  {
    qdf_trace_msg(
      0x68u,
      4u,
      "%s: vdev %d cm_id 0x%x: %d attempts tried, max %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "cm_get_valid_candidate",
      v16,
      *(unsigned int *)(a2 + 16));
    goto LABEL_10;
  }
  if ( *(_BYTE *)(a2 + 873) )
  {
    v46 = *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL);
    v47 = qdf_mc_timer_get_system_time() - *(_QWORD *)(a2 + 880);
    if ( v47 >> 3 >= 0xC35 )
    {
      v69 = *(_DWORD *)(a2 + 24);
      system_time = qdf_mc_timer_get_system_time();
      qdf_trace_msg(
        0x68u,
        4u,
        "%s: vdev %d cm_id 0x%x: Max time allocated (%d ms) for connect completed, cur time %lu, active time %lu and diff %lu",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        "cm_is_time_allowed_for_connect_attempt",
        v46,
        v69,
        25000,
        system_time,
        *(_QWORD *)(a2 + 880),
        v47);
      goto LABEL_10;
    }
  }
  if ( a3 && v20 )
  {
    v48 = *((_DWORD *)a3 + 15);
    v49 = a3;
    v50 = *(_QWORD *)(*(_QWORD *)(a2 + 864) + 24LL);
    LOBYTE(v179) = 1;
    v175 = *(_DWORD *)(v50 + 1140);
    if ( v48 == 30 || v48 == 53 )
      goto LABEL_27;
    v108 = *(_DWORD *)(v50 + 1064);
    v109 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 152LL) + 80LL);
    if ( (v175 & 0x18000C00) != 0 )
    {
      wlan_mlme_get_sae_assoc_retry_count(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 152LL) + 80LL), &v179);
      v49 = a3;
    }
    v110 = *((_DWORD *)v49 + 14);
    if ( v110 == 10 )
    {
      if ( (v175 & 0x18000C00) != 0 || (mlme_get_reconn_after_assoc_timeout_flag(v109, *v49) & 1) != 0 )
        goto LABEL_27;
    }
    else if ( v110 == 6
           && (*(_DWORD *)(*(_QWORD *)(a2 + 848) + 16LL) == 1 || *(_DWORD *)(a2 + 856) == 1)
           && (policy_mgr_will_freq_lead_to_mcc(v109, v108) & 1) == 0 )
    {
      v111 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
      v112 = *(unsigned __int8 **)(*(_QWORD *)(a2 + 864) + 24LL);
      psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(v109, "cm_increase_retry_by_scan_age", 988);
      if ( psoc_ext_obj_fl )
      {
        v122 = _qdf_mem_malloc(0x2D0u, "cm_increase_retry_by_scan_age", 995);
        if ( !v122 )
          goto LABEL_86;
        v173 = v112;
        v123 = v112 + 1;
        *(_BYTE *)(v122 + 16) = 1;
        v124 = v122;
        v174 = v123;
        qdf_mem_copy((void *)(v122 + 70), v123, 6u);
        *(_QWORD *)(v124 + 8) = *(unsigned int *)(psoc_ext_obj_fl + 3468);
        scan_result = scm_get_scan_result(v111, v124);
        _qdf_mem_free(v124);
        if ( scan_result )
        {
          if ( *(_DWORD *)(scan_result + 16) )
          {
            v126 = (int)v174;
            if ( v174 )
            {
              v127 = v173[1];
              v126 = v173[2];
              v128 = v173[3];
              v129 = v173[6];
            }
            else
            {
              v128 = 0;
              v127 = 0;
              v129 = 0;
            }
            v172 = *(_DWORD *)(psoc_ext_obj_fl + 3468);
            LOBYTE(psoc_ext_obj_fl) = 2;
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: vdev %d cm_id 0x%x:  increase try num %d,%02x:%02x:%02x:**:**:%02x age < %d ms",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              "cm_increase_retry_by_scan_age",
              *a3,
              *((unsigned int *)a3 + 1),
              2,
              v127,
              v126,
              v128,
              v129,
              v172);
          }
          else
          {
            LOBYTE(psoc_ext_obj_fl) = 0;
          }
          scm_purge_scan_results(scan_result);
        }
        else
        {
LABEL_86:
          LOBYTE(psoc_ext_obj_fl) = 0;
        }
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev %d cm_id 0x%x:  psoc mlme obj is NULL ",
          v114,
          v115,
          v116,
          v117,
          v118,
          v119,
          v120,
          v121,
          "cm_increase_retry_by_scan_age",
          *a3,
          *((unsigned int *)a3 + 1));
      }
      LOBYTE(v179) = (_BYTE)v179 + psoc_ext_obj_fl;
LABEL_27:
      if ( *(unsigned __int8 *)(a2 + 872) < (unsigned int)(unsigned __int8)v179 )
      {
        v51 = *(_QWORD *)(a2 + 864);
        v181 = nullptr;
        v182 = 0;
        v52 = *(_QWORD *)a1;
        v53 = *(_QWORD *)(v51 + 24);
        v185 = 0;
        v186 = 0;
        v54 = *(_DWORD *)(v53 + 1064);
        v184 = v53;
        v183 = v54;
        WORD2(v183) = *(_WORD *)(v53 + 68);
        v55 = *(_DWORD *)(v53 + 1);
        LOWORD(v53) = *(_WORD *)(v53 + 5);
        LODWORD(v182) = v55;
        WORD2(v182) = v53;
        if ( !(unsigned int)if_mgr_deliver_event(v52, 4u, (__int64)&v181, v21, v22, v23, v24, v25, v26, v27, v28) )
        {
          LODWORD(v171) = *((_DWORD *)a3 + 14);
          LODWORD(v170) = *((_DWORD *)a3 + 15);
          LODWORD(v169) = a3[13];
          LODWORD(v168) = a3[10];
          qdf_trace_msg(
            0x68u,
            4u,
            "%s: vdev %d cm_id 0x%x: Retry again with %02x:%02x:%02x:**:**:%02x, status code %d reason %d key_mgmt 0x%x r"
            "etry count %d max retry %d",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "cm_is_retry_with_same_candidate",
            *a3,
            *((unsigned int *)a3 + 1),
            a3[8],
            a3[9],
            v168,
            v169,
            v170,
            v171,
            v175,
            *(unsigned __int8 *)(a2 + 872),
            (unsigned __int8)v179);
          v56 = *(_BYTE *)(a2 + 872);
          v57 = *(_BYTE *)(a2 + 873);
          v30 = 0;
          *(_QWORD *)(a2 + 864) = v20;
          v31 = 1;
          *(_BYTE *)(a2 + 872) = v56 + 1;
          *(_BYTE *)(a2 + 873) = v57 + 1;
          goto LABEL_12;
        }
      }
    }
  }
  else if ( !v20 )
  {
    qdf_list_peek_front(*(_QWORD **)(a2 + 848), &v177);
    goto LABEL_47;
  }
  v58 = *(_QWORD *)a1;
  v180[0] = 0;
  v181 = nullptr;
  v59 = *(_QWORD *)(v58 + 152);
  v60 = *(unsigned __int8 *)(v58 + 104);
  v178 = nullptr;
  v179 = nullptr;
  if ( !v59 )
  {
    v79 = *(unsigned int *)(a2 + 24);
    v80 = "%s: vdev %d cm_id 0x%x: Failed to find pdev";
    v81 = "cm_update_candidate_list";
    v82 = 2;
    v83 = v60;
    goto LABEL_45;
  }
  if ( (unsigned int)cm_connect_fetch_candidates(v59, a1, a2 + 24, &v181, v180) )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d cm_id 0x%x: failed to fetch bss: %d",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "cm_update_candidate_list",
      v60,
      *(unsigned int *)(a2 + 24),
      v180[0]);
LABEL_40:
    v92 = 0;
    goto LABEL_41;
  }
  if ( (unsigned int)qdf_list_peek_front(v181, &v179) )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: failed to peer front of candidate_list",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "cm_update_candidate_list",
      v60,
      *(unsigned int *)(a2 + 24));
    goto LABEL_40;
  }
  v130 = v179;
  if ( !v179 )
    goto LABEL_40;
  v92 = 0;
  v131 = v20;
  while ( 1 )
  {
    qdf_list_peek_next(v181, v130, &v178);
    v132 = v179;
    v133 = v179[3];
    v135 = *(_DWORD *)(v133 + 1);
    v134 = v133 + 1;
    if ( !(v135 | *(unsigned __int16 *)(v134 + 4))
      || (*(_DWORD *)v134 == -1 ? (v136 = *(__int16 *)(v134 + 4) == -1) : (v136 = 0),
          v136 || (cm_find_bss_from_candidate_list(*(_QWORD *)(a2 + 848)) & 1) != 0) )
    {
      v132 = v131;
      goto LABEL_70;
    }
    if ( (unsigned int)qdf_list_remove_node((__int64)v181, v179) )
      break;
    v145 = qdf_list_insert_after(*(_QWORD *)(a2 + 848), v132, v131);
    v154 = (unsigned __int8 *)v132[3];
    v155 = *(unsigned int *)(a2 + 24);
    v156 = (_DWORD)v154 + 1;
    if ( v145 )
    {
      if ( v154 == (unsigned __int8 *)-1LL )
      {
        v165 = 0;
        v166 = 0;
        v167 = 0;
      }
      else
      {
        v165 = v154[1];
        v166 = v154[2];
        v156 = v154[3];
        v167 = v154[6];
      }
      LODWORD(v169) = v167;
      LODWORD(v168) = v156;
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d cm_id 0x%x: failed to insert node for %02x:%02x:%02x:**:**:%02x to candidate list",
        v146,
        v147,
        v148,
        v149,
        v150,
        v151,
        v152,
        v153,
        "cm_update_candidate_list",
        v60,
        v155,
        v165,
        v166,
        v168,
        v169);
      util_scan_free_cache_entry_0(v132[3]);
      _qdf_mem_free((__int64)v132);
      goto LABEL_41;
    }
    if ( v154 == (unsigned __int8 *)-1LL )
    {
      v157 = 0;
      v158 = 0;
      v159 = 0;
    }
    else
    {
      v157 = v154[1];
      v158 = v154[2];
      v156 = v154[3];
      v159 = v154[6];
    }
    LODWORD(v169) = v159;
    LODWORD(v168) = v156;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d cm_id 0x%x: insert new node %02x:%02x:%02x:**:**:%02x to candidate list",
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      v152,
      v153,
      "cm_update_candidate_list",
      v60,
      v155,
      v157,
      v158,
      v168,
      v169);
    v92 = 1;
LABEL_70:
    v130 = v178;
    v131 = v132;
    v178 = nullptr;
    v179 = v130;
    if ( !v130 )
      goto LABEL_41;
  }
  v160 = (unsigned __int8 *)v132[3];
  if ( v160 == (unsigned __int8 *)-1LL )
  {
    v163 = 0;
    v161 = 0;
    v162 = 0;
    v164 = 0;
  }
  else
  {
    v161 = v160[1];
    v162 = v160[2];
    v163 = v160[3];
    v164 = v160[6];
  }
  LODWORD(v169) = v164;
  LODWORD(v168) = v163;
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: vdev %d cm_id 0x%x: failed to remove node for %02x:%02x:%02x:**:**:%02x from candidate list",
    v137,
    v138,
    v139,
    v140,
    v141,
    v142,
    v143,
    v144,
    "cm_update_candidate_list",
    v60,
    *(unsigned int *)(a2 + 24),
    v161,
    v162,
    v168,
    v169);
LABEL_41:
  if ( v181 )
    scm_purge_scan_results(v181);
  if ( (v92 & 1) != 0 )
  {
    v79 = *(unsigned int *)(a2 + 16);
    v80 = "%s: vdev %d cm_id 0x%x: dump updated candidate list";
    v81 = "cm_get_valid_candidate";
    v82 = 8;
    v83 = v16;
LABEL_45:
    qdf_trace_msg(0x68u, v82, v80, v21, v22, v23, v24, v25, v26, v27, v28, v81, v83, v79);
  }
  qdf_list_peek_next(*(_QWORD **)(a2 + 848), v20, &v177);
LABEL_47:
  v93 = v177;
  if ( v177 )
  {
    while ( 1 )
    {
      qdf_list_peek_next(*(_QWORD **)(a2 + 848), v93, &v176);
      v94 = v177;
      v181 = nullptr;
      v182 = 0;
      v95 = *(_QWORD *)a1;
      v96 = v177[3];
      v185 = 0;
      v186 = 0;
      v97 = *(_DWORD *)(v96 + 1064);
      v184 = v96;
      v183 = v97;
      WORD2(v183) = *(_WORD *)(v96 + 68);
      v98 = *(_DWORD *)(v96 + 1);
      LOWORD(v96) = *(_WORD *)(v96 + 5);
      LODWORD(v182) = v98;
      WORD2(v182) = v96;
      if ( !(unsigned int)if_mgr_deliver_event(v95, 4u, (__int64)&v181, v99, v100, v101, v102, v103, v104, v105, v106) )
        break;
      cm_store_n_send_failed_candidate(a1, *(unsigned int *)(a2 + 16));
      v93 = v176;
      v176 = nullptr;
      v177 = v93;
      if ( !v93 )
        goto LABEL_53;
    }
    if ( v177 )
    {
      v107 = *(_BYTE *)(a2 + 873);
      v30 = 0;
      v31 = 0;
      *(_BYTE *)(a2 + 872) = 0;
      *(_QWORD *)(a2 + 864) = v94;
      *(_BYTE *)(a2 + 873) = v107 + 1;
      goto LABEL_12;
    }
  }
LABEL_53:
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d cm_id 0x%x: No more candidates left",
    v84,
    v85,
    v86,
    v87,
    v88,
    v89,
    v90,
    v91,
    "cm_get_valid_candidate",
    v16,
    *(unsigned int *)(a2 + 16));
  v31 = 0;
  *(_QWORD *)(a2 + 864) = 0;
LABEL_11:
  v30 = 16;
LABEL_12:
  param = wlan_crypto_get_param(*(_QWORD *)a1, 7u);
  if ( v20 )
  {
    if ( (v31 & 1) == 0 )
    {
      v33 = param;
      if ( (util_scan_entry_single_pmk(v17, v20[3]) & 1) != 0 && (v33 & 0x8000400) != 0 )
      {
        v34 = v20[3];
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
        v181 = nullptr;
        qdf_mem_set(&v181, 0x98u, 0);
        v35 = *(_DWORD *)(v34 + 1);
        v36 = *(_QWORD *)a1;
        WORD2(v181) = *(_WORD *)(v34 + 5);
        LODWORD(v181) = v35;
        wlan_crypto_set_del_pmksa(v36, (__int64)&v181, 0, v37, v38, v39, v40, v41, v42, v43, v44);
      }
    }
  }
  if ( a4 )
    *a4 = v31;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return v30;
}
