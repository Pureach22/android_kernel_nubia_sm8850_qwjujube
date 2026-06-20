__int64 qcom_sdei_driver_remove()
{
  sdei_event_disable(0);
  sdei_event_unregister(0);
  sdei_event_disable(0x40000000);
  return sdei_event_unregister(0x40000000);
}
