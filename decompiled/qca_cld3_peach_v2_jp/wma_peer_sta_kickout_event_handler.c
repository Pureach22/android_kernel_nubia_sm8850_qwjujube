__int64 __fastcall wma_peer_sta_kickout_event_handler(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x22
  unsigned int v22; // w8
  unsigned int v23; // w20
  __int64 v24; // x9
  unsigned int (*v25)(void); // x9
  unsigned int v26; // w22
  unsigned int v27; // w21
  unsigned int v28; // w19
  __int64 result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned __int8 *v38; // x21
  const void *v39; // x20
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  const char *v48; // x2
  const void *vdev_bssid; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  int v58; // w8
  const void *v59; // x20
  _BYTE *v60; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x21
  __int64 v70; // x8
  _BYTE *v71; // x0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x21
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  int v89; // w8
  __int16 v90; // w9
  __int16 v91; // w8
  char v92; // w0
  char v93; // w8
  bool v94; // zf
  int v95; // w0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  unsigned int v104; // [xsp+30h] [xbp-10h] BYREF
  __int16 v105; // [xsp+34h] [xbp-Ch]
  __int64 v106; // [xsp+38h] [xbp-8h]

  v106 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"wma_peer_sta_kickout_event_handler", a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = *a2;
  v23 = *(_DWORD *)(*a2 + 4);
  v22 = *(_DWORD *)(v21 + 8);
  v104 = v23;
  v105 = v22;
  if ( !context || !*context || (v24 = *(_QWORD *)(*context + 72LL)) == 0 )
  {
    v28 = v22 >> 8;
    v27 = HIWORD(v23);
    v26 = v23 >> 8;
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v13, v14, v15, v16, v17, v18, v19, v20, "cdp_peer_get_vdevid");
    goto LABEL_10;
  }
  v25 = *(unsigned int (**)(void))(v24 + 48);
  if ( !v25 )
  {
    v28 = v22 >> 8;
    v27 = HIWORD(v23);
    v26 = v23 >> 8;
    goto LABEL_10;
  }
  if ( *((_DWORD *)v25 - 1) != -1370432993 )
    __break(0x8229u);
  if ( !v25() )
  {
    if ( (wma_is_vdev_valid(0, v13, v14, v15, v16, v17, v18, v19, v20) & 1) == 0 )
      goto LABEL_11;
    v38 = **(unsigned __int8 ***)(a1 + 520);
    if ( !v38 )
    {
      v48 = "%s: Not able to find vdev for VDEV_%d";
      goto LABEL_19;
    }
    v39 = v38 + 74;
    qdf_trace_msg(
      0x36u,
      4u,
      "STA kickout for %02x:%02x:%02x:**:**:%02x, on mac %02x:%02x:%02x:**:**:%02x, vdev %d, reason:%d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      (unsigned __int8)v104,
      BYTE1(v104),
      BYTE2(v104),
      HIBYTE(v105),
      v38[74],
      v38[75],
      v38[76],
      v38[79],
      0,
      *(_DWORD *)(v21 + 12));
    if ( (wma_is_roam_in_progress(0, v40, v41, v42, v43, v44, v45, v46, v47) & 1) != 0 )
    {
      v48 = "%s: vdev_id %d: Ignore STA kick out since roaming is in progress";
LABEL_19:
      qdf_trace_msg(0x36u, 2u, v48, v30, v31, v32, v33, v34, v35, v36, v37, "wma_peer_sta_kickout_event_handler", 0);
      goto LABEL_11;
    }
    vdev_bssid = (const void *)wma_get_vdev_bssid((__int64)v38, v30, v31, v32, v33, v34, v35, v36, v37);
    if ( !vdev_bssid )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to get bssid for vdev_%d",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "wma_peer_sta_kickout_event_handler",
        0);
      result = 4294967284LL;
      goto LABEL_12;
    }
    v58 = *(_DWORD *)(v21 + 12);
    if ( v58 )
    {
      if ( v58 != 3 )
      {
        if ( v58 == 4 )
        {
          v59 = vdev_bssid;
          v60 = (_BYTE *)_qdf_mem_malloc(0x14u, "wma_peer_sta_kickout_event_handler", 393);
          if ( !v60 )
          {
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: mem alloc failed for struct del_sta_context for TDLS peer: %02x:%02x:%02x:**:**:%02x",
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              "wma_peer_sta_kickout_event_handler",
              (unsigned __int8)v104,
              BYTE1(v104),
              BYTE2(v104),
              HIBYTE(v105));
            result = 4294967284LL;
            goto LABEL_12;
          }
          v69 = (__int64)v60;
          *v60 = 1;
          v60[1] = 0;
          qdf_mem_copy(v60 + 10, &v104, 6u);
          qdf_mem_copy((void *)(v69 + 4), v59, 6u);
          *(_WORD *)(v69 + 16) = 1;
          wma_send_msg(a1, 0x13C1u, v69, 0);
          goto LABEL_41;
        }
LABEL_30:
        v71 = (_BYTE *)_qdf_mem_malloc(0x14u, "wma_peer_sta_kickout_event_handler", 454);
        if ( !v71 )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: QDF MEM Alloc Failed for struct del_sta_context",
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            "wma_peer_sta_kickout_event_handler");
          result = 4294967284LL;
          goto LABEL_12;
        }
        *v71 = 0;
        v80 = (__int64)v71;
        v71[1] = 0;
        qdf_mem_copy(v71 + 10, &v104, 6u);
        qdf_mem_copy((void *)(v80 + 4), v39, 6u);
        v89 = *(_DWORD *)(v21 + 12);
        if ( v89 == 1 )
          v90 = 7;
        else
          v90 = 1;
        if ( v89 == 5 )
          v91 = 6;
        else
          v91 = v90;
        *(_WORD *)(v80 + 16) = v91;
        v92 = wmi_service_enabled(*(_QWORD *)a1, 0xACu, v81, v82, v83, v84, v85, v86, v87, v88);
        v93 = *(_BYTE *)(v21 + 16);
        v94 = (v92 & 1) == 0;
        v95 = *(unsigned __int16 *)(v80 + 16);
        if ( v94 )
          v93 -= 96;
        *(_BYTE *)(v80 + 18) = v93;
        wma_sta_kickout_event(v95, 0, &v104);
        wma_send_msg(a1, 0x13C1u, v80, 0);
        wma_lost_link_info_handler(a1, 0, (unsigned int)*(char *)(v80 + 18));
      }
    }
    else
    {
      v70 = *(_QWORD *)(a1 + 520);
      if ( *(_DWORD *)(v70 + 164) != 2
        || (*(_DWORD *)(v70 + 168) | 2) != 2
        || (unsigned int)qdf_mem_cmp(vdev_bssid, &v104, 6u) )
      {
        goto LABEL_30;
      }
      wma_sta_kickout_event(2, 0, &v104);
      qdf_trace_msg(
        0x36u,
        3u,
        "%s: WMI_PEER_STA_KICKOUT_REASON_UNSPECIFIED event for STA",
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        "wma_peer_sta_kickout_event_handler");
      wma_beacon_miss_handler(a1, 0, *(unsigned int *)(v21 + 16));
    }
LABEL_41:
    result = 0;
    goto LABEL_12;
  }
  LOBYTE(v23) = v104;
  LOBYTE(v26) = BYTE1(v104);
  LOBYTE(v27) = BYTE2(v104);
  LOBYTE(v28) = HIBYTE(v105);
LABEL_10:
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Not able to find BSSID for peer [%02x:%02x:%02x:**:**:%02x]",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "wma_peer_sta_kickout_event_handler",
    (unsigned __int8)v23,
    (unsigned __int8)v26,
    (unsigned __int8)v27,
    (unsigned __int8)v28);
LABEL_11:
  result = 4294967274LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
