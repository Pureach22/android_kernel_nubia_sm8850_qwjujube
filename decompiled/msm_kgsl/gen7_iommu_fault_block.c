const char *__fastcall gen7_iommu_fault_block(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x1

  if ( a2 <= 3u )
  {
    if ( a2 > 1u )
    {
      if ( a2 == 2 )
        return "UCHE_LPAC: Unknown";
      if ( a2 == 3 )
      {
        v2 = 0;
        goto LABEL_14;
      }
    }
    else
    {
      if ( !a2 )
        return "CP";
      if ( a2 == 1 )
        return "UCHE: Unknown";
    }
  }
  else if ( a2 <= 5u )
  {
    if ( a2 == 4 )
      return "CCU";
    if ( a2 == 5 )
      return "Flag cache";
  }
  else
  {
    switch ( a2 )
    {
      case 6u:
        return "PREFETCH";
      case 7u:
        return "GMU";
      case 8u:
        v2 = 1;
LABEL_14:
        gen7_fault_block_uche(a1, v2);
        return gen7_iommu_fault_block_str;
    }
  }
  snprintf(gen7_iommu_fault_block_str, 0x24u, "Unknown (mid: %u)", a2);
  return gen7_iommu_fault_block_str;
}
