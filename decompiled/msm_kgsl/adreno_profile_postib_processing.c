__int64 __fastcall adreno_profile_postib_processing(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x8
  int v4; // w16
  int v5; // w17
  __int64 *v6; // x8
  __int64 v7; // x12
  __int64 v8; // x14
  __int64 v9; // x9
  _QWORD *v10; // x11
  _QWORD *v11; // x10
  __int64 *v12; // x15
  unsigned int v13; // w17
  int v14; // w3
  __int64 v15; // x1
  int v16; // w3

  v3 = 0;
  if ( !a2 || (*(_BYTE *)(a1 + 24024) & 1) != 0 )
    return v3;
  if ( *(_BYTE *)(a1 + 19728) == 1 )
  {
    v4 = *(_DWORD *)(a1 + 19696);
    v5 = *(_DWORD *)(a1 + 19744);
    v6 = (__int64 *)(a1 + 19680);
    if ( *(_QWORD *)(a1 + 19680) != a1 + 19680 )
    {
      v7 = *(_QWORD *)(a1 + 19736);
      v8 = *(_QWORD *)(v7 + 24);
      v9 = (unsigned int)(v5 - 25 * v4 - 38 + 17 * v4 + 34);
      v10 = (_QWORD *)(*(_QWORD *)(v7 + 8) + 4LL * (unsigned int)v9);
      *v10 = 0x2DEFADE170100001LL;
      v11 = v10 + 1;
      v12 = *(__int64 **)(a1 + 19680);
      if ( v12 != v6 )
      {
        v13 = 4 * v5 - 100 * v4 - 116;
        do
        {
          v14 = *((_DWORD *)v12 + 13);
          *(_DWORD *)v11 = 1883144195;
          *((_DWORD *)v11 + 1) = v14;
          v11[1] = v8 + v13;
          v15 = v13 + 4;
          v13 += 20;
          v16 = *((_DWORD *)v12 + 14);
          *((_DWORD *)v11 + 4) = 1883144195;
          *((_DWORD *)v11 + 5) = v16;
          v11[3] = v8 + v15;
          v11 += 4;
          v12 = (__int64 *)*v12;
        }
        while ( v12 != v6 );
      }
      *(_DWORD *)v11 = 1880096769;
      *((_DWORD *)v11 + 1) = 770682338;
      *a3 = (unsigned __int64)((char *)v11 - (char *)v10 + 8) >> 2;
      return *(_QWORD *)(*(_QWORD *)(a1 + 19736) + 24LL) + 4 * v9;
    }
  }
  return 0;
}
