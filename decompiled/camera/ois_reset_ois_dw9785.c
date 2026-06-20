__int64 __fastcall ois_reset_ois_dw9785(_QWORD *a1)
{
  __int64 result; // x0

  printk(&unk_41F7A8);
  if ( (zte_cam_cci_i2c_write(*a1 + 3656LL, 53250, 1, 2, 2) & 0x80000000) != 0 )
    printk(&unk_41BA38);
  _const_udelay((const char *)0x1062560);
  result = dw9785_wait_check_register(a1, 0xD004u, 38789);
  if ( !(_DWORD)result )
    return printk(&unk_3CFD7A);
  return result;
}
