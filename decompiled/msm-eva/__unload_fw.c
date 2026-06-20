__int64 __fastcall _unload_fw(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x1
  __int64 v3; // x2
  __int64 v4; // x3
  unsigned __int64 StatusReg; // x8

  if ( *(_DWORD *)(result + 2200) )
  {
    v1 = result;
    cancel_delayed_work(&iris_hfi_pm_work);
    if ( *(_DWORD *)(v1 + 2408) != 1 )
      _flush_workqueue(*(_QWORD *)(v1 + 2184));
    unload_cvp_fw_impl(v1);
    power_off_iris2(v1);
    result = _deinit_resources((_QWORD *)v1, v2, v3, v4);
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      return printk(&unk_958D5, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    }
  }
  return result;
}
