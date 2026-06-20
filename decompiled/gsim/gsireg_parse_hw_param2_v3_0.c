void __fastcall gsireg_parse_hw_param2_v3_0(__int64 a1, unsigned int *a2, unsigned int a3)
{
  a2[6] = (a3 >> 14) & 1;
  a2[7] = (a3 >> 13) & 1;
  a2[9] = (unsigned __int8)a3;
  a2[10] = (a3 >> 8) & 0x1F;
  a2[2] = (a3 >> 27) & 7;
  a2[3] = (unsigned __int8)(a3 >> 19);
  a2[4] = HIWORD(a3) & 7;
  a2[5] = (a3 >> 15) & 1;
  *a2 = a3 >> 31;
  a2[1] = (a3 >> 30) & 1;
}
