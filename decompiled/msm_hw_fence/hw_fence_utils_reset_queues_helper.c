__int64 __fastcall hw_fence_utils_reset_queues_helper(__int64 a1, unsigned int a2, __int64 a3, char a4)
{
  __int64 v4; // x30
  __int64 v5; // x27
  int v6; // w8
  __int64 v8; // x22
  __int64 v10; // x28
  __int64 v11; // x8
  unsigned int v14; // w24
  __int64 result; // x0
  __int64 v16; // x23
  int v17; // w8
  __int64 v18; // x22
  bool v19; // zf
  __int64 v20; // x8
  __int64 v21; // x24
  unsigned int v22; // w21
  __int64 v23; // x4
  const char *v24; // x3

  v5 = *(_QWORD *)(a3 + 16);
  v6 = *(unsigned __int8 *)(a1 + 33520);
  __dsb(0xFu);
  v8 = v4;
  if ( v6 )
    v10 = 64;
  else
    v10 = 48;
  if ( v6 )
    v11 = 128;
  else
    v11 = 52;
  v14 = readl_relaxed_0((unsigned int *)(v5 + v11));
  if ( *(_BYTE *)(a3 + 40) == 1 )
    *(_DWORD *)(v5 + 28) = v14;
  result = writel_relaxed_0(v14, (unsigned int *)(v5 + v10));
  __dsb(0xEu);
  if ( (~msm_hw_fence_debug_level & 0x10010) != 0 )
  {
    if ( (a4 & 1) == 0 )
      return result;
  }
  else
  {
    if ( *(_BYTE *)(a3 + 40) )
      v24 = "read_index=tx_wm";
    else
      v24 = "read_index";
    result = printk(&unk_23166, "hw_fence_utils_reset_queues_helper", 2469, v24, v14);
    if ( (a4 & 1) == 0 )
      return result;
  }
  if ( a2 )
  {
    v16 = 8 * a2 - 8;
    if ( (unsigned int)v16 >= *(_DWORD *)(a1 + 112) )
      return printk(&unk_25A24, "hw_fence_utils_reset_queues_helper", 2480, v8, a2);
    if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
      printk(&unk_28650, "hw_fence_utils_reset_queues_helper", 2483, a2, (unsigned int)v16);
    global_atomic_store(a1, *(_QWORD *)(a1 + 104) + 8LL * (unsigned int)v16, 1);
  }
  else
  {
    v16 = 0;
  }
  v17 = *(unsigned __int8 *)(a1 + 33520);
  v18 = *(_QWORD *)(a3 + 64);
  __dsb(0xFu);
  v19 = v17 == 0;
  v20 = 64;
  if ( v19 )
    v20 = 48;
  if ( v19 )
    v21 = 52;
  else
    v21 = 128;
  v22 = readl_relaxed_0((unsigned int *)(v18 + v20));
  result = writel_relaxed_0(v22, (unsigned int *)(v18 + v21));
  __dsb(0xEu);
  if ( a2 )
    result = global_atomic_store(a1, *(_QWORD *)(a1 + 104) + 8 * v16, 0);
  if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
    return printk(&unk_23A40, "hw_fence_utils_reset_queues_helper", 2502, v22, v23);
  return result;
}
