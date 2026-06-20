__int64 __fastcall synx_timer_handler(__int64 a1)
{
  _QWORD *v2; // x19
  __int64 v3; // x21
  unsigned __int64 client; // x0
  unsigned __int64 v5; // x20
  unsigned __int64 v6; // x0
  __int64 v7; // x5
  unsigned __int64 v8; // x23
  unsigned __int64 v9; // x22
  __int64 v10; // x5
  _QWORD *v11; // x9
  _QWORD *v12; // x8
  __int64 *v13; // x9
  __int64 v14; // x10

  v3 = *(_QWORD *)(a1 - 16);
  v2 = (_QWORD *)(a1 - 24);
  client = synx_get_client(*(_QWORD *)(a1 - 24));
  if ( client && client < 0xFFFFFFFFFFFFF001LL )
  {
    v5 = client;
    v6 = synx_util_acquire_handle(client, *(unsigned int *)(a1 - 8));
    if ( v6 && v6 <= 0xFFFFFFFFFFFFF000LL && (v8 = *(_QWORD *)(v6 + 8)) != 0 && v8 < 0xFFFFFFFFFFFFF001LL )
    {
      v9 = v6;
      if ( (synx_debug & 0x10) != 0 )
        printk(&unk_29678, "verb", "synx_timer_handler", 1023, v3, v7);
      mutex_lock(v8 + 72);
      v11 = (_QWORD *)(v8 + 328);
      while ( 1 )
      {
        v11 = (_QWORD *)*v11;
        if ( v11 == (_QWORD *)(v8 + 328) )
          break;
        if ( v11 - 13 == (_QWORD *)v3 )
        {
          if ( (synx_debug & 0x10) != 0 )
            printk(&unk_25F39, "verb", "synx_timer_handler", 1029, v3, v10);
          *(_DWORD *)(v3 + 16) = 7;
          timer_delete((timer_t)(v3 + 24));
          v12 = *(_QWORD **)(v3 + 112);
          v13 = (__int64 *)(v3 + 104);
          if ( *v12 == v3 + 104 && (v14 = *v13, *(__int64 **)(*v13 + 8) == v13) )
          {
            *(_QWORD *)(v14 + 8) = v12;
            *v12 = v14;
          }
          else
          {
            _list_del_entry_valid_or_report(v3 + 104);
          }
          *(_QWORD *)(v3 + 104) = v3 + 104;
          *(_QWORD *)(v3 + 112) = v13;
          queue_work_on(32, *(_QWORD *)(synx_dev + 160), v3 + 72);
          break;
        }
      }
      mutex_unlock(v8 + 72);
      synx_util_release_handle(v9);
    }
    else if ( (synx_debug & 1) != 0 )
    {
      printk(&unk_2B7C9, &unk_29207, "synx_timer_handler", 1020, *(_QWORD *)(a1 - 24), *(unsigned int *)(a1 - 8));
    }
    synx_put_client(v5);
  }
  else if ( (synx_debug & 1) != 0 )
  {
    printk(&unk_26918, &unk_29207, "synx_timer_handler", 1012, *v2, v3);
  }
  return kfree(v2);
}
