__int64 __fastcall dp_nud_process_failure_event(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x9
  int tx_ack_count; // w0
  __int64 v12; // x8
  __int64 vdev_by_user; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x20
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w22
  const char *v33; // x2
  bool v34; // zf
  bool v35; // zf
  _BOOL4 v36; // w9
  _QWORD *v37; // x23
  __int64 v38; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x20
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  void (__fastcall *v104)(_QWORD); // x8
  __int64 (__fastcall *v105)(__int64, __int64); // x8
  __int64 v106; // x0
  __int64 v107; // x1
  unsigned int v108; // w0
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  unsigned int *v117; // x8
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  __int64 v126; // x1
  __int64 result; // x0
  __int64 v128; // x9
  __int64 v129; // [xsp+0h] [xbp-10h] BYREF
  __int64 v130; // [xsp+8h] [xbp-8h]

  v130 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 3480) & 0xFB) == 1 )
  {
    v9 = *(_QWORD *)(a1 + 2888);
    *(_DWORD *)(a1 + 3496) = *(_QWORD *)(a1 + 2896);
    *(_DWORD *)(a1 + 3504) = v9;
    tx_ack_count = dp_txrx_get_tx_ack_count(a1);
    v12 = *(_QWORD *)(a1 + 3664);
    *(_DWORD *)(a1 + 3500) = tx_ack_count;
    WORD2(v129) = 0;
    LODWORD(v129) = 0;
    vdev_by_user = _dp_objmgr_get_vdev_by_user(v12, 0x61u, (__int64)"dp_nud_honour_failure");
    if ( !vdev_by_user )
      goto LABEL_16;
    v22 = vdev_by_user;
    wlan_vdev_mgr_get_param_bssid(vdev_by_user, &v129);
    _dp_objmgr_put_vdev_by_user(
      v22,
      0x61u,
      (__int64)"dp_nud_honour_failure",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31);
    v32 = 1;
    v33 = "%s: NUD_FAILURE_HONORED [mac:%02x:%02x:%02x:**:**:%02x]";
    if ( *(_DWORD *)(a1 + 3496) != *(_DWORD *)(a1 + 3484) && *(_DWORD *)(a1 + 3500) != *(_DWORD *)(a1 + 3488) )
    {
      v34 = *(_DWORD *)(a1 + 3512) == (_DWORD)v129 && *(unsigned __int16 *)(a1 + 3516) == WORD2(v129);
      v35 = !v34 || *(_DWORD *)(a1 + 3504) == *(_DWORD *)(a1 + 3492);
      v36 = !v35;
      if ( *(_DWORD *)(a1 + 3508) || v36 )
      {
LABEL_16:
        v32 = 0;
        v33 = "%s: NUD_FAILURE_NOT_HONORED [mac:%02x:%02x:%02x:**:**:%02x]";
      }
    }
    qdf_trace_msg(
      0x45u,
      5u,
      v33,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "dp_nud_honour_failure",
      *(unsigned __int8 *)(a1 + 3512),
      *(unsigned __int8 *)(a1 + 3513),
      *(unsigned __int8 *)(a1 + 3514),
      *(unsigned __int8 *)(a1 + 3517),
      v129,
      v130);
    v37 = *(_QWORD **)a1;
    v38 = _dp_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 3664), 0x61u, (__int64)"dp_nud_stats_info");
    if ( v38 )
    {
      v47 = v38;
      qdf_trace_msg(0x45u, 5u, "%s: **** NUD STATS: ****", v39, v40, v41, v42, v43, v44, v45, v46, "dp_nud_stats_info");
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: NUD Probe Tx  : %d",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "dp_nud_stats_info",
        *(unsigned int *)(a1 + 3484));
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: NUD Probe Ack : %d",
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        "dp_nud_stats_info",
        *(unsigned int *)(a1 + 3488));
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: NUD Probe Rx  : %d",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "dp_nud_stats_info",
        *(unsigned int *)(a1 + 3492));
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: NUD Failure Tx  : %d",
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        "dp_nud_stats_info",
        *(unsigned int *)(a1 + 3496));
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: NUD Failure Ack : %d",
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        "dp_nud_stats_info",
        *(unsigned int *)(a1 + 3500));
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: NUD Failure Rx  : %d",
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        "dp_nud_stats_info",
        *(unsigned int *)(a1 + 3504));
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: NUD Gateway Rx  : %d",
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        "dp_nud_stats_info",
        *(unsigned int *)(a1 + 3508));
      v104 = (void (__fastcall *)(_QWORD))v37[85];
      if ( *((_DWORD *)v104 - 1) != 1458356883 )
        __break(0x8228u);
      v104(v47);
      v105 = (__int64 (__fastcall *)(__int64, __int64))v37[86];
      v106 = v37[47];
      v107 = *(_QWORD *)(a1 + 56);
      if ( *((_DWORD *)v105 - 1) != 1404304091 )
        __break(0x8228u);
      v108 = v105(v106, v107);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Current pause_map value %x",
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        "dp_nud_stats_info",
        v108);
      _dp_objmgr_put_vdev_by_user(
        v47,
        0x61u,
        (__int64)"dp_nud_stats_info",
        v117,
        v118,
        v119,
        v120,
        v121,
        v122,
        v123,
        v124,
        v125);
    }
    if ( v32 )
    {
      v126 = system_wq;
      *(_BYTE *)(a1 + 3480) = 6;
      result = queue_work_on(32, v126, a1 + 3520);
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: NUD_START [0x%x]",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "dp_nud_process_failure_event",
        1);
      v128 = *(_QWORD *)(a1 + 2888);
      *(_DWORD *)(a1 + 3484) = *(_QWORD *)(a1 + 2896);
      *(_DWORD *)(a1 + 3492) = v128;
      result = dp_txrx_get_tx_ack_count(a1);
      *(_BYTE *)(a1 + 3480) = 1;
      *(_DWORD *)(a1 + 3488) = result;
      *(_DWORD *)(a1 + 3508) = 0;
      *(_BYTE *)(a1 + 3568) = 1;
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x45u,
               5u,
               "%s: NUD FAILED -> Current State [0x%x]",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "dp_nud_process_failure_event");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
