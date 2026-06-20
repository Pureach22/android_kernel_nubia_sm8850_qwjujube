__int64 __fastcall screen_is_on_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 result; // x0
  __int64 v8; // x3
  int v9; // w9
  __int64 v10; // x8
  int v11; // w8
  __int64 v12; // x2
  __int64 v13; // [xsp+0h] [xbp-20h] BYREF
  int v14; // [xsp+8h] [xbp-18h]
  __int64 v15; // [xsp+Ch] [xbp-14h]
  int v16; // [xsp+14h] [xbp-Ch]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v4 = a1 - 8;
  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 == 8 || (unsigned int)kstrtobool(a3, a1 + 1044) )
  {
    result = -22;
  }
  else
  {
    printk(&unk_103F1, "screen_is_on_store", *(unsigned __int8 *)(a1 + 1044));
    cancel_delayed_work_sync(a1 + 784);
    if ( *(_BYTE *)(a1 + 1044) )
      v8 = 17500;
    else
      v8 = 250;
    queue_delayed_work_on(32, system_wq, a1 + 784, v8);
    v9 = *(unsigned __int8 *)(a1 + 1044);
    v10 = a1;
    if ( v9 == 1 )
    {
      cancel_delayed_work(a1 + 896);
      queue_delayed_work_on(32, system_wq, a1 + 896, 13);
      printk(&unk_1144D, "screen_is_on_store", v12);
      v9 = *(unsigned __int8 *)(a1 + 1044);
      v10 = a1;
    }
    v16 = v9;
    v11 = *(_DWORD *)(v10 + 384);
    v15 = 0x2600000000LL;
    v13 = 0x10000800ALL;
    v14 = v11;
    battery_chg_write(v4, (__int64)&v13, 0x18u, 0x3E8u);
    result = a4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
