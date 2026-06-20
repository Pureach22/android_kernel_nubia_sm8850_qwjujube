__int64 __fastcall _err_log(__int64 result, _DWORD *a2, __int64 a3, int a4)
{
  unsigned __int64 StatusReg; // x8

  if ( (result & 1) != 0 )
    *a2 = a4;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    return printk(&unk_9572D, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
  }
  return result;
}
