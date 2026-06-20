__int64 __fastcall hw_fence_utils_register_soccp_ssr_notifier(__int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  __int64 v4; // x4
  __int64 v5; // x3
  __int64 result; // x0
  unsigned __int64 v7; // x0
  __int64 v8; // x4
  __int64 v9; // x3
  __int64 v10; // x4
  unsigned __int64 v11; // x19

  v3 = v1;
  if ( !a1 || (*(_BYTE *)(a1 + 33520) & 1) == 0 )
  {
    printk(&unk_29F4A, "hw_fence_utils_register_soccp_ssr_notifier", 1020, v1, a1);
    return 4294967274LL;
  }
  _mutex_init(a1 + 33624, "&soccp_props->rproc_lock", &hw_fence_utils_register_soccp_ssr_notifier___key);
  *(_DWORD *)(a1 + 33676) = 1;
  _init_waitqueue_head(a1 + 33712, "&soccp_props->ssr_wait_queue", &hw_fence_utils_register_soccp_ssr_notifier___key_58);
  _init_waitqueue_head(
    a1 + 33736,
    "&soccp_props->enable_power_wait_queue",
    &hw_fence_utils_register_soccp_ssr_notifier___key_60);
  v5 = *(unsigned int *)(a1 + 12);
  if ( (_DWORD)v5 )
  {
    if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
      printk(&unk_23B56, "hw_fence_utils_register_soccp_ssr_notifier", 1032, v5, v4);
    *(_BYTE *)(a1 + 736) = 1;
    return 0;
  }
  *(_DWORD *)(a1 + 33696) = 1;
  *(_QWORD *)(a1 + 33680) = hw_fence_notify_ssr;
  v7 = qcom_register_ssr_notifier("soccp", a1 + 33680);
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = v7;
    printk(&unk_23B97, "hw_fence_utils_register_soccp_ssr_notifier", 1041, v3, v8);
    return v11;
  }
  *(_QWORD *)(a1 + 33704) = v7;
  if ( (~msm_hw_fence_debug_level & 0x10100) != 0 )
  {
    if ( (~msm_hw_fence_debug_level & 0x10002) != 0 )
      goto LABEL_10;
  }
  else
  {
    printk(&unk_21907, "hw_fence_utils_register_soccp_ssr_notifier", 1045, v7, v8);
    if ( (~msm_hw_fence_debug_level & 0x10002) != 0 )
      goto LABEL_10;
  }
  printk(&unk_214D8, "_set_soccp_rproc", 851, *(unsigned int *)(a1 + 33608), v8);
LABEL_10:
  result = send_bootup_ctrl_txq_msg(a1, 3);
  if ( (_DWORD)result )
  {
    if ( (~msm_hw_fence_debug_level & 0x10004) == 0 )
      printk(&unk_2630D, "hw_fence_utils_register_soccp_ssr_notifier", 1057, v9, v10);
    return 0;
  }
  return result;
}
