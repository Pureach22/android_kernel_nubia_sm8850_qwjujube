__int64 __fastcall mlo_roam_prepare_and_send_link_connect_req(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 *a4)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x8
  __int64 v17; // x24
  __int64 cmpt_obj; // x0
  size_t v19; // x2
  __int64 result; // x0
  unsigned __int8 v21; // w10
  char v22; // w8
  int v23; // w9
  __int16 v24; // w10
  __int16 v25; // w10
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 rso_config_fl; // x0
  __int64 v35; // x23
  int v36; // w8
  size_t v37; // x0
  void *v38; // x0
  size_t v39; // x2
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x7
  int v49; // w8
  int v50; // w9
  int v51; // w10
  __int64 v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  void *v61; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x22
  __int64 v71; // x23
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned int started; // w20
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  void *v89; // x0
  void *v90; // x0
  __int64 v91; // x20
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  char is_internal_disconnect; // w0
  char v117; // w0
  __int64 v118; // x0
  size_t v119; // x0
  void *v120; // x0
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  const void *v129; // x1
  _QWORD *v130; // x9
  __int64 v131; // x8
  __int64 v132; // x10
  __int64 v133; // x9
  void *v134; // x0
  _QWORD *v135; // x9
  __int64 v136; // x8
  __int64 v137; // x10
  __int64 v138; // x9
  size_t n[4]; // [xsp+70h] [xbp-410h] BYREF
  char v140; // [xsp+90h] [xbp-3F0h]
  __int64 s[125]; // [xsp+98h] [xbp-3E8h] BYREF

  s[124] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x3E0u);
  v16 = *(_QWORD *)(a1 + 1360);
  v140 = 0;
  memset(n, 0, sizeof(n));
  if ( v16 && (v17 = *(_QWORD *)(v16 + 2224)) != 0 )
  {
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, v8, v9, v10, v11, v12, v13, v14, v15);
    if ( cmpt_obj )
    {
      v19 = *(unsigned __int8 *)(cmpt_obj + 178);
      if ( *(_BYTE *)(cmpt_obj + 178) )
      {
        LOBYTE(n[0]) = *(_BYTE *)(cmpt_obj + 178);
        qdf_mem_copy((char *)n + 1, (const void *)(cmpt_obj + 145), v19);
      }
      else
      {
        LOBYTE(n[0]) = 0;
      }
    }
    v21 = a4[6];
    v22 = *(_BYTE *)(a2 + 168);
    HIDWORD(s[7]) = *((unsigned __int16 *)a4 + 5);
    v23 = *(_DWORD *)a4;
    BYTE1(s[101]) = v21;
    v24 = *((_WORD *)a4 + 2);
    LOBYTE(s[0]) = v22;
    HIDWORD(s[0]) = 14;
    LODWORD(s[1]) = v23;
    WORD2(s[1]) = v24;
    *(_DWORD *)((char *)&s[6] + 5) = v23;
    *(_WORD *)((char *)&s[7] + 1) = v24;
    BYTE4(s[2]) = n[0];
    qdf_mem_copy((char *)&s[2] + 5, (char *)n + 1, LOBYTE(n[0]));
    v25 = *(_WORD *)(a3 + 157);
    *(_DWORD *)((char *)&s[101] + 2) = *(_DWORD *)(a3 + 153);
    HIWORD(s[101]) = v25;
    memcpy(&s[102], (const void *)(a3 + 160), 0xB0u);
    rso_config_fl = wlan_cm_get_rso_config_fl(
                      a1,
                      (__int64)"mlo_roam_prepare_and_send_link_connect_req",
                      0x563u,
                      v26,
                      v27,
                      v28,
                      v29,
                      v30,
                      v31,
                      v32,
                      v33);
    if ( !rso_config_fl )
    {
LABEL_12:
      mlme_cm_osif_roam_get_scan_params();
      if ( a4 )
      {
        v48 = *a4;
        v49 = a4[1];
        v50 = a4[2];
        v51 = a4[5];
      }
      else
      {
        v50 = 0;
        v48 = 0;
        v49 = 0;
        v51 = 0;
      }
      qdf_trace_msg(
        0x68u,
        4u,
        "%s: vdev:%d Connecting to %.*s link_addr: %02x:%02x:%02x:**:**:%02x freq %d rsn_caps:0x%x auth_type:0x%x pairwis"
        "e:0x%x grp:0x%x mcast:0x%x akms:0x%x assoc_ie_len:%d f_rsne:%d is_wps:%d dot11_filter:%d",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "mlo_roam_prepare_and_send_link_connect_req",
        LOBYTE(s[0]),
        BYTE4(s[2]),
        (char *)&s[2] + 5,
        v48,
        v49,
        v50,
        v51,
        HIDWORD(s[7]),
        LOWORD(s[15]),
        HIDWORD(s[9]),
        HIDWORD(s[10]),
        LODWORD(s[10]),
        HIDWORD(s[15]),
        LODWORD(s[11]),
        LODWORD(s[19]),
        s[23] & 1,
        (LOBYTE(s[23]) >> 1) & 1,
        HIDWORD(s[23]));
      qdf_mutex_acquire(v17 + 40);
      v52 = *(_QWORD *)(v17 + 32);
      if ( v52 )
      {
        wlan_cm_free_connect_req_param(v52);
        v61 = *(void **)(v17 + 32);
        if ( v61 )
        {
LABEL_17:
          qdf_mem_copy(v61, s, 0x3E0u);
          *(_DWORD *)(*(_QWORD *)(v17 + 32) + 60LL) = 0;
          mlo_allocate_and_copy_ies(*(_QWORD **)(v17 + 32), (__int64)s);
          qdf_mutex_release(v17 + 40);
          v70 = *(_QWORD *)(a1 + 1360);
          if ( !v70 )
          {
            v91 = jiffies;
            if ( mlo_roam_validate_req___last_ticks_66 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: mlo_dev_ctx is NULL",
                v62,
                v63,
                v64,
                v65,
                v66,
                v67,
                v68,
                v69,
                "mlo_roam_validate_req");
              mlo_roam_validate_req___last_ticks_66 = v91;
            }
            started = 29;
            goto LABEL_79;
          }
          v71 = *(_QWORD *)(v70 + 2224);
          if ( v71 && *(_QWORD *)(v71 + 280) )
          {
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: Handle pending disconnect for vdev %d",
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              "mlo_roam_validate_req",
              *(unsigned __int8 *)(a1 + 168));
            mlo_handle_pending_disconnect(a1, v72, v73, v74, v75, v76, v77, v78, v79);
            started = 16;
LABEL_79:
            _qdf_mem_free(s[20]);
            result = started;
            goto LABEL_80;
          }
          if ( wlan_cm_is_vdev_disconnected(a1, v62, v63, v64, v65, v66, v67, v68, v69) )
            goto LABEL_25;
          if ( (*(_BYTE *)(a2 + 60) & 2) == 0 )
            goto LABEL_35;
          if ( wlan_cm_is_vdev_connecting(a2, v81, v82, v83, v84, v85, v86, v87, v88) )
          {
LABEL_25:
            if ( v71 )
            {
LABEL_26:
              v89 = *(void **)(v71 + 288);
              if ( v89 )
              {
                wlan_cm_free_connect_resp(v89);
                *(_QWORD *)(v71 + 288) = 0;
              }
              qdf_mutex_acquire(v71 + 40);
              v90 = *(void **)(v71 + 32);
              if ( v90 )
              {
                wlan_cm_free_connect_req(v90);
                *(_QWORD *)(v71 + 32) = 0;
              }
              qdf_mutex_release(v71 + 40);
            }
          }
          else
          {
            is_internal_disconnect = mlo_roam_is_internal_disconnect(a2);
            if ( v71 && (is_internal_disconnect & 1) == 0 )
              goto LABEL_26;
          }
LABEL_35:
          if ( (wlan_vdev_mlme_is_mlo_vdev(a1, v81, v82, v83, v84, v85, v86, v87, v88) & 1) != 0 )
          {
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: Vdev: %d",
              v92,
              v93,
              v94,
              v95,
              v96,
              v97,
              v98,
              v99,
              "mlo_roam_validate_req",
              *(unsigned __int8 *)(a1 + 168));
            if ( wlan_cm_is_vdev_disconnected(a1, v100, v101, v102, v103, v104, v105, v106, v107) )
            {
              mlo_handle_sta_link_connect_failure(a1, a3, v108, v109, v110, v111, v112, v113, v114, v115);
              started = 16;
              goto LABEL_79;
            }
            if ( !wlan_cm_is_vdev_connected(a1, v108, v109, v110, v111, v112, v113, v114, v115) )
            {
              if ( v71 )
              {
                v134 = *(void **)(v71 + 288);
                if ( v134 )
                {
                  wlan_cm_free_connect_resp(v134);
                  *(_QWORD *)(v71 + 288) = 0;
                  started = 16;
                  goto LABEL_79;
                }
              }
              goto LABEL_77;
            }
          }
          if ( (*(_BYTE *)(a2 + 60) & 2) != 0 )
          {
            if ( wlan_cm_is_vdev_connecting(a2, v92, v93, v94, v95, v96, v97, v98, v99) )
              goto LABEL_77;
            v117 = mlo_roam_is_internal_disconnect(a2);
            if ( !v71 || (v117 & 1) == 0 )
            {
              if ( (v117 & 1) != 0 )
                goto LABEL_68;
LABEL_77:
              started = 16;
              goto LABEL_79;
            }
          }
          else if ( !v71 )
          {
LABEL_68:
            started = wlan_cm_start_connect(a2, (__int64)s);
            if ( !started )
            {
              v135 = *(_QWORD **)(a2 + 1360);
              if ( v135 && (v136 = v135[278]) != 0 )
              {
                v137 = v135[3];
                if ( v137 && v137 == a2 )
                  *(_QWORD *)(v136 + 8) |= 1uLL;
                v138 = v135[4];
                started = 0;
                if ( v138 && v138 == a2 )
                {
                  started = 0;
                  *(_QWORD *)(v136 + 8) |= 2uLL;
                }
              }
              else
              {
                started = 0;
              }
            }
            goto LABEL_79;
          }
          if ( (*(_BYTE *)(a1 + 60) & 2) != 0 )
            goto LABEL_68;
          v118 = *(_QWORD *)(v71 + 112);
          if ( v118 )
          {
            _qdf_mem_free(v118);
            *(_QWORD *)(v71 + 112) = 0;
          }
          v119 = *(unsigned int *)(a3 + 120);
          *(_DWORD *)(v71 + 104) = v119;
          v120 = (void *)_qdf_mem_malloc(v119, "mlo_roam_validate_req", 1328);
          *(_QWORD *)(v71 + 112) = v120;
          if ( v120 )
          {
            v129 = *(const void **)(a3 + 128);
            if ( v129 )
              qdf_mem_copy(v120, v129, *(unsigned int *)(a3 + 120));
            v130 = *(_QWORD **)(a1 + 1360);
            if ( v130 )
            {
              v131 = v130[278];
              if ( v131 )
              {
                v132 = v130[3];
                if ( v132 && v132 == a1 )
                  *(_QWORD *)(v131 + 8) |= 1uLL;
                v133 = v130[4];
                if ( v133 && v133 == a1 )
                  *(_QWORD *)(v131 + 8) |= 2uLL;
              }
            }
            mlo_update_connected_links_bmap(
              v70,
              (unsigned __int8 *)(a3 + 160),
              v121,
              v122,
              v123,
              v124,
              v125,
              v126,
              v127,
              v128);
            goto LABEL_68;
          }
          goto LABEL_77;
        }
      }
      else
      {
        v61 = (void *)_qdf_mem_malloc(0x3E0u, "mlo_roam_prepare_and_send_link_connect_req", 1414);
        *(_QWORD *)(v17 + 32) = v61;
        if ( v61 )
          goto LABEL_17;
      }
      started = 2;
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: MLO_ROAM: vdev:%d Failed to allocate connect req",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "mlo_roam_prepare_and_send_link_connect_req",
        LOBYTE(s[0]));
      qdf_mutex_release(v17 + 40);
      goto LABEL_79;
    }
    v35 = rso_config_fl;
    LOWORD(s[15]) = *(_WORD *)(rso_config_fl + 84);
    HIDWORD(s[9]) = *(_DWORD *)(rso_config_fl + 64);
    HIDWORD(s[10]) = *(_DWORD *)(rso_config_fl + 72);
    LODWORD(s[10]) = *(_DWORD *)(rso_config_fl + 76);
    HIDWORD(s[15]) = *(_DWORD *)(rso_config_fl + 80);
    v36 = *(_DWORD *)(rso_config_fl + 68);
    v37 = *(unsigned int *)(rso_config_fl + 240);
    LODWORD(s[11]) = v36;
    LODWORD(s[19]) = v37;
    v38 = (void *)_qdf_mem_malloc(v37, "mlo_roam_prepare_and_send_link_connect_req", 1390);
    s[20] = (__int64)v38;
    if ( v38 )
    {
      v39 = *(unsigned int *)(v35 + 240);
      if ( (_DWORD)v39 )
        qdf_mem_copy(v38, *(const void **)(v35 + 248), v39);
      goto LABEL_12;
    }
    result = 2;
  }
  else
  {
    result = 16;
  }
LABEL_80:
  _ReadStatusReg(SP_EL0);
  return result;
}
