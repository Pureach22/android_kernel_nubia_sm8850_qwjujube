bool __fastcall cnss_pci_is_smmu_s1_enabled(_BOOL8 result)
{
  if ( result )
    return *(_BYTE *)(result + 272) != 0;
  return result;
}
