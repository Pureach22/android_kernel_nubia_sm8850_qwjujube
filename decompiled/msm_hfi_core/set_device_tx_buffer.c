__int64 __fastcall set_device_tx_buffer(__int64 a1, unsigned int a2, _QWORD *a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  int v6; // w20
  int *v8; // x23
  unsigned int v9; // w22
  _QWORD *v10; // x25
  int v11; // w8
  __int64 v12; // x4
  _DWORD *v13; // x9
  __int64 v14; // x26
  unsigned int v15; // w0
  unsigned int v16; // w0
  __int64 v17; // x3
  void *v19; // x0
  __int64 v20; // x2
  __int64 v21; // x19
  unsigned int v22; // w22
  __int64 v23; // x23
  unsigned int v24; // w19
  unsigned int v25; // w19
  __int64 v26; // [xsp+0h] [xbp-10h]

  v6 = a4;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v21 = a1;
    v22 = a2;
    v23 = v5;
    printk(&unk_1E83A, "set_device_tx_buffer", 852, a4, a5);
    v5 = v23;
    a1 = v21;
    a2 = v22;
    if ( v22 == 3 )
      goto LABEL_3;
LABEL_31:
    printk(&unk_1E07D, "set_device_tx_buffer", 855, v5, a2);
    return 4294967274LL;
  }
  if ( a2 != 3 )
    goto LABEL_31;
LABEL_3:
  if ( !a1 || !a3 || !v6 || (v8 = *(int **)(a1 + 320)) == nullptr )
  {
    v19 = &unk_1905C;
    v20 = 864;
LABEL_29:
    printk(v19, "set_device_tx_buffer", v20, v5, a5);
    return 4294967274LL;
  }
  v9 = 0;
  v26 = v5;
  while ( 1 )
  {
    if ( !a3 || (v10 = (_QWORD *)*a3) == nullptr )
    {
      v5 = v26;
      v19 = &unk_1B44C;
      v20 = 873;
      goto LABEL_29;
    }
    v11 = *v8;
    v12 = *((unsigned int *)v10 + 6);
    if ( !*v8 )
      goto LABEL_35;
    v13 = v8 + 2;
    if ( v8[2] != (_DWORD)v12 )
    {
      if ( v11 == 1 )
        goto LABEL_35;
      v13 = v8 + 8;
      if ( v8[8] != (_DWORD)v12 )
      {
        if ( v11 == 2 )
          goto LABEL_35;
        v13 = v8 + 14;
        if ( v8[14] != (_DWORD)v12 )
        {
          if ( v11 == 3 )
            goto LABEL_35;
          v13 = v8 + 20;
          if ( v8[20] != (_DWORD)v12 )
            break;
        }
      }
    }
    v14 = *((_QWORD *)v13 + 2);
    if ( !v14 )
      goto LABEL_35;
    v15 = push_device_buffers_to_queue(
            *((_QWORD *)v13 + 2),
            *v10,
            *((unsigned int *)v10 + 7),
            *((unsigned int *)v10 + 4));
    if ( v15 )
    {
      v24 = v15;
      printk(&unk_1BBB8, "set_device_tx_buffer", 895, v26, v9);
      return v24;
    }
    v16 = set_param_hfi_queue(v14, 5u, 0, 0);
    if ( v16 )
    {
      v25 = v16;
      printk(&unk_1B818, "set_device_tx_buffer", 903, v26, a5);
      return v25;
    }
    if ( (~msm_hfi_core_debug_level & 0x10002) == 0 )
      printk(&unk_1F515, "set_device_tx_buffer", 910, *v10, v10[2]);
    ++v9;
    ++a3;
    if ( v6 == v9 )
    {
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1C28B, "set_device_tx_buffer", 915, v17, a5);
      return 0;
    }
  }
  if ( v11 == 4 )
  {
LABEL_35:
    printk(&unk_1E88C, "set_device_tx_buffer", 884, v26, v12);
    return 4294967274LL;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))push_device_buffers_to_queue)();
}
