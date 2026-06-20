__int64 __fastcall put_tx_buffer(__int64 a1, unsigned int a2, _QWORD *a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  int v6; // w20
  int *v8; // x28
  unsigned int v9; // w22
  _QWORD *v10; // x25
  int v11; // w8
  __int64 v12; // x4
  _DWORD *v13; // x9
  __int64 v14; // x0
  unsigned int v15; // w0
  __int64 v16; // x3
  void *v18; // x0
  __int64 v19; // x2
  __int64 v20; // x19
  unsigned int v21; // w22
  __int64 v22; // x23
  unsigned int v23; // w19
  __int64 v24; // [xsp+0h] [xbp-10h]

  v6 = a4;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a1 )
      goto LABEL_3;
LABEL_28:
    v18 = &unk_1905C;
    v19 = 309;
LABEL_29:
    printk(v18, "put_tx_buffer", v19, v5, a5);
    return 4294967274LL;
  }
  v20 = a1;
  v21 = a2;
  v22 = v5;
  printk(&unk_1E83A, "put_tx_buffer", 305, a4, a5);
  v5 = v22;
  a1 = v20;
  a2 = v21;
  if ( !v20 )
    goto LABEL_28;
LABEL_3:
  if ( !a3 || !v6 )
    goto LABEL_28;
  if ( a2 >= 4 )
  {
LABEL_34:
    __break(0x5512u);
    return ((__int64 (*)(void))push_buffers_to_buff_pool)();
  }
  v8 = *(int **)(a1 + 176LL * a2 + 144);
  if ( !v8 )
    goto LABEL_28;
  v9 = 0;
  v24 = v5;
  do
  {
    if ( !a3 || (v10 = (_QWORD *)*a3) == nullptr )
    {
      v5 = v24;
      v18 = &unk_1B44C;
      v19 = 317;
      goto LABEL_29;
    }
    v11 = *v8;
    v12 = *((unsigned int *)v10 + 6);
    if ( !*v8 )
      goto LABEL_32;
    v13 = v8 + 2;
    if ( v8[2] != (_DWORD)v12 )
    {
      if ( v11 == 1 )
        goto LABEL_32;
      v13 = v8 + 8;
      if ( v8[8] != (_DWORD)v12 )
      {
        if ( v11 == 2 )
          goto LABEL_32;
        v13 = v8 + 14;
        if ( v8[14] != (_DWORD)v12 )
        {
          if ( v11 == 3 )
            goto LABEL_32;
          v13 = v8 + 20;
          if ( v8[20] != (_DWORD)v12 )
          {
            if ( v11 != 4 )
              goto LABEL_34;
LABEL_32:
            printk(&unk_1E88C, "put_tx_buffer", 328, v24, v12);
            return 4294967274LL;
          }
        }
      }
    }
    v14 = *((_QWORD *)v13 + 1);
    if ( !v14 )
      goto LABEL_32;
    v15 = push_buffers_to_buff_pool(v14, *v10, v10[1], *((unsigned int *)v10 + 4));
    if ( v15 )
    {
      v23 = v15;
      printk(&unk_1CD12, "put_tx_buffer", 337, v24, v9);
      return v23;
    }
    if ( (~msm_hfi_core_debug_level & 0x10002) == 0 )
      printk(&unk_1BB6E, "put_tx_buffer", 342, *v10, v10[2]);
    ++v9;
    ++a3;
  }
  while ( v6 != v9 );
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "put_tx_buffer", 347, v16, a5);
  return 0;
}
