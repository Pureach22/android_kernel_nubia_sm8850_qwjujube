__int64 __fastcall ipareg_parse_comp_cfg(__int64 a1, _BYTE *a2, unsigned int a3)
{
  __int64 result; // x0

  result = ipareg_parse_comp_cfg_common(a2, a3);
  a2[24] = a3 & 1;
  a2[3] = (a3 >> 17) & 0xF;
  a2[19] = (a3 & 0x10) != 0;
  return result;
}
