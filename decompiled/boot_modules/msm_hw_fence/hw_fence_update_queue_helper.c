__int64 __fastcall hw_fence_update_queue_helper(__int64 a1, unsigned int a2, __int64 a3, __int64 *a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x28
  unsigned int v8; // w19
  __int64 v11; // x8
  __int64 v12; // x24
  __int64 v13; // x26
  unsigned int v14; // w27
  __int64 v15; // x25
  unsigned int v16; // w26
  unsigned int v17; // w0
  int v18; // w6
  unsigned int v19; // w19
  int v20; // w5
  unsigned int v21; // w9
  __int64 v22; // x3
  int v23; // w8
  __int64 v24; // x26
  _QWORD *v25; // x24
  unsigned int v26; // w25
  unsigned int v27; // w5
  unsigned int v28; // w0
  __int64 v29; // x4
  __int64 v30; // x8
  __int64 v31; // x10
  __int64 v32; // x11
  __int64 v33; // x8
  __int64 v34; // x10
  __int64 v35; // x11
  unsigned int v36; // w22
  unsigned int v37; // w21
  __int64 v38; // x20
  unsigned int v39; // w24
  unsigned int v40; // w25
  unsigned int v42; // w25
  unsigned int v43; // w24
  unsigned int v44; // w23
  unsigned int v45; // [xsp+24h] [xbp-1Ch]
  __int64 v46; // [xsp+28h] [xbp-18h]
  int v47; // [xsp+34h] [xbp-Ch]
  __int64 v48; // [xsp+38h] [xbp-8h]

  if ( !a4 )
  {
    printk(&unk_20935, "hw_fence_update_queue_helper", 429, v5, 0);
    return (unsigned int)-22;
  }
  if ( !a3 || (v7 = *(_QWORD *)(a3 + 16)) == 0 )
  {
    v37 = a2;
    v38 = v5;
    printk(&unk_28147, "_get_update_queue_params", 371, v5, a5);
    printk(&unk_25414, "hw_fence_update_queue_helper", 435, v38, v37);
    return (unsigned int)-22;
  }
  v8 = *(_DWORD *)(a3 + 8);
  v11 = 52;
  if ( *(_BYTE *)(a1 + 33520) )
    v12 = 64;
  else
    v12 = 48;
  if ( *(_BYTE *)(a1 + 33520) )
    v11 = 128;
  v47 = a5;
  if ( *(_BYTE *)(a3 + 40) )
    v11 = 28;
  v48 = v11;
  if ( (_DWORD)a5 != 1 )
  {
    v14 = a2;
    v15 = 0;
    goto LABEL_17;
  }
  v13 = 8 * a2 - 8;
  if ( (unsigned int)v13 >= *(_DWORD *)(a1 + 112) )
  {
    printk(&unk_25A24, "hw_fence_update_queue_helper", 450, v5, a2);
    return (unsigned int)-22;
  }
  if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
  {
    v42 = a2;
    printk(&unk_28650, "hw_fence_update_queue_helper", 453, a2, (unsigned int)v13);
    a2 = v42;
  }
  v14 = a2;
  v15 = v13;
  global_atomic_store(a1, *(_QWORD *)(a1 + 104) + 8LL * (unsigned int)v13, 1);
LABEL_17:
  __dsb(0xFu);
  v16 = readl_relaxed_0((unsigned int *)(v7 + v12));
  v17 = readl_relaxed_0((unsigned int *)(v7 + v48));
  if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
  {
    v45 = v17;
    printk(&unk_24EDA, "hw_fence_update_queue_helper", 468, v14, v7 + v12);
    v17 = v45;
  }
  v18 = *(_DWORD *)(a3 + 36);
  v19 = v8 >> 2;
  if ( v18 )
  {
    v20 = *(_DWORD *)(a3 + 32);
    if ( v18 != 1 || v20 )
    {
      v16 = (v16 - v20) * v18;
      v17 = (v17 - v20) * v18;
      if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
      {
        v43 = v17;
        printk(&unk_2B381, "_translate_queue_indexes_custom_to_default", 268, v16, v17);
        v17 = v43;
      }
    }
  }
  if ( v16 <= v17 )
    v21 = v19;
  else
    v21 = 0;
  v22 = v21 + v16 - v17;
  if ( (unsigned int)v22 <= 0x10 )
  {
    printk(&unk_243D8, "hw_fence_update_queue_helper", 477, v46, 16);
    v36 = -22;
    v24 = v15;
    if ( v47 != 1 )
      return v36;
    goto LABEL_43;
  }
  v23 = msm_hw_fence_debug_level;
  v24 = v15;
  if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
  {
    v39 = v17;
    printk(&unk_24944, "hw_fence_update_queue_helper", 481, v22, 16);
    v23 = msm_hw_fence_debug_level;
    v17 = v39;
  }
  v25 = (_QWORD *)(*(_QWORD *)a3 + 4LL * v17);
  if ( (~v23 & 0x10010) == 0 )
  {
    v40 = v17;
    printk(&unk_2A6FB, "hw_fence_update_queue_helper", 487, v25, *(_QWORD *)a3);
    v23 = msm_hw_fence_debug_level;
    v17 = v40;
  }
  v26 = v17 + 16;
  if ( (~v23 & 0x10010) == 0 )
    printk(&unk_22CD6, "hw_fence_update_queue_helper", 493, v26, v17);
  v27 = *(_DWORD *)(a3 + 36);
  if ( v26 >= v19 )
    v28 = 0;
  else
    v28 = v26;
  if ( v27 )
  {
    v29 = *(unsigned int *)(a3 + 32);
    if ( v27 != 1 || (_DWORD)v29 )
    {
      v28 = v28 / v27 + v29;
      if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
      {
        v44 = v28;
        printk(&unk_26168, "hw_fence_update_queue_helper", 507, v28, v29);
        v28 = v44;
      }
    }
  }
  v30 = a4[3];
  v31 = *a4;
  v32 = a4[1];
  v25[2] = a4[2];
  v25[3] = v30;
  *v25 = v31;
  v25[1] = v32;
  v33 = a4[7];
  v34 = a4[4];
  v35 = a4[5];
  v25[6] = a4[6];
  v25[7] = v33;
  v25[4] = v34;
  v25[5] = v35;
  __dsb(0xEu);
  writel_relaxed_0(v28, (unsigned int *)(v7 + v48));
  __dsb(0xEu);
  v36 = 0;
  if ( v47 == 1 )
LABEL_43:
    global_atomic_store(a1, *(_QWORD *)(a1 + 104) + 8 * v24, 0);
  return v36;
}
