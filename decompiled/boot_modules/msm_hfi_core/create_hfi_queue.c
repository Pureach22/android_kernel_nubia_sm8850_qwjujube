_QWORD *__fastcall create_hfi_queue(__int64 *a1)
{
  __int64 v1; // x30
  __int64 v2; // x4
  unsigned int v4; // w8
  int v5; // w9
  __int64 v6; // x20
  _QWORD *v7; // x0
  _QWORD *v8; // x19
  __int64 v9; // x9
  __int64 v10; // x0
  __int64 v11; // x4
  int v12; // w22
  _QWORD **v13; // x21
  int v14; // w23
  __int64 v15; // x0
  _QWORD **v16; // x8
  _QWORD *v17; // x1
  _QWORD *v18; // x0
  _QWORD *v19; // x22
  __int64 v20; // x30
  void *v21; // x0
  __int64 v22; // x2

  v2 = *a1;
  if ( !*a1 || !a1[2] || (v4 = *((_DWORD *)a1 + 6)) == 0 || (v5 = *((_DWORD *)a1 + 7)) == 0 )
  {
    printk(&unk_1CC05, "create_hfi_queue", 172, v1, v2);
    return nullptr;
  }
  if ( v4 != ((*((_DWORD *)a1 + 8) + 18 * v5 + 5) & -*((_DWORD *)a1 + 8)) + 8 * v5 + 6 )
  {
    printk(&unk_1E803, "create_hfi_queue", 178, v1, v4);
    return nullptr;
  }
  if ( (*((_BYTE *)a1 + 36) & 1) == 0 )
  {
    printk(&unk_1A2A7, "create_hfi_queue", 183, v1, v2);
    return nullptr;
  }
  v6 = v1;
  v7 = (_QWORD *)vzalloc_noprof(1096);
  v8 = v7;
  if ( !v7 )
    return v8;
  v9 = *a1;
  v7[121] = 0x200000001LL;
  v7[14] = v9;
  v7[119] = v7 + 119;
  v7[120] = v7 + 119;
  v7[123] = v7 + 123;
  v7[124] = v7 + 123;
  v7[1] = 0;
  _mutex_init(v7 + 127, "&qhandle->q_lock", &create_hfi_queue___key);
  v10 = vring_new_virtqueue(
          0,
          *((unsigned int *)a1 + 7),
          *((unsigned int *)a1 + 8),
          v8,
          0,
          0,
          a1[2],
          virtq_notify,
          0,
          a1[1]);
  v8[135] = v10;
  if ( !v10 )
  {
    v20 = v6;
    v21 = &unk_194FE;
    v22 = 206;
LABEL_29:
    printk(v21, "create_hfi_queue", v22, v20, v11);
    if ( v8[135] )
      vring_del_virtqueue();
    vfree(v8);
    return nullptr;
  }
  if ( (unsigned int)virtqueue_set_dma_premapped() )
  {
    v20 = v6;
    v21 = &unk_1A02A;
    v22 = 212;
    goto LABEL_29;
  }
  v12 = *((_DWORD *)a1 + 7);
  v13 = (_QWORD **)(v8 + 125);
  v8[125] = v8 + 125;
  v8[126] = v8 + 125;
  if ( v12 )
  {
    v14 = 0;
    _ReadStatusReg(SP_EL0);
    do
    {
      while ( 1 )
      {
        v15 = vzalloc_noprof(40);
        v16 = (_QWORD **)(v15 + 24);
        *(_QWORD *)(v15 + 24) = v15 + 24;
        if ( !v15 )
          v14 = -12;
        *(_QWORD *)(v15 + 32) = v16;
        v17 = (_QWORD *)v8[126];
        if ( v16 == v13 || v17 == v16 || (_QWORD **)*v17 != v13 )
          break;
        v8[126] = v16;
        *(_QWORD *)(v15 + 24) = v13;
        *(_QWORD *)(v15 + 32) = v17;
        *v17 = v16;
        if ( !--v12 )
          goto LABEL_20;
      }
      _list_add_valid_or_report(v15 + 24, v17, v8 + 125);
      --v12;
    }
    while ( v12 );
LABEL_20:
    if ( v14 )
    {
      v18 = *v13;
      if ( *v13 != v13 )
      {
        do
        {
          v19 = (_QWORD *)*v18;
          vfree(v18 - 3);
          v18 = v19;
        }
        while ( v19 != v13 );
      }
      v20 = v6;
      v21 = &unk_19535;
      v22 = 217;
      goto LABEL_29;
    }
  }
  return v8;
}
