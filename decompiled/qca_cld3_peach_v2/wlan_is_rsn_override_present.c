__int64 __fastcall wlan_is_rsn_override_present(unsigned __int8 *a1, int a2)
{
  __int64 result; // x0
  int v4; // w21
  unsigned __int8 *v5; // x23
  int v6; // w22
  __int64 v7; // x24
  unsigned int v8; // w8
  __int64 v9; // x22
  unsigned int v10; // w8

  result = 0;
  if ( a1 && a2 >= 5 && (a2 & 0xFFFE) != 0 )
  {
    v4 = (unsigned __int16)a2;
    v5 = a1;
    v6 = (unsigned __int16)a2;
    while ( 1 )
    {
      v7 = v5[1];
      v8 = v6 - 2;
      v6 = v6 - 2 - v7;
      if ( v8 < (unsigned int)v7 )
        goto LABEL_14;
      if ( *v5 == 221 )
      {
        if ( v8 < 4 )
          goto LABEL_14;
        if ( !(unsigned int)qdf_mem_cmp(v5 + 2, &unk_A3A6E1, 4u) )
          break;
      }
      v5 += v7 + 2;
      if ( v6 <= 1 )
        goto LABEL_14;
    }
    if ( v5 )
    {
      return 3;
    }
    else
    {
LABEL_14:
      do
      {
        v9 = a1[1];
        v10 = v4 - 2;
        v4 = v4 - 2 - v9;
        if ( v10 < (unsigned int)v9 )
          break;
        if ( *a1 == 221 )
        {
          if ( v10 < 4 )
            break;
          if ( !(unsigned int)qdf_mem_cmp(a1 + 2, &unk_AAA880, 4u) )
            return 2 * (unsigned int)(a1 != nullptr);
        }
        a1 += v9 + 2;
      }
      while ( v4 > 1 );
      a1 = nullptr;
      return 2 * (unsigned int)(a1 != nullptr);
    }
  }
  return result;
}
