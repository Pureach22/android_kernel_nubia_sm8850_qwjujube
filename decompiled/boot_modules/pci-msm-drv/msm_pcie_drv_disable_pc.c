__int64 __fastcall msm_pcie_drv_disable_pc(__int64 a1)
{
  return msm_pcie_drv_send_rpmsg(a1 - 1832, *(_QWORD *)(a1 - 40) + 201LL);
}
