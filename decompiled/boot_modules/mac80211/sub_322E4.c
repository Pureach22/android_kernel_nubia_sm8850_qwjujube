void __usercall sub_322E4(__int64 a1@<X8>)
{
  __int64 v1; // x20
  __int64 v2; // x21
  __int64 v3; // x22
  __int64 v4; // x0
  __int64 v5; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v2 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v2 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(v2 + 16);
    v4 = _traceiter_drv_wake_tx_queue(0, v1, v3 + a1);
    v5 = *(_QWORD *)(v2 + 16) - 1LL;
    *(_DWORD *)(v2 + 16) = v5;
    if ( !v5 || !*(_QWORD *)(v2 + 16) )
      preempt_schedule_notrace(v4);
  }
  JUMPOUT(0x321EC);
}
