__int64 __fastcall gen8_fault_block_uche(__int64 a1, char a2)
{
  unsigned int v3; // w19
  int v5; // w8
  int v6; // w19
  const char *v7; // x3
  __int64 v8; // x8
  char **v9; // x9
  const char *v10; // x3
  unsigned __int64 v11; // x10

  v3 = *(_DWORD *)(a1 + 23988);
  if ( !(unsigned int)rt_mutex_trylock(a1 + 11088) )
  {
LABEL_10:
    if ( (a2 & 1) != 0 )
      goto LABEL_11;
LABEL_15:
    if ( v3 > 0x10 )
    {
      v7 = "UCHE";
      return snprintf(gen8_iommu_fault_block_str, 0x24u, "%s: Unknown (client_id: %u)", v7, v3);
    }
    v8 = v3;
    v9 = &uche_client_1[v3];
    v10 = "UCHE";
    v11 = 136;
    goto LABEL_19;
  }
  v5 = *(_DWORD *)(a1 + 11120);
  if ( v5 != 2 && v5 != 32 || (gen8_gmu_rpmh_pwr_state_is_active(a1) & 1) == 0 || (adreno_gx_is_on(a1) & 1) == 0 )
  {
    rt_mutex_unlock(a1 + 11088);
    goto LABEL_10;
  }
  v6 = kgsl_regmap_read(a1 + 13200);
  rt_mutex_unlock(a1 + 11088);
  if ( v6 != 1543552256 )
  {
    v3 = v6 & 0x7F;
    if ( (a2 & 1) != 0 )
      goto LABEL_11;
    goto LABEL_15;
  }
  v3 = *(_DWORD *)(a1 + 23988);
  if ( (a2 & 1) == 0 )
    goto LABEL_15;
LABEL_11:
  if ( v3 > 7 )
  {
    v7 = "UCHE_LPAC";
    return snprintf(gen8_iommu_fault_block_str, 0x24u, "%s: Unknown (client_id: %u)", v7, v3);
  }
  v8 = v3;
  v9 = &uche_lpac_client_0[v3];
  v10 = "UCHE_LPAC";
  v11 = 64;
LABEL_19:
  if ( v11 <= 8 * v8 )
  {
    __break(1u);
    JUMPOUT(0xC3580);
  }
  return snprintf(gen8_iommu_fault_block_str, 0x24u, "%s: %s", v10, *v9);
}
