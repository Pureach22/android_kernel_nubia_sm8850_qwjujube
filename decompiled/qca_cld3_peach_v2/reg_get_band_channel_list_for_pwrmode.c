__int64 __fastcall reg_get_band_channel_list_for_pwrmode(__int64 a1, char a2, __int64 a3, unsigned int a4, char a5)
{
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _WORD *v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x22
  unsigned int band_from_cur_chan_list; // w20

  v10 = _qdf_mem_malloc(0xE58u, "reg_get_band_channel_list_for_pwrmode", 3042);
  if ( v10 )
  {
    v19 = (_WORD *)v10;
    if ( reg_get_pdev_obj(a1, v11, v12, v13, v14, v15, v16, v17, v18) )
    {
      if ( (unsigned int)reg_get_pwrmode_chan_list(a1, v19, a4, v20, v21, v22, v23, v24, v25, v26, v27) )
      {
        v36 = jiffies;
        if ( reg_get_band_channel_list_for_pwrmode___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: Unable to get powermode channel list",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "reg_get_band_channel_list_for_pwrmode");
          band_from_cur_chan_list = 0;
          reg_get_band_channel_list_for_pwrmode___last_ticks = v36;
        }
        else
        {
          band_from_cur_chan_list = 0;
        }
      }
      else
      {
        band_from_cur_chan_list = reg_get_band_from_cur_chan_list(
                                    a2,
                                    a3,
                                    (__int64)v19,
                                    a5 & 1,
                                    v28,
                                    v29,
                                    v30,
                                    v31,
                                    v32,
                                    v33,
                                    v34,
                                    v35);
      }
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: reg pdev priv obj is NULL",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "reg_get_band_channel_list_for_pwrmode");
      band_from_cur_chan_list = 0;
    }
    _qdf_mem_free((__int64)v19);
  }
  else
  {
    return 0;
  }
  return band_from_cur_chan_list;
}
