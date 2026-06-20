unsigned __int64 __fastcall pdr_add_lookup(unsigned __int64 a1, char *s, const char *a3)
{
  unsigned __int64 result; // x0
  size_t v7; // x8
  __int64 v8; // x0
  unsigned __int64 v9; // x21
  size_t v10; // x0
  unsigned __int64 v11; // x2
  unsigned __int64 *v12; // x22
  const char *v13; // x23
  unsigned __int64 v14; // x2
  unsigned __int64 v15; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v17; // x23
  size_t (*v18)(const char *, size_t); // x0

  result = -22;
  if ( !a1 )
    return result;
  if ( a1 > 0xFFFFFFFFFFFFF000LL )
    return result;
  if ( !s )
    return result;
  v7 = strlen(s);
  result = -22;
  if ( !a3 || v7 > 0x40 )
    return result;
  if ( strlen(a3) > 0x40 )
    return -22;
  v8 = _kmalloc_cache_noprof(strnlen, 3520, 184);
  if ( !v8 )
    return -12;
  while ( 1 )
  {
    v9 = v8;
    *(_DWORD *)(v8 + 148) = 66;
    v10 = strnlen(s, 0x41u);
    if ( v10 != -1 )
    {
      if ( v10 == 65 )
        v11 = 65;
      else
        v11 = v10 + 1;
      if ( v11 >= 0x42 )
        goto LABEL_32;
      sized_strscpy(v9, s);
      v10 = strnlen(a3, 0x41u);
      if ( v10 != -1 )
        break;
    }
    _fortify_panic(2, -1, v10 + 1);
LABEL_32:
    _fortify_panic(7, 65, v11);
    StatusReg = _ReadStatusReg(SP_EL0);
    v17 = *(_QWORD *)(StatusReg + 80);
    v18 = strnlen;
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v8 = _kmalloc_cache_noprof(v18, 3520, 184);
    *(_QWORD *)(StatusReg + 80) = v17;
    if ( !v8 )
      return -12;
  }
  if ( v10 == 65 )
    v11 = 65;
  else
    v11 = v10 + 1;
  if ( v11 >= 0x42 )
    goto LABEL_32;
  sized_strscpy(v9 + 65, a3);
  *(_BYTE *)(v9 + 166) = 1;
  mutex_lock(a1 + 656);
  v12 = (unsigned __int64 *)(a1 + 624);
  v13 = (const char *)(a1 + 624);
  while ( 1 )
  {
    v13 = *(const char **)v13;
    if ( v13 == (const char *)v12 )
      break;
    if ( !strcmp(v13 - 103, a3) )
    {
      mutex_unlock(a1 + 656);
      if ( v9 <= 0xFFFFFFFFFFFFF000LL )
        kfree(v9);
      return -114;
    }
  }
  v14 = *v12;
  v15 = v9 + 168;
  if ( *(unsigned __int64 **)(*v12 + 8) != v12 || (unsigned __int64 *)v15 == v12 || v14 == v15 )
  {
    _list_add_valid_or_report(v15, a1 + 624);
  }
  else
  {
    *(_QWORD *)(v14 + 8) = v15;
    *(_QWORD *)(v9 + 168) = v14;
    *(_QWORD *)(v9 + 176) = v12;
    *v12 = v15;
  }
  mutex_unlock(a1 + 656);
  queue_work_on(32, system_wq, a1 + 808);
  return v9;
}
