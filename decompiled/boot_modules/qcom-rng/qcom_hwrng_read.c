__int64 __fastcall qcom_hwrng_read(__int64 a1)
{
  return qcom_rng_read(a1 - 64);
}
