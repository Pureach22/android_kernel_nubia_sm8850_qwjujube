__int64 __fastcall ieee80211_assign_perm_addr(__int64 result, __int64 a2, int a3)
{
  __int64 v3; // x8
  __int16 v4; // w9
  __int64 v5; // x8
  int v6; // w10
  int v7; // w9
  int v8; // w11
  __int64 v9; // x8
  __int16 v10; // w10
  int v11; // w8
  __int64 v12; // x13
  __int64 v13; // x14
  __int64 v14; // x3
  __int64 v15; // x8
  __int16 v16; // w9
  __int64 v17; // x22
  unsigned __int64 v19; // x19
  unsigned __int64 v20; // x20
  __int64 v21; // x1
  __int64 v22; // x2
  __int64 v23; // x3
  __int64 v24; // x8
  unsigned __int8 *v25; // x10
  __int64 v26; // x11
  unsigned __int64 v27; // x10
  unsigned __int64 v28; // x12
  unsigned __int64 v29; // x15
  unsigned int v30; // w16
  unsigned int v31; // w17
  int v32; // w16
  __int64 v33; // x17
  __int64 *i; // x12
  int v35; // w8

  v3 = *(_QWORD *)(result + 72);
  v4 = *(_WORD *)(v3 + 52);
  LODWORD(v3) = *(_DWORD *)(v3 + 48);
  *(_WORD *)(a2 + 4) = v4;
  *(_DWORD *)a2 = v3;
  v5 = *(_QWORD *)(result + 72);
  v6 = *(_DWORD *)(v5 + 54);
  v7 = *(unsigned __int16 *)(v5 + 58);
  v8 = v6 | v7;
  if ( !(v6 | v7) && *(unsigned __int16 *)(v5 + 94) < 2u )
    return result;
  if ( (unsigned int)(a3 - 8) < 2 )
  {
    if ( (*(_QWORD *)(result + 96) & 0x800000) != 0 )
    {
      for ( i = *(__int64 **)(result + 4616); i != (__int64 *)(result + 4616); i = (__int64 *)*i )
      {
        if ( *((_DWORD *)i + 1180) == 10 && (i[204] & 1) != 0 )
        {
          v35 = *(_DWORD *)((char *)i + 5842);
          *(_WORD *)(a2 + 4) = *((_WORD *)i + 2923);
          *(_DWORD *)a2 = v35;
          return result;
        }
      }
    }
  }
  else
  {
    if ( a3 == 6 )
      return result;
    if ( a3 == 4 )
    {
      v9 = result + 4616;
      while ( 1 )
      {
        v9 = *(_QWORD *)v9;
        if ( v9 == result + 4616 )
          break;
        if ( *(_DWORD *)(v9 + 4720) == 3 )
        {
          v10 = *(_WORD *)(v9 + 5846);
          v11 = *(_DWORD *)(v9 + 5842);
          *(_WORD *)(a2 + 4) = v10;
          *(_DWORD *)a2 = v11;
          return result;
        }
      }
      return result;
    }
  }
  if ( *(_WORD *)(v5 + 94) )
  {
    v12 = *(_QWORD *)(v5 + 64);
    v13 = 0;
    while ( 2 )
    {
      v14 = result + 4616;
      do
      {
        v14 = *(_QWORD *)v14;
        if ( v14 == result + 4616 )
        {
          v15 = v12 + 6LL * (unsigned int)v13;
          v16 = *(_WORD *)(v15 + 4);
          LODWORD(v15) = *(_DWORD *)v15;
          *(_WORD *)(a2 + 4) = v16;
          *(_DWORD *)a2 = v15;
          v5 = *(_QWORD *)(result + 72);
          v6 = *(_DWORD *)(v5 + 54);
          v7 = *(unsigned __int16 *)(v5 + 58);
          v8 = v6 | v7;
          goto LABEL_19;
        }
      }
      while ( *(_DWORD *)(v14 + 5842) ^ *(_DWORD *)(v12 + 6 * v13)
            | *(unsigned __int16 *)(v14 + 5846) ^ *(unsigned __int16 *)(v12 + 6 * v13 + 4) );
      if ( ++v13 != *(unsigned __int16 *)(v5 + 94) )
        continue;
      break;
    }
  }
LABEL_19:
  if ( v8 )
  {
    v17 = result;
    v19 = ((unsigned __int64)(unsigned __int8)v6 << 40)
        | ((unsigned __int64)*(unsigned __int8 *)(v5 + 55) << 32)
        | ((unsigned __int64)*(unsigned __int8 *)(v5 + 56) << 24)
        | ((unsigned __int64)*(unsigned __int8 *)(v5 + 57) << 16)
        | ((unsigned __int64)(unsigned __int8)v7 << 8)
        | *(unsigned __int8 *)(v5 + 59);
    v20 = __clz(__rbit64(v19));
    if ( _sw_hweight64(v19) + v20 == 64 - __clz(v19) )
    {
      v24 = v17 + 4616;
      v25 = (unsigned __int8 *)(*(_QWORD *)(v17 + 72) + 48LL);
      v26 = v17 + 4616;
      while ( 1 )
      {
        v26 = *(_QWORD *)v26;
        if ( v26 == v24 )
          break;
        if ( *(_DWORD *)(v26 + 4720) != 6 )
        {
          v25 = (unsigned __int8 *)(v26 + 5842);
          break;
        }
      }
      v27 = ((unsigned __int64)*v25 << 40)
          | ((unsigned __int64)v25[1] << 32)
          | ((unsigned __int64)v25[2] << 24)
          | ((unsigned __int64)v25[3] << 16)
          | ((unsigned __int64)v25[4] << 8)
          | v25[5];
      v28 = v27 & v19;
      v29 = v27;
      while ( 2 )
      {
        v30 = (unsigned int)v29 >> 8;
        v31 = WORD1(v29);
        result = v29 >> 24;
        v28 += 1LL << v20;
        LODWORD(v29) = bswap32(v29) >> 16;
        v32 = v30 & 0xFF0000 | ((unsigned __int8)v31 << 24) | result & 0xFF00 | BYTE5(v29);
        v33 = v17 + 4616;
        do
        {
          v33 = *(_QWORD *)v33;
          if ( v33 == v24 )
          {
            *(_DWORD *)a2 = v32;
            *(_WORD *)(a2 + 4) = v29;
            return result;
          }
          result = *(_DWORD *)(v33 + 5842) ^ v32 | *(unsigned __int16 *)(v33 + 5846) ^ (unsigned int)v29;
        }
        while ( (_DWORD)result );
        v29 = v28 & v19 | v27 & ~v19;
        if ( v29 != v27 )
          continue;
        break;
      }
    }
    else
    {
      return printk(&unk_BC342, v21, v22, v23);
    }
  }
  return result;
}
