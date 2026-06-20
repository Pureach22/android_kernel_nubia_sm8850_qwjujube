unsigned __int8 *__fastcall wma_parse_ch_switch_wrapper_ie(
        unsigned __int8 *a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x4
  unsigned __int8 *result; // x0
  __int64 v13; // x5
  unsigned __int8 v14; // w10

  v11 = a1[1];
  if ( *a1 == 196 && a1[1] )
  {
    result = a1 + 2;
    while ( 1 )
    {
      v13 = *result;
      v14 = result[1] + 2;
      if ( (unsigned __int8)v11 < (unsigned int)v14 )
        break;
      if ( (_DWORD)v13 == a2 && (a2 != 255 || result[2] == a3) )
        return result;
      LOBYTE(v11) = v11 - v14;
      result += v14;
      if ( !(_BYTE)v11 )
        return nullptr;
    }
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: invalid sub element len :%d id:%d ie len:%d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wma_parse_ch_switch_wrapper_ie",
      (unsigned __int8)(result[1] + 2),
      v13);
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Invalid len: %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wma_parse_ch_switch_wrapper_ie",
      v11);
  }
  return nullptr;
}
