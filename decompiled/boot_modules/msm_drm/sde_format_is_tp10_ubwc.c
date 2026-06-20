bool __fastcall sde_format_is_tp10_ubwc(__int64 a1)
{
  return (*(_QWORD *)(a1 + 32) & 1) != 0
      && (*(_QWORD *)(a1 + 32) & 2) != 0
      && *(_DWORD *)(a1 + 28) == 2
      && (*(_QWORD *)(a1 + 32) & 4) != 0
      && *(_BYTE *)(a1 + 25) == 4
      && *(_BYTE *)(a1 + 21);
}
