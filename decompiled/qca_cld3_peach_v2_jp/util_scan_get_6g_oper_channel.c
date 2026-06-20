unsigned __int8 *__fastcall util_scan_get_6g_oper_channel(unsigned __int8 *result)
{
  unsigned int v1; // w10
  char v2; // w9
  unsigned __int64 v3; // x8
  __int64 v4; // x10
  unsigned __int8 *v5; // x10
  unsigned __int8 *v6; // x8

  if ( result )
  {
    v1 = result[1];
    v2 = v1 - 7;
    if ( v1 >= 7 && (result[5] & 2) != 0 && (_BYTE)v1 != 7 )
    {
      v3 = result[4];
      if ( (v3 & 0x40) == 0 )
      {
        v4 = 9;
        goto LABEL_10;
      }
      if ( (unsigned __int8)(v1 - 7) >= 4u )
      {
        v2 = v1 - 10;
        v4 = 12;
LABEL_10:
        if ( (unsigned __int8)(v2 + ((unsigned int)(char)v3 >> 7)) < 5u )
          return nullptr;
        v5 = &result[v4];
        result = nullptr;
        v6 = &v5[v3 >> 7];
        if ( v6 )
          return (unsigned __int8 *)*v6;
        return result;
      }
    }
    return nullptr;
  }
  return result;
}
