__int64 __fastcall kgsl_pwrctrl_change_state(_QWORD *a1, signed int a2)
{
  __int64 result; // x0
  __int64 v4; // x8
  void (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x1
  _DWORD *v7; // x8
  int v8; // w0
  unsigned int v9; // w8
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0
  unsigned int v12; // w8
  __int64 (__fastcall *v13)(_QWORD); // x8
  unsigned int v14; // w0
  _QWORD *v15; // x0
  __int64 v16; // x1
  int v17; // w8
  void (__fastcall *v18)(_QWORD); // x8
  int v19; // w8
  __int64 (__fastcall *v20)(_QWORD); // x8
  __int64 v21; // x20
  __int64 v22; // x8
  unsigned int v23; // w19
  unsigned int v24; // w20
  void (__fastcall *v25)(_QWORD); // x8
  const char *v26; // x2
  unsigned __int64 StatusReg; // x20
  __int64 v28; // x0
  __int64 v29; // x8
  signed int v30; // [xsp+8h] [xbp-8h]

  if ( *((_DWORD *)a1 + 2780) == a2 )
    return 0;
  if ( !a2 )
  {
    *((_DWORD *)a1 + 2781) = 0;
LABEL_55:
    dev_err(*a1, "bad state request 0x%x\n", a2);
    goto LABEL_56;
  }
  while ( 1 )
  {
    *((_DWORD *)a1 + 2781) = a2;
    if ( a2 > 15 )
    {
      if ( a2 != 16 )
      {
        if ( a2 != 32 )
        {
          if ( a2 != 128 )
            goto LABEL_55;
          return slumber(a1);
        }
        v19 = *((_DWORD *)a1 + 2780);
        if ( v19 != 128 )
        {
          if ( v19 == 2 )
          {
            kgsl_pwrctrl_irq((__int64)a1, 0);
            timer_delete_sync(a1 + 1099);
LABEL_59:
            v15 = a1;
            v16 = 32;
            goto LABEL_60;
          }
          if ( v19 != 1 )
            return 4294967274LL;
        }
        kgsl_pwrctrl_pwrlevel_change((__int64)a1);
        result = kgsl_pwrctrl_pwrrail(a1, 1);
        if ( (_DWORD)result )
          return result;
        kgsl_pwrctrl_clk(a1, 1, 2);
        kgsl_pwrctrl_axi((__int64)a1, 1);
        v20 = *(__int64 (__fastcall **)(_QWORD))(a1[1094] + 200LL);
        if ( *((_DWORD *)v20 - 1) != -1357770785 )
          __break(0x8228u);
        result = v20(a1);
        if ( (_DWORD)result )
          return result;
        goto LABEL_59;
      }
      v12 = *((_DWORD *)a1 + 2780);
      if ( v12 <= 0x10 && ((1 << v12) & 0x10003) != 0 )
        return 0;
      v13 = *(__int64 (__fastcall **)(_QWORD))(a1[1094] + 96LL);
      if ( *((_DWORD *)v13 - 1) != -1357770785 )
        __break(0x8228u);
      v14 = v13(a1);
      if ( v14 || (v14 = slumber(a1)) != 0 )
      {
        v24 = v14;
        v25 = *(void (__fastcall **)(_QWORD))(a1[1094] + 192LL);
        if ( *((_DWORD *)v25 - 1) != 1058568764 )
          __break(0x8228u);
        v25(a1);
        dev_err(*a1, "device failed to SUSPEND %d\n", v24);
        return v24;
      }
      v15 = a1;
      v16 = 16;
LABEL_60:
      kgsl_pwrctrl_set_state(v15, v16);
      return 0;
    }
    if ( a2 == 1 )
    {
      v17 = *((_DWORD *)a1 + 2780);
      result = 0;
      if ( v17 > 31 )
      {
        if ( v17 != 32 )
        {
          if ( v17 != 128 )
            return result;
          goto LABEL_51;
        }
      }
      else
      {
        if ( !v17 )
        {
LABEL_51:
          v15 = a1;
          v16 = 1;
          goto LABEL_60;
        }
        if ( v17 != 2 )
          return result;
        kgsl_pwrctrl_irq((__int64)a1, 0);
        timer_delete_sync(a1 + 1099);
        v18 = *(void (__fastcall **)(_QWORD))(a1[1094] + 32LL);
        if ( *((_DWORD *)v18 - 1) != -1357770785 )
          __break(0x8228u);
        v18(a1);
      }
      kgsl_pwrctrl_disable(a1);
      goto LABEL_51;
    }
    if ( a2 != 2 )
      goto LABEL_55;
    v4 = *((unsigned int *)a1 + 2780);
    if ( (_DWORD)v4 != 128 )
      break;
LABEL_18:
    v6 = *((unsigned __int8 *)a1 + 10440);
    v7 = *(_DWORD **)(a1[1094] + 24LL);
    if ( *(v7 - 1) != -1361917767 )
      __break(0x8228u);
    v8 = ((__int64 (__fastcall *)(_QWORD *, __int64))v7)(a1, v6);
    *((_BYTE *)a1 + 10440) = 0;
    if ( v8 )
    {
      v22 = *a1;
      *((_DWORD *)a1 + 2781) = 0;
      v23 = v8;
      dev_err(v22, "start failed %d\n", v8);
      return v23;
    }
    kgsl_pwrctrl_axi((__int64)a1, 1);
    kgsl_pwrscale_wake(a1);
    kgsl_pwrctrl_irq((__int64)a1, 1);
    v9 = *((_DWORD *)a1 + 2510);
    if ( v9 < 0x20 )
    {
      a2 = *((_DWORD *)a1 + 7 * v9 + 2286) / 0x3E8u;
      if ( *((_DWORD *)a1 + 2510) <= 0x1Fu )
      {
        kgsl_bus_update((__int64)a1, 1);
        kgsl_pwrctrl_clk(a1, 1, 2);
        v10 = *(__int64 (__fastcall **)(_QWORD))(a1[1094] + 264LL);
        if ( *((_DWORD *)v10 - 1) != 1058568764 )
          __break(0x8228u);
        v11 = v10(a1);
        a1[1363] = ktime_get(v11);
        kgsl_pwrctrl_set_state(a1, 2);
        *((_DWORD *)a1 + 2511) = *((_DWORD *)a1 + 2510);
        goto LABEL_53;
      }
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v30 = a2;
      v28 = _traceiter_kgsl_pwr_request_state(0, a1, (unsigned int)a2);
      a2 = v30;
      v29 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v29;
      if ( !v29 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v28);
        a2 = v30;
      }
    }
  }
  if ( (_DWORD)v4 == 32 )
  {
    kgsl_pwrctrl_set_state(a1, 2);
    kgsl_pwrctrl_irq((__int64)a1, 1);
LABEL_53:
    v21 = jiffies;
    a1[1768] = _msecs_to_jiffies(a1[1260]) + v21;
    mod_timer(a1 + 1099);
    return 0;
  }
  if ( (_DWORD)v4 == 16 )
  {
    complete_all(a1 + 1086);
    v5 = *(void (__fastcall **)(_QWORD))(a1[1094] + 192LL);
    if ( *((_DWORD *)v5 - 1) != 1058568764 )
      __break(0x8228u);
    v5(a1);
    goto LABEL_18;
  }
  if ( (unsigned int)v4 > 2 )
    v26 = "UNKNOWN";
  else
    v26 = off_1726C0[v4];
  dev_warn(*a1, "unhandled state %s\n", v26);
LABEL_56:
  *((_DWORD *)a1 + 2781) = 0;
  return 4294967274LL;
}
