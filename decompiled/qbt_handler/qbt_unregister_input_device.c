__int64 __fastcall qbt_unregister_input_device(__int64 a1)
{
  printk(&unk_9DD2, "qbt_unregister_input_device");
  return input_unregister_device(*(_QWORD *)(a1 + 280));
}
