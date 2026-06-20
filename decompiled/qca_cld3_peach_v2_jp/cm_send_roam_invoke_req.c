__int64 __fastcall cm_send_roam_invoke_req(
        __int64 *a1,
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
  __int64 v11; // x0
  unsigned int v12; // w20
  unsigned int v13; // w21
  __int64 v14; // x24
  __int64 v15; // x22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x23
  int *v45; // x9
  int v48; // w10
  __int16 v49; // w9
  int v50; // w8
  int v51; // w9
  int v52; // w10
  __int64 v53; // x0
  __int64 v54; // x26
  __int16 v55; // w9
  int v56; // w10
  _QWORD *scan_result; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned int v66; // w27
  __int64 v67; // x25
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x26
  size_t v77; // x0
  void *v78; // x0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned int v87; // w20
  const char *v88; // x2
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
  int v106; // w9
  int v107; // w8
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  _BYTE v124[4]; // [xsp+8h] [xbp-28h] BYREF
  unsigned int v125; // [xsp+Ch] [xbp-24h] BYREF
  int v126; // [xsp+10h] [xbp-20h] BYREF
  unsigned __int16 v127; // [xsp+14h] [xbp-1Ch]
  _QWORD v128[3]; // [xsp+18h] [xbp-18h] BYREF

  v128[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v124[0] = 0;
  if ( !a2 )
  {
    v87 = 16;
    goto LABEL_41;
  }
  v11 = *a1;
  v12 = *(_DWORD *)(a2 + 16);
  v13 = *(unsigned __int8 *)(a2 + 33);
  v127 = 0;
  v14 = *(_QWORD *)(v11 + 152);
  v125 = v12;
  v126 = 0;
  if ( !v14 )
  {
    v88 = "%s: vdev %d cm_id 0x%x: Failed to find pdev";
LABEL_33:
    qdf_trace_msg(0x68u, 2u, v88, a3, a4, a5, a6, a7, a8, a9, a10, "cm_send_roam_invoke_req", v13, v12);
LABEL_34:
    v44 = 0;
    goto LABEL_35;
  }
  v15 = *(_QWORD *)(v14 + 80);
  if ( !v15 )
  {
    v88 = "%s: vdev %d cm_id 0x%x: Failed to find psoc";
    goto LABEL_33;
  }
  wlan_vdev_get_bss_peer_mac(v11, &v126, a3, a4, a5, a6, a7, a8, a9, a10);
  wlan_mlme_get_self_bss_roam(v15, v124);
  if ( !v124[0] )
  {
    v25 = *a1;
    WORD2(v128[0]) = 0;
    LODWORD(v128[0]) = 0;
    if ( !(unsigned int)wlan_vdev_get_bss_peer_mac(v25, v128, v17, v18, v19, v20, v21, v22, v23, v24)
      && *(_DWORD *)(a2 + 40) == LODWORD(v128[0])
      && *(unsigned __int16 *)(a2 + 44) == WORD2(v128[0]) )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d cm_id 0x%x: self bss roam disabled. invoke_src:%d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "cm_send_roam_invoke_req",
        v13,
        v12,
        *(unsigned int *)(a2 + 36));
      v107 = *(_DWORD *)(a2 + 36);
      if ( v107 == 19 || v107 == 1 )
        cm_roam_reject_reassoc_event(v15, *a1, (unsigned __int8 *)&v126);
      goto LABEL_34;
    }
  }
  v35 = _qdf_mem_malloc(0x20u, "cm_send_roam_invoke_req", 7507);
  v44 = v35;
  if ( v35 )
  {
    *(_BYTE *)v35 = v13;
    if ( (*(_BYTE *)(a2 + 32) & 1) != 0 )
    {
      *(_BYTE *)(v35 + 25) = 1;
      goto LABEL_54;
    }
    v45 = (int *)(a2 + 40);
    if ( *(_DWORD *)(a2 + 40) == -1 && *(__int16 *)(a2 + 44) == -1 )
    {
      v106 = *v45;
      *(_WORD *)(v35 + 5) = *(_WORD *)(a2 + 44);
      *(_DWORD *)(v35 + 1) = v106;
      goto LABEL_54;
    }
    if ( *v45 == v126 && *(unsigned __int16 *)(a2 + 44) == v127 )
      *(_BYTE *)(v35 + 24) = 1;
    v48 = *v45;
    v49 = *(_WORD *)(a2 + 44);
    *(_DWORD *)(v35 + 1) = v48;
    *(_WORD *)(v35 + 5) = v49;
    v128[0] = 0;
    v50 = *(_DWORD *)(a2 + 52);
    v51 = *(_DWORD *)(v35 + 1);
    v52 = *(unsigned __int16 *)(v35 + 5);
    *(_DWORD *)(v35 + 8) = v50;
    if ( !(v51 | v52) )
      goto LABEL_50;
    if ( !v50 )
      goto LABEL_50;
    v53 = _qdf_mem_malloc(0x2D0u, "cm_find_roam_candidate", 7258);
    if ( !v53 )
      goto LABEL_50;
    v54 = v53;
    *(_BYTE *)(v53 + 16) = 1;
    v55 = *(_WORD *)(v44 + 5);
    v56 = *(_DWORD *)(v44 + 1);
    *(_WORD *)(v53 + 18) = 1;
    *(_WORD *)(v53 + 74) = v55;
    *(_DWORD *)(v53 + 70) = v56;
    *(_DWORD *)(v53 + 268) = *(_DWORD *)(v44 + 8);
    scan_result = scm_get_scan_result(v14, v53, v36, v37, v38, v39, v40, v41, v42, v43);
    if ( scan_result )
    {
      v66 = *((_DWORD *)scan_result + 4);
      v67 = (__int64)scan_result;
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev %d cm_id 0x%x: num_entries found %d",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        "cm_find_roam_candidate",
        *(unsigned __int8 *)(a2 + 33),
        *(unsigned int *)(a2 + 24),
        v66);
      _qdf_mem_free(v54);
      if ( *(_DWORD *)(v67 + 16) )
      {
        qdf_list_peek_front((_QWORD *)v67, v128);
        v76 = v128[0];
        v77 = *(unsigned int *)(*(_QWORD *)(v128[0] + 24LL) + 1704LL);
        *(_DWORD *)(v44 + 12) = v77;
        if ( (_DWORD)v77 )
        {
          v78 = (void *)_qdf_mem_malloc(v77, "cm_find_roam_candidate", 7299);
          *(_QWORD *)(v44 + 16) = v78;
          if ( v78 )
          {
            qdf_mem_copy(v78, *(const void **)(*(_QWORD *)(v76 + 24) + 1712LL), *(unsigned int *)(v44 + 12));
            scm_purge_scan_results(v67, v79, v80, v81, v82, v83, v84, v85, v86);
LABEL_51:
            if ( (wlan_cm_get_ese_assoc(v14, v13) & 1) != 0 )
            {
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: vdev %d cm_id 0x%x: Beacon is not required for ESE",
                v116,
                v117,
                v118,
                v119,
                v120,
                v121,
                v122,
                v123,
                "cm_send_roam_invoke_req",
                v13,
                v12);
              if ( *(_DWORD *)(v44 + 12) )
              {
                _qdf_mem_free(*(_QWORD *)(v44 + 16));
                *(_QWORD *)(v44 + 16) = 0;
                *(_DWORD *)(v44 + 12) = 0;
              }
            }
LABEL_54:
            if ( !(unsigned int)wlan_cm_tgt_send_roam_invoke_req(v15, v44) )
            {
              v87 = 0;
              if ( !*(_DWORD *)(v44 + 12) )
                goto LABEL_40;
              goto LABEL_39;
            }
            goto LABEL_35;
          }
          *(_DWORD *)(v44 + 12) = 0;
        }
LABEL_50:
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev %d cm_id 0x%x: No Candidate found, send roam invoke req, fw will perform scan",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "cm_send_roam_invoke_req",
          v13,
          v12);
        goto LABEL_51;
      }
      scm_purge_scan_results(v67, v68, v69, v70, v71, v72, v73, v74, v75);
    }
    else
    {
      _qdf_mem_free(v54);
      v66 = 0;
    }
    qdf_trace_msg(
      0x68u,
      4u,
      "%s: vdev %d cm_id 0x%x: no valid candidate found, num_bss %d",
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      v115,
      "cm_find_roam_candidate",
      *(unsigned __int8 *)(a2 + 33),
      *(unsigned int *)(a2 + 24),
      v66);
    goto LABEL_50;
  }
LABEL_35:
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d cm_id 0x%x: fail to send roam invoke req",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "cm_send_roam_invoke_req",
    v13,
    v12);
  v87 = wlan_sm_dispatch(a1[9], 0x13u, 4u, (__int64)&v125, v89, v90, v91, v92, v93, v94, v95, v96);
  if ( v87 )
    cm_remove_cmd(a1, &v125, v97, v98, v99, v100, v101, v102, v103, v104);
  if ( v44 )
  {
    if ( !*(_DWORD *)(v44 + 12) )
    {
LABEL_40:
      _qdf_mem_free(v44);
      goto LABEL_41;
    }
LABEL_39:
    _qdf_mem_free(*(_QWORD *)(v44 + 16));
    goto LABEL_40;
  }
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return v87;
}
