__int64 __fastcall div_round_rate(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w22
  __int64 v4; // x24
  __int64 v5; // x21
  __int64 parent; // x0

  v3 = *(_DWORD *)(a1 - 16);
  v4 = *(unsigned int *)(a1 - 12);
  v5 = *(_QWORD *)(a1 - 8);
  parent = clk_hw_get_parent(a1);
  return divider_round_rate_parent(a1, parent, a2, a3, v5, v3, v4 | 0x10);
}
