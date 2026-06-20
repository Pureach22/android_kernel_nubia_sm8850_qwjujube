__int64 __fastcall cm_csr_connect_rsp(
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
  int v10; // w8
  unsigned int v11; // w21
  __int64 result; // x0
  _QWORD *context; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  __int64 v25; // x23
  _QWORD *v26; // x20
  __int64 v27; // x8
  int v28; // w8
  _QWORD *v29; // x9
  __int64 v30; // x0
  __int64 v31; // x0
  unsigned int v32; // w22
  int v33; // w10
  unsigned int v34; // w21
  unsigned int v35; // w9
  char *v36; // x0
  char *v37; // x22
  size_t v38; // x2
  char *v39; // x21
  __int64 v40; // x9
  size_t v41; // x2
  char *v42; // x21
  __int64 v43; // x9
  size_t v44; // x2
  char *v45; // x21
  __int64 v46; // x9
  size_t v47; // x2
  char v48; // w8
  unsigned int v49; // w21
  __int64 v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int16 v59; // w10
  _BYTE *v60; // x23
  int v61; // w8
  __int64 cmpt_obj; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  _QWORD *v71; // x9
  size_t v72; // x2
  _QWORD *scan_result; // x22
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x26
  __int64 v83; // x0
  __int64 v84; // x23
  __int64 v85; // x0
  int v86; // w8
  __int64 v87; // x0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 v96; // x24
  __int64 v97; // x8
  size_t v98; // x0
  void *v99; // x0
  char v100; // w9
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x27
  char is_ese_connection; // w0
  __int64 v111; // [xsp+0h] [xbp-90h] BYREF
  __int64 v112; // [xsp+8h] [xbp-88h]
  __int64 v113; // [xsp+10h] [xbp-80h]
  __int64 v114; // [xsp+18h] [xbp-78h]
  _QWORD v115[4]; // [xsp+20h] [xbp-70h] BYREF
  __int64 v116; // [xsp+40h] [xbp-50h] BYREF
  __int64 v117; // [xsp+48h] [xbp-48h]
  _BYTE *v118; // [xsp+50h] [xbp-40h] BYREF
  __int64 v119; // [xsp+58h] [xbp-38h] BYREF
  _QWORD v120[4]; // [xsp+60h] [xbp-30h] BYREF
  __int16 v121; // [xsp+84h] [xbp-Ch] BYREF
  char v122; // [xsp+86h] [xbp-Ah]
  __int64 v123; // [xsp+88h] [xbp-8h]

  v123 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(a2 + 60);
  v11 = *(unsigned __int8 *)(a1 + 168);
  v113 = 0;
  v114 = 0;
  v111 = 0;
  v112 = 0;
  if ( !v10 )
  {
    context = _cds_get_context(52, (__int64)"cm_csr_connect_rsp", a3, a4, a5, a6, a7, a8, a9, a10);
    if ( context )
    {
      if ( v11 <= 5 )
      {
        v24 = context[2162];
        v25 = v24 + 96LL * v11;
        if ( v25 )
        {
          if ( v24 && (*(_BYTE *)(v24 + 96LL * v11 + 1) & 1) != 0 )
          {
            v26 = context;
            v27 = a2;
            if ( (*(_BYTE *)(a2 + 9) & 4) == 0 )
            {
              if ( *(_BYTE *)(a2 + 377) )
              {
                sme_ps_start_uapsd(context, v11, v16, v17, v18, v19, v20, v21, v22, v23);
                v28 = *(unsigned __int8 *)(a2 + 377);
                v29 = v26;
              }
              else
              {
                v29 = context;
                v28 = 0;
              }
              v30 = v29[2703];
              LODWORD(v111) = v28;
              wlan_cm_roam_cfg_set_value(v30, v11, 0x13u, (unsigned int *)&v111);
              v27 = a2;
            }
            v31 = *(_QWORD *)(v25 + 32);
            *(_BYTE *)(v25 + 61) = *(_BYTE *)(v27 + 376);
            if ( v31 )
            {
              _qdf_mem_free(v31);
              v27 = a2;
              *(_QWORD *)(v25 + 32) = 0;
            }
            *(_DWORD *)(v25 + 24) = 0;
            *(_QWORD *)(v25 + 8) = 0;
            *(_QWORD *)(v25 + 16) = 0;
            v32 = *(_DWORD *)(v27 + 80);
            v33 = *(_DWORD *)(v27 + 360);
            if ( v32 >= 0x18 )
              v34 = v32 - 24;
            else
              v34 = 0;
            v35 = v34 + *(_DWORD *)(v27 + 112) + *(_DWORD *)(v27 + 128) + *(_DWORD *)(v27 + 344);
            if ( v35 + v33 )
            {
              v36 = (char *)_qdf_mem_malloc(v35 + v33, "csr_fill_connected_info", 5471);
              v27 = a2;
              *(_QWORD *)(v25 + 32) = v36;
              if ( v36 )
              {
                *(_DWORD *)(v25 + 8) = v34;
                if ( v32 >= 0x19 )
                {
                  v37 = v36;
                  qdf_mem_copy(v36, (const void *)(*(_QWORD *)(a2 + 88) + 24LL), v34);
                  v36 = v37;
                  v27 = a2;
                }
                v38 = *(unsigned int *)(v27 + 112);
                v39 = &v36[v34];
                *(_DWORD *)(v25 + 12) = v38;
                if ( (_DWORD)v38 )
                {
                  qdf_mem_copy(v39, *(const void **)(v27 + 120), v38);
                  v40 = *(unsigned int *)(a2 + 112);
                  v27 = a2;
                }
                else
                {
                  v40 = 0;
                }
                v41 = *(unsigned int *)(v27 + 128);
                v42 = &v39[v40];
                *(_DWORD *)(v25 + 16) = v41;
                if ( (_DWORD)v41 )
                {
                  qdf_mem_copy(v42, *(const void **)(v27 + 136), v41);
                  v43 = *(unsigned int *)(a2 + 128);
                  v27 = a2;
                }
                else
                {
                  v43 = 0;
                }
                v44 = *(unsigned int *)(v27 + 344);
                v45 = &v42[v43];
                *(_DWORD *)(v25 + 20) = v44;
                if ( (_DWORD)v44 )
                {
                  qdf_mem_copy(v45, *(const void **)(v27 + 352), v44);
                  v46 = *(unsigned int *)(a2 + 344);
                  v27 = a2;
                }
                else
                {
                  v46 = 0;
                }
                v47 = *(unsigned int *)(v27 + 360);
                *(_DWORD *)(v25 + 24) = v47;
                if ( (_DWORD)v47 )
                {
                  qdf_mem_copy(&v45[v46], *(const void **)(v27 + 368), v47);
                  v27 = a2;
                }
              }
            }
            v48 = *(_BYTE *)(v27 + 377);
            v49 = *(unsigned __int8 *)(a1 + 168);
            v118 = nullptr;
            v119 = 0;
            v116 = 0;
            v117 = 0;
            memset(v115, 0, sizeof(v115));
            v122 = 0;
            v121 = 0;
            *(_BYTE *)(v25 + 40) = v48;
            v50 = _qdf_mem_malloc(0x2D8u, "csr_fill_connected_profile", 5634);
            if ( v50 )
            {
              v59 = *(_WORD *)v50;
              v60 = (_BYTE *)v50;
              *(_BYTE *)(v50 + 16) = 1;
              v61 = *(_DWORD *)(a2 + 16);
              *(_WORD *)(v50 + 74) = *(_WORD *)(a2 + 20);
              *(_DWORD *)(v50 + 70) = v61;
              *(_WORD *)v50 = v59 | 8;
              cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, v51, v52, v53, v54, v55, v56, v57, v58);
              v71 = v26;
              if ( cmpt_obj )
              {
                v72 = *(unsigned __int8 *)(cmpt_obj + 178);
                if ( *(_BYTE *)(cmpt_obj + 178) )
                {
                  v60[100] = v72;
                  qdf_mem_copy(v60 + 101, (const void *)(cmpt_obj + 145), v72);
                  v71 = v26;
                  v60[17] = 1;
                }
                else
                {
                  v60[100] = 0;
                }
              }
              scan_result = scm_get_scan_result(v71[2704], (__int64)v60, v63, v64, v65, v66, v67, v68, v69, v70);
              _qdf_mem_free((__int64)v60);
              if ( scan_result )
              {
                if ( *((_DWORD *)scan_result + 4) )
                {
                  qdf_list_peek_front(scan_result, &v119);
                  v82 = v119;
                  if ( v119 )
                  {
                    v83 = _qdf_mem_malloc(
                            (unsigned __int16)(*(_WORD *)(*(_QWORD *)(v119 + 24) + 1888LL) + 68),
                            "csr_fill_connected_profile",
                            5661);
                    if ( v83 )
                    {
                      v84 = v83;
                      wlan_fill_bss_desc_from_scan_entry((__int64)v26, v83, *(_QWORD *)(v82 + 24));
                      v85 = v26[2703];
                      LODWORD(v115[0]) = *(_DWORD *)(v84 + 92);
                      wlan_cm_roam_cfg_set_value(v85, v49, 0x18u, (unsigned int *)v115);
                      v86 = *(_DWORD *)(v84 + 96);
                      v87 = v26[2703];
                      v120[2] = 0;
                      v120[3] = 0;
                      v120[0] = 0;
                      v120[1] = v86 != 0;
                      wlan_cm_roam_cfg_set_value(v87, v49, 0x19u, (unsigned int *)v120);
                      if ( !(unsigned int)wlan_get_parsed_bss_description_ies(
                                            (__int64)v26,
                                            (unsigned __int16 *)v84,
                                            (__int64 *)&v118) )
                      {
                        if ( !*(_WORD *)(v84 + 16) )
                          qdf_trace_msg(
                            0x34u,
                            2u,
                            "%s: ERROR: Beacon interval is ZERO",
                            v88,
                            v89,
                            v90,
                            v91,
                            v92,
                            v93,
                            v94,
                            v95,
                            "csr_fill_connected_profile");
                        v96 = *(_QWORD *)(v82 + 24);
                        v97 = a2;
                        if ( v96 )
                        {
                          if ( !*(_QWORD *)(a2 + 88) )
                          {
                            v98 = *(unsigned int *)(v96 + 1888);
                            *(_DWORD *)(a2 + 80) = v98;
                            v99 = (void *)_qdf_mem_malloc(v98, "csr_update_beacon_in_connect_rsp", 5593);
                            v97 = a2;
                            *(_QWORD *)(a2 + 88) = v99;
                            if ( v99 )
                            {
                              qdf_mem_copy(v99, *(const void **)(v96 + 1896), *(unsigned int *)(a2 + 80));
                              v97 = a2;
                            }
                          }
                        }
                        v100 = *(_BYTE *)(v97 + 9);
                        v116 = v84;
                        if ( (v100 & 4) != 0 )
                        {
                          v109 = v97;
                          is_ese_connection = cm_is_ese_connection(
                                                a1,
                                                v118[3449] != 0,
                                                v88,
                                                v89,
                                                v90,
                                                v91,
                                                v92,
                                                v93,
                                                v94,
                                                v95);
                          wlan_cm_set_ese_assoc(v26[2704], v49, is_ese_connection & 1);
                          wlan_cm_roam_cfg_get_value(v26[2703], v49, 0x13u, v115);
                          LOBYTE(v117) = v115[0];
                          csr_qos_send_reassoc_ind(v26, v49, &v116, v109 + 8);
                          if ( LODWORD(v115[0]) )
                            sme_ps_start_uapsd(v26, v49, v101, v102, v103, v104, v105, v106, v107, v108);
                        }
                        else
                        {
                          LOBYTE(v117) = *(_BYTE *)(v97 + 377);
                          sme_qos_csr_event_ind(v26, v49, 1, &v116);
                        }
                        if ( (*(_BYTE *)(a2 + 9) & 4) != 0 || (mlo_mgr_is_link_switch_in_progress(a1) & 1) != 0 )
                          mlme_set_mbssid_info(
                            a1,
                            (unsigned __int8 *)(*(_QWORD *)(v82 + 24) + 112LL),
                            *(_DWORD *)(v84 + 28),
                            v101,
                            v102,
                            v103,
                            v104,
                            v105,
                            v106,
                            v107,
                            v108);
                        if ( v118[322] )
                          qdf_mem_copy(&v121, v118 + 323, 3u);
                        else
                          qdf_mem_set(&v121, 3u, 0);
                        wlan_cm_set_country_code(v26[2704], v49, (unsigned __int8 *)&v121);
                        _qdf_mem_free((__int64)v118);
                      }
                      _qdf_mem_free(v84);
                    }
                  }
                }
                scm_purge_scan_results((__int64)scan_result, v74, v75, v76, v77, v78, v79, v80, v81);
              }
            }
            goto LABEL_2;
          }
        }
      }
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: session not found for vdev_id %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "cm_csr_connect_rsp",
        v11,
        v111,
        v112,
        v113,
        v114);
    }
    result = 4;
    goto LABEL_13;
  }
LABEL_2:
  result = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
