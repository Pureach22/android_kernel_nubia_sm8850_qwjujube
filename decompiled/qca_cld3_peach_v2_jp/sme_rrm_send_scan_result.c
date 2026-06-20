__int64 __fastcall sme_rrm_send_scan_result(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 a3,
        unsigned int *a4,
        unsigned int a5)
{
  __int64 result; // x0
  __int64 v11; // x23
  unsigned __int16 *v12; // x0
  int v13; // t1
  size_t v14; // x2
  int v15; // w8
  unsigned __int64 v16; // x8
  _BYTE *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 first; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x24
  unsigned int v52; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w26
  __int64 *v62; // x27
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x4
  const char *v72; // x2
  unsigned int v73; // w25
  __int64 *v74; // x21
  int v75; // w27
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  char v92; // w23
  __int64 next; // x28
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  unsigned int v110; // [xsp+Ch] [xbp-34h]
  unsigned int *v111; // [xsp+10h] [xbp-30h]
  unsigned int v112; // [xsp+1Ch] [xbp-24h] BYREF
  __int64 v113; // [xsp+20h] [xbp-20h] BYREF
  int v114; // [xsp+28h] [xbp-18h] BYREF
  __int16 v115; // [xsp+2Ch] [xbp-14h]
  __int64 v116; // [xsp+38h] [xbp-8h]

  v116 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v113 = 0;
  if ( (unsigned __int8)a2 >= 6u )
    goto LABEL_68;
  v112 = 0;
  v115 = 0;
  v114 = 0;
  result = _qdf_mem_malloc(0x2D0u, "sme_rrm_send_scan_result", 458);
  if ( !result )
    goto LABEL_63;
  v11 = result;
  v13 = *(_DWORD *)(result + 70);
  v12 = (unsigned __int16 *)(result + 70);
  if ( !(v13 | v12[2]) || (*(_BYTE *)v12 & 1) != 0 )
  {
    *(_BYTE *)(v11 + 16) = 0;
    if ( !*(_BYTE *)(a1 + 544LL * (unsigned __int8)a2 + 17489) )
      goto LABEL_12;
  }
  else
  {
    *(_BYTE *)(v11 + 16) = 1;
    qdf_mem_copy(v12, (const void *)(a1 + 544LL * (unsigned __int8)a2 + 17522), 6u);
    if ( !*(_BYTE *)(a1 + 544LL * (unsigned __int8)a2 + 17489) )
      goto LABEL_12;
  }
  *(_BYTE *)(v11 + 17) = 1;
  if ( *(unsigned __int8 *)(a1 + 544LL * (unsigned __int8)a2 + 17489) >= 0x20u )
    v14 = 32;
  else
    v14 = *(unsigned __int8 *)(a1 + 544LL * (unsigned __int8)a2 + 17489);
  *(_BYTE *)(v11 + 100) = v14;
  qdf_mem_copy((void *)(v11 + 101), (const void *)(a1 + 544LL * (unsigned __int8)a2 + 17490), v14);
LABEL_12:
  v15 = a3;
  if ( a3 >= 0x66u )
    v15 = 102;
  *(_WORD *)(v11 + 18) = v15;
  qdf_mem_copy((void *)(v11 + 268), a4, (unsigned int)(4 * v15));
  *(_WORD *)v11 |= 2u;
  if ( (*(_DWORD *)(a1 + 544LL * (unsigned __int8)a2 + 17952) | 2) != 3 )
  {
    v17 = (_BYTE *)(a1 + 544LL * (unsigned __int8)a2 + 17546);
    goto LABEL_18;
  }
  v16 = *(unsigned __int8 *)(a1 + 544LL * (unsigned __int8)a2 + 17488);
  if ( v16 > 7 )
LABEL_68:
    __break(0x5512u);
  v17 = (_BYTE *)(a1 + 544LL * (unsigned __int8)a2 + 17416 + v16 + 130);
LABEL_18:
  if ( *v17 == 2 )
    *(_QWORD *)(v11 + 8) = wlan_scan_get_aging_time(*(_QWORD *)(a1 + 21552));
  if ( (unsigned int)csr_roam_get_session_id_from_bssid(a1, (int *)(a1 + 544LL * (unsigned __int8)a2 + 17418), &v112) == 16 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: BSSID mismatch, using current session_id",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "sme_rrm_send_scan_result");
    v112 = **(unsigned __int8 **)(a1 + 17224);
  }
  csr_scan_get_result(a1, v11, &v113);
  _qdf_mem_free(v11);
  result = qdf_trace_msg(
             0x34u,
             8u,
             "%s: RRM Measurement Done %d for index:%d",
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             "sme_rrm_send_scan_result",
             (unsigned __int8)a5,
             (unsigned __int8)a2);
  if ( v113 )
  {
    first = csr_scan_result_get_first(a1, v113);
    v51 = first;
    if ( (_BYTE)a5 && !first )
    {
      if ( *(_DWORD *)(a1 + 544LL * (unsigned __int8)a2 + 17952) == 3 )
        sme_ese_send_beacon_req_scan_results(a1, a2, v112, *a4, 0, a5, 0);
      else
        sme_rrm_send_beacon_report_xmit_ind(a1, a2, nullptr, a5, 0, v43, v44, v45, v46, v47, v48, v49, v50);
    }
    v52 = csr_ll_count(v113, v43, v44, v45, v46, v47, v48, v49, v50);
    if ( !v52 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: num_scan_results is %d",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "sme_rrm_send_scan_result",
        0);
      goto LABEL_62;
    }
    v61 = v52;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: num_scan_results %d",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "sme_rrm_send_scan_result",
      v52);
    v62 = (__int64 *)_qdf_mem_malloc(8LL * v61, "sme_rrm_send_scan_result", 569);
    v111 = a4;
    if ( !v62 )
    {
LABEL_55:
      v73 = 0;
LABEL_56:
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Number of BSS Desc with RRM Scan %d",
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        "sme_rrm_send_scan_result",
        v73);
      if ( (_BYTE)a5 || v73 )
      {
LABEL_58:
        if ( *(_DWORD *)(a1 + 544LL * (unsigned __int8)a2 + 17952) != 3 )
        {
          sme_rrm_send_beacon_report_xmit_ind(a1, a2, v62, a5, v73, v102, v103, v104, v105, v106, v107, v108, v109);
          if ( !v62 )
            goto LABEL_62;
          goto LABEL_61;
        }
        sme_ese_send_beacon_req_scan_results(a1, a2, v112, *v111, v62, a5, v73);
      }
      if ( v62 )
LABEL_61:
        _qdf_mem_free((__int64)v62);
LABEL_62:
      result = csr_scan_result_purge(a1, v113);
      goto LABEL_63;
    }
    if ( (unsigned int)wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21560), v112, &v114) )
    {
      v71 = v112;
      v72 = "%s: BSSID not found for vdev: %d";
LABEL_54:
      qdf_trace_msg(0x34u, 2u, v72, v63, v64, v65, v66, v67, v68, v69, v70, "sme_rrm_send_scan_result", v71);
      goto LABEL_55;
    }
    if ( !cm_is_vdevid_connected(*(_QWORD *)(a1 + 21560), v112) )
    {
      v71 = v112;
      v72 = "%s: vdev:%d is not connected";
      goto LABEL_54;
    }
    v73 = 0;
    v110 = a5;
    while ( 1 )
    {
      if ( !v51 )
      {
        a5 = v110;
        goto LABEL_56;
      }
      v74 = v62;
      v75 = qdf_mem_cmp((const void *)(v51 + 58), &v114, 6u);
      if ( v75 )
      {
        if ( !*(_BYTE *)(v51 + 105) )
          goto LABEL_47;
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Connected BSS in scan results",
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          "sme_rrm_send_scan_result");
        if ( !*(_BYTE *)(v51 + 105) )
          goto LABEL_47;
      }
      if ( (unsigned int)qdf_mem_cmp((const void *)(v51 + 107), &v114, 6u) )
      {
LABEL_47:
        v92 = 0;
        goto LABEL_49;
      }
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Non Tx BSS of Conn AP in results",
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        "sme_rrm_send_scan_result");
      v92 = 1;
LABEL_49:
      next = csr_scan_result_get_next(a1, v113);
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Scan res timer:%lu, rrm scan timer:%llu",
        v94,
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        "sme_rrm_send_scan_result",
        *(_QWORD *)(v51 + 48),
        rrm_scan_timer);
      if ( !v75 || (v92 & 1) != 0 || *(_QWORD *)(v51 + 48) >= (unsigned __int64)rrm_scan_timer )
      {
        v62 = v74;
        v74[v73++] = v51;
      }
      else
      {
        v62 = v74;
      }
      v51 = next;
      if ( v73 >= v61 )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Number of BSS Desc with RRM Scan %d",
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          "sme_rrm_send_scan_result",
          v73);
        a5 = v110;
        goto LABEL_58;
      }
    }
  }
  if ( (_BYTE)a5 )
  {
    if ( *(_DWORD *)(a1 + 544LL * (unsigned __int8)a2 + 17952) == 3 )
      result = sme_ese_send_beacon_req_scan_results(a1, a2, v112, *a4, 0, 1, 0);
    else
      result = sme_rrm_send_beacon_report_xmit_ind(a1, a2, nullptr, 1, 0, v34, v35, v36, v37, v38, v39, v40, v41);
  }
LABEL_63:
  _ReadStatusReg(SP_EL0);
  return result;
}
