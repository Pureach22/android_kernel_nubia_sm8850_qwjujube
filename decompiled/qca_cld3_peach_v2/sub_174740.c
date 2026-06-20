__int64 sub_174740()
{
  unsigned int *v0; // x19

  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  atomic_load(v0);
  return hif_rtpm_log_debug_stats();
}
