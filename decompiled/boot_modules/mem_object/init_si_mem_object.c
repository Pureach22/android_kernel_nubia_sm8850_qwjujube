__int64 __fastcall init_si_mem_object(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x0
  __int64 v8; // x19
  _QWORD *v9; // x1
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = a1;
  if ( ((a2 + 4095) & 0xFFFFFFFFFFFFF000LL) == a2 )
  {
    if ( mem_ops )
    {
      v7 = _kmalloc_cache_noprof(_warn_printk, 3520, 232);
      v8 = v7;
      if ( v7 )
      {
        _mutex_init(v7 + 112, "&mo->map.lock", &init_si_mem_object___key);
        *(_QWORD *)(v8 + 176) = v11[0];
        *(_QWORD *)(v8 + 184) = a2;
        *(_QWORD *)(v8 + 216) = a4;
        *(_QWORD *)(v8 + 224) = a3;
        *(_DWORD *)(v8 + 192) = 6;
        init_si_object_user(v8, 2, &mem_ops, "kernel-mem-object-%pa", v11);
        mutex_lock(&mo_list_mutex);
        v9 = off_E0;
        if ( off_E0 == (_UNKNOWN **)(v8 + 200) || *off_E0 != (_UNKNOWN *)&mo_list )
        {
          _list_add_valid_or_report();
        }
        else
        {
          off_E0 = (_UNKNOWN **)(v8 + 200);
          *(_QWORD *)(v8 + 200) = &mo_list;
          *(_QWORD *)(v8 + 208) = v9;
          *v9 = v8 + 200;
        }
        mutex_unlock(&mo_list_mutex);
      }
    }
    else
    {
      printk(&unk_6CA6, "init_si_mem_object");
      v8 = 0;
    }
  }
  else
  {
    printk(&unk_6CF9, "init_si_mem_object");
    v8 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
