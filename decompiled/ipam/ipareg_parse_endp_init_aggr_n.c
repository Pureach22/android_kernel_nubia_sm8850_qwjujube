void __fastcall ipareg_parse_endp_init_aggr_n(__int64 a1, _DWORD *a2, unsigned int a3)
{
  a2[6] = 0;
  *((_BYTE *)a2 + 24) = (a3 & 0x200000) != 0;
  *a2 = (a3 & 3) == 1;
  a2[1] = (a3 >> 2) & 7;
  a2[2] = (a3 >> 5) & 0x1F;
  a2[3] = 1000 * ((a3 >> 10) & 0x1F);
  a2[4] = (a3 >> 15) & 0x3F;
  a2[5] = HIBYTE(a3) & 1;
}
