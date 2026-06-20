__int64 __fastcall get_device_tx_buffer(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  int *v7; // x8
  int v8; // w9
  __int64 v9; // x4
  _DWORD *v10; // x10
  _DWORD *v11; // x8
  int v12; // t1
  __int64 v13; // x0
  __int64 v14; // x20
  unsigned int param_hfi_queue; // w0
  __int64 v16; // x3
  __int64 v17; // x5
  __int64 v18; // x4
  int v19; // w6
  int v20; // w8
  __int64 result; // x0
  __int64 v22; // x20
  unsigned int v23; // w23
  __int64 v24; // x24
  unsigned int v25; // w19
  __int64 v26; // [xsp+0h] [xbp-20h] BYREF
  __int64 v27; // [xsp+8h] [xbp-18h]
  __int64 v28; // [xsp+10h] [xbp-10h]
  __int64 v29; // [xsp+18h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  v26 = 0;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v22 = a1;
    v23 = a2;
    v24 = v5;
    printk(&unk_1E83A, "get_device_tx_buffer", 1010, a4, a5);
    a1 = v22;
    a2 = v23;
    v5 = v24;
    if ( v23 == 3 )
      goto LABEL_3;
LABEL_23:
    printk(&unk_1E07D, "get_device_tx_buffer", 1013, v5, a2);
    result = 4294967274LL;
    goto LABEL_20;
  }
  if ( a2 != 3 )
    goto LABEL_23;
LABEL_3:
  if ( !a1 || !a3 || (v7 = *(int **)(a1 + 320)) == nullptr )
  {
    printk(&unk_1905C, "get_device_tx_buffer", 1023, v5, a5);
    result = 4294967274LL;
    goto LABEL_20;
  }
  v8 = *v7;
  v9 = *(unsigned int *)(a3 + 24);
  if ( !*v7 )
    goto LABEL_28;
  v10 = v7 + 2;
  if ( v7[2] == (_DWORD)v9 )
    goto LABEL_15;
  if ( v8 == 1 )
    goto LABEL_28;
  v10 = v7 + 8;
  if ( v7[8] == (_DWORD)v9 )
    goto LABEL_15;
  if ( v8 == 2 )
    goto LABEL_28;
  v10 = v7 + 14;
  if ( v7[14] == (_DWORD)v9 )
  {
LABEL_15:
    v13 = *((_QWORD *)v10 + 2);
    if ( v13 )
    {
      v14 = v5;
      param_hfi_queue = get_param_hfi_queue(v13, 3u, (__int64)&v26, 0x18u);
      if ( param_hfi_queue )
      {
        v25 = param_hfi_queue;
        printk(&unk_1E509, "get_device_tx_buffer", 1043, v14, param_hfi_queue);
        result = v25;
        goto LABEL_20;
      }
      v16 = v26;
      v17 = v27;
      v18 = (unsigned int)v28;
      v19 = HIDWORD(v28);
      *(_QWORD *)a3 = v26;
      *(_QWORD *)(a3 + 8) = v17;
      v20 = msm_hfi_core_debug_level;
      *(_QWORD *)(a3 + 16) = v18;
      *(_DWORD *)(a3 + 28) = v19;
      if ( (~v20 & 0x10002) != 0 )
      {
        if ( (~v20 & 0x10001) != 0 )
        {
LABEL_19:
          result = 0;
LABEL_20:
          _ReadStatusReg(SP_EL0);
          return result;
        }
      }
      else
      {
        printk(&unk_1F515, "get_device_tx_buffer", 1056, v16, v18);
        if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
          goto LABEL_19;
      }
      printk(&unk_1C28B, "get_device_tx_buffer", 1058, v16, v18);
      goto LABEL_19;
    }
LABEL_28:
    printk(&unk_1E88C, "get_device_tx_buffer", 1034, v5, v9);
    result = 4294967274LL;
    goto LABEL_20;
  }
  if ( v8 == 3 )
    goto LABEL_28;
  v12 = v7[20];
  v11 = v7 + 20;
  if ( v12 == (_DWORD)v9 )
  {
    v10 = v11;
    goto LABEL_15;
  }
  if ( v8 == 4 )
    goto LABEL_28;
  __break(0x5512u);
  return put_device_rx_buffer();
}
