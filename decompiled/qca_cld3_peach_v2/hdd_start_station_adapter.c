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
  _DWORD *v10; // x22
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w8
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w20
  const char *v30; // x2
  unsigned int v31; // w1
  unsigned int v32; // w0
  unsigned int v33; // w0
  __int64 result; // x0
  _DWORD *v35; // x21
  _DWORD *v36; // x20
  unsigned int v37; // w0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int inited; // w0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x8
  __int64 v56; // x9
  __int64 v57; // x10
  double v58; // d0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w21
  unsigned int v68; // w21
  unsigned int v69; // w26
  __int64 v70; // x8
  __int64 v71; // x9
  __int64 v72; // x10

  v10 = (_DWORD *)(a1 + 52832);
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
  if ( (*(_QWORD *)(*(_QWORD *)v10 + 5968LL) & 1) != 0 )
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
      *(unsigned __int8 *)(*(_QWORD *)v10 + 8LL));
    v32 = 0;
    return qdf_status_to_os_return(v32);
  }
  v19 = *(_DWORD *)(a1 + 40);
  if ( v19 == 16 || v19 == 7 )
    wlan_hdd_lpc_del_monitor_interface(*(_QWORD *)(a1 + 24), 0);
  v20 = hdd_adapter_fill_link_address(a1);
  if ( v20 )
  {
    v29 = v20;
    v30 = "%s: Link address derive failed";
    v31 = 8;
LABEL_10:
    qdf_trace_msg(0x33u, v31, v30, v21, v22, v23, v24, v25, v26, v27, v28, "hdd_start_station_adapter");
    v32 = v29;
    return qdf_status_to_os_return(v32);
  }
  v33 = hdd_adapter_check_duplicate_session(a1);
  if ( v33 )
  {
    v29 = v33;
    v30 = "%s: Duplicate session is existing with same mac address";
    v31 = 2;
    goto LABEL_10;
  }
  if ( a1
    && ((*(_QWORD *)(a1 + 1640) & 1) != 0 && (v35 = (_DWORD *)(a1 + 52840), a1 != -52840)
     || (*(_QWORD *)(a1 + 1640) & 2) != 0 && (v35 = (_DWORD *)(a1 + 58928), a1 != -58928)
     || (*(_QWORD *)(a1 + 1640) & 4) != 0 && (v35 = (_DWORD *)(a1 + 65016), a1 != -65016)) )
  {
    v36 = v10 + 2;
    while ( 1 )
    {
      v37 = hdd_vdev_create(v35);
      if ( v37 )
      {
        v67 = v37;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: failed to create vdev: %d",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "hdd_start_station_adapter",
          v37);
        result = v67;
        goto LABEL_34;
      }
      inited = hdd_init_station_mode(v35);
      if ( inited )
        break;
      if ( (unsigned __int8)(73 * ((unsigned int)((_DWORD)v35 - *v35 - 52840) >> 3) + 1) <= 2u )
      {
        v55 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v35 - *v35 - 52840) >> 3) + 1);
        v35 = nullptr;
        v56 = a1 + 52840 + 6088LL * (unsigned int)v55;
        do
        {
          if ( v35 )
            break;
          v57 = *(_QWORD *)(a1 + 1640) >> v55++;
          v35 = (_DWORD *)((v57 << 63 >> 63) & v56);
          v56 += 6088;
        }
        while ( v55 != 3 );
        if ( v35 )
          continue;
      }
      goto LABEL_29;
    }
    v68 = inited;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Error Initializing station mode: %d",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "hdd_start_station_adapter",
      inited);
    result = qdf_status_to_os_return(v68);
LABEL_34:
    if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 && v10 != (_DWORD *)-8LL
      || (*(_QWORD *)(a1 + 1640) & 2) != 0 && (v36 = (_DWORD *)(a1 + 58928), a1 != -58928)
      || (*(_QWORD *)(a1 + 1640) & 4) != 0 && (v36 = (_DWORD *)(a1 + 65016), a1 != -65016) )
    {
      do
      {
        v69 = result;
        hdd_vdev_destroy(v36);
        result = v69;
        if ( (unsigned __int8)(73 * ((unsigned int)((_DWORD)v36 - *v36 - 52840) >> 3) + 1) > 2u )
          break;
        v70 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v36 - *v36 - 52840) >> 3) + 1);
        v36 = nullptr;
        v71 = a1 + 52840 + 6088LL * (unsigned int)v70;
        do
        {
          if ( v36 )
            break;
          v72 = *(_QWORD *)(a1 + 1640) >> v70++;
          v36 = (_DWORD *)((v72 << 63 >> 63) & v71);
          v71 += 6088;
        }
        while ( v70 != 3 );
      }
      while ( v36 );
    }
  }
  else
  {
LABEL_29:
    v58 = hdd_adapter_reset_station_ctx(a1);
    hdd_set_netdev_flags(a1, v58);
    if ( (hdd_get_multi_client_ll_support(a1) & 1) != 0 )
      wlan_hdd_init_multi_client_info_table(a1);
    hdd_adapter_set_wlm_client_latency_level(a1);
    hdd_adapter_update_mlo_mgr_mac_addr(a1);
    hdd_restore_info_for_ssr(a1);
    qdf_trace_msg(0x33u, 8u, "%s: exit", v59, v60, v61, v62, v63, v64, v65, v66, "hdd_start_station_adapter");
    return 0;
  }
  return result;
}
