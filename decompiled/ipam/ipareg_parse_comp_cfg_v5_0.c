__int64 __fastcall ipareg_parse_comp_cfg_v5_0(__int64 a1, bool *a2, int a3)
{
  __int64 result; // x0

  result = ipareg_parse_comp_cfg_common(a2, (unsigned int)a3);
  *a2 = a3 < 0;
  a2[1] = (a3 & 0x40000000) != 0;
  a2[3] = ((unsigned int)a3 >> 22) & 0x3F;
  a2[4] = (a3 & 0x200000) != 0;
  a2[5] = (a3 & 0x100000) != 0;
  a2[6] = (a3 & 0x80000) != 0;
  a2[2] = (a3 & 0x20000) != 0;
  a2[23] = a3 & 1;
  return result;
}
