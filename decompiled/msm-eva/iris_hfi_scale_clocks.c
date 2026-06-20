__int64 __fastcall iris_hfi_scale_clocks(__int64 a1, unsigned int a2)
{
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x3
  unsigned int v7; // w20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x8

  if ( a1 )
  {
    mutex_lock(a1 + 80);
    if ( (unsigned int)_resume(a1, v4, v5, v6) )
    {
      v7 = -19;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_82ECE, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
    }
    else
    {
      v7 = msm_cvp_set_clocks_impl(a1, a2);
    }
    mutex_unlock(a1 + 80);
  }
  else
  {
    v7 = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v9 = _ReadStatusReg(SP_EL0);
      printk(&unk_900F7, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), &unk_8E7CE);
    }
  }
  return v7;
}
