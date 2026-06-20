__int64 hdd_get_rssi_snr_by_bssid()
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

  result = sme_get_rssi_snr_by_bssid();
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: sme_get_rssi_snr_by_bssid failed",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      "hdd_get_rssi_snr_by_bssid");
    return 4294967274LL;
  }
  return result;
}
