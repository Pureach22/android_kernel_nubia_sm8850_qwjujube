__int64 __fastcall sde_power_scale_reg_bus(__int64 a1, unsigned int a2, char a3)
{
  unsigned __int64 v3; // x9
  __int64 v4; // x22
  unsigned __int64 v5; // x8
  __int64 v9; // x8
  unsigned int v10; // w0
  __int64 result; // x0
  unsigned int v12; // w20
  unsigned int v13; // w22
  __int64 v14; // x0
  __int64 v15; // x10
  unsigned __int64 v16; // [xsp+0h] [xbp-10h]
  unsigned __int64 v17; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(a1 + 104);
  if ( !v5 )
    return 0;
  if ( (a3 & 1) == 0 )
    mutex_lock(a1 + 48);
  if ( a2 >= 4 )
  {
    __break(0x5512u);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v4 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v4 + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(v4 + 16);
      v16 = v3;
      v17 = v5;
      v14 = _traceiter_tracing_mark_write(0, 0x42u, v4, (__int64)"msm_bus_scale_req", 0);
      v3 = v16;
      v5 = v17;
      v15 = *(_QWORD *)(v4 + 16) - 1LL;
      *(_DWORD *)(v4 + 16) = v15;
      if ( !v15 || !*(_QWORD *)(v4 + 16) )
      {
        preempt_schedule_notrace(v14);
        v3 = v16;
        v5 = v17;
      }
    }
  }
  else
  {
    if ( !*(_QWORD *)(a1 + 104) )
      goto LABEL_8;
    v9 = a1 + 16LL * a2;
    _ReadStatusReg(SP_EL0);
    v3 = *(_QWORD *)(v9 + 120);
    v5 = *(_QWORD *)(v9 + 128);
  }
  v10 = icc_set_bw(*(_QWORD *)(a1 + 104), v3 / 0x3E8, v5 / 0x3E8);
  if ( v10 )
  {
    v13 = v10;
    printk(&unk_22520F, "sde_power_reg_bus_update");
    result = v13;
    if ( (a3 & 1) == 0 )
      goto LABEL_9;
    return result;
  }
LABEL_8:
  result = 0;
  *(_DWORD *)(a1 + 112) = a2;
  if ( (a3 & 1) == 0 )
  {
LABEL_9:
    v12 = result;
    mutex_unlock(a1 + 48);
    return v12;
  }
  return result;
}
