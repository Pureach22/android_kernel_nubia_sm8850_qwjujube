__int64 __fastcall sme_rrm_issue_scan_req(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w19
  __int64 v3; // x20
  __int64 v4; // x28
  __int64 v5; // x8
  __int64 v6; // x21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  __int64 v19; // x8
  unsigned __int8 *v20; // x8
  unsigned int v21; // w21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w23
  __int64 v32; // x0
  __int64 v33; // x21
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x25
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int scan_id; // w0
  __int64 v53; // x4
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned __int64 v71; // x8
  unsigned __int16 *v72; // x8
  __int64 v73; // x9
  unsigned __int64 v74; // x22
  unsigned __int64 v75; // x8
  __int64 v76; // x21
  __int64 v77; // x5
  __int64 v78; // x4
  __int64 system_time; // x23
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 v88; // x8
  unsigned int v89; // w9
  size_t v90; // x24
  __int64 v91; // x0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 v100; // x23
  unsigned int v101; // w25
  unsigned int v102; // w27
  unsigned __int64 v103; // x22
  int v104; // w3
  int v105; // w0
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  unsigned int *v122; // x8
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  __int64 v131; // [xsp+8h] [xbp-18h]
  unsigned int v132; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v133; // [xsp+18h] [xbp-8h]

  v133 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned __int8)a2 >= 6u )
    goto LABEL_68;
  v2 = a2;
  v3 = a1;
  v5 = a1 + 544LL * (unsigned __int8)a2;
  v132 = 0;
  v6 = v5 + 17418;
  v4 = v5 + 17416;
  if ( (unsigned int)csr_roam_get_session_id_from_bssid(a1, (int *)(v5 + 17418), &v132) )
  {
    if ( v6 )
    {
      v15 = *(unsigned __int8 *)(v4 + 2);
      v16 = *(unsigned __int8 *)(v4 + 3);
      v17 = *(unsigned __int8 *)(v4 + 4);
      v18 = *(unsigned __int8 *)(v4 + 7);
    }
    else
    {
      v17 = 0;
      v15 = 0;
      v16 = 0;
      v18 = 0;
    }
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: sme session ID not found for bssid= %02x:%02x:%02x:**:**:%02x",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "sme_rrm_issue_scan_req",
      v15,
      v16,
      v17,
      v18);
    goto LABEL_11;
  }
  v19 = *(unsigned __int8 *)(v4 + 72);
  if ( (unsigned int)v19 >= *(unsigned __int8 *)(v4 + 56) )
  {
    sme_rrm_send_beacon_report_xmit_ind(v3, v2, 0, 1, 0);
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: done with the complete ch lt. finish and fee now",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "sme_rrm_issue_scan_req");
    v21 = 0;
    goto LABEL_13;
  }
  if ( (*(_DWORD *)(v4 + 536) | 2) == 3 )
  {
    if ( (unsigned int)v19 <= 7 )
    {
      v20 = (unsigned __int8 *)(v4 + v19 + 130);
      goto LABEL_17;
    }
LABEL_68:
    __break(0x5512u);
    goto LABEL_69;
  }
  v20 = (unsigned __int8 *)(v4 + 130);
LABEL_17:
  v31 = *v20;
  if ( v31 > 1 )
  {
    if ( v31 == 2 )
    {
      rrm_scan_timer = 0;
      v73 = *(_QWORD *)(v4 + 64);
      if ( !v73 )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: [802.11 RRM]: Global freq list is null",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "sme_rrm_issue_scan_req");
        if ( v4 )
          *(_BYTE *)(v4 + 532) = 0;
        goto LABEL_11;
      }
      v74 = *(unsigned __int8 *)(v4 + 72);
      LODWORD(v75) = *(unsigned __int8 *)(v4 + 56);
      if ( (unsigned int)v74 < (unsigned int)v75 )
      {
        v76 = v73 + 4 * v74;
        while ( (int)v74 + 1 < (unsigned int)v75 )
        {
          sme_rrm_send_scan_result(v3, v2, 1, v76, 0);
          v75 = *(unsigned __int8 *)(v4 + 56);
          ++v74;
          v76 += 4;
          ++*(_BYTE *)(v4 + 72);
          if ( v74 >= v75 )
            goto LABEL_34;
        }
        sme_rrm_send_scan_result(v3, v2, 1, v76, 1);
        v21 = 0;
        if ( v4 )
          *(_BYTE *)(v4 + 532) = 0;
        goto LABEL_13;
      }
    }
LABEL_34:
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Unknown beacon report req mode(%d)",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "sme_rrm_issue_scan_req",
      v31);
    v21 = 0;
    goto LABEL_12;
  }
  if ( !*(_QWORD *)(v4 + 64) )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: [802.11 RRM]: Global freq list is null",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "sme_rrm_issue_scan_req");
LABEL_11:
    v21 = 16;
LABEL_12:
    sme_rrm_send_beacon_report_xmit_ind(v3, v2, 0, 1, 0);
LABEL_13:
    _qdf_mem_free(*(_QWORD *)(v4 + 64));
    *(_QWORD *)(v4 + 64) = 0;
    *(_BYTE *)(v4 + 56) = 0;
    goto LABEL_14;
  }
  v32 = _qdf_mem_malloc(0x8F0u, "sme_rrm_issue_scan_req", 949);
  if ( !v32 )
  {
LABEL_69:
    v21 = 2;
    goto LABEL_12;
  }
  v33 = v32;
  v34 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(v3 + 21552),
          v132,
          11);
  if ( !v34 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: VDEV is null %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "sme_rrm_issue_scan_req",
      v132);
    _qdf_mem_free(v33);
    v21 = 4;
    goto LABEL_12;
  }
  v43 = v34;
  wlan_scan_init_default_params(v34, (__int64 *)v33, v35, v36, v37, v38, v39, v40, v41, v42);
  scan_id = wlan_scan_get_scan_id(*(_QWORD *)(v3 + 21552), v44, v45, v46, v47, v48, v49, v50, v51);
  *(_DWORD *)(v33 + 8) = scan_id;
  v53 = *(unsigned __int8 *)(v4 + 9);
  *(_DWORD *)(v4 + 140) = scan_id;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: RRM_SCN: rrm_idx:%d scan_id:%d",
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    "sme_rrm_issue_scan_req",
    v53,
    scan_id);
  v62 = *(_DWORD *)(v33 + 92) & 0xFFFFFFFE;
  if ( v31 != 1 )
    ++v62;
  *(_DWORD *)(v33 + 92) = v62;
  *(_DWORD *)(v33 + 16) = *(unsigned __int8 *)(v43 + 104);
  *(_DWORD *)(v33 + 12) = *(unsigned __int16 *)(v4 + 540);
  qdf_mem_copy((void *)(v33 + 1876), (const void *)(v4 + 106), 6u);
  *(_DWORD *)(v33 + 108) = 1;
  if ( *(_BYTE *)(v4 + 73) )
  {
    *(_DWORD *)(v33 + 112) = 1;
    qdf_mem_copy((void *)(v33 + 1349), (const void *)(v4 + 74), *(unsigned __int8 *)(v4 + 73));
    *(_BYTE *)(v33 + 1348) = *(_BYTE *)(v4 + 73);
  }
  if ( (*(_DWORD *)(v4 + 536) | 2) == 3 )
  {
    v71 = *(unsigned __int8 *)(v4 + 72);
    if ( v71 <= 7 )
    {
      v72 = (unsigned __int16 *)(v4 + 2 * v71 + 114);
      goto LABEL_40;
    }
    goto LABEL_68;
  }
  v72 = (unsigned __int16 *)(v4 + 114);
LABEL_40:
  v77 = *v72;
  if ( (*(_BYTE *)(v33 + 92) & 1) != 0 )
  {
    if ( (unsigned int)v77 > 0x13 )
    {
      *(_DWORD *)(v33 + 44) = v77;
      *(_DWORD *)(v33 + 56) = v77;
    }
    else
    {
      LODWORD(v77) = *(_DWORD *)(v33 + 44);
    }
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Passive Max Dwell Time(%d)",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "sme_rrm_issue_scan_req",
      (unsigned int)v77);
  }
  else
  {
    if ( (unsigned int)v77 > 0x13 )
    {
      v78 = *v72;
      *(_DWORD *)(v33 + 36) = v77;
      *(_DWORD *)(v33 + 40) = v77;
      *(_DWORD *)(v33 + 52) = v77;
    }
    else
    {
      v78 = *(unsigned int *)(v33 + 36);
      v77 = *(unsigned int *)(v33 + 40);
    }
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Active Max Dwell Time(%d) 2G Dwell time %d",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "sme_rrm_issue_scan_req",
      v78,
      v77);
  }
  *(_QWORD *)(v33 + 100) = 0x9600000004LL;
  *(_QWORD *)(v33 + 60) = 0x3200000032LL;
  *(_DWORD *)(v33 + 76) = 25;
  system_time = qdf_mc_timer_get_system_time();
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: prev scan triggered before %llu ms, totalchannels %d",
    v80,
    v81,
    v82,
    v83,
    v84,
    v85,
    v86,
    v87,
    "sme_rrm_issue_scan_req",
    system_time - rrm_scan_timer,
    *(unsigned __int8 *)(v4 + 56));
  v88 = system_time - rrm_scan_timer;
  if ( system_time - rrm_scan_timer < 0 )
    v88 = rrm_scan_timer - system_time;
  if ( v88 >= 1001 && *(_BYTE *)(v4 + 56) == 1 )
  {
    *(_QWORD *)(v33 + 60) = 0x100000001LL;
    *(_DWORD *)(v33 + 76) = 1;
  }
  rrm_scan_timer = qdf_mc_timer_get_system_time();
  v89 = *(unsigned __int8 *)(v4 + 56);
  *(_BYTE *)(v33 + 120) = v89;
  if ( v89 < 0x27 )
    v90 = 5 * v89 + 1;
  else
    v90 = 196;
  v91 = _qdf_mem_malloc(v90, "sme_rrm_issue_scan_req", 1060);
  if ( !v91 )
    goto LABEL_69;
  v100 = v91;
  v131 = v43;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Number of chan %d active duration %d passive %d",
    v92,
    v93,
    v94,
    v95,
    v96,
    v97,
    v98,
    v99,
    "sme_rrm_issue_scan_req",
    *(unsigned __int8 *)(v33 + 120),
    *(unsigned int *)(v33 + 36),
    *(unsigned int *)(v33 + 44));
  if ( *(_BYTE *)(v33 + 120) )
  {
    v101 = 0;
    v102 = 0;
    v103 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v104 = *(_DWORD *)(*(_QWORD *)(v4 + 64) + 4 * v103);
        *(_DWORD *)(v33 + 124 + 12 * v103) = v104;
        v106 = scnprintf(v100 + v101, (unsigned int)v90 - v101, " %d", v104);
        if ( v102 <= 0x25 )
          break;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: RRM Scan Req for channels: %s",
          v106,
          v107,
          v108,
          v109,
          v110,
          v111,
          v112,
          v113,
          "sme_rrm_issue_scan_req",
          v100);
        if ( ++v103 >= *(unsigned __int8 *)(v33 + 120) )
          goto LABEL_72;
        v102 = 0;
        v101 = 0;
        if ( v103 == 102 )
          goto LABEL_68;
      }
      ++v103;
      v101 += v105;
      if ( v103 >= *(unsigned __int8 *)(v33 + 120) )
        break;
      ++v102;
      if ( v103 == 102 )
        goto LABEL_68;
    }
    if ( v101 )
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: RRM Freq scan req channels: %s",
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        "sme_rrm_issue_scan_req",
        v100);
  }
LABEL_72:
  _qdf_mem_free(v100);
  *(_DWORD *)(v33 + 28) = 3;
  v21 = wlan_scan_start((__int64 *)v33, v114, v115, v116, v117, v118, v119, v120, v121);
  wlan_objmgr_vdev_release_ref(v131, 0xBu, v122, v123, v124, v125, v126, v127, v128, v129, v130);
  if ( v21 )
    goto LABEL_12;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v21;
}
