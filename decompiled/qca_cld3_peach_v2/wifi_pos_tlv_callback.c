__int64 __fastcall wifi_pos_tlv_callback(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *v10; // x20
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8
  __int64 v22; // x0
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x22
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int *v41; // x11
  unsigned int v42; // w9
  unsigned int v43; // w8
  unsigned __int8 v44; // w10
  char v45; // w21
  _DWORD *v46; // x11
  int v47; // w13
  bool v48; // cf
  char v49; // w13
  int *v50; // x13
  __int64 v51; // x13
  int v52; // w14
  __int64 psoc; // x0
  _DWORD *v54; // x22
  __int64 psoc_priv_obj; // x0
  unsigned int *v56; // x21
  unsigned int v57; // w9
  _DWORD *v58; // x8
  __int64 v59; // x1
  __int64 v60; // x0
  __int64 v61; // x2
  __int64 v62; // x3
  __int64 v63; // x0
  __int64 v64; // x0
  unsigned int *v65; // x21
  __int64 v66; // x25
  _DWORD *v67; // x26
  __int64 v68; // x0
  __int64 v69; // x0
  unsigned int *v70; // x23
  __int64 v71; // x0
  __int64 v72; // x21
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  _BYTE *v81; // x20
  __int64 v82; // x22
  _WORD *v83; // x24
  unsigned int v84; // w19
  __int64 v85; // x0
  __int64 v86; // x0
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  char v95; // w8
  unsigned int v96; // w22
  _DWORD *v97; // x8
  __int64 v98; // x1
  __int64 result; // x0
  const char *v100; // x2
  const char *v101; // x3
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  __int64 tx_ops; // x0
  __int64 v111; // x22
  __int64 pdev_by_id; // x0
  __int64 v113; // x9
  double (*v114)(void); // x10
  __int64 v115; // x19
  double v116; // d0
  unsigned int *v117; // x8
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  void (__fastcall *v125)(__int64, __int64, __int64, __int64); // x8
  __int64 v126; // x2
  __int64 v127; // x3
  __int64 v128; // x0
  __int64 v129; // x1
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  int v138; // w20
  unsigned __int64 v139; // x26
  unsigned int v140; // w25
  __int64 v141; // x27
  unsigned __int64 StatusReg; // x8
  __int64 v143; // x8
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  __int64 v152; // x4
  __int64 i; // x20
  unsigned int *v154; // x27
  __int64 v155; // x0
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7
  const void *v164; // x22
  unsigned int v165; // w23
  _BYTE *v166; // x0
  int v167; // w8
  __int64 v168; // x24
  _BYTE *v169; // x25
  double v170; // d0
  double v171; // d1
  double v172; // d2
  double v173; // d3
  double v174; // d4
  double v175; // d5
  double v176; // d6
  double v177; // d7
  __int64 v178; // x8
  _DWORD *v179; // x8
  __int64 v180; // x1
  __int64 v181; // x26
  unsigned int *v182; // x28
  unsigned int v183; // t1
  unsigned int *v184; // x20
  char v185; // w0
  unsigned int v186; // w1
  double v187; // d0
  double v188; // d1
  double v189; // d2
  double v190; // d3
  double v191; // d4
  double v192; // d5
  double v193; // d6
  double v194; // d7
  unsigned __int8 channel_reg_power_for_freq; // w0
  unsigned int v196; // w1
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  char is_dfs_for_freq; // w0
  __int64 v206; // x2
  unsigned int v207; // w27
  double v208; // d0
  double v209; // d1
  double v210; // d2
  double v211; // d3
  double v212; // d4
  double v213; // d5
  double v214; // d6
  double v215; // d7
  unsigned int v216; // w26
  int v217; // w11
  __int64 v218; // x9
  __int64 v219; // x11
  int v220; // w8
  int v221; // w10
  int v222; // w7
  unsigned int v223; // w8
  unsigned int v224; // w10
  int v225; // w12
  _DWORD *v226; // x8
  __int64 v227; // x1
  unsigned int *v228; // x8
  double v229; // d0
  double v230; // d1
  double v231; // d2
  double v232; // d3
  double v233; // d4
  double v234; // d5
  double v235; // d6
  double v236; // d7
  __int64 v237; // x0
  __int64 v238; // [xsp+0h] [xbp-1D0h]
  __int64 v239; // [xsp+8h] [xbp-1C8h]
  __int64 v240; // [xsp+10h] [xbp-1C0h]
  __int64 v241; // [xsp+18h] [xbp-1B8h]
  _QWORD s[53]; // [xsp+28h] [xbp-1A8h] BYREF

  v10 = a2;
  s[51] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = qdf_trace_msg(
          0x25u,
          8u,
          "%s: enter: msg_type: %d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "wifi_pos_tlv_callback",
          *a2);
  v21 = *(_DWORD *)v10;
  if ( *(int *)v10 <= 2 )
  {
    if ( v21 != 1 )
    {
      if ( v21 != 2 )
        goto LABEL_42;
      psoc = wifi_pos_get_psoc(v12);
      if ( !psoc || (v54 = (_DWORD *)v10[1], (psoc_priv_obj = wifi_pos_get_psoc_priv_obj(psoc)) == 0) )
      {
        v100 = "%s: wifi_pos priv obj is null";
        v101 = "wifi_pos_process_set_cap_req";
        goto LABEL_79;
      }
      v56 = (unsigned int *)psoc_priv_obj;
      qdf_trace_msg(
        0x25u,
        8u,
        "%s: Received set cap req pid(%d), len(%d)",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "wifi_pos_process_set_cap_req",
        *((unsigned int *)v10 + 1),
        *((unsigned int *)v10 + 4));
      v57 = v56[3] & 0xFFFFFFFE | *v54 & 1;
      v56[3] = v57;
      v56[3] = v57 & 0xFFFFFFFD | (2 * ((*v54 >> 1) & 1));
      LODWORD(s[0]) = qdf_status_to_os_return(0);
      v58 = *((_DWORD **)v56 + 16);
      v59 = *v56;
      v60 = a1;
      v61 = 2;
      v62 = 4;
      if ( *(v58 - 1) != 1562231049 )
        __break(0x8228u);
LABEL_22:
      ((void (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD *))v58)(v60, v59, v61, v62, s);
      goto LABEL_43;
    }
    v85 = wifi_pos_get_psoc(v12);
    if ( !v85 || (v86 = wifi_pos_get_psoc_priv_obj(v85)) == 0 )
    {
      v100 = "%s: wifi_pos priv obj is null";
      v101 = "wifi_pos_process_app_reg_req";
      goto LABEL_79;
    }
    v72 = v86;
    qdf_trace_msg(
      0x25u,
      8u,
      "%s: Received App Req Req pid(%d), len(%d)",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wifi_pos_process_app_reg_req",
      *((unsigned int *)v10 + 1),
      *((unsigned int *)v10 + 4));
    if ( *((_DWORD *)v10 + 4) == 16 && !strncmp((const char *)v10[1], "QUALCOMM-OEM-APP", 0x10u) )
    {
      qdf_trace_msg(
        0x25u,
        8u,
        "%s: Valid App Req Req from pid(%d)",
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        "wifi_pos_process_app_reg_req",
        *((unsigned int *)v10 + 1));
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v72 + 88);
        v143 = *(_QWORD *)(v72 + 96);
      }
      else
      {
        raw_spin_lock_bh(v72 + 88);
        v143 = *(_QWORD *)(v72 + 96) | 1LL;
        *(_QWORD *)(v72 + 96) = v143;
      }
      *(_BYTE *)(v72 + 4) = 1;
      *(_DWORD *)v72 = *((_DWORD *)v10 + 1);
      if ( (v143 & 1) != 0 )
      {
        *(_QWORD *)(v72 + 96) = v143 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v72 + 88);
      }
      else
      {
        raw_spin_unlock(v72 + 88);
      }
      v152 = *(unsigned __int16 *)(a1 + 54);
      v67 = &unk_92E000;
      vdev_idx = 0;
      if ( (unsigned int)(v152 - 31) > 0xFFFFFFE1 )
      {
LABEL_99:
        v155 = _qdf_mem_malloc(2 * v152, "wifi_pos_process_app_reg_req", 903);
        if ( v155 )
        {
          v164 = (const void *)v155;
          wlan_objmgr_iterate_obj_list(a1, 2, wifi_pos_vdev_iterator, v155, 1, 0xDu);
          v165 = 2 * v67[308] + 5;
          v166 = (_BYTE *)_qdf_mem_malloc(v165, "wifi_pos_prepare_reg_resp", 104);
          if ( v166 )
          {
            v167 = v67[308];
            v168 = (__int64)v166;
            *v166 = v167;
            v169 = v166 + 1;
            qdf_mem_copy(v166 + 1, v164, (unsigned int)(2 * v167));
            v178 = (unsigned int)v67[308];
            *(_DWORD *)&v169[2 * v178] |= 1u;
            if ( !(_DWORD)v178 )
              qdf_trace_msg(
                0x25u,
                8u,
                "%s: no active vdev",
                v170,
                v171,
                v172,
                v173,
                v174,
                v175,
                v176,
                v177,
                "wifi_pos_process_app_reg_req");
            v179 = *(_DWORD **)(v72 + 128);
            v180 = *((unsigned int *)v10 + 1);
            v67[308] = 0;
            if ( *(v179 - 1) != 1562231049 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64))v179)(a1, v180, 1, v165, v168);
            _qdf_mem_free(v168);
            _qdf_mem_free((__int64)v164);
            goto LABEL_43;
          }
          LOBYTE(s[0]) = 1;
          _qdf_mem_free((__int64)v164);
          v96 = 2;
LABEL_39:
          v97 = *(_DWORD **)(v72 + 128);
          v98 = *((unsigned int *)v10 + 1);
          if ( *(v97 - 1) != 1562231049 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD *))v97)(a1, v98, 6, 1, s);
          result = v96;
          goto LABEL_80;
        }
        v96 = 2;
        qdf_trace_msg(
          0x25u,
          2u,
          "%s: App Reg failed as Vdevs info allocation failed",
          v156,
          v157,
          v158,
          v159,
          v160,
          v161,
          v162,
          v163,
          "wifi_pos_process_app_reg_req");
        v95 = 1;
      }
      else
      {
        qdf_trace_msg(
          0x25u,
          2u,
          "%s: App Reg failed as Vdev count is %d (zero or greater than max)",
          v144,
          v145,
          v146,
          v147,
          v148,
          v149,
          v150,
          v151,
          "wifi_pos_process_app_reg_req");
        v95 = 1;
        v96 = 4;
      }
    }
    else
    {
      qdf_trace_msg(
        0x25u,
        2u,
        "%s: Invalid signature pid(%d)",
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        "wifi_pos_process_app_reg_req",
        *((unsigned int *)v10 + 1));
      v95 = 3;
      v96 = 12;
    }
    LOBYTE(s[0]) = v95;
    goto LABEL_39;
  }
  if ( v21 == 3 )
  {
    memset(s, 0, 168);
    v63 = wifi_pos_get_psoc(v12);
    if ( !v63 || (v64 = wifi_pos_get_psoc_priv_obj(v63)) == 0 )
    {
      v100 = "%s: wifi_pos priv obj is null";
      v101 = "wifi_pos_process_get_cap_req";
      goto LABEL_79;
    }
    v65 = (unsigned int *)v64;
    qdf_trace_msg(
      0x25u,
      8u,
      "%s: Received get cap req pid(%d), len(%d)",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wifi_pos_process_get_cap_req",
      *((unsigned int *)v10 + 1),
      *((unsigned int *)v10 + 4));
    wifi_pos_populate_caps(a1, s);
    v60 = a1;
    v61 = 3;
    v62 = 168;
    LODWORD(s[20]) = s[20] & 0xFFFFFFFC | v65[3] & 3;
    v58 = *((_DWORD **)v65 + 16);
    v59 = *v65;
    if ( *(v58 - 1) != 1562231049 )
      __break(0x8228u);
    goto LABEL_22;
  }
  if ( v21 != 4 )
  {
    if ( v21 == 5 )
    {
      s[0] = 0;
      v22 = wifi_pos_get_psoc(v12);
      v23 = wifi_pos_get_psoc_priv_obj(v22);
      if ( v23 )
      {
        v32 = v23;
        qdf_trace_msg(
          0x25u,
          8u,
          "%s: Received data req pid(%d), len(%d)",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wifi_pos_process_data_req",
          *((unsigned int *)v10 + 1),
          *((unsigned int *)v10 + 4));
        v41 = (unsigned int *)v10[3];
        if ( v41 && (v42 = *v41) != 0 )
        {
          v43 = 0;
          v44 = 0;
          v45 = 0;
          v46 = v41 + 1;
          do
          {
            v50 = &v46[3 * v44];
            v52 = *v50;
            v51 = (unsigned int)v50[1];
            if ( v52 == 2 )
            {
              v47 = *(_DWORD *)(v10[1] + v51);
              v48 = v47 != 0;
              v49 = v47 - 1;
              if ( v48 )
                v45 = v49;
              else
                v45 = 0;
            }
            else if ( !v52 )
            {
              v43 = *(_DWORD *)(v10[1] + v51);
            }
            ++v44;
          }
          while ( v42 > v44 );
          if ( v43 <= 0xA && ((1 << v43) & 0x60A) != 0 )
            goto LABEL_43;
          if ( v43 == 128 )
          {
            qdf_trace_msg(
              0x25u,
              8u,
              "%s: WRU request",
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              "wifi_pos_process_data_req");
            v125 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v32 + 152);
            if ( !v125 )
              goto LABEL_43;
            v126 = v10[1];
            v127 = *((unsigned int *)v10 + 4);
            v128 = a1;
            v129 = 128;
            if ( *((_DWORD *)v125 - 1) != -810363768 )
              __break(0x8228u);
            goto LABEL_63;
          }
          if ( v43 == 129 )
          {
            qdf_trace_msg(
              0x25u,
              8u,
              "%s: FTMRR request",
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              "wifi_pos_process_data_req");
            v125 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v32 + 152);
            if ( v125 )
            {
              v126 = v10[1];
              v127 = *((unsigned int *)v10 + 4);
              v128 = a1;
              v129 = 129;
              if ( *((_DWORD *)v125 - 1) != -810363768 )
                __break(0x8228u);
LABEL_63:
              v125(v128, v129, v126, v127);
            }
LABEL_43:
            result = 0;
LABEL_80:
            _ReadStatusReg(SP_EL0);
            return result;
          }
        }
        else
        {
          v45 = 0;
        }
        qdf_trace_msg(
          0x25u,
          8u,
          "%s: invalid sub type or not passed",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "wifi_pos_process_data_req");
        tx_ops = wifi_pos_get_tx_ops(a1, v102, v103, v104, v105, v106, v107, v108, v109);
        if ( tx_ops )
        {
          v111 = tx_ops;
          pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, v45, 0xDu);
          if ( pdev_by_id )
          {
            v113 = v10[1];
            v114 = *(double (**)(void))(v111 + 16);
            v115 = pdev_by_id;
            LODWORD(s[0]) = *((_DWORD *)v10 + 4);
            s[1] = v113;
            if ( *((_DWORD *)v114 - 1) != 2016393330 )
              __break(0x822Au);
            v116 = v114();
            wlan_objmgr_pdev_release_ref(v115, 0xDu, v117, v116, v118, v119, v120, v121, v122, v123, v124);
            goto LABEL_43;
          }
          v100 = "%s: pdev null";
        }
        else
        {
          v100 = "%s: tx ops null";
        }
      }
      else
      {
        v100 = "%s: wifi_pos priv obj is null";
      }
      v101 = "wifi_pos_process_data_req";
LABEL_79:
      qdf_trace_msg(0x25u, 2u, v100, v24, v25, v26, v27, v28, v29, v30, v31, v101);
      result = 4;
      goto LABEL_80;
    }
LABEL_42:
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: invalid request type",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wifi_pos_tlv_callback");
    goto LABEL_43;
  }
  v66 = v10[1];
  v67 = (_DWORD *)*((unsigned int *)v10 + 4);
  v68 = wifi_pos_get_psoc(v12);
  if ( !v68 || (v69 = wifi_pos_get_psoc_priv_obj(v68)) == 0 )
  {
    v100 = "%s: wifi_pos priv obj is null";
LABEL_46:
    v101 = "wifi_pos_process_ch_info_req";
    goto LABEL_79;
  }
  v70 = (unsigned int *)v69;
  qdf_trace_msg(
    0x25u,
    8u,
    "%s: Received ch info req pid(%d), len(%d)",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "wifi_pos_process_ch_info_req",
    *((unsigned int *)v10 + 1),
    *((unsigned int *)v10 + 4));
  v71 = wlan_objmgr_get_pdev_by_id(a1, 0, 0xDu);
  if ( !v71 )
  {
    v100 = "%s: pdev get API failed";
    goto LABEL_46;
  }
  v72 = v71;
  memset(s, 0, 0x198u);
  if ( (unsigned int)v67 >= 0x67 )
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Invalid number of channels",
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      "wifi_pos_process_ch_info_req");
    v81 = nullptr;
    v82 = 0;
    v83 = nullptr;
    v84 = 4;
LABEL_131:
    _qdf_mem_free((__int64)v81);
    _qdf_mem_free((__int64)v83);
    _qdf_mem_free(v82);
    wlan_objmgr_pdev_release_ref(v72, 0xDu, v228, v229, v230, v231, v232, v233, v234, v235, v236);
    result = v84;
    goto LABEL_80;
  }
  v82 = _qdf_mem_malloc(0x198u, "wifi_pos_process_ch_info_req", 673);
  if ( !v82 )
  {
    v81 = nullptr;
    v83 = nullptr;
    v84 = 2;
    goto LABEL_131;
  }
  v83 = (_WORD *)_qdf_mem_malloc(0x992u, "wifi_pos_process_ch_info_req", 679);
  if ( !v83 )
  {
    v81 = nullptr;
    v84 = 2;
    goto LABEL_131;
  }
  if ( !(_DWORD)v67 && *((_DWORD *)v10 + 9) == 2 )
  {
    wifi_pos_get_ch_info(a1, v83);
    qdf_spin_lock_bh_15(v70 + 22);
    v138 = *((unsigned __int8 *)v70 + 104);
    qdf_spin_unlock_bh_20(v70 + 22);
    if ( *v83 )
    {
      v139 = 0;
      v140 = 0;
      v141 = 1;
      do
      {
        if ( !v138 || !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)&v83[v141]) )
          ++v140;
        ++v139;
        v141 += 12;
      }
      while ( v139 < (unsigned __int16)*v83 );
    }
    else
    {
      v140 = 0;
    }
LABEL_115:
    v207 = (32 * v140) | 1;
    v81 = (_BYTE *)_qdf_mem_malloc(v207, "wifi_pos_process_ch_info_req", 732);
    if ( v81 )
    {
      if ( v140 )
      {
        v216 = 0;
        do
        {
          v218 = (__int64)&v83[12 * (unsigned __int8)v216 + 1];
          v219 = (__int64)&v81[32 * v216 + 1];
          *(_DWORD *)(v219 + 4) = 0;
          v220 = *(_DWORD *)(v219 + 24);
          v221 = *(_DWORD *)(v219 + 28);
          *(_DWORD *)v219 = *(unsigned __int8 *)(v218 + 4);
          *(_DWORD *)(v219 + 8) = *(_DWORD *)v218;
          v222 = *(_DWORD *)(v218 + 12);
          *(_QWORD *)(v219 + 16) = 0;
          *(_DWORD *)(v219 + 24) = v220 & 0xFF00FFFF;
          *(_DWORD *)(v219 + 12) = v222;
          v223 = v220 & 0xFF00FFFF | ((unsigned __int8)*(_DWORD *)(v218 + 8) << 16);
          *(_DWORD *)(v219 + 24) = v223;
          *(_DWORD *)(v219 + 28) = v221 & 0xFFFF00FF;
          v224 = v221 & 0xFFFF00FF | ((unsigned __int8)*(_DWORD *)(v218 + 8) << 8);
          *(_DWORD *)(v219 + 28) = v224;
          v225 = 0;
          if ( *(_BYTE *)(v218 + 20) == 1 )
          {
            v225 = 1024;
            *(_DWORD *)(v219 + 20) = 1024;
          }
          if ( *(_DWORD *)(v218 + 16) )
          {
            *(_DWORD *)(v219 + 20) = v225;
            *(_DWORD *)(v219 + 20) = *(_DWORD *)(v218 + 16) | v225;
            v217 = *(_DWORD *)(v218 + 16);
          }
          else
          {
            v217 = 0;
          }
          LODWORD(v241) = v217;
          LODWORD(v240) = *(unsigned __int8 *)(v218 + 20);
          LODWORD(v239) = v224;
          LODWORD(v238) = v223;
          qdf_trace_msg(
            0x25u,
            8u,
            "%s: i:%d chan_id:%d freq:%d cfreq1:%d reg_info_1:%x reg_info_2:%x is_dfs_chan:%d phymode:%d",
            v208,
            v209,
            v210,
            v211,
            v212,
            v213,
            v214,
            v215,
            "wifi_pos_process_ch_info_req",
            v216++,
            v238,
            v239,
            v240,
            v241);
        }
        while ( v140 > (unsigned __int8)v216 );
        v207 = (32 * v140) | 1;
      }
      else
      {
        LOBYTE(v216) = 0;
      }
      *v81 = v216;
      v226 = *((_DWORD **)v70 + 16);
      v227 = *v70;
      if ( *(v226 - 1) != 1562231049 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, _BYTE *))v226)(a1, v227, 4, v207, v81);
      v84 = 0;
    }
    else
    {
      v84 = 2;
    }
    goto LABEL_131;
  }
  for ( i = 0; i != 102; ++i )
    *(_DWORD *)(v82 + 4 * i) = wlan_reg_chan_band_to_freq(
                                 v72,
                                 *(unsigned __int8 *)(v66 + i),
                                 3u,
                                 v130,
                                 v131,
                                 v132,
                                 v133,
                                 v134,
                                 v135,
                                 v136,
                                 v137);
  v140 = 0;
  if ( !(_DWORD)v67 )
    goto LABEL_115;
  v10 = s;
  v154 = (unsigned int *)v82;
  do
  {
    if ( (unsigned int)wlan_reg_get_chan_enum_for_freq(*v154, v130, v131, v132, v133, v134, v135, v136, v137) <= 0x65 )
    {
      if ( v140 > 0x65 )
      {
        __break(1u);
        goto LABEL_99;
      }
      *((_DWORD *)s + v140++) = *v154;
    }
    v67 = (_DWORD *)((char *)v67 - 1);
    ++v154;
  }
  while ( v67 );
  if ( !v140 )
    goto LABEL_115;
  v181 = 0;
  v182 = (unsigned int *)s;
  while ( v181 != 1224 )
  {
    v183 = *v182++;
    *(_DWORD *)&v83[v181 + 1] = v183;
    v184 = (unsigned int *)&v83[v181 + 1];
    v185 = wlan_reg_freq_to_chan(v72, v183, v130, v131, v132, v133, v134, v135, v136, v137);
    v186 = *v184;
    LOBYTE(v83[v181 + 3]) = v185;
    channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(
                                   v72,
                                   v186,
                                   v187,
                                   v188,
                                   v189,
                                   v190,
                                   v191,
                                   v192,
                                   v193,
                                   v194);
    v196 = *v184;
    *(_DWORD *)&v83[v181 + 5] = channel_reg_power_for_freq;
    is_dfs_for_freq = wlan_reg_is_dfs_for_freq(v72, v196, v197, v198, v199, v200, v201, v202, v203, v204);
    v206 = *v184;
    LOBYTE(v83[v181 + 11]) = is_dfs_for_freq & 1;
    wifi_update_channel_bw_info(a1, v72, v206, v184);
    v181 += 12;
    if ( 12LL * v140 == v181 )
      goto LABEL_115;
  }
  __break(0x5512u);
  v237 = MEMORY[0x408EC78]();
  return wifi_pos_psoc_obj_destroyed_notification(v237);
}
