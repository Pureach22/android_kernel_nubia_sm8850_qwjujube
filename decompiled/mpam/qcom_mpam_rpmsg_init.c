__int64 qcom_mpam_rpmsg_init()
{
  rpmsg_complete = 0;
  _init_swait_queue_head(&algn_6964[4], "&x->wait", &init_completion___key);
  return _register_rpmsg_driver(&qcom_mpam_rpmsg_driver, &_this_module);
}
