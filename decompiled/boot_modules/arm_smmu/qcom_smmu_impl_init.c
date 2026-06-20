__int64 __fastcall qcom_smmu_impl_init(const char ***a1)
{
  const char ***v1; // x19
  int v2; // w10
  const char *v3; // x20
  __int64 matched; // x0
  _QWORD *v5; // x20
  const char *v6; // x0
  __int64 v7; // x21
  const char *v8; // x1
  char is_available; // w8
  const char **v10; // x0
  __int64 v11; // x0

  v1 = a1;
  v2 = (unsigned __int8)qcom_smmu_impl_init_tbu_registered;
  v3 = (*a1)[93];
  ++qcom_smmu_impl_init_tbu_registered;
  if ( !v2 )
    _platform_driver_register(&qcom_smmu_tbu_driver, &_this_module);
  matched = of_match_node(&qcom_smmu_impl_of_match, v3);
  if ( matched )
  {
    v5 = *(_QWORD **)(matched + 192);
    if ( !v5 )
      return -22;
    v6 = (*v1)[93];
    if ( v6 && (unsigned int)of_device_is_compatible(v6, "qcom,adreno-smmu") )
    {
      v7 = v5[2];
      if ( !v7 )
        return (__int64)v1;
    }
    else
    {
      v7 = v5[1];
      if ( !v7 )
        return (__int64)v1;
    }
    is_available = qcom_scm_is_available();
    v10 = *v1;
    if ( (is_available & 1) != 0 )
    {
      v11 = devm_krealloc(v10, v1, 344, 3264);
      if ( v11 )
      {
        *(_QWORD *)(v11 + 48) = v7;
        v1 = (const char ***)v11;
        *(_QWORD *)(v11 + 328) = *v5;
      }
      else
      {
        return -12;
      }
    }
    else
    {
      return (int)dev_err_probe(v10, 4294966779LL, "qcom_scm not ready\n");
    }
  }
  else if ( (unsigned int)of_device_is_compatible(v3, "qcom,adreno-smmu") )
  {
    v8 = (*v1)[14];
    if ( !v8 )
      v8 = **v1;
    _warn_printk("Missing qcom_smmu_impl_of_match entry for: %s", v8);
    __break(0x800u);
  }
  return (__int64)v1;
}
