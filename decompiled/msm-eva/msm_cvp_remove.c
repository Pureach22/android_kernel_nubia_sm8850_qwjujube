__int64 __fastcall msm_cvp_remove(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  unsigned __int64 v3; // x8
  unsigned __int64 StatusReg; // x8

  if ( result )
  {
    v1 = result;
    result = of_device_is_compatible(*(_QWORD *)(result + 760), "qcom,msm-cvp");
    if ( (_DWORD)result )
    {
      v2 = *(_QWORD *)(v1 + 168);
      if ( v2 )
      {
LABEL_4:
        cvp_hfi_deinitialize(*(unsigned int *)(v2 + 600), *(_QWORD *)(v2 + 256));
        msm_cvp_free_platform_resources(v2 + 608);
        sysfs_remove_group(v1 + 16, &msm_cvp_core_attr_group);
        *(_QWORD *)(v1 + 168) = 0;
        return kfree(v2);
      }
    }
    else
    {
      v2 = *(_QWORD *)(*(_QWORD *)(v1 + 112) + 152LL);
      if ( v2 )
        goto LABEL_4;
    }
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      return printk(&unk_91215, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v3 = _ReadStatusReg(SP_EL0);
    return printk(&unk_822E5, *(unsigned int *)(v3 + 1800), *(unsigned int *)(v3 + 1804), &unk_8E7CE);
  }
  return result;
}
