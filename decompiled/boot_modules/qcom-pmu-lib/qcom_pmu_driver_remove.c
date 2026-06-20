__int64 qcom_pmu_driver_remove()
{
  qcom_pmu_inited = 0;
  return delete_events();
}
