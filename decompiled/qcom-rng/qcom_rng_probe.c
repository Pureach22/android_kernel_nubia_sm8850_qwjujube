unsigned __int64 __fastcall qcom_rng_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  unsigned __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x20
  __int64 v7; // x20

  v2 = devm_kmalloc(a1 + 16, 224, 3520);
  if ( !v2 )
    return 4294967284LL;
  v3 = v2;
  *(_QWORD *)(a1 + 168) = v2;
  _mutex_init();
  result = devm_platform_ioremap_resource(a1, 0);
  *(_QWORD *)(v3 + 48) = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    result = devm_clk_get_optional(a1 + 16, "core");
    *(_QWORD *)(v3 + 56) = result;
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      *(_QWORD *)(v3 + 216) = device_get_match_data(a1 + 16);
      qcom_rng_dev = v3;
      v5 = crypto_register_rng(qcom_rng_alg);
      if ( (_DWORD)v5 )
      {
        v7 = v5;
        dev_err(a1 + 16, "Register crypto rng failed: %d\n", v5);
        qcom_rng_dev = 0;
        return v7;
      }
      else if ( *(_BYTE *)(*(_QWORD *)(v3 + 216) + 1LL) == 1 )
      {
        *(_QWORD *)(v3 + 64) = "qcom_hwrng";
        *(_QWORD *)(v3 + 104) = qcom_hwrng_read;
        *(_WORD *)(v3 + 120) = 1024;
        result = devm_hwrng_register(a1 + 16, v3 + 64);
        if ( (_DWORD)result )
        {
          v6 = (unsigned int)result;
          dev_err(a1 + 16, "Register hwrng failed: %d\n", result);
          qcom_rng_dev = 0;
          crypto_unregister_rng(qcom_rng_alg);
          return v6;
        }
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}
