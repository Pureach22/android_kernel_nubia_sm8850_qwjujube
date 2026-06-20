__int64 __fastcall wlan_ipa_uc_rt_debug_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v11; // x0
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
  __int64 v28; // x0
  __int64 v29; // x8
  void (*v30)(void); // x8

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 1464) + 1LL) & 1) == 0 )
    return qdf_trace_msg(
             0x61u,
             8u,
             "%s: IPA RT debug is not enabled",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "wlan_ipa_uc_rt_debug_handler");
  v11 = _qdf_mem_malloc(0x7D00u, "wlan_ipa_uc_rt_debug_handler", 116);
  if ( v11 )
  {
    _qdf_mem_free(v11);
  }
  else
  {
    wlan_ipa_uc_rt_debug_host_dump(a1, v12, v13, v14, v15, v16, v17, v18, v19);
    qdf_mutex_acquire(a1 + 7224);
    if ( wlan_ipa_is_fw_wdi_activated(a1) && (*(_BYTE *)(a1 + 3720) & 1) == 0 )
    {
      v28 = *(_QWORD *)(a1 + 1456);
      *(_DWORD *)(a1 + 4120) = 1;
      if ( v28 && *(_QWORD *)v28 && (v29 = *(_QWORD *)(*(_QWORD *)v28 + 152LL)) != 0 )
      {
        v30 = *(void (**)(void))(v29 + 56);
        if ( v30 )
        {
          if ( *((_DWORD *)v30 - 1) != 261447488 )
            __break(0x8228u);
          v30();
        }
      }
      else
      {
        qdf_trace_msg(0x45u, 1u, "%s invalid instance", v20, v21, v22, v23, v24, v25, v26, v27, "cdp_ipa_get_stat");
      }
    }
    qdf_mutex_release(a1 + 7224);
  }
  return qdf_mc_timer_start(a1 + 4168, 0x12Cu);
}
