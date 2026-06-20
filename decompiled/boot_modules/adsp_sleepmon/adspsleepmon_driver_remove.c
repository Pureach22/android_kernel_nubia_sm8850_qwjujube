__int64 __fastcall adspsleepmon_driver_remove(__int64 a1)
{
  qcom_unregister_ssr_notifier(qword_B188, &qword_B170);
  device_destroy(qword_A740, (unsigned int)dword_A738);
  class_destroy(qword_A740);
  cdev_del(&unk_A6B8);
  unregister_chrdev_region((unsigned int)dword_A748, 1);
  debugfs_remove(qword_B100);
  unregister_pm_notifier(&adsp_sleepmon_pm_nb);
  if ( byte_A636 == 1 )
  {
    unregister_rpmsg_driver(&sleepmon_rpmsg_client);
    qword_A680 = 0;
    dword_A678 = 0;
  }
  return dev_info(a1 + 16, "ADSP sleep monitor remove called\n");
}
