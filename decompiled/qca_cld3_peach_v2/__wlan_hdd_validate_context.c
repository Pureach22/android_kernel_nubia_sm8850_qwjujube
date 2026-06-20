__int64 __fastcall _wlan_hdd_validate_context(
        __int64 a1,
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
  char driver_state; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x5
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  const char *v46; // x2
  const char *v47; // x2

  if ( !a1 )
  {
    v47 = "%s: HDD context is null (via %s)";
LABEL_15:
    qdf_trace_msg(0x33u, 2u, v47, a3, a4, a5, a6, a7, a8, a9, a10, "__wlan_hdd_validate_context", a2);
    return 4294967277LL;
  }
  if ( !*(_QWORD *)(a1 + 104) )
  {
    v47 = "%s: HDD config is null (via %s)";
    goto LABEL_15;
  }
  driver_state = cds_get_driver_state(a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = (unsigned int)cds_get_driver_state(v13, v14, v15, v16, v17, v18, v19, v20);
  if ( (driver_state & 8) != 0 )
  {
    v46 = "%s: Recovery in progress (via %s); state:0x%x";
    goto LABEL_12;
  }
  if ( (v21 & 4) != 0 )
  {
    v47 = "%s: Driver unload is in progress (via %s)";
    goto LABEL_15;
  }
  if ( (cds_get_driver_state(a3, a4, a5, a6, a7, a8, a9, a10) & 2) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Driver load is in progress (via %s)",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "__wlan_hdd_validate_context",
      a2);
    return 4294967285LL;
  }
  if ( (cds_get_driver_state(v22, v23, v24, v25, v26, v27, v28, v29) & 0x10) != 0 )
  {
    v21 = (unsigned int)cds_get_driver_state(v30, v31, v32, v33, v34, v35, v36, v37);
    v46 = "%s: Driver in bad state (via %s); state:0x%x";
    goto LABEL_12;
  }
  if ( cds_is_fw_down(v30, v31, v32, v33, v34, v35, v36, v37) )
  {
    v21 = (unsigned int)cds_get_driver_state(v38, v39, v40, v41, v42, v43, v44, v45);
    v46 = "%s: FW is down (via %s); state:0x%x";
LABEL_12:
    qdf_trace_msg(0x33u, 8u, v46, a3, a4, a5, a6, a7, a8, a9, a10, "__wlan_hdd_validate_context", a2, v21);
    return 4294967285LL;
  }
  if ( *(_BYTE *)(a1 + 7123) == 1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: WLAN is disabled by user space",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "__wlan_hdd_validate_context");
    return 4294967285LL;
  }
  return 0;
}
