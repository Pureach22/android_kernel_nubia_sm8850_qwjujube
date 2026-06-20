__int64 __fastcall dot11f_unpack_ie_wmm_params(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3, __int64 a4)
{
  int v6; // w21
  int v7; // w8
  unsigned __int8 v9; // w8
  unsigned __int8 v10; // w8
  unsigned __int8 v11; // w8
  unsigned __int8 v12; // w8

  if ( *(_BYTE *)a4 )
    return 32;
  v6 = a3;
  *(_BYTE *)a4 = 1;
  if ( !a3 )
  {
LABEL_22:
    *(_BYTE *)a4 = 0;
    return 4;
  }
  v7 = *a2;
  *(_BYTE *)(a4 + 1) = v7;
  if ( v7 == 1 )
  {
    if ( a3 != 1 )
    {
      *(_BYTE *)(a4 + 2) = a2[1];
      if ( a3 != 2 )
      {
        *(_BYTE *)(a4 + 3) = a2[2];
        if ( a3 != 3 )
        {
          v9 = a2[3];
          *(_WORD *)(a4 + 4) = v9 & 0xF | (*(unsigned __int8 *)(a4 + 5) << 8) | v9 & 0x10 | v9 & 0x60 | v9 & 0x80;
          if ( a3 != 4 )
          {
            *(_WORD *)(a4 + 4) = v9 | ((a2[4] & 0xF) << 8) & 0xFFF | (((a2[4] >> 4) & 0xF) << 12);
            if ( (unsigned int)a3 - 5 > 1 )
            {
              qdf_mem_copy((void *)(a4 + 6), a2 + 5, 2u);
              if ( v6 != 7 )
              {
                v10 = a2[7];
                *(_WORD *)(a4 + 8) = v10 & 0xF
                                   | (*(unsigned __int8 *)(a4 + 9) << 8)
                                   | v10 & 0x10
                                   | v10 & 0x60
                                   | v10 & 0x80;
                if ( v6 != 8 )
                {
                  *(_WORD *)(a4 + 8) = v10 | ((a2[8] & 0xF) << 8) & 0xFFF | (((a2[8] >> 4) & 0xF) << 12);
                  if ( (unsigned int)(v6 - 9) > 1 )
                  {
                    qdf_mem_copy((void *)(a4 + 10), a2 + 9, 2u);
                    if ( v6 != 11 )
                    {
                      v11 = a2[11];
                      *(_WORD *)(a4 + 12) = v11 & 0xF
                                          | (*(unsigned __int8 *)(a4 + 13) << 8)
                                          | v11 & 0x10
                                          | v11 & 0x60
                                          | v11 & 0x80;
                      if ( v6 != 12 )
                      {
                        *(_WORD *)(a4 + 12) = v11 | ((a2[12] & 0xF) << 8) & 0xFFF | (((a2[12] >> 4) & 0xF) << 12);
                        if ( (unsigned int)(v6 - 13) > 1 )
                        {
                          qdf_mem_copy((void *)(a4 + 14), a2 + 13, 2u);
                          if ( v6 != 15 )
                          {
                            v12 = a2[15];
                            *(_WORD *)(a4 + 16) = v12 & 0xF
                                                | (*(unsigned __int8 *)(a4 + 17) << 8)
                                                | v12 & 0x10
                                                | v12 & 0x60
                                                | v12 & 0x80;
                            if ( v6 != 16 )
                            {
                              *(_WORD *)(a4 + 16) = v12 | ((a2[16] & 0xF) << 8) & 0xFFF | (((a2[16] >> 4) & 0xF) << 12);
                              if ( (unsigned int)(v6 - 17) > 1 )
                              {
                                qdf_mem_copy((void *)(a4 + 18), a2 + 17, 2u);
                                return 0;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    goto LABEL_22;
  }
  *(_BYTE *)a4 = 0;
  return 64;
}
