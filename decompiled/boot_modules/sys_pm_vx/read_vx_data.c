__int64 __fastcall read_vx_data(unsigned __int64 *a1, unsigned __int64 a2)
{
  unsigned __int64 v2; // x20
  unsigned int v5; // w0
  __int64 v6; // x9
  __int64 v7; // x8
  __int64 result; // x0
  unsigned __int64 v9; // x25
  int v10; // w0
  unsigned __int64 v11; // x23
  __int64 v12; // x28
  unsigned __int64 v13; // x26
  unsigned int v14; // w27
  unsigned __int64 v15; // x8
  int v16; // w0
  unsigned __int64 v17; // x8
  _DWORD *v18; // x19
  __int64 v19; // x24
  int v20; // w28
  unsigned __int64 v21; // x19
  unsigned int v22; // w0
  unsigned __int64 v23; // x8
  bool v24; // cf
  unsigned __int64 v25; // x8
  int v26; // w8
  bool v27; // cc
  unsigned __int64 v28; // x9
  unsigned __int64 v29; // x19
  unsigned __int64 StatusReg; // x19
  __int64 v31; // x21
  __int64 v32; // [xsp+8h] [xbp-38h]
  unsigned __int64 v33; // [xsp+10h] [xbp-30h]
  unsigned __int64 v34; // [xsp+18h] [xbp-28h]
  unsigned __int64 v35; // [xsp+20h] [xbp-20h]
  unsigned __int64 v36; // [xsp+28h] [xbp-18h]
  _DWORD *v37; // [xsp+30h] [xbp-10h]

  v2 = *a1;
  v5 = readl_relaxed(*a1);
  __dmb(9u);
  if ( !v5 )
    return 4294967294LL;
  v6 = 4;
  *(_WORD *)(a2 + 2) = bswap32(v5) >> 16;
  v7 = 2;
  if ( (unsigned __int8)v5 != 221 && (unsigned __int8)v5 != 204 )
  {
    if ( (unsigned __int8)v5 != 170 )
      return 4294967277LL;
    v6 = 5;
    v7 = 3;
  }
  result = 4294967277LL;
  if ( a1[v6] )
  {
    v9 = a1[v7];
    if ( v9 )
    {
      v10 = readl_relaxed(v2 + 4);
      __dmb(9u);
      if ( v10 )
      {
        *(_WORD *)(a2 + 6) = v10;
        *(_BYTE *)(a2 + 5) = BYTE2(v10);
        *(_BYTE *)(a2 + 4) = HIBYTE(v10);
        v11 = 16LL * *(unsigned __int8 *)(a2 + 2);
        v12 = _kmalloc_noprof(v11, 3520);
        if ( !v12 )
          return 4294967284LL;
        while ( 1 )
        {
          if ( !*(_BYTE *)(a2 + 2) )
          {
            LODWORD(v13) = 0;
LABEL_35:
            *(_QWORD *)(a2 + 8) = v12;
            *(_DWORD *)(a2 + 16) = v13;
            return 0;
          }
          v13 = 0;
          v14 = 8;
          v15 = (v9 + 3) & 0xFFFFFFFFFFFFFFFCLL;
          v33 = a2;
          v35 = v11;
          v34 = 4 * v15;
          v36 = v15 >> 62;
          _ReadStatusReg(SP_EL0);
          v32 = v12;
LABEL_12:
          v16 = readl_relaxed(v2 + v14);
          v17 = 16 * v13;
          __dmb(9u);
          if ( v11 > 16 * v13 )
          {
            v18 = (_DWORD *)(v12 + v17);
            *(_DWORD *)(v12 + 16 * v13) = v16;
            if ( !v16 )
              goto LABEL_35;
            if ( v11 > v17 )
            {
              *v18 = v16 << *(_BYTE *)(a2 + 5);
              if ( v36 || (v19 = _kmalloc_noprof(v34, 3520)) == 0 )
              {
                v2 = v35;
                if ( !(_DWORD)v13 )
                {
LABEL_40:
                  kfree(v12);
                  return 4294967284LL;
                }
                v29 = 8;
                while ( v35 >= v29 )
                {
                  kfree(*(_QWORD *)(v12 + v29));
                  --v13;
                  v29 += 16LL;
                  if ( !v13 )
                    goto LABEL_40;
                }
              }
              else
              {
                v37 = v18;
                a2 = v34 - 12;
                v20 = 4;
                v21 = 12;
                while ( 1 )
                {
                  v22 = readl_relaxed(v2 + v14 + v20);
                  v23 = 4LL * (v20 - 4);
                  __dmb(9u);
                  v24 = v34 >= v23;
                  v25 = v34 - v23;
                  if ( v20 - 4 < 0 )
                    break;
                  if ( !v24 )
                    break;
                  if ( v25 < 4 )
                    break;
                  *(_DWORD *)(v19 + 4LL * (v20 - 4)) = (unsigned __int8)v22;
                  if ( v34 < v21 - 8 )
                    break;
                  if ( a2 + 8 < 4 )
                    break;
                  *(_DWORD *)(v19 + v21 - 8) = BYTE1(v22);
                  if ( v34 < v21 - 4 )
                    break;
                  if ( a2 >= 0xFFFFFFFFFFFFFFFCLL )
                    break;
                  *(_DWORD *)(v19 + v21 - 4) = BYTE2(v22);
                  if ( v34 < v21 || a2 < 4 )
                    break;
                  v26 = v20 + 4;
                  v27 = v9 > v20;
                  *(_DWORD *)(v19 + v21) = HIBYTE(v22);
                  a2 -= 16LL;
                  v21 += 16LL;
                  v20 += 4;
                  if ( !v27 )
                  {
                    v11 = v35;
                    if ( v35 < ((16 * v13) | 8) )
                      break;
                    v12 = v32;
                    a2 = v33;
                    ++v13;
                    v14 += v26;
                    v28 = *(unsigned __int8 *)(v33 + 2);
                    *((_QWORD *)v37 + 1) = v19;
                    if ( v13 < v28 )
                      goto LABEL_12;
                    goto LABEL_35;
                  }
                }
              }
            }
          }
          __break(1u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v31 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
          v11 = 16LL * *(unsigned __int8 *)(a2 + 2);
          v12 = _kmalloc_noprof(v11, 3520);
          *(_QWORD *)(StatusReg + 80) = v31;
          if ( !v12 )
            return 4294967284LL;
        }
      }
      return 4294967294LL;
    }
  }
  return result;
}
