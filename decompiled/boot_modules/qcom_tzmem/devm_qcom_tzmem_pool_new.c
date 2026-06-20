unsigned __int64 __fastcall devm_qcom_tzmem_pool_new(__int64 a1, __int64 *a2)
{
  unsigned __int64 v3; // x19
  int v4; // w0
  int v5; // w20

  v3 = qcom_tzmem_pool_new(a2);
  if ( v3 <= 0xFFFFFFFFFFFFF000LL )
  {
    v4 = _devm_add_action(a1, devm_qcom_tzmem_pool_free, v3, "devm_qcom_tzmem_pool_free");
    if ( v4 )
    {
      v5 = v4;
      qcom_tzmem_pool_free(v3);
      return v5;
    }
  }
  return v3;
}
