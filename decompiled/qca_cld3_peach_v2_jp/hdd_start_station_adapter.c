__int64 __fastcall hdd_start_station_adapter(
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
  __int64 v10; // x22
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  int v20; // w8
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 result; // x0
  unsigned int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w20
  _DWORD *v34; // x21
  _DWORD *v35; // x20
  unsigned int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int inited; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x9
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 *v63; // x20
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
  unsigned int v80; // w0
  __int64 v81; // x4
  const char *v82; // x2
  unsigned int v83; // w0
  unsigned int v84; // w1
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  unsigned int v93; // w21
  unsigned int v94; // w21
  unsigned int v95; // w21
  _QWORD v96[3]; // [xsp+8h] [xbp-18h] BYREF

  v10 = a1 + 49152;
  v96[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter(%s)",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "hdd_start_station_adapter",
    *(_QWORD *)(a1 + 32) + 296LL);
  v19 = *(_QWORD *)(v10 + 3672);
  if ( (*(_QWORD *)(v19 + 4416) & 1) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: session is already opened, %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "hdd_start_station_adapter",
      *(unsigned __int8 *)(v19 + 8));
    result = qdf_status_to_os_return(0);
    goto LABEL_43;
  }
  v20 = *(_DWORD *)(a1 + 40);
  if ( v20 == 16 || v20 == 7 )
    wlan_hdd_lpc_del_monitor_interface(*(_QWORD *)(a1 + 24), 0);
  v96[1] = 0;
  if ( a1 && (v21 = *(_QWORD *)(a1 + 24)) != 0 )
    v22 = *(_QWORD *)(v21 + 16);
  else
    v22 = 0;
  v96[0] = a1 + 1617;
  v24 = sme_check_for_duplicate_session(v22, v96);
  if ( v24 )
  {
    v33 = v24;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Duplicate session is existing with same mac address",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "hdd_start_station_adapter");
    result = qdf_status_to_os_return(v33);
    goto LABEL_43;
  }
  if ( !a1 || (*(_QWORD *)(a1 + 1640) & 1) == 0 || (v34 = (_DWORD *)(v10 + 3680), v10 == -3680) )
  {
LABEL_20:
    if ( a1 )
      v54 = a1 + 52832;
    else
      v54 = 0;
    if ( v54 && v54 == a1 + 52832 )
    {
      qdf_mem_set((void *)(a1 + 53132), 6u, 0);
      *(_BYTE *)(a1 + 54489) = 8;
    }
    hdd_set_netdev_flags(a1);
    if ( (hdd_get_multi_client_ll_support(a1) & 1) != 0 )
    {
      *(_WORD *)(v10 + 2962) = 0;
      *(_BYTE *)(v10 + 2964) = 0;
      *(_QWORD *)(a1 + 52104) = 0;
      *(_BYTE *)(a1 + 52112) = 0;
      *(_QWORD *)(v10 + 2968) = 1;
      *(_QWORD *)(v10 + 2984) = 2;
      *(_QWORD *)(v10 + 3000) = 3;
      *(_BYTE *)(v10 + 2976) = 0;
      *(_WORD *)(v10 + 2978) = 0;
      *(_BYTE *)(v10 + 2980) = 0;
      *(_BYTE *)(v10 + 2992) = 0;
      *(_WORD *)(v10 + 2994) = 0;
      *(_BYTE *)(v10 + 2996) = 0;
      *(_BYTE *)(v10 + 3008) = 0;
      *(_WORD *)(v10 + 3010) = 0;
      *(_BYTE *)(v10 + 3012) = 0;
      *(_QWORD *)(v10 + 3016) = 4;
      *(_BYTE *)(v10 + 3024) = 0;
      *(_WORD *)(v10 + 3026) = 0;
      *(_BYTE *)(v10 + 3028) = 0;
    }
    v63 = *(__int64 **)(a1 + 24);
    if ( !v63 )
      goto LABEL_39;
    LOBYTE(v96[0]) = 0;
    if ( (unsigned int)mlme_get_cfg_wlm_reset(*v63, v96) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: could not get the wlm reset flag",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "hdd_adapter_set_wlm_client_latency_level");
      LOBYTE(v96[0]) = 0;
    }
    else if ( (v96[0] & 1) != 0 )
    {
      goto LABEL_38;
    }
    if ( (hdd_get_multi_client_ll_support(a1) & 1) != 0 )
    {
      v80 = wlan_hdd_set_wlm_client_latency_level(
              a1,
              0xFFFFFF,
              *(_WORD *)(v10 + 2946),
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79);
      if ( v80 )
      {
        v81 = v80;
        v82 = "%s: Fail to set latency level:%u";
LABEL_37:
        qdf_trace_msg(
          0x33u,
          3u,
          v82,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          "hdd_adapter_set_wlm_client_latency_level",
          v81);
      }
    }
    else
    {
      v83 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))sme_set_wlm_latency_level)(
              v63[2],
              *(unsigned __int8 *)(*(_QWORD *)(v10 + 3672) + 8LL),
              *(unsigned __int16 *)(v10 + 2946),
              0,
              0);
      if ( v83 )
      {
        v81 = v83;
        v82 = "%s: set wlm mode failed, %u";
        goto LABEL_37;
      }
    }
LABEL_38:
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: wlm initial mode %u",
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      "hdd_adapter_set_wlm_client_latency_level",
      *(unsigned __int16 *)(v10 + 2946));
LABEL_39:
    if ( (cds_get_driver_state(v55, v56, v57, v58, v59, v60, v61, v62) & 8) != 0 )
      v84 = *(_DWORD *)(v10 + 3668);
    else
      v84 = 0;
    hdd_set_vdev_phy_mode(a1, v84);
    qdf_trace_msg(0x33u, 8u, "%s: exit", v85, v86, v87, v88, v89, v90, v91, v92, "hdd_start_station_adapter");
    result = 0;
    goto LABEL_43;
  }
  v35 = (_DWORD *)(v10 + 3680);
  while ( 1 )
  {
    v36 = hdd_vdev_create(v34);
    if ( v36 )
    {
      v93 = v36;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to create vdev: %d",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "hdd_start_station_adapter",
        v36);
      result = v93;
      goto LABEL_46;
    }
    inited = hdd_init_station_mode(v34);
    if ( inited )
      break;
    if ( !(unsigned __int8)~(-910593773 * ((unsigned int)((_DWORD)v34 - *v34 - 52832) >> 4)) )
    {
      v34 = (_DWORD *)(v10 + 3680);
      if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 )
        continue;
    }
    goto LABEL_20;
  }
  v94 = inited;
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Error Initializing station mode: %d",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    "hdd_start_station_adapter",
    inited);
  result = qdf_status_to_os_return(v94);
LABEL_46:
  if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 )
  {
    v95 = result;
    do
      hdd_vdev_destroy(v35);
    while ( !(unsigned __int8)~(-910593773 * ((unsigned int)((_DWORD)v35 - *v35 - 52832) >> 4))
         && (*(_QWORD *)(a1 + 1640) & 1) != 0 );
    result = v95;
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
