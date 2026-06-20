__int64 __fastcall awp1921_irq_handle(__int64 a1, __int64 a2)
{
  unsigned int v3; // w20
  _WORD v5[2]; // [xsp+0h] [xbp-10h] BYREF
  __int16 v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  printk(&unk_886D, "awp1921GetState", 222);
  if ( !(unsigned int)awp1921_i2c_read(a2, 2, v5) )
    printk(&unk_81D2, "awp1921GetState", 225);
  printk(&unk_8739, "awp1921_irq_handle", 621);
  v3 = 0;
  v6 = 0;
  do
  {
    awp1921_i2c_read(a2, v3, &v6);
    printk(&unk_8367, "dumpAllRegister", 186);
    ++v3;
  }
  while ( v3 != 31 );
  _ReadStatusReg(SP_EL0);
  return 1;
}
