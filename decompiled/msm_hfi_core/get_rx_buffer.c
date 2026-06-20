__int64 __fastcall get_rx_buffer(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  int *v7; // x26
  int v8; // w27
  unsigned int v9; // w21
  int v10; // w8
  _DWORD *v11; // x9
  __int64 v12; // x0
  unsigned int param_hfi_queue; // w0
  __int64 result; // x0
  __int64 v15; // x3
  __int64 v16; // x5
  __int64 v17; // x4
  int v18; // w8
  __int64 v19; // x20
  unsigned int v20; // w21
  __int64 v21; // x22
  unsigned int v22; // w19
  __int64 v23; // [xsp+8h] [xbp-28h]
  __int64 v24; // [xsp+10h] [xbp-20h] BYREF
  __int64 v25; // [xsp+18h] [xbp-18h]
  __int64 v26; // [xsp+20h] [xbp-10h]
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v26 = 0;
  v24 = 0;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
      goto LABEL_33;
  }
  else
  {
    v19 = a1;
    v20 = a2;
    v21 = v5;
    printk(&unk_1E83A, "get_rx_buffer", 195, a4, a5);
    v5 = v21;
    a1 = v19;
    a2 = v20;
    if ( !v19 )
      goto LABEL_33;
  }
  if ( !a3 )
    goto LABEL_33;
  if ( a2 >= 4 )
  {
LABEL_23:
    __break(0x5512u);
LABEL_24:
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1B183, "get_rx_buffer", 232, a4, a5);
    result = 4294967191LL;
    goto LABEL_27;
  }
  v7 = *(int **)(a1 + 176LL * a2 + 144);
  if ( !v7 )
  {
LABEL_33:
    printk(&unk_1905C, "get_rx_buffer", 199, v5, a5);
    result = 4294967274LL;
    goto LABEL_27;
  }
  v8 = 0;
  v9 = 0;
  v23 = v5;
  while ( 1 )
  {
    v10 = *v7;
    if ( v8 == *v7 )
      goto LABEL_24;
    if ( v10 )
      break;
LABEL_8:
    if ( ++v9 == 4 )
      goto LABEL_24;
  }
  v11 = v7 + 2;
  if ( v9 != v7[2] )
  {
    if ( v10 == 1 )
      goto LABEL_8;
    v11 = v7 + 8;
    if ( v9 != v7[8] )
    {
      if ( v10 == 2 )
        goto LABEL_8;
      v11 = v7 + 14;
      if ( v9 != v7[14] )
      {
        if ( v10 == 3 )
          goto LABEL_8;
        v11 = v7 + 20;
        if ( v9 != v7[20] )
        {
          if ( v10 != 4 )
            goto LABEL_23;
          goto LABEL_8;
        }
      }
    }
  }
  v12 = *((_QWORD *)v11 + 2);
  if ( !v12 )
    goto LABEL_8;
  param_hfi_queue = get_param_hfi_queue(v12, 1u, (__int64)&v24, 0x18u);
  if ( param_hfi_queue == -105 )
  {
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1AEF8, "get_rx_buffer", 223, v9, a5);
    ++v8;
    goto LABEL_8;
  }
  if ( !param_hfi_queue )
  {
    v15 = v24;
    v16 = v25;
    v17 = (unsigned int)v26;
    *(_DWORD *)(a3 + 24) = v9;
    *(_QWORD *)a3 = v15;
    *(_QWORD *)(a3 + 8) = v16;
    v18 = msm_hfi_core_debug_level;
    *(_QWORD *)(a3 + 16) = v17;
    if ( (~v18 & 0x10002) != 0 )
    {
      if ( (~v18 & 0x10001) != 0 )
      {
LABEL_31:
        result = 0;
        goto LABEL_27;
      }
    }
    else
    {
      printk(&unk_1BB6E, "get_rx_buffer", 244, v15, v17);
      if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
        goto LABEL_31;
    }
    printk(&unk_1C28B, "get_rx_buffer", 245, v15, v17);
    goto LABEL_31;
  }
  v22 = param_hfi_queue;
  printk(&unk_1A76A, "get_rx_buffer", 225, v23, v9);
  result = v22;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
