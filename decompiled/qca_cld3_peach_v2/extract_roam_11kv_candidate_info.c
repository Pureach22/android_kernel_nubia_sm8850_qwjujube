__int64 __fastcall extract_roam_11kv_candidate_info(
        __int64 result,
        __int64 a2,
        unsigned __int8 a3,
        unsigned __int16 a4)
{
  __int64 v4; // x9
  unsigned int v5; // w8
  __int64 v6; // x10
  unsigned int v7; // w9
  unsigned int v8; // w8
  _DWORD *v9; // x10
  int v10; // w11

  v4 = *(_QWORD *)(result + 192);
  if ( v4 )
  {
    v5 = *(_DWORD *)(result + 200);
    if ( v5 )
    {
      if ( a4 + (unsigned int)a3 <= v5 && a4 )
      {
        v6 = v4 + 16LL * a3;
        v7 = a4;
        v8 = 0;
        if ( (a4 & 0xFFF8) != 0 )
          v7 = 8;
        v9 = (_DWORD *)(v6 + 8);
        do
        {
          ++v8;
          *(_WORD *)a2 = *(v9 - 1);
          *(_BYTE *)(a2 + 2) = *((_WORD *)v9 - 1);
          *(_BYTE *)(a2 + 3) = *((_BYTE *)v9 - 1);
          *(_WORD *)(a2 + 4) = *v9;
          v10 = v9[1];
          v9 += 4;
          *(_BYTE *)(a2 + 12) = v10;
          a2 += 16;
        }
        while ( v8 < v7 );
      }
    }
  }
  return result;
}
