__int64 __fastcall msm_cvp_cache_operations(__int64 result, int a2, unsigned int a3, unsigned int a4)
{
  int v4; // w9
  int v5; // w1
  int v6; // w19
  unsigned int v7; // w20
  unsigned int v8; // w21
  __int64 v9; // x22
  unsigned __int64 StatusReg; // x8

  if ( (msm_cvp_cacheop_disabled & 1) == 0 )
  {
    if ( result )
    {
      if ( a2 == 2 )
        v4 = 1;
      else
        v4 = 2;
      if ( a2 == 1 )
        v5 = 0;
      else
        v5 = v4;
      if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
      {
        v6 = v5;
        v7 = a3;
        v8 = a4;
        v9 = result;
        printk(&unk_8D211, &unk_84256, "msm_cvp_cache_operations", *(_QWORD *)(result + 48));
        v5 = v6;
        result = v9;
        a3 = v7;
        a4 = v8;
      }
      return msm_cvp_smem_cache_operations(*(_QWORD *)(result + 48), v5, a3, a4);
    }
    else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      return printk(&unk_912BD, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
  }
  return result;
}
