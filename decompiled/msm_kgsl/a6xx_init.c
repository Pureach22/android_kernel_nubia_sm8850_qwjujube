unsigned __int64 __fastcall a6xx_init(__int64 a1)
{
  __int64 v2; // x8
  __int64 node_opts_by_path; // x0
  __int64 v4; // x8
  int v5; // w22
  const char *v6; // x20
  int v7; // w8
  unsigned __int64 v8; // x8
  unsigned __int64 result; // x0
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 14264);
  v10 = 0;
  *(_DWORD *)(a1 + 20652) = *(_DWORD *)(v2 + 180);
  *(_BYTE *)(a1 + 19673) = (*(_DWORD *)(v2 + 32) & 0x200) != 0;
  node_opts_by_path = of_find_node_opts_by_path("/memory", 0);
  if ( !node_opts_by_path
    || (of_property_read_variable_u32_array(node_opts_by_path, "ddr_device_type", &v10, 1, 0) & 0x80000000) != 0
    || v10 != 7 )
  {
    goto LABEL_24;
  }
  v4 = *(_QWORD *)(a1 + 14264);
  v5 = *(_DWORD *)v4;
  v6 = *(const char **)(v4 + 24);
  if ( *(_DWORD *)v4 == 660 )
  {
    if ( !v6 )
      goto LABEL_21;
    if ( !strcmp(*(const char **)(v4 + 24), "qcom,adreno-gpu-a660-shima") )
      goto LABEL_20;
  }
  else if ( !v6 )
  {
    if ( v5 > 661 )
    {
      if ( v5 == 203264 || v5 == 662 )
        goto LABEL_20;
      goto LABEL_21;
    }
    goto LABEL_15;
  }
  if ( !strcmp(v6, "qcom,adreno-gpu-a642l") )
    goto LABEL_20;
  if ( v5 <= 661 )
  {
LABEL_15:
    if ( v5 != 643 )
    {
      if ( v5 == 650 )
      {
LABEL_22:
        v7 = 15;
        goto LABEL_23;
      }
      goto LABEL_21;
    }
LABEL_20:
    v7 = 14;
LABEL_23:
    *(_DWORD *)(a1 + 20652) = v7;
    goto LABEL_24;
  }
  if ( v5 == 662 || v5 == 203264 )
    goto LABEL_20;
LABEL_21:
  if ( (unsigned int)adreno_is_a660(a1) )
    goto LABEL_22;
LABEL_24:
  a6xx_crashdump_init(a1);
  v8 = *(_QWORD *)(a1 + 20464);
  if ( v8 && v8 < 0xFFFFFFFFFFFFF001LL )
  {
    result = 0;
  }
  else
  {
    result = kgsl_allocate_global(a1, 4096, 0, 0, 64, "powerup_register_list");
    *(_QWORD *)(a1 + 20464) = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
      result = 0;
    else
      result = (unsigned int)result;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
