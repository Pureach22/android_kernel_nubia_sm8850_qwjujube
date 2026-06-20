__int64 __fastcall usb_real_type_show(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w9
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x11
  char **v9; // x9
  const char *v10; // x3
  __int64 v11; // [xsp+0h] [xbp-20h] BYREF
  int v12; // [xsp+8h] [xbp-18h]
  __int64 v13; // [xsp+Ch] [xbp-14h]
  int v14; // [xsp+14h] [xbp-Ch]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0xB00000000LL;
  v5 = *(_DWORD *)(a1 + 428);
  v14 = 0;
  v11 = 0x10000800ALL;
  v12 = v5;
  LODWORD(result) = battery_chg_write(a1 - 8, (__int64)&v11, 0x18u, 0x3E8u);
  if ( (result & 0x80000000) == 0 )
  {
    v7 = *(unsigned int *)(*(_QWORD *)(a1 + 416) + 44LL);
    v8 = (unsigned int)(v7 - 128);
    if ( (unsigned int)v8 >= 3 )
    {
      if ( (unsigned int)v7 >= 0xA )
      {
LABEL_8:
        v10 = "Unknown";
        goto LABEL_9;
      }
      v9 = &(&power_supply_usb_type_text)[v7];
      if ( (unsigned __int64)(8 * v7) < 0x50 )
        goto LABEL_4;
    }
    else
    {
      v9 = &qc_power_supply_usb_type_text[(unsigned int)v8];
      if ( (unsigned __int64)(8 * v8) < 0x18 )
      {
LABEL_4:
        v10 = *v9;
LABEL_9:
        LODWORD(result) = scnprintf(a3, 4096, "%s\n", v10);
        goto LABEL_10;
      }
    }
    __break(1u);
    goto LABEL_8;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
