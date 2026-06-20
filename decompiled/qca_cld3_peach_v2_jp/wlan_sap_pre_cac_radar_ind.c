__int64 __fastcall wlan_sap_pre_cac_radar_ind(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: sapdfs: Radar detect on pre cac:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_sap_pre_cac_radar_ind",
    *(unsigned __int8 *)(a1 + 12));
  if ( (*(_BYTE *)(a1 + 1627) & 1) == 0 )
  {
    qdf_mc_timer_stop(a2 + 14640);
    qdf_mc_timer_destroy(a2 + 14640);
  }
  *(_BYTE *)(a2 + 14809) = 0;
  return wlan_pre_cac_handle_radar_ind(*(_QWORD *)(a1 + 16));
}
