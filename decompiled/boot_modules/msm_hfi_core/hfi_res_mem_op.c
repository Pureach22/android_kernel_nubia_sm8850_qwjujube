__int64 __fastcall hfi_res_mem_op(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  unsigned int *v6; // x23
  __int64 v7; // x24
  __int64 v8; // x20
  __int64 v9; // x21
  unsigned int v10; // w19
  unsigned int v11; // w8
  __int64 v12; // x4
  __int64 (__fastcall *v13)(__int64, __int64); // x8
  __int64 (__fastcall *v14)(__int64, __int64); // x8
  unsigned int v16; // w23

  v6 = *(unsigned int **)(a1 + 280);
  v7 = *(_QWORD *)(a1 + 288);
  v8 = v5;
  v9 = a1;
  v10 = a2;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    v11 = *v6;
    if ( *v6 )
      goto LABEL_3;
LABEL_23:
    printk(&unk_1B8E2, "hfi_res_mem_op", 563, v8, a5);
    return 4294967274LL;
  }
  a1 = printk(&unk_1E83A, "hfi_res_mem_op", 560, a4, a5);
  v11 = *v6;
  if ( !*v6 )
    goto LABEL_23;
LABEL_3:
  v12 = *(unsigned int *)(v7 + 20);
  if ( (_DWORD)v12 != 1 )
  {
    if ( (_DWORD)v12 != 2 )
      goto LABEL_26;
    if ( v11 < 2 )
      return 0;
LABEL_12:
    v12 = *(unsigned int *)(v7 + 24);
    if ( (_DWORD)v12 == 2 )
      goto LABEL_19;
    if ( (_DWORD)v12 == 1 )
    {
      if ( v10 <= 3 )
      {
        v14 = (__int64 (__fastcall *)(__int64, __int64))hfi_vq_res_op[v10];
        if ( *((_DWORD *)v14 - 1) != -1619865549 )
          __break(0x8228u);
        a1 = v14(1, v9);
        if ( !(_DWORD)a1 )
        {
          v11 = *v6;
LABEL_19:
          if ( v11 <= 2 )
            return 0;
LABEL_29:
          __break(0x5512u);
          return hfi_core_wait_event(a1, a2);
        }
        goto LABEL_25;
      }
LABEL_28:
      __break(1u);
      goto LABEL_29;
    }
LABEL_26:
    printk(&unk_1A388, "hfi_res_mem_op", 578, v8, v12);
    v16 = -22;
    goto LABEL_27;
  }
  if ( v10 > 3 )
    goto LABEL_28;
  v13 = (__int64 (__fastcall *)(__int64, __int64))hfi_vq_res_op[v10];
  if ( *((_DWORD *)v13 - 1) != -1619865549 )
    __break(0x8228u);
  a1 = v13(1, v9);
  if ( (_DWORD)a1 )
  {
LABEL_25:
    v16 = a1;
LABEL_27:
    printk(&unk_1AB76, "hfi_res_mem_op", 586, v8, v10);
    return v16;
  }
  v11 = *v6;
  if ( *v6 >= 2 )
    goto LABEL_12;
  return 0;
}
