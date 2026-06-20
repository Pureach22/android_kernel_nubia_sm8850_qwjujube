__int64 __fastcall hfi_create_header(__int64 *a1, _DWORD *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x22
  __int64 v8; // x4
  int v9; // w8
  __int64 v10; // x3
  __int64 v11; // x4
  int v12; // w8
  __int64 result; // x0
  int v14; // w8
  int v15; // w9
  __int64 *v16; // x22
  __int64 v17; // x23

  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v16 = a1;
    v17 = v5;
    printk(&unk_1E83A, "hfi_create_header", 47, a4, a5);
    a1 = v16;
    v5 = v17;
    if ( v16 )
      goto LABEL_3;
LABEL_10:
    printk(&unk_1905C, "hfi_create_header", 50, v5, a5);
    return 0xFFFFFFFFLL;
  }
  if ( !a1 )
    goto LABEL_10;
LABEL_3:
  if ( !a2 )
    goto LABEL_10;
  v7 = *a1;
  if ( !*a1 )
    goto LABEL_10;
  v8 = *((unsigned int *)a1 + 2);
  if ( (unsigned int)v8 <= 0x1F )
  {
    printk(&unk_1D454, "hfi_create_header", 57, v5, v8);
    return 0xFFFFFFFFLL;
  }
  else
  {
    *(_QWORD *)(v7 + 16) = 0;
    *(_QWORD *)(v7 + 24) = 0;
    *(_QWORD *)v7 = 0;
    *(_QWORD *)(v7 + 8) = 0;
    v9 = a2[1];
    *(_WORD *)(v7 + 4) = 0;
    *(_DWORD *)v7 = (v9 << 24) | 0x20;
    *(_WORD *)(v7 + 6) = a2[2];
    v12 = ktime_get(a1);
    result = 0;
    *(_DWORD *)(v7 + 8) = 0;
    *(_DWORD *)(v7 + 12) = v12;
    v14 = msm_hfi_core_debug_level;
    v15 = a2[3];
    *(_DWORD *)(v7 + 28) = 0;
    *(_DWORD *)(v7 + 16) = v15;
    if ( (~v14 & 0x10001) == 0 )
    {
      printk(&unk_1C28B, "hfi_create_header", 73, v10, v11);
      return 0;
    }
  }
  return result;
}
