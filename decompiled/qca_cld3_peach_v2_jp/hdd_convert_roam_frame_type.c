__int64 __fastcall hdd_convert_roam_frame_type(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  unsigned int v11; // w4
  __int64 v12; // x20

  v11 = a1;
  if ( a1 - 1 >= 0xA )
  {
    v12 = jiffies;
    if ( hdd_convert_roam_frame_type___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid roam frame type received: %d",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "hdd_convert_roam_frame_type",
        a1,
        v9,
        v10);
      hdd_convert_roam_frame_type___last_ticks = v12;
    }
    return 9;
  }
  return v11;
}
