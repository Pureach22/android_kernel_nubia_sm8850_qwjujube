void __usercall sub_24E80(__int64 a1@<X8>)
{
  __int64 v1; // x0
  __int64 v2; // x9

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(a1 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(a1 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(a1 + 16);
    v1 = _traceiter_safg_sau_cnt_calc(0);
    v2 = *(_QWORD *)(a1 + 16) - 1LL;
    *(_DWORD *)(a1 + 16) = v2;
    if ( !v2 || !*(_QWORD *)(a1 + 16) )
      preempt_schedule_notrace(v1);
  }
  JUMPOUT(0x24DDC);
}
