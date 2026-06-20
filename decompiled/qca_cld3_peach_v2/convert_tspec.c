void __fastcall convert_tspec(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w9
  unsigned int v4; // w9
  unsigned int v5; // w9
  unsigned int v6; // w9
  unsigned int v7; // w9
  unsigned int v8; // w9
  __int16 v9; // w8

  v3 = *(_WORD *)(a2 + 3) & 0xFFFE | *(_WORD *)(a3 + 1) & 1;
  *(_WORD *)(a2 + 3) = *(_WORD *)(a2 + 3) & 0xFFFE | *(_WORD *)(a3 + 1) & 1;
  v4 = v3 & 0xFFFFFFE1 | (2 * ((*(unsigned __int16 *)(a3 + 1) >> 1) & 0xF));
  *(_WORD *)(a2 + 3) = v4;
  v5 = v4 & 0xFFFFFF9F | (32 * ((*(unsigned __int16 *)(a3 + 1) >> 5) & 3));
  *(_WORD *)(a2 + 3) = v5;
  v6 = v5 & 0xFFFFFE7F | ((HIBYTE(*(unsigned __int16 *)(a3 + 1)) & 3) << 7);
  *(_WORD *)(a2 + 3) = v6;
  v7 = v6 & 0xFFFFFDFF | (((*(unsigned __int16 *)(a3 + 1) >> 10) & 1) << 9);
  *(_WORD *)(a2 + 3) = v7;
  v8 = v7 & 0xFFFFFBFF | (((*(unsigned __int16 *)(a3 + 1) >> 11) & 1) << 10);
  *(_WORD *)(a2 + 3) = v8;
  LOWORD(v8) = v8 & 0xC7FF | (((*(_WORD *)(a3 + 1) >> 12) & 7) << 11);
  *(_WORD *)(a2 + 3) = v8;
  v9 = (*(_DWORD *)(a3 + 1) >> 1) & 0xC000 | v8 & 0x3FFF;
  LOBYTE(v8) = *(_BYTE *)(a2 + 5);
  *(_WORD *)(a2 + 3) = v9;
  *(_BYTE *)(a2 + 5) = v8 & 0xFE | ((*(_DWORD *)(a3 + 1) & 0x20000) != 0);
  *(_WORD *)(a2 + 6) = *(_WORD *)(a3 + 6) & 0x7FFF;
  *(_WORD *)(a2 + 8) = *(_WORD *)(a3 + 8);
  *(_DWORD *)(a2 + 10) = *(_DWORD *)(a3 + 12);
  *(_DWORD *)(a2 + 14) = *(_DWORD *)(a3 + 16);
  *(_DWORD *)(a2 + 18) = *(_DWORD *)(a3 + 20);
  *(_DWORD *)(a2 + 22) = *(_DWORD *)(a3 + 24);
  *(_DWORD *)(a2 + 26) = *(_DWORD *)(a3 + 28);
  *(_DWORD *)(a2 + 30) = *(_DWORD *)(a3 + 32);
  *(_DWORD *)(a2 + 34) = *(_DWORD *)(a3 + 36);
  *(_DWORD *)(a2 + 38) = *(_DWORD *)(a3 + 40);
  *(_DWORD *)(a2 + 42) = *(_DWORD *)(a3 + 44);
  *(_DWORD *)(a2 + 46) = *(_DWORD *)(a3 + 48);
  *(_DWORD *)(a2 + 50) = *(_DWORD *)(a3 + 52);
  *(_WORD *)(a2 + 54) = *(_WORD *)(a3 + 56);
  *(_WORD *)(a2 + 56) = *(_WORD *)(a3 + 58);
}
