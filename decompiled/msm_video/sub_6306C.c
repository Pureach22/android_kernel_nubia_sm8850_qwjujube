void __usercall sub_6306C(__int64 a1@<X0>, unsigned int a2@<W7>, char a3@<W8>)
{
  __int64 v3; // x20
  unsigned int v4; // w21
  __int64 v5; // x22
  unsigned __int64 StatusReg; // x25
  __int64 v7; // x0
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v7 = _traceiter_msm_vidc_dma_buffer(0, (__int64)"ALLOC", v3, v4, v5, a1, a3 & 1, a2);
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v7);
  }
  JUMPOUT(0x62D50);
}
