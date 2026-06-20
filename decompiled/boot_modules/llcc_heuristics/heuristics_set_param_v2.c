__int64 __fastcall heuristics_set_param_v2(__int64 a1, char a2)
{
  _DWORD *v4; // x0
  int v5; // w8
  __int64 result; // x0
  _DWORD *v7; // x20
  __int64 v8; // x22
  __int64 v9; // x21
  _DWORD *v10; // x24
  unsigned int u32_index; // w0
  __int64 v12; // x0
  __int64 (__fastcall *v13)(__int64, _DWORD *, __int64, _QWORD, __int64); // x8
  __int64 v14; // x0
  __int64 (__fastcall *v15)(__int64, _DWORD *, __int64, __int64, __int64); // x8
  __int64 v16; // x1
  const char *v17; // x2

  v4 = (_DWORD *)devm_kmalloc(a1 + 16, 72, 3520);
  if ( !v4 )
    return dev_err_probe(a1 + 16, 4294967284LL, "Failed to alloc memory for heuristics_data\n");
  v5 = number_of_domains;
  if ( (unsigned int)number_of_domains >= 9 )
    return dev_err_probe(a1 + 16, 4294967274LL, "Missing Nodes for qcom,freq-threshold-idx!\n");
  v7 = v4;
  v4[17] = a2 & 1;
  if ( (a2 & 1) == 0 )
  {
    v14 = ph;
    v15 = *(__int64 (__fastcall **)(__int64, _DWORD *, __int64, __int64, __int64))ops;
    if ( *(_DWORD *)(*(_QWORD *)ops - 4LL) != 1737159351 )
      __break(0x8228u);
    result = v15(v14, v7, 0x4845555253434944LL, 1, 72);
    if ( (result & 0x80000000) != 0 )
      return dev_err_probe(a1 + 16, (unsigned int)result, "llcc_heuristics scmi set_param failed!\n");
    return result;
  }
  *v4 = heur_scid;
  if ( !v5 )
    goto LABEL_13;
  v8 = *(_QWORD *)(a1 + 760);
  v9 = 0;
  v10 = v4 + 9;
  do
  {
    if ( v9 == 9 )
    {
      __break(0x5512u);
      JUMPOUT(0x6654);
    }
    u32_index = of_property_read_u32_index(v8, "qcom,freq-threshold-idx", (unsigned int)v9, v10 - 8);
    if ( u32_index )
    {
      v16 = u32_index;
      v17 = "Missing index %d qcom,freq-threshold-idx\n";
      return dev_err_probe(a1 + 16, v16, v17);
    }
    result = of_property_read_u32_index(v8, "qcom,frequency-threshold-residency", (unsigned int)v9, v10);
    if ( (_DWORD)result )
    {
      v16 = (unsigned int)result;
      v17 = "Missing index %d qcom,frequency-threshold-residency\n";
      return dev_err_probe(a1 + 16, v16, v17);
    }
    ++v9;
    ++v10;
  }
  while ( v9 < number_of_domains );
  if ( !v7[17] )
    goto LABEL_16;
LABEL_13:
  v12 = ph;
  v13 = *(__int64 (__fastcall **)(__int64, _DWORD *, __int64, _QWORD, __int64))ops;
  if ( *(_DWORD *)(*(_QWORD *)ops - 4LL) != 1737159351 )
    __break(0x8228u);
  result = v13(v12, v7, 0x4845555253434944LL, 0, 72);
  if ( (result & 0x80000000) == 0 )
  {
LABEL_16:
    *(_QWORD *)(a1 + 168) = v7;
    return result;
  }
  return dev_err_probe(a1 + 16, (unsigned int)result, "llcc_heuristics scmi set_param failed!\n");
}
