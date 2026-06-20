__int64 __fastcall msm_pcie_poll_for_l0_from_l0s(__int64 result)
{
  __int64 v1; // x19

  if ( *(_BYTE *)(result + 1217) == 1 )
  {
    v1 = result;
    for ( result = readl_relaxed_0((unsigned int *)(*(_QWORD *)(result + 872) + 432LL));
          (result & 0x3F) != 0x11;
          result = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 872) + 432LL)) )
    {
      pci_walk_bus(*(_QWORD *)(*(_QWORD *)(v1 + 8) + 16LL), msm_pcie_read_devid_all, v1);
    }
  }
  return result;
}
