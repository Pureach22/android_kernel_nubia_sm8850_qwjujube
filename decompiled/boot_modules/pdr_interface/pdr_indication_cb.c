__int64 __fastcall pdr_indication_cb(__int64 result, int a2, int a3, char *string)
{
  const char *v4; // x20
  __int64 v5; // x19
  size_t v7; // x0
  const char *v8; // x23
  __int16 v9; // w8
  int v10; // w9
  __int64 v11; // x20
  unsigned __int64 StatusReg; // x22
  __int64 v13; // x23
  __int64 (__fastcall *v14)(_QWORD, _QWORD, _QWORD); // x0

  if ( !string )
    return result;
  v4 = string + 4;
  if ( !string[4] )
    return result;
  v5 = result;
  v7 = strnlen(string + 4, 0x41u);
  if ( v7 >= 0x42 )
  {
    v7 = _fortify_panic(2, 65, v7 + 1);
  }
  else if ( v7 != 65 )
  {
    mutex_lock(v5 + 352);
    v8 = (const char *)(v5 + 320);
    do
    {
      v8 = *(const char **)v8;
      if ( v8 == (const char *)(v5 + 320) )
        return mutex_unlock(v5 + 352);
    }
    while ( strcmp(v8 - 103, v4) );
    v4 = v8 - 168;
    result = mutex_unlock(v5 + 352);
    if ( v8 != (const char *)&off_A8 )
    {
      printk(&unk_77C5, string + 4, *(unsigned int *)string, *((unsigned __int16 *)string + 35));
      result = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
      if ( result )
        goto LABEL_10;
    }
    return result;
  }
  _fortify_panic(4, 65, v7 + 1);
  StatusReg = _ReadStatusReg(SP_EL0);
  v13 = *(_QWORD *)(StatusReg + 80);
  v14 = _kmalloc_cache_noprof;
  *(_QWORD *)(StatusReg + 80) = &pdr_indication_cb__alloc_tag;
  result = _kmalloc_cache_noprof(v14, 3520, 72);
  *(_QWORD *)(StatusReg + 80) = v13;
  if ( result )
  {
LABEL_10:
    v9 = *((_WORD *)string + 35);
    v10 = *(_DWORD *)string;
    *(_QWORD *)(result + 8) = v4;
    v11 = result;
    *(_WORD *)(result + 4) = v9;
    *(_DWORD *)result = v10;
    init_timer_key(result + 32, ind_notif_timeout_handler, 0, 0, 0);
    mutex_lock(v5 + 352);
    list_add_tail(v11 + 16, v5 + 336);
    mutex_unlock(v5 + 352);
    return queue_work_on(32, *(_QWORD *)(v5 + 608), v5 + 568);
  }
  return result;
}
