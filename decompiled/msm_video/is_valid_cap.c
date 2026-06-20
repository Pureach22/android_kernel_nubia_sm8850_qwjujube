bool __fastcall is_valid_cap(__int64 a1, unsigned int a2)
{
  return a2 - 197 >= 0xFFFFFF3C && *(_DWORD *)(a1 + 168LL * a2 + 4320) != 0;
}
