__int64 __fastcall populate_dot11f_tspec(__int64 result, __int64 a2)
{
  unsigned int v2; // w10
  unsigned int v3; // w10
  unsigned int v4; // w10
  unsigned int v5; // w10
  unsigned int v6; // w10
  unsigned int v7; // w10
  unsigned int v8; // w10
  unsigned int v9; // w10
  __int16 v10; // w9
  __int16 v11; // w9

  v2 = *(_DWORD *)(a2 + 1) & 0xFFFFFFFE | *(_WORD *)(result + 3) & 1;
  *(_DWORD *)(a2 + 1) = v2;
  v3 = v2 & 0xFFFFFFE1 | (2 * ((*(unsigned __int16 *)(result + 3) >> 1) & 0xF));
  *(_DWORD *)(a2 + 1) = v3;
  v4 = v3 & 0xFFFFFF9F | (32 * ((*(unsigned __int16 *)(result + 3) >> 5) & 3));
  *(_DWORD *)(a2 + 1) = v4;
  v5 = v4 & 0xFFFFFCFF | (((*(unsigned __int16 *)(result + 3) >> 7) & 3) << 8);
  *(_DWORD *)(a2 + 1) = v5;
  v6 = v5 & 0xFFFFFBFF | (((*(unsigned __int16 *)(result + 3) >> 9) & 1) << 10);
  *(_DWORD *)(a2 + 1) = v6;
  v7 = v6 & 0xFFFFF7FF | (((*(unsigned __int16 *)(result + 3) >> 10) & 1) << 11);
  *(_DWORD *)(a2 + 1) = v7;
  v8 = v7 & 0xFFFF8FFF | (((*(unsigned __int16 *)(result + 3) >> 11) & 7) << 12);
  *(_DWORD *)(a2 + 1) = v8;
  v9 = v8 & 0xFFFE7FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(result + 3)) >> 6 << 15);
  *(_DWORD *)(a2 + 1) = v9;
  v10 = *(_WORD *)(a2 + 6);
  *(_DWORD *)(a2 + 1) = v9 & 0xFFFDFFFF | ((*(_BYTE *)(result + 5) & 1) << 17);
  LOWORD(v9) = *(_WORD *)(result + 6);
  *(_WORD *)(a2 + 6) = v10 & 0x8000 | v9 & 0x7FFF;
  *(_WORD *)(a2 + 6) = *(_WORD *)(result + 6) & 0x8000 | v9 & 0x7FFF;
  *(_WORD *)(a2 + 8) = *(_WORD *)(result + 8);
  *(_DWORD *)(a2 + 12) = *(_DWORD *)(result + 10);
  *(_DWORD *)(a2 + 16) = *(_DWORD *)(result + 14);
  *(_DWORD *)(a2 + 20) = *(_DWORD *)(result + 18);
  *(_DWORD *)(a2 + 24) = *(_DWORD *)(result + 22);
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(result + 26);
  *(_DWORD *)(a2 + 32) = *(_DWORD *)(result + 30);
  *(_DWORD *)(a2 + 36) = *(_DWORD *)(result + 34);
  *(_DWORD *)(a2 + 40) = *(_DWORD *)(result + 38);
  *(_DWORD *)(a2 + 44) = *(_DWORD *)(result + 42);
  *(_DWORD *)(a2 + 48) = *(_DWORD *)(result + 46);
  *(_DWORD *)(a2 + 52) = *(_DWORD *)(result + 50);
  *(_WORD *)(a2 + 56) = *(_WORD *)(result + 54);
  v11 = *(_WORD *)(result + 56);
  *(_BYTE *)a2 = 1;
  *(_WORD *)(a2 + 58) = v11;
  return result;
}
