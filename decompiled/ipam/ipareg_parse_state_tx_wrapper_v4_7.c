void __fastcall ipareg_parse_state_tx_wrapper_v4_7(__int64 a1, _BYTE *a2, unsigned int a3)
{
  *a2 = a3 & 1;
  a2[1] = (a3 & 2) != 0;
  a2[2] = (a3 & 4) != 0;
  a2[3] = (a3 & 8) != 0;
  a2[4] = (a3 & 0x10) != 0;
  a2[12] = (a3 & 0x40000) != 0;
  a2[13] = (a3 & 0x80000) != 0;
  a2[14] = a3 >> 28;
}
