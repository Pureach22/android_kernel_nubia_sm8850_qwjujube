__int64 __fastcall wlan_parse_bss_description_ies(
        __int64 a1,
        unsigned __int16 *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16)
{
  unsigned int v16; // w4
  __int64 v17; // x20
  __int64 v18; // x4
  __int64 v19; // x20
  int v20; // w8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0

  if ( !a2 )
  {
    v19 = jiffies;
    if ( wlan_get_ielen_from_bss_description___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Bss_desc is NULL",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_get_ielen_from_bss_description");
      v18 = 0;
      wlan_get_ielen_from_bss_description___last_ticks = v19;
      goto LABEL_11;
    }
    goto LABEL_6;
  }
  v16 = *a2;
  if ( v16 <= 0x66 )
  {
    v17 = jiffies;
    if ( wlan_get_ielen_from_bss_description___last_ticks_131 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Invalid bss_desc len:%d ie_fields_offset:%d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_get_ielen_from_bss_description");
      v18 = 0;
      wlan_get_ielen_from_bss_description___last_ticks_131 = v17;
LABEL_11:
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: BSS description has invalid IE : %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_parse_bss_description_ies",
        v18);
      return 16;
    }
LABEL_6:
    v18 = 0;
    goto LABEL_11;
  }
  v18 = (unsigned __int16)(v16 - 102);
  if ( !a3 )
    goto LABEL_11;
  v20 = dot11f_unpack_beacon_i_es(a1, (__int64)(a2 + 52), (unsigned int)v18, a3, 0, a14, a15, a16);
  result = 0;
  if ( (v20 & 0x10000000) == 0 )
    return result;
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Beacon IE parsing failed",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "wlan_parse_bss_description_ies");
  return 16;
}
