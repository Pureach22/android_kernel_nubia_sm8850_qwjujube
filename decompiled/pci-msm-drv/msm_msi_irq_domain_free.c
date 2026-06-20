__int64 __fastcall msm_msi_irq_domain_free(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  unsigned int *v7; // x24
  __int64 *v8; // x22
  __int64 v9; // x23
  unsigned int v10; // w8
  __int64 **v11; // x8
  __int64 *v12; // x9

  result = irq_domain_get_irq_data();
  if ( result )
  {
    v7 = *(unsigned int **)(result + 48);
    v8 = *(__int64 **)v7;
    v9 = *(_QWORD *)(*(_QWORD *)v7 + 16LL);
    mutex_lock(v9 + 64);
    _bitmap_clear(*(_QWORD *)(v9 + 56), v7[7], a3);
    v10 = *((_DWORD *)v8 + 8) - a3;
    *((_DWORD *)v8 + 8) = v10;
    if ( !v10 )
    {
      if ( !*(_DWORD *)(v9 + 140) )
        dma_unmap_resource(v8[3], v8[5], 4096, 2, 0);
      v11 = (__int64 **)v8[1];
      if ( *v11 == v8 && (v12 = (__int64 *)*v8, *(__int64 **)(*v8 + 8) == v8) )
      {
        v12[1] = (__int64)v11;
        *v11 = v12;
      }
      else
      {
        _list_del_entry_valid_or_report(v8);
      }
      *v8 = 0xDEAD000000000100LL;
      v8[1] = 0xDEAD000000000122LL;
      kfree(v8);
    }
    mutex_unlock(v9 + 64);
    return irq_domain_free_irqs_parent(a1, a2, a3);
  }
  return result;
}
