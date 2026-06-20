__int64 __fastcall adreno_profile_preib_processing(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x8
  int *v4; // x21
  unsigned int v5; // w24
  _QWORD *v6; // x19
  __int64 v7; // x23
  unsigned int v8; // w8
  unsigned int v9; // w10
  int v10; // w9
  __int64 v14; // x27
  __int64 v15; // x14
  __int64 v16; // x10
  int v17; // w11
  __int64 v18; // x9
  __int64 v19; // x11
  __int64 v20; // x10
  int v21; // w15
  int v22; // w16
  int v23; // w16
  unsigned __int64 v24; // x15
  __int64 v25; // x12
  int v26; // w16
  unsigned __int64 v28; // x17
  unsigned __int64 v29; // x15
  unsigned __int64 v30; // x16
  unsigned __int64 v31; // x15
  unsigned __int64 v32; // x16
  int v33; // w13
  __int64 v34; // x15
  _QWORD *v35; // x17
  unsigned int v36; // w14
  int v37; // w1
  int v38; // w1
  __int64 v39; // x1
  int v40; // w2

  v3 = 0;
  if ( a2 && (*(_BYTE *)(a1 + 24024) & 1) == 0 )
  {
    v4 = (int *)(a1 + 19696);
    if ( *(_BYTE *)(a1 + 19728) != 1 )
      return 0;
    v5 = *(_DWORD *)(a1 + 19744);
    v6 = (_QWORD *)(a1 + 19680);
    v7 = *(_QWORD *)(a1 + 19640);
    if ( *(_QWORD *)(a1 + 19680) == a1 + 19680 )
      return 0;
    v8 = *(_DWORD *)(a1 + 19748);
    v9 = v8 - v5;
    v10 = 25 * *v4 + 38;
    if ( v8 <= v5 )
      v9 += *(_DWORD *)(a1 + 19752);
    if ( v10 >= v9 )
      return 0;
    if ( v10 + v5 < *(_DWORD *)(a1 + 19752) )
      goto LABEL_12;
    *(_DWORD *)(a1 + 19752) = v5;
    if ( !v8 )
      v8 = v5;
    v5 = 0;
    *(_DWORD *)(a1 + 19744) = 0;
    if ( v10 >= v8 )
    {
      return 0;
    }
    else
    {
LABEL_12:
      v14 = v10;
      memset((void *)(*(_QWORD *)(*(_QWORD *)(a1 + 19736) + 8LL) + 4LL * v5), 0, 4LL * v10);
      v15 = 4 * v5;
      v16 = *(_QWORD *)(a1 + 19736);
      v17 = 5 * *v4;
      v4[12] = ((unsigned __int64)(unsigned int)v4[12] + v14) % (unsigned int)v4[14];
      v18 = v5 + v17 + 6;
      v19 = *(_QWORD *)(v16 + 24);
      v20 = *(_QWORD *)(v16 + 8) + 4LL * (unsigned int)v18;
      v21 = *(_DWORD *)(v7 + 36) + 1;
      *(_DWORD *)(v20 + 8) = 1883078659;
      *(_DWORD *)(v20 + 12) = v19 + v15;
      *(_QWORD *)v20 = 0x2DEFADE170100001LL;
      *(_DWORD *)(v20 + 16) = (unsigned __int64)(v19 + v15) >> 32;
      *(_DWORD *)(v20 + 20) = v21;
      v22 = *v4;
      *(_DWORD *)(v20 + 24) = 1883078659;
      *(_QWORD *)(v20 + 28) = v19 + (unsigned int)(v15 + 4);
      *(_DWORD *)(v20 + 36) = v22;
      v23 = *(_DWORD *)(a2 + 4);
      *(_DWORD *)(v20 + 40) = 1883078659;
      *(_QWORD *)(v20 + 44) = v19 + (unsigned int)(v15 + 8);
      *(_DWORD *)(v20 + 52) = v23;
      v24 = v19 + (unsigned int)(v15 + 12);
      v25 = *(_QWORD *)(*(_QWORD *)(a2 + 24) + 8LL);
      if ( v25 )
        v26 = *(_DWORD *)(v25 + 112);
      else
        v26 = 0;
      v28 = HIDWORD(v24);
      *(_DWORD *)(v20 + 56) = 1883078659;
      *(_DWORD *)(v20 + 60) = v24;
      v29 = v19 + (unsigned int)(v15 + 16);
      *(_DWORD *)(v20 + 64) = v28;
      *(_DWORD *)(v20 + 68) = v26;
      v30 = HIDWORD(v29);
      LODWORD(v28) = *(_DWORD *)(a2 + 12);
      *(_DWORD *)(v20 + 72) = 1883078659;
      *(_DWORD *)(v20 + 76) = v29;
      v31 = v19 + (unsigned int)(v15 + 20);
      *(_DWORD *)(v20 + 80) = v30;
      *(_DWORD *)(v20 + 84) = v28;
      v32 = HIDWORD(v31);
      v33 = *(_DWORD *)(a2 + 400);
      *(_DWORD *)(v20 + 88) = 1883078659;
      *(_DWORD *)(v20 + 92) = v31;
      v34 = v20 + 104;
      *(_DWORD *)(v20 + 96) = v32;
      *(_DWORD *)(v20 + 100) = v33;
      v35 = (_QWORD *)*v6;
      if ( (_QWORD *)*v6 != v6 )
      {
        v36 = v15 + 32;
        do
        {
          v37 = *((_DWORD *)v35 + 13);
          *(_DWORD *)v34 = 1883078659;
          *(_QWORD *)(v34 + 4) = v19 + v36 - 8;
          *(_DWORD *)(v34 + 12) = v37;
          v38 = *((_DWORD *)v35 + 13);
          *(_QWORD *)(v34 + 24) = v19 + v36 - 4;
          *(_DWORD *)(v34 + 16) = 1883144195;
          *(_DWORD *)(v34 + 20) = v38;
          v39 = v19 + v36;
          v36 += 20;
          v40 = *((_DWORD *)v35 + 14);
          *(_DWORD *)(v34 + 32) = 1883144195;
          *(_DWORD *)(v34 + 36) = v40;
          *(_QWORD *)(v34 + 40) = v39;
          v34 += 48;
          v35 = (_QWORD *)*v35;
        }
        while ( v35 != v6 );
      }
      *(_DWORD *)v34 = 1880096769;
      *(_DWORD *)(v34 + 4) = 770682338;
      *a3 = (unsigned __int64)(v34 - v20 + 8) >> 2;
      return *(_QWORD *)(*(_QWORD *)(a1 + 19736) + 24LL) + 4 * v18;
    }
  }
  return v3;
}
