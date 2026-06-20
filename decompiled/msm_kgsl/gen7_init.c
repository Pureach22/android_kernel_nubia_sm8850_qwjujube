unsigned __int64 __fastcall gen7_init(__int64 a1)
{
  _DWORD *v2; // x21
  _DWORD *v3; // x22
  __int64 v4; // x9
  int v5; // w8
  __int64 node_opts_by_path; // x0
  unsigned __int64 v7; // x8
  unsigned __int64 result; // x0
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD **)(a1 + 14264);
  *(_DWORD *)(a1 + 20652) = v2[50];
  v3 = (_DWORD *)(a1 + 23992);
  *(_DWORD *)(a1 + 24048) = adreno_get_ahb_timeout_val((_QWORD *)a1, v2[64]);
  v4 = *(_QWORD *)(a1 + 14264);
  v5 = v2[56];
  v9 = 0;
  *v3 = v5;
  *(_BYTE *)(a1 + 19673) = (*(_DWORD *)(v4 + 32) & 0x200) != 0;
  node_opts_by_path = of_find_node_opts_by_path("/memory", 0);
  if ( node_opts_by_path
    && (of_property_read_variable_u32_array(node_opts_by_path, "ddr_device_type", &v9, 1, 0) & 0x80000000) == 0
    && v9 == 7 )
  {
    *(_DWORD *)(a1 + 20652) = 14;
  }
  gen7_crashdump_init(a1);
  v7 = *(_QWORD *)(a1 + 20464);
  if ( v7 && v7 < 0xFFFFFFFFFFFFF001LL )
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
