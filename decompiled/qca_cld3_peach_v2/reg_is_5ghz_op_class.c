bool __fastcall reg_is_5ghz_op_class(
        unsigned __int8 *a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v11; // w20
  char *class_from_country; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  unsigned int v23; // w9

  v11 = a2;
  class_from_country = reg_get_class_from_country(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  while ( 1 )
  {
    if ( !*class_from_country )
    {
LABEL_5:
      v21 = jiffies;
      if ( reg_is_opclass_band_found___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: Opclass %d is not found",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "reg_is_opclass_band_found",
          a2);
        reg_is_opclass_band_found___last_ticks = v21;
        return 0;
      }
      return 0;
    }
    if ( (unsigned __int8)*class_from_country == v11 )
      break;
    class_from_country += 96;
    if ( !class_from_country )
      goto LABEL_5;
  }
  v23 = 5 * (unsigned __int8)class_from_country[16] + *((_DWORD *)class_from_country + 3);
  return v23 >= *(_DWORD *)(channel_map + 168) && v23 <= *(_DWORD *)(channel_map + 492);
}
