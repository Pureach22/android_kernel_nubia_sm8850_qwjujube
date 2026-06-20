__int64 __fastcall RamWrite16A_ois_dw9784(_QWORD *a1, int a2, int a3)
{
  __int64 result; // x0
  unsigned int v4; // w21

  result = zte_cam_cci_i2c_write(*a1 + 3656LL, a2, a3, 2, 2);
  if ( (result & 0x80000000) != 0 )
  {
    v4 = result;
    printk(&unk_41BA38);
    return v4;
  }
  return result;
}
