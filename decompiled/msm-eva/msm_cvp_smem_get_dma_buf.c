unsigned __int64 msm_cvp_smem_get_dma_buf()
{
  unsigned __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  result = dma_buf_get();
  if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
  {
    result = 0;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8D065, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 0;
    }
  }
  return result;
}
