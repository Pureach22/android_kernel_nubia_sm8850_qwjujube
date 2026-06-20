__int64 __fastcall hdd_close_all_adapters(
        __int64 *a1,
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x25
  __int64 v30; // x28
  int v31; // w27
  char *v32; // x24
  __int64 v33; // x24
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x25
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  _QWORD v60[2]; // [xsp+0h] [xbp-10h] BYREF

  v60[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v60[0] = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_close_all_adapters");
  while ( !(unsigned int)hdd_get_front_adapter(a1, v60) )
  {
    v29 = 0;
    v30 = v60[0] + 52524LL;
    do
    {
      v31 = 50;
      while ( *(_DWORD *)(v30 + 4 * v29) )
      {
        v32 = net_dev_ref_debug_string_from_id_strings[v29];
        qdf_trace_msg(
          0x33u,
          4u,
          "%s: net_dev held for debug id %s",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "hdd_check_for_net_dev_ref_leak",
          v32);
        qdf_sleep();
        if ( !--v31 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: net_dev hold reference leak detected for debug id: %s",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "hdd_check_for_net_dev_ref_leak",
            v32);
          break;
        }
      }
      ++v29;
    }
    while ( v29 != 68 );
    hdd_remove_front_adapter(a1, v60);
    v33 = v60[0];
    v34 = osif_vdev_sync_unregister(*(_QWORD *)(v60[0] + 32LL));
    if ( v34 )
    {
      v43 = v34;
      v44 = osif_vdev_sync_wait_for_ops();
      wlan_hdd_release_intf_addr((__int64)a1, (unsigned __int8 *)(v33 + 1617), v44, v45, v46, v47, v48, v49, v50, v51);
      _hdd_close_adapter(a1, v33, a2 & 1, v52, v53, v54, v55, v56, v57, v58, v59);
      osif_vdev_sync_destroy(v43);
    }
    else
    {
      wlan_hdd_release_intf_addr((__int64)a1, (unsigned __int8 *)(v33 + 1617), v35, v36, v37, v38, v39, v40, v41, v42);
      _hdd_close_adapter(a1, v33, a2 & 1, v21, v22, v23, v24, v25, v26, v27, v28);
    }
  }
  result = qdf_trace_msg(0x33u, 8u, "%s: exit", v12, v13, v14, v15, v16, v17, v18, v19, "hdd_close_all_adapters");
  _ReadStatusReg(SP_EL0);
  return result;
}
