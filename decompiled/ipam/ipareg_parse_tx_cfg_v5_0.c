void __fastcall ipareg_parse_tx_cfg_v5_0(__int64 a1, __int64 a2, unsigned int a3)
{
  *(_DWORD *)(a2 + 4) = (a3 >> 2) & 0xF;
  *(_DWORD *)(a2 + 8) = (a3 >> 13) & 0xF;
  *(_DWORD *)(a2 + 12) = (a3 >> 6) & 0xF;
  *(_DWORD *)(a2 + 16) = (a3 >> 10) & 1;
  *(_DWORD *)(a2 + 20) = (a3 >> 11) & 1;
  *(_DWORD *)(a2 + 24) = (a3 >> 12) & 1;
  *(_BYTE *)(a2 + 28) = (a3 & 0x20000) != 0;
  *(_BYTE *)(a2 + 29) = (a3 & 0x40000) != 0;
  *(_BYTE *)(a2 + 30) = (a3 & 0x100000) != 0;
}
