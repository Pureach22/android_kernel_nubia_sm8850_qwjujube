__int64 __fastcall msm_pcie_config_l1ss_enable_all(__int64 result)
{
  __int64 v1; // x19

  if ( *(_BYTE *)(result + 1219) == 1 )
  {
    v1 = result;
    pci_walk_bus(*(_QWORD *)(*(_QWORD *)(result + 8) + 16LL), msm_pcie_config_l1_2_threshold, result);
    return pci_walk_bus(*(_QWORD *)(*(_QWORD *)(v1 + 8) + 16LL), msm_pcie_config_l1ss_enable, v1);
  }
  return result;
}
