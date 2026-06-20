__int64 __fastcall ucfg_dp_intf_get_pkt_type_bitmap_value(
        __int64 a1,
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

  if ( a1 )
    return *(unsigned int *)(a1 + 3076);
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Unable to get DP link",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "ucfg_dp_intf_get_pkt_type_bitmap_value",
    v9,
    v10);
  return 0;
}
