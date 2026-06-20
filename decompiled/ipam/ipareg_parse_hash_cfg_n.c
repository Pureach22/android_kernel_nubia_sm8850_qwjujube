void __fastcall ipareg_parse_hash_cfg_n(__int64 a1, __int64 a2, unsigned int a3)
{
  *(_BYTE *)a2 = a3 & 1;
  *(_BYTE *)(a2 + 1) = (a3 & 2) != 0;
  *(_BYTE *)(a2 + 2) = (a3 & 4) != 0;
  *(_BYTE *)(a2 + 3) = (a3 & 8) != 0;
  *(_BYTE *)(a2 + 4) = (a3 & 0x10) != 0;
  *(_BYTE *)(a2 + 5) = (a3 & 0x20) != 0;
  *(_BYTE *)(a2 + 6) = (a3 & 0x40) != 0;
  *(_BYTE *)(a2 + 7) = BYTE2(a3) & 1;
  *(_BYTE *)(a2 + 8) = (a3 & 0x20000) != 0;
  *(_BYTE *)(a2 + 9) = (a3 & 0x40000) != 0;
  *(_BYTE *)(a2 + 10) = (a3 & 0x80000) != 0;
  *(_BYTE *)(a2 + 11) = (a3 & 0x100000) != 0;
  *(_BYTE *)(a2 + 12) = (a3 & 0x200000) != 0;
  *(_BYTE *)(a2 + 13) = (a3 & 0x400000) != 0;
  *(_DWORD *)(a2 + 16) = (unsigned __int16)a3 >> 7;
  *(_DWORD *)(a2 + 20) = a3 >> 23;
}
