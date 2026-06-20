__int64 __fastcall ipareg_construct_clkon_cfg(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 result; // x0

  result = ipareg_construct_clkon_cfg_common(a2, a3);
  *a3 |= *(unsigned __int8 *)(a2 + 13) << 17;
  return result;
}
