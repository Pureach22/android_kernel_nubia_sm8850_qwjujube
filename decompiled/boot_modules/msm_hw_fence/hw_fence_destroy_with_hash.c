__int64 __fastcall hw_fence_destroy_with_hash(__int64 a1, unsigned int *a2, unsigned __int64 a3)
{
  __int64 v3; // x30
  unsigned int v5; // w20
  unsigned __int64 v6; // x21
  __int64 v9; // x21

  if ( a2 )
    v5 = *a2;
  else
    v5 = -1;
  if ( *(unsigned int *)(a1 + 16) <= a3 )
  {
    v9 = v3;
    printk(&unk_23ADB, "_get_hw_fence", 1135, v3, a3);
LABEL_10:
    printk(&unk_226E9, "hw_fence_destroy_with_hash", 1801, v9, a3);
    return 4294967274LL;
  }
  v6 = *(_QWORD *)(a1 + 64) + (a3 << 7);
  if ( !v6 )
  {
    v9 = v3;
    goto LABEL_10;
  }
  global_atomic_store(a1, v6 + 40, 1);
  return hw_fence_put_and_unlock(a1, v5, v6, a3);
}
