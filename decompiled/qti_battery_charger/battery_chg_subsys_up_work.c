__int64 __fastcall battery_chg_subsys_up_work(__int64 a1)
{
  __int64 v2; // x20
  char v3; // w8
  unsigned int v4; // w0
  __int64 result; // x0
  unsigned int v6; // w21
  unsigned int v7; // w8
  int v8; // w10
  __int64 v9; // [xsp+Ch] [xbp-24h] BYREF
  int v10; // [xsp+14h] [xbp-1Ch]
  __int64 v11; // [xsp+18h] [xbp-18h]
  __int64 v12; // [xsp+20h] [xbp-10h]
  __int64 v13; // [xsp+28h] [xbp-8h]

  v2 = a1 - 560;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_BYTE *)(a1 + 604);
  v11 = 0;
  v12 = 0;
  if ( (v3 & 1) == 0 )
  {
    v9 = 0x20000800ALL;
    v10 = 4;
    v4 = battery_chg_write(a1 - 560, (__int64)&v9, 0x1Cu, 0x3E8u);
    if ( (v4 & 0x80000000) != 0 )
      printk(&unk_11A0A, "battery_chg_notify_enable", v4);
    else
      *(_BYTE *)(a1 + 604) = 1;
  }
  result = msleep(200);
  v6 = *(_DWORD *)(a1 + 568);
  if ( !v6 )
  {
LABEL_13:
    if ( !*(_DWORD *)(a1 + 572) )
      goto LABEL_16;
    goto LABEL_14;
  }
  if ( *(_BYTE *)(a1 + 580) == 1 )
  {
    v7 = *(_DWORD *)(a1 + 564);
    if ( v7 >= v6 )
      v7 = *(_DWORD *)(a1 + 568);
    if ( v7 >= *(_DWORD *)(a1 + 560) )
      v6 = *(_DWORD *)(a1 + 560);
    else
      v6 = v7;
  }
  v8 = *(_DWORD *)(a1 - 168);
  LODWORD(v12) = v6;
  v11 = 0xA00000000LL;
  v9 = 0x10000800ALL;
  v10 = v8;
  result = battery_chg_write(v2, (__int64)&v9, 0x18u, 0x3E8u);
  if ( (result & 0x80000000) == 0 )
  {
    *(_DWORD *)(a1 + 568) = v6;
    goto LABEL_13;
  }
  printk(&unk_FE40, "__battery_psy_set_charge_current", v6);
  result = printk(&unk_106FB, "battery_chg_subsys_up_work", *(unsigned int *)(a1 + 568));
  if ( !*(_DWORD *)(a1 + 572) )
    goto LABEL_16;
LABEL_14:
  result = usb_psy_set_icl(v2, 5);
  if ( (result & 0x80000000) != 0 )
    result = printk(&unk_10DAA, "battery_chg_subsys_up_work", *(unsigned int *)(a1 + 572));
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
