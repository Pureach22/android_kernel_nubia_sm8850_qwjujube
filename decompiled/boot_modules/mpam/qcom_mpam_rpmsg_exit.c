__int64 qcom_mpam_rpmsg_exit()
{
  complete_all(&rpmsg_complete);
  return unregister_rpmsg_driver(&qcom_mpam_rpmsg_driver);
}
