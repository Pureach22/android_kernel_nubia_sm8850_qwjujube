__int64 __fastcall slim_unregister_controller(__int64 a1)
{
  device_for_each_child(*(_QWORD *)a1, 0, slim_ctrl_remove_device);
  ida_free(&ctrl_ida, *(unsigned int *)(a1 + 8));
  return 0;
}
