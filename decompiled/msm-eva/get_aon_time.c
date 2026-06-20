unsigned __int64 get_aon_time()
{
  return _ReadStatusReg(CNTVCT_EL0);
}
