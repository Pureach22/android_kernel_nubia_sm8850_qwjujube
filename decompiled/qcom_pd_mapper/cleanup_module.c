__int64 cleanup_module()
{
  return auxiliary_driver_unregister(qcom_pdm_drv);
}
