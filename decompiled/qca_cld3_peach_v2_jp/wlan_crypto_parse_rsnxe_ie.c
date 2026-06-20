unsigned __int8 *__fastcall wlan_crypto_parse_rsnxe_ie(
        unsigned __int8 *result,
        _BYTE *a2,
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
  int v12; // w4

  if ( result )
  {
    v12 = *result;
    if ( v12 == 244 )
    {
      if ( result[1] )
      {
        result += 2;
        goto LABEL_8;
      }
    }
    else
    {
      if ( v12 != 221 )
      {
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: Unknown eid %x",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "wlan_crypto_get_ie_offset",
          v10,
          v11);
        return nullptr;
      }
      if ( result[1] >= 5u )
      {
        result += 6;
LABEL_8:
        *a2 = *result & 0xF;
        return result;
      }
    }
    return nullptr;
  }
  return result;
}
