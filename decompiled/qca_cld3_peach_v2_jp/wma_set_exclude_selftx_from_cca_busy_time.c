__int64 __fastcall wma_set_exclude_selftx_from_cca_busy_time(
        __int64 result,
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
  __int64 v10; // x29
  __int64 v11; // x30
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( a2 )
  {
    *(_BYTE *)(a2 + 3361) = result & 1;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid WMA handle (via %s)",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "__wma_validate_handle",
      "wma_get_ini_handle",
      v10,
      v11);
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: NULL WMA ini handle",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "wma_set_exclude_selftx_from_cca_busy_time");
  }
  return result;
}
