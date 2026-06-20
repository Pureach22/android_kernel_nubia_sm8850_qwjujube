char *__fastcall adreno_get_gpu_model(__int64 a1)
{
  size_t v2; // x0
  __int64 gpu_model_node; // x0
  const char *partinfo_part_name; // x20
  size_t v5; // x0
  unsigned __int64 v6; // x2
  __int64 v8; // x0
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  v2 = strnlen(adreno_get_gpu_model_gpu_model, 0x20u);
  if ( v2 >= 0x21 )
    _fortify_panic(2, 32, v2 + 1);
  if ( v2 )
  {
    if ( v2 != 32 )
    {
LABEL_17:
      _ReadStatusReg(SP_EL0);
      return adreno_get_gpu_model_gpu_model;
    }
    _fortify_panic(4, 32, 33);
  }
  gpu_model_node = adreno_get_gpu_model_node(*(_QWORD *)(a1 + 11168));
  if ( !gpu_model_node )
    gpu_model_node = *(_QWORD *)(*(_QWORD *)(a1 + 11168) + 760LL);
  if ( (unsigned int)of_property_read_string(gpu_model_node, "qcom,gpu-model", v9) )
  {
    partinfo_part_name = (const char *)socinfo_get_partinfo_part_name(1);
    v9[0] = partinfo_part_name;
    if ( !partinfo_part_name )
    {
      scnprintf(
        adreno_get_gpu_model_gpu_model,
        32,
        "Adreno%u%u%uv%u",
        HIBYTE(*(_DWORD *)(a1 + 14248)),
        (unsigned __int8)BYTE2(*(_DWORD *)(a1 + 14248)),
        BYTE1(*(_DWORD *)(a1 + 14248)),
        (unsigned __int8)*(_DWORD *)(a1 + 14248) + 1);
      goto LABEL_17;
    }
  }
  else
  {
    partinfo_part_name = (const char *)v9[0];
  }
  v5 = strnlen(partinfo_part_name, 0x20u);
  if ( v5 == -1 )
  {
    _fortify_panic(2, -1, 0);
  }
  else
  {
    if ( v5 == 32 )
      v6 = 32;
    else
      v6 = v5 + 1;
    if ( v6 < 0x21 )
    {
      sized_strscpy(adreno_get_gpu_model_gpu_model, partinfo_part_name);
      goto LABEL_17;
    }
  }
  v8 = _fortify_panic(7, 32, v6);
  return (char *)adreno_get_gpu_model_node(v8);
}
