__int64 __fastcall init_si_mem_object_user(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x19
  _QWORD *v9; // x1
  unsigned __int64 v16; // x9

  if ( mem_ops )
  {
    v6 = _kmalloc_cache_noprof(_warn_printk, 3520, 232);
    v7 = v6;
    if ( v6 )
    {
      _mutex_init(v6 + 112, "&mo->map.lock", &init_si_mem_object_user___key);
      _X8 = (unsigned __int64 *)a1[1];
      __asm { PRFM            #0x11, [X8] }
      do
        v16 = __ldxr(_X8);
      while ( __stxr(v16 + 1, _X8) );
      if ( !v16 && (get_file___already_done & 1) == 0 )
      {
        get_file___already_done = 1;
        _warn_printk("struct file::f_count incremented from zero; use-after-free condition present!\n");
        __break(0x800u);
      }
      *(_QWORD *)(v7 + 88) = a1;
      *(_QWORD *)(v7 + 216) = a3;
      *(_QWORD *)(v7 + 224) = a2;
      init_si_object_user(v7, 2, &mem_ops, "mem-object-%p", a1);
      mutex_lock(&mo_list_mutex);
      v9 = off_E0;
      if ( off_E0 == (_UNKNOWN **)(v7 + 200) || *off_E0 != (_UNKNOWN *)&mo_list )
      {
        _list_add_valid_or_report();
      }
      else
      {
        off_E0 = (_UNKNOWN **)(v7 + 200);
        *(_QWORD *)(v7 + 200) = &mo_list;
        *(_QWORD *)(v7 + 208) = v9;
        *v9 = v7 + 200;
      }
      mutex_unlock(&mo_list_mutex);
    }
  }
  else
  {
    printk(&unk_6CA6, "init_si_mem_object_user");
    return 0;
  }
  return v7;
}
