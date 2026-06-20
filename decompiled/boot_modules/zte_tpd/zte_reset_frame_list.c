__int64 __fastcall zte_reset_frame_list(__int64 a1)
{
  void *v2; // x0
  __int64 v3; // x2

  mutex_lock(a1 + 1136);
  v2 = *(void **)(a1 + 1120);
  *(_QWORD *)(a1 + 1084) = 0;
  memset(v2, 0, 0x32000u);
  mutex_unlock(a1 + 1136);
  return printk(&unk_365BE, "zte_reset_frame_list", v3);
}
