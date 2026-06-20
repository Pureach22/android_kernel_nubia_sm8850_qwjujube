__int64 __fastcall sub_5CCBD8(__int64 a1, __int64 a2)
{
  __int64 v2; // x13
  __int64 v3; // x23

  return hif_pci_set_grp_intr_affinity(a1, a2, v3 & ~__ROR8__(v2, 43));
}
