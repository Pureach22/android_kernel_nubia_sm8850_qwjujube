__int64 __fastcall zte_usb_psy_get_prop(__int64 a1, int a2, _BOOL4 *a3)
{
  __int64 drvdata; // x0
  __int64 v6; // x20
  __int64 result; // x0
  _BOOL4 v8; // w8
  __int64 v9; // [xsp+0h] [xbp-20h] BYREF
  int v10; // [xsp+8h] [xbp-18h]
  __int64 v11; // [xsp+Ch] [xbp-14h]
  int v12; // [xsp+14h] [xbp-Ch]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  drvdata = zte_power_supply_get_drvdata();
  v6 = drvdata;
  if ( a2 == 18 )
  {
    v12 = 0;
    v11 = 0xF00000000LL;
    v9 = 0x10000800ALL;
    v10 = *(_DWORD *)(drvdata + 436);
    result = battery_chg_write(drvdata, (__int64)&v9, 0x18u, 0x3E8u);
    if ( (result & 0x80000000) == 0 )
    {
      v8 = *(_DWORD *)(*(_QWORD *)(v6 + 424) + 60LL) != 0;
      *(_BYTE *)(v6 + 1049) = v8;
      goto LABEL_7;
    }
  }
  else
  {
    if ( a2 != 17 )
    {
      result = 0;
      goto LABEL_9;
    }
    v12 = 0;
    v11 = 0xE00000000LL;
    v9 = 0x10000800ALL;
    v10 = *(_DWORD *)(drvdata + 436);
    result = battery_chg_write(drvdata, (__int64)&v9, 0x18u, 0x3E8u);
    if ( (result & 0x80000000) == 0 )
    {
      v8 = *(_DWORD *)(*(_QWORD *)(v6 + 424) + 56LL) != 0;
      *(_BYTE *)(v6 + 1048) = v8;
LABEL_7:
      result = 0;
      *a3 = v8;
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
