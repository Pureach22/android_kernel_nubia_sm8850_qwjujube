__int64 __fastcall wlan_dp_intf_get_pkt_type_bitmap_value(
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
  __int64 v10; // x20

  if ( a1 )
    return *(unsigned int *)(*(_QWORD *)(a1 + 32) + 3076LL);
  v10 = jiffies;
  if ( wlan_dp_intf_get_pkt_type_bitmap_value___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: DP Link is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_dp_intf_get_pkt_type_bitmap_value");
    wlan_dp_intf_get_pkt_type_bitmap_value___last_ticks = v10;
  }
  return 0;
}
