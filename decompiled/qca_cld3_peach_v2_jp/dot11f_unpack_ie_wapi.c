__int64 __fastcall dot11f_unpack_ie_wapi(__int64 a1, char *a2, unsigned __int8 a3, _WORD *a4)
{
  __int64 result; // x0
  unsigned int v8; // w8
  unsigned __int8 v9; // w21
  size_t v10; // x2
  char *v11; // x20
  __int64 v12; // x8
  unsigned __int8 v13; // w21
  char *v14; // x20
  unsigned int v15; // w8
  unsigned __int8 v16; // w21
  size_t v17; // x2
  char *v18; // x20
  __int64 v19; // x8
  unsigned __int8 v20; // w21
  char *v21; // x20
  unsigned int v22; // w8
  size_t v23; // x2
  __int16 v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)a4 )
  {
    *(_BYTE *)a4 = 1;
    if ( a3 > 1u )
    {
      v24 = 0;
      qdf_mem_copy(a4 + 1, a2, 2u);
      if ( a4[1] != 1 )
      {
        *(_BYTE *)a4 = 0;
        result = 64;
        goto LABEL_13;
      }
      if ( (a3 & 0xFE) != 2 )
      {
        qdf_mem_copy(a4 + 2, a2 + 2, 2u);
        v8 = (unsigned __int16)a4[2];
        v9 = a3 - 4;
        v10 = 4 * v8;
        if ( (unsigned int)v10 <= v9 )
        {
          if ( v8 >= 5 )
          {
LABEL_11:
            *(_BYTE *)a4 = 0;
            result = 8;
            goto LABEL_13;
          }
          v11 = a2 + 4;
          qdf_mem_copy(a4 + 3, v11, v10);
          v12 = 4LL * (unsigned __int16)a4[2];
          v13 = v9 - v12;
          if ( v13 > 1u )
          {
            v14 = &v11[v12];
            qdf_mem_copy(a4 + 11, v14, 2u);
            v15 = (unsigned __int16)a4[11];
            v16 = v13 - 2;
            v17 = 4 * v15;
            if ( (unsigned int)v17 <= v16 )
            {
              if ( v15 >= 5 )
                goto LABEL_11;
              v18 = v14 + 2;
              qdf_mem_copy(a4 + 12, v18, v17);
              v19 = 4LL * (unsigned __int16)a4[11];
              v20 = v16 - v19;
              if ( v20 > 3u )
              {
                v21 = &v18[v19];
                qdf_mem_copy(a4 + 20, v21, 4u);
                if ( (v20 & 0xFE) != 4 )
                {
                  qdf_mem_copy(&v24, v21 + 4, 2u);
                  a4[22] = v24;
                  if ( v20 == 6 )
                  {
                    result = 0;
                    a4[23] = 0;
                    goto LABEL_13;
                  }
                  if ( v20 != 7 )
                  {
                    qdf_mem_copy(a4 + 23, v21 + 6, 2u);
                    v22 = (unsigned __int16)a4[23];
                    v23 = 16 * v22;
                    if ( (unsigned int)v23 <= (unsigned __int8)(v20 - 8) )
                    {
                      if ( v22 < 5 )
                      {
                        qdf_mem_copy(a4 + 24, v21 + 8, v23);
                        result = 0;
                        goto LABEL_13;
                      }
                      goto LABEL_11;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    *(_BYTE *)a4 = 0;
    result = 4;
    goto LABEL_13;
  }
  result = 32;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
