__int64 cleanup_module()
{
  __int64 result; // x0

  smem_mailbox_stop(*(unsigned int *)(cnss_utils_priv + 560));
  result = kfree(cnss_utils_priv);
  cnss_utils_priv = 0;
  return result;
}
