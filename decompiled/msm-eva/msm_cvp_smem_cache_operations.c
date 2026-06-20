__int64 __fastcall msm_cvp_smem_cache_operations(__int64 a1, int a2, unsigned int a3, unsigned int a4)
{
  __int64 result; // x0
  unsigned __int64 v8; // x8
  unsigned __int64 StatusReg; // x8

  if ( a1 )
  {
    switch ( a2 )
    {
      case 2:
        goto LABEL_5;
      case 1:
        result = dma_buf_begin_cpu_access_partial();
        if ( !(_DWORD)result )
          return dma_buf_end_cpu_access_partial(a1, 2, a3, a4);
        break;
      case 0:
LABEL_5:
        result = dma_buf_begin_cpu_access_partial();
        if ( !(_DWORD)result )
          return dma_buf_end_cpu_access_partial(a1, 0, a3, a4);
        return result;
      default:
        result = 4294967274LL;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          printk(&unk_882AE, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          return 4294967274LL;
        }
        break;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v8 = _ReadStatusReg(SP_EL0);
      printk(&unk_9307C, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
