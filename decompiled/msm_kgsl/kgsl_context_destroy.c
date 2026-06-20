__int64 __fastcall kgsl_context_destroy(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x20
  __int64 v4; // x8
  _QWORD *v5; // x21
  _QWORD *v6; // x22
  _QWORD *v7; // x8
  _QWORD *v8; // x24
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 (__fastcall *v11)(_QWORD); // x8
  unsigned int v19; // w10

  v2 = *(_QWORD *)(a1 + 40);
  if ( a1 )
  {
    v4 = *(_QWORD *)(a1 + 32);
    if ( (v4 & 2) == 0 )
    {
      __break(0x800u);
LABEL_19:
      _X8 = (unsigned int *)(v4 + 376);
      __asm { PRFM            #0x11, [X8] }
      do
        v19 = __ldxr(_X8);
      while ( __stxr(v19 - 1, _X8) );
      idr_remove(v2 + 11184);
      *(_DWORD *)(a1 + 4) = -1;
      goto LABEL_15;
    }
  }
  if ( (*(_BYTE *)(a1 + 203) & 0x40) != 0 )
  {
    v5 = *(_QWORD **)(a1 + 296);
    v6 = (_QWORD *)(a1 + 296);
    if ( v5 != (_QWORD *)(a1 + 296) )
    {
      do
      {
        v8 = (_QWORD *)*v5;
        v7 = (_QWORD *)v5[1];
        if ( (_QWORD *)*v7 == v5 && (_QWORD *)v8[1] == v5 )
        {
          v8[1] = v7;
          *v7 = v8;
        }
        else
        {
          _list_del_entry_valid_or_report(v5);
        }
        v9 = v5[3];
        *v5 = 0xDEAD000000000100LL;
        v5[1] = 0xDEAD000000000122LL;
        kfree(v9);
        kfree(v5);
        v5 = v8;
      }
      while ( v8 != v6 );
    }
  }
  kgsl_sync_timeline_put(*(_QWORD *)(a1 + 56));
  v1 = 11208;
  raw_write_lock(v2 + 11208);
  v10 = *(unsigned int *)(a1 + 4);
  if ( (_DWORD)v10 != -1 )
  {
    kgsl_sharedmem_writel(*(_QWORD *)(v2 + 40), 40 * v10, 0);
    kgsl_sharedmem_writel(*(_QWORD *)(v2 + 40), 40LL * *(unsigned int *)(a1 + 4) + 8, 0);
    if ( *(_DWORD *)(a1 + 4) == *(_DWORD *)(v2 + 10432) )
      *(_DWORD *)(v2 + 10416) = 0;
    v4 = *(_QWORD *)(a1 + 24);
    goto LABEL_19;
  }
LABEL_15:
  raw_write_unlock(v2 + v1);
  kgsl_process_private_put(*(unsigned int **)(a1 + 24));
  v11 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v2 + 8752) + 136LL);
  if ( *((_DWORD *)v11 - 1) != -940862279 )
    __break(0x8228u);
  return v11(a1);
}
