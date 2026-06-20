__int64 __fastcall zte_battery_psy_set_prop(__int64 a1, int a2, _DWORD *a3)
{
  __int64 drvdata; // x0
  bool v6; // zf
  __int64 result; // x0
  int v8; // w10
  __int64 v9; // [xsp+0h] [xbp-20h] BYREF
  int v10; // [xsp+8h] [xbp-18h]
  __int64 v11; // [xsp+Ch] [xbp-14h]
  int v12; // [xsp+14h] [xbp-Ch]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  drvdata = zte_power_supply_get_drvdata();
  if ( a2 == 4 )
  {
    v6 = *a3 == 1;
    *(_BYTE *)(drvdata + 1047) = v6;
    if ( v6 )
    {
      v11 = 0x1F00000000LL;
      v8 = *(_DWORD *)(drvdata + 392);
      v12 = -1;
    }
    else
    {
      v8 = *(_DWORD *)(drvdata + 392);
      v12 = 0;
      v11 = 0x1F00000000LL;
    }
    v9 = 0x10000800ALL;
    v10 = v8;
    result = battery_chg_write(drvdata, (__int64)&v9, 0x18u, 0x3E8u);
  }
  else if ( a2 == 3 )
  {
    v6 = *a3 == 1;
    *(_BYTE *)(drvdata + 1046) = v6;
    if ( v6 )
      result = usb_psy_set_icl((_DWORD *)drvdata, 5, 0xFFFFFFFF);
    else
      result = usb_psy_set_icl((_DWORD *)drvdata, 5, 0xBF68u);
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
