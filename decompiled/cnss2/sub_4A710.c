__int64 sub_4A710()
{
  __int64 v0; // x30

  if ( (v0 & 0x200000000000LL) == 0 )
    JUMPOUT(0x5022C);
  return cnss_pci_smmu_fault_handler();
}
