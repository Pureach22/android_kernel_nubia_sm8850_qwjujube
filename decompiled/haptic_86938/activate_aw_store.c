__int64 __fastcall activate_aw_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v8 = 0;
  v6 = kstrtouint(a3, 0, &v8);
  if ( v6 < 0 )
  {
    a4 = v6;
  }
  else
  {
    printk(&unk_14087, "haptic_hv", 2349, "activate_aw_store");
    if ( (*(_BYTE *)(v5 - 162) & 1) != 0 )
    {
      mutex_lock(v5 + 584);
      hrtimer_cancel(v5 + 648);
      *(_DWORD *)(v5 - 104) = v8;
      mutex_unlock(v5 + 584);
      queue_work_on(32, *(_QWORD *)(v5 + 928), v5 + 896);
    }
    else
    {
      printk(&unk_16977, "haptic_hv", 2351, "activate_aw_store");
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
