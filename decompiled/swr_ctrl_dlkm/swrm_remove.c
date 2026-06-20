__int64 __fastcall swrm_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  _DWORD *v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 irq_data; // x0
  __int64 v8; // x21
  __int64 v9; // x0
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 168);
  v3 = *(_QWORD *)(v1 + 20880);
  if ( v3 )
    proc_remove(v3);
  v4 = *(_DWORD **)(v1 + 9112);
  if ( v4 )
  {
    v5 = *(_QWORD *)(v1 + 9064);
    if ( *(v4 - 1) != -46680235 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64 (__fastcall *)(), __int64, _QWORD))v4)(v5, swr_mstr_interrupt, v1, 0);
    goto LABEL_14;
  }
  v6 = *(unsigned int *)(v1 + 9120);
  if ( !(_DWORD)v6 )
  {
    v9 = *(unsigned int *)(v1 + 9124);
    if ( (int)v9 < 1 )
    {
LABEL_14:
      cancel_work_sync(v1 + 15712);
      _pm_runtime_disable(a1 + 16, 1);
      _pm_runtime_set_status(a1 + 16, 2);
      swr_unregister_master(v1);
      cpu_latency_qos_remove_request(v1 + 15752);
      return devm_kfree(a1 + 16, v1);
    }
LABEL_13:
    free_irq(v9, v1);
    goto LABEL_14;
  }
  irq_data = irq_get_irq_data(v6);
  if ( irq_data )
  {
    **(_DWORD **)(irq_data + 16) &= 0xFFFFFFF0;
    **(_DWORD **)(irq_data + 16) |= 0x2000000u;
    if ( *(_DWORD *)(v1 + 15868) )
    {
      irq_set_irq_wake(*(unsigned int *)(v1 + 9120), 0);
      v8 = *(_QWORD *)(v1 + 8512);
      device_wakeup_disable(v8);
      device_set_wakeup_capable(v8, 0);
    }
    v9 = *(unsigned int *)(v1 + 9120);
    goto LABEL_13;
  }
  result = __ratelimit(&swrm_remove__rs, "swrm_remove");
  if ( (_DWORD)result )
    return printk(&unk_1118B, "swrm_remove");
  return result;
}
