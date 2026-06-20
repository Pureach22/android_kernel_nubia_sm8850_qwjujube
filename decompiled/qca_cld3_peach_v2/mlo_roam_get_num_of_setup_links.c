__int64 __fastcall mlo_roam_get_num_of_setup_links(
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
    return *(unsigned __int8 *)(a1 + 2497);
  qdf_trace_msg(
    0x8Fu,
    2u,
    "%s: Roam Sync ind is null",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "mlo_roam_get_num_of_setup_links",
    v9,
    v10);
  return 255;
}
