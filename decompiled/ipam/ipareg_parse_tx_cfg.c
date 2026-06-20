void __fastcall ipareg_parse_tx_cfg(__int64 a1, __int64 a2, unsigned int a3)
{
  int v3; // w10

  v3 = (a3 >> 2) & 7;
  *(_BYTE *)a2 = a3 & 1;
  *(_BYTE *)(a2 + 1) = (a3 & 2) != 0;
  *(_DWORD *)(a2 + 4) = v3;
  *(_DWORD *)(a2 + 8) = v3;
}
