__int64 __fastcall cvp_hfi_process_sys_init_done_prop_read(_DWORD *a1, __int64 a2)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x1
  __int64 v5; // x2
  void *v6; // x0
  unsigned __int64 v7; // x8
  unsigned __int64 v10; // x8
  unsigned int v11; // w20

  if ( a1 && a2 )
  {
    if ( *a1 == 16 )
    {
      result = 0x80000000LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        v4 = *(unsigned int *)(StatusReg + 1800);
        v5 = *(unsigned int *)(StatusReg + 1804);
        v6 = &unk_964C7;
LABEL_10:
        printk(v6, v4, v5, &unk_8E7CE);
        return 0x80000000LL;
      }
    }
    else
    {
      result = hfi_map_err_status((unsigned int)a1[2]);
      if ( (_DWORD)result )
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v10 = _ReadStatusReg(SP_EL0);
          v11 = result;
          printk(&unk_95A25, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), &unk_8E7CE);
          return v11;
        }
      }
      else
      {
        if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
          printk(&unk_96F61, "hfi", "cvp_hfi_process_sys_init_done_prop_read", a1 + 4);
        *(_QWORD *)(a2 + 16) = 0;
        return 0;
      }
    }
  }
  else
  {
    result = 0x80000000LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v7 = _ReadStatusReg(SP_EL0);
      v4 = *(unsigned int *)(v7 + 1800);
      v5 = *(unsigned int *)(v7 + 1804);
      v6 = &unk_8A953;
      goto LABEL_10;
    }
  }
  return result;
}
