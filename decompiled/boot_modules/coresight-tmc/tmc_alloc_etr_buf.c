__int64 __fastcall tmc_alloc_etr_buf(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x23
  int mappings_configuration; // w0
  char v8; // w22
  int v9; // w25
  __int64 result; // x0
  __int64 v11; // x8
  int v12; // w23
  __int64 (__fastcall ***v13)(); // x26
  __int64 (__fastcall *v14)(); // x8
  __int64 v15; // x24
  __int64 (__fastcall *v16)(__int64, __int64, __int64, __int64); // x8
  __int64 v17; // x21
  __int64 (__fastcall *v18)(__int64, __int64, unsigned int, __int64); // x8
  __int64 v19; // x21

  v6 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 152LL) + 152LL);
  if ( iommu_get_domain_for_dev() )
  {
    mappings_configuration = qcom_iommu_get_mappings_configuration();
    if ( mappings_configuration < 0 )
      return -12;
    v8 = mappings_configuration;
  }
  else
  {
    v8 = 1;
  }
  v9 = *(_DWORD *)(v6 + 204);
  result = _kmalloc_cache_noprof(arm64_use_ng_mappings, 3520, 64);
  if ( result )
  {
    v11 = *(unsigned int *)(a1 + 208);
    *(_QWORD *)(result + 16) = a2;
    if ( (_DWORD)v11 == 3 )
    {
      v12 = -12;
    }
    else if ( (unsigned int)v11 <= 2 && (v13 = &etr_buf_ops[v11], *v13) && (v14 = **v13) != nullptr )
    {
      v15 = result;
      if ( *((_DWORD *)v14 - 1) != 1465360599 )
        __break(0x8228u);
      v12 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v14)(a1, result, a3, 0);
      result = v15;
      if ( !v12 )
        goto LABEL_33;
    }
    else
    {
      v12 = -22;
    }
    if ( a2 < 0x100000 || (v8 & 1) == 0 || (v9 & 1) == 0 )
    {
      if ( !etr_buf_ops[0]
        || (v16 = (__int64 (__fastcall *)(__int64, __int64, __int64, __int64))*etr_buf_ops[0]) == nullptr )
      {
        v12 = -22;
        if ( (v9 & 1) == 0 )
          goto LABEL_35;
        goto LABEL_27;
      }
      v17 = result;
      if ( *((_DWORD *)v16 - 1) != 1465360599 )
        __break(0x8228u);
      v12 = v16(a1, result, a3, 0);
      result = v17;
      if ( !v12 )
      {
        v13 = etr_buf_ops;
        goto LABEL_33;
      }
    }
    if ( (v9 & 1) == 0 )
      goto LABEL_35;
LABEL_27:
    if ( off_AE0 )
    {
      v18 = (__int64 (__fastcall *)(__int64, __int64, unsigned int, __int64))*off_AE0;
      if ( *off_AE0 )
      {
        v19 = result;
        if ( *((_DWORD *)v18 - 1) != 1465360599 )
          __break(0x8228u);
        v12 = v18(a1, result, a3, 0);
        result = v19;
        if ( v12 )
          goto LABEL_35;
        v13 = &off_AE0;
LABEL_33:
        *(_QWORD *)(result + 48) = *v13;
        *(_DWORD *)result = 1;
        return result;
      }
    }
    v12 = -22;
LABEL_35:
    kfree(result);
    return v12;
  }
  return -12;
}
