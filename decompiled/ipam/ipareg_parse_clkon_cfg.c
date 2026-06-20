__int64 __fastcall ipareg_parse_clkon_cfg(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0

  result = ipareg_parse_clkon_cfg_common(a2, a3);
  *(_BYTE *)(a2 + 13) = (a3 & 0x20000) != 0;
  return result;
}
