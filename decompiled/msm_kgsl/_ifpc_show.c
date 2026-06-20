bool ifpc_show()
{
  return (unsigned int)gmu_core_dev_ifpc_isenabled() != 0;
}
