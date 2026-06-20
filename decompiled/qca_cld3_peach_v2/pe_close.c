__int64 __fastcall pe_close(__int64 a1)
{
  __int64 v1; // x29
  __int64 v2; // x30
  unsigned int v4; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  unsigned __int16 v23; // w8
  unsigned __int8 v24; // w20
  __int64 v25; // x0
  __int64 v27; // [xsp+8h] [xbp-28h]

  if ( *(_DWORD *)a1 != 1 )
  {
    v27 = v2;
    qdf_hang_event_unregister_notifier(&pe_hang_event_notifier);
    lim_cleanup_mlm(a1);
    lim_cleanup(a1);
    v4 = wlan_scan_register_mbssid_cb(*(_QWORD *)(a1 + 21624), 0);
    if ( v4 )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: failed with status code %08d [x%08x]",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "lim_unregister_scan_mbssid_callback",
        v4,
        v4,
        v1,
        v27);
    v13 = ucfg_scan_register_bcn_cb(*(_QWORD *)(a1 + 21624), 0, 1u);
    if ( v13 )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: failed with status code %08d [x%08x]",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "lim_unregister_sap_bcn_callback",
        v13,
        v13);
    wlan_reg_unregister_ctry_change_callback(*(_QWORD *)(a1 + 21624), (__int64)lim_update_tx_pwr_on_ctry_change_cb);
    wlan_reg_unregister_c2c_detect_callback(*(_QWORD *)(a1 + 21624), (__int64)lim_update_tpc_bcn_on_c2c_detect_cb);
    wlan_reg_unregister_is_chan_connected_callback(*(_QWORD *)(a1 + 21624), (__int64)lim_get_connected_chan_for_mode);
    v22 = *(_QWORD *)(a1 + 12400);
    if ( v22 )
    {
      _qdf_mem_free(v22);
      *(_QWORD *)(a1 + 12400) = 0;
    }
    v23 = *(_WORD *)(a1 + 3992);
    if ( v23 )
    {
      v24 = 0;
      do
      {
        if ( *(_BYTE *)(*(_QWORD *)(a1 + 12264) + 14000LL * v24 + 70) == 1 )
        {
          pe_delete_session(a1);
          v23 = *(_WORD *)(a1 + 3992);
        }
        ++v24;
      }
      while ( v23 > (unsigned int)v24 );
    }
    _qdf_mem_free(*(_QWORD *)(a1 + 1336));
    v25 = *(_QWORD *)(a1 + 12264);
    *(_QWORD *)(a1 + 1336) = 0;
    _qdf_mem_free(v25);
    *(_QWORD *)(a1 + 12264) = 0;
  }
  return 0;
}
