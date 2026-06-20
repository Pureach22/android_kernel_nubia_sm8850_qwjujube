void __fastcall ipareg_parse_tx_cfg_v4_0(__int64 a1, _DWORD *a2, unsigned int a3)
{
  a2[1] = (a3 >> 2) & 0xF;
  a2[2] = (a3 >> 13) & 0xF;
  a2[3] = (a3 >> 6) & 0xF;
  a2[4] = (a3 >> 10) & 1;
  a2[5] = (a3 >> 11) & 1;
  a2[6] = (a3 >> 12) & 1;
}
