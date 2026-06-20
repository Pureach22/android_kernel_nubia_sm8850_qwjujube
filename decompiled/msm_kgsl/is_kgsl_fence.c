bool __fastcall is_kgsl_fence(__int64 a1)
{
  return *(_QWORD *)(a1 + 8) == (_QWORD)&kgsl_sync_fence_ops;
}
