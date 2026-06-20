void __fastcall convert_wmm_schedule(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w9
  unsigned int v4; // w9
  unsigned int v5; // w9

  v3 = *(unsigned __int16 *)(a2 + 2);
  *(_WORD *)a2 = 5341;
  v4 = v3 & 0xFFFFFFFE | *(_WORD *)(a3 + 2) & 1;
  *(_WORD *)(a2 + 2) = v4;
  v5 = v4 & 0xFFFFFFE1 | (2 * ((*(unsigned __int16 *)(a3 + 2) >> 1) & 0xF));
  *(_WORD *)(a2 + 2) = v5;
  *(_WORD *)(a2 + 2) = v5 & 0xFF9F | *(_WORD *)(a3 + 2) & 0x60;
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(a3 + 4);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(a3 + 8);
  *(_WORD *)(a2 + 14) = *(_WORD *)(a3 + 14);
}
