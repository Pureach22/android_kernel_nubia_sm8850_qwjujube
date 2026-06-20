__int64 __fastcall arm_smmu_write_ns(__int64 a1, int a2, int a3, unsigned int a4)
{
  if ( !a2 && ((unsigned int)(a3 - 72) <= 0x10 && ((1 << (a3 - 72)) & 0x11101) != 0 || a3 == 16 || !a3) )
    a3 += 1024;
  return writel_relaxed(a4, (unsigned int *)(*(_QWORD *)(a1 + 8) + (a2 << *(_DWORD *)(a1 + 28)) + a3));
}
