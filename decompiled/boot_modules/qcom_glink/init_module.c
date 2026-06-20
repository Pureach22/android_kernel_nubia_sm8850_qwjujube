__int64 init_module()
{
  return _register_rpmsg_driver(&qcom_glink_ssr_driver, &_this_module);
}
