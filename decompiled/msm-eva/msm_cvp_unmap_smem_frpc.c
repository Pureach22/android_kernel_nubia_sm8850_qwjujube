__int64 __fastcall msm_cvp_unmap_smem_frpc(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v13; // w10

  if ( a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64))print_smem_no_instance)(64, a3, a2);
    result = msm_cvp_unmap_smem_helper(a2);
    if ( !(_DWORD)result )
    {
      _X8 = (unsigned int *)(a1 + 6520);
      __asm { PRFM            #0x11, [X8] }
      do
        v13 = __ldxr(_X8);
      while ( __stxr(v13 - 1, _X8) );
      return 0;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_959B0, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
