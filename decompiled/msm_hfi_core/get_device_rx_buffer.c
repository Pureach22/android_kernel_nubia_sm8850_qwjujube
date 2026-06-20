__int64 __fastcall get_device_rx_buffer(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
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
  __int64 v15; // x5
  int v16; // w6
  int v17; // w8
  __int64 v18; // x20
  unsigned int v19; // w21
  __int64 v20; // x22
  unsigned int v21; // w19
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
    if ( a2 == 3 )
      goto LABEL_3;
LABEL_36:
    printk(&unk_1E07D, "get_device_rx_buffer", 933, v5, a2);
    result = 4294967274LL;
    goto LABEL_29;
  }
  v18 = a1;
  v19 = a2;
  v20 = v5;
  printk(&unk_1E83A, "get_device_rx_buffer", 930, a4, a5);
  v5 = v20;
  a1 = v18;
  a2 = v19;
  if ( v19 != 3 )
    goto LABEL_36;
LABEL_3:
  if ( !a1 || !a3 || (v7 = *(int **)(a1 + 320)) == nullptr )
  {
    printk(&unk_1905C, "get_device_rx_buffer", 942, v5, a5);
    result = 4294967274LL;
    goto LABEL_29;
  }
  v8 = 0;
  v9 = 0;
  v23 = v5;
  while ( 1 )
  {
    v10 = *v7;
    if ( v8 == *v7 )
      goto LABEL_24;
    if ( !v10 )
      goto LABEL_8;
    v11 = v7 + 2;
    if ( v9 == v7[2] )
      break;
    if ( v10 == 1 )
      goto LABEL_8;
    v11 = v7 + 8;
    if ( v9 == v7[8] )
      break;
    if ( v10 == 2 )
      goto LABEL_8;
    v11 = v7 + 14;
    if ( v9 == v7[14] )
      break;
    if ( v10 == 3 )
      goto LABEL_8;
    v11 = v7 + 20;
    if ( v9 == v7[20] )
      break;
    if ( v10 != 4 )
    {
      __break(0x5512u);
LABEL_24:
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1B183, "get_device_rx_buffer", 980, a4, a5);
      result = 4294967191LL;
      goto LABEL_27;
    }
LABEL_8:
    if ( ++v9 == 4 )
      goto LABEL_24;
  }
  v12 = *((_QWORD *)v11 + 1);
  if ( !v12 )
    goto LABEL_8;
  param_hfi_queue = get_param_hfi_queue(v12, 3u, (__int64)&v24, 0x18u);
  if ( param_hfi_queue == -61 )
  {
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1AEF8, "get_device_rx_buffer", 969, v9, a5);
    ++v8;
    goto LABEL_8;
  }
  if ( param_hfi_queue )
  {
    v22 = param_hfi_queue;
    printk(&unk_1CD96, "get_device_rx_buffer", 973, v23, v9);
    result = v22;
  }
  else
  {
    a4 = v24;
    v15 = v25;
    a5 = (unsigned int)v26;
    v16 = HIDWORD(v26);
    *(_QWORD *)a3 = v24;
    *(_QWORD *)(a3 + 8) = v15;
    v17 = msm_hfi_core_debug_level;
    *(_QWORD *)(a3 + 16) = a5;
    *(_DWORD *)(a3 + 24) = v9;
    *(_DWORD *)(a3 + 28) = v16;
    if ( (~v17 & 0x10002) == 0 )
      printk(&unk_1F515, "get_device_rx_buffer", 995, a4, a5);
    result = 0;
  }
LABEL_27:
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v21 = result;
    printk(&unk_1C28B, "get_device_rx_buffer", 998, a4, a5);
    result = v21;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
