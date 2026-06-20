__int64 __fastcall dp_soc_detach_wifi3(__int64 *a1)
{
  void (*v1)(void); // x8
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x1
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  v1 = (void (*)(void))a1[144];
  if ( *((_DWORD *)v1 - 1) != -1941278151 )
    __break(0x8228u);
  v1();
  qdf_ssr_driver_dump_unregister_region("wlan_cfg_ctx");
  qdf_ssr_driver_dump_unregister_region("dp_soc");
  qdf_ssr_driver_dump_unregister_region("tcl_wbm_map_array");
  wlan_minidump_remove(v3, v4, v5, v6, v7, v8, v9, v10, a1[5], 840, a1[2]);
  ((void (__fastcall *)(__int64))hif_rtpm_deregister)(4);
  ((void (__fastcall *)(__int64))hif_rtpm_deregister)(5);
  if ( (wlan_cfg_is_ipa_enabled(a1[5]) & 1) != 0 )
    dp_srng_free((__int64)a1, (__int64)(a1 + 2311), v12, v13, v14, v15, v16, v17, v18, v19);
  if ( *(_DWORD *)(a1[5] + 132) )
  {
    _qdf_mem_free(a1[2517]);
    _qdf_mem_free(a1[2518]);
    _qdf_mem_free(a1[2519]);
    _qdf_mem_free(a1[2520]);
  }
  dp_sysfs_deinitialize_stats((__int64)a1, v11, v12, v13, v14, v15, v16, v17, v18, v19);
  wlan_dp_lapb_flow_detach(a1);
  ((void (__fastcall *)(__int64 *))dp_soc_swlm_detach)(a1);
  ((void (__fastcall *)(__int64 *))dp_soc_tx_desc_sw_pools_free)(a1);
  ((void (__fastcall *)(__int64 *))dp_soc_srng_free)(a1);
  dp_hw_link_desc_ring_free(a1);
  ((void (__fastcall *)(__int64 *, __int64))dp_hw_link_desc_pool_banks_free)(a1, 0xFFFFFFFFLL);
  wlan_cfg_soc_detach(a1[5]);
  dp_mon_soc_detach(a1);
  _qdf_mem_free(*a1);
  return _qdf_mem_free((__int64)a1);
}
