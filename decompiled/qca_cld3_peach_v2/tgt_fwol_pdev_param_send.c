__int64 __fastcall tgt_fwol_pdev_param_send(__int64 a1)
{
  __int64 *v1; // x8
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( a1 && (v1 = *(__int64 **)(a1 + 1240)) != nullptr && *v1 )
    result = wmi_unified_pdev_param_send(*v1);
  else
    result = 16;
  _ReadStatusReg(SP_EL0);
  return result;
}
