__int64 __fastcall wcd_usbss_display_port_switch_update(_QWORD *a1, int a2)
{
  __int64 v4; // x3
  __int64 v5; // x0
  __int64 result; // x0
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_BAAF);
  regmap_update_bits_base(*a1, 1027, 96, 0, 0, 0, 0);
  if ( a2 == 1 )
    v4 = 64;
  else
    v4 = 128;
  regmap_update_bits_base(*a1, 1028, 192, v4, 0, 0, 0);
  regmap_update_bits_base(*a1, 1027, 96, 96, 0, 0, 0);
  v5 = *a1;
  v7 = 0;
  result = regmap_read(v5, 1031, &v7);
  if ( !(_DWORD)result )
  {
    v7 &= 0xCCu;
    printk(&unk_B889);
    if ( a2 == 1 && v7 == 72 || a2 == 2 && v7 == 132 )
    {
      result = 0;
    }
    else
    {
      printk(&unk_BDE2);
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
