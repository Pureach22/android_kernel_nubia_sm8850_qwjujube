__int64 __fastcall cam_ife_csid_ver2_set_debug(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  unsigned int v3; // w9
  _BYTE *v4; // x10
  int v5; // w11
  int v6; // w11
  int v7; // w12
  int v8; // w13
  int v9; // w14
  int v10; // w15
  int v11; // w16
  _BYTE *v12; // x1
  int v13; // w2
  bool v14; // cc
  char v15; // w2
  __int64 v16; // x2
  unsigned int v17; // w2
  int v18; // w3
  unsigned int v19; // w2
  int v20; // w3
  unsigned int v21; // w2
  int v22; // w3
  unsigned int v23; // w2
  int v24; // w3
  unsigned int v25; // w2
  int v26; // w3
  unsigned int v27; // w2
  int v28; // w3
  unsigned int v29; // w2
  int v30; // w3
  unsigned int v31; // w2
  int v32; // w3
  unsigned int v33; // w2
  int v34; // w3

  v2 = **(_QWORD **)(result + 31136);
  *(_QWORD *)(result + 2168) = 0;
  *(_QWORD *)(result + 2176) = 0;
  *(_QWORD *)(result + 2184) = 0;
  *(_QWORD *)(result + 2192) = 0;
  *(_QWORD *)(result + 2200) = 0;
  *(_QWORD *)(result + 2208) = 0;
  *(_QWORD *)(result + 2216) = 0;
  *(_QWORD *)(result + 2224) = 0;
  *(_QWORD *)(result + 2232) = 0;
  *(_QWORD *)(result + 2240) = 0;
  v3 = *(_DWORD *)a2;
  *(_DWORD *)(result + 2168) = *(_DWORD *)a2;
  *(_DWORD *)(result + 2204) = *(_DWORD *)(a2 + 12);
  *(_BYTE *)(result + 2214) = *(_BYTE *)(a2 + 21);
  *(_DWORD *)(result + 2208) = *(_DWORD *)(a2 + 16);
  *(_BYTE *)(result + 2215) = *(_BYTE *)(a2 + 22);
  v4 = *(_BYTE **)(v2 + 624);
  *(_DWORD *)(result + 2180) = *(_DWORD *)(a2 + 8) & 0xF;
  *(_DWORD *)(result + 2172) = (unsigned __int8)(*(_DWORD *)(a2 + 8) >> 4);
  *(_DWORD *)(result + 2176) = (unsigned __int8)(*(_DWORD *)(a2 + 8) >> 12);
  *(_BYTE *)(result + 2212) = *(_BYTE *)(a2 + 20);
  if ( *(_BYTE *)(a2 + 23) == 1 )
  {
    *(_DWORD *)(result + 2224) = *(_DWORD *)(a2 + 28);
    *(_DWORD *)(result + 2236) = *(_DWORD *)(a2 + 40);
    *(_DWORD *)(result + 2228) = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(result + 2240) = *(_DWORD *)(a2 + 44);
    *(_DWORD *)(result + 2232) = *(_DWORD *)(a2 + 36);
    *(_DWORD *)(result + 2244) = *(_DWORD *)(a2 + 48);
    v5 = *(_DWORD *)(a2 + 24);
    *(_BYTE *)(result + 2216) = 1;
    *(_DWORD *)(result + 2220) = v5;
  }
  if ( !v3 )
    return result;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = v4 + 16;
  while ( 1 )
  {
    if ( (v3 & 1) == 0 )
    {
      do
      {
        v15 = v3;
        v3 >>= 1;
        ++v11;
      }
      while ( (v15 & 2) == 0 );
    }
    v16 = 1LL << v11;
    if ( (int)(1LL << v11) > 31 )
    {
      if ( (int)v16 > 1023 )
      {
        switch ( (_DWORD)v16 )
        {
          case 0x400:
            v4 = *(_BYTE **)(v2 + 616);
            v33 = *(_DWORD *)(v2 + 656);
            v12 = v4 + 16;
            if ( v33 )
            {
              if ( (*v4 & 1) != 0 )
              {
                v8 |= 1LL << *v12;
                *(_DWORD *)(result + 2184) = v8;
                v33 = *(_DWORD *)(v2 + 656);
              }
              if ( v33 >= 2 )
              {
                if ( (v4[8] & 1) != 0 )
                {
                  v7 |= 1LL << *v12;
                  *(_DWORD *)(result + 2188) = v7;
                  v33 = *(_DWORD *)(v2 + 656);
                }
                if ( v33 >= 3 )
                {
                  v34 = 2;
                  while ( (*(_QWORD *)&v4[8 * v34] & 1) == 0 )
                  {
                    if ( ++v34 >= v33 )
                      goto LABEL_7;
                  }
                  goto LABEL_126;
                }
              }
            }
            break;
          case 0x800:
            v4 = *(_BYTE **)(v2 + 616);
            v27 = *(_DWORD *)(v2 + 656);
            v12 = v4 + 16;
            if ( v27 )
            {
              if ( (*v4 & 2) != 0 )
              {
                v8 |= 1LL << v4[17];
                *(_DWORD *)(result + 2184) = v8;
                v27 = *(_DWORD *)(v2 + 656);
              }
              if ( v27 >= 2 )
              {
                if ( (v4[8] & 2) != 0 )
                {
                  v7 |= 1LL << v4[17];
                  *(_DWORD *)(result + 2188) = v7;
                  v27 = *(_DWORD *)(v2 + 656);
                }
                if ( v27 >= 3 )
                {
                  v28 = 2;
                  while ( (*(_QWORD *)&v4[8 * v28] & 2) == 0 )
                  {
                    if ( ++v28 >= v27 )
                      goto LABEL_7;
                  }
                  goto LABEL_126;
                }
              }
            }
            break;
          case 0x1000:
            v4 = *(_BYTE **)(v2 + 616);
            v21 = *(_DWORD *)(v2 + 656);
            v12 = v4 + 16;
            if ( v21 )
            {
              if ( (*v4 & 4) != 0 )
              {
                v8 |= 1LL << v4[18];
                *(_DWORD *)(result + 2184) = v8;
                v21 = *(_DWORD *)(v2 + 656);
              }
              if ( v21 >= 2 )
              {
                if ( (v4[8] & 4) != 0 )
                {
                  v7 |= 1LL << v4[18];
                  *(_DWORD *)(result + 2188) = v7;
                  v21 = *(_DWORD *)(v2 + 656);
                }
                if ( v21 >= 3 )
                {
                  v22 = 2;
                  while ( (*(_QWORD *)&v4[8 * v22] & 4) == 0 )
                  {
                    if ( ++v22 >= v21 )
                      goto LABEL_7;
                  }
                  goto LABEL_126;
                }
              }
            }
            break;
        }
      }
      else
      {
        switch ( (_DWORD)v16 )
        {
          case 0x20:
            v31 = *(_DWORD *)(v2 + 660);
            if ( v31 )
            {
              if ( (v4[1] & 1) != 0 )
              {
                v10 |= 1LL << v12[8];
                *(_DWORD *)(result + 2192) = v10;
                v31 = *(_DWORD *)(v2 + 660);
              }
              if ( v31 >= 2 )
              {
                if ( (v4[9] & 1) != 0 )
                {
                  v6 |= 1LL << v12[8];
                  *(_DWORD *)(result + 2196) = v6;
                  v31 = *(_DWORD *)(v2 + 660);
                }
                if ( v31 >= 3 )
                {
                  v32 = 2;
                  while ( (*(_QWORD *)&v4[8 * v32] & 0x100) == 0 )
                  {
                    if ( ++v32 >= v31 )
                      goto LABEL_7;
                  }
                  goto LABEL_126;
                }
              }
            }
            break;
          case 0x40:
            v25 = *(_DWORD *)(v2 + 660);
            if ( v25 )
            {
              if ( (v4[1] & 4) != 0 )
              {
                v10 |= 1LL << v12[10];
                *(_DWORD *)(result + 2192) = v10;
                v25 = *(_DWORD *)(v2 + 660);
              }
              if ( v25 >= 2 )
              {
                if ( (v4[9] & 4) != 0 )
                {
                  v6 |= 1LL << v12[10];
                  *(_DWORD *)(result + 2196) = v6;
                  v25 = *(_DWORD *)(v2 + 660);
                }
                if ( v25 >= 3 )
                {
                  v26 = 2;
                  while ( (*(_QWORD *)&v4[8 * v26] & 0x400) == 0 )
                  {
                    if ( ++v26 >= v25 )
                      goto LABEL_7;
                  }
                  goto LABEL_126;
                }
              }
            }
            break;
          case 0x200:
            v17 = *(_DWORD *)(v2 + 660);
            if ( v17 )
            {
              if ( (v4[2] & 0x40) != 0 )
              {
                v10 |= 1LL << v12[22];
                *(_DWORD *)(result + 2192) = v10;
                v17 = *(_DWORD *)(v2 + 660);
              }
              if ( v17 >= 2 )
              {
                if ( (v4[10] & 0x40) != 0 )
                {
                  v6 |= 1LL << v12[22];
                  *(_DWORD *)(result + 2196) = v6;
                  v17 = *(_DWORD *)(v2 + 660);
                }
                if ( v17 >= 3 )
                {
                  v18 = 2;
                  while ( (*(_QWORD *)&v4[8 * v18] & 0x400000) == 0 )
                  {
                    if ( ++v18 >= v17 )
                      goto LABEL_7;
                  }
                  goto LABEL_126;
                }
              }
            }
            break;
        }
      }
      goto LABEL_7;
    }
    if ( (int)v16 > 3 )
      break;
    if ( (_DWORD)v16 == 1 )
    {
      v13 = 4096;
    }
    else
    {
      if ( (_DWORD)v16 != 2 )
        goto LABEL_7;
      v13 = 512;
    }
    v9 |= v13;
    *(_DWORD *)(result + 2200) = v9;
LABEL_7:
    v14 = v3 > 1;
    ++v11;
    v3 >>= 1;
    if ( !v14 )
      return result;
  }
  if ( (_DWORD)v16 != 4 )
  {
    if ( (_DWORD)v16 == 8 )
    {
      v23 = *(_DWORD *)(v2 + 660);
      if ( v23 )
      {
        if ( (*v4 & 1) != 0 )
        {
          v10 |= (1LL << v12[1]) | (1LL << *v12) | (1LL << v12[2]) | (1LL << v12[3]);
          *(_DWORD *)(result + 2192) = v10;
          v23 = *(_DWORD *)(v2 + 660);
        }
        if ( v23 >= 2 )
        {
          if ( (v4[8] & 1) != 0 )
          {
            v6 |= (1LL << v12[1]) | (1LL << *v12) | (1LL << v12[2]) | (1LL << v12[3]);
            *(_DWORD *)(result + 2196) = v6;
            v23 = *(_DWORD *)(v2 + 660);
          }
          if ( v23 >= 3 )
          {
            v24 = 2;
            while ( (*(_QWORD *)&v4[8 * v24] & 1) == 0 )
            {
              if ( ++v24 >= v23 )
                goto LABEL_7;
            }
            goto LABEL_126;
          }
        }
      }
    }
    else if ( (_DWORD)v16 == 16 )
    {
      v19 = *(_DWORD *)(v2 + 660);
      if ( v19 )
      {
        if ( (v4[1] & 2) != 0 )
        {
          v10 |= 1LL << v12[9];
          *(_DWORD *)(result + 2192) = v10;
          v19 = *(_DWORD *)(v2 + 660);
        }
        if ( v19 >= 2 )
        {
          if ( (v4[9] & 2) != 0 )
          {
            v6 |= 1LL << v12[9];
            *(_DWORD *)(result + 2196) = v6;
            v19 = *(_DWORD *)(v2 + 660);
          }
          if ( v19 >= 3 )
          {
            v20 = 2;
            while ( (*(_QWORD *)&v4[8 * v20] & 0x200) == 0 )
            {
              if ( ++v20 >= v19 )
                goto LABEL_7;
            }
            goto LABEL_126;
          }
        }
      }
    }
    goto LABEL_7;
  }
  v29 = *(_DWORD *)(v2 + 660);
  if ( !v29 )
    goto LABEL_7;
  if ( (*v4 & 0x10) != 0 )
  {
    v10 |= (1LL << v12[5]) | (1LL << v12[4]) | (1LL << v12[6]) | (1LL << v12[7]);
    *(_DWORD *)(result + 2192) = v10;
    v29 = *(_DWORD *)(v2 + 660);
  }
  if ( v29 < 2 )
    goto LABEL_7;
  if ( (v4[8] & 0x10) != 0 )
  {
    v6 |= (1LL << v12[5]) | (1LL << v12[4]) | (1LL << v12[6]) | (1LL << v12[7]);
    *(_DWORD *)(result + 2196) = v6;
    v29 = *(_DWORD *)(v2 + 660);
  }
  if ( v29 < 3 )
    goto LABEL_7;
  v30 = 2;
  while ( (*(_QWORD *)&v4[8 * v30] & 0x10) == 0 )
  {
    if ( ++v30 >= v29 )
      goto LABEL_7;
  }
LABEL_126:
  __break(0x5512u);
  return cam_ife_csid_ver2_eof_irq_enable(result, v12);
}
