__int64 awp1921_check_handle()
{
  __int64 v0; // x19
  char v1; // w21
  __int64 result; // x0
  _WORD v3[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = mAWP1921;
  v3[0] = 0;
  awp1921_i2c_read(mAWP1921, 20, v3);
  printk(&unk_831F, "awp1921_check_handle", 280);
  awp1921_i2c_read(v0, 21, v3);
  printk(&unk_8128, "awp1921_check_handle", 283);
  awp1921_i2c_read(v0, 2, v3);
  v1 = v3[0];
  printk(&unk_848B, "awp1921_check_handle", 286);
  if ( (v1 & 0x20) != 0 )
  {
    printk(&unk_86FE, "awp1921_check_handle", 289);
    enableMicroPump(v0, 0);
    result = enableMicroPump(v0, 1);
  }
  else
  {
    result = queue_delayed_work_on(32, system_wq, v0 + 2096, 15000);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
