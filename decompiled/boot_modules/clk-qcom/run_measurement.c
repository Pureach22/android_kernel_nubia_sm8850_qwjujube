__int64 __fastcall run_measurement(int a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  regmap_update_bits_base(a2, a3, 0x100000, 0, 0, 0, 0);
  regmap_update_bits_base(a2, a3, 0x200000, 0x200000, 0, 0, 0);
  _const_udelay(4295);
  regmap_update_bits_base(a2, a3, 0x200000, 0, 0, 0, 0);
  regmap_update_bits_base(a2, a3, 0xFFFFF, a1 & 0xFFFFF, 0, 0, 0);
  regmap_update_bits_base(a2, a3, 0x100000, 0x100000, 0, 0, 0);
  while ( 1 )
  {
    regmap_read(a2, a4, &v9);
    if ( (v9 & 0x2000000) != 0 )
      break;
    __yield();
  }
  regmap_update_bits_base(a2, a3, 0x100000, 0, 0, 0, 0);
  regmap_read(a2, a4, &v9);
  _ReadStatusReg(SP_EL0);
  return v9 & 0x1FFFFFF;
}
