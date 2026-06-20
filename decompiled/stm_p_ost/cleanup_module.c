__int64 cleanup_module()
{
  return stm_unregister_protocol(&ost_pdrv);
}
