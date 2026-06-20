__int64 __fastcall ipareg_parse_clkon_cfg_v4_5(__int64 a1, bool *a2, unsigned int a3)
{
  __int64 result; // x0

  result = ipareg_parse_clkon_cfg_common(a2, a3);
  *a2 = (a3 & 0x40000000) != 0;
  return result;
}
