__int64 __fastcall wma_check_txrx_chainmask(
        char a1,
        int a2,
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

  if ( ~(-1 << a1) >= a2 && a2 > 0 )
    return 0;
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Requested value %d over the range",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_check_txrx_chainmask",
    (unsigned int)a2,
    v10,
    v11);
  return 4;
}
