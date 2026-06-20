__int64 __fastcall wifi_pos_get_ch_info(__int64 a1, unsigned __int16 *a2)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  wlan_objmgr_iterate_obj_list(a1, 1, &wifi_pos_pdev_iterator, (__int64)a2, 1, 0xDu);
  return qdf_trace_msg(0x25u, 8u, "%s: num channels: %d", v3, v4, v5, v6, v7, v8, v9, v10, "wifi_pos_get_ch_info", *a2);
}
