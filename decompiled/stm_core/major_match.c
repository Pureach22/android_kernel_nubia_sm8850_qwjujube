bool __fastcall major_match(__int64 a1, _DWORD *a2)
{
  return *a2 == *(_DWORD *)(a1 + 760) >> 20;
}
