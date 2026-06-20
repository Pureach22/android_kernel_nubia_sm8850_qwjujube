__int64 __fastcall mlo_mgr_link_recfg_indication_event_handler(__int64 a1, unsigned __int8 *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned __int8 v31; // w8
  int v32; // w10
  __int64 v33; // x8
  __int64 v34; // x8
  __int64 v35; // x8
  __int64 v36; // x8
  __int64 v37; // x8
  __int64 v38; // x8
  __int64 v39; // x8
  __int64 v40; // x8
  __int64 v41; // x8
  __int64 v42; // x8
  __int64 v43; // x8
  __int64 v44; // x8
  __int64 v45; // x8
  __int64 v46; // x8
  __int64 v47; // x8
  __int64 v48; // x8
  __int64 pdev_by_id; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x21
  _QWORD *v59; // x23
  __int64 entry_by_bssid; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x22
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x22
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x22
  __int64 v78; // x0
  __int64 v79; // x0
  unsigned int v80; // w22
  char v81; // w23
  unsigned int *v82; // x8
  unsigned int *v83; // x8
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int16 v100; // w9
  unsigned __int8 v101; // w10
  __int64 v102; // x8
  __int64 (__fastcall *v103)(__int64, __int64 *); // x8
  unsigned int v104; // w0
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  unsigned __int8 *v121; // x8
  __int64 v122; // x4
  __int64 v123; // x5
  __int64 v124; // x6
  __int64 v125; // x7
  unsigned __int8 *v126; // x25
  unsigned __int8 *ap_link_by_link_id; // x0
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  unsigned __int16 *v136; // x8
  __int16 v137; // w9
  unsigned __int8 *v138; // x0
  unsigned __int16 *v139; // x8
  __int16 v140; // w9
  unsigned __int8 *v141; // x0
  unsigned __int16 *v142; // x8
  __int16 v143; // w9
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  __int64 v152; // x4
  __int64 v153; // x5
  __int64 v154; // x6
  __int64 v155; // x7
  const char *v156; // x2
  unsigned int *v157; // x8
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  __int64 v167; // [xsp+0h] [xbp-280h]
  __int64 v168; // [xsp+0h] [xbp-280h]
  __int64 v169; // [xsp+0h] [xbp-280h]
  __int64 v170; // [xsp+8h] [xbp-278h]
  __int64 v171; // [xsp+8h] [xbp-278h]
  __int64 v172; // [xsp+8h] [xbp-278h]
  __int64 v173; // [xsp+10h] [xbp-270h]
  __int64 v174; // [xsp+10h] [xbp-270h]
  __int64 v175; // [xsp+18h] [xbp-268h]
  __int64 v176; // [xsp+18h] [xbp-268h]
  __int64 v177; // [xsp+20h] [xbp-260h]
  __int64 v178; // [xsp+20h] [xbp-260h]
  __int64 v179; // [xsp+28h] [xbp-258h]
  __int64 v180; // [xsp+28h] [xbp-258h]
  __int64 v181; // [xsp+38h] [xbp-248h] BYREF
  __int64 v182; // [xsp+40h] [xbp-240h]
  _QWORD s[71]; // [xsp+48h] [xbp-238h] BYREF

  s[70] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x230u);
  v181 = 0;
  v182 = 0;
  if ( a2 )
  {
    v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 108);
    if ( v12 )
    {
      v21 = *(_QWORD *)(v12 + 1360);
      v22 = v12;
      if ( !v21 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: mlo_ctx null",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "mlo_mgr_link_recfg_indication_event_handler");
        v80 = 4;
LABEL_67:
        wlan_objmgr_vdev_release_ref(v22, 0x6Cu, v83, v84, v85, v86, v87, v88, v89, v90, v91);
        goto LABEL_68;
      }
      if ( !cm_is_vdev_connected(v12, v13, v14, v15, v16, v17, v18, v19, v20) )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: vdev is NOT in connected state, send complete cmd to with failure status",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "mlo_mgr_link_recfg_indication_event_handler");
        v100 = *(_WORD *)(a2 + 5);
        v101 = *a2;
        *(_DWORD *)((char *)&v181 + 1) = *(_DWORD *)(a2 + 1);
        *(_WORD *)((char *)&v181 + 5) = v100;
        LOBYTE(v181) = v101;
        v182 = 1;
        if ( a1 && (v102 = *(_QWORD *)(a1 + 2128)) != 0 )
        {
          v103 = *(__int64 (__fastcall **)(__int64, __int64 *))(v102 + 2056);
          if ( *((_DWORD *)v103 - 1) != -1575080629 )
            __break(0x8228u);
          v104 = v103(a1, &v181);
          if ( v104 )
            qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: send_mlo_link_recfg_complete_cmd failed %d",
              v84,
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              "mlo_link_recfg_send_complete_cmd",
              v104);
          v80 = 16;
        }
        else
        {
          qdf_trace_msg(
            0x49u,
            2u,
            "%s: tx_ops is NULL",
            v92,
            v93,
            v94,
            v95,
            v96,
            v97,
            v98,
            v99,
            "target_if_mlo_get_tx_ops");
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: tx_ops is null!",
            v105,
            v106,
            v107,
            v108,
            v109,
            v110,
            v111,
            v112,
            "mlo_link_recfg_send_complete_cmd");
          v80 = 16;
        }
        goto LABEL_67;
      }
      qdf_mem_set(s, 0x230u, 0);
      v31 = *a2;
      v32 = *((_DWORD *)a2 + 2);
      BYTE2(s[33]) = 1;
      LOBYTE(s[0]) = v31;
      v33 = *((_QWORD *)a2 + 15);
      s[13] = *((_QWORD *)a2 + 14);
      s[14] = v33;
      LOBYTE(s[33]) = v32 == 9;
      v34 = *((_QWORD *)a2 + 17);
      s[15] = *((_QWORD *)a2 + 16);
      s[16] = v34;
      v35 = *((_QWORD *)a2 + 11);
      s[9] = *((_QWORD *)a2 + 10);
      s[10] = v35;
      v36 = *((_QWORD *)a2 + 13);
      s[11] = *((_QWORD *)a2 + 12);
      s[12] = v36;
      v37 = *((_QWORD *)a2 + 7);
      s[5] = *((_QWORD *)a2 + 6);
      s[6] = v37;
      v38 = *((_QWORD *)a2 + 9);
      s[7] = *((_QWORD *)a2 + 8);
      s[8] = v38;
      v39 = *((_QWORD *)a2 + 3);
      s[1] = *((_QWORD *)a2 + 2);
      s[2] = v39;
      v40 = *((_QWORD *)a2 + 5);
      s[3] = *((_QWORD *)a2 + 4);
      s[4] = v40;
      v41 = *((_QWORD *)a2 + 31);
      s[29] = *((_QWORD *)a2 + 30);
      s[30] = v41;
      v42 = *((_QWORD *)a2 + 33);
      s[31] = *((_QWORD *)a2 + 32);
      s[32] = v42;
      v43 = *((_QWORD *)a2 + 27);
      s[25] = *((_QWORD *)a2 + 26);
      s[26] = v43;
      v44 = *((_QWORD *)a2 + 29);
      s[27] = *((_QWORD *)a2 + 28);
      s[28] = v44;
      v45 = *((_QWORD *)a2 + 23);
      s[21] = *((_QWORD *)a2 + 22);
      s[22] = v45;
      v46 = *((_QWORD *)a2 + 25);
      s[23] = *((_QWORD *)a2 + 24);
      s[24] = v46;
      v47 = *((_QWORD *)a2 + 19);
      s[17] = *((_QWORD *)a2 + 18);
      s[18] = v47;
      v48 = *((_QWORD *)a2 + 21);
      s[19] = *((_QWORD *)a2 + 20);
      s[20] = v48;
      memcpy(&s[35], a2, 0x110u);
      pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, 0, 0x6Cu);
      if ( !pdev_by_id )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Invalid pdev",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "mlo_link_recfg_update_channel_freq");
LABEL_65:
        v80 = 4;
        goto LABEL_66;
      }
      v58 = pdev_by_id;
      if ( !LOBYTE(s[16]) )
        goto LABEL_25;
      v59 = &s[2];
      entry_by_bssid = wlan_scan_get_entry_by_bssid(pdev_by_id, (unsigned __int8 *)&s[2]);
      if ( !entry_by_bssid )
      {
        v121 = (unsigned __int8 *)&s[1];
        goto LABEL_43;
      }
      v69 = entry_by_bssid;
      HIDWORD(s[1]) = *(_DWORD *)(entry_by_bssid + 1192);
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: add: freq %d link id %d %02x:%02x:%02x:**:**:%02x",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "mlo_link_recfg_update_channel_freq",
        BYTE2(s[2]),
        BYTE5(s[2]));
      v70 = *(_QWORD *)(v69 + 1320);
      if ( v70 )
        _qdf_mem_free(v70);
      v71 = *(_QWORD *)(v69 + 1896);
      if ( v71 )
        _qdf_mem_free(v71);
      _qdf_mem_free(v69);
      if ( LOBYTE(s[16]) >= 2u )
      {
        v59 = &s[7];
        v72 = wlan_scan_get_entry_by_bssid(v58, (unsigned __int8 *)&s[7]);
        if ( !v72 )
        {
          v121 = (unsigned __int8 *)&s[6];
          goto LABEL_43;
        }
        v73 = v72;
        HIDWORD(s[6]) = *(_DWORD *)(v72 + 1192);
        LODWORD(v170) = BYTE5(s[7]);
        LODWORD(v167) = BYTE2(s[7]);
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: add: freq %d link id %d %02x:%02x:%02x:**:**:%02x",
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          "mlo_link_recfg_update_channel_freq",
          v167,
          v170);
        v74 = *(_QWORD *)(v73 + 1320);
        if ( v74 )
          _qdf_mem_free(v74);
        v75 = *(_QWORD *)(v73 + 1896);
        if ( v75 )
          _qdf_mem_free(v75);
        _qdf_mem_free(v73);
        if ( LOBYTE(s[16]) >= 3u )
        {
          v59 = &s[12];
          v76 = wlan_scan_get_entry_by_bssid(v58, (unsigned __int8 *)&s[12]);
          if ( v76 )
          {
            v77 = v76;
            HIDWORD(s[11]) = *(_DWORD *)(v76 + 1192);
            LODWORD(v170) = BYTE5(s[12]);
            LODWORD(v167) = BYTE2(s[12]);
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: add: freq %d link id %d %02x:%02x:%02x:**:**:%02x",
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              "mlo_link_recfg_update_channel_freq",
              v167,
              v170);
            v78 = *(_QWORD *)(v77 + 1320);
            if ( v78 )
              _qdf_mem_free(v78);
            v79 = *(_QWORD *)(v77 + 1896);
            if ( v79 )
              _qdf_mem_free(v79);
            _qdf_mem_free(v77);
            goto LABEL_25;
          }
          v121 = (unsigned __int8 *)&s[11];
LABEL_43:
          if ( v59 )
          {
            v122 = *(unsigned __int8 *)v59;
            v123 = v121[9];
            v124 = v121[10];
            v125 = v121[13];
          }
          else
          {
            v124 = 0;
            v122 = 0;
            v123 = 0;
            v125 = 0;
          }
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: add link %02x:%02x:%02x:**:**:%02x scan entry not found",
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            "mlo_link_recfg_update_channel_freq",
            v122,
            v123,
            v124,
            v125);
          v81 = 0;
          v80 = 4;
          v82 = (unsigned int *)LOBYTE(s[32]);
          if ( !LOBYTE(s[32]) )
          {
LABEL_56:
            wlan_objmgr_pdev_release_ref(v58, 0x6Cu, v82, v50, v51, v52, v53, v54, v55, v56, v57);
            if ( (v81 & 1) != 0 )
            {
              qdf_mutex_acquire(*(_QWORD *)(v21 + 3888) + 760LL);
              v80 = wlan_sm_dispatch(
                      *(_QWORD *)(*(_QWORD *)(v21 + 3888) + 824LL),
                      1u,
                      0x230u,
                      (__int64)s,
                      v144,
                      v145,
                      v146,
                      v147,
                      v148,
                      v149,
                      v150,
                      v151);
              qdf_mutex_release(*(_QWORD *)(v21 + 3888) + 760LL);
              goto LABEL_67;
            }
LABEL_66:
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: failed to find link freq for fw link recfg ind event",
              v113,
              v114,
              v115,
              v116,
              v117,
              v118,
              v119,
              v120,
              "mlo_mgr_link_recfg_indication_event_handler");
            goto LABEL_67;
          }
LABEL_47:
          v126 = (unsigned __int8 *)&s[17];
          ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(v21, BYTE1(s[17]));
          if ( ap_link_by_link_id )
          {
            v136 = *((unsigned __int16 **)ap_link_by_link_id + 4);
            if ( !v136 )
              goto LABEL_60;
            HIDWORD(s[17]) = *v136;
            v137 = *((_WORD *)ap_link_by_link_id + 2);
            *(_DWORD *)((char *)&s[18] + 6) = *(_DWORD *)ap_link_by_link_id;
            WORD1(s[19]) = v137;
            LODWORD(v170) = BYTE5(s[18]);
            LODWORD(v167) = BYTE2(s[18]);
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: del: freq %d link id %d %02x:%02x:%02x:**:**:%02x self addr %02x:%02x:%02x:**:**:%02x",
              v128,
              v129,
              v130,
              v131,
              v132,
              v133,
              v134,
              v135,
              "mlo_link_recfg_update_channel_freq",
              v167,
              v170,
              BYTE6(s[18]),
              HIBYTE(s[18]),
              LOBYTE(s[19]),
              HIBYTE(v137));
            v82 = (unsigned int *)LOBYTE(s[32]);
            if ( LOBYTE(s[32]) < 2u )
              goto LABEL_56;
            v126 = (unsigned __int8 *)&s[22];
            v138 = mlo_mgr_get_ap_link_by_link_id(v21, BYTE1(s[22]));
            if ( !v138 )
              goto LABEL_58;
            v139 = *((unsigned __int16 **)v138 + 4);
            if ( !v139 )
            {
LABEL_60:
              if ( v126 == (unsigned __int8 *)-8LL )
              {
                v154 = 0;
                v152 = 0;
                v153 = 0;
                v155 = 0;
                v156 = "%s: del link %02x:%02x:%02x:**:**:%02x ch info not found";
              }
              else
              {
                v152 = v126[8];
                v153 = v126[9];
                v156 = "%s: del link %02x:%02x:%02x:**:**:%02x ch info not found";
                v154 = v126[10];
                v155 = v126[13];
              }
LABEL_64:
              qdf_trace_msg(
                0x8Fu,
                8u,
                v156,
                v128,
                v129,
                v130,
                v131,
                v132,
                v133,
                v134,
                v135,
                "mlo_link_recfg_update_channel_freq",
                v152,
                v153,
                v154,
                v155);
              wlan_objmgr_pdev_release_ref(v58, 0x6Cu, v157, v158, v159, v160, v161, v162, v163, v164, v165);
              goto LABEL_65;
            }
            HIDWORD(s[22]) = *v139;
            v140 = *((_WORD *)v138 + 2);
            LODWORD(v171) = BYTE5(s[23]);
            *(_DWORD *)((char *)&s[23] + 6) = *(_DWORD *)v138;
            WORD1(s[24]) = v140;
            LODWORD(v173) = BYTE6(s[23]);
            LODWORD(v175) = HIBYTE(s[23]);
            LODWORD(v179) = HIBYTE(v140);
            LODWORD(v177) = LOBYTE(s[24]);
            LODWORD(v168) = BYTE2(s[23]);
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: del: freq %d link id %d %02x:%02x:%02x:**:**:%02x self addr %02x:%02x:%02x:**:**:%02x",
              v128,
              v129,
              v130,
              v131,
              v132,
              v133,
              v134,
              v135,
              "mlo_link_recfg_update_channel_freq",
              v168,
              v171,
              v173,
              v175,
              v177,
              v179);
            v82 = (unsigned int *)LOBYTE(s[32]);
            if ( LOBYTE(s[32]) < 3u )
              goto LABEL_56;
            v126 = (unsigned __int8 *)&s[27];
            v141 = mlo_mgr_get_ap_link_by_link_id(v21, BYTE1(s[27]));
            if ( v141 )
            {
              v142 = *((unsigned __int16 **)v141 + 4);
              if ( v142 )
              {
                HIDWORD(s[27]) = *v142;
                v143 = *((_WORD *)v141 + 2);
                LODWORD(v172) = BYTE5(s[28]);
                *(_DWORD *)((char *)&s[28] + 6) = *(_DWORD *)v141;
                WORD1(s[29]) = v143;
                LODWORD(v174) = BYTE6(s[28]);
                LODWORD(v176) = HIBYTE(s[28]);
                LODWORD(v180) = HIBYTE(v143);
                LODWORD(v178) = LOBYTE(s[29]);
                LODWORD(v169) = BYTE2(s[28]);
                qdf_trace_msg(
                  0x8Fu,
                  8u,
                  "%s: del: freq %d link id %d %02x:%02x:%02x:**:**:%02x self addr %02x:%02x:%02x:**:**:%02x",
                  v128,
                  v129,
                  v130,
                  v131,
                  v132,
                  v133,
                  v134,
                  v135,
                  "mlo_link_recfg_update_channel_freq",
                  v169,
                  v172,
                  v174,
                  v176,
                  v178,
                  v180);
                goto LABEL_56;
              }
              goto LABEL_60;
            }
          }
LABEL_58:
          if ( v126 == (unsigned __int8 *)-8LL )
          {
            v154 = 0;
            v152 = 0;
            v153 = 0;
            v155 = 0;
          }
          else
          {
            v152 = v126[8];
            v153 = v126[9];
            v154 = v126[10];
            v155 = v126[13];
          }
          v156 = "%s: del link %02x:%02x:%02x:**:**:%02x link info not found";
          goto LABEL_64;
        }
      }
LABEL_25:
      v80 = 0;
      v81 = 1;
      v82 = (unsigned int *)LOBYTE(s[32]);
      if ( !LOBYTE(s[32]) )
        goto LABEL_56;
      goto LABEL_47;
    }
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Invalid link recfg VDEV %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlo_mgr_link_recfg_indication_event_handler",
      *a2);
    v80 = 4;
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Invalid params",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "mlo_mgr_link_recfg_indication_event_handler");
    v80 = 4;
  }
LABEL_68:
  _ReadStatusReg(SP_EL0);
  return v80;
}
