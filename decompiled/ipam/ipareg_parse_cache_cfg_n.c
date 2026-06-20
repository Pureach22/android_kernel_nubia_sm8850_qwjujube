void __fastcall ipareg_parse_cache_cfg_n(__int64 a1, __int64 a2, unsigned int a3)
{
  *(_BYTE *)a2 = a3 & 1;
  *(_BYTE *)(a2 + 1) = (a3 & 2) != 0;
  *(_BYTE *)(a2 + 2) = (a3 & 4) != 0;
  *(_BYTE *)(a2 + 3) = (a3 & 8) != 0;
  *(_BYTE *)(a2 + 4) = (a3 & 0x10) != 0;
  *(_BYTE *)(a2 + 5) = (a3 & 0x20) != 0;
  *(_BYTE *)(a2 + 6) = (a3 & 0x40) != 0;
  *(_DWORD *)(a2 + 8) = a3 >> 7;
}
