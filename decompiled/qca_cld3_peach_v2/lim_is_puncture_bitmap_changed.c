bool __fastcall lim_is_puncture_bitmap_changed(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: punct orig 0x%x target 0x%x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_is_puncture_bitmap_changed",
    *(unsigned __int16 *)(a1 + 7184),
    *(unsigned __int16 *)(a2 + 18));
  return *(unsigned __int16 *)(a1 + 7184) != *(unsigned __int16 *)(a2 + 18);
}
