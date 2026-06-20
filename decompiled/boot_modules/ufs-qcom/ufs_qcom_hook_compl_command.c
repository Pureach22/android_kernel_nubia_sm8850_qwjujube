__int64 __fastcall ufs_qcom_hook_compl_command(__int64 result, __int64 a2, __int64 a3)
{
  unsigned int v3; // w19
  __int64 v4; // x21
  unsigned int v5; // w22
  unsigned int v6; // w23
  __int64 v7; // x25
  __int64 v8; // x26
  __int64 v9; // x27
  __int64 v11; // x21
  __int64 v12; // x19
  __int64 v13; // x8
  int v14; // w19
  __int64 v15; // x21
  int v16; // w22
  int v17; // w23
  int v18; // w24
  int v19; // w0
  unsigned __int64 StatusReg; // x24
  __int64 v21; // x28
  unsigned int v22; // w20
  __int64 (__fastcall *v23)(__int64, __int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD); // x8
  __int64 v24; // x0
  __int64 v25; // t1
  __int64 v26; // x8

  if ( !a2 )
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v21 = qword_174C8;
      if ( qword_174C8 )
      {
        v22 = result;
        do
        {
          v23 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD))v21;
          v24 = *(_QWORD *)(v21 + 8);
          if ( *(_DWORD *)(*(_QWORD *)v21 - 4LL) != -384891958 )
            __break(0x8228u);
          result = v23(v24, v4, 1, v5, v6, v22, v3);
          v25 = *(_QWORD *)(v21 + 24);
          v21 += 24;
        }
        while ( v25 );
      }
      v26 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v26;
      if ( !v26 || !*(_QWORD *)(StatusReg + 16) )
        result = preempt_schedule_notrace(result);
    }
LABEL_22:
    if ( *(_BYTE *)(v7 + 3137) == 1 && v9 && *(_DWORD *)(v7 + 704) )
      *(_DWORD *)(v8 - 264) |= 0x400000u;
    return result;
  }
  v7 = *(_QWORD *)(a2 + 184);
  if ( (*(_BYTE *)(v7 + 360) & 1) == 0 && *(_BYTE *)(v7 + 3176) == 1 )
  {
    v11 = a3;
    v12 = raw_spin_lock_irqsave(*(_QWORD *)(*(_QWORD *)(a2 + 56) + 56LL));
    v13 = *(_QWORD *)(v7 + 3184) - 1LL;
    *(_QWORD *)(v7 + 3184) = v13;
    if ( !v13 )
      writel(*(_DWORD *)(a2 + 100), (unsigned int *)(*(_QWORD *)a2 + 24LL));
    result = raw_spin_unlock_irqrestore(*(_QWORD *)(*(_QWORD *)(a2 + 56) + 56LL), v12);
    a3 = v11;
  }
  if ( a3 )
  {
    v8 = *(_QWORD *)(a3 + 64);
    if ( v8 )
    {
      v9 = v8 - 288;
      if ( v8 == 288 )
      {
        if ( (*(_BYTE *)(a2 + 4893) & 1) != 0 )
          return result;
        v14 = 0;
      }
      else
      {
        v14 = *(_DWORD *)(v8 - 244) >> 9;
        if ( (*(_BYTE *)(a2 + 4893) & 1) != 0 )
        {
          result = *(_QWORD *)(v7 + 656);
          if ( result )
          {
            if ( *(_BYTE *)(v7 + 664) == 1 )
              return ipc_log_string(
                       result,
                       ",%d,>,%x,%d,%d,%d\n",
                       *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40),
                       *(unsigned __int8 *)(v8 + 180),
                       *(_DWORD *)(a3 + 80),
                       *(_DWORD *)(*(_QWORD *)(a2 + 5072)
                                 + 144LL * *(unsigned __int16 *)(*(_QWORD *)(v8 - 272) + 356LL)
                                 + 68),
                       v14);
          }
          return result;
        }
      }
      v15 = *(_QWORD *)(v7 + 656);
      if ( v15 && *(_BYTE *)(v7 + 664) == 1 )
      {
        v16 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40);
        v17 = *(unsigned __int8 *)(v8 + 180);
        v18 = *(_DWORD *)(a3 + 80);
        v19 = readl((unsigned int *)(*(_QWORD *)a2 + 88LL));
        result = ipc_log_string(v15, ",%d,>,%x,%d,%x,%d\n", v16, v17, v18, v19, v14);
      }
      if ( *(_BYTE *)(v7 + 664) == 1 )
        result = readl((unsigned int *)(*(_QWORD *)a2 + 88LL));
      goto LABEL_22;
    }
  }
  return result;
}
