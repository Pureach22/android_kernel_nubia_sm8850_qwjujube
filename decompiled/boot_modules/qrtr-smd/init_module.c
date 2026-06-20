__int64 init_module()
{
  return _register_rpmsg_driver(&qcom_smd_qrtr_driver, &_this_module);
}
