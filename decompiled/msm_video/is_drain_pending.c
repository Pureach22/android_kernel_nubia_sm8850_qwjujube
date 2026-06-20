bool __fastcall is_drain_pending(__int64 a1)
{
  return (~*(_DWORD *)(a1 + 176) & 5) == 0;
}
