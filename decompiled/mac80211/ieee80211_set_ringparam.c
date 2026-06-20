__int64 __fastcall ieee80211_set_ringparam(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v5; // x19
  __int64 (__fastcall *v6)(__int64, __int64, __int64); // x8
  unsigned int v7; // w19
  unsigned __int64 StatusReg; // x21
  unsigned int v9; // w19
  __int64 v10; // x0
  __int64 v11; // x8
  unsigned int v12; // [xsp+1Ch] [xbp+1Ch]

  v3 = **(_QWORD **)(a1 + 992);
  if ( v3 )
  {
    if ( *(_DWORD *)(a2 + 24) || *(_DWORD *)(a2 + 28) )
      return 4294967274LL;
    v5 = a2;
    mutex_lock(*(_QWORD *)(v3 + 1608));
    a2 = *(unsigned int *)(v5 + 32);
    a3 = *(unsigned int *)(v5 + 20);
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v9 = a3;
      ++*(_DWORD *)(StatusReg + 16);
      v12 = a2;
      v10 = _traceiter_drv_set_ringparam(0, 1536, (unsigned int)a2, (unsigned int)a3);
      a2 = v12;
      v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v11;
      if ( !v11 || (a3 = v9, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(v10);
        a2 = v12;
        a3 = v9;
      }
    }
  }
  v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v3 + 2000) + 488LL);
  if ( v6 )
  {
    if ( *((_DWORD *)v6 - 1) != 2126203277 )
      __break(0x8228u);
    v7 = v6(v3 + 1536, a2, a3);
  }
  else
  {
    v7 = -95;
  }
  mutex_unlock(*(_QWORD *)(v3 + 1608));
  return v7;
}
