__int64 __fastcall zte_ir_release(__int64 a1, __int64 a2)
{
  __int64 v3; // x1

  mutex_lock(&device_list_lock);
  *(_QWORD *)(a2 + 32) = 0;
  printk(&unk_6F0C, v3);
  mutex_unlock(&device_list_lock);
  return 0;
}
