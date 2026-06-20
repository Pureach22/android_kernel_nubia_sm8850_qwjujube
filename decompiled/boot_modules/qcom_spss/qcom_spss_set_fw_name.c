__int64 __fastcall qcom_spss_set_fw_name(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x20

  v3 = kstrdup_const(a2, 3264);
  if ( !v3 )
    return 4294967284LL;
  v4 = v3;
  mutex_lock(a1 + 984);
  kfree(*(_QWORD *)(a1 + 32));
  *(_QWORD *)(a1 + 32) = v4;
  mutex_unlock(a1 + 984);
  return 0;
}
