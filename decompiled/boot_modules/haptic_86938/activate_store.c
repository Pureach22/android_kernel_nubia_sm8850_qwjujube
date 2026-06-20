__int64 __fastcall activate_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  int v6; // w0
  void (__fastcall *v8)(__int64, __int64); // x8
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v9 = 0;
  v6 = kstrtouint(a3, 0, &v9);
  if ( v6 < 0 )
  {
    a4 = v6;
  }
  else
  {
    printk(&unk_14087, "haptic_hv", 2275, "activate_store");
    if ( (*(_BYTE *)(v5 - 162) & 1) != 0 )
    {
      mutex_lock(v5 + 584);
      v8 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v5 + 1312) + 128LL);
      if ( *((_DWORD *)v8 - 1) != 487251822 )
        __break(0x8228u);
      v8(v5 - 168, 1);
      hrtimer_cancel(v5 + 648);
      *(_DWORD *)(v5 - 104) = v9;
      mutex_unlock(v5 + 584);
      queue_work_on(32, *(_QWORD *)(v5 + 928), v5 + 896);
    }
    else
    {
      printk(&unk_16977, "haptic_hv", 2277, "activate_store");
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
