__int64 __fastcall qmp_remove(__int64 a1)
{
  _QWORD *v1; // x19

  v1 = *(_QWORD **)(a1 + 168);
  debugfs_remove(v1[25]);
  debugfs_remove(v1[30]);
  of_clk_del_provider(*(_QWORD *)(v1[1] + 744LL));
  clk_hw_unregister(v1 + 21);
  thermal_cooling_device_unregister(*(_QWORD *)v1[24]);
  thermal_cooling_device_unregister(*(_QWORD *)(v1[24] + 32LL));
  writel(0xFFFF0000, (unsigned int *)(*v1 + 44LL));
  writel(0xFFFF0000, (unsigned int *)(*v1 + 36LL));
  mbox_send_message(v1[9], 0);
  mbox_client_txdone(v1[9], 0);
  return mbox_free_channel(v1[9]);
}
