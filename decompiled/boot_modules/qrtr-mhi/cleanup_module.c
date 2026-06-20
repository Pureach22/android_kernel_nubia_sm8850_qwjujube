__int64 cleanup_module()
{
  return mhi_driver_unregister(&qcom_mhi_qrtr_driver);
}
