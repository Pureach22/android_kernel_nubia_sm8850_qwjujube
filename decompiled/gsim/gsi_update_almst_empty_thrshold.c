__int64 __fastcall gsi_update_almst_empty_thrshold(__int64 a1)
{
  return gsihal_write_reg_nk(147, *(unsigned int *)(gsi_ctx + 20), a1);
}
