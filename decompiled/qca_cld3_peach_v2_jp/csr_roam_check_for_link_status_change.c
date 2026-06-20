__int64 __fastcall csr_roam_check_for_link_status_change(
        __int64 result,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x19
  const char *v12; // x2
  const char *v13; // x3
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  unsigned int v23; // w20
  __int64 v24; // x8
  void (__fastcall *v25)(__int64, __int64, __int64, __int64, __int64); // x8
  __int64 v26; // x0
  __int64 v27; // x1
  __int64 v28; // x2
  __int64 v29; // x3
  __int64 v30; // x4
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int16 v39; // w9
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w22
  __int64 v50; // x4
  __int64 v51; // x8
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int v60; // w21
  __int64 v61; // x8
  int *v62; // x22
  __int64 v63; // x23
  int v64; // w8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  int v73; // w9
  __int64 v74; // x8
  _DWORD *v75; // x8
  __int64 v76; // x0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x8
  int opmode_from_vdev_id; // w8
  int v87; // w9
  __int64 v88; // x8
  __int16 v89; // w9
  __int64 v90; // x0
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  unsigned int v99; // w23
  unsigned int v100; // w22
  unsigned int v101; // w20
  __int64 v102; // x8
  _DWORD *v103; // x8
  __int64 v104; // x0
  unsigned __int16 v105; // w9
  __int64 v106; // x0
  unsigned int v107; // w21
  unsigned int v108; // w22
  __int64 v109; // x19
  void (__fastcall *v110)(__int128 *, __int64); // x8
  __int64 v111; // x10
  __int64 v112; // x11
  __int64 v113; // x1
  unsigned int v114; // w21
  __int64 v115; // x8
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  __int64 v124; // x22
  int v125; // w9
  _DWORD *command_buffer; // x0
  __int64 v127; // x8
  _DWORD *v128; // x22
  unsigned int v129; // w8
  int v130; // w9
  _DWORD *v131; // x21
  __int64 v132; // x8
  int v133; // w27
  unsigned __int16 v134; // w9
  __int64 v135; // x0
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  __int16 v152; // w8
  int v153; // w9
  __int64 v154; // x8
  __int64 v155; // x5
  __int64 v156; // x6
  const char *v157; // x2
  __int64 v158; // x7
  int v159; // w8
  const char *v160; // x3
  __int64 v161; // x0
  unsigned __int16 v162; // w9
  double v163; // d0
  double v164; // d1
  double v165; // d2
  double v166; // d3
  double v167; // d4
  double v168; // d5
  double v169; // d6
  double v170; // d7
  unsigned int v171; // w22
  unsigned int v172; // w23
  int v173; // w26
  __int64 v174; // x8
  char v175; // w9
  char v176; // w9
  double v177; // d0
  double v178; // d1
  double v179; // d2
  double v180; // d3
  double v181; // d4
  double v182; // d5
  double v183; // d6
  double v184; // d7
  char v185; // w8
  __int64 v186; // x9
  __int64 v187; // x0
  double v188; // d0
  double v189; // d1
  double v190; // d2
  double v191; // d3
  double v192; // d4
  double v193; // d5
  double v194; // d6
  double v195; // d7
  __int64 v196; // x23
  int v197; // w8
  void *v198; // x0
  __int64 v199; // x8
  _DWORD *v200; // x8
  __int64 v201; // x0
  __int64 v202; // x0
  _QWORD *v203; // x22
  __int64 v204; // x8
  _DWORD *v205; // x8
  __int64 v206; // x0
  const char *v207; // x3
  int v208; // w9
  int v209; // w9
  __int128 v210; // [xsp+20h] [xbp-20h] BYREF
  __int64 v211; // [xsp+30h] [xbp-10h]
  __int64 v212; // [xsp+38h] [xbp-8h]

  v212 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v12 = "%s: pSirMsg is NULL";
    v13 = "csr_roam_check_for_link_status_change";
LABEL_5:
    result = qdf_trace_msg(0x34u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, v13);
    goto LABEL_198;
  }
  v11 = result;
  switch ( *a2 )
  {
    case 0x1405u:
      result = csr_roam_chk_lnk_set_ctx_rsp(result, a2);
      goto LABEL_198;
    case 0x1406u:
    case 0x1407u:
    case 0x1408u:
    case 0x140Bu:
    case 0x140Cu:
    case 0x1410u:
    case 0x1411u:
    case 0x1412u:
    case 0x1413u:
    case 0x1414u:
    case 0x1416u:
    case 0x1418u:
    case 0x1419u:
    case 0x141Au:
    case 0x141Cu:
    case 0x141Du:
    case 0x141Eu:
    case 0x141Fu:
    case 0x1420u:
    case 0x1421u:
    case 0x1422u:
    case 0x1423u:
    case 0x1426u:
    case 0x1427u:
    case 0x1428u:
    case 0x142Au:
    case 0x142Bu:
    case 0x142Cu:
    case 0x142Du:
    case 0x142Eu:
    case 0x142Fu:
    case 0x1430u:
    case 0x1431u:
    case 0x1432u:
    case 0x1433u:
    case 0x1434u:
    case 0x1435u:
    case 0x1436u:
    case 0x1437u:
    case 0x1438u:
    case 0x143Au:
    case 0x143Bu:
    case 0x143Cu:
    case 0x143Du:
    case 0x143Eu:
    case 0x143Fu:
    case 0x1440u:
    case 0x1441u:
    case 0x1442u:
    case 0x1443u:
    case 0x1444u:
    case 0x1445u:
    case 0x1446u:
    case 0x1447u:
    case 0x1448u:
    case 0x1449u:
    case 0x144Au:
    case 0x144Bu:
    case 0x144Cu:
    case 0x144Du:
    case 0x144Eu:
    case 0x144Fu:
    case 0x1450u:
      goto LABEL_198;
    case 0x1409u:
      result = _qdf_mem_malloc(0x180u, "csr_roam_chk_lnk_disassoc_rsp", 4433);
      if ( result )
      {
        if ( !v11 )
          goto LABEL_197;
        v60 = *((unsigned __int8 *)a2 + 4);
        if ( v60 > 5 )
          goto LABEL_197;
        v85 = *(_QWORD *)(v11 + 17224);
        if ( !v85 )
          goto LABEL_197;
        if ( *(_BYTE *)(v85 + 96LL * *((unsigned __int8 *)a2 + 4) + 1) != 1 )
          goto LABEL_197;
        v62 = (int *)(a2 + 6);
        v63 = result;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Vdev %d, peer %02x:%02x:%02x:**:**:%02x status code %d",
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          "csr_roam_chk_lnk_disassoc_rsp",
          *((unsigned __int8 *)a2 + 4),
          *((unsigned __int8 *)a2 + 12),
          *((unsigned __int8 *)a2 + 13),
          *((unsigned __int8 *)a2 + 14),
          *((unsigned __int8 *)a2 + 17),
          *((_DWORD *)a2 + 2));
        opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(v11 + 21560), v60);
        result = v63;
        if ( (opmode_from_vdev_id & 0xFFFFFFFD) != 1 )
          goto LABEL_197;
        v87 = *v62;
        *(_WORD *)(v63 + 27) = a2[8];
        *(_DWORD *)(v63 + 23) = v87;
        *(_DWORD *)(v63 + 36) = 2;
        *(_DWORD *)(v63 + 32) = *((_DWORD *)a2 + 2);
        v88 = *(_QWORD *)(v11 + 17224);
        if ( !v88 || (*(_BYTE *)(v88 + 96LL * v60 + 1) & 1) == 0 )
          goto LABEL_147;
        goto LABEL_33;
      }
      goto LABEL_198;
    case 0x140Au:
      v114 = *((unsigned __int8 *)a2 + 4);
      if ( !result
        || v114 > 5
        || (v115 = *(_QWORD *)(result + 17224)) == 0
        || (*(_BYTE *)(v115 + 96LL * *((unsigned __int8 *)a2 + 4) + 1) & 1) == 0 )
      {
        v155 = *((unsigned __int8 *)a2 + 12);
        v156 = *((unsigned __int8 *)a2 + 13);
        v157 = "%s: vdev:%d Invalid session. BSSID: %02x:%02x:%02x:**:**:%02x";
        v158 = *((unsigned __int8 *)a2 + 14);
        v159 = *((unsigned __int8 *)a2 + 17);
        v160 = "csr_roam_chk_lnk_disassoc_ind";
        goto LABEL_116;
      }
      result = csr_if_peer_present(result, a2 + 6, a2 + 9);
      if ( (result & 1) != 0 )
      {
        result = csr_is_deauth_disassoc_cmd_active(
                   v11,
                   v114,
                   *(unsigned int *)(a2 + 9) | ((unsigned __int64)a2[11] << 32),
                   a2 + 9,
                   a2 + 12);
        if ( (result & 1) == 0 )
        {
          v124 = *(_QWORD *)(v11 + 17224) + 96LL * v114;
          if ( !v124 )
          {
            v207 = "csr_roam_chk_lnk_disassoc_ind";
            goto LABEL_185;
          }
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Vdev %d, peer %02x:%02x:%02x:**:**:%02x reason: %d status: %d",
            v116,
            v117,
            v118,
            v119,
            v120,
            v121,
            v122,
            v123,
            "csr_roam_chk_lnk_disassoc_ind",
            v114,
            *((unsigned __int8 *)a2 + 18),
            *((unsigned __int8 *)a2 + 19),
            *((unsigned __int8 *)a2 + 20),
            *((unsigned __int8 *)a2 + 23),
            *((_DWORD *)a2 + 8),
            *((_DWORD *)a2 + 2));
          v125 = *(_DWORD *)(v124 + 72) + 1;
          ++*(_DWORD *)(v124 + 64);
          *(_DWORD *)(v124 + 72) = v125;
          command_buffer = (_DWORD *)sme_get_command_buffer(v11);
          if ( !command_buffer )
            goto LABEL_181;
          ++*(_DWORD *)(v11 + 17220);
          command_buffer[4] = 65538;
          command_buffer[6] = v114;
          command_buffer[8] = 0;
          goto LABEL_97;
        }
      }
      goto LABEL_198;
    case 0x140Du:
      result = _qdf_mem_malloc(0x180u, "csr_roam_chk_lnk_deauth_rsp", 4391);
      if ( result )
      {
        if ( v11 )
        {
          v60 = *((unsigned __int8 *)a2 + 4);
          if ( v60 <= 5 )
          {
            v61 = *(_QWORD *)(v11 + 17224);
            if ( v61 )
            {
              if ( *(_BYTE *)(v61 + 96LL * *((unsigned __int8 *)a2 + 4) + 1) == 1 )
              {
                v62 = (int *)(a2 + 6);
                v63 = result;
                qdf_trace_msg(
                  0x34u,
                  8u,
                  "%s: Vdev %d, peer %02x:%02x:%02x:**:**:%02x status code %d",
                  v52,
                  v53,
                  v54,
                  v55,
                  v56,
                  v57,
                  v58,
                  v59,
                  "csr_roam_chk_lnk_deauth_rsp",
                  *((unsigned __int8 *)a2 + 4),
                  *((unsigned __int8 *)a2 + 12),
                  *((unsigned __int8 *)a2 + 13),
                  *((unsigned __int8 *)a2 + 14),
                  *((unsigned __int8 *)a2 + 17),
                  *((_DWORD *)a2 + 2));
                v64 = wlan_get_opmode_from_vdev_id(*(_QWORD *)(v11 + 21560), v60);
                result = v63;
                if ( (v64 & 0xFFFFFFFD) == 1 )
                {
                  v73 = *v62;
                  *(_WORD *)(v63 + 27) = a2[8];
                  *(_DWORD *)(v63 + 23) = v73;
                  *(_DWORD *)(v63 + 36) = 2;
                  *(_DWORD *)(v63 + 32) = *((_DWORD *)a2 + 2);
                  v74 = *(_QWORD *)(v11 + 17224);
                  if ( v74 && (*(_BYTE *)(v74 + 96LL * v60 + 1) & 1) != 0 )
                  {
LABEL_33:
                    wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(v11 + 21560), v60);
                    v75 = *(_DWORD **)(v11 + 21968);
                    if ( v75 )
                    {
                      v76 = *(_QWORD *)(v11 + 21552);
                      if ( *(v75 - 1) != 1469140685 )
                        __break(0x8228u);
                      ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64))v75)(v76, v60, v63, 12, 2);
                    }
                  }
                  else
                  {
LABEL_147:
                    qdf_trace_msg(
                      0x34u,
                      2u,
                      "%s: Session ID: %d is not valid",
                      v65,
                      v66,
                      v67,
                      v68,
                      v69,
                      v70,
                      v71,
                      v72,
                      "csr_roam_call_callback",
                      v60);
                  }
                  csr_rel_wm_status_cng_cmd(v11, v60, v62, *a2);
                  result = v63;
                }
              }
            }
          }
        }
        goto LABEL_197;
      }
      goto LABEL_198;
    case 0x140Eu:
      v114 = *((unsigned __int8 *)a2 + 4);
      if ( !result
        || v114 > 5
        || (v127 = *(_QWORD *)(result + 17224)) == 0
        || (*(_BYTE *)(v127 + 96LL * *((unsigned __int8 *)a2 + 4) + 1) & 1) == 0 )
      {
        v155 = *((unsigned __int8 *)a2 + 12);
        v156 = *((unsigned __int8 *)a2 + 13);
        v157 = "%s: vdev %d: Invalid session BSSID: %02x:%02x:%02x:**:**:%02x";
        v158 = *((unsigned __int8 *)a2 + 14);
        v159 = *((unsigned __int8 *)a2 + 17);
        v160 = "csr_roam_chk_lnk_deauth_ind";
LABEL_116:
        result = qdf_trace_msg(0x34u, 2u, v157, a3, a4, a5, a6, a7, a8, a9, a10, v160, v114, v155, v156, v158, v159);
        goto LABEL_198;
      }
      result = csr_if_peer_present(result, a2 + 6, a2 + 9);
      if ( (result & 1) == 0 )
        goto LABEL_198;
      result = csr_is_deauth_disassoc_cmd_active(
                 v11,
                 v114,
                 *(unsigned int *)(a2 + 9) | ((unsigned __int64)a2[11] << 32),
                 a2 + 9,
                 a2 + 12);
      if ( (result & 1) != 0 )
        goto LABEL_198;
      v128 = (_DWORD *)(*(_QWORD *)(v11 + 17224) + 96LL * v114);
      if ( !v128 )
      {
        v207 = "csr_roam_chk_lnk_deauth_ind";
LABEL_185:
        result = qdf_trace_msg(
                   0x34u,
                   2u,
                   "%s: vdev %d session not found",
                   v116,
                   v117,
                   v118,
                   v119,
                   v120,
                   v121,
                   v122,
                   v123,
                   v207,
                   v114);
        goto LABEL_198;
      }
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: vdev %d bssid %02x:%02x:%02x:**:**:%02x reason: %d status: %d",
        v116,
        v117,
        v118,
        v119,
        v120,
        v121,
        v122,
        v123,
        "csr_roam_chk_lnk_deauth_ind",
        *((unsigned __int8 *)a2 + 4),
        *((unsigned __int8 *)a2 + 12),
        *((unsigned __int8 *)a2 + 13),
        *((unsigned __int8 *)a2 + 14),
        *((unsigned __int8 *)a2 + 17),
        *((_DWORD *)a2 + 8),
        *((_DWORD *)a2 + 2));
      v129 = *((_DWORD *)a2 + 8);
      if ( v129 > 9 )
        goto LABEL_201;
      if ( ((1 << v129) & 0x2CE) != 0 )
      {
        v130 = v128[19] + 1;
        ++v128[16];
        v128[19] = v130;
      }
      else if ( v129 == 4 )
      {
        v208 = v128[21] + 1;
        ++v128[16];
        v128[21] = v208;
      }
      else
      {
LABEL_201:
        if ( v129 == 65533 )
        {
          v209 = v128[20] + 1;
          ++v128[16];
          v128[20] = v209;
        }
      }
      command_buffer = (_DWORD *)sme_get_command_buffer(v11);
      if ( !command_buffer )
      {
LABEL_181:
        v12 = "%s:  fail to get command buffer";
        goto LABEL_182;
      }
      ++*(_DWORD *)(v11 + 17220);
      command_buffer[4] = 65538;
      command_buffer[6] = v114;
      command_buffer[8] = 1;
LABEL_97:
      v131 = command_buffer;
      qdf_mem_copy(command_buffer + 9, a2, 0x28u);
      result = csr_queue_sme_command(v11, v131, 0);
      if ( (_DWORD)result )
      {
        v12 = "%s: fail to send message";
LABEL_182:
        v13 = "csr_roam_issue_wm_status_change";
        goto LABEL_5;
      }
      goto LABEL_198;
    case 0x140Fu:
      result = csr_roam_send_disconnect_done_indication(result, a2);
      goto LABEL_198;
    case 0x1415u:
      v132 = *((unsigned int *)a2 + 7);
      if ( (unsigned int)v132 > 0x16 )
        v133 = 255;
      else
        v133 = dword_A1752C[v132];
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Receive WNI_SME_ASSOC_IND from SME vdev id %d, peer %02x:%02x:%02x:**:**:%02x akm %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "csr_roam_chk_lnk_assoc_ind",
        *((unsigned __int8 *)a2 + 4),
        *((unsigned __int8 *)a2 + 5),
        *((unsigned __int8 *)a2 + 6),
        *((unsigned __int8 *)a2 + 7),
        *((unsigned __int8 *)a2 + 10),
        v133);
      v161 = *(_QWORD *)(v11 + 21560);
      v162 = a2[9];
      LODWORD(v210) = *(_DWORD *)(a2 + 7);
      WORD2(v210) = v162;
      BYTE6(v210) = 6;
      wlan_objmgr_pdev_iterate_obj_list(
        v161,
        2,
        (void (__fastcall *)(__int64, __int64, __int64))csr_get_vdev_id_from_bssid,
        (__int64)&v210,
        0,
        0xBu);
      v171 = BYTE6(v210);
      if ( BYTE6(v210) >= 6uLL )
        v172 = 0;
      else
        v172 = BYTE6(v210);
      if ( BYTE6(v210) >= 6uLL )
      {
        result = qdf_trace_msg(
                   0x34u,
                   8u,
                   "%s: Couldn't find session_id for given BSSID%02x:%02x:%02x:**:**:%02x",
                   v163,
                   v164,
                   v165,
                   v166,
                   v167,
                   v168,
                   v169,
                   v170,
                   "csr_roam_chk_lnk_assoc_ind",
                   *((unsigned __int8 *)a2 + 14),
                   *((unsigned __int8 *)a2 + 15),
                   *((unsigned __int8 *)a2 + 16),
                   *((unsigned __int8 *)a2 + 19));
        goto LABEL_198;
      }
      if ( !(*(_QWORD *)(v11 + 17224) + 96LL * BYTE6(v210)) )
      {
        result = qdf_trace_msg(
                   0x34u,
                   2u,
                   "%s: session %d not found",
                   v163,
                   v164,
                   v165,
                   v166,
                   v167,
                   v168,
                   v169,
                   v170,
                   "csr_roam_chk_lnk_assoc_ind",
                   v172);
        goto LABEL_198;
      }
      result = _qdf_mem_malloc(0x180u, "csr_roam_chk_lnk_assoc_ind", 4034);
      if ( !result )
        goto LABEL_198;
      v22 = result;
      v173 = wlan_get_opmode_from_vdev_id(*(_QWORD *)(v11 + 21560), v171);
      *(_DWORD *)(v22 + 112) = *((_DWORD *)a2 + 685);
      v174 = *((_QWORD *)a2 + 343);
      *(_DWORD *)(v22 + 32) = 0;
      *(_QWORD *)(v22 + 120) = v174;
      *(_BYTE *)(v22 + 41) = *((_BYTE *)a2 + 20);
      v175 = *((_BYTE *)a2 + 326);
      *(_QWORD *)(v22 + 48) = a2 + 164;
      *(_BYTE *)(v22 + 43) = v175;
      v176 = *((_BYTE *)a2 + 66);
      *(_QWORD *)(v22 + 64) = a2 + 34;
      *(_BYTE *)(v22 + 56) = v176;
      *(_BYTE *)(v22 + 72) = *((_BYTE *)a2 + 586);
      *(_QWORD *)(v22 + 80) = a2 + 294;
      *(_BYTE *)(v22 + 16) = *((_BYTE *)a2 + 2739);
      qdf_mem_copy((void *)(v22 + 23), (char *)a2 + 5, 6u);
      qdf_mem_copy((void *)(v22 + 17), a2 + 7, 6u);
      *(_BYTE *)(v22 + 96) = *((_BYTE *)a2 + 2738);
      *(_BYTE *)(v22 + 136) = *((_BYTE *)a2 + 2752);
      *(_BYTE *)(v22 + 294) = *((_BYTE *)a2 + 2814);
      qdf_mem_copy((void *)(v22 + 140), a2 + 1378, 0x28u);
      if ( *((_BYTE *)a2 + 2824) )
        qdf_mem_copy((void *)(v22 + 196), a2 + 1412, 0x3Cu);
      if ( *((_BYTE *)a2 + 2884) )
        qdf_mem_copy((void *)(v22 + 256), a2 + 1442, 0x10u);
      *(_WORD *)(v22 + 316) = a2[1451];
      *(_BYTE *)(v22 + 272) = *((_BYTE *)a2 + 2900);
      *(_BYTE *)(v22 + 273) = *((_BYTE *)a2 + 2901);
      if ( (v173 & 0xFFFFFFFD) != 1 )
        goto LABEL_190;
      if ( wlan_is_open_wep_cipher(*(_QWORD *)(v11 + 21560), v171) )
      {
        csr_issue_set_context_req_helper(v11, v172, v22 + 23, 0, 1, 0);
        v185 = 0;
      }
      else
      {
        v185 = 1;
      }
      *(_BYTE *)(v22 + 42) = v185;
      if ( (unsigned __int8)v133 == 11 )
      {
        v198 = (void *)_qdf_mem_malloc(0xB90u, "csr_roam_chk_lnk_assoc_ind", 4093);
        *(_QWORD *)(v22 + 344) = v198;
        if ( v198 )
LABEL_153:
          qdf_mem_copy(v198, a2, 0xB90u);
      }
      else if ( (unsigned __int8)v133 == 23 )
      {
        v198 = (void *)_qdf_mem_malloc(0xB90u, "csr_roam_chk_lnk_assoc_ind", 4087);
        *(_QWORD *)(v22 + 336) = v198;
        if ( v198 )
          goto LABEL_153;
      }
      if ( !v11 || (v199 = *(_QWORD *)(v11 + 17224)) == 0 || (*(_BYTE *)(v199 + 96LL * v171 + 1) & 1) == 0 )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Session ID: %d is not valid",
          v177,
          v178,
          v179,
          v180,
          v181,
          v182,
          v183,
          v184,
          "csr_roam_call_callback",
          v172);
        goto LABEL_164;
      }
      wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(v11 + 21560), v171);
      v200 = *(_DWORD **)(v11 + 21968);
      if ( v200 )
      {
        v201 = *(_QWORD *)(v11 + 21552);
        if ( *(v200 - 1) != 1469140685 )
          __break(0x8228u);
        if ( ((unsigned int (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64))v200)(v201, v171, v22, 18, 10) )
        {
LABEL_164:
          v202 = *(_QWORD *)(v22 + 336);
          if ( v202 )
          {
            v203 = (_QWORD *)(v22 + 336);
          }
          else
          {
            v202 = *(_QWORD *)(v22 + 344);
            if ( !v202 )
            {
LABEL_189:
              *(_DWORD *)(v22 + 32) = 516;
              goto LABEL_190;
            }
            v203 = (_QWORD *)(v22 + 344);
          }
          _qdf_mem_free(v202);
          *v203 = 0;
          goto LABEL_189;
        }
      }
LABEL_190:
      if ( (unsigned __int8)v133 != 11 && (unsigned __int8)v133 != 23 )
      {
        if ( (v173 & 0xFFFFFFFD) == 1 && *(_DWORD *)(v22 + 32) != 516 )
          *((_BYTE *)a2 + 2942) = 1;
        csr_send_assoc_cnf_msg();
      }
LABEL_196:
      result = v22;
LABEL_197:
      result = _qdf_mem_free(result);
LABEL_198:
      _ReadStatusReg(SP_EL0);
      return result;
    case 0x1417u:
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: eWNI_SME_SWITCH_CHL_IND from SME",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "csr_roam_chk_lnk_swt_ch_ind");
      v105 = a2[16];
      v106 = *(_QWORD *)(v11 + 21560);
      LODWORD(v210) = *((_DWORD *)a2 + 7);
      WORD2(v210) = v105;
      BYTE6(v210) = 6;
      result = wlan_objmgr_pdev_iterate_obj_list(
                 v106,
                 2,
                 (void (__fastcall *)(__int64, __int64, __int64))csr_get_vdev_id_from_bssid,
                 (__int64)&v210,
                 0,
                 0xBu);
      v107 = BYTE6(v210);
      if ( BYTE6(v210) >= 6uLL )
        v108 = 0;
      else
        v108 = BYTE6(v210);
      if ( BYTE6(v210) > 5uLL )
        goto LABEL_198;
      if ( !(*(_QWORD *)(v11 + 17224) + 96LL * BYTE6(v210)) )
      {
        result = qdf_trace_msg(
                   0x34u,
                   2u,
                   "%s: session %d not found",
                   a3,
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   "csr_roam_chk_lnk_swt_ch_ind",
                   v108);
        goto LABEL_198;
      }
      if ( *((_DWORD *)a2 + 9) )
      {
        v12 = "%s: Channel switch failed";
        v13 = "csr_roam_chk_lnk_swt_ch_ind";
        goto LABEL_5;
      }
      wlan_cm_init_occupied_ch_freq_list(*(_QWORD *)(v11 + 21560), *(_QWORD *)(v11 + 21552), BYTE6(v210));
      result = _qdf_mem_malloc(0x180u, "csr_roam_chk_lnk_swt_ch_ind", 4327);
      if ( !result )
        goto LABEL_198;
      v196 = result;
      *(_DWORD *)(result + 140) = *((_DWORD *)a2 + 2);
      *(_DWORD *)(result + 176) = *((_DWORD *)a2 + 3);
      *(_BYTE *)(result + 172) = *((_BYTE *)a2 + 16);
      *(_DWORD *)(result + 144) = *((_DWORD *)a2 + 5);
      *(_DWORD *)(result + 148) = *((_DWORD *)a2 + 6);
      v197 = *((_DWORD *)a2 + 10);
      if ( (unsigned int)(v197 - 5) > 5 )
      {
        if ( (unsigned int)(v197 - 11) > 0x13 )
          *(_DWORD *)(result + 284) = 0;
        else
          *(_DWORD *)(result + 284) = 2;
      }
      else
      {
        *(_DWORD *)(result + 284) = 1;
      }
      if ( v11 && (v204 = *(_QWORD *)(v11 + 17224)) != 0 && (*(_BYTE *)(v204 + 96LL * v107 + 1) & 1) != 0 )
      {
        wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(v11 + 21560), v107);
        v205 = *(_DWORD **)(v11 + 21968);
        if ( v205 )
        {
          v206 = *(_QWORD *)(v11 + 21552);
          if ( *(v205 - 1) != 1469140685 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))v205)(v206, v107, v196, 42, 0);
        }
        result = v196;
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Session ID: %d is not valid",
          v188,
          v189,
          v190,
          v191,
          v192,
          v193,
          v194,
          v195,
          "csr_roam_call_callback",
          v108);
        result = v196;
      }
      goto LABEL_197;
    case 0x141Bu:
      result = _qdf_mem_malloc(0x180u, "csr_roam_chk_lnk_mic_fail_ind", 4496);
      if ( !result )
        goto LABEL_198;
      v22 = result;
      v89 = *(unsigned __int16 *)((char *)a2 + 9);
      v90 = *(_QWORD *)(v11 + 21560);
      LODWORD(v210) = *(_DWORD *)((char *)a2 + 5);
      WORD2(v210) = v89;
      BYTE6(v210) = 6;
      wlan_objmgr_pdev_iterate_obj_list(
        v90,
        2,
        (void (__fastcall *)(__int64, __int64, __int64))csr_get_vdev_id_from_bssid,
        (__int64)&v210,
        0,
        0xBu);
      v99 = BYTE6(v210);
      if ( BYTE6(v210) >= 6uLL )
        v100 = 0;
      else
        v100 = BYTE6(v210);
      if ( BYTE6(v210) > 5uLL )
        goto LABEL_138;
      *(_QWORD *)(v22 + 88) = (char *)a2 + 11;
      if ( *((_BYTE *)a2 + 29) )
        v101 = 5;
      else
        v101 = 4;
      if ( v11 && (v102 = *(_QWORD *)(v11 + 17224)) != 0 && (*(_BYTE *)(v102 + 96LL * v99 + 1) & 1) != 0 )
      {
        wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(v11 + 21560), v99);
        v103 = *(_DWORD **)(v11 + 21968);
        if ( v103 )
        {
          v104 = *(_QWORD *)(v11 + 21552);
          if ( *(v103 - 1) != 1469140685 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))v103)(v104, v99, v22, 14, v101);
        }
        *(_QWORD *)((char *)&v210 + 5) = 0;
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Session ID: %d is not valid",
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          "csr_roam_call_callback",
          v100);
LABEL_138:
        *(_QWORD *)((char *)&v210 + 5) = 0;
        v99 = v100;
      }
      v186 = *(_QWORD *)(v11 + 17224);
      *(_QWORD *)&v210 = 0;
      if ( v186 + 96LL * v99 )
      {
        qdf_mem_set(&v210, 0xDu, 0);
        v187 = *(_QWORD *)(v11 + 21552);
        LOBYTE(v210) = 9;
        cm_diag_get_auth_enc_type_vdev_id(v187, (_BYTE *)&v210 + 1, (_BYTE *)&v210 + 2, (_BYTE *)&v210 + 3, v100);
        wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(v11 + 21560), v100, (char *)&v210 + 5);
        host_diag_event_report_payload(1653, 13, &v210);
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: session %d not found",
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          "csr_roam_diag_mic_fail",
          v100);
      }
      goto LABEL_196;
    case 0x1424u:
      v134 = a2[9];
      v135 = *(_QWORD *)(result + 21560);
      LODWORD(v210) = *(_DWORD *)(a2 + 7);
      WORD2(v210) = v134;
      BYTE6(v210) = 6;
      wlan_objmgr_pdev_iterate_obj_list(
        v135,
        2,
        (void (__fastcall *)(__int64, __int64, __int64))csr_get_vdev_id_from_bssid,
        (__int64)&v210,
        0,
        0xBu);
      if ( BYTE6(v210) >= 6u )
        result = qdf_trace_msg(
                   0x34u,
                   8u,
                   "%s: Couldn't find session_id for given BSSID",
                   v136,
                   v137,
                   v138,
                   v139,
                   v140,
                   v141,
                   v142,
                   v143,
                   "csr_roam_chk_lnk_assoc_ind_upper_layer");
      else
        result = csr_send_assoc_ind_to_upper_layer_cnf_msg(v11, a2, 0);
      if ( !*((_DWORD *)a2 + 685) )
        goto LABEL_198;
      result = *((_QWORD *)a2 + 343);
      if ( !result )
        goto LABEL_198;
      goto LABEL_197;
    case 0x1425u:
      result = _qdf_mem_malloc(0x180u, "csr_roam_chk_lnk_pbs_probe_req_ind", 4524);
      if ( !result )
        goto LABEL_198;
      v22 = result;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: WPS PBC Probe request Indication from SME",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "csr_roam_chk_lnk_pbs_probe_req_ind");
      v39 = *(unsigned __int16 *)((char *)a2 + 9);
      v40 = *(_QWORD *)(v11 + 21560);
      LODWORD(v210) = *(_DWORD *)((char *)a2 + 5);
      WORD2(v210) = v39;
      BYTE6(v210) = 6;
      wlan_objmgr_pdev_iterate_obj_list(
        v40,
        2,
        (void (__fastcall *)(__int64, __int64, __int64))csr_get_vdev_id_from_bssid,
        (__int64)&v210,
        0,
        0xBu);
      v49 = BYTE6(v210);
      if ( BYTE6(v210) >= 6uLL )
        v50 = 0;
      else
        v50 = BYTE6(v210);
      if ( BYTE6(v210) > 5uLL )
        goto LABEL_196;
      *(_QWORD *)(v22 + 88) = a2 + 6;
      if ( !v11 || (v51 = *(_QWORD *)(v11 + 17224)) == 0 || (*(_BYTE *)(v51 + 96LL * v49 + 1) & 1) == 0 )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Session ID: %d is not valid",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "csr_roam_call_callback",
          v50);
        goto LABEL_196;
      }
      wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(v11 + 21560), v49);
      v25 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v11 + 21968);
      if ( !v25 )
        goto LABEL_196;
      v26 = *(_QWORD *)(v11 + 21552);
      v27 = v49;
      v28 = v22;
      v29 = 19;
      v30 = 12;
      goto LABEL_110;
    case 0x1429u:
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: GetSnrReq from self",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "csr_roam_check_for_link_status_change");
      result = wma_get_snr(a2);
      if ( !(_DWORD)result )
        goto LABEL_198;
      v12 = "%s: Error in wma_get_snr";
      v13 = "csr_update_snr";
      goto LABEL_5;
    case 0x1439u:
      result = _qdf_mem_malloc(0x180u, "csr_roam_chk_lnk_max_assoc_exceeded", 4547);
      if ( !result )
        goto LABEL_198;
      v22 = result;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: max assoc have been reached, new peer cannot be accepted",
        v144,
        v145,
        v146,
        v147,
        v148,
        v149,
        v150,
        v151,
        "csr_roam_chk_lnk_max_assoc_exceeded");
      v152 = *(unsigned __int16 *)((char *)a2 + 9);
      v153 = *(_DWORD *)((char *)a2 + 5);
      v23 = *((unsigned __int8 *)a2 + 4);
      *(_WORD *)(v22 + 27) = v152;
      *(_DWORD *)(v22 + 23) = v153;
      if ( !v11 )
        goto LABEL_113;
      if ( v23 > 5 )
        goto LABEL_113;
      v154 = *(_QWORD *)(v11 + 17224);
      if ( !v154 || (*(_BYTE *)(v154 + 96LL * v23 + 1) & 1) == 0 )
        goto LABEL_113;
      wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(v11 + 21560), v23);
      v25 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v11 + 21968);
      if ( !v25 )
        goto LABEL_196;
      v26 = *(_QWORD *)(v11 + 21552);
      v27 = v23;
      v28 = v22;
      v29 = 18;
      v30 = 13;
      goto LABEL_110;
    case 0x1451u:
      result = qdf_trace_msg(
                 0x34u,
                 8u,
                 "%s: TSM Stats rsp from PE",
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 "csr_roam_check_for_link_status_change");
      v109 = *((_QWORD *)a2 + 6);
      if ( v109 )
      {
        v110 = *(void (__fastcall **)(__int128 *, __int64))(v109 + 16);
        if ( v110 )
        {
          v111 = *(_QWORD *)(a2 + 14);
          v112 = *(_QWORD *)(a2 + 18);
          v113 = *(_QWORD *)(v109 + 24);
          *(_QWORD *)&v210 = *(_QWORD *)(a2 + 10);
          *((_QWORD *)&v210 + 1) = v111;
          v211 = v112;
          if ( *((_DWORD *)v110 - 1) != 1889688530 )
            __break(0x8228u);
          v110(&v210, v113);
          *(_QWORD *)(v109 + 16) = 0;
        }
        result = _qdf_mem_free(v109);
        *((_QWORD *)a2 + 6) = 0;
      }
      goto LABEL_198;
    default:
      if ( *a2 != 5283 )
        goto LABEL_198;
      result = _qdf_mem_malloc(0x180u, "csr_roam_channel_switch_started_notify", 4574);
      if ( !result )
        goto LABEL_198;
      *(_QWORD *)(result + 368) = a2;
      v22 = result;
      v23 = *((unsigned __int8 *)a2 + 4);
      if ( v11 && v23 <= 5 && (v24 = *(_QWORD *)(v11 + 17224)) != 0 && (*(_BYTE *)(v24 + 96LL * v23 + 1) & 1) != 0 )
      {
        wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(v11 + 21560), v23);
        v25 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v11 + 21968);
        if ( v25 )
        {
          v26 = *(_QWORD *)(v11 + 21552);
          v27 = v23;
          v28 = v22;
          v29 = 51;
          v30 = 23;
LABEL_110:
          if ( *((_DWORD *)v25 - 1) != 1469140685 )
            __break(0x8228u);
          v25(v26, v27, v28, v29, v30);
        }
      }
      else
      {
LABEL_113:
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Session ID: %d is not valid",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "csr_roam_call_callback",
          v23);
      }
      goto LABEL_196;
  }
}
