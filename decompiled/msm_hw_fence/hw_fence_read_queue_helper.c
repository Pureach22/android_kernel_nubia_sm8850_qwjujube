__int64 __fastcall hw_fence_read_queue_helper(__int64 a1, __int64 a2, _QWORD *a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  unsigned int v6; // w23
  __int64 v9; // x24
  int v10; // w8
  __int64 v11; // x25
  __int64 v12; // x28
  unsigned int v13; // w22
  unsigned int v14; // w0
  __int64 v15; // x3
  __int64 v16; // x4
  int v17; // w6
  unsigned int v18; // w21
  int v19; // w5
  __int64 v21; // x21
  __int64 v22; // x22
  unsigned int v23; // w28
  __int64 *v24; // x23
  unsigned int v25; // w5
  unsigned int v26; // w22
  __int64 v27; // x4
  __int64 v28; // x8
  __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x8
  __int64 v32; // x10
  __int64 v33; // x11

  v6 = *(_DWORD *)(a2 + 8);
  if ( (~msm_hw_fence_debug_level & 0x10010) != 0 )
  {
    if ( !a3 )
    {
LABEL_21:
      printk(&unk_253E8, "hw_fence_read_queue_helper", 303, v5, a5);
      return 4294967274LL;
    }
  }
  else
  {
    v21 = a1;
    v22 = v5;
    printk(&unk_22CAC, "hw_fence_read_queue_helper", 300, 64, a5);
    a1 = v21;
    v5 = v22;
    if ( !a3 )
      goto LABEL_21;
  }
  v9 = *(_QWORD *)(a2 + 16);
  if ( !v9 )
    goto LABEL_21;
  v10 = *(unsigned __int8 *)(a1 + 33520);
  __dsb(0xFu);
  if ( v10 )
    v11 = 64;
  else
    v11 = 48;
  if ( v10 )
    v12 = 128;
  else
    v12 = 52;
  v13 = readl_relaxed_0(v9 + v11);
  v14 = readl_relaxed_0(v9 + v12);
  v17 = *(_DWORD *)(a2 + 36);
  v18 = v14;
  if ( v17 )
  {
    v19 = *(_DWORD *)(a2 + 32);
    if ( v17 != 1 || v19 )
    {
      v13 = (v13 - v19) * v17;
      v18 = (v14 - v19) * v17;
      if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
        printk(&unk_2B381, "_translate_queue_indexes_custom_to_default", 268, v13, v18);
    }
  }
  if ( (~msm_hw_fence_debug_level & 0x10010) != 0 )
  {
    if ( v13 == v18 )
    {
LABEL_17:
      if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
        printk(&unk_21DE8, "hw_fence_read_queue_helper", 323, v15, v16);
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_26610, "hw_fence_read_queue_helper", 320, v9 + v11, v9 + v12);
    if ( v13 == v18 )
      goto LABEL_17;
  }
  v23 = v6 >> 2;
  v24 = (__int64 *)(*(_QWORD *)a2 + 4LL * v13);
  if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
    printk(&unk_27123, "hw_fence_read_queue_helper", 331, *(_QWORD *)a2 + 4LL * v13, *(_QWORD *)a2);
  v25 = *(_DWORD *)(a2 + 36);
  if ( v13 + 16 >= v23 )
    v26 = 0;
  else
    v26 = v13 + 16;
  if ( v25 )
  {
    v27 = *(unsigned int *)(a2 + 32);
    if ( v25 != 1 || (_DWORD)v27 )
    {
      v26 = v26 / v25 + v27;
      if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
        printk(&unk_248F6, "hw_fence_read_queue_helper", 348, v26, v27);
    }
  }
  v28 = v24[3];
  v29 = *v24;
  v30 = v24[1];
  a3[2] = v24[2];
  a3[3] = v28;
  *a3 = v29;
  a3[1] = v30;
  v31 = v24[7];
  v32 = v24[4];
  v33 = v24[5];
  a3[6] = v24[6];
  a3[7] = v31;
  a3[4] = v32;
  a3[5] = v33;
  writel_relaxed_0(v26, v9 + v11);
  __dsb(0xEu);
  return v26 != v18;
}
