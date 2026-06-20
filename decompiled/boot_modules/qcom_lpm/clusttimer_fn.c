__int64 __fastcall clusttimer_fn(__int64 a1)
{
  *(_WORD *)(a1 - 252) = 257;
  *(_DWORD *)(a1 - 244) = -1;
  *(_BYTE *)(a1 + 140) = 0;
  *(_QWORD *)(a1 + 104) = 0;
  *(_WORD *)(a1 + 142) = 1;
  return 0;
}
