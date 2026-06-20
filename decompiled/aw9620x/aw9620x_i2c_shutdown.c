__int64 __fastcall aw9620x_i2c_shutdown(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 result; // x0
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 184);
  printk(&unk_1470C, "aw9620x_i2c_shutdown", a3, a4);
  if ( !*(_BYTE *)(v4 + 5) )
  {
    disable_irq(*(unsigned int *)(v4 + 28));
    *(_BYTE *)(v4 + 5) = 1;
  }
  aw9620x_i2c_read(v4, 0x4410u, &v6);
  result = aw9620x_i2c_write(v4, 0x4408u, 2);
  _ReadStatusReg(SP_EL0);
  return result;
}
