__int64 __fastcall kgsl_iommu_put_gpuaddr(__int64 *a1)
{
  __int64 result; // x0
  __int64 v3; // x23
  unsigned __int64 v4; // x1
  __int64 *v5; // x20
  __int64 v6; // x21
  __int64 v7; // x8
  unsigned __int64 v8; // x8
  __int64 v9; // x0
  unsigned __int64 v10; // x8
  __int64 v11; // x10

  result = *a1;
  if ( !result )
    return result;
  raw_spin_lock(result);
  v3 = *a1;
  v4 = a1[3];
  v5 = (__int64 *)(*a1 + 120);
  v6 = *v5;
  if ( !*v5 )
  {
LABEL_3:
    _warn_printk("GPU address %llx doesn't exist\n", v4);
    __break(0x800u);
    return raw_spin_unlock(*a1);
  }
  while ( 1 )
  {
    v8 = *(_QWORD *)(v6 - 16);
    if ( v8 <= v4 )
      break;
    v7 = 16;
LABEL_5:
    v6 = *(_QWORD *)(v6 + v7);
    if ( !v6 )
      goto LABEL_3;
  }
  if ( v8 < v4 )
  {
    v7 = 8;
    goto LABEL_5;
  }
  if ( v6 == 16 )
    goto LABEL_3;
  if ( *(_QWORD *)(v3 + 176) == *(_QWORD *)(v6 - 8) + v8 )
  {
    v9 = rb_prev(v6);
    v10 = *(_QWORD *)(v3 + 128);
    *(_QWORD *)(v3 + 176) = v10;
    if ( v9 )
    {
      if ( v9 != 16 )
      {
        v11 = *(_QWORD *)(v9 - 8);
        if ( v11 + *(_QWORD *)(v9 - 16) > v10 )
          v10 = v11 + *(_QWORD *)(v9 - 16);
        *(_QWORD *)(v3 + 176) = v10;
      }
    }
  }
  rb_erase(v6, v5);
  kmem_cache_free(addr_entry_cache, v6 - 16);
  return raw_spin_unlock(*a1);
}
