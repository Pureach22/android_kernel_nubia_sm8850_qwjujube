__int64 __fastcall dw9785_wait_check_register(_QWORD *a1, unsigned int a2, int a3)
{
  int v6; // w24
  int v7; // w1
  int v8; // w2
  __int64 v9; // x25
  __int64 result; // x0
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v6 = 0;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  while ( 1 )
  {
    if ( (camera_io_dev_read(*a1 + 3656LL, a2, (__int64)&v12, 2, 2, 0) & 0x80000000) != 0 )
      printk(&unk_3E416B);
    if ( v12 == a3 )
    {
      result = 0;
      goto LABEL_11;
    }
    if ( v6 == 199 )
      break;
    v9 = -100;
    do
      _const_udelay("d: %u rc: %d", v7, v8);
    while ( !__CFADD__(v9++, 1) );
    ++v6;
  }
  printk(&unk_3E7E57);
  result = 0xFFFFFFFFLL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
