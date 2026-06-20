unsigned __int64 __fastcall mrvl_mmu500_readq(__int64 a1, int a2, int a3)
{
  unsigned int *v3; // x19
  __int64 v4; // x20

  v3 = (unsigned int *)(*(_QWORD *)(a1 + 8) + (a2 << *(_DWORD *)(a1 + 28)) + a3);
  v4 = (unsigned int)readl_relaxed(v3 + 1);
  return (unsigned int)readl_relaxed(v3) | (unsigned __int64)(v4 << 32);
}
