__int64 __fastcall wlan_ipa_uc_rt_debug_init(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x8

  qdf_mutex_create(a1 + 7160);
  *(_DWORD *)(a1 + 6256) = 0;
  qdf_mem_set((void *)(a1 + 4336), 0x780u, 0);
  v10 = *(_QWORD *)(a1 + 1464);
  *(_QWORD *)(a1 + 4160) = 0;
  *(_QWORD *)(a1 + 4152) = 0;
  *(_QWORD *)(a1 + 4144) = 0;
  *(_QWORD *)(a1 + 4136) = 0;
  *(_QWORD *)(a1 + 4128) = 0;
  if ( (*(_BYTE *)(v10 + 1) & 1) == 0 )
    return qdf_trace_msg(
             0x61u,
             8u,
             "%s: IPA RT debug is not enabled",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "wlan_ipa_uc_rt_debug_init");
  qdf_mc_timer_init(a1 + 6992, 0, (__int64)wlan_ipa_uc_rt_debug_host_fill, a1);
  qdf_mc_timer_start(a1 + 6992, 0x2710u);
  qdf_mc_timer_init(a1 + 4168, 0, (__int64)wlan_ipa_uc_rt_debug_handler, a1);
  return qdf_mc_timer_start(a1 + 4168, 0x12Cu);
}
