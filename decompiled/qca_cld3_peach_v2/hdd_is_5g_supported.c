bool __fastcall hdd_is_5g_supported(__int64 a1)
{
  return !a1 || *(_DWORD *)(a1 + 3252) != 1;
}
