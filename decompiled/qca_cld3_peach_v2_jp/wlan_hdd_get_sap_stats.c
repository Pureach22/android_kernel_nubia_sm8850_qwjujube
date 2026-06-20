__int64 __fastcall wlan_hdd_get_sap_stats(__int64 a1, __int64 a2)
{
  unsigned int station_stats; // w19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  station_stats = wlan_hdd_get_station_stats((__int64 *)a1);
  if ( station_stats )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to get SAP stats; status:%d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_hdd_get_sap_stats",
      station_stats);
  else
    wlan_hdd_fill_summary_stats(a1 + 2432, a2, *(unsigned __int8 *)(a1 + 8));
  return station_stats;
}
