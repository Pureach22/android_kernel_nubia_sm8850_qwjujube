__int64 __fastcall hw_fence_notify_ssr(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x4
  int v6; // w8
  __int64 v7; // x19
  int v8; // w8
  __int64 v9; // x0
  __int64 v10; // x1
  unsigned int v11; // w0
  __int64 result; // x0
  int v13; // w8
  __int64 v14; // x19
  __int64 v15; // x20
  __int64 v16; // x22
  __int64 v17; // x4
  int v18; // w8
  __int64 v19; // x1
  unsigned int v20; // w2
  __int64 v21; // x19
  __int64 v22; // x22
  __int64 v23; // x23
  __int64 v24; // x20
  __int64 v25; // x22
  __int64 v26; // x23
  __int64 v27; // x20
  const char *v28; // x3
  __int64 v29; // x19

  v5 = a2;
  if ( a2 <= 1 )
  {
    if ( !a2 )
    {
      if ( (~msm_hw_fence_debug_level & 0x10100) == 0 )
        printk(&unk_23321, "hw_fence_notify_ssr", 963, a4, 0);
      return 1;
    }
    if ( a2 == 1 )
    {
      v6 = msm_hw_fence_debug_level;
      if ( (~msm_hw_fence_debug_level & 0x10100) == 0 )
      {
        v22 = a1;
        v23 = v4;
        printk(&unk_2A967, "hw_fence_notify_ssr", 966, a4, 1);
        v6 = msm_hw_fence_debug_level;
        v4 = v23;
        a1 = v22;
      }
      v7 = v4;
      if ( (~v6 & 0x10002) == 0 )
      {
        v24 = a1;
        printk(&unk_214D8, "_set_soccp_rproc", 851, *(unsigned int *)(a1 - 72), v5);
        a1 = v24;
      }
      v8 = *(_DWORD *)(a1 + 80);
      v9 = a1 - 33680;
      if ( v8 )
        v10 = 4;
      else
        v10 = 3;
      v11 = send_bootup_ctrl_txq_msg(v9, v10);
      if ( v11 )
      {
        printk(&unk_29952, "hw_fence_notify_ssr", 978, v7, v11);
        return 32770;
      }
      return 1;
    }
LABEL_27:
    printk(&unk_26D00, "hw_fence_notify_ssr", 1004, v4, a2);
    return 1;
  }
  if ( a2 == 2 )
  {
    if ( (~msm_hw_fence_debug_level & 0x10100) == 0 )
    {
      if ( *(_BYTE *)(a3 + 8) )
        v28 = "crashed";
      else
        v28 = "stopping";
      v29 = a1;
      printk(&unk_2B537, "hw_fence_notify_ssr", 984, v28, *(unsigned int *)(a1 + 80));
      a1 = v29;
    }
    v19 = *(_QWORD *)(a1 - 33616);
    v20 = *(_DWORD *)(a1 - 33664);
    *(_BYTE *)(a1 - 32944) = 0;
    v21 = a1;
    hw_fence_ssr_cleanup_lock(a1 - 33680, v19, v20, 2u, v5);
    ++*(_DWORD *)(v21 + 80);
    return 1;
  }
  if ( a2 != 3 )
    goto LABEL_27;
  v13 = msm_hw_fence_debug_level;
  if ( (~msm_hw_fence_debug_level & 0x10100) == 0 )
  {
    v25 = a1;
    v26 = v4;
    printk(&unk_23824, "hw_fence_notify_ssr", 993, a4, 3);
    v13 = msm_hw_fence_debug_level;
    v4 = v26;
    a1 = v25;
  }
  v14 = v4;
  if ( (~v13 & 0x10002) == 0 )
  {
    v27 = a1;
    printk(&unk_214D8, "_clear_soccp_rproc", 858, *(unsigned int *)(a1 - 72), v5);
    a1 = v27;
  }
  v15 = a1 - 56;
  v16 = a1;
  mutex_lock(a1 - 56);
  *(_BYTE *)(v16 - 8) = 0;
  mutex_unlock(v15);
  hw_fence_utils_reset_queues_helper(v16 - 33680, 0, v16 - 33464, 1);
  v18 = hw_fence_ssr_cleanup_table(v16 - 33680, *(_QWORD *)(v16 - 33616), *(_DWORD *)(v16 - 33664));
  result = 1;
  if ( v18 )
  {
    printk(&unk_240E5, "hw_fence_notify_ssr", 1001, v14, v17);
    return 32770;
  }
  return result;
}
