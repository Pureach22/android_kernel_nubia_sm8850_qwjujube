__int64 __fastcall put_device_rx_buffer(__int64 a1, __int64 a2, _QWORD **a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x30
  int v7; // w20
  _QWORD **v8; // x21
  int *v9; // x23
  unsigned int v10; // w22
  _QWORD *v11; // x25
  int v12; // w8
  __int64 v13; // x4
  _DWORD *v14; // x9
  __int64 v15; // x26
  unsigned int v16; // w0
  void *v18; // x0
  __int64 v19; // x2
  __int64 v20; // x19
  unsigned int v21; // w22
  __int64 v22; // x23
  unsigned int v23; // w19
  void *v24; // x0
  __int64 v25; // x2
  __int64 v26; // [xsp+0h] [xbp-10h]

  v7 = a4;
  v8 = a3;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v20 = a1;
    v21 = a2;
    v22 = v6;
    printk(&unk_1E83A, "put_device_rx_buffer", 1070, a4, a5);
    v6 = v22;
    a1 = v20;
    a2 = v21;
    if ( v21 == 3 )
      goto LABEL_3;
LABEL_31:
    printk(&unk_1E07D, "put_device_rx_buffer", 1073, v6, (unsigned int)a2);
    return 4294967274LL;
  }
  if ( (_DWORD)a2 != 3 )
    goto LABEL_31;
LABEL_3:
  if ( !a1 || !v8 || !v7 || (v9 = *(int **)(a1 + 320)) == nullptr )
  {
    v18 = &unk_1905C;
    v19 = 1082;
LABEL_29:
    printk(v18, "put_device_rx_buffer", v19, v6, a5);
    return 4294967274LL;
  }
  v10 = 0;
  v26 = v6;
  while ( 1 )
  {
    if ( !v8 || (v11 = *v8) == nullptr )
    {
      v6 = v26;
      v18 = &unk_1B44C;
      v19 = 1091;
      goto LABEL_29;
    }
    v12 = *v9;
    v13 = *((unsigned int *)v11 + 6);
    if ( !*v9 )
      goto LABEL_36;
    v14 = v9 + 2;
    if ( v9[2] != (_DWORD)v13 )
    {
      if ( v12 == 1 )
        goto LABEL_36;
      v14 = v9 + 8;
      if ( v9[8] != (_DWORD)v13 )
      {
        if ( v12 == 2 )
          goto LABEL_36;
        v14 = v9 + 14;
        if ( v9[14] != (_DWORD)v13 )
        {
          if ( v12 == 3 )
            goto LABEL_36;
          v14 = v9 + 20;
          if ( v9[20] != (_DWORD)v13 )
            break;
        }
      }
    }
    v15 = *((_QWORD *)v14 + 1);
    if ( !v15 )
      goto LABEL_36;
    v16 = push_device_buffers_to_queue(
            *((_QWORD *)v14 + 1),
            *v11,
            *((_DWORD *)v11 + 7),
            *((unsigned int *)v11 + 4),
            v13);
    if ( v16 )
    {
      v23 = v16;
      v24 = &unk_1BBB8;
      v25 = 1113;
LABEL_34:
      printk(v24, "put_device_rx_buffer", v25, v26, v10);
      return v23;
    }
    a1 = set_param_hfi_queue(v15, 5u, 0, 0);
    if ( (_DWORD)a1 )
    {
      v23 = a1;
      v24 = &unk_18DF9;
      v25 = 1120;
      goto LABEL_34;
    }
    if ( (~msm_hfi_core_debug_level & 0x10002) == 0 )
      a1 = printk(&unk_1A7AB, "put_device_rx_buffer", 1127, *v11, v11[2]);
    ++v10;
    ++v8;
    if ( v7 == v10 )
    {
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1C28B, "put_device_rx_buffer", 1132, a4, a5);
      return 0;
    }
  }
  if ( v12 == 4 )
  {
LABEL_36:
    printk(&unk_1E88C, "put_device_rx_buffer", 1102, v26, v13);
    return 4294967274LL;
  }
  __break(0x5512u);
  return submit_all_buffers(a1, a2, a3, a4, v13, a6);
}
