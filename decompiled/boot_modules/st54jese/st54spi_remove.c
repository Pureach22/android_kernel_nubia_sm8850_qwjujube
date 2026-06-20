__int64 __fastcall st54spi_remove(__int64 a1)
{
  unsigned int *v1; // x19
  unsigned int **v2; // x8
  unsigned int *v3; // x0
  __int64 v4; // x9
  __int64 v5; // x0
  __int64 v6; // x1
  unsigned __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x8
  unsigned __int64 v17; // x10

  v1 = *(unsigned int **)(a1 + 152);
  raw_spin_lock_irq(v1 + 1);
  *((_QWORD *)v1 + 1) = 0;
  *((_QWORD *)v1 + 2) = 0;
  raw_spin_unlock_irq(v1 + 1);
  mutex_lock(&device_list_lock);
  v2 = *((unsigned int ***)v1 + 4);
  v3 = v1 + 6;
  if ( *v2 == v1 + 6 && (v4 = *(_QWORD *)v3, *(unsigned int **)(*(_QWORD *)v3 + 8LL) == v3) )
  {
    *(_QWORD *)(v4 + 8) = v2;
    *v2 = (unsigned int *)v4;
  }
  else
  {
    _list_del_entry_valid_or_report();
  }
  v5 = st54spi_class;
  v6 = *v1;
  *((_QWORD *)v1 + 3) = 0xDEAD000000000100LL;
  *((_QWORD *)v1 + 4) = 0xDEAD000000000122LL;
  device_destroy(v5, v6);
  v7 = *v1;
  v8 = (v7 >> 6) & 0x3FFF;
  v9 = 1LL << v7;
  _X9 = (unsigned __int64 *)&minors[v8];
  __asm { PRFM            #0x11, [X9] }
  do
    v17 = __ldxr(_X9);
  while ( __stxr(v17 & ~v9, _X9) );
  if ( !v1[22] )
  {
    kfree(*((_QWORD *)v1 + 12));
    kfree(*((_QWORD *)v1 + 13));
    kfree(*((_QWORD *)v1 + 14));
    kfree(v1);
  }
  return mutex_unlock(&device_list_lock);
}
