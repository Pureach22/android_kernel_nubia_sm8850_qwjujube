__int64 __fastcall wma_config_stats_factor(
        __int64 *a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( !a2 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Invalid input of stats avg factor",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wma_config_stats_factor");
  if ( (unsigned int)wma_vdev_set_param(*a1, *a2, 0x4Bu, *((unsigned __int16 *)a2 + 1), a3, a4, a5, a6, a7, a8, a9, a10) )
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: failed to set avg_factor for vdev_id %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wma_config_stats_factor",
      *a2);
  return qdf_trace_msg(
           0x36u,
           8u,
           "%s: Set stats_avg_factor %d for vdev_id %d",
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           "wma_config_stats_factor",
           *((unsigned __int16 *)a2 + 1),
           *a2);
}
