void __fastcall gsireg_parse_hw_param2(__int64 a1, _DWORD *a2, unsigned int a3)
{
  a2[6] = (a3 >> 14) & 1;
  a2[7] = (a3 >> 13) & 1;
  a2[10] = a3 & 7;
  a2[8] = (a3 >> 8) & 0x1F;
  a2[9] = (unsigned __int8)a3 >> 3;
}
