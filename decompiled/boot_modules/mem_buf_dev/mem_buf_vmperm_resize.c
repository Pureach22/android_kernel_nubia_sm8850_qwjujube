__int64 __fastcall mem_buf_vmperm_resize(__int64 a1, unsigned int a2)
{
  size_t v2; // x27
  const void *v3; // x21
  const void *v4; // x23
  unsigned __int64 v7; // x24
  void *v8; // x22
  void *v9; // x26
  unsigned __int64 StatusReg; // x25
  __int64 v12; // x26

  v2 = *(unsigned int *)(a1 + 52);
  if ( (unsigned int)v2 >= a2 )
    return 0;
  v4 = *(const void **)(a1 + 32);
  v3 = *(const void **)(a1 + 40);
  v7 = 4LL * a2;
  v8 = (void *)_kmalloc_noprof(v7, 3520);
  if ( !v8 )
    return 4294967284LL;
  while ( 1 )
  {
    v9 = (void *)_kmalloc_noprof(4LL * a2, 3520);
    if ( !v9 )
      break;
    v2 *= 4LL;
    if ( *(_QWORD *)(a1 + 32) )
    {
      if ( v7 < v2 )
      {
        _fortify_panic(17, v7, v2);
        goto LABEL_13;
      }
      memcpy(v8, v4, v2);
      kfree(v4);
    }
    if ( !*(_QWORD *)(a1 + 40) )
      goto LABEL_10;
    if ( 4 * (unsigned __int64)a2 >= v2 )
    {
      memcpy(v9, v3, v2);
      kfree(v3);
LABEL_10:
      *(_QWORD *)(a1 + 32) = v8;
      *(_QWORD *)(a1 + 40) = v9;
      *(_DWORD *)(a1 + 52) = a2;
      return 0;
    }
LABEL_13:
    _fortify_panic(17, 4LL * a2, v2);
    v7 = 4LL * a2;
    StatusReg = _ReadStatusReg(SP_EL0);
    v12 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &mem_buf_vmperm_resize__alloc_tag;
    v8 = (void *)_kmalloc_noprof(v7, 3520);
    *(_QWORD *)(StatusReg + 80) = v12;
    if ( !v8 )
      return 4294967284LL;
  }
  kfree(v8);
  return 4294967284LL;
}
