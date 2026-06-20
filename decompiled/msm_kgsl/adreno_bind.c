__int64 __fastcall adreno_bind(__int64 a1)
{
  __int64 v1; // x20
  __int64 gpu_model_node; // x0
  __int64 v4; // x22
  __int64 v5; // x24
  unsigned __int64 v6; // x21
  unsigned int partinfo_chip_id; // w0
  unsigned int v8; // w2
  unsigned int v9; // w0
  __int64 v10; // x8
  int v11; // w13
  int v12; // w13
  int v13; // w13
  __int64 v14; // x1
  __int64 (__fastcall *v15)(__int64, __int64, unsigned __int64); // x8
  __int64 v16; // x8
  const char *v17; // x2
  unsigned int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v1 = a1 - 16;
  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  gpu_model_node = adreno_get_gpu_model_node(a1 - 16);
  if ( !gpu_model_node || (v4 = gpu_model_node, !of_find_property(gpu_model_node, "compatible", 0)) )
    v4 = *(_QWORD *)(a1 + 744);
  v5 = 0;
  v19 = 0;
  do
  {
    v6 = *(unsigned __int64 *)((char *)&adreno_gpulist + v5);
    if ( *(_QWORD *)(v6 + 24) && (unsigned int)of_device_is_compatible(v4) )
    {
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,chipid", &v19, 1, 0) & 0x80000000) == 0 )
        goto LABEL_24;
      partinfo_chip_id = socinfo_get_partinfo_chip_id(1);
      if ( partinfo_chip_id )
      {
        v19 = partinfo_chip_id;
        goto LABEL_24;
      }
      dev_crit(a1, "No chipid associated with %s\n", *(const char **)(v6 + 24));
      goto LABEL_37;
    }
    v5 += 8;
  }
  while ( v5 != 520 );
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,chipid", &v19, 1, 0) & 0x80000000) != 0 )
  {
    v9 = socinfo_get_partinfo_chip_id(1);
    if ( v9 )
    {
      v8 = v9;
      v19 = v9;
      goto LABEL_15;
    }
    v8 = v19;
LABEL_36:
    dev_crit(a1, "Unknown GPU chip ID %8.8x\n", v8);
    goto LABEL_37;
  }
  v8 = v19;
LABEL_15:
  v10 = 0;
  while ( 1 )
  {
    v6 = *(unsigned __int64 *)((char *)&adreno_gpulist + v10);
    if ( HIBYTE(v8) == *(_DWORD *)(v6 + 4) )
    {
      v11 = *(_DWORD *)(v6 + 8);
      if ( v11 == -1 || v11 == BYTE2(v8) )
      {
        v12 = *(_DWORD *)(v6 + 12);
        if ( v12 == -1 || v12 == BYTE1(v8) )
        {
          v13 = *(_DWORD *)(v6 + 16);
          if ( v13 == -1 || v13 == (unsigned __int8)v8 )
            break;
        }
      }
    }
    v10 += 8;
    if ( v10 == 520 )
      goto LABEL_36;
  }
LABEL_24:
  if ( !v6 )
  {
LABEL_37:
    LODWORD(v6) = -19;
    goto LABEL_38;
  }
  if ( (*(_BYTE *)(v6 + 33) & 4) != 0 )
  {
    v17 = *(const char **)(v6 + 24);
    if ( v17 )
      dev_err(a1, "Support for GPU %s has been deprecated\n", v17);
    else
      dev_err(
        a1,
        "Support for GPU %x.%d.%x.%d has been deprecated\n",
        *(_DWORD *)(v6 + 4),
        *(_DWORD *)(v6 + 8),
        *(_DWORD *)(v6 + 12),
        *(_DWORD *)(v6 + 16));
    goto LABEL_37;
  }
  if ( v6 < 0xFFFFFFFFFFFFF001LL )
  {
    v14 = v19;
    v15 = *(__int64 (__fastcall **)(__int64, __int64, unsigned __int64))(*(_QWORD *)(v6 + 40) + 8LL);
    if ( *((_DWORD *)v15 - 1) != -1500871183 )
      __break(0x8228u);
    LODWORD(v6) = v15(v1, v14, v6);
    if ( (_DWORD)v6 )
    {
      adreno_unbind(a1);
    }
    else
    {
      v16 = *(_QWORD *)(a1 + 152);
      *(_BYTE *)(v16 + 13417) = 1;
      srcu_init_notifier_head(v16 + 13424);
    }
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v6;
}
