__int64 __fastcall put_rx_buffer(_QWORD *a1, unsigned int a2, __int64 **a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x13
  __int64 v6; // x30
  int v7; // w20
  int *v9; // x19
  unsigned int v10; // w22
  __int64 *v11; // x25
  int v12; // w8
  __int64 v13; // x4
  _DWORD *v14; // x9
  __int64 v15; // x26
  unsigned int v16; // w0
  __int64 v17; // x3
  void *v19; // x0
  __int64 v20; // x2
  _QWORD *v21; // x19
  unsigned int v22; // w22
  __int64 v23; // x23
  unsigned int v24; // w19
  void *v25; // x0
  __int64 v26; // x2
  __int64 v27; // [xsp+0h] [xbp-10h]

  v7 = a4;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
      goto LABEL_29;
  }
  else
  {
    v21 = a1;
    v22 = a2;
    v23 = v6;
    printk(&unk_1E83A, "put_rx_buffer", 359, a4, a5);
    v6 = v23;
    a1 = v21;
    a2 = v22;
    if ( !v21 )
      goto LABEL_29;
  }
  if ( !a3 || !v7 )
  {
LABEL_29:
    v19 = &unk_1905C;
    v20 = 363;
LABEL_30:
    printk(v19, "put_rx_buffer", v20, v6, a5);
    return 4294967274LL;
  }
  if ( a2 < 4 )
  {
    v9 = (int *)a1[22 * a2 + 18];
    if ( v9 )
    {
      v10 = 0;
      v27 = v6;
      while ( 1 )
      {
        if ( !a3 || (v11 = *a3) == nullptr )
        {
          v6 = v27;
          v19 = &unk_1B44C;
          v20 = 371;
          goto LABEL_30;
        }
        v12 = *v9;
        v13 = *((unsigned int *)v11 + 6);
        if ( !*v9 )
          goto LABEL_35;
        v14 = v9 + 2;
        if ( v9[2] != (_DWORD)v13 )
        {
          if ( v12 == 1 )
            goto LABEL_35;
          v14 = v9 + 8;
          if ( v9[8] != (_DWORD)v13 )
          {
            if ( v12 == 2 )
              goto LABEL_35;
            v14 = v9 + 14;
            if ( v9[14] != (_DWORD)v13 )
            {
              if ( v12 == 3 )
                goto LABEL_35;
              v14 = v9 + 20;
              if ( v9[20] != (_DWORD)v13 )
                break;
            }
          }
        }
        v15 = *((_QWORD *)v14 + 2);
        if ( !v15 )
          goto LABEL_35;
        v16 = push_buffers_to_fw_queue(*((_QWORD *)v14 + 2), *v11, v11[1], *((unsigned int *)v11 + 4), 1);
        if ( v16 )
        {
          v24 = v16;
          v25 = &unk_1AF37;
          v26 = 392;
LABEL_33:
          printk(v25, "put_rx_buffer", v26, v27, v10);
          return v24;
        }
        a1 = (_QWORD *)set_param_hfi_queue(v15, 5u, 0, 0);
        if ( (_DWORD)a1 )
        {
          v24 = (unsigned int)a1;
          v25 = &unk_18DF9;
          v26 = 399;
          goto LABEL_33;
        }
        if ( (~msm_hfi_core_debug_level & 0x10002) == 0 )
          a1 = (_QWORD *)printk(&unk_1BB6E, "put_rx_buffer", 404, *v11, v11[2]);
        ++v10;
        ++a3;
        if ( v7 == v10 )
        {
          if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
            printk(&unk_1C28B, "put_rx_buffer", 409, v17, a5);
          return 0;
        }
      }
      if ( v12 != 4 )
        goto LABEL_37;
LABEL_35:
      printk(&unk_1E88C, "put_rx_buffer", 382, v27, v13);
      return 4294967274LL;
    }
    goto LABEL_29;
  }
LABEL_37:
  __break(0x5512u);
  *a1 = v5;
  return get_queue_size_req((char *)a1 + 217);
}
