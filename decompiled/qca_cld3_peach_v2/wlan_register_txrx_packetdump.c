__int64 wlan_register_txrx_packetdump()
{
  __int64 result; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  __int64 v9; // x8
  void (*v10)(void); // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x0
  __int64 v28; // [xsp+0h] [xbp-20h] BYREF
  _BYTE v29[10]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v30; // [xsp+18h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _cds_get_context(71, "wlan_register_txrx_packetdump");
  if ( result )
  {
    if ( *(_QWORD *)result && (v9 = *(_QWORD *)(*(_QWORD *)result + 64LL)) != 0 )
    {
      v10 = *(void (**)(void))(v9 + 184);
      if ( v10 )
      {
        if ( *((_DWORD *)v10 - 1) != -781202089 )
          __break(0x8228u);
        v10();
      }
    }
    else
    {
      qdf_trace_msg(0x45u, 1u, "%s invalid instance", v1, v2, v3, v4, v5, v6, v7, v8, "cdp_register_packetdump_cb");
    }
    wma_register_packetdump_callback(tx_packetdump_cb, rx_packetdump_cb);
    *(_WORD *)v29 = 0x8000;
    *(_QWORD *)&v29[2] = 0x8000B0000LL;
    qdf_trace_msg(
      0x33u,
      8u,
      "fate Tx-Rx %s: type: %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "send_packetdump_monitor",
      1,
      256,
      *(_QWORD *)v29,
      0,
      v30);
    v27 = wlan_pkt_stats_to_logger_thread(
            (unsigned __int16 *)v29,
            &v28,
            nullptr,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26);
    gtx_count = 0;
    grx_count = 0;
    result = csr_packetdump_timer_start(v27);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
