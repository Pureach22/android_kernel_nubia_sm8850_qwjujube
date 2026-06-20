const char *__fastcall gen8_iommu_fault_block(__int64 a1, unsigned __int8 a2)
{
  __int64 v3; // x1

  if ( a2 > 4u )
  {
    if ( a2 <= 6u )
    {
      if ( a2 == 5 )
        return "Flag cache";
      if ( a2 == 6 )
        return "PREFETCH";
      goto LABEL_25;
    }
    if ( a2 == 7 )
      return "GMU";
    if ( a2 != 8 )
    {
      if ( a2 == 9 )
        return "UCHE_HPAC";
      goto LABEL_25;
    }
    v3 = 1;
LABEL_24:
    gen8_fault_block_uche(a1, v3);
    return gen8_iommu_fault_block_str;
  }
  if ( a2 <= 1u )
  {
    if ( !a2 )
      return "CP";
    if ( a2 == 1 )
      return "UCHE: Unknown";
    goto LABEL_25;
  }
  switch ( a2 )
  {
    case 2u:
      return "UCHE_LPAC: Unknown";
    case 3u:
      v3 = 0;
      goto LABEL_24;
    case 4u:
      return "CCU";
  }
LABEL_25:
  snprintf(gen8_iommu_fault_block_str, 0x24u, "Unknown (mid: %u)", a2);
  return gen8_iommu_fault_block_str;
}
