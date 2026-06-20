__int64 __fastcall hdd_map_nl_chan_width(int a1)
{
  __int64 vht_ch_width; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0
  int eht_ch_width; // w0
  unsigned int v13; // w8
  unsigned int v14; // w9
  char v15; // w19
  int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  bool v25; // zf

  vht_ch_width = wma_get_vht_ch_width();
  if ( a1 > 4 )
  {
    if ( a1 > 6 )
    {
      if ( a1 == 7 )
        return 6;
      if ( a1 != 13 )
        goto LABEL_32;
      eht_ch_width = sme_get_eht_ch_width(vht_ch_width);
      if ( eht_ch_width == 2 )
        v13 = 3;
      else
        v13 = 2;
      if ( eht_ch_width == 4 )
        return 7;
      else
        return v13;
    }
    else if ( a1 == 5 )
    {
      v15 = vht_ch_width;
      v16 = sme_get_eht_ch_width(vht_ch_width);
      if ( v16 == 2 )
      {
        return 3;
      }
      else
      {
        v25 = v16 == 4;
        result = 3;
        if ( !v25 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: FW does not support this BW %d max BW supported %d",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "hdd_is_target_eht_phy_ch_width_supported",
            3,
            2);
          if ( (v15 & 0xFE) != 0 )
            return 3;
          else
            return 2;
        }
      }
    }
    else
    {
      return 5;
    }
  }
  else
  {
    if ( a1 <= 2 )
    {
      if ( (unsigned int)a1 < 2 )
        return 0;
      if ( a1 == 2 )
        return 1;
LABEL_32:
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
        (unsigned int)a1);
      return 8;
    }
    if ( a1 == 3 )
    {
      return 2;
    }
    else
    {
      if ( (unsigned __int8)vht_ch_width == 2 )
        v14 = 3;
      else
        v14 = 2;
      if ( (unsigned __int8)vht_ch_width == 3 )
        return 4;
      else
        return v14;
    }
  }
  return result;
}
