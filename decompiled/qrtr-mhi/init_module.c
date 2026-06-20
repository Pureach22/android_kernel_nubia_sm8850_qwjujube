__int64 init_module()
{
  return _mhi_driver_register(&qcom_mhi_qrtr_driver, &_this_module);
}
