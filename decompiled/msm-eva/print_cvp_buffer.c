__int64 __fastcall print_cvp_buffer(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x8

  if ( a3 && a4 )
    return print_smem(result, a2, a3, *(_QWORD *)(a4 + 56));
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    return printk(&unk_8784B, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
  }
  return result;
}
