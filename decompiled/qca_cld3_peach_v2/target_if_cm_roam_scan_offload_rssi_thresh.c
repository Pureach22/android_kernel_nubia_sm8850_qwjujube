__int64 __fastcall target_if_cm_roam_scan_offload_rssi_thresh(
        __int64 a1,
        char *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8
  int v22; // w11
  char v23; // w9
  int v24; // w10
  int v25; // w8
  int v26; // w9
  int v27; // w8
  int v28; // w9
  int v29; // w8
  char v30; // w21
  unsigned int v31; // w8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
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
  unsigned int v72; // w19
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v82; // [xsp+0h] [xbp-20h]
  __int64 v83; // [xsp+0h] [xbp-20h]
  __int64 v84; // [xsp+8h] [xbp-18h]
  __int64 v85; // [xsp+10h] [xbp-10h]

  v12 = wmi_service_enabled(a1, 0xACu, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (v12 & 1) != 0 )
  {
    v21 = *((_DWORD *)a2 + 4);
    *((_DWORD *)a2 + 3) = (unsigned __int8)a2[12];
    if ( v21 < -96 )
      v21 = 127;
  }
  else
  {
    v22 = *((_DWORD *)a2 + 12);
    v23 = a2[84] + 96;
    v24 = *((_DWORD *)a2 + 24) + 96;
    *a2 += 96;
    a2[84] = v23;
    v26 = *((_DWORD *)a2 + 3);
    v25 = *((_DWORD *)a2 + 4);
    *((_DWORD *)a2 + 24) = v24;
    *((_DWORD *)a2 + 12) = (unsigned __int8)(v22 + 96);
    *((_DWORD *)a2 + 3) = (unsigned __int8)(v26 + 96);
    if ( v25 < -96 )
      goto LABEL_7;
    v21 = (unsigned __int8)(v25 + 96);
  }
  *((_DWORD *)a2 + 8) = v21;
LABEL_7:
  v27 = *((_DWORD *)a2 + 5);
  if ( v27 > -97 )
  {
    if ( (v12 & 1) == 0 )
      v27 = (unsigned __int8)(v27 + 96);
    goto LABEL_12;
  }
  if ( (v12 & 1) != 0 )
  {
    v27 = -128;
LABEL_12:
    *((_DWORD *)a2 + 7) = v27;
    goto LABEL_14;
  }
  *((_DWORD *)a2 + 7) = 0;
LABEL_14:
  if ( a2[52] == 1 )
  {
    if ( (v12 & 1) == 0 )
    {
      v28 = *((_DWORD *)a2 + 15) + 96;
      *((_DWORD *)a2 + 14) += 96;
      *((_DWORD *)a2 + 15) = v28;
      if ( !*((_DWORD *)a2 + 2) )
        goto LABEL_29;
LABEL_21:
      v29 = *((_DWORD *)a2 + 26);
      if ( (v29 & 1) != 0 )
      {
        v30 = v12;
        if ( (wmi_service_enabled(a1, 0x130u, v13, v14, v15, v16, v17, v18, v19, v20) & 1) != 0 )
        {
          qdf_trace_msg(
            0x49u,
            8u,
            "%s: FW supports Hi RSSI roam in 5 GHz",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "target_if_check_hi_rssi_5ghz_support");
          v12 = v30;
          v31 = *((_DWORD *)a2 + 26) | 1;
LABEL_28:
          *((_DWORD *)a2 + 26) = v31;
          goto LABEL_29;
        }
        v29 = *((_DWORD *)a2 + 26);
        v12 = v30;
      }
      v31 = v29 & 0xFFFFFFFE;
      goto LABEL_28;
    }
LABEL_20:
    if ( !*((_DWORD *)a2 + 2) )
      goto LABEL_29;
    goto LABEL_21;
  }
  if ( (v12 & 1) != 0 )
  {
    *((_QWORD *)a2 + 7) = 0xFFFFFF80FFFFFF80LL;
    goto LABEL_20;
  }
  *((_QWORD *)a2 + 7) = 0;
  if ( *((_DWORD *)a2 + 2) )
    goto LABEL_21;
LABEL_29:
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: RSO_CFG: vdev %d: db2dbm enabled:%d, good_rssi_threshold:%d, early_stop_thresholds en:%d, min:%d, max:%d, roam_s"
    "can_rssi_thresh:%d, roam_rssi_thresh_diff:%d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "target_if_cm_roam_scan_offload_rssi_thresh",
    (unsigned __int8)a2[24],
    v12 & 1,
    *((unsigned int *)a2 + 12),
    *((_DWORD *)a2 + 14),
    *((_DWORD *)a2 + 15),
    *a2,
    (unsigned __int8)a2[1]);
  LODWORD(v85) = *((_DWORD *)a2 + 18);
  LODWORD(v84) = *((_DWORD *)a2 + 19);
  LODWORD(v82) = *((_DWORD *)a2 + 17);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: RSO_CFG: hirssi max cnt:%d, delta:%d, hirssi upper bound:%d, dense rssi thresh offset:%d, dense min aps cnt:%d, "
    "traffic_threshold:%d, dense_status:%d",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "target_if_cm_roam_scan_offload_rssi_thresh",
    *((unsigned int *)a2 + 1),
    *((unsigned int *)a2 + 2),
    *((unsigned int *)a2 + 3),
    *((unsigned int *)a2 + 16),
    v82,
    v84,
    v85);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: RSO_CFG: raise rssi threshold 5g:%d, drop rssi threshold 5g:%d, penalty threshold 5g:%d, boost threshold 5g:%d",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "target_if_cm_roam_scan_offload_rssi_thresh",
    *((unsigned int *)a2 + 4),
    *((unsigned int *)a2 + 5),
    *((unsigned int *)a2 + 7),
    *((unsigned int *)a2 + 8));
  LODWORD(v83) = *((_DWORD *)a2 + 20);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: RSO_CFG: raise factor 5g:%d, drop factor 5g:%d, max raise rssi 5g:%d, max drop rssi 5g:%d, rssi threshold offset 5g:%d",
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    "target_if_cm_roam_scan_offload_rssi_thresh",
    (unsigned __int8)a2[36],
    (unsigned __int8)a2[36],
    *((unsigned int *)a2 + 10),
    *((unsigned int *)a2 + 11),
    v83);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: RSO_CFG: BG Scan Bad RSSI:%d, bitmap:0x%x Offset for 2G to 5G Roam:%d",
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    "target_if_cm_roam_scan_offload_rssi_thresh",
    (unsigned int)a2[84],
    *((unsigned int *)a2 + 22),
    (unsigned __int8)a2[85]);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: RSO_CFG: Roam data rssi triggers:0x%x, threshold:%d, rx time:%d",
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    "target_if_cm_roam_scan_offload_rssi_thresh",
    *((unsigned int *)a2 + 23),
    *((unsigned int *)a2 + 24),
    *((unsigned int *)a2 + 25));
  v72 = wmi_unified_roam_scan_offload_rssi_thresh_cmd(a1, a2);
  if ( v72 )
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: roam_scan_offload_rssi_thresh_cmd failed %d",
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      "target_if_cm_roam_scan_offload_rssi_thresh",
      v72);
  return v72;
}
