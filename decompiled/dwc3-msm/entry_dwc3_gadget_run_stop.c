__int64 __fastcall entry_dwc3_gadget_run_stop(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x8
  __int64 *v6; // x0
  int v7; // w1

  v2 = *(_QWORD *)a2;
  if ( !*(_DWORD *)(a2 + 8) )
  {
    dwc3_core_stop_hw_active_transfers(*(_QWORD *)a2);
    dwc3_msm_notify_event((__int64 *)v2, 13, 0);
    v6 = (__int64 *)v2;
    v7 = 15;
LABEL_9:
    dwc3_msm_notify_event(v6, v7, 0);
    return 0;
  }
  v3 = irq_to_desc(*(unsigned int *)(v2 + 1208));
  if ( !v3 )
  {
    v6 = (__int64 *)v2;
    v7 = 11;
    goto LABEL_9;
  }
  v4 = *(_QWORD *)(v3 + 120);
  dwc3_msm_notify_event((__int64 *)v2, 11, 0);
  if ( v4 )
  {
    while ( 1 )
    {
      v5 = *(_QWORD *)(v4 + 40);
      if ( v5 )
        break;
      v4 = *(_QWORD *)(v4 + 24);
      if ( !v4 )
        return 0;
    }
    dev_info(
      *(_QWORD *)(v2 + 368),
      "Set IRQ thread:%s pid:%d to SCHED_NORMAL prio\n",
      (const char *)(v5 + 2320),
      *(_DWORD *)(v5 + 1800));
    sched_set_normal(*(_QWORD *)(v4 + 40), 4294967276LL);
  }
  return 0;
}
