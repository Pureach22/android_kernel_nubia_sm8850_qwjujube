__int64 __fastcall qcom_smd_unregister_edge(__int64 a1)
{
  int v2; // w0

  disable_irq(*(unsigned int *)(a1 + 936));
  cancel_work_sync(a1 + 1096);
  cancel_work_sync(a1 + 1128);
  v2 = device_for_each_child(a1, 0, qcom_smd_remove_device);
  if ( v2 )
    dev_warn(a1, "can't remove smd device: %d\n", v2);
  mbox_free_channel(*(_QWORD *)(a1 + 1016));
  return device_unregister(a1);
}
