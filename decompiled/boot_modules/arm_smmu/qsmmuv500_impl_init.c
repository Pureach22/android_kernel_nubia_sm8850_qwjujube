__int64 __fastcall qsmmuv500_impl_init(_QWORD *a1)
{
  void *v2; // x1
  __int64 result; // x0
  __int64 v4; // x0
  __int64 v5; // x19
  int v6; // w8

  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*a1 + 744LL), "qcom,adreno-smmu") )
  {
    v2 = &qsmmuv500_adreno_impl;
    return qsmmuv500_create(a1, (__int64)v2);
  }
  if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(*a1 + 744LL), "qcom,virt-smmu") )
  {
    v2 = &qsmmuv500_impl;
    return qsmmuv500_create(a1, (__int64)v2);
  }
  v4 = devm_krealloc(*a1, a1, 400, 3520);
  if ( !v4 )
    return -12;
  v5 = v4;
  *(_QWORD *)(v4 + 328) = v4 + 328;
  *(_QWORD *)(v4 + 336) = v4 + 328;
  *(_QWORD *)(v4 + 360) = 0xFFFFFFFE00000LL;
  *(_DWORD *)(v4 + 392) = 0;
  *(_QWORD *)(v4 + 368) = v4 + 368;
  *(_QWORD *)(v4 + 376) = v4 + 368;
  *(_QWORD *)(v4 + 384) = qsmmuv500_log_outstanding_transactions;
  *(_QWORD *)(v4 + 48) = &qsmmuv500_virt_impl;
  v6 = ((__int64 (*)(void))qsmmuv500_read_actlr_tbl)();
  result = v5;
  if ( v6 )
    return v6;
  return result;
}
