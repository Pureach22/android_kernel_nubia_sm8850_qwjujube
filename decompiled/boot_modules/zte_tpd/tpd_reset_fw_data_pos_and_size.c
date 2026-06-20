void tpd_reset_fw_data_pos_and_size()
{
  __int64 v0; // x8

  v0 = tpd_cdev;
  **(_QWORD **)(tpd_cdev + 2720) = *(unsigned int *)(tpd_cdev + 1096);
  *(_DWORD *)(v0 + 1096) = 0;
}
