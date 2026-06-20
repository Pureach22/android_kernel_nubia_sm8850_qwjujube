__int64 __fastcall ufs_qcom_hook_send_uic_command(__int64 a1, _QWORD *a2, int *a3, int a4, int a5)
{
  unsigned int v5; // w19
  unsigned int v6; // w20
  unsigned int v7; // w21
  __int64 v8; // x22
  __int64 v9; // x23
  __int64 v10; // x29
  int v12; // w4
  __int64 v13; // x3
  __int64 result; // x0
  unsigned __int64 StatusReg; // x24
  unsigned __int64 v16; // x8
  __int64 v17; // x25
  __int64 (__fastcall *v18)(__int64, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD); // x8
  __int64 v19; // x0
  __int64 v20; // x3
  __int64 v21; // t1
  __int64 v22; // x8
  int v23; // w22

  if ( a2 )
  {
    v9 = a2[23];
    if ( a4 )
    {
      v5 = readl((unsigned int *)(*a2 + 148LL));
      v6 = readl((unsigned int *)(*a2 + 152LL));
      v7 = readl((unsigned int *)(*a2 + 156LL));
      v12 = readl((unsigned int *)(*a2 + 144LL));
      v13 = 41;
    }
    else
    {
      v6 = a3[2];
      v7 = a3[3];
      v12 = *a3;
      v5 = a3[1];
      v13 = 40;
    }
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v16 = *(unsigned int *)(StatusReg + 40);
    *(_DWORD *)(v10 + 28) = a5;
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v16 >> 3) & 0x1FFFFFF8)) >> v16) & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v17 = qword_17518;
      if ( qword_17518 )
      {
        do
        {
          v18 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD))v17;
          v19 = *(_QWORD *)(v17 + 8);
          v20 = *(unsigned int *)(v10 + 28);
          if ( *(_DWORD *)(*(_QWORD *)v17 - 4LL) != -1781180407 )
            __break(0x8228u);
          a1 = v18(v19, v8, 1, v20, v5, v6, v7);
          v21 = *(_QWORD *)(v17 + 24);
          v17 += 24;
        }
        while ( v21 );
      }
      v22 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v22;
      if ( v22 )
      {
        v13 = 41;
        v12 = *(_DWORD *)(v10 + 28);
        if ( *(_QWORD *)(StatusReg + 16) )
          goto LABEL_5;
      }
      else
      {
        v12 = *(_DWORD *)(v10 + 28);
      }
      v23 = v12;
      preempt_schedule_notrace(a1);
      v13 = 41;
      v12 = v23;
    }
    else
    {
      v12 = *(_DWORD *)(v10 + 28);
      v13 = 41;
    }
  }
LABEL_5:
  result = *(_QWORD *)(v9 + 656);
  if ( result )
  {
    if ( *(_BYTE *)(v9 + 664) == 1 )
      return ipc_log_string(
               result,
               ",%d,%c,%x,%x,%x,%x\n",
               *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40),
               v13,
               v12,
               v5,
               v6,
               v7);
  }
  return result;
}
