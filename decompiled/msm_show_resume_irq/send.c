__int64 __fastcall send(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v5; // x2
  __int64 v6; // x2
  _QWORD v8[12]; // [xsp+0h] [xbp-80h] BYREF
  int v9; // [xsp+60h] [xbp-20h]
  _QWORD v10[3]; // [xsp+68h] [xbp-18h] BYREF

  v10[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  memset(v8, 0, sizeof(v8));
  snprintf((char *)v8, 0x64u, "UID=%s", a3);
  v10[0] = v8;
  v10[1] = 0;
  if ( state )
  {
    send_unfreeze_event((__int64)"KILL", 1000, v5);
    kobject_uevent_env(dev, 2, v10);
  }
  else
  {
    printk(&unk_6FE0, 0, v5);
  }
  printk(&unk_7061, v8, v6);
  _ReadStatusReg(SP_EL0);
  return a4;
}
