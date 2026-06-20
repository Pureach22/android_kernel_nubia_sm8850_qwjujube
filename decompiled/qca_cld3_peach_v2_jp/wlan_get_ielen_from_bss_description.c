__int64 __fastcall wlan_get_ielen_from_bss_description(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x4
  __int64 result; // x0
  __int64 v11; // x20
  __int64 v12; // x20

  if ( a1 )
  {
    v9 = *a1;
    result = (unsigned int)(v9 - 102);
    if ( (unsigned int)v9 > 0x66 )
      return result;
    v11 = jiffies;
    if ( wlan_get_ielen_from_bss_description___last_ticks_131 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Invalid bss_desc len:%d ie_fields_offset:%d",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wlan_get_ielen_from_bss_description",
        v9,
        104);
      wlan_get_ielen_from_bss_description___last_ticks_131 = v11;
      return 0;
    }
    return 0;
  }
  v12 = jiffies;
  if ( wlan_get_ielen_from_bss_description___last_ticks - jiffies + 125 >= 0 )
    return 0;
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Bss_desc is NULL",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_get_ielen_from_bss_description");
  wlan_get_ielen_from_bss_description___last_ticks = v12;
  return 0;
}
