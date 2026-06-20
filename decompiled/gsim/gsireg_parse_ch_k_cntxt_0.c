void __fastcall gsireg_parse_ch_k_cntxt_0(__int64 a1, unsigned int *a2, unsigned int a3)
{
  *a2 = HIBYTE(a3);
  a2[1] = (a3 >> 20) & 0xF;
  a2[2] = (a3 >> 14) & 0x1F;
  a2[4] = (a3 >> 8) & 0x1F;
  a2[5] = (unsigned __int8)a3 >> 4;
  a2[6] = (a3 >> 3) & 1;
  a2[7] = a3 & 7;
}
