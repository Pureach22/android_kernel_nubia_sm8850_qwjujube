__int64 __fastcall process_private_deferred_put(__int64 a1)
{
  __int64 v1; // x19

  v1 = a1 - 8;
  kgsl_process_private_put(*(unsigned int **)(a1 - 8));
  return kfree(v1);
}
