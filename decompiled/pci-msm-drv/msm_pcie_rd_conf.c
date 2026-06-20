__int64 __fastcall msm_pcie_rd_conf(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4, __int64 a5)
{
  return msm_pcie_oper_conf(a1, a2, 0, a3, a4, a5);
}
