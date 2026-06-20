const char *__fastcall dp_srng_get_str_from_hal_ring_type(
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

  if ( a1 < 0x1D && ((0x136FF8FFu >> a1) & 1) != 0 )
    return off_A27528[a1];
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Invalid ring type: %u",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_srng_get_str_from_hal_ring_type",
    a1,
    v9,
    v10);
  return "Invalid";
}
