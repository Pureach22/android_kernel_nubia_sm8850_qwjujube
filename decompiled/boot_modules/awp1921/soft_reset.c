__int64 __fastcall soft_reset(__int64 *a1)
{
  awp1921_i2c_write(a1, 1u, 21123);
  return msleep(10);
}
