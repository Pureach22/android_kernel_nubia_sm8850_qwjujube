__int64 __fastcall get_tx_buffer(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
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
  int v19; // w8
  __int64 result; // x0
  __int64 v21; // x20
  unsigned int v22; // w23
  __int64 v23; // x24
  unsigned int v24; // w19
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  __int64 v26; // [xsp+8h] [xbp-18h]
  __int64 v27; // [xsp+10h] [xbp-10h]
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  v25 = 0;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
      goto LABEL_22;
  }
  else
  {
    v21 = a1;
    v22 = a2;
    v23 = v5;
    printk(&unk_1E83A, "get_tx_buffer", 258, a4, a5);
    a1 = v21;
    a2 = v22;
    v5 = v23;
    if ( !v21 )
      goto LABEL_22;
  }
  if ( !a3 )
    goto LABEL_22;
  if ( a2 >= 4 )
    goto LABEL_28;
  v7 = *(int **)(a1 + 176LL * a2 + 144);
  if ( !v7 )
  {
LABEL_22:
    printk(&unk_1905C, "get_tx_buffer", 262, v5, a5);
    result = 4294967274LL;
    goto LABEL_20;
  }
  v8 = *v7;
  v9 = *(unsigned int *)(a3 + 24);
  if ( !*v7 )
    goto LABEL_27;
  v10 = v7 + 2;
  if ( v7[2] == (_DWORD)v9 )
    goto LABEL_15;
  if ( v8 == 1 )
    goto LABEL_27;
  v10 = v7 + 8;
  if ( v7[8] == (_DWORD)v9 )
    goto LABEL_15;
  if ( v8 == 2 )
    goto LABEL_27;
  v10 = v7 + 14;
  if ( v7[14] == (_DWORD)v9 )
    goto LABEL_15;
  if ( v8 == 3 )
  {
LABEL_27:
    printk(&unk_1E88C, "get_tx_buffer", 273, v5, v9);
    result = 4294967274LL;
    goto LABEL_20;
  }
  v12 = v7[20];
  v11 = v7 + 20;
  if ( v12 != (_DWORD)v9 )
  {
    if ( v8 == 4 )
      goto LABEL_27;
LABEL_28:
    __break(0x5512u);
  }
  v10 = v11;
LABEL_15:
  v13 = *((_QWORD *)v10 + 1);
  if ( !v13 )
    goto LABEL_27;
  v14 = v5;
  param_hfi_queue = get_param_hfi_queue(v13, 4u, (__int64)&v25, 0x18u);
  if ( param_hfi_queue )
  {
    v24 = param_hfi_queue;
    printk(&unk_1E509, "get_tx_buffer", 281, v14, param_hfi_queue);
    result = v24;
    goto LABEL_20;
  }
  v16 = v25;
  v17 = v26;
  v18 = (unsigned int)v27;
  *(_QWORD *)a3 = v25;
  *(_QWORD *)(a3 + 8) = v17;
  v19 = msm_hfi_core_debug_level;
  *(_QWORD *)(a3 + 16) = v18;
  if ( (~v19 & 0x10002) == 0 )
  {
    printk(&unk_1BB6E, "get_tx_buffer", 291, v16, v18);
    if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
      goto LABEL_19;
LABEL_25:
    printk(&unk_1C28B, "get_tx_buffer", 293, v16, v18);
    goto LABEL_19;
  }
  if ( (~v19 & 0x10001) == 0 )
    goto LABEL_25;
LABEL_19:
  result = 0;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
