_BYTE *__fastcall rate_idx_match_mask(
        _BYTE *result,
        __int16 *a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        __int64 a6,
        __int64 a7)
{
  int v7; // w8
  int v8; // w10
  bool v9; // cc
  __int16 v10; // w9
  int v11; // w9
  char v12; // w8
  unsigned int v13; // w10
  __int64 v14; // x8
  unsigned __int64 v15; // x11
  char v16; // w12
  int v17; // w10
  int v18; // w8
  int v19; // w9
  unsigned int v20; // w12
  __int64 v21; // x9
  int v22; // w8
  __int64 v23; // x9
  int v24; // w10
  char v25; // w9
  __int64 v26; // x8
  __int64 v27; // x9
  __int16 v28; // w9
  __int16 v29; // w8
  int v30; // w10
  int v31; // w9
  char v32; // w8
  unsigned __int64 v33; // x11
  char v34; // w8
  unsigned int v35; // w11
  __int64 v36; // x8
  unsigned __int64 v37; // x12
  char v38; // w13
  int v39; // w10
  int v40; // w8
  int v41; // w9
  unsigned int v42; // w12
  __int64 v43; // x9
  unsigned int v44; // w10
  __int64 v45; // x10
  int v46; // w11
  int v47; // w8
  int v48; // w10
  unsigned int v49; // w13
  __int64 v50; // x10
  unsigned int v51; // w11
  __int64 v52; // x11
  unsigned int v53; // w10
  __int64 v54; // x10

  if ( (*a2 & 0x100) == 0 )
  {
    if ( (*a2 & 8) == 0 )
    {
      v7 = (char)*result;
      if ( v7 < 0 )
        goto LABEL_10;
      v8 = (char)*result;
      while ( ((a5 >> v8) & 1) == 0 )
      {
        v9 = v8-- <= 0;
        if ( v9 )
        {
LABEL_10:
          while ( ++v7 < *(_DWORD *)(a3 + 24) )
          {
            if ( ((a5 >> v7) & 1) != 0 )
              goto LABEL_61;
          }
          if ( a4 <= 7 && ((1 << a4) & 0xC1) != 0 )
            return result;
          *result = 0;
          v10 = a4 == 2 ? 40 : 8;
          *a2 = v10 & 0xFFF8 | *a2 & 7;
          v11 = (char)*result;
          if ( (unsigned __int8)(*result - 80) < 0xA9u )
            return result;
          v12 = v11 + (((unsigned int)(char)v11 >> 12) & 7);
          LOBYTE(v13) = v11 - (v12 & 0xF8);
          v14 = (unsigned __int8)((unsigned __int64)(unsigned int)v12 >> 3);
          if ( (v13 & 0x80) != 0 )
            goto LABEL_24;
          v15 = *(unsigned __int8 *)(a6 + v14);
          if ( ((v15 >> v13) & 1) != 0 )
            goto LABEL_108;
          if ( !(_BYTE)v13 )
            goto LABEL_24;
          v16 = v13 - 1;
          if ( ((v15 >> ((unsigned __int8)v13 - 1)) & 1) != 0 )
            goto LABEL_77;
          v16 = v13 - 2;
          if ( (char)v13 < 2 )
            goto LABEL_24;
          if ( ((v15 >> v16) & 1) != 0 )
            goto LABEL_77;
          if ( (char)v13 == 2 )
            goto LABEL_24;
          v16 = v13 - 3;
          if ( ((v15 >> ((unsigned __int8)v13 - 3)) & 1) != 0 )
            goto LABEL_77;
          v16 = v13 - 4;
          if ( (char)v13 < 4 )
            goto LABEL_24;
          if ( ((v15 >> v16) & 1) != 0 )
            goto LABEL_77;
          if ( (char)v13 == 4 )
            goto LABEL_24;
          v16 = v13 - 5;
          if ( ((v15 >> ((unsigned __int8)v13 - 5)) & 1) != 0 )
            goto LABEL_77;
          v16 = v13 - 6;
          if ( (char)v13 < 6 )
            goto LABEL_24;
          if ( ((v15 >> v16) & 1) != 0 )
            goto LABEL_77;
          if ( (char)v13 == 6 || (LOBYTE(v13) = v13 - 7, ((v15 >> v13) & 1) == 0) )
          {
LABEL_24:
            if ( (unsigned int)(v11 + 7) >= 0xF )
            {
              --v14;
              while ( (*(char *)(a6 + v14) & 0x80000000) == 0 )
              {
                v53 = *(unsigned __int8 *)(a6 + v14);
                if ( v53 > 0x3F )
                  goto LABEL_152;
                if ( v53 > 0x1F )
                  goto LABEL_153;
                if ( v53 > 0xF )
                  goto LABEL_154;
                if ( v53 > 7 )
                  goto LABEL_155;
                if ( v53 > 3 )
                  goto LABEL_156;
                if ( v53 > 1 )
                  goto LABEL_157;
                if ( *(_BYTE *)(a6 + v14) )
                  goto LABEL_158;
                v54 = v14-- + 1;
                if ( v54 <= 1 )
                  goto LABEL_25;
              }
              goto LABEL_151;
            }
LABEL_25:
            if ( v11 > 78 )
              return result;
            v17 = v11 + 1;
            v18 = v11 + 8;
            if ( v11 + 1 >= 0 )
              v18 = v11 + 1;
            v19 = v18 >> 3;
            v20 = v18 & 0xFFFFFFF8;
            v14 = (__int64)v18 >> 3;
            v13 = v17 - v20;
            if ( v19 <= 9 )
              v19 = 9;
            v21 = (unsigned int)(v19 + 1);
            while ( (((unsigned __int64)*(unsigned __int8 *)(a6 + v14) >> v13) & 1) == 0 )
            {
              if ( ++v13 == 8 )
              {
                ++v14;
                v13 = 0;
                if ( v14 == v21 )
                  return result;
              }
            }
          }
          goto LABEL_108;
        }
      }
LABEL_72:
      *result = v8;
      return result;
    }
    v31 = (char)*result;
    if ( (unsigned __int8)(*result - 80) < 0xA9u )
    {
LABEL_63:
      *result = 0;
      *a2 &= 7u;
      v7 = (char)*result;
      if ( v7 < 0 )
        goto LABEL_70;
      v8 = (char)*result;
      while ( ((a5 >> v8) & 1) == 0 )
      {
        v9 = v8-- <= 0;
        if ( v9 )
        {
LABEL_70:
          while ( ++v7 < *(_DWORD *)(a3 + 24) )
          {
            if ( ((a5 >> v7) & 1) != 0 )
              goto LABEL_61;
          }
          return result;
        }
      }
      goto LABEL_72;
    }
    v32 = v31 + (((unsigned int)(char)v31 >> 12) & 7);
    LOBYTE(v13) = v31 - (v32 & 0xF8);
    v14 = (unsigned __int8)((unsigned __int64)(unsigned int)v32 >> 3);
    if ( (v13 & 0x80) == 0 )
    {
      v33 = *(unsigned __int8 *)(a6 + v14);
      if ( ((v33 >> v13) & 1) != 0 )
      {
LABEL_108:
        *result = v13 + 8 * v14;
        return result;
      }
      if ( (_BYTE)v13 )
      {
        v16 = v13 - 1;
        if ( ((v33 >> ((unsigned __int8)v13 - 1)) & 1) != 0 )
        {
LABEL_77:
          LOBYTE(v13) = v16;
          goto LABEL_108;
        }
        v16 = v13 - 2;
        if ( (char)v13 >= 2 )
        {
          if ( ((v33 >> v16) & 1) != 0 )
            goto LABEL_77;
          if ( (char)v13 != 2 )
          {
            v16 = v13 - 3;
            if ( ((v33 >> ((unsigned __int8)v13 - 3)) & 1) != 0 )
              goto LABEL_77;
            v16 = v13 - 4;
            if ( (char)v13 >= 4 )
            {
              if ( ((v33 >> v16) & 1) != 0 )
                goto LABEL_77;
              if ( (char)v13 != 4 )
              {
                v16 = v13 - 5;
                if ( ((v33 >> ((unsigned __int8)v13 - 5)) & 1) != 0 )
                  goto LABEL_77;
                v16 = v13 - 6;
                if ( (char)v13 >= 6 )
                {
                  if ( ((v33 >> v16) & 1) != 0 )
                    goto LABEL_77;
                  if ( (char)v13 != 6 )
                  {
                    LOBYTE(v13) = v13 - 7;
                    if ( ((v33 >> v13) & 1) != 0 )
                      goto LABEL_108;
                  }
                }
              }
            }
          }
        }
      }
    }
    if ( (unsigned int)(v31 + 7) >= 0xF )
    {
      --v14;
      while ( 1 )
      {
        if ( *(char *)(a6 + v14) < 0 )
        {
LABEL_151:
          LOBYTE(v13) = 7;
          goto LABEL_108;
        }
        v44 = *(unsigned __int8 *)(a6 + v14);
        if ( v44 > 0x3F )
        {
LABEL_152:
          LOBYTE(v13) = 6;
          goto LABEL_108;
        }
        if ( v44 > 0x1F )
        {
LABEL_153:
          LOBYTE(v13) = 5;
          goto LABEL_108;
        }
        if ( v44 > 0xF )
        {
LABEL_154:
          LOBYTE(v13) = 4;
          goto LABEL_108;
        }
        if ( v44 > 7 )
        {
LABEL_155:
          LOBYTE(v13) = 3;
          goto LABEL_108;
        }
        if ( v44 > 3 )
        {
LABEL_156:
          LOBYTE(v13) = 2;
          goto LABEL_108;
        }
        if ( v44 > 1 )
        {
LABEL_157:
          LOBYTE(v13) = 1;
          goto LABEL_108;
        }
        if ( *(_BYTE *)(a6 + v14) )
          break;
        v45 = v14-- + 1;
        if ( v45 <= 1 )
          goto LABEL_87;
      }
LABEL_158:
      LOBYTE(v13) = 0;
    }
    else
    {
LABEL_87:
      if ( v31 > 78 )
        goto LABEL_63;
      v39 = v31 + 1;
      v40 = v31 + 8;
      if ( v31 + 1 >= 0 )
        v40 = v31 + 1;
      v41 = v40 >> 3;
      v42 = v40 & 0xFFFFFFF8;
      v14 = (__int64)v40 >> 3;
      v13 = v39 - v42;
      if ( v41 <= 9 )
        v41 = 9;
      v43 = (unsigned int)(v41 + 1);
      while ( (((unsigned __int64)*(unsigned __int8 *)(a6 + v14) >> v13) & 1) == 0 )
      {
        if ( ++v13 == 8 )
        {
          ++v14;
          v13 = 0;
          if ( v14 == v43 )
            goto LABEL_63;
        }
      }
    }
    goto LABEL_108;
  }
  v22 = (char)*result;
  v23 = (unsigned int)(v22 >> 4);
  if ( (v23 & 0x80000000) != 0 )
  {
LABEL_47:
    *result = 0;
    v28 = *a2;
    if ( a4 == 2 )
      v29 = 40;
    else
      v29 = 8;
    *a2 = v29 & 0xFFF8 | *a2 & 7;
    v30 = (char)*result;
    if ( (unsigned __int8)(*result - 80) < 0xA9u )
    {
LABEL_51:
      *a2 = v28 & 7;
      v7 = (char)*result;
      if ( v7 < 0 )
        goto LABEL_58;
      v8 = (char)*result;
      while ( ((a5 >> v8) & 1) == 0 )
      {
        v9 = v8-- <= 0;
        if ( v9 )
        {
LABEL_58:
          while ( ++v7 < *(_DWORD *)(a3 + 24) )
          {
            if ( ((a5 >> v7) & 1) != 0 )
              goto LABEL_61;
          }
          return result;
        }
      }
      goto LABEL_72;
    }
    v34 = v30 + (((unsigned int)(char)v30 >> 12) & 7);
    LOBYTE(v35) = v30 - (v34 & 0xF8);
    v36 = (unsigned __int8)((unsigned __int64)(unsigned int)v34 >> 3);
    if ( (v35 & 0x80) == 0 )
    {
      v37 = *(unsigned __int8 *)(a6 + v36);
      if ( ((v37 >> v35) & 1) != 0 )
        goto LABEL_134;
      if ( (_BYTE)v35 )
      {
        v38 = v35 - 1;
        if ( ((v37 >> ((unsigned __int8)v35 - 1)) & 1) != 0 )
        {
LABEL_82:
          LOBYTE(v35) = v38;
          goto LABEL_134;
        }
        v38 = v35 - 2;
        if ( (char)v35 >= 2 )
        {
          if ( ((v37 >> v38) & 1) != 0 )
            goto LABEL_82;
          if ( (char)v35 != 2 )
          {
            v38 = v35 - 3;
            if ( ((v37 >> ((unsigned __int8)v35 - 3)) & 1) != 0 )
              goto LABEL_82;
            v38 = v35 - 4;
            if ( (char)v35 >= 4 )
            {
              if ( ((v37 >> v38) & 1) != 0 )
                goto LABEL_82;
              if ( (char)v35 != 4 )
              {
                v38 = v35 - 5;
                if ( ((v37 >> ((unsigned __int8)v35 - 5)) & 1) != 0 )
                  goto LABEL_82;
                v38 = v35 - 6;
                if ( (char)v35 >= 6 )
                {
                  if ( ((v37 >> v38) & 1) != 0 )
                    goto LABEL_82;
                  if ( (char)v35 != 6 )
                  {
                    LOBYTE(v35) = v35 - 7;
                    if ( ((v37 >> v35) & 1) != 0 )
                      goto LABEL_134;
                  }
                }
              }
            }
          }
        }
      }
    }
    if ( (unsigned int)(v30 + 7) >= 0xF )
    {
      --v36;
      while ( 1 )
      {
        if ( *(char *)(a6 + v36) < 0 )
        {
          LOBYTE(v35) = 7;
          goto LABEL_134;
        }
        v51 = *(unsigned __int8 *)(a6 + v36);
        if ( v51 > 0x3F )
        {
          LOBYTE(v35) = 6;
          goto LABEL_134;
        }
        if ( v51 > 0x1F )
        {
          LOBYTE(v35) = 5;
          goto LABEL_134;
        }
        if ( v51 > 0xF )
        {
          LOBYTE(v35) = 4;
          goto LABEL_134;
        }
        if ( v51 > 7 )
        {
          LOBYTE(v35) = 3;
          goto LABEL_134;
        }
        if ( v51 > 3 )
        {
          LOBYTE(v35) = 2;
          goto LABEL_134;
        }
        if ( v51 > 1 )
        {
          LOBYTE(v35) = 1;
          goto LABEL_134;
        }
        if ( *(_BYTE *)(a6 + v36) )
          break;
        v52 = v36-- + 1;
        if ( v52 <= 1 )
          goto LABEL_113;
      }
      LOBYTE(v35) = 0;
    }
    else
    {
LABEL_113:
      if ( v30 > 78 )
        goto LABEL_51;
      v46 = v30 + 1;
      v47 = v30 + 8;
      if ( v30 + 1 >= 0 )
        v47 = v30 + 1;
      v48 = v47 >> 3;
      v49 = v47 & 0xFFFFFFF8;
      v36 = (__int64)v47 >> 3;
      v35 = v46 - v49;
      if ( v48 <= 9 )
        v48 = 9;
      v50 = (unsigned int)(v48 + 1);
      while ( (((unsigned __int64)*(unsigned __int8 *)(a6 + v36) >> v35) & 1) == 0 )
      {
        if ( ++v35 == 8 )
        {
          ++v36;
          v35 = 0;
          if ( v36 == v50 )
            goto LABEL_51;
        }
      }
    }
LABEL_134:
    *result = v35 + 8 * v36;
    return result;
  }
  v24 = v22 & 0xF;
  while ( 1 )
  {
    if ( (((unsigned __int64)*(unsigned __int16 *)(a7 + 2 * v23) >> v24) & 1) != 0 )
    {
      LOBYTE(v7) = v24 | (16 * v23);
LABEL_61:
      *result = v7;
      return result;
    }
    v9 = v24-- <= 0;
    if ( v9 )
    {
      v9 = v23-- <= 0;
      v24 = 15;
      if ( v9 )
        break;
    }
  }
  v25 = v22 + 1;
  LODWORD(v26) = (v22 + 1) >> 4;
  if ( (int)v26 > 7 )
    goto LABEL_47;
  v26 = (int)v26;
  v27 = v25 & 0xF;
  while ( (((unsigned __int64)*(unsigned __int16 *)(a7 + 2 * v26) >> v27) & 1) == 0 )
  {
    if ( ++v27 == 16 )
    {
      ++v26;
      v27 = 0;
      if ( v26 == 8 )
        goto LABEL_47;
    }
  }
  *result = v27 + 16 * v26;
  return result;
}
