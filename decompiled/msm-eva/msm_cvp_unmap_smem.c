__int64 __fastcall msm_cvp_unmap_smem(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v6; // w21
  unsigned __int64 StatusReg; // x8
  unsigned int v14; // w10

  if ( a2 )
  {
    print_smem(64, a3, a1, a2);
    result = msm_cvp_unmap_smem_helper(a2);
    if ( !(_DWORD)result )
    {
      _X8 = (unsigned int *)(a1 + 168);
      __asm { PRFM            #0x11, [X8] }
      do
        v14 = __ldxr(_X8);
      while ( __stxr(v14 - 1, _X8) );
    }
    if ( (msm_cvp_sw_dbg_buf_dump & 2) != 0 )
    {
      v6 = result;
      eva_kmd_buf_dump(a1, a2, 1);
      return v6;
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
