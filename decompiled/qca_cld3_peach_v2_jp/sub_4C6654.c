__int64 __fastcall sub_4C6654(__int64 a1, __int64 a2, __int64 a3, __int64 a4, float *a5)
{
  float32x2x4_t v6; // 0:d13.8,8:d14.8,16:d15.8,24:d16.8

  vst4_f32(a5, v6);
  return dp_tx_get_success_ack_stats();
}
