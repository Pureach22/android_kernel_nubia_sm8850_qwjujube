__int64 __fastcall gen7_fault_block_uche(__int64 a1, char a2)
{
  unsigned int v3; // w19
  __int64 v5; // x0
  int v6; // w8
  int v7; // w19
  const char *v8; // x3
  __int64 v9; // x8
  char **v10; // x9
  const char *v11; // x3
  unsigned __int64 v12; // x10

  v3 = *(_DWORD *)(a1 + 23988);
  v5 = rt_mutex_trylock(a1 + 11088);
  if ( !(_DWORD)v5 )
  {
LABEL_8:
    if ( (a2 & 1) != 0 )
      goto LABEL_9;
LABEL_13:
    if ( v3 > 0xF )
    {
      v8 = "UCHE";
      return snprintf(gen7_iommu_fault_block_str, 0x24u, "%s: Unknown (client_id: %u)", v8, v3);
    }
    v9 = v3;
    v10 = &uche_client_0[v3];
    v11 = "UCHE";
    v12 = 128;
    goto LABEL_17;
  }
  v6 = *(_DWORD *)(a1 + 11120);
  if ( v6 != 2 && v6 != 32 )
  {
    v5 = rt_mutex_unlock(a1 + 11088);
    if ( (a2 & 1) != 0 )
      goto LABEL_9;
    goto LABEL_13;
  }
  v7 = kgsl_regmap_read(a1 + 13200);
  v5 = rt_mutex_unlock(a1 + 11088);
  if ( v7 != 1543552256 )
  {
    v3 = v7 & 0x7F;
    goto LABEL_8;
  }
  v3 = *(_DWORD *)(a1 + 23988);
  if ( (a2 & 1) == 0 )
    goto LABEL_13;
LABEL_9:
  if ( v3 > 7 )
  {
    v8 = "UCHE_LPAC";
    return snprintf(gen7_iommu_fault_block_str, 0x24u, "%s: Unknown (client_id: %u)", v8, v3);
  }
  v9 = v3;
  v10 = &uche_lpac_client[v3];
  v11 = "UCHE_LPAC";
  v12 = 64;
LABEL_17:
  if ( v12 > 8 * v9 )
    return snprintf(gen7_iommu_fault_block_str, 0x24u, "%s: %s", v11, *v10);
  __break(1u);
  return to_gen7_gmu(v5);
}
