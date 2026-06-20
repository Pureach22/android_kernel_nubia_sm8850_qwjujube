__int64 __fastcall msm_find_most_appropriate_phase(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 v3; // x3
  _QWORD *v4; // x8
  unsigned __int64 v5; // x10
  unsigned int v6; // w9
  __int64 v7; // x11
  unsigned __int8 *v8; // x12
  __int64 v9; // x16
  char v10; // w14
  signed int v11; // w15
  _BYTE *v12; // x11
  __int64 v13; // x12
  int v14; // w16
  unsigned int v15; // w10
  unsigned int v16; // w11
  __int64 v17; // x10
  __int64 result; // x0
  __int64 v19; // x2
  __int64 v20; // x10
  __int64 v21; // x12
  __int64 v22; // x16
  unsigned int v23; // w11
  __int64 v24; // x13
  bool v25; // cf
  __int64 v26; // x15
  unsigned __int64 v27; // x14
  __int64 v28; // x16
  __int64 v29; // x2
  __int64 v30; // [xsp+8h] [xbp-118h]
  __int64 v31; // [xsp+10h] [xbp-110h]
  _QWORD v32[33]; // [xsp+18h] [xbp-108h] BYREF

  v3 = a3;
  v32[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD **)(a1 + 72);
  memset(v32, 0, 256);
  v30 = 0;
  v31 = 0;
  if ( a3 > 0x10u )
  {
    v29 = v4[15];
    if ( !v29 )
      v29 = v4[1];
    dev_err(*v4, "%s: Invalid argument: total_phases=%d\n", v29, v3);
LABEL_152:
    result = 4294967274LL;
    goto LABEL_153;
  }
  if ( !a3 )
  {
    v6 = 0;
    goto LABEL_54;
  }
  v5 = 0;
  v6 = 0;
  v7 = a3;
  v8 = (unsigned __int8 *)(a2 + 1);
  do
  {
    if ( v6 > 0xF || v5 >= 0x10 )
      goto LABEL_155;
    if ( (v5 | (16LL * v6)) > 0x100 )
      goto LABEL_154;
    v9 = *(v8 - 1);
    *((_BYTE *)&v32[2 * v6] + v5++) = v9;
    ++*((_BYTE *)&v30 + v6);
    if ( v7 != 1 && v9 + 1 != *v8 )
    {
      ++v6;
      v5 = 0;
    }
    --v7;
    ++v8;
  }
  while ( v7 );
  if ( v6 > 0xF )
    goto LABEL_152;
  if ( LOBYTE(v32[0]) || !v6 )
    goto LABEL_54;
  v10 = 0;
  v11 = 0;
  v12 = (char *)&v32[3] + 7;
  v13 = 1;
  do
  {
    if ( v13 == 16 )
      goto LABEL_155;
    v14 = *((unsigned __int8 *)&v30 + v13);
    if ( *((_BYTE *)&v30 + v13) )
    {
      if ( *(v12 - 15) == 15 )
        goto LABEL_16;
      if ( v14 != 1 )
      {
        if ( *(v12 - 14) == 15 )
          goto LABEL_16;
        if ( v14 != 2 )
        {
          if ( *(v12 - 13) == 15 )
            goto LABEL_16;
          if ( v14 != 3 )
          {
            if ( *(v12 - 12) == 15 )
              goto LABEL_16;
            if ( v14 != 4 )
            {
              if ( *(v12 - 11) == 15 )
                goto LABEL_16;
              if ( v14 != 5 )
              {
                if ( *(v12 - 10) == 15 )
                  goto LABEL_16;
                if ( v14 != 6 )
                {
                  if ( *(v12 - 9) == 15 )
                    goto LABEL_16;
                  if ( v14 != 7 )
                  {
                    if ( *(v12 - 8) == 15 )
                      goto LABEL_16;
                    if ( v14 != 8 )
                    {
                      if ( *(v12 - 7) == 15 )
                        goto LABEL_16;
                      if ( v14 != 9 )
                      {
                        if ( *(v12 - 6) == 15 )
                          goto LABEL_16;
                        if ( v14 != 10 )
                        {
                          if ( *(v12 - 5) == 15 )
                            goto LABEL_16;
                          if ( v14 != 11 )
                          {
                            if ( *(v12 - 4) == 15 )
                              goto LABEL_16;
                            if ( v14 != 12 )
                            {
                              if ( *(v12 - 3) == 15 )
                                goto LABEL_16;
                              if ( v14 != 13 )
                              {
                                if ( *(v12 - 2) == 15 )
                                  goto LABEL_16;
                                if ( v14 != 14 )
                                {
                                  if ( *(v12 - 1) == 15 )
                                    goto LABEL_16;
                                  if ( v14 != 15 )
                                  {
                                    if ( *v12 == 15 )
                                    {
LABEL_16:
                                      v10 = 1;
                                      v11 = v13;
                                      goto LABEL_17;
                                    }
                                    if ( v14 != 16 )
                                      goto LABEL_155;
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
      }
    }
LABEL_17:
    ++v13;
    v12 += 16;
  }
  while ( v6 + 1 != v13 );
  if ( (v10 & 1) == 0 )
    goto LABEL_54;
  if ( (unsigned int)v11 > 0xF )
    goto LABEL_155;
  v20 = v11;
  v21 = (unsigned __int8)v30;
  v22 = *((unsigned __int8 *)&v30 + v11);
  v23 = v22 + (unsigned __int8)v30;
  if ( v23 > 0xF )
    goto LABEL_152;
  if ( (_BYTE)v30 )
  {
    v24 = 0;
    v25 = (unsigned int)v22 <= 0x10;
    LODWORD(v26) = 16 - v22;
    v27 = v22 + 16 * v20;
    v28 = 15 - v22;
    if ( v25 )
      v26 = (unsigned int)v26;
    else
      v26 = 0;
    while ( v26 != v24 )
    {
      if ( v27 > 0xFF )
        goto LABEL_154;
      *((_BYTE *)v32 + v27) = *((_BYTE *)v32 + v24);
      if ( v28 != v24 )
      {
        ++v24;
        ++v27;
        if ( v21 != v24 )
          continue;
      }
      goto LABEL_148;
    }
LABEL_155:
    __break(0x5512u);
  }
LABEL_148:
  LOBYTE(v30) = 0;
  *((_BYTE *)&v30 + v20) = v23;
LABEL_54:
  v15 = (unsigned __int8)v30;
  if ( v6 )
  {
    v16 = v6 + 1;
    v6 = (unsigned __int8)v30 < (unsigned int)BYTE1(v30);
    if ( (unsigned __int8)v30 <= (int)BYTE1(v30) )
      v15 = BYTE1(v30);
    if ( v16 != 2 )
    {
      if ( v15 < BYTE2(v30) )
        v6 = 2;
      if ( (int)v15 <= BYTE2(v30) )
        v15 = BYTE2(v30);
      if ( v16 != 3 )
      {
        if ( v15 < BYTE3(v30) )
          v6 = 3;
        if ( (int)v15 <= BYTE3(v30) )
          v15 = BYTE3(v30);
        if ( v16 != 4 )
        {
          if ( v15 < BYTE4(v30) )
            v6 = 4;
          if ( (int)v15 <= BYTE4(v30) )
            v15 = BYTE4(v30);
          if ( v16 != 5 )
          {
            if ( v15 < BYTE5(v30) )
              v6 = 5;
            if ( (int)v15 <= BYTE5(v30) )
              v15 = BYTE5(v30);
            if ( v16 != 6 )
            {
              if ( v15 < BYTE6(v30) )
                v6 = 6;
              if ( (int)v15 <= BYTE6(v30) )
                v15 = BYTE6(v30);
              if ( v16 != 7 )
              {
                if ( v15 < HIBYTE(v30) )
                  v6 = 7;
                if ( (int)v15 <= HIBYTE(v30) )
                  v15 = HIBYTE(v30);
                if ( v16 != 8 )
                {
                  if ( v15 < (unsigned __int8)v31 )
                    v6 = 8;
                  if ( (int)v15 <= (unsigned __int8)v31 )
                    v15 = (unsigned __int8)v31;
                  if ( v16 != 9 )
                  {
                    if ( v15 < BYTE1(v31) )
                      v6 = 9;
                    if ( (int)v15 <= BYTE1(v31) )
                      v15 = BYTE1(v31);
                    if ( v16 != 10 )
                    {
                      if ( v15 < BYTE2(v31) )
                        v6 = 10;
                      if ( (int)v15 <= BYTE2(v31) )
                        v15 = BYTE2(v31);
                      if ( v16 != 11 )
                      {
                        if ( v15 < BYTE3(v31) )
                          v6 = 11;
                        if ( (int)v15 <= BYTE3(v31) )
                          v15 = BYTE3(v31);
                        if ( v16 != 12 )
                        {
                          if ( v15 < BYTE4(v31) )
                            v6 = 12;
                          if ( (int)v15 <= BYTE4(v31) )
                            v15 = BYTE4(v31);
                          if ( v16 != 13 )
                          {
                            if ( v15 < BYTE5(v31) )
                              v6 = 13;
                            if ( (int)v15 <= BYTE5(v31) )
                              v15 = BYTE5(v31);
                            if ( v16 != 14 )
                            {
                              if ( v15 < BYTE6(v31) )
                                v6 = 14;
                              if ( (int)v15 <= BYTE6(v31) )
                                v15 = BYTE6(v31);
                              if ( v16 != 15 )
                              {
                                if ( v15 < HIBYTE(v31) )
                                  v6 = 15;
                                if ( (int)v15 <= HIBYTE(v31) )
                                  v15 = HIBYTE(v31);
                                if ( v16 != 16 )
                                  goto LABEL_154;
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
  }
  if ( v15 >= 2 )
    v17 = ((3 * v15) >> 2) - 1;
  else
    v17 = 0;
  if ( (unsigned int)v17 > 0xF )
    goto LABEL_155;
  if ( (v17 | (16 * (unsigned __int64)v6)) > 0x100 )
  {
LABEL_154:
    __break(1u);
    goto LABEL_155;
  }
  result = *((unsigned __int8 *)&v32[2 * v6] + v17);
  if ( (unsigned int)result >= 0x10 )
  {
    v19 = v4[15];
    if ( !v19 )
      v19 = v4[1];
    dev_err(*v4, "%s: Invalid phase selected=%d\n", v19, 4294967274LL);
    goto LABEL_152;
  }
LABEL_153:
  _ReadStatusReg(SP_EL0);
  return result;
}
