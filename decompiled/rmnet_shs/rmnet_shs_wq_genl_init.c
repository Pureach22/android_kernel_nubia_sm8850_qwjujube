__int64 rmnet_shs_wq_genl_init()
{
  void *v0; // x19
  unsigned int v1; // w20
  int v2; // w8
  __int64 result; // x0

  v0 = &rmnet_shs_genl_family;
  rmnet_shs_userspace_connected = 0;
  if ( (unsigned int)genl_register_family(&rmnet_shs_genl_family) )
  {
    v1 = -1;
  }
  else
  {
    v0 = &rmnet_shs_genl_msg_family;
    v2 = genl_register_family(&rmnet_shs_genl_msg_family);
    v1 = 0;
    result = 0;
    if ( !v2 )
      return result;
  }
  genl_unregister_family(v0);
  return v1;
}
