__int64 __fastcall entry_ffs_sb_fill(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  _QWORD *i; // x19
  const char *v4; // x20
  size_t v5; // x0
  unsigned __int64 v6; // x2
  __int64 v7; // x1
  unsigned __int64 StatusReg; // x20
  __int64 v10; // x22
  __int64 (__fastcall *v11)(_QWORD, _QWORD, _QWORD); // x0

  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 8) + 64LL) + 32LL);
  for ( i = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 2336, 88); i; *(_QWORD *)(StatusReg + 80) = v10 )
  {
    *i = 0xFFFFFFFE00000LL;
    i[1] = i + 1;
    i[2] = i + 1;
    i[3] = create_ipc_context_work;
    v4 = *(const char **)(v2 + 200);
    v5 = strnlen(v4, 0x29u);
    if ( v5 == -1 )
    {
      _fortify_panic(2, -1, 0);
    }
    else
    {
      if ( v5 == 41 )
        v6 = 41;
      else
        v6 = v5 + 1;
      if ( v6 < 0x2A )
      {
        sized_strscpy(i + 5, v4);
        v7 = ipc_wq;
        i[4] = v2;
        queue_work_on(32, v7, i);
        return 0;
      }
    }
    _fortify_panic(7, 41, v6);
    StatusReg = _ReadStatusReg(SP_EL0);
    v10 = *(_QWORD *)(StatusReg + 80);
    v11 = _kmalloc_cache_noprof;
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    i = (_QWORD *)_kmalloc_cache_noprof(v11, 2336, 88);
  }
  return 0;
}
