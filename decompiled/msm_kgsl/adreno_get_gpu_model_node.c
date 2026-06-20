__int64 __fastcall adreno_get_gpu_model_node(__int64 a1)
{
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x19
  const void *v4; // x21
  __int64 node_by_name; // x0
  __int64 v6; // x21
  __int64 i; // x20
  size_t v8; // x2
  unsigned __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  int dest; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = nvmem_cell_get(a1 + 16, "gpu_model");
  v3 = v2;
  dest = 0;
  if ( v2 < 0xFFFFFFFFFFFFF001LL )
  {
    v10 = 0;
    v4 = (const void *)nvmem_cell_read(v2, &v10);
    nvmem_cell_put(v3);
    if ( (unsigned __int64)v4 < 0xFFFFFFFFFFFFF001LL )
    {
      if ( v10 >= 4 )
        v8 = 4;
      else
        v8 = v10;
      memcpy(&dest, v4, v8);
      kfree(v4);
      LODWORD(v3) = dest;
      if ( dest < 0 )
        goto LABEL_16;
      goto LABEL_5;
    }
    LODWORD(v3) = (_DWORD)v4;
  }
  if ( (v3 & 0x80000000) != 0 )
  {
LABEL_16:
    i = 0;
    goto LABEL_17;
  }
LABEL_5:
  node_by_name = of_find_node_by_name(*(_QWORD *)(a1 + 760), "qcom,gpu-models");
  if ( !node_by_name )
    goto LABEL_16;
  v6 = node_by_name;
  for ( i = of_get_next_child(node_by_name, 0); i; i = of_get_next_child(v6, i) )
  {
    LODWORD(v10) = 0;
    if ( (of_property_read_variable_u32_array(i, "qcom,gpu-model-id", &v10, 1, 0) & 0x80000000) == 0
      && (_DWORD)v10 == (_DWORD)v3 )
    {
      break;
    }
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return i;
}
