__int64 __fastcall msm_cvp_pm_suspend(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w19
  unsigned int v3; // w0
  unsigned int v4; // w8
  unsigned __int64 v5; // x8
  unsigned __int64 StatusReg; // x9

  if ( result )
  {
    if ( *(_QWORD *)(result + 136) )
    {
      v1 = result;
      result = of_device_is_compatible(*(_QWORD *)(result + 744), "qcom,msm-cvp");
      if ( !(_DWORD)result )
        return result;
      if ( *(_QWORD *)(v1 + 152) )
      {
        v2 = 0;
        v3 = msm_cvp_suspend();
        if ( v3 != -524 )
        {
          v4 = v3;
          result = 0;
          if ( !v4 )
            return result;
          if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
            return v4;
          StatusReg = _ReadStatusReg(SP_EL0);
          v2 = v4;
          printk(&unk_87FDF, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
        }
        return v2;
      }
      else
      {
        result = 4294967274LL;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v5 = _ReadStatusReg(SP_EL0);
          printk(&unk_889E9, *(unsigned int *)(v5 + 1800), *(unsigned int *)(v5 + 1804), &unk_8E7CE);
          return 4294967274LL;
        }
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
