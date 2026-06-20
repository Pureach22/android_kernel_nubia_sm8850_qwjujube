__int64 get_qpace()
{
  int v0; // w8

  mutex_lock(&qpace_ref_lock);
  v0 = active_rings;
  if ( !active_rings )
  {
    pm_stay_awake(qpace_dev);
    dev_pm_qos_update_request(&qos_req, 300);
    v0 = active_rings;
  }
  active_rings = v0 + 1;
  return mutex_unlock(&qpace_ref_lock);
}
