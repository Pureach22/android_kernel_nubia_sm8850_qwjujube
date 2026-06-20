__int64 __fastcall reg_is_6ghz_psc_chan_freq(
        unsigned __int16 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned __int64 v10; // t2
  __int64 v11; // x20

  if ( *(_DWORD *)(channel_map + 504) <= (unsigned int)a1 && *(_DWORD *)(channel_map + 1212) >= (unsigned int)a1 )
  {
    HIDWORD(v10) = -1179 - 858993459 * a1;
    LODWORD(v10) = HIDWORD(v10);
    if ( (unsigned int)(v10 >> 4) < 0x3333334 )
      return 1;
    v11 = jiffies;
    if ( reg_is_6ghz_psc_chan_freq___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: Channel freq %d MHz is not a 6GHz PSC frequency",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "reg_is_6ghz_psc_chan_freq");
      reg_is_6ghz_psc_chan_freq___last_ticks = v11;
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      8u,
      "%s:  Channel frequency is not a 6GHz frequency",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "reg_is_6ghz_psc_chan_freq");
  }
  return 0;
}
