__int64 cleanup_module()
{
  return unregister_rpmsg_driver(&qcom_smd_qrtr_driver);
}
