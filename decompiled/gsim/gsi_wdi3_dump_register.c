__int64 __fastcall gsi_wdi3_dump_register(unsigned int a1)
{
  if ( !gsi_ctx )
    return printk(&unk_2DEB9, "gsi_wdi3_dump_register", 5585);
  gsihal_read_reg_nk(8, *(unsigned int *)(gsi_ctx + 20), a1);
  gsihal_read_reg_nk(52, *(unsigned int *)(gsi_ctx + 20), a1);
  gsihal_read_reg_nk(53, *(unsigned int *)(gsi_ctx + 20), a1);
  gsihal_read_reg_nk(54, *(unsigned int *)(gsi_ctx + 20), a1);
  gsihal_read_reg_nk(66, *(unsigned int *)(gsi_ctx + 20), a1);
  gsihal_read_reg_nk(67, *(unsigned int *)(gsi_ctx + 20), a1);
  gsihal_read_reg_nk(68, *(unsigned int *)(gsi_ctx + 20), a1);
  gsihal_read_reg_nk(69, *(unsigned int *)(gsi_ctx + 20), a1);
  gsihal_read_reg_nk(120, *(unsigned int *)(gsi_ctx + 20), a1);
  gsihal_read_reg_nk(121, *(unsigned int *)(gsi_ctx + 20), a1);
  gsihal_read_reg_nk(51, *(unsigned int *)(gsi_ctx + 20), a1);
  gsihal_read_reg_nk(56, *(unsigned int *)(gsi_ctx + 20), a1);
  gsihal_read_reg_nk(57, *(unsigned int *)(gsi_ctx + 20), a1);
  gsihal_read_reg_nk(58, *(unsigned int *)(gsi_ctx + 20), a1);
  return gsihal_read_reg_nk(59, *(unsigned int *)(gsi_ctx + 20), a1);
}
