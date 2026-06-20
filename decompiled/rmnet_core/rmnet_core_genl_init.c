__int64 rmnet_core_genl_init()
{
  __int64 result; // x0

  result = genl_register_family(&rmnet_core_genl_family);
  if ( (_DWORD)result )
  {
    genl_unregister_family(&rmnet_core_genl_family);
    return 0xFFFFFFFFLL;
  }
  return result;
}
