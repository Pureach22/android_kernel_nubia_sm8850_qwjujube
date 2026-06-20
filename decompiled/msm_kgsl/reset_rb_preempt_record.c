__int64 __fastcall reset_rb_preempt_record(__int64 a1, __int64 a2)
{
  int v4; // w22

  v4 = (*(_DWORD *)(*(_QWORD *)(a1 + 14264) + 32LL) << 16) & 0x8000000;
  memset(*(void **)(*(_QWORD *)(a2 + 184) + 8LL), 0, *(_QWORD *)(*(_QWORD *)(a2 + 184) + 40LL));
  kgsl_sharedmem_writel(*(_QWORD *)(a2 + 184), 0, 2923011438LL);
  kgsl_sharedmem_writel(*(_QWORD *)(a2 + 184), 16, v4 ^ 0x800020Cu);
  kgsl_sharedmem_writeq(*(_QWORD *)(a2 + 184), 32, *(_QWORD *)(*(_QWORD *)(a1 + 48) + 24LL) + 32LL * *(int *)(a2 + 28));
  return kgsl_sharedmem_writeq(*(_QWORD *)(a2 + 184), 40, *(_QWORD *)(*(_QWORD *)(a2 + 8) + 24LL));
}
