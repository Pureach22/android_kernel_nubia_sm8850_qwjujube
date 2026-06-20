__int64 __fastcall wlan_hdd_ipv6_changed(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v30; // x21
  int v31; // w0
  __int64 v32; // x20
  unsigned int v33; // w21
  _QWORD v34[2]; // [xsp+0h] [xbp-10h] BYREF

  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = **(_QWORD **)(a3 + 184);
  v34[0] = 0;
  if ( !(unsigned int)_osif_vdev_sync_op_start(v4, v34, "wlan_hdd_ipv6_changed") )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", v5, v6, v7, v8, v9, v10, v11, v12, "__wlan_hdd_ipv6_changed", v4 + 296);
    if ( !(unsigned int)_hdd_validate_adapter(
                          v4 + 2688,
                          (__int64)"__wlan_hdd_ipv6_changed",
                          v13,
                          v14,
                          v15,
                          v16,
                          v17,
                          v18,
                          v19,
                          v20)
      && *(_QWORD *)(v4 + 2720) == v4 )
    {
      v30 = *(_QWORD *)(v4 + 2712);
      v31 = _wlan_hdd_validate_context(v30, (__int64)"__wlan_hdd_ipv6_changed", v21, v22, v23, v24, v25, v26, v27, v28);
      if ( a2 == 1 && !v31 && (*(_DWORD *)(v4 + 2728) | 2) == 2 )
      {
        v32 = *(_QWORD *)(v30 + 16);
        v33 = *(unsigned __int8 *)(*(_QWORD *)(v4 + 55512) + 8LL);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: invoking sme_dhcp_done_ind",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "hdd_dhcp_v6_done_ind");
        sme_dhcp_done_ind(v32, v33);
        queue_work_on(32, system_wq, v4 + 2768);
      }
    }
    qdf_trace_msg(0x33u, 8u, "%s: exit", v21, v22, v23, v24, v25, v26, v27, v28, "__wlan_hdd_ipv6_changed");
    _osif_vdev_sync_op_stop(v34[0], "wlan_hdd_ipv6_changed");
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
