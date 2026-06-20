__int64 __fastcall server_release(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  _QWORD *v3; // x23
  int v6; // w8
  _QWORD *v7; // x20
  _QWORD *v8; // x8
  __int64 v9; // x21
  __int64 i; // x25
  int v11; // w9
  int v12; // w8
  __int64 v14; // x8
  int v20; // w8

  v2 = *(_QWORD *)(a2 + 32);
  mutex_lock(&si_mutex);
  v3 = *(_QWORD **)(v2 + 24);
  *(_DWORD *)(v2 + 20) = 1;
  while ( v3 != (_QWORD *)(v2 + 24) )
  {
    v6 = *((_DWORD *)v3 - 5);
    v7 = v3;
    v3 = (_QWORD *)*v3;
    if ( (unsigned int)(v6 - 1) <= 1 )
    {
      if ( *((_DWORD *)v7 - 13) )
      {
        complete(v7 + 2);
      }
      else if ( v6 == 1 )
      {
        v8 = (_QWORD *)v7[1];
        if ( (_QWORD *)*v8 == v7 && (_QWORD *)v3[1] == v7 )
        {
          v3[1] = v8;
          *v8 = v3;
        }
        else
        {
          _list_del_entry_valid_or_report(v7);
        }
        *v7 = v7;
        v7[1] = v7;
        v9 = *(v7 - 4);
        if ( v9 )
        {
          for ( i = 0; ; ++i )
          {
            v11 = 0;
            do
              v12 = v11;
            while ( *(_DWORD *)(v9 + 24LL * v11++) );
            if ( i >= v12 )
              break;
            v14 = v9 + 24 * i;
            if ( (unsigned int)(*(_DWORD *)v14 - 1) <= 1 )
              kfree(*(_QWORD *)(v14 + 8));
          }
          kfree(v9);
        }
        kfree(*(v7 - 1));
        kfree(v7 - 7);
      }
    }
  }
  mutex_unlock(&si_mutex);
  _X20 = (unsigned int *)(v2 + 16);
  printk(&unk_10520, "server_release", v2);
  __asm { PRFM            #0x11, [X20] }
  do
    v20 = __ldxr(_X20);
  while ( __stlxr(v20 - 1, _X20) );
  if ( v20 == 1 )
  {
    __dmb(9u);
    printk(&unk_103E6, "____destroy_server_info", v2);
    kfree(v2);
  }
  else if ( v20 <= 0 )
  {
    refcount_warn_saturate(v2 + 16, 3);
  }
  return 0;
}
