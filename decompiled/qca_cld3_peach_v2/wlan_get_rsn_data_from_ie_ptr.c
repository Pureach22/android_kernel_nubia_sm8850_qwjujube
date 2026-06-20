unsigned __int8 *__fastcall wlan_get_rsn_data_from_ie_ptr(unsigned __int8 *a1, unsigned __int16 a2)
{
  int v2; // w23
  int v3; // w24
  unsigned __int8 *v5; // x19
  unsigned __int8 *v6; // x21
  int v7; // w25
  __int64 v8; // x26
  unsigned int v9; // w8
  unsigned __int8 *v10; // x22
  __int64 v11; // x25
  unsigned int v12; // w8
  unsigned int v13; // w8
  int v14; // w8
  __int64 v15; // x9
  unsigned int v16; // w8
  bool v17; // cf

  v2 = a2 & 0xFFFE;
  if ( (a2 & 0xFFFE) != 0 )
  {
    v3 = a2;
    v5 = a1;
    v6 = a1;
    v7 = a2;
    do
    {
      v8 = v6[1];
      v9 = v7 - 2;
      v7 = v7 - 2 - v8;
      if ( v9 < (unsigned int)v8 )
        break;
      if ( *v6 == 221 )
      {
        if ( v9 < 4 )
          break;
        if ( !(unsigned int)qdf_mem_cmp(v6 + 2, &unk_A3A6E1, 4u) )
        {
          if ( v6 && v6[1] > 4u )
            return v6;
          break;
        }
      }
      v6 += v8 + 2;
    }
    while ( v7 > 1 );
    v10 = v5;
    while ( 1 )
    {
      v11 = v10[1];
      v12 = v3 - 2;
      v3 = v3 - 2 - v11;
      if ( v12 < (unsigned int)v11 )
        goto LABEL_23;
      if ( *v10 == 221 )
      {
        if ( v12 < 4 )
          goto LABEL_23;
        if ( !(unsigned int)qdf_mem_cmp(v10 + 2, &unk_AAA880, 4u) )
          break;
      }
      v10 += v11 + 2;
      if ( v3 <= 1 )
        goto LABEL_23;
    }
    if ( !v10 )
    {
LABEL_23:
      if ( !v2 )
        return nullptr;
      goto LABEL_24;
    }
    v13 = v10[1];
    if ( v13 <= 4 )
      v6 = nullptr;
    else
      v6 = v10;
    if ( v13 > 4 || !v2 )
      return v6;
LABEL_24:
    v14 = a2;
    do
    {
      v15 = v5[1];
      v16 = v14 - 2;
      v17 = v16 >= (unsigned int)v15;
      v14 = v16 - v15;
      if ( !v17 )
        break;
      if ( *v5 == 48 )
        return v5;
      v5 += v15 + 2;
    }
    while ( v14 > 1 );
  }
  return nullptr;
}
