void __fastcall sub_749BC(unsigned int a1)
{
  unsigned __int64 StatusReg; // x20
  __int64 v3; // x8
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    _traceiter_msm_v4l2_vidc_fw_load(0, (__int64)&unk_927FF);
    v3 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v3;
    if ( v3 )
    {
      v4 = a1;
      if ( *(_QWORD *)(StatusReg + 16) )
        goto LABEL_7;
    }
    else
    {
      v4 = a1;
    }
    preempt_schedule_notrace(v4);
  }
LABEL_7:
  JUMPOUT(0x7491C);
}
