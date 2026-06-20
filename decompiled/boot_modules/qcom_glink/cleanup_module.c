__int64 cleanup_module()
{
  return unregister_rpmsg_driver(&qcom_glink_ssr_driver);
}
