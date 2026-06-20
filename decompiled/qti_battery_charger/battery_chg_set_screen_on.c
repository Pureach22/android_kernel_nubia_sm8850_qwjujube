__int64 __fastcall battery_chg_set_screen_on(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x3
  int v5; // w8
  int v6; // w10
  __int64 v7; // x2
  __int64 v8; // [xsp+0h] [xbp-20h] BYREF
  int v9; // [xsp+8h] [xbp-18h]
  __int64 v10; // [xsp+Ch] [xbp-14h]
  int v11; // [xsp+14h] [xbp-Ch]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 && !(unsigned int)kstrtobool(a1, a2 + 1052) )
  {
    printk(&unk_10465, "battery_chg_set_screen_on", *(unsigned __int8 *)(a2 + 1052));
    cancel_delayed_work_sync(a2 + 792);
    if ( *(_BYTE *)(a2 + 1052) )
      v4 = 17500;
    else
      v4 = 250;
    queue_delayed_work_on(32, system_wq, a2 + 792, v4);
    v5 = *(unsigned __int8 *)(a2 + 1052);
    if ( v5 == 1 )
    {
      cancel_delayed_work(a2 + 904);
      queue_delayed_work_on(32, system_wq, a2 + 904, 13);
      printk(&unk_1144D, "battery_chg_set_screen_on", v7);
      v5 = *(unsigned __int8 *)(a2 + 1052);
    }
    v11 = v5;
    v6 = *(_DWORD *)(a2 + 392);
    v10 = 0x2600000000LL;
    v8 = 0x10000800ALL;
    v9 = v6;
    battery_chg_write(a2, &v8, 24, 1000);
    result = 0;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
