__int64 __fastcall mhi_tryset_pm_state(__int64 a1, unsigned int a2)
{
  __int64 v2; // x29
  unsigned int v3; // w8
  __int64 v4; // x10
  _DWORD *v5; // x9
  unsigned __int64 StatusReg; // x19
  __int64 v8; // x8

  v3 = *(_DWORD *)(a1 + 336);
  if ( v3 )
  {
    v4 = __clz(v3) ^ 0x1F;
    if ( (unsigned int)v4 <= 0xC )
    {
      v5 = (_DWORD *)((char *)&dev_state_transitions + 8 * (unsigned int)v4);
      if ( v3 == *v5 )
      {
        if ( ((8 * v4) | 4uLL) > 0x68 )
        {
          __break(1u);
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                           + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
              & 1) != 0 )
          {
            ++*(_DWORD *)(StatusReg + 16);
            *(_QWORD *)(v2 + 24) = a1;
            *(_DWORD *)(v2 - 4) = a2;
            _traceiter_mhi_tryset_pm_state(0, *(_QWORD *)(v2 + 24), *(_DWORD *)(v2 - 4));
            a2 = *(_DWORD *)(v2 - 4);
            a1 = *(_QWORD *)(v2 + 24);
            v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
            *(_DWORD *)(StatusReg + 16) = v8;
            if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
            {
              preempt_schedule_notrace(a1);
              a2 = *(_DWORD *)(v2 - 4);
              a1 = *(_QWORD *)(v2 + 24);
            }
          }
          goto LABEL_6;
        }
        if ( (v5[1] & a2) != 0 )
        {
LABEL_6:
          *(_DWORD *)(a1 + 336) = a2;
          return a2;
        }
      }
    }
  }
  return v3;
}
