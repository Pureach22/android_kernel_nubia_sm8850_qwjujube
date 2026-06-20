__int64 __fastcall synx_util_add_callback(unsigned __int64 a1, int a2)
{
  __int64 result; // x0
  unsigned __int64 v5; // x0
  __int64 v6; // x4
  __int64 v7; // x5
  unsigned __int64 v8; // x20
  _QWORD *v10; // x22
  _QWORD *v11; // x21
  __int64 v12; // x0
  __int64 v13; // x9
  _QWORD *v14; // x2
  _QWORD *v15; // x1
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4
  __int64 v20; // x5
  unsigned int v21; // w21
  unsigned int object_status; // w0
  unsigned int v23; // w0
  unsigned int v24; // w21
  __int64 v25; // x1
  unsigned int v31; // w8

  result = 4294967274LL;
  if ( !a1 || a1 > 0xFFFFFFFFFFFFF000LL )
    return result;
  v5 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
  v8 = v5;
  if ( !v5 || v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_276EF, &unk_29207, "synx_util_add_callback", 162, v6, v7);
    return 4294967284LL;
  }
  _X0 = (unsigned int *)(a1 + 120);
  *(_DWORD *)v8 = a2;
  *(_DWORD *)(v8 + 24) = 2;
  *(_QWORD *)(v8 + 16) = a1;
  __asm { PRFM            #0x11, [X0] }
  do
    v31 = __ldxr(_X0);
  while ( __stxr(v31 + 1, _X0) );
  if ( !v31 )
  {
    v25 = 2;
LABEL_31:
    refcount_warn_saturate(_X0, v25);
    v10 = *(_QWORD **)(a1 + 64);
    if ( !v10 )
    {
LABEL_32:
      __break(0x800u);
      v24 = -22;
      if ( (synx_debug & 1) != 0 )
        printk(&unk_2831D, &unk_29207, "synx_util_add_callback", 197, *(_QWORD *)(a1 + 64), 4294967274LL);
LABEL_21:
      synx_util_put_object(a1);
      kfree(v8);
      return v24;
    }
    goto LABEL_8;
  }
  if ( (((v31 + 1) | v31) & 0x80000000) != 0 )
  {
    v25 = 1;
    goto LABEL_31;
  }
  v10 = *(_QWORD **)(a1 + 64);
  if ( !v10 )
    goto LABEL_32;
LABEL_8:
  v11 = (_QWORD *)(v8 + 32);
  v12 = raw_spin_lock_irqsave(*v10);
  v13 = v12;
  if ( (v10[6] & 1) != 0 )
  {
    *(_QWORD *)(v8 + 32) = v8 + 32;
    *(_QWORD *)(v8 + 40) = v11;
    raw_spin_unlock_irqrestore(*v10, v12);
    if ( (*(_BYTE *)(a1 + 124) & 2) != 0
      && (v21 = *(_DWORD *)(a1 + 344),
          object_status = synx_util_get_object_status(a1, v16, v17, v18, v19, v20),
          (v23 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))synx_global_update_status_core)(v21, object_status, 0)) != 0) )
    {
      v24 = v23;
      if ( (synx_debug & 1) != 0 )
        printk(&unk_27072, &unk_29207, "synx_util_add_callback", 190, *(unsigned int *)(a1 + 344), *(_QWORD *)(a1 + 64));
    }
    else
    {
      v24 = 0;
    }
    goto LABEL_21;
  }
  v14 = v10 + 2;
  *(_QWORD *)(v8 + 48) = synx_fence_callback;
  v15 = (_QWORD *)v10[3];
  if ( v10 + 2 == v11 || v15 == v11 || (_QWORD *)*v15 != v14 )
  {
    _list_add_valid_or_report(v8 + 32, v15);
  }
  else
  {
    v10[3] = v11;
    *(_QWORD *)(v8 + 32) = v14;
    *(_QWORD *)(v8 + 40) = v15;
    *v15 = v11;
  }
  raw_spin_unlock_irqrestore(*v10, v13);
  *(_QWORD *)(a1 + 352) = v8;
  if ( (synx_debug & 0x10) != 0 )
    printk(&unk_27BD7, "verb", "synx_util_add_callback", 206, v8, *(_QWORD *)(a1 + 64));
  return 0;
}
