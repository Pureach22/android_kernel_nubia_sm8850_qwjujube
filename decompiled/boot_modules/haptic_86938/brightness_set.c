__int64 __fastcall brightness_set(__int64 a1, int a2)
{
  printk(&unk_14A18, "haptic_hv", 2185, "brightness_set");
  if ( (*(_BYTE *)(a1 - 162) & 1) == 0 )
    return printk(&unk_16977, "haptic_hv", 2187, "brightness_set");
  mutex_lock(a1 + 584);
  *(_DWORD *)(a1 - 80) = a2;
  *(_DWORD *)(a1 - 104) = a2;
  *(_BYTE *)(a1 - 141) = 1;
  mutex_unlock(a1 + 584);
  return queue_work_on(32, *(_QWORD *)(a1 + 928), a1 + 896);
}
