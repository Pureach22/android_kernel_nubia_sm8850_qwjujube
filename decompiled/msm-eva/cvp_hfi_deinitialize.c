__int64 __fastcall cvp_hfi_deinitialize(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  if ( a2 )
  {
    cvp_iris_hfi_delete_device(*a2);
    return kfree(a2);
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    return printk(&unk_91FC3, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
  }
  return result;
}
