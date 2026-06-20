__int64 __fastcall ese_populate_wmm_tspec(__int64 result, __int64 a2)
{
  int v2; // w9
  unsigned int v3; // w9
  unsigned int v4; // w9
  unsigned int v5; // w9
  unsigned int v6; // w9
  unsigned int v7; // w9
  __int16 v8; // w8
  __int16 v9; // w8

  v2 = *(_WORD *)a2 & 0xFFFE | *(_WORD *)(result + 3) & 1;
  *(_WORD *)a2 = *(_WORD *)a2 & 0xFFFE | *(_WORD *)(result + 3) & 1;
  v3 = v2 & 0xFFFFFFE1 | (2 * ((*(unsigned __int16 *)(result + 3) >> 1) & 0xF));
  *(_WORD *)a2 = v3;
  v4 = v3 & 0xFFFFFF9F | (32 * ((*(unsigned __int16 *)(result + 3) >> 5) & 3));
  *(_WORD *)a2 = v4;
  v5 = v4 & 0xFFFFFE7F | (((*(unsigned __int16 *)(result + 3) >> 7) & 3) << 7);
  *(_WORD *)a2 = v5;
  v6 = v5 & 0xFFFFFDFF | (((*(unsigned __int16 *)(result + 3) >> 9) & 1) << 9);
  *(_WORD *)a2 = v6;
  v7 = v6 & 0xFFFFFBFF | (((*(unsigned __int16 *)(result + 3) >> 10) & 1) << 10);
  *(_WORD *)a2 = v7;
  LOWORD(v7) = v7 & 0xC7FF | (((*(_WORD *)(result + 3) >> 11) & 7) << 11);
  *(_WORD *)a2 = v7;
  v8 = *(_WORD *)(result + 3) & 0xC000 | v7 & 0x3FFF;
  LOBYTE(v7) = *(_BYTE *)(a2 + 2);
  *(_WORD *)a2 = v8;
  LOBYTE(v8) = *(_BYTE *)(result + 2) & 0x80 | v7 & 0x7F;
  LOWORD(v7) = *(_WORD *)(a2 + 3);
  *(_BYTE *)(a2 + 2) = v8;
  v9 = *(_WORD *)(result + 6);
  *(_WORD *)(a2 + 3) = v7 & 0x8000 | v9 & 0x7FFF;
  *(_WORD *)(a2 + 3) = *(_WORD *)(result + 6) & 0x8000 | v9 & 0x7FFF;
  *(_WORD *)(a2 + 5) = *(_WORD *)(result + 8);
  *(_DWORD *)(a2 + 7) = *(_DWORD *)(result + 10);
  *(_DWORD *)(a2 + 11) = *(_DWORD *)(result + 14);
  *(_DWORD *)(a2 + 15) = *(_DWORD *)(result + 18);
  *(_DWORD *)(a2 + 19) = *(_DWORD *)(result + 22);
  *(_DWORD *)(a2 + 23) = *(_DWORD *)(result + 26);
  *(_DWORD *)(a2 + 27) = *(_DWORD *)(result + 30);
  *(_DWORD *)(a2 + 31) = *(_DWORD *)(result + 34);
  *(_DWORD *)(a2 + 35) = *(_DWORD *)(result + 38);
  *(_DWORD *)(a2 + 39) = *(_DWORD *)(result + 42);
  *(_DWORD *)(a2 + 43) = *(_DWORD *)(result + 46);
  *(_DWORD *)(a2 + 47) = *(_DWORD *)(result + 50);
  *(_WORD *)(a2 + 51) = *(_WORD *)(result + 54);
  *(_WORD *)(a2 + 53) = *(_WORD *)(result + 56);
  return result;
}
