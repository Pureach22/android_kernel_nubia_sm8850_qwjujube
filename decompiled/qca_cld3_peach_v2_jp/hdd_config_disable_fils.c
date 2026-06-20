__int64 __fastcall hdd_config_disable_fils(
        unsigned __int8 *a1,
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
  __int64 v10; // x29
  __int64 v11; // x30
  int v13; // w20
  __int64 *v15; // x22
  unsigned int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w19
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7

  if ( *(_DWORD *)(*(_QWORD *)a1 + 40LL) )
    return 0;
  v13 = *(unsigned __int8 *)(a2 + 4);
  v15 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: %u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_config_disable_fils",
    *(unsigned __int8 *)(a2 + 4),
    v10,
    v11);
  v16 = wlan_mlme_set_fils_enabled_info(*v15, v13 == 0);
  if ( v16 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not set fils enabled info, %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "hdd_config_disable_fils",
      v16);
  v25 = wlan_mlme_set_enable_bcast_probe_rsp(*v15, v13 == 0);
  if ( v25 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not set enable bcast probe resp info, %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "hdd_config_disable_fils",
      v25);
  v34 = wma_cli_set_command(a1[8], 108, v13 == 0, 1);
  if ( v34 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to set enable bcast probe resp, %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "hdd_config_disable_fils",
      v34);
  return qdf_status_to_os_return(v34);
}
