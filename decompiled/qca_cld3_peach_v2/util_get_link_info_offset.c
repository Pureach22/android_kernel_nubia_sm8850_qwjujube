__int64 __fastcall util_get_link_info_offset(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x4
  __int64 v11; // x20
  const char *v13; // x2
  __int64 v14; // x20
  unsigned __int64 v15; // x8
  __int64 v16; // x11
  unsigned __int64 v17; // x20
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x10
  __int64 v20; // x8
  __int64 v21; // x10
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x19

  if ( !a1 )
  {
    v13 = "%s: ml_ie is null";
LABEL_11:
    qdf_trace_msg(0x15u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "util_get_link_info_offset");
    return 0;
  }
  if ( !a2 )
  {
    v14 = jiffies;
    if ( util_get_link_info_offset___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: is_ml_ie_valid is null",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "util_get_link_info_offset");
      util_get_link_info_offset___last_ticks = v14;
      return 0;
    }
    return 0;
  }
  v10 = *(unsigned __int8 *)(a1 + 1);
  if ( !*(_BYTE *)(a1 + 1) )
  {
    v13 = "%s: ml_ie_len is zero";
    goto LABEL_11;
  }
  if ( (unsigned int)v10 <= 4 )
  {
    v11 = jiffies;
    if ( util_get_link_info_offset___last_ticks_64 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: Length %zu octets is smaller than required for the fixed portion of Multi-Link element (%zu octets)",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "util_get_link_info_offset");
      util_get_link_info_offset___last_ticks_64 = v11;
      return 0;
    }
    return 0;
  }
  v15 = *(unsigned __int16 *)(a1 + 3);
  v16 = 12;
  v17 = v10 + 2;
  v18 = v15 >> 4;
  v19 = v15 >> 5;
  v20 = (v15 >> 5) & 1;
  v21 = v19 & 2;
  if ( (v18 & 1) != 0 )
    v16 = 13;
  v22 = v16
      + v20
      + v21
      + (((unsigned int)v18 >> 2) & 2)
      + (((unsigned int)v18 >> 3) & 2)
      + (unsigned __int64)(((unsigned int)v18 >> 5) & 1);
  v23 = v22 + (((unsigned int)v18 >> 5) & 2);
  if ( v23 <= v17 )
  {
    *a2 = 1;
  }
  else
  {
    *a2 = 0;
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: Invalid ML IE, expect min len: %zu, actual len: %zu",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "util_get_link_info_offset",
      v22 + (((unsigned int)v18 >> 5) & 2),
      v17);
  }
  if ( v23 >= v17 )
    return 0;
  else
    return (unsigned int)v23;
}
