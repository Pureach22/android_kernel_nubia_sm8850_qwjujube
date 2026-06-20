__int64 qdf_blocking_notfier_call()
{
  __int64 v0; // x0

  v0 = blocking_notifier_call_chain();
  return qdf_status_from_os_return(v0);
}
