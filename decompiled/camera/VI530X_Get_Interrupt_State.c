__int64 __fastcall VI530X_Get_Interrupt_State(__int64 a1)
{
  unsigned int byte; // w2
  _BYTE v3[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  byte = vi530x_read_byte(a1, 3, v3);
  if ( (v3[0] & 1) == 0 )
  {
    printk(&unk_3F082A);
    byte = -10;
  }
  _ReadStatusReg(SP_EL0);
  return byte;
}
