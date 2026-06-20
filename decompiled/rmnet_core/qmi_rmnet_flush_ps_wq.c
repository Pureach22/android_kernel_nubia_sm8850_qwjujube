__int64 qmi_rmnet_flush_ps_wq()
{
  __int64 result; // x0

  result = rmnet_ps_wq;
  if ( rmnet_ps_wq )
    return _flush_workqueue();
  return result;
}
