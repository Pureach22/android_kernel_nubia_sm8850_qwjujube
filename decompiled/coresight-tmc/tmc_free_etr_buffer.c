__int64 __fastcall tmc_free_etr_buffer(__int64 *a1)
{
  __int64 v3; // x22
  __int64 v4; // x21
  __int64 v5; // x20
  __int64 v6; // x8
  void (__fastcall *v7)(_QWORD); // x8
  int v13; // w8

  _X20 = (unsigned int *)a1[1];
  if ( _X20 )
  {
    v3 = *a1;
    mutex_lock(*a1 + 240);
    __asm { PRFM            #0x11, [X20] }
    do
      v13 = __ldxr(_X20);
    while ( __stlxr(v13 - 1, _X20) );
    if ( v13 == 1 )
    {
      __dmb(9u);
      v4 = idr_remove(v3 + 216, *((int *)a1 + 4));
      mutex_unlock(v3 + 240);
      if ( v4 && (unsigned int *)v4 != _X20 )
      {
        __break(0x800u);
      }
      else
      {
        v5 = a1[1];
        v6 = *(_QWORD *)(v5 + 48);
        if ( !v6 || (v7 = *(void (__fastcall **)(_QWORD))(v6 + 24)) == nullptr )
        {
          __break(0x800u);
          v7 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v5 + 48) + 24LL);
        }
        if ( *((_DWORD *)v7 - 1) != 1050944703 )
          __break(0x8228u);
        v7(v5);
        kfree(v5);
      }
    }
    else
    {
      if ( v13 <= 0 )
        refcount_warn_saturate(_X20, 3);
      mutex_unlock(v3 + 240);
    }
  }
  return kfree(a1);
}
