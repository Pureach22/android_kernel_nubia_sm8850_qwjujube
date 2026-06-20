__int64 __fastcall aw8693x_set_rtp_data(__int64 a1, __int64 a2, unsigned int a3)
{
  return i2c_w_bytes(a1, 50, a2, a3);
}
