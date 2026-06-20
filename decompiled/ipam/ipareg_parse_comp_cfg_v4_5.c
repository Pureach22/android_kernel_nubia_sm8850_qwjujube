__int64 __fastcall ipareg_parse_comp_cfg_v4_5(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0

  result = ipareg_parse_comp_cfg_common(a2, a3);
  *(_BYTE *)(a2 + 3) = (a3 >> 17) & 0xF;
  *(_BYTE *)(a2 + 2) = (a3 & 0x200000) != 0;
  return result;
}
