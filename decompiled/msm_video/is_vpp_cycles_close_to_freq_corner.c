bool __fastcall is_vpp_cycles_close_to_freq_corner(__int64 a1, __int64 a2)
{
  int v2; // w19
  unsigned __int64 v3; // x23
  unsigned __int64 clock_freq; // x0
  unsigned __int64 v6; // x20
  unsigned __int64 v7; // x0
  int v8; // w21

  if ( a1 && (v2 = a1, *(_QWORD *)(a1 + 3904)) )
  {
    v3 = 1000000 * a2;
    get_max_clock_index(a1);
    clock_freq = get_clock_freq(v2, "video_cc_mvs0_clk_src");
    if ( v3 <= clock_freq )
    {
      v6 = clock_freq;
      if ( get_clock_freq_count(v2, "video_cc_mvs0_clk_src") )
      {
        v7 = get_clock_freq(v2, "video_cc_mvs0_clk_src");
        if ( v3 <= v7 )
        {
          v8 = 1;
          do
          {
            v6 = v7;
            if ( get_clock_freq_count(v2, "video_cc_mvs0_clk_src") <= (unsigned __int64)v8 )
              break;
            v7 = get_clock_freq(v2, "video_cc_mvs0_clk_src");
            ++v8;
          }
          while ( v3 <= v7 );
        }
      }
      return (unsigned int)(100 * (v6 - v3) / (unsigned int)v6) < 5;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "is_vpp_cycles_close_to_freq_corner");
    return 0;
  }
}
