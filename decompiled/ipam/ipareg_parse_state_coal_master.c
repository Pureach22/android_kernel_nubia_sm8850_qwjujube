void __fastcall ipareg_parse_state_coal_master(__int64 a1, unsigned int *a2, unsigned int a3)
{
  *a2 = a3 >> 28;
  a2[1] = HIBYTE(a3) & 0xF;
  a2[2] = (a3 >> 20) & 0xF;
  a2[3] = HIWORD(a3) & 0xF;
  a2[4] = (unsigned __int16)a3 >> 12;
  a2[5] = (a3 >> 8) & 0xF;
  a2[6] = (unsigned __int8)a3 >> 4;
  a2[7] = a3 & 0xF0;
}
