__int64 __fastcall arm_tbu_write_sync(__int64 a1)
{
  return readl_relaxed_1((unsigned int *)(*(_QWORD *)(a1 + 32) + 32LL));
}
