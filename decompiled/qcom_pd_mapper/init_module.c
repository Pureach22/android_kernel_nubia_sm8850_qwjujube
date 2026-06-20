__int64 init_module()
{
  return _auxiliary_driver_register(qcom_pdm_drv, &_this_module, "qcom_pd_mapper");
}
