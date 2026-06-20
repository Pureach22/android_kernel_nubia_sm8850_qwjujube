void __fastcall walt_cfs_check_preempt_wakeup_fair(__int64 a1, __int64 a2, char *a3, _BYTE *a4, _BYTE *a5)
{
  __int64 v5; // x19
  __int64 v6; // x20
  __int64 v7; // x8
  char *v8; // x21
  _QWORD *v9; // x20
  _QWORD *v10; // x23
  __int64 v11; // x10
  _QWORD *v12; // x8
  _QWORD *v13; // x9
  void **v15; // x25
  int v16; // w27
  unsigned __int64 StatusReg; // x21
  __int64 v19; // x0
  __int64 v20; // x8

  v7 = *(unsigned int *)(a2 + 3632);
  if ( (unsigned int)v7 >= 0x20 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v19 = _traceiter_walt_cfs_mvp_wakeup_preempt(0, v5, v6, (unsigned int)a4);
      v20 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v20;
      if ( !v20 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v19);
    }
  }
  else
  {
    v8 = *(char **)(a2 + 3344);
    if ( a3 == (char *)&init_task )
      v9 = &vendor_data_pad;
    else
      v9 = a3 + 5184;
    if ( v8 == (char *)&init_task )
      v10 = &vendor_data_pad;
    else
      v10 = v8 + 5184;
    if ( (walt_disabled & 1) == 0 )
    {
      v11 = *((_QWORD *)&_per_cpu_offset + v7);
      v12 = (_QWORD *)v9[36];
      v13 = (_QWORD *)v10[36];
      v15 = (void **)&walt_rq[v11];
      if ( v13 != v10 + 36 && v13 )
      {
        v16 = *((unsigned __int8 *)v15 + 608);
        ((void (__fastcall *)(__int64, _QWORD))walt_cfs_account_mvp_runtime)(a2, *(_QWORD *)(a2 + 3344));
        if ( v16 == *((unsigned __int8 *)v15 + 608)
          && v15[71] == v10 + 36
          && *((_DWORD *)v9 + 82) <= *((_DWORD *)v10 + 82) )
        {
          *a5 = 1;
          return;
        }
        goto LABEL_18;
      }
      if ( v12 != v9 + 36 && v12 && ((_BYTE)v15[76] & 1) == 0 )
LABEL_18:
        *a4 = 1;
    }
  }
}
