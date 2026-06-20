__int64 cleanup_module()
{
  return genl_unregister_family(&family);
}
