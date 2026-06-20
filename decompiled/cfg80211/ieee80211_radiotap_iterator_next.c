__int64 __fastcall ieee80211_radiotap_iterator_next(__int64 *a1)
{
  int v1; // w8
  unsigned int i; // w13
  __int64 v3; // x15
  int v4; // w15
  unsigned int v5; // w16
  int v6; // w2
  unsigned int v7; // w16
  unsigned __int8 *v8; // x1
  __int64 v9; // x17
  int v10; // w4
  unsigned __int64 v11; // x2
  int v12; // w5
  __int64 *v13; // x7
  int v14; // w20
  int v15; // w19
  int v16; // w4
  __int64 v17; // x6
  int v18; // w20
  __int64 v19; // x5
  __int64 v20; // x16
  unsigned int v21; // w16
  __int64 v22; // x4
  unsigned __int8 *v23; // x3
  __int64 v24; // x4
  unsigned __int8 *v25; // x3
  __int64 v26; // x15
  unsigned int *v27; // x15
  _DWORD *v28; // x15
  unsigned int v29; // t1

  v1 = *((_DWORD *)a1 + 18);
  for ( i = *((_DWORD *)a1 + 19); ; *((_DWORD *)a1 + 19) = i )
  {
    while ( 1 )
    {
      if ( (v1 & 0x8000001F) == 0x1F )
      {
        if ( (i & 1) == 0 )
          return 4294967294LL;
      }
      else if ( (i & 1) == 0 )
      {
        goto LABEL_4;
      }
      if ( v1 <= 0 )
        v4 = -(-v1 & 0x1F);
      else
        v4 = v1 & 0x1F;
      v5 = v4 - 29;
      if ( (unsigned int)(v4 - 29) >= 3 )
      {
        v20 = a1[2];
        if ( !v20 )
          goto LABEL_3;
        if ( v1 >= *(_DWORD *)(v20 + 8) )
        {
          if ( (_UNKNOWN **)v20 == &radiotap_ns )
            return 4294967294LL;
LABEL_3:
          v3 = a1[4];
          a1[2] = 0;
          a1[3] = v3;
          goto LABEL_4;
        }
        v21 = *(unsigned __int8 *)(*(_QWORD *)v20 + v1);
        v6 = v21 & 0xF;
        if ( (v21 & 0xF) == 0 )
          goto LABEL_3;
        v7 = v21 >> 4;
      }
      else
      {
        v6 = dword_BE030[v5];
        v7 = dword_BE03C[v5];
      }
      v8 = (unsigned __int8 *)a1[3];
      v9 = *a1;
      v10 = (v6 - 1) & ((_DWORD)v8 - *a1);
      if ( v10 )
      {
        v8 += v6 - v10;
        a1[3] = (__int64)v8;
      }
      v11 = *((int *)a1 + 17);
      if ( (v1 & 0x8000001F) == 0x1E )
      {
        if ( (unsigned __int64)&v8[v7 - v9] > v11 )
          return 4294967274LL;
        v12 = *v8;
        v13 = (__int64 *)a1[1];
        v14 = v8[1];
        v15 = v8[2];
        v16 = v8[3];
        a1[2] = 0;
        if ( v13 && (v17 = *((unsigned int *)v13 + 2), (int)v17 >= 1) )
        {
          v18 = (v12 << 16) | (v14 << 8);
          v19 = *v13;
          do
          {
            if ( *(_DWORD *)(v19 + 12) == (v18 | v15) && *(unsigned __int8 *)(v19 + 16) == v16 )
            {
              a1[2] = v19;
              goto LABEL_31;
            }
            --v17;
            v19 += 24;
          }
          while ( v17 );
          v19 = 0;
LABEL_31:
          v24 = *((unsigned __int16 *)v8 + 2);
          v23 = &v8[v7 + v24];
          if ( v19 )
            LODWORD(v24) = 0;
          v7 += v24;
        }
        else
        {
          v22 = *((unsigned __int16 *)v8 + 2);
          v23 = &v8[v7 + v22];
          v7 += v22;
        }
        a1[4] = (__int64)v23;
      }
      v25 = &v8[v7];
      a1[6] = (__int64)v8;
      *((_DWORD *)a1 + 14) = v1;
      *((_DWORD *)a1 + 15) = v7;
      a1[3] = (__int64)v25;
      if ( (unsigned __int64)&v25[-v9] > v11 )
        return 4294967274LL;
      if ( v4 == 29 )
      {
        *((_DWORD *)a1 + 20) = 1;
        a1[2] = (__int64)&radiotap_ns;
        *((_DWORD *)a1 + 16) = 1;
        goto LABEL_4;
      }
      if ( v4 != 31 )
        break;
      v27 = (unsigned int *)a1[5];
      v29 = *v27;
      v28 = v27 + 1;
      i = v29;
      if ( *((_DWORD *)a1 + 20) )
        v1 = 0;
      else
        ++v1;
      a1[5] = (__int64)v28;
      *((_DWORD *)a1 + 18) = v1;
      *((_DWORD *)a1 + 19) = i;
      *((_DWORD *)a1 + 20) = 0;
    }
    if ( v4 != 30 )
      break;
    v26 = a1[2];
    *((_DWORD *)a1 + 20) = 1;
    *((_DWORD *)a1 + 16) = 0;
    *((_DWORD *)a1 + 14) = 30;
    if ( !v26 )
      break;
LABEL_4:
    i >>= 1;
    *((_DWORD *)a1 + 18) = ++v1;
  }
  *((_DWORD *)a1 + 18) = v1 + 1;
  *((_DWORD *)a1 + 19) = i >> 1;
  return 0;
}
