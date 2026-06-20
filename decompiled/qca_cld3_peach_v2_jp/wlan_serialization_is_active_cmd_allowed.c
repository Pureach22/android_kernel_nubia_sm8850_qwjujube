__int64 __fastcall wlan_serialization_is_active_cmd_allowed(_DWORD *a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  char is_scan_pending_queue_empty; // w0

  if ( !wlan_serialization_get_pdev_from_cmd(a1) )
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: NULL pdev",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wlan_serialization_is_active_cmd_allowed");
    goto LABEL_8;
  }
  if ( !*a1 )
  {
    if ( (wlan_serialization_is_active_scan_cmd_allowed(a1) & 1) != 0 )
    {
      is_scan_pending_queue_empty = wlan_serialization_is_scan_pending_queue_empty(a1);
      return is_scan_pending_queue_empty & 1;
    }
LABEL_8:
    is_scan_pending_queue_empty = 0;
    return is_scan_pending_queue_empty & 1;
  }
  if ( (wlan_serialization_is_active_non_scan_cmd_allowed(a1) & 1) == 0 )
    goto LABEL_8;
  is_scan_pending_queue_empty = wlan_serialization_is_non_scan_pending_queue_empty(a1);
  return is_scan_pending_queue_empty & 1;
}
