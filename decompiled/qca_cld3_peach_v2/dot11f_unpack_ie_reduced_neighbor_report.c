__int64 __fastcall dot11f_unpack_ie_reduced_neighbor_report(__int64 a1, _BYTE *a2, unsigned __int8 a3, __int64 a4)
{
  __int64 result; // x0
  int v5; // w22
  unsigned int v9; // w8
  unsigned int v10; // w9
  void *v11; // x0
  const void *v12; // x1
  size_t v13; // x2
  char v14; // w8
  _WORD v15[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int16 v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)a4 )
  {
    v5 = a3;
    *(_BYTE *)a4 = 1;
    if ( a3 <= 1u )
      goto LABEL_70;
    v16 = 0;
    v15[0] = 0;
    qdf_mem_copy(&v16, a2, 2u);
    v9 = v16;
    *(_WORD *)(a4 + 1) = v16;
    if ( v5 == 2 )
      goto LABEL_70;
    *(_BYTE *)(a4 + 3) = a2[2];
    if ( a3 == 3 )
      goto LABEL_70;
    v10 = v9 >> 8;
    result = 0;
    *(_BYTE *)(a4 + 4) = a2[3];
    if ( v9 >> 8 <= 7 )
    {
      if ( v9 >> 8 <= 4 )
      {
        if ( v10 == 1 )
        {
          if ( a3 != 4 )
          {
            result = 0;
            *(_BYTE *)(a4 + 8) = a2[4];
            goto LABEL_3;
          }
        }
        else
        {
          if ( v10 != 2 )
            goto LABEL_3;
          if ( a3 != 4 )
          {
            *(_BYTE *)(a4 + 8) = a2[4];
            if ( a3 != 5 )
            {
              result = 0;
              *(_BYTE *)(a4 + 9) = a2[5];
              goto LABEL_3;
            }
          }
        }
        goto LABEL_70;
      }
      if ( v10 == 5 )
      {
        if ( a3 != 4 )
        {
          *(_BYTE *)(a4 + 8) = a2[4];
          if ( (unsigned __int8)(a3 - 5) > 3u )
          {
            v11 = (void *)(a4 + 12);
            v12 = a2 + 5;
            goto LABEL_59;
          }
        }
LABEL_70:
        *(_BYTE *)a4 = 0;
        result = 4;
        goto LABEL_3;
      }
      if ( v10 != 6 )
      {
        if ( a3 != 4 )
        {
          *(_BYTE *)(a4 + 8) = a2[4];
          if ( (unsigned __int8)(a3 - 5) > 5u )
          {
            v11 = (void *)(a4 + 9);
            v12 = a2 + 5;
            v13 = 6;
LABEL_60:
            qdf_mem_copy(v11, v12, v13);
            result = 0;
            goto LABEL_3;
          }
        }
        goto LABEL_70;
      }
      if ( a3 == 4 )
        goto LABEL_70;
      *(_BYTE *)(a4 + 8) = a2[4];
      if ( (unsigned __int8)(a3 - 5) <= 3u )
        goto LABEL_70;
      qdf_mem_copy((void *)(a4 + 12), a2 + 5, 4u);
      if ( a3 == 9 )
        goto LABEL_70;
      v14 = a2[9];
    }
    else
    {
      if ( v9 >> 8 > 0xB )
      {
        switch ( v10 )
        {
          case 0xCu:
            if ( a3 != 4 )
            {
              *(_BYTE *)(a4 + 8) = a2[4];
              if ( (unsigned __int8)(a3 - 5) > 5u )
              {
                qdf_mem_copy((void *)(a4 + 9), a2 + 5, 6u);
                if ( (unsigned __int8)(a3 - 11) > 3u )
                {
                  qdf_mem_copy((void *)(a4 + 16), a2 + 11, 4u);
                  if ( a3 != 15 )
                  {
                    result = 0;
                    *(_BYTE *)(a4 + 20) = a2[15];
                    goto LABEL_3;
                  }
                }
              }
            }
            break;
          case 0xDu:
            if ( a3 != 4 )
            {
              *(_BYTE *)(a4 + 8) = a2[4];
              if ( (unsigned __int8)(a3 - 5) > 5u )
              {
                qdf_mem_copy((void *)(a4 + 9), a2 + 5, 6u);
                if ( (unsigned __int8)(a3 - 11) > 3u )
                {
                  qdf_mem_copy((void *)(a4 + 16), a2 + 11, 4u);
                  if ( a3 != 15 )
                  {
                    *(_BYTE *)(a4 + 20) = a2[15];
                    if ( a3 != 16 )
                    {
                      result = 0;
                      *(_BYTE *)(a4 + 21) = a2[16];
                      goto LABEL_3;
                    }
                  }
                }
              }
            }
            break;
          case 0x10u:
            if ( a3 != 4 )
            {
              *(_BYTE *)(a4 + 8) = a2[4];
              if ( (unsigned __int8)(a3 - 5) > 5u )
              {
                qdf_mem_copy((void *)(a4 + 9), a2 + 5, 6u);
                if ( (unsigned __int8)(a3 - 11) > 3u )
                {
                  qdf_mem_copy((void *)(a4 + 16), a2 + 11, 4u);
                  if ( a3 != 15 )
                  {
                    *(_BYTE *)(a4 + 20) = a2[15];
                    if ( a3 != 16 )
                    {
                      *(_BYTE *)(a4 + 21) = a2[16];
                      if ( a3 != 17 )
                      {
                        *(_BYTE *)(a4 + 22) = a2[17];
                        if ( (a3 & 0xFE) != 0x12 )
                        {
                          qdf_mem_copy(v15, a2 + 18, 2u);
                          result = 0;
                          *(_DWORD *)(a4 + 23) = *(_DWORD *)(a4 + 23) & 0xFFF000F0
                                               | v15[0] & 0xF
                                               | (unsigned __int16)((unsigned __int8)(v15[0] >> 4) << 8)
                                               | (v15[0] >> 13 << 17)
                                               | (((v15[0] >> 12) & 1) << 16);
                          goto LABEL_3;
                        }
                      }
                    }
                  }
                }
              }
            }
            break;
          default:
            goto LABEL_3;
        }
        goto LABEL_70;
      }
      if ( v10 == 8 )
      {
        if ( a3 != 4 )
        {
          *(_BYTE *)(a4 + 8) = a2[4];
          if ( (unsigned __int8)(a3 - 5) > 5u )
          {
            qdf_mem_copy((void *)(a4 + 9), a2 + 5, 6u);
            if ( a3 != 11 )
            {
              result = 0;
              *(_BYTE *)(a4 + 15) = a2[11];
              goto LABEL_3;
            }
          }
        }
        goto LABEL_70;
      }
      if ( v10 != 9 )
      {
        if ( v10 != 11 )
          goto LABEL_3;
        if ( a3 != 4 )
        {
          *(_BYTE *)(a4 + 8) = a2[4];
          if ( (unsigned __int8)(a3 - 5) > 5u )
          {
            qdf_mem_copy((void *)(a4 + 9), a2 + 5, 6u);
            if ( (unsigned __int8)(a3 - 11) > 3u )
            {
              v11 = (void *)(a4 + 16);
              v12 = a2 + 11;
LABEL_59:
              v13 = 4;
              goto LABEL_60;
            }
          }
        }
        goto LABEL_70;
      }
      if ( a3 == 4 )
        goto LABEL_70;
      *(_BYTE *)(a4 + 8) = a2[4];
      if ( (unsigned __int8)(a3 - 5) <= 5u )
        goto LABEL_70;
      qdf_mem_copy((void *)(a4 + 9), a2 + 5, 6u);
      if ( a3 == 11 )
        goto LABEL_70;
      *(_BYTE *)(a4 + 15) = a2[11];
      if ( a3 == 12 )
        goto LABEL_70;
      v14 = a2[12];
    }
    result = 0;
    *(_BYTE *)(a4 + 16) = v14;
    goto LABEL_3;
  }
  result = 32;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
