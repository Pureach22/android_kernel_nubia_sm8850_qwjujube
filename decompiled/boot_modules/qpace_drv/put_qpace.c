__int64 put_qpace()
{
  mutex_lock(&qpace_ref_lock);
  if ( !--active_rings )
  {
    dev_pm_qos_update_request(&qos_req, 0x7FFFFFFF);
    pm_relax(qpace_dev);
    rings_inited_since_activation = 0;
  }
  return mutex_unlock(&qpace_ref_lock);
}
