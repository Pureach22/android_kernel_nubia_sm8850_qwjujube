__int64 cvp_dsp_device_exit()
{
  mutex_lock(&gfa_cv);
  dword_6C668 = 0;
  mutex_unlock(&gfa_cv);
  complete_all(&dword_6C688);
  complete_all(&dword_6C6A8);
  complete_all(&dword_6C6C8);
  complete_all(&dword_6C6E8);
  complete_all(&dword_6C708);
  complete_all(&dword_6C728);
  complete_all(&dword_6C748);
  complete_all(&dword_6C768);
  complete_all(&dword_6C788);
  return unregister_rpmsg_driver(&cvp_dsp_rpmsg_client);
}
