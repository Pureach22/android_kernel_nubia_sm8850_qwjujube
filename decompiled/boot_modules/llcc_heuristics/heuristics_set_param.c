__int64 __fastcall heuristics_set_param(__int64 a1, char a2)
{
  _DWORD *v4; // x0
  int v5; // w8
  const char *v6; // x2
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 result; // x0
  _DWORD *v10; // x20
  __int64 v11; // x21
  unsigned int u32_index; // w0
  __int64 v13; // x1
  const char *v14; // x2
  __int64 v15; // x0
  __int64 (__fastcall *v16)(__int64, _DWORD *, __int64, __int64, __int64); // x8
  unsigned int v17; // w0
  unsigned int v18; // w0
  __int64 v19; // x1
  __int64 v20; // x0
  __int64 (__fastcall *v21)(__int64, _DWORD *, __int64, _QWORD, __int64); // x8

  v4 = (_DWORD *)devm_kmalloc(a1 + 16, 24, 3520);
  if ( !v4 )
  {
    v6 = "Failed to alloc memory for heuristics_data\n";
    v7 = a1 + 16;
    v8 = 4294967284LL;
    return dev_err_probe(v7, v8, v6);
  }
  v5 = number_of_domains;
  if ( (unsigned int)number_of_domains >= 3 )
  {
    v6 = "Missing Nodes for qcom,freq-threshold-idx!\n";
    v7 = a1 + 16;
    v8 = 4294967274LL;
    return dev_err_probe(v7, v8, v6);
  }
  v10 = v4;
  v4[5] = a2 & 1;
  if ( (a2 & 1) != 0 )
  {
    *v4 = heur_scid;
    if ( v5 )
    {
      v11 = *(_QWORD *)(a1 + 760);
      u32_index = of_property_read_u32_index(v11, "qcom,freq-threshold-idx", 0, v4 + 1);
      if ( u32_index )
      {
        v13 = u32_index;
LABEL_11:
        v14 = "Missing index %d qcom,freq-threshold-idx\n";
        return dev_err_probe(a1 + 16, v13, v14);
      }
      result = of_property_read_u32_index(v11, "qcom,frequency-threshold-residency", 0, v10 + 3);
      if ( (_DWORD)result )
      {
        v13 = (unsigned int)result;
LABEL_18:
        v14 = "Missing index %d qcom,frequency-threshold-residency\n";
        return dev_err_probe(a1 + 16, v13, v14);
      }
      if ( number_of_domains >= 2 )
      {
        v17 = of_property_read_u32_index(v11, "qcom,freq-threshold-idx", 1, v10 + 2);
        if ( v17 )
        {
          v13 = v17;
          goto LABEL_11;
        }
        result = of_property_read_u32_index(v11, "qcom,frequency-threshold-residency", 1, v10 + 4);
        if ( (_DWORD)result )
        {
          v13 = (unsigned int)result;
          goto LABEL_18;
        }
        if ( number_of_domains >= 3 )
        {
          v18 = of_property_read_u32_index(v11, "qcom,freq-threshold-idx", 2, v10 + 3);
          if ( v18 )
          {
            v13 = v18;
            goto LABEL_11;
          }
          result = of_property_read_u32_index(v11, "qcom,frequency-threshold-residency", 2, v10 + 5);
          if ( (_DWORD)result )
          {
            v13 = (unsigned int)result;
            goto LABEL_18;
          }
          if ( number_of_domains > 3 )
          {
            __break(0x5512u);
            return heuristics_set_param_v2(result, v19);
          }
        }
      }
      if ( !v10[5] )
        goto LABEL_35;
    }
    v20 = ph;
    v21 = *(__int64 (__fastcall **)(__int64, _DWORD *, __int64, _QWORD, __int64))ops;
    if ( *(_DWORD *)(*(_QWORD *)ops - 4LL) != 1737159351 )
      __break(0x8228u);
    result = v21(v20, v10, 0x4845555253434944LL, 0, 24);
    if ( (result & 0x80000000) == 0 )
    {
LABEL_35:
      *(_QWORD *)(a1 + 168) = v10;
      return result;
    }
LABEL_36:
    v8 = (unsigned int)result;
    v6 = "llcc_heuristics scmi set_param failed!\n";
    v7 = a1 + 16;
    return dev_err_probe(v7, v8, v6);
  }
  v15 = ph;
  v16 = *(__int64 (__fastcall **)(__int64, _DWORD *, __int64, __int64, __int64))ops;
  if ( *(_DWORD *)(*(_QWORD *)ops - 4LL) != 1737159351 )
    __break(0x8228u);
  result = v16(v15, v10, 0x4845555253434944LL, 1, 24);
  if ( (result & 0x80000000) != 0 )
    goto LABEL_36;
  return result;
}
