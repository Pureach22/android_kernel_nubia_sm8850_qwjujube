__int64 __fastcall wma_update_protection_mode(
        __int64 *a1,
        unsigned __int8 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  v11 = a3 != 0;
  if ( (unsigned int)wma_vdev_set_param(*a1, a2, 0x1Au, v11, a4, a5, a6, a7, a8, a9, a10, a11) )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Failed to send wmi protection mode cmd",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "wma_update_protection_mode");
  else
    return qdf_trace_msg(0x36u, 8u, "Updated protection mode %d to target", v12, v13, v14, v15, v16, v17, v18, v19, v11);
}
