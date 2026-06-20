__int64 __fastcall ipa3_register_intf_ext(const char *a1, unsigned int *a2, const void **a3, _BYTE *a4)
{
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x21
  size_t v22; // x0
  unsigned __int64 v23; // x2
  __int64 v24; // x1
  __int64 v25; // x0
  int v26; // w8
  size_t v27; // x22
  __int64 v28; // x0
  int v29; // w8
  size_t v30; // x20
  __int64 v31; // x0
  int v32; // w8
  _QWORD *v33; // x0
  __int64 v34; // x2
  _QWORD *v35; // x1
  unsigned __int64 StatusReg; // x24
  __int64 v37; // x25
  __int64 (__fastcall *v38)(_QWORD, _QWORD, _QWORD); // x0

  if ( !a1 || !a2 && !a3 && !a4 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_register_intf_ext__rs, "ipa3_register_intf_ext") )
      printk(&unk_3F82AD, "ipa3_register_intf_ext");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(
          v9,
          "ipa %s:%d invalid params name=%pK tx=%pK rx=%pK ext=%pK\n",
          "ipa3_register_intf_ext",
          83,
          a1,
          a2,
          a3,
          a4);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
      {
        ipc_log_string(
          v10,
          "ipa %s:%d invalid params name=%pK tx=%pK rx=%pK ext=%pK\n",
          "ipa3_register_intf_ext",
          83,
          a1,
          a2,
          a3,
          a4);
        return 4294967274LL;
      }
    }
    return 4294967274LL;
  }
  if ( a2 && *a2 >= 0x24 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_register_intf_ext__rs_2, "ipa3_register_intf_ext") )
      printk(&unk_3C6FC7, "ipa3_register_intf_ext");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d invalid tx num_props=%d max=%d\n", "ipa3_register_intf_ext", 89, *a2, 35);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d invalid tx num_props=%d max=%d\n", "ipa3_register_intf_ext", 89, *a2, 35);
        return 4294967274LL;
      }
    }
    return 4294967274LL;
  }
  if ( a3 && *(_DWORD *)a3 >= 0x24u )
  {
    if ( (unsigned int)__ratelimit(&ipa3_register_intf_ext__rs_5, "ipa3_register_intf_ext") )
      printk(&unk_3A3A18, "ipa3_register_intf_ext");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(
          v16,
          "ipa %s:%d invalid rx num_props=%d max=%d\n",
          "ipa3_register_intf_ext",
          95,
          *(_DWORD *)a3,
          35);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
      {
        ipc_log_string(
          v17,
          "ipa %s:%d invalid rx num_props=%d max=%d\n",
          "ipa3_register_intf_ext",
          95,
          *(unsigned int *)a3,
          35);
        return 4294967274LL;
      }
    }
    return 4294967274LL;
  }
  if ( a4 && *((_DWORD *)a4 + 2) >= 0x24u )
  {
    if ( (unsigned int)__ratelimit(&ipa3_register_intf_ext__rs_8, "ipa3_register_intf_ext") )
      printk(&unk_3D5B97, "ipa3_register_intf_ext");
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(
          v19,
          "ipa %s:%d invalid ext num_props=%d max=%d\n",
          "ipa3_register_intf_ext",
          101,
          *((_DWORD *)a4 + 2),
          35);
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
      {
        ipc_log_string(
          v20,
          "ipa %s:%d invalid ext num_props=%d max=%d\n",
          "ipa3_register_intf_ext",
          101,
          *((unsigned int *)a4 + 2),
          35);
        return 4294967274LL;
      }
    }
    return 4294967274LL;
  }
  v21 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 96);
  if ( !v21 )
    return 4294967284LL;
  while ( 1 )
  {
    v22 = strnlen(a1, 0x20u);
    if ( v22 != -1 )
      break;
    _fortify_panic(2, -1, 0);
LABEL_63:
    _fortify_panic(7, 32, v23);
    _fortify_panic(17, a2, a2);
    _fortify_panic(17, a3, a3);
    StatusReg = _ReadStatusReg(SP_EL0);
    v37 = *(_QWORD *)(StatusReg + 80);
    v38 = _kmalloc_cache_noprof;
    *(_QWORD *)(StatusReg + 80) = &ipa3_register_intf_ext__alloc_tag;
    v21 = _kmalloc_cache_noprof(v38, 3520, 96);
    *(_QWORD *)(StatusReg + 80) = v37;
    if ( !v21 )
      return 4294967284LL;
  }
  if ( v22 == 32 )
    v23 = 32;
  else
    v23 = v22 + 1;
  if ( v23 >= 0x21 )
    goto LABEL_63;
  sized_strscpy(v21, a1);
  if ( a2 )
  {
    v24 = 200 * *a2;
    *(_DWORD *)(v21 + 48) = *a2;
    v25 = kmemdup_noprof(*((_QWORD *)a2 + 1), v24, 3264);
    *(_QWORD *)(v21 + 64) = v25;
    if ( !v25 )
      goto LABEL_68;
  }
  if ( !a3 )
    goto LABEL_52;
  v26 = *(_DWORD *)a3;
  v27 = (unsigned int)(164 * *(_DWORD *)a3);
  *(_DWORD *)(v21 + 52) = *(_DWORD *)a3;
  v28 = kmemdup_noprof(a3[1], (unsigned int)(164 * v26), 3264);
  *(_QWORD *)(v21 + 72) = v28;
  if ( !v28 )
  {
LABEL_67:
    kfree(*(_QWORD *)(v21 + 64));
LABEL_68:
    kfree(v21);
    return 4294967284LL;
  }
  memcpy(*(void **)(v21 + 72), a3[1], v27);
LABEL_52:
  if ( !a4 )
    goto LABEL_56;
  v29 = *((_DWORD *)a4 + 2);
  v30 = (unsigned int)(216 * v29);
  *(_DWORD *)(v21 + 56) = v29;
  v31 = kmemdup_noprof(*((_QWORD *)a4 + 2), v30, 3264);
  *(_QWORD *)(v21 + 80) = v31;
  if ( !v31 )
  {
    kfree(*(_QWORD *)(v21 + 72));
    goto LABEL_67;
  }
  memcpy(*(void **)(v21 + 80), *((const void **)a4 + 2), v30);
  if ( *a4 != 1 )
  {
LABEL_56:
    v32 = 33;
    goto LABEL_57;
  }
  v32 = *((_DWORD *)a4 + 1);
LABEL_57:
  *(_DWORD *)(v21 + 88) = v32;
  mutex_lock(ipa3_ctx + 29472);
  v33 = (_QWORD *)(v21 + 32);
  v34 = ipa3_ctx + 32056;
  v35 = *(_QWORD **)(ipa3_ctx + 32064);
  if ( v21 + 32 == ipa3_ctx + 32056 || v35 == v33 || *v35 != v34 )
  {
    _list_add_valid_or_report(v33, v35);
  }
  else
  {
    *(_QWORD *)(ipa3_ctx + 32064) = v33;
    *(_QWORD *)(v21 + 32) = v34;
    *(_QWORD *)(v21 + 40) = v35;
    *v35 = v33;
  }
  mutex_unlock(ipa3_ctx + 29472);
  return 0;
}
