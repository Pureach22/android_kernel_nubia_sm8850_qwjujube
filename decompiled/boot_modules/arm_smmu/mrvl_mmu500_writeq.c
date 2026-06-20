__int64 __fastcall mrvl_mmu500_writeq(__int64 a1, int a2, int a3, __int64 a4)
{
  unsigned int v4; // w19
  unsigned int *v5; // x20

  v4 = a4;
  v5 = (unsigned int *)(*(_QWORD *)(a1 + 8) + (a2 << *(_DWORD *)(a1 + 28)) + a3);
  writel_relaxed(HIDWORD(a4), v5 + 1);
  return writel_relaxed(v4, v5);
}
