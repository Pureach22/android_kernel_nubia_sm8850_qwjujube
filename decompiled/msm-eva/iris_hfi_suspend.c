__int64 __fastcall iris_hfi_suspend(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 result; // x0
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8
  unsigned __int64 StatusReg; // x8

  if ( a1 )
  {
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 2208) + 329LL) == 1 )
    {
      if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
        printk(&unk_89D2C, "core", a3, a4);
      if ( (unsigned int)mutex_trylock(a1 + 80) )
      {
        if ( (unsigned int)_power_collapse(a1, 1, v5, v6) )
        {
          if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            printk(&unk_8B28E, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
          }
          mutex_unlock(a1 + 80);
          return 4294967280LL;
        }
        else
        {
          mutex_unlock(a1 + 80);
          cancel_delayed_work(&iris_hfi_pm_work);
          return 0;
        }
      }
      else
      {
        result = 4294967280LL;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v9 = _ReadStatusReg(SP_EL0);
          printk(&unk_876E0, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), &unk_8E7CE);
          return 4294967280LL;
        }
      }
    }
    else
    {
      return 4294966772LL;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v8 = _ReadStatusReg(SP_EL0);
      printk(&unk_861CC, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
