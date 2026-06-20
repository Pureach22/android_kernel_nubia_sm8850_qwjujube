__int64 __fastcall battery_chg_update_usb_type_work(__int64 a1)
{
  __int64 v1; // x20
  int v3; // w9
  __int64 result; // x0
  int v5; // w10
  __int64 v6; // x9
  int v7; // w8
  int v8; // w9
  __int64 v9; // [xsp+0h] [xbp-20h] BYREF
  int v10; // [xsp+8h] [xbp-18h]
  __int64 v11; // [xsp+Ch] [xbp-14h]
  int v12; // [xsp+14h] [xbp-Ch]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v1 = a1 - 592;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0x700000000LL;
  v3 = *(_DWORD *)(a1 - 156);
  v12 = 0;
  v9 = 0x10000800ALL;
  v10 = v3;
  result = battery_chg_write(a1 - 592, (__int64)&v9, 0x18u, 0x3E8u);
  if ( (result & 0x80000000) != 0 )
  {
    result = printk(&unk_10815, "battery_chg_update_usb_type_work", (unsigned int)result);
    goto LABEL_20;
  }
  if ( !*(_DWORD *)(*(_QWORD *)(a1 - 168) + 28LL) )
    goto LABEL_18;
  v5 = *(_DWORD *)(a1 - 156);
  v12 = 0;
  v11 = 0xD00000000LL;
  v9 = 0x10000800ALL;
  v10 = v5;
  result = battery_chg_write(v1, (__int64)&v9, 0x18u, 0x3E8u);
  v6 = *(_QWORD *)(a1 - 168);
  v7 = *(_DWORD *)(v6 + 28);
  if ( (unsigned int)v7 <= 6 && ((1 << v7) & 0x4A) != 0 )
  {
    if ( v7 > 5 )
      goto LABEL_6;
LABEL_11:
    if ( v7 > 2 )
    {
      if ( v7 == 3 )
      {
        v8 = 6;
      }
      else if ( v7 == 4 )
      {
        v8 = 7;
      }
      else
      {
        v8 = 8;
      }
      goto LABEL_19;
    }
    if ( v7 != 2 )
      goto LABEL_18;
LABEL_17:
    v8 = 5;
    goto LABEL_19;
  }
  *(_DWORD *)(a1 + 540) = 0;
  v7 = *(_DWORD *)(v6 + 28);
  if ( v7 <= 5 )
    goto LABEL_11;
LABEL_6:
  if ( (unsigned int)(v7 - 6) >= 3 )
  {
    if ( (unsigned int)(v7 - 128) >= 3 && v7 != 9 )
    {
LABEL_18:
      v8 = 4;
      goto LABEL_19;
    }
    goto LABEL_17;
  }
  v8 = 9;
LABEL_19:
  dword_298 = v8;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
