__int64 __fastcall synx_native_create_core(unsigned __int64 a1, unsigned __int64 a2, __int64 a3)
{
  _QWORD *v3; // x19
  int *v4; // x8
  int v5; // w23
  unsigned __int64 v9; // x0
  __int64 v10; // x4
  __int64 v11; // x5
  unsigned __int64 v12; // x21
  int v13; // w0
  __int64 v14; // x5
  _QWORD *v15; // x0
  int v16; // w0
  int v17; // w21
  int inited; // w0
  __int64 v19; // x5

  LODWORD(v3) = -22;
  if ( !a1 )
    return (unsigned int)v3;
  if ( a1 > 0xFFFFFFFFFFFFF000LL )
    return (unsigned int)v3;
  LODWORD(v3) = -22;
  if ( !a2 )
    return (unsigned int)v3;
  if ( a2 > 0xFFFFFFFFFFFFF000LL )
    return (unsigned int)v3;
  v4 = *(int **)(a2 + 8);
  LODWORD(v3) = -22;
  if ( !v4 || (unsigned __int64)v4 > 0xFFFFFFFFFFFFF000LL )
    return (unsigned int)v3;
  v5 = *v4;
  v9 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 368);
  v12 = v9;
  if ( v9 && v9 < 0xFFFFFFFFFFFFF001LL )
  {
    v13 = ((__int64 (__fastcall *)(unsigned __int64, unsigned __int64, void *, _QWORD, __int64))synx_util_init_coredata)(
            v9,
            a2,
            &synx_fence_ops,
            *(_QWORD *)(a1 + 112),
            a3);
    if ( v13 )
    {
      LODWORD(v3) = v13;
      if ( (synx_debug & 1) != 0 )
        printk(&unk_29F4E, &unk_29207, "synx_native_create_core", 297, *(_QWORD *)(a1 + 104), v14);
      kfree(v12);
      return (unsigned int)v3;
    }
    v15 = (_QWORD *)synx_util_insert_to_map(v12, **(unsigned int **)(a2 + 8), 0, v5 != 0);
    v3 = v15;
    if ( !v15 || (unsigned __int64)v15 >= 0xFFFFFFFFFFFFF001LL )
    {
      synx_util_put_object(v12);
      return (unsigned int)v3;
    }
    v16 = synx_util_add_callback(*v15, **(unsigned int **)(a2 + 8));
    if ( v16 )
    {
      v17 = v16;
LABEL_17:
      synx_util_release_map_entry(v3);
      LODWORD(v3) = v17;
      return (unsigned int)v3;
    }
    inited = synx_util_init_handle(a1, *v3, *(_QWORD *)(a2 + 8), v3);
    if ( inited < 0 )
    {
      v17 = inited;
      if ( (synx_debug & 1) != 0 )
        printk(&unk_284D4, &unk_29207, "synx_native_create_core", 322, *(_QWORD *)(a1 + 104), v19);
      goto LABEL_17;
    }
    if ( (synx_debug & 0x80) != 0 )
      printk(&unk_2666D, &unk_25D36, "synx_native_create_core", 330, *(_QWORD *)(a1 + 104), **(unsigned int **)(a2 + 8));
    LODWORD(v3) = 0;
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2A5C1, &unk_29207, "synx_native_create_core", 288, v10, v11);
    LODWORD(v3) = -12;
  }
  return (unsigned int)v3;
}
