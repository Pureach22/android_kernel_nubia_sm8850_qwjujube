__int64 __fastcall msm_cvp_smem_put_dma_buf(__int64 result)
{
  unsigned __int64 StatusReg; // x8

  if ( result )
    return dma_heap_buffer_free();
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    return printk(&unk_82F3E, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
  }
  return result;
}
