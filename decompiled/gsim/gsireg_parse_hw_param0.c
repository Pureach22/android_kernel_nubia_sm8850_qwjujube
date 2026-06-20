void __fastcall gsireg_parse_hw_param0(__int64 a1, int *a2, unsigned int a3)
{
  *a2 = (a3 >> 26) & 0x1F;
  a2[1] = a3 >> 31;
  a2[2] = (a3 >> 21) & 0x1F;
  a2[3] = HIWORD(a3) & 0x1F;
  a2[4] = BYTE1(a3);
  a2[5] = (unsigned __int8)a3;
}
