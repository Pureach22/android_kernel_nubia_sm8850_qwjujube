__int64 __fastcall hdd_set_mon_rx_cb(__int64 a1)
{
  __int64 *v1; // x20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _DWORD *v11; // x21
  unsigned int inited; // w0
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x10

  v1 = *(__int64 **)(a1 + 2712);
  if ( (unsigned int)cds_get_conparam() != 4
    && ((wlan_mlme_is_sta_mon_conc_supported(*v1) & 1) != 0 || ucfg_dp_is_local_pkt_capture_enabled()) )
  {
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: Acquire wakelock for STA + monitor mode",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "hdd_set_mon_rx_cb");
    qdf_wake_lock_acquire((__int64)(v1 + 411), 0x16u);
    hdd_lpc_disable_powersave((__int64)v1);
    qdf_runtime_pm_prevent_suspend(v1 + 211);
  }
  if ( (*(_QWORD *)(a1 + 4328) & 1) != 0 && (v11 = (_DWORD *)(a1 + 55528), a1 != -55528)
    || (*(_QWORD *)(a1 + 4328) & 2) != 0 && (v11 = (_DWORD *)(a1 + 61616), a1 != -61616)
    || (inited = 16, (*(_QWORD *)(a1 + 4328) & 4) != 0) && (v11 = (_DWORD *)(a1 + 67704), a1 != -67704) )
  {
    while ( 1 )
    {
      inited = wlan_hdd_init_mon_link(v1, (__int64)v11, v3, v4, v5, v6, v7, v8, v9, v10);
      if ( inited )
        break;
      if ( (unsigned __int8)(73 * ((unsigned int)((_DWORD)v11 - *v11 - 52840) >> 3) + 1) <= 2u )
      {
        v13 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v11 - *v11 - 52840) >> 3) + 1);
        v11 = nullptr;
        v14 = a1 + 55528 + 6088LL * (unsigned int)v13;
        do
        {
          if ( v11 )
            break;
          v15 = *(_QWORD *)(a1 + 4328) >> v13++;
          v11 = (_DWORD *)((v15 << 63 >> 63) & v14);
          v14 += 6088;
        }
        while ( v13 != 3 );
        if ( v11 )
          continue;
      }
      inited = 0;
      return qdf_status_to_os_return(inited);
    }
  }
  return qdf_status_to_os_return(inited);
}
