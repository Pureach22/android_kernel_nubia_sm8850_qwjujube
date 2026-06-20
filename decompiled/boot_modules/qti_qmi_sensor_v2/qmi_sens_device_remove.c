__int64 qmi_sens_device_remove()
{
  qmi_ts_cleanup();
  return unregister_pm_notifier(&qmi_sensor_pm_nb);
}
