void __fastcall gsireg_parse_ev_ch_k_cntxt_0_v3_0(__int64 a1, unsigned int *a2, unsigned int a3)
{
  *a2 = HIBYTE(a3);
  a2[1] = (a3 >> 20) & 0xF;
  a2[2] = (a3 >> 7) & 1;
  a2[3] = BYTE1(a3);
  a2[4] = HIWORD(a3) & 0xF;
  a2[5] = a3 & 0x7F;
}
