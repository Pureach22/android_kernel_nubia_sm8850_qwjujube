void __usercall sub_2EA24(__int64 a1@<X0>, __int64 a2@<X2>, unsigned int a3@<W5>, unsigned int a4@<W8>)
{
  unsigned int v4; // w20
  unsigned int v5; // w22
  unsigned __int64 StatusReg; // x26
  __int64 v8; // x0
  __int64 v9; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v8 = _traceiter_tracing_eva_frame_from_sw(0, a2, "EVA_KMD_FWD_END", v5, a3, v4, a1, a4);
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || (v8 = a1, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v8);
  }
  JUMPOUT(0x2E41C);
}
