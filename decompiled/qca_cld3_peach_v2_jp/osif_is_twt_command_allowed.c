__int64 __fastcall osif_is_twt_command_allowed(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w21
  unsigned int v13; // w19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x21
  __int64 v42; // x22
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x20

  v11 = *(_DWORD *)(a2 + 16);
  if ( (v11 & 0xFFFFFFFD) == 1 )
    return 0;
  if ( (v11 & 0xFFFFFFFD) != 0 )
    return 4294967201LL;
  v13 = *(unsigned __int8 *)(a2 + 104);
  if ( !wlan_cm_is_vdev_connected(a2, a4, a5, a6, a7, a8, a9, a10, a11) )
  {
    v42 = jiffies;
    if ( osif_is_twt_command_allowed___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Not associated!, vdev %d mode %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "osif_is_twt_command_allowed",
        *(unsigned __int8 *)(a2 + 104),
        v11);
      osif_is_twt_command_allowed___last_ticks = v42;
    }
    return 4294967285LL;
  }
  if ( (wlan_cm_host_roam_in_progress(a1, v13) & 1) != 0 )
    return 4294967280LL;
  if ( !(unsigned int)wlan_get_vdev_status(a2, v24, v25, v26, v27, v28, v29, v30, v31) )
  {
    if ( a3 != 1 || (osif_twt_setup_conc_allowed(a1, a2) & 1) != 0 )
      return 0;
    v51 = jiffies;
    if ( osif_is_twt_command_allowed___last_ticks_100 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: TWT setup reject: SCC or MCC concurrency exists",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "osif_is_twt_command_allowed");
      osif_is_twt_command_allowed___last_ticks_100 = v51;
    }
    return 4294967285LL;
  }
  v40 = jiffies;
  if ( osif_is_twt_command_allowed___last_ticks_98 - jiffies + 125 >= 0 )
    return 4294967280LL;
  qdf_trace_msg(
    0x48u,
    2u,
    "%s: vdev:%d Scan in progress",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "osif_is_twt_command_allowed",
    v13);
  osif_is_twt_command_allowed___last_ticks_98 = v40;
  return 4294967280LL;
}
