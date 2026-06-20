__int64 __fastcall lim_convert_channel_width_enum(
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

  if ( a1 < 0xA && ((0x29Fu >> a1) & 1) != 0 )
    return dword_A09684[a1];
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: invalid enum: %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "lim_convert_channel_width_enum",
    a1,
    v9,
    v10);
  return 0;
}
