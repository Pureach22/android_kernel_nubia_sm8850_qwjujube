__int64 __fastcall msm_pcie_drv_enable_pc(__int64 a1)
{
  return msm_pcie_drv_send_rpmsg(a1 - 1800, *(_QWORD *)(a1 - 8) + 161LL);
}
