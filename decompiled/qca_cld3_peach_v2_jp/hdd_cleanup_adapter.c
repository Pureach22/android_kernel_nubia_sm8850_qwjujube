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
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x5
  unsigned __int64 v31; // x10

  if ( !a1 )
    return qdf_trace_msg(0x33u, 2u, "%s: adapter is Null", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_cleanup_adapter");
  v10 = *(_QWORD *)(a1 + 32);
  hdd_apf_context_destroy();
  v14 = 0;
  do
  {
    qdf_event_destroy(a1 + 55208 + v14, v13);
    v14 += 4528;
  }
  while ( !v14 );
  hdd_sta_info_deinit(a1 + 38848);
  hdd_sta_info_deinit(a1 + 38888);
  wlan_hdd_debugfs_csr_deinit(a1);
  result = hdd_debugfs_exit(a1);
  _X8 = (unsigned __int64 *)(a1 + 1624);
  __asm { PRFM            #0x11, [X8] }
  do
    v31 = __ldxr(_X8);
  while ( __stxr(v31 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
  if ( (*(_QWORD *)(a1 + 1624) & 1) != 0 )
  {
    v24 = *(unsigned int *)(a1 + 40);
    if ( (a2 & 1) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: hdd_unregister_netdevice(%s) type:%d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "hdd_cleanup_adapter",
        v10 + 296,
        v24);
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
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "hdd_cleanup_adapter",
        v10 + 296,
        v24);
      return unregister_netdev(v10);
    }
  }
  return result;
}
