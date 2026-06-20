__int64 __fastcall _qdf_nbuf_data_get_eapol_subtype(__int64 a1)
{
  unsigned int v1; // w8
  unsigned int v3; // w8
  unsigned int v4; // w8
  int v5; // w9
  unsigned int v6; // w9
  unsigned int v7; // w9
  unsigned int v8; // w9
  unsigned int v9; // w9
  unsigned int v10; // w9

  v1 = *(unsigned __int8 *)(a1 + 15);
  if ( v1 <= 1 )
  {
    if ( *(_BYTE *)(a1 + 15) )
    {
      if ( v1 == 1 )
        return 43;
      return 0;
    }
    v4 = *(unsigned __int8 *)(a1 + 18);
    if ( v4 > 3 )
    {
      switch ( v4 )
      {
        case 4u:
          return 40;
        case 5u:
          return 41;
        case 6u:
          return 42;
        default:
          return 0;
      }
    }
    else
    {
      if ( v4 - 1 >= 2 )
      {
        if ( v4 == 3 )
          return 39;
        return 0;
      }
      v5 = *(unsigned __int8 *)(a1 + 22);
      if ( v5 == 1 )
      {
        if ( v4 == 2 )
          v8 = 47;
        else
          v8 = 0;
        if ( v4 == 1 )
          return 46;
        else
          return v8;
      }
      else
      {
        if ( v5 == 254 )
        {
          v6 = *(unsigned __int8 *)(a1 + 30);
          if ( v6 > 3 )
          {
            switch ( v6 )
            {
              case 4u:
                v9 = *(unsigned __int8 *)(a1 + 41) - 4;
                if ( v9 < 9 && ((0x1FBu >> v9) & 1) != 0 )
                  return dword_9DE210[(unsigned __int8)(*(_BYTE *)(a1 + 41) - 4)];
                break;
              case 5u:
                return 59;
              case 6u:
                return 60;
            }
          }
          else
          {
            switch ( v6 )
            {
              case 1u:
                return 56;
              case 2u:
                return 57;
              case 3u:
                return 58;
            }
          }
        }
        if ( v4 == 2 )
          v10 = 38;
        else
          v10 = 0;
        if ( v4 == 1 )
          return 37;
        else
          return v10;
      }
    }
  }
  else
  {
    if ( v1 == 2 )
      return 44;
    if ( v1 != 3 )
    {
      if ( v1 == 4 )
        return 45;
      return 0;
    }
    v3 = bswap32(*(unsigned __int16 *)(a1 + 19)) >> 16;
    if ( (v3 & 0x80) != 0 )
    {
      if ( (v3 & 8) != 0 )
        v7 = 3;
      else
        v7 = 61;
      if ( (v3 & 0x1100) != 0 )
        return v7;
      else
        return 1;
    }
    else if ( *(_WORD *)(a1 + 111)
           && (*(_QWORD *)(a1 + 31) || *(_QWORD *)(a1 + 39) || *(_QWORD *)(a1 + 47) || *(_QWORD *)(a1 + 55)) )
    {
      return 2;
    }
    else if ( (v3 & 8) != 0 )
    {
      return 4;
    }
    else
    {
      return 62;
    }
  }
}
