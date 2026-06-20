__int64 __fastcall lim_send_frame(
        __int64 a1,
        unsigned int a2,
        unsigned __int16 *a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v16; // w8
  __int64 result; // x0
  unsigned int *v18; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w8
  __int16 v28; // w8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x0
  __int64 v38; // x23
  unsigned __int8 *v39; // x22
  __int16 v40; // w25
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x24
  int v50; // w26
  __int64 session_by_vdev_id; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int v60; // w8
  unsigned int *v61; // x1
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 entry_by_bssid; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  unsigned int v79; // w26
  __int64 v80; // x27
  __int64 v81; // x0
  int v82; // w9
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  __int64 v99; // x0
  __int64 v100; // x0
  __int64 v101; // x8
  _QWORD *context; // x0
  unsigned int v103; // w20
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  __int64 v112; // [xsp+40h] [xbp-40h] BYREF
  void *v113; // [xsp+48h] [xbp-38h] BYREF
  __int64 v114; // [xsp+50h] [xbp-30h] BYREF
  __int64 v115; // [xsp+58h] [xbp-28h]
  __int64 v116; // [xsp+60h] [xbp-20h]
  __int64 v117; // [xsp+68h] [xbp-18h]
  unsigned int v118; // [xsp+74h] [xbp-Ch] BYREF
  __int64 v119; // [xsp+78h] [xbp-8h]

  v119 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *a3;
  v113 = nullptr;
  v112 = 0;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: sending fc->type: %d fc->subType: %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "lim_send_frame",
    (v16 >> 2) & 3,
    (unsigned __int8)v16 >> 4);
  result = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
             *(_QWORD *)(a1 + 21552),
             a2,
             7);
  if ( !result )
    goto LABEL_32;
  wlan_objmgr_vdev_release_ref(result, 7u, v18, v19, v20, v21, v22, v23, v24, v25, v26);
  v27 = *(unsigned __int16 *)(a1 + 21532);
  if ( v27 <= 0xFFE )
    v28 = v27 + 1;
  else
    v28 = 2048;
  *(_WORD *)(a1 + 21532) = v28;
  a3[11] = (16 * (v28 & 0xF)) | a3[11] & 0xFF0F;
  a3[11] = (16 * *(_WORD *)(a1 + 21532)) & 0xFF00 | (16 * (v28 & 0xF));
  if ( (unsigned int)cds_packet_alloc(a4, &v113, &v112) )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: call to bufAlloc failed for AUTH frame",
               v29,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               "lim_send_frame");
    goto LABEL_32;
  }
  qdf_mem_copy(v113, a3, (unsigned __int16)a4);
  v37 = *(_QWORD *)(a1 + 21560);
  v38 = v112;
  v39 = (unsigned __int8 *)v113;
  v118 = 0;
  if ( (unsigned int)wlan_get_opmode_from_vdev_id(v37, a2) == 16 )
  {
    v40 = (unsigned __int8)a2;
    qdf_mtrace(53, 54, 2u, a2, 0);
    v49 = 0;
    v50 = 12;
    goto LABEL_30;
  }
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2);
  if ( !session_by_vdev_id )
  {
    cds_packet_free(v38);
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: session not found for given vdev_id %d",
               v91,
               v92,
               v93,
               v94,
               v95,
               v96,
               v97,
               v98,
               "lim_tx_mgmt_frame",
               (unsigned __int8)a2);
    goto LABEL_32;
  }
  v40 = *(_WORD *)(session_by_vdev_id + 8);
  v49 = session_by_vdev_id;
  qdf_mtrace(53, 54, 2u, v40, 0);
  if ( (*(_WORD *)v39 & 0xF0) != 0xB0 )
    goto LABEL_28;
  v60 = *((unsigned __int16 *)v39 + 12);
  v61 = nullptr;
  v116 = 0;
  v117 = 0;
  v114 = 0;
  v115 = 0;
  if ( v60 == 3 )
  {
    if ( wlan_cm_is_vdev_active(*(_QWORD *)(v49 + 16), v52, v53, v54, v55, v56, v57, v58, v59) )
    {
      entry_by_bssid = wlan_scan_get_entry_by_bssid(*(_QWORD *)(a1 + 21560), v39 + 16);
      if ( entry_by_bssid )
      {
        v79 = *(_DWORD *)(entry_by_bssid + 1064);
        v80 = entry_by_bssid;
        v118 = v79;
        if ( wlan_reg_is_24ghz_ch_freq(v79) )
        {
          v81 = *(_QWORD *)(a1 + 21552);
          v82 = *(_DWORD *)(v80 + 1704) + 65500;
          v114 = *(_QWORD *)(v80 + 1712) + 36LL;
          LODWORD(v115) = (unsigned __int16)v82;
          if ( (wlan_action_oui_search(v81, &v114, 17) & 1) != 0 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Send pre-auth with 6Mbps on freq %d",
              v83,
              v84,
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              "lim_tx_mgmt_frame",
              v79);
            util_scan_free_cache_entry_2(v80);
            v50 = 4;
            goto LABEL_30;
          }
        }
        v99 = *(_QWORD *)(v80 + 1192);
        if ( v99 )
          _qdf_mem_free(v99);
        v100 = *(_QWORD *)(v80 + 1712);
        if ( v100 )
          _qdf_mem_free(v100);
        _qdf_mem_free(v80);
        goto LABEL_26;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: %02x:%02x:%02x:**:**:%02x scan entry not found",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        "lim_tx_mgmt_frame",
        v39[16],
        v39[17],
        v39[18],
        v39[21]);
    }
    v101 = *(_QWORD *)(v49 + 7432);
    if ( !v101 )
      goto LABEL_28;
    v79 = *(unsigned __int16 *)(v101 + 10);
    v118 = v79;
LABEL_26:
    if ( v79 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: TX SAE pre-auth frame on freq %d",
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        "lim_tx_mgmt_frame",
        v79);
      v61 = &v118;
      goto LABEL_29;
    }
LABEL_28:
    v61 = nullptr;
  }
LABEL_29:
  v50 = ((__int64 (__fastcall *)(__int64, unsigned int *))lim_get_min_session_txrate)(v49, v61);
LABEL_30:
  context = _cds_get_context(54, (__int64)"lim_tx_mgmt_frame", v41, v42, v43, v44, v45, v46, v47, v48);
  v103 = wma_tx_packet(
           context,
           v38,
           a4,
           3,
           1,
           7,
           lim_tx_complete,
           v39,
           lim_auth_tx_complete_cnf,
           0,
           (_BYTE)a2,
           0,
           (_WORD)v118,
           v50,
           0,
           0);
  result = qdf_trace(53, 5u, v40, v103);
  if ( v103 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Could not send Auth frame, retCode=%X",
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      "lim_tx_mgmt_frame",
      v103);
    *(_DWORD *)(a1 + 21588) = 3;
    result = lim_diag_event_report(a1, 78, v49, 2);
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
