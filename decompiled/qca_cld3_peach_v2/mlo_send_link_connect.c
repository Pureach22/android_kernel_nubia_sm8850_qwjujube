__int64 __fastcall mlo_send_link_connect(
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
  __int64 v11; // x19
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 cmpt_obj; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  size_t v30; // x2
  __int64 v31; // x8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 *v40; // x1
  __int64 result; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x25
  __int64 v51; // x28
  unsigned int v52; // w20
  unsigned int *v53; // x8
  __int64 v54; // x27
  __int64 v55; // x21
  unsigned int v56; // w23
  __int64 ap_link_by_link_id; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x26
  int v67; // w8
  __int64 v68; // x9
  const char *v69; // x2
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned __int8 *v78; // x20
  int v79; // w23
  int v80; // w26
  int v81; // w19
  __int16 v82; // w25
  int v83; // w24
  unsigned __int8 v84; // w21
  int v85; // w20
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x8
  __int64 v95; // x20
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  const void *v104; // x1
  unsigned int v105; // w20
  _QWORD *v106; // x9
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  int v115; // w9
  __int64 v116; // x1
  __int64 v117; // x10
  __int64 v118; // x10
  __int64 v119; // x9
  __int64 v120; // x0
  __int64 v121; // x21
  int v122; // w8
  int v123; // w4
  unsigned int *v124; // x8
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  __int64 v133; // [xsp+0h] [xbp-4D0h]
  __int64 v134; // [xsp+8h] [xbp-4C8h]
  __int64 v135; // [xsp+10h] [xbp-4C0h]
  __int64 v136; // [xsp+18h] [xbp-4B8h]
  __int64 v137; // [xsp+20h] [xbp-4B0h]
  __int64 v138; // [xsp+28h] [xbp-4A8h]
  __int64 v139; // [xsp+30h] [xbp-4A0h]
  int v140; // [xsp+3Ch] [xbp-494h]
  __int64 v141; // [xsp+48h] [xbp-488h]
  __int64 v142; // [xsp+50h] [xbp-480h]
  __int64 v143; // [xsp+58h] [xbp-478h]
  int v144; // [xsp+60h] [xbp-470h]
  __int64 v145; // [xsp+68h] [xbp-468h]
  unsigned int v146; // [xsp+74h] [xbp-45Ch]
  unsigned int v147; // [xsp+78h] [xbp-458h]
  unsigned __int16 v148; // [xsp+7Ch] [xbp-454h] BYREF
  size_t n[4]; // [xsp+80h] [xbp-450h] BYREF
  char v150; // [xsp+A0h] [xbp-430h]
  _QWORD v151[2]; // [xsp+A8h] [xbp-428h] BYREF
  size_t v152; // [xsp+B8h] [xbp-418h] BYREF
  size_t v153; // [xsp+C0h] [xbp-410h]
  size_t v154; // [xsp+C8h] [xbp-408h]
  size_t v155; // [xsp+D0h] [xbp-400h]
  char v156; // [xsp+D8h] [xbp-3F8h]
  _QWORD s[126]; // [xsp+E0h] [xbp-3F0h] BYREF

  v11 = a1;
  s[124] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 1360);
  v156 = 0;
  v154 = 0;
  v155 = 0;
  v152 = 0;
  v153 = 0;
  v148 = 0;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: Sending link connect on partner interface",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "mlo_send_link_connect");
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v11, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !cmpt_obj )
  {
LABEL_4:
    if ( *(_BYTE *)(a2 + 160) )
      goto LABEL_5;
LABEL_74:
    result = qdf_trace_msg(
               0x8Fu,
               2u,
               "%s: No partner info in connect resp",
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               "mlo_send_link_connect");
    goto LABEL_75;
  }
  v30 = *(unsigned __int8 *)(cmpt_obj + 178);
  if ( *(_BYTE *)(cmpt_obj + 178) )
  {
    LOBYTE(v152) = *(_BYTE *)(cmpt_obj + 178);
    qdf_mem_copy((char *)&v152 + 1, (const void *)(cmpt_obj + 145), v30);
    goto LABEL_4;
  }
  LOBYTE(v152) = 0;
  if ( !*(_BYTE *)(a2 + 160) )
    goto LABEL_74;
LABEL_5:
  if ( (*(_BYTE *)(v11 + 60) & 2) != 0 )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64))mlo_mgr_find_and_clear_rejected_links)(
               v11,
               15,
               a2 + 160);
  }
  else
  {
    qdf_mutex_acquire(*(_QWORD *)(v12 + 2224) + 40LL);
    v31 = *(_QWORD *)(v12 + 2224);
    if ( !*(_QWORD *)(v31 + 32) )
    {
      *(_QWORD *)(*(_QWORD *)(v12 + 2224) + 32LL) = _qdf_mem_malloc(0x3E0u, "mlo_send_link_connect", 1070);
      v31 = *(_QWORD *)(v12 + 2224);
      v40 = *(__int64 **)(v31 + 32);
      if ( v40 )
      {
        wlan_cm_get_active_connect_req_param(v11, v40, v32, v33, v34, v35, v36, v37, v38, v39);
        v31 = *(_QWORD *)(v12 + 2224);
      }
    }
    v151[0] = 0;
    v151[1] = 0;
    qdf_mutex_release(v31 + 40);
    result = mlo_sta_get_vdev_list(v11, &v148, v151);
    v146 = v148;
    if ( v148 )
    {
      v50 = v12 + 24;
      v145 = a2 + 168;
      v51 = 0;
      v138 = a2 + 264;
      v139 = a2 + 216;
      v52 = 0;
      v141 = v12 + 24;
      v140 = 2;
      v142 = a2;
      v143 = v11;
      while ( 1 )
      {
        if ( v51 == 2 )
        {
LABEL_76:
          __break(0x5512u);
          __break(1u);
        }
        v53 = (unsigned int *)v151;
        v54 = v151[v51];
        if ( v54 == v11 )
          goto LABEL_53;
        if ( v52 > 2 )
          goto LABEL_76;
        if ( !v54 )
        {
          v69 = "%s: Vdev is null";
LABEL_29:
          qdf_trace_msg(0x8Fu, 2u, v69, v42, v43, v44, v45, v46, v47, v48, v49, "mlo_mgr_is_link_rejected");
          goto LABEL_30;
        }
        v55 = *(_QWORD *)(v54 + 1360);
        if ( !v55 )
        {
          v69 = "%s: ml dev ctx is null";
          goto LABEL_29;
        }
        v56 = *(unsigned __int8 *)(v54 + 168);
        ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(
                               *(_QWORD *)(v54 + 1360),
                               *(unsigned __int8 *)(v145 + 48LL * v52 + 6));
        if ( ap_link_by_link_id )
        {
          v66 = ap_link_by_link_id;
          if ( *(_DWORD *)(ap_link_by_link_id + 44) )
          {
            if ( *(unsigned __int8 *)(ap_link_by_link_id + 12) != 255 )
              break;
          }
        }
LABEL_30:
        wlan_vdev_mlme_set_mlo_vdev(*(_QWORD *)(v50 + 8 * v51), v58, v59, v60, v61, v62, v63, v64, v65);
        wlan_vdev_mlme_set_mlo_link_vdev(*(_QWORD *)(v50 + 8 * v51), v70, v71, v72, v73, v74, v75, v76, v77);
        v147 = v52;
        v78 = (unsigned __int8 *)(v145 + 48LL * v52);
        *(_BYTE *)(v54 + 93) = v78[6];
        v78[12] = *(_BYTE *)(*(_QWORD *)(v50 + 8 * v51) + 168LL);
        wlan_crypto_free_vdev_key(v54);
        v79 = *v78;
        v80 = v78[1];
        v81 = v78[2];
        n[2] = v154;
        n[3] = v155;
        v82 = *(_WORD *)(v78 + 3);
        v83 = v78[5];
        v84 = v78[6];
        v85 = *((unsigned __int16 *)v78 + 5);
        v150 = v156;
        n[0] = v152;
        n[1] = v153;
        memset(s, 0, 0x3E0u);
        v94 = *(_QWORD *)(v54 + 1360);
        if ( v94 )
        {
          v144 = v85;
          v95 = *(_QWORD *)(v94 + 2224);
          LODWORD(v136) = v83;
          LODWORD(v137) = *(unsigned __int8 *)(v54 + 168);
          LODWORD(v135) = v81;
          LODWORD(v134) = v80;
          LODWORD(v133) = v79;
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: Partner link connect mac:%02x:%02x:%02x:**:**:%02x bssid:%02x:%02x:%02x:**:**:%02x vdev_id:%d",
            v86,
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            "mlo_prepare_and_send_connect",
            *(unsigned __int8 *)(v54 + 74),
            *(unsigned __int8 *)(v54 + 75),
            *(unsigned __int8 *)(v54 + 76),
            *(unsigned __int8 *)(v54 + 79),
            v133,
            v134,
            v135,
            v136,
            v137);
          v104 = *(const void **)(v95 + 32);
          if ( v104 )
            qdf_mem_copy(s, v104, 0x3E0u);
          else
            qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: Invalid copied_conn_req",
              v96,
              v97,
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              "mlo_prepare_and_send_connect");
          BYTE5(s[1]) = v83;
          BYTE2(s[7]) = v83;
          a2 = v142;
          BYTE2(s[1]) = v81;
          HIBYTE(s[6]) = v81;
          *(_QWORD *)((char *)&s[7] + 4) = 0;
          LOBYTE(s[1]) = v79;
          BYTE1(s[1]) = v80;
          *(_WORD *)((char *)&s[1] + 3) = v82;
          BYTE5(s[6]) = v79;
          BYTE6(s[6]) = v80;
          LOWORD(s[7]) = v82;
          qdf_mem_copy(&s[102], (const void *)(v142 + 160), 0xB0u);
          LOBYTE(s[0]) = *(_BYTE *)(v54 + 168);
          HIDWORD(s[7]) = v144;
          BYTE1(s[101]) = v84;
          BYTE4(s[2]) = n[0];
          qdf_mem_copy((char *)&s[2] + 5, (char *)n + 1, LOBYTE(n[0]));
          v115 = *(_DWORD *)(v142 + 153);
          HIWORD(s[101]) = *(_WORD *)(v142 + 157);
          *(_DWORD *)((char *)&s[101] + 2) = v115;
          v116 = *(_QWORD *)(v95 + 32);
          if ( v116 )
            mlo_allocate_and_copy_ies(s, v116);
          v11 = v143;
          v50 = v141;
          if ( s[20] )
          {
            if ( s[22] )
              goto LABEL_40;
LABEL_47:
            qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: Failed to allocate scan IEs",
              v107,
              v108,
              v109,
              v110,
              v111,
              v112,
              v113,
              v114,
              "mlo_prepare_and_send_connect");
          }
          else
          {
            qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: Failed to allocate assoc IEs",
              v107,
              v108,
              v109,
              v110,
              v111,
              v112,
              v113,
              v114,
              "mlo_prepare_and_send_connect");
            if ( !s[22] )
              goto LABEL_47;
          }
LABEL_40:
          HIDWORD(s[9]) = 0;
          wlan_cm_start_connect(v54, (__int64)s);
          wlan_cm_free_connect_req_param((__int64)s);
          v105 = v147;
          v106 = *(_QWORD **)(v54 + 1360);
          if ( !v106 )
            goto LABEL_52;
          goto LABEL_41;
        }
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: ML dev ctx is NULL",
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          "mlo_prepare_and_send_connect");
        a2 = v142;
        v11 = v143;
        v105 = v147;
        v50 = v141;
        v106 = *(_QWORD **)(v54 + 1360);
        if ( !v106 )
          goto LABEL_52;
LABEL_41:
        v53 = (unsigned int *)v106[278];
        if ( v53 )
        {
          v117 = v106[3];
          if ( !v117 || v117 != v54 )
          {
            v119 = v106[4];
            if ( !v119 || v119 != v54 )
              goto LABEL_52;
            v118 = *((_QWORD *)v53 + 1);
LABEL_51:
            *((_QWORD *)v53 + 1) = v118 | 2;
            goto LABEL_52;
          }
          v118 = *((_QWORD *)v53 + 1) | 1LL;
          *((_QWORD *)v53 + 1) = v118;
          if ( v106[4] == v54 )
            goto LABEL_51;
        }
LABEL_52:
        v52 = v105 + 1;
LABEL_53:
        result = mlo_release_vdev_ref(v54, v53, v42, v43, v44, v45, v46, v47, v48, v49);
LABEL_54:
        if ( v146 <= (unsigned __int16)++v51 )
          goto LABEL_75;
      }
      v67 = *(unsigned __int8 *)(a2 + 160);
      if ( *(_BYTE *)(a2 + 160) )
      {
        v68 = v145;
        if ( !*(_DWORD *)(a2 + 212) )
          goto LABEL_56;
        if ( v67 != 1 )
        {
          v68 = v139;
          if ( !*(_DWORD *)(a2 + 260) )
            goto LABEL_56;
          if ( v67 != 2 )
          {
            v68 = v138;
            if ( *(_DWORD *)(a2 + 308) )
            {
              if ( v67 != 3 )
                goto LABEL_76;
              goto LABEL_69;
            }
LABEL_56:
            v120 = mlo_mgr_get_ap_link_by_link_id(v55, *(unsigned __int8 *)(v68 + 6));
            if ( v120 )
            {
              v121 = v120;
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: Rejected link id %d vdev id %d Accepted link id %d vdev id %d",
                v58,
                v59,
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                "mlo_mgr_is_link_rejected",
                *(unsigned __int8 *)(v66 + 6),
                v56,
                *(unsigned __int8 *)(v120 + 6),
                *(unsigned __int8 *)(v120 + 12));
              mlo_mgr_link_rejection_handler(v54, v66, v121, 1);
              v122 = *(unsigned __int8 *)(a2 + 160);
              if ( !*(_BYTE *)(a2 + 160) )
                goto LABEL_70;
              if ( *(_DWORD *)(a2 + 212) )
              {
                if ( v122 == 1 )
                  goto LABEL_70;
                if ( *(_DWORD *)(a2 + 260) )
                {
                  if ( v122 == 2 )
                    goto LABEL_70;
                  if ( *(_DWORD *)(a2 + 308) )
                  {
                    if ( v122 != 3 )
                      goto LABEL_76;
LABEL_70:
                    qdf_trace_msg(
                      0x8Fu,
                      8u,
                      "%s: Valid link not found",
                      v58,
                      v59,
                      v60,
                      v61,
                      v62,
                      v63,
                      v64,
                      v65,
                      "mlo_send_link_connect");
                    result = mlo_release_vdev_ref(v54, v124, v125, v126, v127, v128, v129, v130, v131, v132);
                    v140 = 2;
                    goto LABEL_54;
                  }
                  v123 = 2;
                }
                else
                {
                  v123 = 1;
                }
              }
              else
              {
                v123 = 0;
              }
              v140 = v123;
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: valid idx %d",
                v58,
                v59,
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                "mlo_mgr_find_valid_partner_link_info_idx");
            }
          }
        }
      }
LABEL_69:
      if ( v140 == 2 )
        goto LABEL_70;
      v52 = v140;
      qdf_trace_msg(0x8Fu, 8u, "%s: Valid idx %d", v58, v59, v60, v61, v62, v63, v64, v65, "mlo_send_link_connect");
      goto LABEL_30;
    }
  }
LABEL_75:
  _ReadStatusReg(SP_EL0);
  return result;
}
