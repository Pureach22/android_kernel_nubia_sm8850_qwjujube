__int64 __fastcall dot11f_unpack_ie_wmmtclas(__int64 a1, unsigned __int8 *a2, char a3, _BYTE *a4)
{
  int v5; // w8
  int v6; // w8
  _BYTE *v9; // x19
  void *v10; // x0
  const void *v11; // x1
  int v12; // w8
  size_t v15; // x2

  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( !a3 )
    goto LABEL_39;
  v5 = *a2;
  a4[1] = v5;
  if ( v5 != 1 )
  {
    *a4 = 0;
    return 64;
  }
  if ( a3 == 1 )
    goto LABEL_39;
  a4[2] = a2[1];
  if ( a3 == 2 )
    goto LABEL_39;
  v6 = a2[2];
  a4[3] = v6;
  if ( a3 == 3 )
    goto LABEL_39;
  a4[4] = a2[3];
  switch ( v6 )
  {
    case 2:
      if ( (unsigned __int8)(a3 - 4) > 1u )
      {
        v10 = a4 + 6;
        v11 = a2 + 4;
        goto LABEL_29;
      }
      goto LABEL_39;
    case 1:
      if ( a3 == 4 )
        goto LABEL_39;
      v12 = a2[4];
      a4[6] = v12;
      if ( v12 == 6 )
      {
        if ( (unsigned __int8)(a3 - 5) > 0xFu )
        {
          v9 = a4;
          qdf_mem_copy(a4 + 8, a2 + 5, 0x10u);
          if ( (unsigned __int8)(a3 - 21) > 0xFu )
          {
            qdf_mem_copy(v9 + 24, a2 + 21, 0x10u);
            if ( (unsigned __int8)(a3 - 37) > 1u )
            {
              qdf_mem_copy(v9 + 40, a2 + 37, 2u);
              if ( (unsigned __int8)(a3 - 39) > 1u )
              {
                qdf_mem_copy(v9 + 42, a2 + 39, 2u);
                if ( (unsigned __int8)(a3 - 41) > 2u )
                {
                  v10 = v9 + 44;
                  v11 = a2 + 41;
                  v15 = 3;
                  goto LABEL_30;
                }
              }
            }
          }
          goto LABEL_40;
        }
LABEL_39:
        *a4 = 0;
        return 4;
      }
      if ( v12 == 4 )
      {
        if ( (unsigned __int8)(a3 - 5) > 3u )
        {
          v9 = a4;
          qdf_mem_copy(a4 + 8, a2 + 5, 4u);
          if ( (unsigned __int8)(a3 - 9) > 3u )
          {
            qdf_mem_copy(v9 + 12, a2 + 9, 4u);
            if ( (unsigned __int8)(a3 - 13) > 1u )
            {
              qdf_mem_copy(v9 + 16, a2 + 13, 2u);
              if ( (unsigned __int8)(a3 - 15) > 1u )
              {
                qdf_mem_copy(v9 + 18, a2 + 15, 2u);
                if ( a3 != 17 )
                {
                  v9[20] = a2[17];
                  if ( a3 != 18 )
                  {
                    v9[21] = a2[18];
                    if ( a3 != 19 )
                    {
                      v9[22] = a2[19];
                      return 0;
                    }
                  }
                }
              }
            }
          }
          goto LABEL_40;
        }
        goto LABEL_39;
      }
      break;
    case 0:
      if ( (unsigned __int8)(a3 - 4) > 5u )
      {
        v9 = a4;
        qdf_mem_copy(a4 + 6, a2 + 4, 6u);
        if ( (unsigned __int8)(a3 - 10) > 5u )
        {
          qdf_mem_copy(v9 + 12, a2 + 10, 6u);
          if ( (a3 & 0xFE) != 0x10 )
          {
            v10 = v9 + 18;
            v11 = a2 + 16;
LABEL_29:
            v15 = 2;
LABEL_30:
            qdf_mem_copy(v10, v11, v15);
            return 0;
          }
        }
LABEL_40:
        *v9 = 0;
        return 4;
      }
      goto LABEL_39;
  }
  return 0;
}
