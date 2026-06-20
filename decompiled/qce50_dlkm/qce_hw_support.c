__int64 __fastcall qce_hw_support(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v4; // w9
  unsigned int v5; // w10
  bool v6; // zf
  char v8; // w9
  int v9; // w8

  if ( !a2 )
    return 4294967274LL;
  *(_DWORD *)a2 = 0x1000000;
  result = 0;
  *(_WORD *)(a2 + 4) = 1;
  *(_BYTE *)(a2 + 6) = 1;
  v4 = *(_DWORD *)(a1 + 144);
  *(_BYTE *)(a2 + 10) = 1;
  *(_BYTE *)(a2 + 8) = (~v4 & 0x18C) == 0;
  *(_BYTE *)(a2 + 11) = *(_DWORD *)(a1 + 60) == 1;
  LOBYTE(v4) = *(_BYTE *)(a1 + 69);
  *(_BYTE *)(a2 + 7) = 1;
  *(_BYTE *)(a2 + 12) = v4;
  *(_BYTE *)(a2 + 19) = *(_BYTE *)(a1 + 70);
  *(_BYTE *)(a2 + 20) = *(_BYTE *)(a1 + 72);
  v5 = *(_DWORD *)(a1 + 408);
  if ( *(_DWORD *)(a1 + 404) )
    v6 = v5 == 5;
  else
    v6 = 0;
  v8 = !v6 && v5 < 6;
  *(_BYTE *)(a2 + 9) = v8;
  *(_BYTE *)(a2 + 13) = *(_BYTE *)(a1 + 136);
  *(_BYTE *)(a2 + 14) = *(_BYTE *)(a1 + 137);
  *(_BYTE *)(a2 + 15) = *(_BYTE *)(a1 + 138);
  *(_BYTE *)(a2 + 16) = *(_BYTE *)(a1 + 139);
  *(_BYTE *)(a2 + 17) = *(_BYTE *)(a1 + 140);
  *(_BYTE *)(a2 + 18) = *(_BYTE *)(a1 + 141);
  *(_DWORD *)(a2 + 24) = *(_DWORD *)(a1 + 304);
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(a1 + 308);
  if ( *(_BYTE *)(a1 + 128) )
    v9 = 8;
  else
    v9 = 1;
  *(_DWORD *)(a2 + 32) = v9;
  return result;
}
