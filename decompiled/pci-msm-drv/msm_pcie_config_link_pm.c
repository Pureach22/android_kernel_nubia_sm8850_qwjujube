__int64 __fastcall msm_pcie_config_link_pm(__int64 result)
{
  __int64 v1; // x19

  v1 = result;
  if ( *(_BYTE *)(result + 1232) == 1 )
    result = pci_walk_bus(*(_QWORD *)(*(_QWORD *)(result + 8) + 16LL), msm_pcie_config_common_clock_enable, result);
  if ( *(_BYTE *)(v1 + 1233) == 1 )
    result = pci_walk_bus(*(_QWORD *)(*(_QWORD *)(v1 + 8) + 16LL), msm_pcie_config_clock_power_management_enable, v1);
  if ( *(_BYTE *)(v1 + 1219) == 1 )
  {
    pci_walk_bus(*(_QWORD *)(*(_QWORD *)(v1 + 8) + 16LL), msm_pcie_config_l1_2_threshold, v1);
    result = pci_walk_bus(*(_QWORD *)(*(_QWORD *)(v1 + 8) + 16LL), msm_pcie_config_l1ss_enable, v1);
  }
  if ( *(_BYTE *)(v1 + 1218) == 1 )
    result = pci_walk_bus(*(_QWORD *)(*(_QWORD *)(v1 + 8) + 16LL), msm_pcie_config_l1_enable, v1);
  if ( *(_BYTE *)(v1 + 1217) == 1 )
    return pci_walk_bus(*(_QWORD *)(*(_QWORD *)(v1 + 8) + 16LL), msm_pcie_config_l0s_enable, v1);
  return result;
}
