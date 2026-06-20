unsigned int *__fastcall kgsl_process_private_put(unsigned int *result)
{
  unsigned int *v1; // x19
  unsigned int **v2; // x8
  unsigned int *v3; // x0
  __int64 v4; // x9
  int v10; // w8

  if ( result )
  {
    v1 = result;
    result += 9;
    __asm { PRFM            #0x11, [X0] }
    do
      v10 = __ldxr(result);
    while ( __stlxr(v10 - 1, result) );
    if ( v10 == 1 )
    {
      __dmb(9u);
      if ( v1[220] )
        gmu_core_free_block(*(_QWORD *)(*((_QWORD *)v1 + 8) + 112LL) - 56LL, v1 + 174);
      kgsl_put_work_period(*((_QWORD *)v1 + 61));
      mutex_lock(&unk_3A840);
      debugfs_remove(*((_QWORD *)v1 + 25));
      kobject_put(v1 + 126);
      kobject_put(v1 + 26);
      if ( *(_DWORD *)(*((_QWORD *)v1 + 8) + 24LL) )
        kgsl_mmu_detach_pagetable();
      raw_write_lock(&unk_3A870);
      v2 = *((unsigned int ***)v1 + 10);
      v3 = v1 + 18;
      if ( *v2 == v1 + 18 && (v4 = *(_QWORD *)v3, *(unsigned int **)(*(_QWORD *)v3 + 8LL) == v3) )
      {
        *(_QWORD *)(v4 + 8) = v2;
        *v2 = (unsigned int *)v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      *((_QWORD *)v1 + 9) = 0xDEAD000000000100LL;
      *((_QWORD *)v1 + 10) = 0xDEAD000000000122LL;
      raw_write_unlock(&unk_3A870);
      mutex_unlock(&unk_3A840);
      kfree(*((_QWORD *)v1 + 81));
      put_pid(*((_QWORD *)v1 + 1));
      idr_destroy(v1 + 10);
      idr_destroy(v1 + 86);
      if ( *(_DWORD *)(*((_QWORD *)v1 + 8) + 24LL) )
        kgsl_mmu_putpagetable();
      return (unsigned int *)kfree(v1);
    }
    else if ( v10 <= 0 )
    {
      return (unsigned int *)refcount_warn_saturate(result, 3);
    }
  }
  return result;
}
