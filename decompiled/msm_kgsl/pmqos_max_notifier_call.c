__int64 __fastcall pmqos_max_notifier_call(__int64 a1, int a2)
{
  __int64 v2; // x1
  __int64 v3; // x8
  __int64 v4; // x10
  unsigned int v5; // w13
  int v6; // w13
  __int64 v7; // x22
  _DWORD *v8; // x8
  __int64 v9; // x8
  void (__fastcall *v10)(_QWORD); // x8
  unsigned __int64 StatusReg; // x20
  __int64 v13; // x21
  __int64 v14; // x8

  if ( *(_BYTE *)(a1 + 3320) != 1 || *(_BYTE *)(a1 + 2048) == 1 )
  {
    v2 = (unsigned int)(1000 * a2);
    v3 = *(unsigned int *)(a1 - 844);
    v4 = v3 - 1;
    while ( 1 )
    {
      LODWORD(v3) = v3 - 1;
      if ( (int)v3 < 0 )
        return 0;
      if ( (unsigned int)v3 >= 0x20 )
        break;
      v5 = v4-- & 0x1F;
      v6 = *(_DWORD *)(a1 - 1768 + 28LL * v5) - v2;
      if ( v6 < 0 )
        v6 = -v6;
      if ( v6 <= 4999999 )
      {
        if ( *(_DWORD *)(a1 - 360) != (_DWORD)v3 )
        {
          *(_DWORD *)(a1 - 360) = v3;
          goto LABEL_11;
        }
        return 1;
      }
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v13 = a1;
      ++*(_DWORD *)(StatusReg + 16);
      a1 = _traceiter_kgsl_thermal_constraint(0, v2);
      v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v14;
      if ( !v14 || (a1 = v13, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(a1);
        a1 = v13;
      }
    }
LABEL_11:
    __dmb(0xBu);
    if ( *(_DWORD *)(a1 + 216) )
    {
      v7 = a1;
      rt_mutex_lock(a1 + 176);
      v8 = *(_DWORD **)(*(_QWORD *)(v7 - 2160) + 304LL);
      if ( *(v8 - 1) != -227291694 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, _QWORD, _QWORD))v8)(v7 - 10912, 0, 0) )
      {
        v9 = v7;
        if ( *(_DWORD *)(v7 + 36) != 255 )
        {
          v10 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v7 - 2160) + 312LL);
          if ( *((_DWORD *)v10 - 1) != 1058568764 )
            __break(0x8228u);
          v10(v7 - 10912);
          v9 = v7;
        }
        kgsl_pwrctrl_pwrlevel_change(v9 - 10912);
      }
      rt_mutex_unlock(v7 + 176);
    }
    return 1;
  }
  return 0;
}
