__int64 __fastcall msm_cvp_smmu_fault_handler(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  int v7; // w8
  __int64 result; // x0
  unsigned __int64 v9; // x8
  int v10; // w8
  int v11; // w9
  _QWORD *i; // x20
  __int64 v13; // x0
  __int64 v14; // x8
  void (*v15)(void); // x8
  unsigned __int64 StatusReg; // x8

  if ( a1 && a5 )
  {
    if ( (unsigned int)__ratelimit(&msm_cvp_smmu_fault_handler__rs, "msm_cvp_smmu_fault_handler") )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_91C90, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
    v7 = *(_DWORD *)(a5 + 1252);
    *(_DWORD *)(a5 + 51292) = v7;
    if ( v7 )
    {
      *(_DWORD *)(a5 + 1252) = v7 + 1;
    }
    else
    {
      mutex_lock(a5);
      v10 = *(_DWORD *)(a5 + 1252);
      v11 = *(_DWORD *)(a5 + 1256);
      *(_DWORD *)(a5 + 51288) = a3;
      *(_DWORD *)(a5 + 1252) = v10 + 1;
      if ( !v11 )
        *(_DWORD *)(a5 + 1256) = a3;
      for ( i = *(_QWORD **)(a5 + 280); i != (_QWORD *)(a5 + 280); i = (_QWORD *)*i )
      {
        cvp_print_inst(1, (__int64)i);
        ((void (__fastcall *)(_QWORD *, __int64))msm_cvp_print_inst_bufs)(i, 1);
      }
      v13 = **(_QWORD **)(a5 + 256);
      if ( v13 )
      {
        *(_DWORD *)(v13 + 32) = -2147483629;
        v14 = *(_QWORD *)(a5 + 256);
        if ( v14 )
        {
          v15 = *(void (**)(void))(v14 + 192);
          if ( v15 )
          {
            if ( *((_DWORD *)v15 - 1) != -1066802076 )
              __break(0x8228u);
            v15();
          }
        }
      }
      mutex_unlock(a5);
    }
    return 4294967258LL;
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v9 = _ReadStatusReg(SP_EL0);
      printk(&unk_9070B, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
