__int64 __fastcall ipareg_construct_clkon_cfg_v4_5(__int64 a1, unsigned __int8 *a2, _DWORD *a3)
{
  __int64 result; // x0

  result = ipareg_construct_clkon_cfg_common(a2, a3);
  *a3 |= *a2 << 30;
  return result;
}
