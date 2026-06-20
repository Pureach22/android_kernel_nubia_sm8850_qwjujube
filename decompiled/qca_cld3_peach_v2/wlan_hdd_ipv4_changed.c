__int64 __fastcall wlan_hdd_ipv4_changed(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _QWORD *v28; // x20
  __int64 v30; // x21
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x0
  _QWORD v40[2]; // [xsp+0h] [xbp-10h] BYREF

  v40[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = **(_QWORD **)(a3 + 24);
  v40[0] = 0;
  if ( !(unsigned int)_osif_vdev_sync_op_start(v3, v40, "wlan_hdd_ipv4_changed") )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", v4, v5, v6, v7, v8, v9, v10, v11, "__wlan_hdd_ipv4_changed", v3 + 296);
    if ( !(unsigned int)_hdd_validate_adapter(
                          v3 + 2688,
                          (__int64)"__wlan_hdd_ipv4_changed",
                          v12,
                          v13,
                          v14,
                          v15,
                          v16,
                          v17,
                          v18,
                          v19)
      && *(_QWORD *)(v3 + 2720) == v3 )
    {
      v28 = *(_QWORD **)(v3 + 2712);
      if ( !(unsigned int)_wlan_hdd_validate_context(
                            (__int64)v28,
                            (__int64)"__wlan_hdd_ipv4_changed",
                            v20,
                            v21,
                            v22,
                            v23,
                            v24,
                            v25,
                            v26,
                            v27)
        && (*(_DWORD *)(v3 + 2728) | 2) == 2 )
      {
        v30 = v28[2];
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: invoking sme_dhcp_done_ind",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "hdd_dhcp_v4_done_ind");
        sme_dhcp_done_ind(v30, *(unsigned __int8 *)(*(_QWORD *)(v3 + 55520) + 8LL));
        if ( (ucfg_pmo_is_arp_offload_enabled(*v28) & 1) != 0 )
        {
          v39 = hdd_lookup_ifaddr(v3 + 2688);
          if ( v39 && *(_DWORD *)(v39 + 48) )
            queue_work_on(32, system_wq, v3 + 2736);
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Offload not enabled",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "__wlan_hdd_ipv4_changed");
        }
      }
    }
    qdf_trace_msg(0x33u, 8u, "%s: exit", v20, v21, v22, v23, v24, v25, v26, v27, "__wlan_hdd_ipv4_changed");
    _osif_vdev_sync_op_stop(v40[0], "wlan_hdd_ipv4_changed");
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
