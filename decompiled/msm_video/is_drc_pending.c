bool __fastcall is_drc_pending(__int64 a1)
{
  return (~*(_DWORD *)(a1 + 176) & 0xA) == 0;
}
