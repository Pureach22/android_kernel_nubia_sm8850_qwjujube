__int64 __fastcall dot11f_unpack_ie_tclas(__int64 a1, _BYTE *a2, char a3, _BYTE *a4)
{
  int v7; // w8
  void *v9; // x0
  const void *v10; // x1
  int v11; // w8
  size_t v13; // x2

  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( !a3 )
    goto LABEL_36;
  a4[1] = *a2;
  if ( a3 == 1 )
    goto LABEL_36;
  v7 = (unsigned __int8)a2[1];
  a4[2] = v7;
  if ( a3 == 2 )
    goto LABEL_36;
  a4[3] = a2[2];
  switch ( v7 )
  {
    case 2:
      if ( (unsigned __int8)(a3 - 3) > 1u )
      {
        v9 = a4 + 4;
        v10 = a2 + 3;
        goto LABEL_26;
      }
LABEL_36:
      *a4 = 0;
      return 4;
    case 1:
      if ( a3 == 3 )
        goto LABEL_36;
      v11 = (unsigned __int8)a2[3];
      a4[4] = v11;
      if ( v11 == 6 )
      {
        if ( (unsigned __int8)(a3 - 4) > 0xFu )
        {
          qdf_mem_copy(a4 + 6, a2 + 4, 0x10u);
          if ( (unsigned __int8)(a3 - 20) > 0xFu )
          {
            qdf_mem_copy(a4 + 22, a2 + 20, 0x10u);
            if ( (a3 & 0xFE) != 0x24 )
            {
              qdf_mem_copy(a4 + 38, a2 + 36, 2u);
              if ( (a3 & 0xFE) != 0x26 )
              {
                qdf_mem_copy(a4 + 40, a2 + 38, 2u);
                if ( (unsigned __int8)(a3 - 40) > 2u )
                {
                  v9 = a4 + 42;
                  v10 = a2 + 40;
                  v13 = 3;
                  goto LABEL_27;
                }
              }
            }
          }
        }
        goto LABEL_36;
      }
      if ( v11 == 4 )
      {
        if ( (unsigned __int8)(a3 - 4) > 3u )
        {
          qdf_mem_copy(a4 + 6, a2 + 4, 4u);
          if ( (a3 & 0xFC) != 8 )
          {
            qdf_mem_copy(a4 + 10, a2 + 8, 4u);
            if ( (a3 & 0xFE) != 0xC )
            {
              qdf_mem_copy(a4 + 14, a2 + 12, 2u);
              if ( (a3 & 0xFE) != 0xE )
              {
                qdf_mem_copy(a4 + 16, a2 + 14, 2u);
                if ( a3 != 16 )
                {
                  a4[18] = a2[16];
                  if ( a3 != 17 )
                  {
                    a4[19] = a2[17];
                    if ( a3 != 18 )
                    {
                      a4[20] = a2[18];
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
        goto LABEL_36;
      }
      break;
    case 0:
      if ( (unsigned __int8)(a3 - 3) > 5u )
      {
        qdf_mem_copy(a4 + 4, a2 + 3, 6u);
        if ( (unsigned __int8)(a3 - 9) > 5u )
        {
          qdf_mem_copy(a4 + 10, a2 + 9, 6u);
          if ( (unsigned __int8)(a3 - 15) > 1u )
          {
            v9 = a4 + 16;
            v10 = a2 + 15;
LABEL_26:
            v13 = 2;
LABEL_27:
            qdf_mem_copy(v9, v10, v13);
            return 0;
          }
        }
      }
      goto LABEL_36;
  }
  return 0;
}
