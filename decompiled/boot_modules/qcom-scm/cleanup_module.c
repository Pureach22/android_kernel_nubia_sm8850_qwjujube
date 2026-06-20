__int64 cleanup_module()
{
  _qcom_scm_qcpe_exit();
  qtee_shmbridge_driver_exit();
  return platform_driver_unregister(&qcom_scm_driver);
}
