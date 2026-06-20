__int64 qdf_register_blocking_notifier_chain()
{
  __int64 v0; // x0

  v0 = blocking_notifier_chain_register();
  return qdf_status_from_os_return(v0);
}
