__int64 __fastcall dot11f_unpack_ie_rsn(__int64 a1, char *a2, unsigned __int8 a3, _WORD *a4)
{
  int v4; // w9
  __int64 result; // x0
  int v9; // w8
  unsigned __int8 v10; // w21
  size_t v11; // x2
  char *v12; // x20
  __int64 v13; // x8
  unsigned __int8 v14; // w21
  char *v15; // x20
  int v16; // w8
  unsigned __int8 v17; // w21
  size_t v18; // x2
  char *v19; // x20
  __int64 v20; // x8
  unsigned __int8 v21; // w21
  char *v22; // x20
  unsigned int v23; // w8
  unsigned __int8 v24; // w21
  size_t v25; // x2
  char *v26; // x20
  __int64 v27; // x8
  int v28; // [xsp+0h] [xbp-10h] BYREF
  int v29; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 *)a4;
  v29 = 78384896;
  v28 = 28053248;
  if ( !v4 )
  {
    *(_BYTE *)a4 = 1;
    if ( a3 > 1u )
    {
      qdf_mem_copy(a4 + 1, a2, 2u);
      if ( a4[1] != 1 )
      {
        *(_BYTE *)a4 = 0;
        result = 64;
        goto LABEL_18;
      }
      if ( a3 == 2 )
      {
        *((_BYTE *)a4 + 70) = 0;
        *((_BYTE *)a4 + 140) = 0;
        *((_BYTE *)a4 + 4) = 1;
        qdf_mem_copy((char *)a4 + 5, &v29, 4u);
        goto LABEL_11;
      }
      *((_BYTE *)a4 + 4) = 1;
      if ( (unsigned __int8)(a3 - 2) > 3u )
      {
        qdf_mem_copy((char *)a4 + 5, a2 + 2, 4u);
        if ( a3 == 6 )
        {
          *((_BYTE *)a4 + 70) = 0;
          *((_BYTE *)a4 + 140) = 0;
LABEL_11:
          a4[5] = 1;
          qdf_mem_copy(a4 + 6, &v29, 4u);
          a4[18] = 1;
LABEL_12:
          qdf_mem_copy(a4 + 19, &v28, 4u);
          result = 0;
LABEL_13:
          a4[37] = 0;
          goto LABEL_18;
        }
        if ( a3 != 7 )
        {
          qdf_mem_copy(a4 + 5, a2 + 6, 2u);
          v9 = (unsigned __int16)a4[5];
          v10 = a3 - 8;
          v11 = (unsigned int)(4 * v9);
          if ( (unsigned int)v11 <= v10 )
          {
            if ( (unsigned int)(v9 - 7) <= 0xFFFFFFF9 )
            {
LABEL_17:
              *(_BYTE *)a4 = 0;
              result = 8;
              goto LABEL_18;
            }
            v12 = a2 + 8;
            qdf_mem_copy(a4 + 6, v12, v11);
            v13 = 4LL * (unsigned __int16)a4[5];
            if ( (unsigned __int8)(4 * a4[5]) == v10 )
            {
              *((_BYTE *)a4 + 70) = 0;
              *((_BYTE *)a4 + 140) = 0;
              a4[18] = 1;
              goto LABEL_12;
            }
            v14 = v10 - v13;
            if ( v14 > 1u )
            {
              v15 = &v12[v13];
              qdf_mem_copy(a4 + 18, v15, 2u);
              v16 = (unsigned __int16)a4[18];
              v17 = v14 - 2;
              v18 = (unsigned int)(4 * v16);
              if ( (unsigned int)v18 <= v17 )
              {
                if ( (unsigned int)(v16 - 9) <= 0xFFFFFFF7 )
                  goto LABEL_17;
                v19 = v15 + 2;
                qdf_mem_copy(a4 + 19, v19, v18);
                v20 = 4LL * (unsigned __int16)a4[18];
                if ( (unsigned __int8)(4 * a4[18]) == v17 )
                {
                  result = 0;
                  *((_BYTE *)a4 + 70) = 0;
LABEL_29:
                  *((_BYTE *)a4 + 140) = 0;
                  goto LABEL_13;
                }
                v21 = v17 - v20;
                *((_BYTE *)a4 + 70) = 1;
                if ( v21 > 1u )
                {
                  v22 = &v19[v20];
                  qdf_mem_copy((char *)a4 + 71, v22, 2u);
                  if ( v21 == 2 )
                  {
                    result = 0;
                    goto LABEL_29;
                  }
                  if ( v21 != 3 )
                  {
                    qdf_mem_copy(a4 + 37, v22 + 2, 2u);
                    v23 = (unsigned __int16)a4[37];
                    v24 = v21 - 4;
                    v25 = 16 * v23;
                    if ( (unsigned int)v25 <= v24 )
                    {
                      if ( v23 >= 5 )
                        goto LABEL_17;
                      v26 = v22 + 4;
                      qdf_mem_copy(a4 + 38, v26, v25);
                      v27 = 16LL * (unsigned __int16)a4[37];
                      if ( (unsigned __int8)(16 * a4[37]) == v24 )
                      {
LABEL_36:
                        result = 0;
                        goto LABEL_18;
                      }
                      *((_BYTE *)a4 + 140) = 1;
                      if ( (unsigned __int8)(v24 - v27) > 3u )
                      {
                        qdf_mem_copy((char *)a4 + 141, &v26[v27], 4u);
                        goto LABEL_36;
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
    *(_BYTE *)a4 = 0;
    result = 4;
    goto LABEL_18;
  }
  result = 32;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
