__int64 __fastcall wma_get_he_vdev_param(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a2 == 107 )
    return *(unsigned __int8 *)(a1 + 145);
  if ( a2 == 106 )
    return *(unsigned __int8 *)(a1 + 144);
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Unhandled HE vdev param: %0x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_get_he_vdev_param",
    a2,
    v10,
    v11);
  return 0;
}
