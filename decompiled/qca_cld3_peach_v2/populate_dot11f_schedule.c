__int64 __fastcall populate_dot11f_schedule(__int64 result, __int64 a2)
{
  char v2; // w10
  char v3; // w10
  char v4; // w9
  __int16 v5; // w10
  __int16 v6; // w9

  v2 = *(_BYTE *)(a2 + 1) & 0xFE | *(_BYTE *)(result + 2) & 1;
  *(_BYTE *)(a2 + 1) = v2;
  v3 = v2 & 0xE1 | (2 * ((*(_BYTE *)(result + 2) >> 1) & 0xF));
  *(_BYTE *)(a2 + 1) = v3;
  v4 = v3 & 0x9F | *(_BYTE *)(result + 2) & 0x60;
  v5 = *(_WORD *)(a2 + 2);
  *(_BYTE *)(a2 + 1) = v4;
  *(_WORD *)(a2 + 2) = v5 & 0xFE00 | (*(_WORD *)(result + 2) >> 7);
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(result + 4);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(result + 8);
  *(_WORD *)(a2 + 12) = *(_WORD *)(result + 12);
  v6 = *(_WORD *)(result + 14);
  *(_BYTE *)a2 = 1;
  *(_WORD *)(a2 + 14) = v6;
  return result;
}
