__int64 qcom_rng_remove()
{
  __int64 result; // x0

  result = crypto_unregister_rng(qcom_rng_alg);
  qcom_rng_dev = 0;
  return result;
}
