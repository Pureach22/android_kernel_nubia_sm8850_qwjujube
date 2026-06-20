unsigned __int8 *__fastcall util_scan_get_he_6g_params(unsigned __int8 *result)
{
  unsigned int v1; // w10
  char v2; // w8
  unsigned __int64 v3; // x9
  __int64 v4; // x10
  unsigned int v5; // w11
  unsigned __int8 *v6; // x9

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
        v5 = (char)v3;
        v6 = &result[v4 + (v3 >> 7)];
        if ( (unsigned __int8)(v2 + (v5 >> 7)) >= 5u )
          return v6;
        else
          return nullptr;
      }
    }
    return nullptr;
  }
  return result;
}
