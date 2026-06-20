void __fastcall ipareg_parse_endp_init_prod_cfg_n_v5_5(__int64 a1, _BYTE *a2, unsigned int a3)
{
  *a2 = a3 & 1;
  a2[1] = (a3 & 2) != 0;
  a2[2] = (a3 & 4) != 0;
  a2[4] = BYTE1(a3);
  a2[3] = (a3 >> 3) & 0x1E;
  a2[5] = BYTE2(a3);
  a2[6] = HIBYTE(a3);
}
