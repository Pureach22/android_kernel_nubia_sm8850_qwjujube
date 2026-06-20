unsigned __int8 *__fastcall wlan_get_parsed_bss_description_ies(__int64 a1, unsigned __int16 *a2, __int64 *a3)
{
  unsigned __int8 *result; // x0
  __int64 v7; // x0
  __int64 v8; // x3
  __int64 v9; // x4
  __int64 v10; // x5
  __int64 v11; // x6
  __int64 v12; // x7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20

  result = (_BYTE *)(&off_0 + 4);
  if ( a2 && a3 )
  {
    v7 = _qdf_mem_malloc(0x1490u, "wlan_get_parsed_bss_description_ies", 13086);
    *a3 = v7;
    if ( v7 )
    {
      result = wlan_parse_bss_description_ies(a1, a2, v7, v13, v14, v15, v16, v17, v18, v19, v20, v8, v9, v10, v11, v12);
      if ( (_DWORD)result )
      {
        v21 = (unsigned int)result;
        _qdf_mem_free(*a3);
        *a3 = 0;
        return (unsigned __int8 *)v21;
      }
    }
    else
    {
      return (_BYTE *)(&off_0 + 2);
    }
  }
  return result;
}
