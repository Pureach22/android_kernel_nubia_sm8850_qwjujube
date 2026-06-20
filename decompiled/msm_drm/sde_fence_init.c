__int64 __fastcall sde_fence_init(const char *a1, int a2)
{
  __int64 v4; // x21
  size_t v5; // x0
  unsigned __int64 v6; // x2
  __int64 v7; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v10; // x23
  __int64 (__fastcall *v11)(_QWORD, _QWORD, _QWORD); // x0

  if ( !a1 )
  {
    printk(&unk_253460, "sde_fence_init");
    return -22;
  }
  v4 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
  if ( !v4 )
  {
LABEL_13:
    printk(&unk_22F5A1, "sde_fence_init");
    return -12;
  }
  while ( 1 )
  {
    v5 = strnlen(a1, 0x18u);
    if ( v5 != -1 )
      break;
    _fortify_panic(2, -1, 0);
LABEL_12:
    _fortify_panic(7, 24, v6);
    StatusReg = _ReadStatusReg(SP_EL0);
    v10 = *(_QWORD *)(StatusReg + 80);
    v11 = _kmalloc_cache_noprof;
    *(_QWORD *)(StatusReg + 80) = &sde_fence_init__alloc_tag;
    v4 = _kmalloc_cache_noprof(v11, 3520, 88);
    *(_QWORD *)(StatusReg + 80) = v10;
    if ( !v4 )
      goto LABEL_13;
  }
  if ( v5 == 24 )
    v6 = 24;
  else
    v6 = v5 + 1;
  if ( v6 >= 0x19 )
    goto LABEL_12;
  sized_strscpy(v4 + 64, a1);
  *(_DWORD *)(v4 + 8) = a2;
  *(_DWORD *)(v4 + 12) = 1;
  v7 = dma_fence_context_alloc(1);
  *(_QWORD *)(v4 + 16) = 0;
  *(_QWORD *)(v4 + 24) = v7;
  *(_QWORD *)(v4 + 48) = v4 + 48;
  *(_QWORD *)(v4 + 56) = v4 + 48;
  return v4;
}
