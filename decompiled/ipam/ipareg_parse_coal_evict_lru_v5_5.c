void __fastcall ipareg_parse_coal_evict_lru_v5_5(__int64 a1, __int64 a2, unsigned int a3)
{
  *(_QWORD *)a2 = 0;
  *(_BYTE *)(a2 + 4) = a3 & 1;
  *(_BYTE *)(a2 + 5) = (a3 >> 1) & 3;
  *(_BYTE *)(a2 + 6) = (unsigned __int8)a3 >> 3;
  *(_BYTE *)(a2 + 7) = BYTE1(a3) & 0x1F;
  *(_DWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 8) = (a3 & 0x2000) != 0;
  *(_BYTE *)(a2 + 9) = (a3 & 0x4000) != 0;
  *(_BYTE *)(a2 + 10) = (a3 & 0xF8000) != 0;
}
