__int64 gsi_pending_irq_type()
{
  return gsihal_read_reg_nk(6, *(unsigned int *)(gsi_ctx + 20), 0);
}
