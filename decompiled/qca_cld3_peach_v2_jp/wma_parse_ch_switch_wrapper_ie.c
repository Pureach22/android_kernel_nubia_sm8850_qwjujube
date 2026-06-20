unsigned __int8 *__fastcall wma_parse_ch_switch_wrapper_ie(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x4
  unsigned __int8 *result; // x0
  unsigned __int8 v11; // w6
  unsigned __int8 v12; // w8

  v9 = a1[1];
  if ( *a1 == 196 && a1[1] )
  {
    result = a1 + 2;
    while ( 1 )
    {
      v11 = result[1];
      v12 = v11 + 2;
      if ( (unsigned __int8)v9 < (unsigned int)(unsigned __int8)(v11 + 2) )
        break;
      if ( *result == 194 )
        return result;
      LOBYTE(v9) = v9 - v12;
      result += v12;
      if ( !(_BYTE)v9 )
        return nullptr;
    }
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: invalid sub element len :%d id:%d ie len:%d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wma_parse_ch_switch_wrapper_ie",
      (unsigned __int8)(v11 + 2),
      *result);
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Invalid len: %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wma_parse_ch_switch_wrapper_ie",
      v9);
  }
  return nullptr;
}
