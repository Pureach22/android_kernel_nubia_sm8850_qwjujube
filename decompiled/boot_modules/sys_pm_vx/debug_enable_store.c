__int64 __fastcall debug_enable_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v7 = 0;
  if ( (unsigned int)kstrtoint(a3, 0, &v7) )
  {
    a4 = -22;
  }
  else if ( v7 >= 2 )
  {
    printk(&unk_753B, "debug_enable_store");
    a4 = -22;
  }
  else
  {
    mutex_lock(v5 + 48);
    *(_BYTE *)(v5 + 120) = v7 != 0;
    mutex_unlock(v5 + 48);
    subsystem_sleep_debug_enable(*(unsigned __int8 *)(v5 + 120));
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
