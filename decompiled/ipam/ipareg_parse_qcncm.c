void __fastcall ipareg_parse_qcncm(__int64 a1, _DWORD *a2, unsigned int a3)
{
  *a2 = 0;
  a2[1] = (a3 >> 4) & 0xFFFFFF;
  *(_BYTE *)a2 = a3 & 1;
  a2[2] = a3 & 0xF000000E;
}
