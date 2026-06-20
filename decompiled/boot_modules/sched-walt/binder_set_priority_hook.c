unsigned __int64 __fastcall binder_set_priority_hook(unsigned __int64 result, __int64 a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x20
  int *v4; // x19
  _DWORD *v5; // x21
  char v6; // w8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (_UNKNOWN *)a3 == &init_task )
    v4 = (int *)&vendor_data_pad;
  else
    v4 = (int *)(a3 + 5184);
  if ( (_UNKNOWN *)StatusReg == &init_task )
    v5 = &vendor_data_pad;
  else
    v5 = (_DWORD *)(StatusReg + 5184);
  if ( (walt_disabled & 1) == 0 )
  {
    if ( a2 && (*(_BYTE *)(a2 + 88) & 1) != 0 && v5[46] == 3 )
    {
      *(_QWORD *)(a2 + 176) = v4[46];
      v4[46] = 3;
    }
    if ( StatusReg != a3 )
    {
      if ( !a3 )
      {
LABEL_19:
        v6 = *((_BYTE *)v4 + 191) & 0xFD;
LABEL_23:
        *((_BYTE *)v4 + 191) = v6;
        return result;
      }
      if ( !*((_QWORD *)v5 + 30) || *(int *)(*(_QWORD *)(a3 + 1864) + 148LL) >= 100 )
      {
        if ( (*((_BYTE *)v5 + 191) & 0xC) == 0 )
        {
          if ( (*((_BYTE *)v5 + 191) & 1) != 0
            && sysctl_walt_low_latency_task_threshold > (unsigned int)*((unsigned __int16 *)v5 + 79) )
          {
            goto LABEL_22;
          }
          if ( *((_QWORD *)v5 + 24) )
          {
            result = walt_sched_clock(result, a2);
            if ( result > *((_QWORD *)v5 + 25) )
            {
              v5[46] = 0;
              *((_QWORD *)v5 + 24) = 0;
              *((_QWORD *)v5 + 25) = 0;
            }
          }
        }
        if ( *(int *)(*(_QWORD *)(StatusReg + 1864) + 148LL) > 99 || !*((_QWORD *)v4 + 30) )
          goto LABEL_19;
      }
LABEL_22:
      v6 = *((_BYTE *)v4 + 191) | 2;
      goto LABEL_23;
    }
  }
  return result;
}
