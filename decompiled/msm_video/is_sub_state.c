bool __fastcall is_sub_state(__int64 a1, int a2)
{
  return (*(_DWORD *)(a1 + 176) & a2) != 0;
}
