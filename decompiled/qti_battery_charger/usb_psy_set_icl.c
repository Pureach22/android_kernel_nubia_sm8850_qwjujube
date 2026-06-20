__int64 __fastcall usb_psy_set_icl(_DWORD *a1, int a2, unsigned int a3)
{
  int v6; // w9
  unsigned int v7; // w19
  int v8; // w8
  __int64 v10; // [xsp+0h] [xbp-20h] BYREF
  int v11; // [xsp+8h] [xbp-18h]
  __int64 v12; // [xsp+Ch] [xbp-14h]
  unsigned int v13; // [xsp+14h] [xbp-Ch]
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0x700000000LL;
  v6 = a1[109];
  v13 = 0;
  v10 = 0x10000800ALL;
  v11 = v6;
  v7 = battery_chg_write((__int64)a1, (__int64)&v10, 0x18u, 0x3E8u);
  if ( (v7 & 0x80000000) != 0 )
  {
    printk(&unk_10730, "usb_psy_set_icl", v7);
  }
  else
  {
    if ( (a3 & 0x80000000) != 0 )
      a3 = -1;
    if ( a3 <= 0x7D0 )
    {
      printk(&unk_FCC2, "usb_psy_set_icl", a3);
    }
    else
    {
      v10 = 0x10000800ALL;
      v8 = a1[110];
      HIDWORD(v12) = a2;
      v13 = a3;
      v11 = v8;
      LODWORD(v12) = 0;
      v7 = battery_chg_write((__int64)a1, (__int64)&v10, 0x18u, 0x3E8u);
      if ( (v7 & 0x80000000) != 0 )
        printk(&unk_105D5, "usb_psy_set_icl", a3);
      else
        a1[283] = a3;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
