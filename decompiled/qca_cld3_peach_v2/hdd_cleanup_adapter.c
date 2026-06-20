__int64 __fastcall hdd_cleanup_adapter(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  __int64 v13; // x1
  __int64 v14; // x22
  __int64 v15; // x23
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x5
  unsigned __int64 v32; // x10

  if ( !a1 )
    return qdf_trace_msg(0x33u, 2u, "%s: adapter is Null", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_cleanup_adapter");
  v10 = *(_QWORD *)(a1 + 32);
  hdd_apf_context_destroy();
  v14 = 0;
  v15 = a1 + 52840;
  do
  {
    if ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v14 >> 3)) > 2 )
      break;
    qdf_event_destroy(v15 + 2648, v13);
    v15 += 6088;
    v14 += 6088;
  }
  while ( v15 );
  hdd_sta_info_deinit(a1 + 38848);
  hdd_sta_info_deinit(a1 + 38888);
  wlan_hdd_debugfs_csr_deinit(a1);
  result = hdd_debugfs_exit(a1);
  _X8 = (unsigned __int64 *)(a1 + 1624);
  __asm { PRFM            #0x11, [X8] }
  do
    v32 = __ldxr(_X8);
  while ( __stxr(v32 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
  if ( (*(_QWORD *)(a1 + 1624) & 1) != 0 )
  {
    v25 = *(unsigned int *)(a1 + 40);
    if ( (a2 & 1) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: hdd_unregister_netdevice(%s) type:%d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "hdd_cleanup_adapter",
        v10 + 296,
        v25);
      if ( *(_BYTE *)(a1 + 52797) == 1 )
      {
        result = cfg80211_unregister_wdev(*(_QWORD *)(v10 + 992));
        *(_BYTE *)(a1 + 52797) = 0;
      }
      else
      {
        return unregister_netdevice_queue(v10, 0);
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: unregister_netdev(%s) type:%d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "hdd_cleanup_adapter",
        v10 + 296,
        v25);
      return unregister_netdev(v10);
    }
  }
  return result;
}
