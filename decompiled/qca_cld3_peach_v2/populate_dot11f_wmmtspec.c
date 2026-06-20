__int64 __fastcall populate_dot11f_wmmtspec(__int64 result, __int64 a2)
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

  v2 = *(_DWORD *)(a2 + 2) & 0xFFFFFFFE | *(_WORD *)(result + 3) & 1;
  *(_DWORD *)(a2 + 2) = v2;
  v3 = v2 & 0xFFFFFFE1 | (2 * ((*(unsigned __int16 *)(result + 3) >> 1) & 0xF));
  *(_DWORD *)(a2 + 2) = v3;
  v4 = v3 & 0xFFFFFF9F | (32 * ((*(unsigned __int16 *)(result + 3) >> 5) & 3));
  *(_DWORD *)(a2 + 2) = v4;
  v5 = v4 & 0xFFFFFE7F | (((*(unsigned __int16 *)(result + 3) >> 7) & 3) << 7);
  *(_DWORD *)(a2 + 2) = v5;
  v6 = v5 & 0xFFFFFDFF | (((*(unsigned __int16 *)(result + 3) >> 9) & 1) << 9);
  *(_DWORD *)(a2 + 2) = v6;
  v7 = v6 & 0xFFFFFBFF | (((*(unsigned __int16 *)(result + 3) >> 10) & 1) << 10);
  *(_DWORD *)(a2 + 2) = v7;
  v8 = v7 & 0xFFFFC7FF | (((*(unsigned __int16 *)(result + 3) >> 11) & 7) << 11);
  *(_DWORD *)(a2 + 2) = v8;
  v9 = v8 & 0xFFFF3FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(result + 3)) >> 6 << 14);
  *(_DWORD *)(a2 + 2) = v9;
  v10 = *(_WORD *)(a2 + 6);
  *(_DWORD *)(a2 + 2) = v9 & 0xFF7FFFFF | (((*(unsigned __int8 *)(result + 2) >> 7) & 1) << 23);
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
  *(_WORD *)a2 = 257;
  *(_WORD *)(a2 + 58) = v11;
  return result;
}
