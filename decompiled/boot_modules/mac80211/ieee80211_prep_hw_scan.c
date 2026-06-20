__int64 __fastcall ieee80211_prep_hw_scan(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x19
  int v3; // w11
  __int64 v4; // x6
  __int64 v5; // x8
  __int64 v6; // x10
  unsigned int v7; // w11
  unsigned int i; // w12
  _DWORD *v9; // x13
  __int64 v10; // x14
  __int64 v11; // x11
  int v12; // w8
  unsigned int v13; // w8
  __int64 v14; // x11
  _DWORD *v15; // x13
  unsigned int v16; // w8
  __int64 v17; // x3
  __int64 v18; // x2
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x1
  unsigned int v22; // w0
  __int64 v23; // x9
  __int64 result; // x0
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x8
  _QWORD v28[5]; // [xsp+18h] [xbp-28h] BYREF

  v28[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 1616);
  v2 = *(_QWORD *)(v1 + 4752);
  if ( (*(_QWORD *)(v1 + 4696) & 0x20) != 0 )
  {
LABEL_18:
    result = 0;
    goto LABEL_19;
  }
  if ( (*(_QWORD *)(v1 + 96) & 0x10000000) == 0 )
  {
    v3 = *(_DWORD *)(v1 + 4800);
    v4 = 0;
    v5 = v2 + 160;
    while ( v3 != 6 )
    {
      v6 = *(_QWORD *)(v1 + 4760);
      *(_DWORD *)(v6 + 124) = 0;
      v7 = *(_DWORD *)(v2 + 12);
      if ( v7 )
      {
        for ( i = 0; i < v7; ++i )
        {
          v9 = *(_DWORD **)(v5 + 8LL * (int)i);
          if ( *v9 == *(_DWORD *)(v1 + 4800) )
          {
            v10 = *(unsigned int *)(v6 + 124);
            v11 = *(_QWORD *)(v1 + 4760) + 8 * v10;
            *(_DWORD *)(v6 + 124) = v10 + 1;
            *(_QWORD *)(v11 + 272) = v9;
            v7 = *(_DWORD *)(v2 + 12);
            v4 = (unsigned int)v4 | (unsigned int)(1LL << **(_DWORD **)(v5 + 8LL * (int)i));
          }
        }
      }
      v3 = *(_DWORD *)(v1 + 4800) + 1;
      *(_DWORD *)(v1 + 4800) = v3;
      if ( *(_DWORD *)(v6 + 124) )
        goto LABEL_16;
    }
    goto LABEL_18;
  }
  v12 = *(_DWORD *)(v2 + 12);
  *(_DWORD *)(*(_QWORD *)(v1 + 4760) + 124LL) = v12;
  if ( v12 )
  {
    v13 = 0;
    LODWORD(v4) = 0;
    do
    {
      v14 = 8LL * (int)v13++;
      v15 = *(_DWORD **)(v2 + 160 + v14);
      *(_QWORD *)(*(_QWORD *)(v1 + 4760) + v14 + 272) = v15;
      v4 = (unsigned int)v4 | (unsigned int)(1LL << *v15);
    }
    while ( v13 < *(_DWORD *)(v2 + 12) );
  }
  else
  {
    v4 = 0;
  }
LABEL_16:
  v16 = *(_DWORD *)(v2 + 36);
  v17 = *(_QWORD *)(v1 + 4760);
  v18 = *(int *)(v1 + 4812);
  v19 = *(_QWORD *)(v2 + 16);
  v20 = *(_QWORD *)(v2 + 24);
  v21 = *(_QWORD *)(v17 + 128);
  memset(v28, 0, 32);
  v22 = ieee80211_build_preq_ies(a1, v21, v18, v17, v19, v20, v4, v2 + 40, v28, (v16 >> 11) & 2);
  if ( (v22 & 0x80000000) != 0 )
    goto LABEL_18;
  v23 = v22;
  result = 1;
  *(_QWORD *)(*(_QWORD *)(v1 + 4760) + 136LL) = v23;
  *(_BYTE *)(*(_QWORD *)(v1 + 4760) + 241LL) = *(_BYTE *)(v2 + 129);
  v25 = *(_QWORD *)(v1 + 4760);
  *(_DWORD *)(v25 + 184) = *(_DWORD *)(v2 + 72);
  *(_WORD *)(v25 + 188) = *(_WORD *)(v2 + 76);
  v26 = *(_QWORD *)(v1 + 4760);
  *(_DWORD *)(v26 + 190) = *(_DWORD *)(v2 + 78);
  *(_WORD *)(v26 + 194) = *(_WORD *)(v2 + 82);
  v27 = *(_QWORD *)(v1 + 4760);
  *(_DWORD *)(v27 + 196) = *(_DWORD *)(v2 + 84);
  *(_WORD *)(v27 + 200) = *(_WORD *)(v2 + 88);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
