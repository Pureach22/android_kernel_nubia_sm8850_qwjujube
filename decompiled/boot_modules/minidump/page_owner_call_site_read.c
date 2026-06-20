__int64 __fastcall page_owner_call_site_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  const char *v7; // x22
  int v8; // w23
  const char *v9; // x28
  int v10; // w25
  size_t v11; // x0
  __int64 v12; // x19
  unsigned __int64 StatusReg; // x19
  __int64 v14; // x23
  __int64 v16; // [xsp+8h] [xbp-8h]

  v7 = (const char *)_kmalloc_cache_noprof(_kmalloc_large_noprof, 3264, 4096);
  if ( !v7 )
    return -12;
  while ( 1 )
  {
    v16 = a2;
    a2 = a4;
    v8 = scnprintf(v7, a3, "%s\n", "Accounted call sites:");
    a4 = raw_spin_lock_irqsave(&accounted_call_site_lock);
    v9 = (const char *)accounted_call_site_list;
    if ( accounted_call_site_list != (_UNKNOWN *)&accounted_call_site_list )
      break;
LABEL_6:
    raw_spin_unlock_irqrestore(&accounted_call_site_lock, a4);
    v11 = strnlen(v7, 0x1000u);
    if ( v11 > 0x1000 )
    {
      _fortify_panic(2, 4096, v11 + 1);
    }
    else if ( v11 != 4096 )
    {
      v12 = (int)simple_read_from_buffer(v16, a3, a2, v7, v11);
      goto LABEL_10;
    }
    _fortify_panic(4, 4096, 4097);
    StatusReg = _ReadStatusReg(SP_EL0);
    v14 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &page_owner_call_site_read__alloc_tag;
    v7 = (const char *)_kmalloc_cache_noprof(_kmalloc_large_noprof, 3264, 4096);
    *(_QWORD *)(StatusReg + 80) = v14;
    if ( !v7 )
      return -12;
  }
  v10 = 1;
  while ( 1 )
  {
    v8 += scnprintf(&v7[v8], 4096LL - v8, "%d. %s\n", v10, v9 + 16);
    if ( v8 == 4096 )
      break;
    v9 = *(const char **)v9;
    ++v10;
    if ( v9 == (const char *)&accounted_call_site_list )
      goto LABEL_6;
  }
  raw_spin_unlock_irqrestore(&accounted_call_site_lock, a4);
  v12 = -12;
LABEL_10:
  kfree(v7);
  return v12;
}
