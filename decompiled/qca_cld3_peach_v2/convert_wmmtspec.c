void __fastcall convert_wmmtspec(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w9
  unsigned int v4; // w9
  unsigned int v5; // w9
  unsigned int v6; // w9
  unsigned int v7; // w9
  unsigned int v8; // w9
  unsigned int v9; // w9

  v3 = *(_WORD *)(a2 + 3) & 0xFFFE | *(_WORD *)(a3 + 2) & 1;
  *(_WORD *)(a2 + 3) = *(_WORD *)(a2 + 3) & 0xFFFE | *(_WORD *)(a3 + 2) & 1;
  v4 = v3 & 0xFFFFFFE1 | (2 * ((*(unsigned __int16 *)(a3 + 2) >> 1) & 0xF));
  *(_WORD *)(a2 + 3) = v4;
  v5 = v4 & 0xFFFFFF9F | (32 * ((*(unsigned __int16 *)(a3 + 2) >> 5) & 3));
  *(_WORD *)(a2 + 3) = v5;
  v6 = v5 & 0xFFFFFE7F | (((*(unsigned __int16 *)(a3 + 2) >> 7) & 3) << 7);
  *(_WORD *)(a2 + 3) = v6;
  v7 = v6 & 0xFFFFFDFF | (((*(unsigned __int16 *)(a3 + 2) >> 9) & 1) << 9);
  *(_WORD *)(a2 + 3) = v7;
  v8 = v7 & 0xFFFFFBFF | (((*(unsigned __int16 *)(a3 + 2) >> 10) & 1) << 10);
  *(_WORD *)(a2 + 3) = v8;
  v9 = v8 & 0xFFFFC7FF | (((*(unsigned __int16 *)(a3 + 2) >> 11) & 7) << 11);
  *(_WORD *)(a2 + 3) = v9;
  *(_WORD *)(a2 + 3) = *(_WORD *)(a3 + 2) & 0xC000 | v9 & 0x3FFF;
  *(_WORD *)(a2 + 6) = *(_WORD *)(a3 + 6);
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
