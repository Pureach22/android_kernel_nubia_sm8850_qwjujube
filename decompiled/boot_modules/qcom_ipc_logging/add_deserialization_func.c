__int64 __fastcall add_deserialization_func(__int64 a1, int a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v7; // x22
  __int64 lock_irqsave; // x23
  __int64 v9; // x2
  __int64 *v10; // x1

  result = 4294967274LL;
  if ( a1 && a3 )
  {
    v7 = _kmalloc_cache_noprof(raw_read_unlock_irq, 3264, 32);
    if ( v7 )
    {
      lock_irqsave = raw_read_lock_irqsave(&context_list_lock_lha1);
      raw_spin_lock(a1 + 160);
      v9 = a1 + 144;
      v10 = *(__int64 **)(a1 + 152);
      *(_DWORD *)(v7 + 16) = a2;
      *(_QWORD *)(v7 + 24) = a3;
      if ( v7 == a1 + 144 || v10 == (__int64 *)v7 || *v10 != v9 )
      {
        _list_add_valid_or_report(v7, v10);
      }
      else
      {
        *(_QWORD *)(a1 + 152) = v7;
        *(_QWORD *)v7 = v9;
        *(_QWORD *)(v7 + 8) = v10;
        *v10 = v7;
      }
      raw_spin_unlock(a1 + 160);
      raw_read_unlock_irqrestore(&context_list_lock_lha1, lock_irqsave);
      return 0;
    }
    else
    {
      return 4294967268LL;
    }
  }
  return result;
}
