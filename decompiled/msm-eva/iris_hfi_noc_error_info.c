__int64 __fastcall iris_hfi_noc_error_info(__int64 a1)
{
  __int64 v2; // x8
  void (__fastcall *v3)(_QWORD); // x8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v6; // x8

  if ( a1 )
  {
    mutex_lock(a1 + 80);
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_83A36, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      v2 = *(_QWORD *)(a1 + 2512);
      if ( v2 )
      {
LABEL_5:
        v3 = *(void (__fastcall **)(_QWORD))(v2 + 48);
        if ( v3 )
        {
          if ( *((_DWORD *)v3 - 1) != -639316779 )
            __break(0x8228u);
          v3(a1);
        }
      }
    }
    else
    {
      v2 = *(_QWORD *)(a1 + 2512);
      if ( v2 )
        goto LABEL_5;
    }
    mutex_unlock(a1 + 80);
    return 0;
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v6 = _ReadStatusReg(SP_EL0);
    printk(&unk_95952, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  return result;
}
