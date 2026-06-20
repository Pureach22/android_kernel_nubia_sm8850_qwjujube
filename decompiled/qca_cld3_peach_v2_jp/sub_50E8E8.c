__int64 sub_50E8E8()
{
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  return dp_tx_desc_pool_alloc();
}
