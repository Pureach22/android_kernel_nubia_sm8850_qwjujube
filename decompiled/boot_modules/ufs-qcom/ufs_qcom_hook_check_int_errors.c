__int64 __usercall ufs_qcom_hook_check_int_errors@<X0>(
        __int64 result@<X0>,
        __int64 a2@<X1>,
        char a3@<W2>,
        __int64 a4@<X8>)
{
  int v4; // w9
  unsigned int v5; // w10
  __int64 v6; // x29
  __int64 v7; // x19
  unsigned __int64 StatusReg; // x19
  __int64 v9; // x20
  __int64 (__fastcall *v10)(__int64, __int64, __int64, _QWORD); // x8
  __int64 v11; // x0
  __int64 v12; // x2
  __int64 v13; // t1
  __int64 v14; // x8
  unsigned int v15; // [xsp+4Ch] [xbp+2Ch]

  if ( a2 )
  {
    if ( (a3 & 1) != 0 )
    {
      v7 = *(_QWORD *)(a2 + 184);
      result = *(_QWORD *)(v7 + 656);
      if ( result )
      {
        if ( *(_BYTE *)(v7 + 664) == 1 )
          return ipc_log_string(
                   result,
                   ",%d,_,%x,%x\n",
                   *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40),
                   *(_DWORD *)(a2 + 672),
                   *(_DWORD *)(a2 + 676));
      }
    }
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v15 = v5;
      *(_DWORD *)(v6 - 4) = v4;
      ++*(_DWORD *)(StatusReg + 16);
      v9 = qword_17568;
      if ( qword_17568 )
      {
        do
        {
          v10 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD))v9;
          v11 = *(_QWORD *)(v9 + 8);
          v12 = *(unsigned int *)(v6 - 4);
          if ( *(_DWORD *)(*(_QWORD *)v9 - 4LL) != -1677128442 )
            __break(0x8228u);
          result = v10(v11, a4, v12, v15);
          v13 = *(_QWORD *)(v9 + 24);
          v9 += 24;
        }
        while ( v13 );
      }
      v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v14;
      if ( !v14 || !*(_QWORD *)(StatusReg + 16) )
        return preempt_schedule_notrace(result);
    }
  }
  return result;
}
