__int64 __fastcall hdd_map_nl_chan_width(__int64 a1)
{
  int v1; // w19
  char vht_ch_width; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v12; // w9

  v1 = a1;
  vht_ch_width = wma_get_vht_ch_width(a1);
  if ( v1 <= 3 )
  {
    if ( (unsigned int)v1 < 2 )
      return 0;
    if ( v1 == 2 )
      return 1;
    if ( v1 == 3 )
      return 2;
    goto LABEL_23;
  }
  if ( v1 > 5 )
  {
    if ( v1 == 6 )
      return 5;
    if ( v1 == 7 )
      return 6;
LABEL_23:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid channel width %d, setting to default",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_hdd_map_nl_chan_width",
      (unsigned int)v1);
    return 8;
  }
  if ( v1 == 4 )
  {
    if ( vht_ch_width == 2 )
      v12 = 3;
    else
      v12 = 2;
    if ( vht_ch_width == 3 )
      return 4;
    else
      return v12;
  }
  else if ( (vht_ch_width & 0xFE) != 0 )
  {
    return 3;
  }
  else
  {
    return 2;
  }
}
