size_t __fastcall reg_dma_read_clear_status_v1_to_v3(__int64 a1, __int64 a2)
{
  size_t result; // x0
  int v4; // w19
  int v5; // w6
  int v6; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  result = sde_reg_read(a2, reg_dma_intr_4_status_offset);
  if ( (_DWORD)result )
  {
    v4 = result;
    _drm_dev_dbg(0, 0, 0, "LUT dma status %x\n", result);
    sde_reg_write(a2, reg_dma_intr_4_clear_offset, reg_dma_error_clear_mask, "reg_dma_intr_4_clear_offset");
    return sde_evtlog_log(
             sde_dbg_base_evtlog,
             "reg_dma_read_clear_status_v1_to_v3",
             937,
             -1,
             v4,
             -1059143953,
             v5,
             v6,
             vars0);
  }
  return result;
}
