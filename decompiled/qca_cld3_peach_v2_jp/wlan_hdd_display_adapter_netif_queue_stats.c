__int64 __fastcall wlan_hdd_display_adapter_netif_queue_stats(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  _QWORD *v13; // x26
  _DWORD *v14; // x27
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  __int64 v32; // x28
  __int64 v33; // x8
  __int64 v34; // x21
  __int64 v35; // x22
  unsigned int v37; // w23
  unsigned int v38; // w22
  unsigned int v39; // w0
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
  __int64 v56; // x25
  __int64 v57; // x19
  __int64 v58; // x0
  unsigned int v59; // w22
  unsigned int v60; // w23
  __int64 v61; // t1
  __int64 v62; // x24
  unsigned int v63; // w0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int v73; // w21
  unsigned int v74; // w0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // x22
  __int64 i; // x21
  unsigned int v93; // w24
  __int64 v94; // x25
  __int64 v95; // x0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // [xsp+10h] [xbp-10h]
  unsigned int v105; // [xsp+18h] [xbp-8h]

  v2 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 32) + 1096LL);
  v3 = _qdf_mem_malloc(15 * v2, "wlan_hdd_display_adapter_netif_queue_stats", 14125);
  if ( !v3 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Mem alloc failure for queue status buffer - num_queues:%d mode:%d",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "wlan_hdd_display_adapter_netif_queue_stats",
             (unsigned int)v2,
             *(unsigned int *)(a1 + 40));
  v12 = v3;
  v104 = a1 + 40960;
  v13 = (_QWORD *)(a1 + 51768);
  v14 = (_DWORD *)(a1 + 42092);
  qdf_trace_msg(0x33u, 8u, "Netif queue operation statistics:", v4, v5, v6, v7, v8, v9, v10, v11);
  qdf_trace_msg(
    0x33u,
    8u,
    "vdev_id %d device mode %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL),
    *(unsigned int *)(a1 + 40));
  qdf_trace_msg(
    0x33u,
    8u,
    "Current pause_map %x",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    *(unsigned int *)(a1 + 42092));
  v105 = v2;
  v31 = jiffies - *(_QWORD *)(a1 + 42104);
  v32 = jiffies - *(_QWORD *)(a1 + 42112);
  if ( *(_DWORD *)(a1 + 42092) )
  {
    v33 = *(_QWORD *)(a1 + 42120);
    v34 = *(_QWORD *)(a1 + 42128);
    v35 = v33 + v32;
  }
  else
  {
    v35 = *(_QWORD *)(a1 + 42120);
    v34 = *(_QWORD *)(a1 + 42128) + v32;
  }
  v37 = jiffies_to_msecs(v31);
  v38 = jiffies_to_msecs(v35);
  v39 = jiffies_to_msecs(v34);
  qdf_trace_msg(
    0x33u,
    8u,
    "Total: %ums Pause: %ums Unpause: %ums",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v37,
    v38,
    v39);
  qdf_trace_msg(0x33u, 8u, "reason_type: pause_cnt: unpause_cnt: pause_time", v48, v49, v50, v51, v52, v53, v54, v55);
  v56 = -17;
  do
  {
    if ( ((*v14 >> (v56 + 18)) & 1) != 0 )
      v57 = v32;
    else
      v57 = 0;
    v58 = ((__int64 (*)(void))hdd_reason_type_to_string)();
    v59 = *((_DWORD *)v13 - 2);
    v60 = *((_DWORD *)v13 - 1);
    v61 = *v13;
    v13 += 2;
    v62 = v58;
    v63 = jiffies_to_msecs(v61 + v57);
    qdf_trace_msg(0x33u, 8u, "%s: %d: %d: %ums", v64, v65, v66, v67, v68, v69, v70, v71, v62, v59, v60, v63);
  }
  while ( !__CFADD__(v56++, 1) );
  v73 = *(unsigned __int8 *)(v104 + 1176);
  v74 = jiffies_to_msecs(jiffies);
  qdf_trace_msg(
    0x33u,
    8u,
    "Netif queue operation history: Total entries: %d current index %d(-1) time %u",
    v75,
    v76,
    v77,
    v78,
    v79,
    v80,
    v81,
    v82,
    25,
    v73,
    v74);
  qdf_trace_msg(
    0x33u,
    8u,
    "%2s%20s%50s%30s%10s  %s",
    v83,
    v84,
    v85,
    v86,
    v87,
    v88,
    v89,
    v90,
    "#",
    "time(ms)",
    "action_type",
    "reason_type",
    "pause_map",
    "netdev-queue-status");
  v91 = v104 + 1184;
  for ( i = 0; i != 25; ++i )
  {
    if ( *(_QWORD *)v91 )
    {
      ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))wlan_hdd_dump_queue_history_state)(v91, v105, v12, 8);
      v93 = jiffies_to_msecs(*(_QWORD *)v91);
      v94 = hdd_action_type_to_string(*(unsigned __int16 *)(v91 + 8));
      v95 = hdd_reason_type_to_string(*(unsigned __int16 *)(v91 + 10));
      qdf_trace_msg(
        0x33u,
        8u,
        "%2d%20u%50s%30s%10x  %s",
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        (unsigned int)i,
        v93,
        v94,
        v95,
        *(unsigned int *)(v91 + 12),
        v12);
    }
    v91 += 384;
  }
  return _qdf_mem_free(v12);
}
