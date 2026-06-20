_BYTE *__fastcall reg_dmn_print_channels_in_opclass(
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
  unsigned int v10; // w19
  _BYTE *result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w8
  _BYTE *v21; // x21
  int v22; // t1
  __int64 i; // x24

  v10 = a2;
  result = reg_get_class_from_country(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  v20 = (unsigned __int8)*result;
  if ( !*result )
    return (_BYTE *)qdf_trace_msg(0x38u, 2u, "Invalid requested RC (%d)", v12, v13, v14, v15, v16, v17, v18, v19, v10);
  v21 = result;
  while ( v20 != v10 )
  {
    v22 = (unsigned __int8)v21[96];
    v21 += 96;
    v20 = v22;
    if ( !v22 )
      return (_BYTE *)qdf_trace_msg(0x38u, 2u, "Invalid requested RC (%d)", v12, v13, v14, v15, v16, v17, v18, v19, v10);
  }
  for ( i = 16; i != 86; ++i )
  {
    if ( !v21[i] )
      break;
    result = (_BYTE *)qdf_trace_msg(
                        0x51u,
                        8u,
                        "%s: Valid channel(%d) in requested RC(%d)",
                        v12,
                        v13,
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        "reg_dmn_print_channels_in_opclass");
  }
  if ( !*v21 )
    return (_BYTE *)qdf_trace_msg(0x38u, 2u, "Invalid requested RC (%d)", v12, v13, v14, v15, v16, v17, v18, v19, v10);
  return result;
}
