__int64 __fastcall kgsl_mmu_pagetable_init(__int64 result, __int64 a2, int a3)
{
  *(_DWORD *)(a2 + 4) = 1;
  *(_QWORD *)(a2 + 40) = 0xFFFFFFFE00000LL;
  *(_DWORD *)a2 = 0;
  *(_QWORD *)(a2 + 48) = a2 + 48;
  *(_QWORD *)(a2 + 56) = a2 + 48;
  *(_QWORD *)(a2 + 64) = deferred_destroy_0;
  *(_QWORD *)(a2 + 112) = result;
  *(_DWORD *)(a2 + 24) = a3;
  *(_DWORD *)(a2 + 72) = 0;
  *(_QWORD *)(a2 + 80) = 0;
  *(_QWORD *)(a2 + 88) = 0;
  return result;
}
