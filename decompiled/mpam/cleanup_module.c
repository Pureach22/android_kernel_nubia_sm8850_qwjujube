__int64 cleanup_module()
{
  __int64 v0; // x0

  v0 = platform_driver_unregister(qcom_mpam_driver);
  return qcom_mpam_rpmsg_exit(v0);
}
