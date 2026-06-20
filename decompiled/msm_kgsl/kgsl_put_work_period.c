unsigned int *__fastcall kgsl_put_work_period(unsigned int *result)
{
  __int64 v2; // x8
  unsigned int *v3; // x9
  unsigned int **v4; // x10
  int v10; // w8

  if ( result )
  {
    _X19 = result;
    if ( (unsigned __int64)result <= 0xFFFFFFFFFFFFF000LL )
    {
      __asm { PRFM            #0x11, [X19] }
      do
        v10 = __ldxr(result);
      while ( __stlxr(v10 - 1, result) );
      if ( v10 == 1 )
      {
        __dmb(9u);
        raw_spin_lock(&unk_3A820);
        v3 = _X19 + 2;
        v2 = *((_QWORD *)_X19 + 1);
        if ( (unsigned int *)v2 != _X19 + 2 )
        {
          v4 = *((unsigned int ***)_X19 + 2);
          if ( *v4 == v3 && *(unsigned int **)(v2 + 8) == v3 )
          {
            *(_QWORD *)(v2 + 8) = v4;
            *v4 = (unsigned int *)v2;
          }
          else
          {
            _list_del_entry_valid_or_report(_X19 + 2);
          }
          *((_QWORD *)_X19 + 1) = _X19 + 2;
          *((_QWORD *)_X19 + 2) = v3;
        }
        raw_spin_unlock(&unk_3A820);
        return (unsigned int *)kfree(_X19);
      }
      else if ( v10 <= 0 )
      {
        return (unsigned int *)refcount_warn_saturate(result, 3);
      }
    }
  }
  return result;
}
