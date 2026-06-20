__int64 __fastcall wma_update_beacon_interval(
        __int64 *a1,
        unsigned __int8 a2,
        unsigned __int16 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( (unsigned int)wma_vdev_set_param(*a1, a2, 3u, a3, a4, a5, a6, a7, a8, a9, a10, a11) )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Failed to update beacon interval",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "wma_update_beacon_interval");
  else
    return qdf_trace_msg(
             0x36u,
             4u,
             "%s: Updated beacon interval %d for vdev %d",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "wma_update_beacon_interval",
             a3,
             a2);
}
